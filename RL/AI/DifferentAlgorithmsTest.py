import logging
import sys

import numpy as np
from A_Star import calculate_path

sys.path.insert(0, "./ProtoFiles")

from concurrent import futures
import ProtoFiles.game_pb2 as game_pb2
import ProtoFiles.game_pb2_grpc as game_pb2_grpc

import grpc

logging.basicConfig(filename="../LearningData/Test.logs", level=logging.DEBUG)


def reformat_map_matrix_state(input_state: str):
    input_list = []
    input_state = input_state[:-1]
    if len(input_state) != 0:
        for sequence in input_state.split("#"):
            line = [*sequence]
            line = [int(x) for x in line]
            input_list.append(line)

    return np.asarray(input_list)


def get_action(index, path):
    # print(path)
    # print(index)
    action = path[index]

    if "UP" in action:
        return 1
    elif "DOWN" in action:
        return 3
    elif "RIGHT" in action:
        return 2
    elif "LEFT" in action:
        return 4


class StateActionExchange(game_pb2_grpc.StateActionExchangeServicer):

    def __init__(self):
        self.winCounter = 0
        self.loseCounter = 0
        self.actualEpisode = -1
        self.index = 0
        self.countIter = 0
        self.path = None
        self.setIfNoCoins = True
        self.setIfBeginEpisode = True

    def StateAction(self, request, context):
        self.countIter += 1
        if self.countIter == 1000:
            print("STOP")
        if (request.episodeCount != self.actualEpisode and self.setIfBeginEpisode) or \
                (request.coinsLeft == 0 and self.setIfNoCoins):

            if request.episodeCount != self.actualEpisode:
                self.setIfBeginEpisode = False
                self.actualEpisode = request.episodeCount
                self.path = calculate_path(reformat_map_matrix_state(request.mapMatrix), False)

            if request.coinsLeft == 0:
                self.setIfNoCoins = False
                self.path = calculate_path(reformat_map_matrix_state(request.mapMatrix), True)

            self.index = 0


        action = get_action(self.index, self.path)
        self.index += 1

        return game_pb2.Action(moveDirection=action, shotDirection=0)

    def StateReset(self, request, context):
        reset = False
        status = "[NO_STATUS]"
        if request.stepsCount > 200:
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
            self.setIfNoCoins = True
            self.setIfBeginEpisode = True
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
