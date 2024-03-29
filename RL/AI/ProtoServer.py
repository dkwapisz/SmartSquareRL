# Author:       Dawid Kwapisz (dkwapisz99@gmail.com, dkwapisz@student.agh.edu.pl)
# License:      GPLv3

import json
import sys
from datetime import datetime

from line_profiler_pycharm import profile

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

server = grpc.server(futures.ThreadPoolExecutor(max_workers=1))


def get_learning_params():
    with open("../LearningData/learning_params.json") as paramsFile:
        config_params = json.load(paramsFile)
    return config_params


def log_test_purpose():
    config_params = get_learning_params()

    for key, value in config_params.items():
        if len(value) > 1:
            logging.debug(
                "WORKER: {} TESTING: {} WITH VALUES: {}".format(params.WORKER_ID, key, value[params.WORKER_ID]))


class StateActionExchange(game_pb2_grpc.StateActionExchangeServicer):

    def __init__(self):
        self.gameDataHandling = GameDataHandling(params.WORKER_ID)
        self.lastActions = []
        self.rewardInEpisode = 0
        self.winGameNNSaved = False
        self.steps_if_win = []
        self.steps_per_episode = get_learning_params()["iter_per_episode"][params.WORKER_ID] \
            if len(get_learning_params()["iter_per_episode"]) > 1 else get_learning_params()["iter_per_episode"][0]
        self.target_episodes = get_learning_params()["target_episodes"][params.WORKER_ID] \
            if len(get_learning_params()["target_episodes"]) > 1 else get_learning_params()["target_episodes"][0]
        print("Worker {}, steps per episode: {}".format(params.WORKER_ID, self.steps_per_episode))
        print("Worker {}, target episodes: {}".format(params.WORKER_ID, self.target_episodes))
        logging.basicConfig(filename="../LearningData/reward_worker_{}.logs".format(params.WORKER_ID),
                            level=logging.DEBUG)
        log_test_purpose()

    @profile
    def perform_lost_operations(self, request):
        self.lastActions = []
        if request.coinsLeft == 0:
            self.gameDataHandling.reward = -500
        else:
            self.gameDataHandling.reward = -300 + (request.coinsLeft * (-125))
        logging.debug(
            "Reward: {}, Ep: {}, Coins left: {}, Epsilon: {}, Steps in episode: {}, [LOSE]".format(
                (self.rewardInEpisode + self.gameDataHandling.reward),
                request.episodeCount, request.coinsLeft, self.gameDataHandling.agent.get_epsilon(),
                request.stepsCount))
        self.gameDataHandling.game_over = True
        self.gameDataHandling.reset_env = True
        self.rewardInEpisode = 0

    def perform_win_operations(self, request):
        logging.debug(
            "Reward: {}, Ep: {}, Coins left: {}, Epsilon: {}, Steps in episode: {}, [WIN]".format(
                self.rewardInEpisode,
                request.episodeCount,
                request.coinsLeft,
                self.gameDataHandling.agent.get_epsilon(),
                request.stepsCount))
        self.gameDataHandling.game_over = True
        self.rewardInEpisode = 0

    def save_NN_every_n_iterations(self, episode_count, n, reset_env):
        if episode_count == self.target_episodes + 1:
            self.gameDataHandling.save_agent(episode_count, params.WORKER_ID)
        elif episode_count >= (self.target_episodes + 1):
            print("Server stopped at {}. Worker_ID: {}".format(datetime.now(), params.WORKER_ID))
            server.stop(None)

        if reset_env and episode_count % n == 0 and episode_count != 0:
            self.gameDataHandling.save_agent(episode_count, params.WORKER_ID)

    @profile
    def StateAction(self, request, context):
        self.gameDataHandling.set_state(request)

        moveDir = self.gameDataHandling.get_action()
        self.add_action_to_list(moveAction=moveDir)

        return game_pb2.Action(moveDirection=moveDir + 1, shotDirection=0)

    @profile
    def StateReset(self, request, context):
        self.gameDataHandling.set_new_state(request)
        self.rewardInEpisode += request.reward
        if self.gameDataHandling.steps_count >= self.steps_per_episode or self.check_action_duplicates() or request.gameOver:
            self.perform_lost_operations(request)
        elif request.win:
            self.perform_win_operations(request)

        if request.stepsCount != 0:
            self.gameDataHandling.remember()
            self.gameDataHandling.learn()
            self.gameDataHandling.reduce_epsilon_value()

        resetEnv = self.gameDataHandling.get_reset()
        self.gameDataHandling.set_reset(resetEnv=False, gameOver=False)

        self.save_NN_every_n_iterations(episode_count=request.episodeCount, n=500, reset_env=resetEnv)

        return game_pb2.Reset(resetNeeded=resetEnv)

    @profile
    def add_action_to_list(self, moveAction):
        if len(self.lastActions) < 6:
            self.lastActions.append(moveAction)
        else:
            self.lastActions.pop(0)
            self.lastActions.append(moveAction)

    @profile
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
    game_pb2_grpc.add_StateActionExchangeServicer_to_server(StateActionExchange(), server)
    server.add_insecure_port('[::]:{}'.format(port))
    server.start()
    print("-----------------------------------------------")
    print("Server is ready. WorkerID: {}, Port: {}".format(worker_id, port))
    print("-----------------------------------------------")
    server.wait_for_termination()


if __name__ == '__main__':
    serve()
