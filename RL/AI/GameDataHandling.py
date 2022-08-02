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
        self.newState = []
        self.resetEnv = False
        self.ticks = 0
        self.agent = Agent(0.001, 0.90, 4, 1, 64, 15)
        self.reward = 0
        self.clockTime = 0
        self.gameOver = False

    def get_numpy_state(self):
        return np.asarray(self.state).astype('float32')

    def set_state(self, areCoinsNeeded, closestObstacle, closestCoin, finishDirection, clockTime):
        self.state = []
        # testing reset
        # self.ticks += 1
        # print(self.ticks)
        # if self.ticks > 500:
        #     self.resetEnv = True
        #     self.ticks = 0
        # testing reset

        if areCoinsNeeded:
            self.state += [0, 1]
        else:
            self.state += [1, 0]

        self.state += create_one_hot_encoding(closestObstacle, 4)
        self.state += create_one_hot_encoding(closestCoin, 5)
        self.state += create_one_hot_encoding(finishDirection, 4)

        self.clockTime = clockTime

    def set_new_state(self, areCoinsNeeded, closestObstacle, closestCoin, finishDirection, reward, gameOver):
        self.newState = []

        if areCoinsNeeded:
            self.newState += [0, 1]
        else:
            self.newState += [1, 0]

        self.newState += create_one_hot_encoding(closestObstacle, 4)
        self.newState += create_one_hot_encoding(closestCoin, 5)
        self.newState += create_one_hot_encoding(finishDirection, 4)

        self.reward = reward
        self.gameOver = gameOver

    def reinforcement(self):
        print("Timer: {}, Actual Reward: {}".format(self.clockTime, self.reward))
        try:
            self.agent.learn()
        except:
            pass

    def remember(self):
        self.agent.store_transition(self.state, self.moveDir, self.reward, self.newState, self.gameOver)

    def get_state(self):
        return self.state

    def get_action(self):
        self.moveDir = self.agent.choose_action(self.state)
        return self.moveDir, self.shotDir

    def get_reset(self):
        return self.resetEnv

    def set_reset(self, resetEnv, gameOver):
        self.gameOver = gameOver
        self.resetEnv = resetEnv
