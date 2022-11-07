from line_profiler_pycharm import profile

from DDQN import DoubleDQN

blocks_mapping = {
    0: [0, 0, 0, 0, 1],  # floor [undiscovered]
    1: [0, 0, 0, 1, 0],  # wall
    4: [0, 0, 1, 0, 0],  # coin
    8: [0, 1, 0, 0, 0],  # player
    9: [1, 0, 0, 0, 0]   # floor [discovered]
    # 7: [0, 0, 1, 0, 0, 0],  # finish
}

MAP_SIZE = 7


class GameDataHandling:

    def __init__(self, worker_id_):
        input_dims = MAP_SIZE * MAP_SIZE * len(blocks_mapping)

        self.move_dir = 0
        self.shot_dir = 0
        self.state = []
        self.new_state = []
        self.game_over = False
        self.reset_env = False
        self.agent = DoubleDQN(action_dims=4, input_dims=input_dims, worker_id=worker_id_)
        self.reward = 0
        self.steps_count = 0

    @profile
    def set_state(self, request):
        self.state = GameDataHandling.__reformat_map_matrix_state(request.mapMatrix)
        self.steps_count = request.stepsCount

    def set_new_state(self, request):
        self.new_state = GameDataHandling.__reformat_map_matrix_state(request.mapMatrix)
        self.reward = request.reward
        self.game_over = request.gameOver

    def learn(self):
        #print("Step: {}, Actual Reward: {}".format(self.steps_count, self.reward))
        self.agent.learn()

    def remember(self):
        self.agent.write_to_memory(self.state, self.move_dir, self.reward, self.new_state, self.game_over)

    def get_action(self):
        self.move_dir = self.agent.calculate_action(self.state)
        return self.move_dir, -1

    def get_reset(self):
        return self.reset_env or self.game_over

    def set_reset(self, resetEnv, gameOver):
        self.game_over = gameOver
        self.reset_env = resetEnv

    def save_agent(self, episodeCount, worker_id):
        self.agent.save_neural_network(episodeCount, worker_id)

    @staticmethod
    @profile
    def __reformat_map_matrix_state(input_state: str):
        input_list = []
        if len(input_state) != 0:
            for sequence in input_state.split("#"):
                for num in sequence:
                    input_list += blocks_mapping[int(num)]

        return input_list
        # CNN
        # input_list = []
        # input_state = input_state[:-1]
        # if len(input_state) != 0:
        #     for sequence in input_state.split("#"):
        #         line = [*sequence]
        #         line = [blocks_mapping[int(x)] for x in line]
        #         input_list.append(line)
        #
        # return np.asarray(input_list)
