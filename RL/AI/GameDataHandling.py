import numpy as np
from AI.DQN import Agent
import logging
import traceback





class GameDataHandling:

    # Actions
    def __init__(self):
        self.moveDir = 0
        self.shotDir = 0
        self.state = []
        self.newState = []
        self.gameOver = False
        self.resetEnv = False
        self.agent = Agent(0.001, 0.90, 4, 1, 64, 14)
        self.reward = 0
        self.clockTime = 0

    def set_state(self, request):
        self.state = []

        if request.allCoinsCollected:
            self.state += [0]
        else:
            self.state += [1]

        self.state += self.__get_array_from_bool(request.closestObstacle.up)
        self.state += self.__get_array_from_bool(request.closestObstacle.right)
        self.state += self.__get_array_from_bool(request.closestObstacle.down)
        self.state += self.__get_array_from_bool(request.closestObstacle.left)

        self.state += self.__get_array_from_bool(request.closestCoin.up)
        self.state += self.__get_array_from_bool(request.closestCoin.right)
        self.state += self.__get_array_from_bool(request.closestCoin.down)
        self.state += self.__get_array_from_bool(request.closestCoin.left)

        self.state += self.__get_array_from_bool(request.finishDirection.up)
        self.state += self.__get_array_from_bool(request.finishDirection.right)
        self.state += self.__get_array_from_bool(request.finishDirection.down)
        self.state += self.__get_array_from_bool(request.finishDirection.left)

        print(self.state)

        self.clockTime = request.clockTime

    def set_new_state(self, request):
        self.newState = []

        if request.allCoinsCollected:
            self.state += [0]
        else:
            self.state += [1]

        self.state += self.__get_array_from_bool(request.closestObstacle.up)
        self.state += self.__get_array_from_bool(request.closestObstacle.right)
        self.state += self.__get_array_from_bool(request.closestObstacle.down)
        self.state += self.__get_array_from_bool(request.closestObstacle.left)

        self.state += self.__get_array_from_bool(request.closestCoin.up)
        self.state += self.__get_array_from_bool(request.closestCoin.right)
        self.state += self.__get_array_from_bool(request.closestCoin.down)
        self.state += self.__get_array_from_bool(request.closestCoin.left)

        self.state += self.__get_array_from_bool(request.finishDirection.up)
        self.state += self.__get_array_from_bool(request.finishDirection.right)
        self.state += self.__get_array_from_bool(request.finishDirection.down)
        self.state += self.__get_array_from_bool(request.finishDirection.left)

        self.reward = request.reward
        self.gameOver = request.gameOver

    def reinforcement(self):
        print("Timer: {}, Actual Reward: {}".format(self.clockTime, self.reward))
        try:
            self.agent.learn()
        except Exception:
            print(traceback.format_exc())
            pass

    def remember(self):
        self.agent.store_transition(self.state, self.moveDir, self.reward, self.newState, self.gameOver)

    def get_action(self):
        self.moveDir = self.agent.choose_action(self.state)
        return self.moveDir + 1, 0

    def get_reset(self):
        return self.resetEnv

    def set_reset(self, resetEnv, gameOver):
        self.gameOver = gameOver
        self.resetEnv = resetEnv

    def __get_array_from_bool(self, bool_state):
        if bool_state:
            return [0]
        else:
            return [1]
