import sys

import numpy as np

sys.path.insert(0, "./ProtoFiles")

from concurrent import futures
import ProtoFiles.game_pb2 as game_pb2
import ProtoFiles.game_pb2_grpc as game_pb2_grpc

import grpc


def reformat_map_matrix_state(input_state: str):
    input_list = []
    input_state = input_state[:-1]
    if len(input_state) != 0:
        for sequence in input_state.split("#"):
            line = [*sequence]
            line = [int(x) for x in line]
            input_list.append(line)

    print(np.asarray(input_list))

    return np.asarray(input_list)

def get_action():
    return 0

class StateActionExchange(game_pb2_grpc.StateActionExchangeServicer):

    def __init__(self):
        self.winCounter = 0
        self.loseCounter = 0
        self.actualEpisode = 0
        self.actualMap = None

    def StateAction(self, request, context):
        if request.episodeCount != self.actualEpisode:
            self.actualEpisode = request.episodeCount
            self.actualEpisode = reformat_map_matrix_state(request.mapMatrix)

        action = get_action()

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
