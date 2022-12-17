import os
import sys

import numpy as np
from tensorflow.python.keras.models import load_model
import tensorflow as tf

sys.path.insert(0, "./ProtoFiles")

from concurrent import futures
import ProtoFiles.game_pb2 as game_pb2
import ProtoFiles.game_pb2_grpc as game_pb2_grpc

import grpc
import argparse

parser = argparse.ArgumentParser(description="Config for multiple workers")
parser.add_argument("--PORT", type=int)

params = parser.parse_args()

blocks_mapping = {
    0: [0, 0, 0, 0, 1],  # floor [undiscovered]
    1: [0, 0, 0, 1, 0],  # wall
    4: [0, 0, 1, 0, 0],  # coin
    8: [0, 1, 0, 0, 0],  # player
    9: [1, 0, 0, 0, 0]   # floor [discovered]
    # 7: [0, 0, 1, 0, 0, 0],  # finish
}

def set_tf_gpu():
    os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'
    os.environ['TF_XLA_FLAGS'] = '--tf_xla_enable_xla_devices'
    os.environ['CUDA_VISIBLE_DEVICES'] = "0"
    os.environ['TF_GPU_THREAD_MODE'] = 'gpu_private'
    os.environ['KERAS_BACKEND'] = 'tensorflow'

    gpu_devices = tf.config.experimental.list_physical_devices('GPU')
    for device in gpu_devices:
        tf.config.experimental.set_memory_growth(device, True)

    print("Num GPUs Available: ", len(tf.config.list_physical_devices('GPU')))


def reformat_map_matrix_state(input_state: str):
    # NN
    # input_list = []
    # if len(input_state) != 0:
    #     for sequence in input_state.split("#"):
    #         for num in sequence:
    #             input_list += blocks_mapping[int(num)]
    #
    # return input_list
    # CNN
    input_list = []
    input_state = input_state[:-1]
    if len(input_state) != 0:
        for sequence in input_state.split("#"):
            line = [*sequence]
            line = [blocks_mapping[int(x)] for x in line]
            input_list.append(line)

    return np.asarray(input_list)


class StateActionExchange(game_pb2_grpc.StateActionExchangeServicer):

    def __init__(self):
        self.winCounter = 0
        self.loseCounter = 0
        self.modelNum = 4
        self.countIter = 0
        set_tf_gpu()
        self.model = load_model(
            "../LearningData/NeuralNetworks/Worker{}/DDQN_eval_episode_9500_worker_{}.h5".format(self.modelNum,
                                                                                                 self.modelNum))
        print("Model: {} in PyCharm, {} in Overleaf".format(self.modelNum, self.modelNum+1))

    def StateAction(self, request, context):
        self.countIter += 1
        if self.countIter == 1000:
            print("STOP")
        state = np.array(reformat_map_matrix_state(request.mapMatrix))
        state = state[np.newaxis, :]
        actions = self.model.predict(state)
        action = np.argmax(actions)

        return game_pb2.Action(moveDirection=action + 1, shotDirection=0)

    def StateReset(self, request, context):
        reset = False
        status = "[NO_STATUS]"
        if request.stepsCount > 100:
            self.loseCounter += 1
            reset = True
            status = "[LOSE]"

        if request.win is True:
            self.winCounter += 1
            #print("WIN!")
            reset = True
            status = "[WIN]"

        if reset:
            print("Win percentage: {}, maps won/tested: {}/{} Episodes: {} {}".format(
                self.winCounter / (self.winCounter + self.loseCounter), self.winCounter,
                (self.winCounter + self.loseCounter), request.stepsCount, status))
        return game_pb2.Reset(resetNeeded=reset)


def serve():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=1))
    game_pb2_grpc.add_StateActionExchangeServicer_to_server(StateActionExchange(), server)
    server.add_insecure_port('[::]:{}'.format(55610))
    server.start()
    print("-----------------------------------------------")
    print("Test server is ready. Port: {}".format(55610))
    print("-----------------------------------------------")
    server.wait_for_termination()


if __name__ == '__main__':
    serve()
