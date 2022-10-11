import json
import sys

sys.path.insert(0, "./ProtoFiles")

from concurrent import futures
import ProtoFiles.game_pb2 as game_pb2
import ProtoFiles.game_pb2_grpc as game_pb2_grpc

from GameDataHandling import GameDataHandling
import grpc
import logging
import argparse

parser = argparse.ArgumentParser(description="Config for multiple workers")
parser.add_argument("--WORKER_ID", type=int)
parser.add_argument("--PORT", type=int)

params = parser.parse_args()


class StateActionExchange(game_pb2_grpc.StateActionExchangeServicer):

    def __init__(self):
        self.gameDataHandling = GameDataHandling(params.WORKER_ID)
        self.lastActions = []
        self.rewardInEpisode = 0
        logging.basicConfig(filename="../LearningData/reward_worker_{}.logs".format(params.WORKER_ID), level=logging.DEBUG)
        self.log_test_purpose()

    def log_test_purpose(self):
        with open("../LearningData/learning_params.json") as paramsFile:
            config_params = json.load(paramsFile)

        for key, value in config_params.items():
            if len(value) > 1:
                logging.debug("WORKER: {} TESTING: {} WITH VALUES: {}"
                              .format(params.WORKER_ID, key, value[params.WORKER_ID]))

    def StateAction(self, request, context):
        self.gameDataHandling.set_state(request)

        # for line in request.mapMatrix.split("#"):
        #     print(" ".join(line))
        # print("\n")

        moveDir, shotDir = self.gameDataHandling.get_action()
        self.add_action_to_list(moveAction=moveDir)

        return game_pb2.Action(moveDirection=moveDir + 1, shotDirection=shotDir + 1)

    def StateReset(self, request, context):
        self.gameDataHandling.set_new_state(request)
        self.rewardInEpisode += request.reward
        if self.gameDataHandling.steps_count >= 200 or self.check_action_duplicates():
            self.lastActions = []
            self.gameDataHandling.reward = -300 + (request.coinsLeft * (-200))
            logging.debug(
                "Reward: {}, Ep: {}, Coins left: {}, Epsilon: {}, [LOSE]".format(
                    (self.rewardInEpisode + self.gameDataHandling.reward),
                    request.episodeCount, request.coinsLeft, self.gameDataHandling.agent.get_epsilon()))
            self.gameDataHandling.game_over = True
            self.gameDataHandling.reset_env = True
            self.rewardInEpisode = 0
        elif request.gameOver:
            self.gameDataHandling.save_agent(request.episodeCount, params.WORKER_ID)
            logging.debug(
                "Reward: {}, Ep: {}, Coins left: {}, Epsilon: {}, [WIN]".format(self.rewardInEpisode,
                                                                                request.episodeCount,
                                                                                request.coinsLeft,
                                                                                self.gameDataHandling.agent.get_epsilon()))
            self.gameDataHandling.game_over = True
            self.rewardInEpisode = 0

        self.gameDataHandling.remember()
        self.gameDataHandling.learn()

        resetEnv = self.gameDataHandling.get_reset()
        self.gameDataHandling.set_reset(resetEnv=False, gameOver=False)

        if resetEnv and request.episodeCount % 200 == 0 and request.episodeCount != 0:
            self.gameDataHandling.save_agent(request.episodeCount, params.WORKER_ID)

        return game_pb2.Reset(resetNeeded=resetEnv)

    def add_action_to_list(self, moveAction):
        if len(self.lastActions) < 6:
            self.lastActions.append(moveAction)
        else:
            self.lastActions.pop(0)
            self.lastActions.append(moveAction)

    def check_action_duplicates(self):
        if len(self.lastActions) < 6:
            return False
        else:
            return self.lastActions[0] == self.lastActions[2] == self.lastActions[4] and \
                   self.lastActions[1] == self.lastActions[3] == self.lastActions[5] and \
                   self.lastActions[0] % 2 == self.lastActions[1] % 2 and \
                   self.lastActions[0] != self.lastActions[1]


def serve():
    port = params.PORT
    worker_id = params.WORKER_ID
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    game_pb2_grpc.add_StateActionExchangeServicer_to_server(StateActionExchange(), server)
    server.add_insecure_port('[::]:{}'.format(port))
    server.start()
    print("-----------------------------------------------")
    print("Server is ready. WorkerID: {}, Port: {}".format(worker_id, port))
    print("-----------------------------------------------")
    server.wait_for_termination()


if __name__ == '__main__':
    serve()
