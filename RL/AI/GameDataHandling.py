import numpy as np
from AI.DQN import Agent
import logging
import traceback


def create_one_hot_encoding(state, length):
    one_hot = []
    for _ in range(length - 1):
        one_hot.append(0)
    one_hot.insert(state - 1, 1)

    return one_hot


class GameDataHandling:

    # Actions
    def __init__(self):
        self.moveDir = 2
        self.shotDir = 0
        self.state = []
        self.resetEnv = False
        self.ticks = 0
        self.agent = Agent(0.001, 0.99, 4, 1, 64, 15)

    def get_numpy_state(self):
        return np.asarray(self.state).astype('float32')

    def set_state(self, coinsNeeded, closestObstacle, closestCoin, finishDirection, reward, clockTime):
        self.state = []
        # testing reset
        # self.ticks += 1
        # print(self.ticks)
        # if self.ticks > 500:
        #     self.resetEnv = True
        #     self.ticks = 0
        # testing reset

        if coinsNeeded == 0:
            self.state += [0, 1]
        else:
            self.state += [1, 0]

        self.state += create_one_hot_encoding(closestObstacle, 4)
        self.state += create_one_hot_encoding(closestCoin, 5)
        self.state += create_one_hot_encoding(finishDirection, 4)

        done = False
        print("Timer: {}, Actual Reward: {}".format(clockTime, reward))
        if clockTime > 10:
            done = True
            self.set_reset(True)
            reward = -100

        try:
            newState = self.state
            self.moveDir = self.agent.choose_action(self.state)
            self.agent.store_transition(self.state, self.moveDir, reward, newState, done)
            self.agent.learn()
        except Exception:
            print(traceback.print_exc())

    def get_action(self):
        return self.moveDir, self.shotDir

    def get_reset(self):
        return self.resetEnv

    def set_reset(self, resetEnv):
        self.resetEnv = resetEnv
