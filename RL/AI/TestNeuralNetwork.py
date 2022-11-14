import sys

import numpy as np
from tensorflow.python.keras.models import load_model

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
        self.model = load_model(
            "../LearningData/NeuralNetworks/Worker4/DDQN_eval_episode_4000_worker_4.h5")

    def StateAction(self, request, context):
        state = np.array(reformat_map_matrix_state(request.mapMatrix))
        state = state[np.newaxis, :]
        actions = self.model.predict(state)
        action = np.argmax(actions)

        return game_pb2.Action(moveDirection=action + 1, shotDirection=0)

    def StateReset(self, request, context):
        reset = False
        if request.stepsCount > 80:
            self.loseCounter += 1
            reset = True

        if request.win is True:
            self.winCounter += 1
            #print("WIN!")
            reset = True

        if reset:
            print("Win percentage: {}, maps won/tested: {}/{}".format(self.winCounter/(self.winCounter+self.loseCounter), self.winCounter, (self.winCounter+self.loseCounter)))
        return game_pb2.Reset(resetNeeded=reset)


def serve():
    port = params.PORT
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
