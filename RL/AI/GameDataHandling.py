import math

from AI.DDQN import DoubleDQN
from sklearn import preprocessing
import numpy as np


class GameDataHandling:

    # Actions
    def __init__(self):
        self.move_dir = 0
        self.shot_dir = 0
        self.state = []
        self.new_state = []
        self.game_over = False
        self.reset_env = False
        self.agent = DoubleDQN(lr=0.001, gamma=0.9, action_dims=4, input_dims=22, eps=0.99)
        self.reward = 0
        self.clock_time = 0

    def set_state(self, request):
        self.state = []

        # self.state += self.__get_array_from_bool(request.allCoinsCollected)
        # self.state += self.__get_array_from_bool(request.coinInFoV)

        self.state += GameDataHandling.__reformat_ray_distances_state(request.rayDistances)
        self.state = GameDataHandling.__normalize(self.state)
        self.state += GameDataHandling.__get_unit_vector(request.closestDestinationDistX,
                                                         request.closestDestinationDistY)

        self.clock_time = request.clockTime

    def set_new_state(self, request):
        self.new_state = []

        # self.new_state += self.__get_array_from_bool(request.allCoinsCollected)
        # self.new_state += self.__get_array_from_bool(request.coinInFoV)

        self.new_state += GameDataHandling.__reformat_ray_distances_state(request.rayDistances)
        self.new_state = GameDataHandling.__normalize(self.new_state)
        self.new_state += GameDataHandling.__get_unit_vector(request.closestDestinationDistX,
                                                             request.closestDestinationDistY)

        self.reward = request.reward
        self.game_over = request.gameOver

        # if request.iteration == 20:
        #     self.agent.save_neural_network()

    def learn(self):
        print("Timer: {}, Actual Reward: {}, State: {}".format(self.clock_time, self.reward, self.new_state[20:22]))
        self.agent.learn()

    def remember(self):
        self.agent.write_to_memory(self.state, self.move_dir, self.reward, self.new_state, self.game_over)

    def get_action(self):
        self.move_dir = self.agent.calculate_action(self.state)
        return self.move_dir, -1

    def get_reset(self):
        return self.reset_env

    def set_reset(self, resetEnv, gameOver):
        self.game_over = gameOver
        self.reset_env = resetEnv

    def save_agent(self):
        self.agent.save_neural_network()

    @staticmethod
    def __reformat_ray_distances_state(input_state: str):
        input_list = []
        if len(input_state) != 0:
            for dist in input_state.split("#"):
                input_list += [float(dist)]
        else:
            # dirty fix
            input_list = [0.1 for _ in range(0, 20)]

        return input_list

    @staticmethod
    def __normalize(values):
        return (lambda the_max, the_min: [(float(i)-the_min)/(the_max-(the_min+0.000001)) for i in values])(max(values), min(values))

    @staticmethod
    def __get_unit_vector(dirX, dirY):
        vector_len = math.hypot(dirX, dirY)
        return [dirX/vector_len, dirY/vector_len]
