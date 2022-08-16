from AI.DDQN import DoubleDQN
import traceback


class GameDataHandling:

    # Actions
    def __init__(self):
        self.move_dir = 0
        self.shot_dir = 0
        self.state = []
        self.new_state = []
        self.game_over = False
        self.reset_env = False
        self.agent = DoubleDQN(lr=0.001, gamma=0.9, action_dims=4, input_dims=4, eps=0.99)
        self.reward = 0
        self.clock_time = 0

    def set_state(self, request):
        self.state = []

        # self.state += self.__get_array_from_bool(request.allCoinsCollected)
        # self.state += self.__get_array_from_bool(request.coinInFoV)

        # self.state += self.__get_array_from_bool(request.closestObstacle.up)
        # self.state += self.__get_array_from_bool(request.closestObstacle.right)
        # self.state += self.__get_array_from_bool(request.closestObstacle.down)
        # self.state += self.__get_array_from_bool(request.closestObstacle.left)

        if request.coinInFoV:
            self.state += self.__get_array_from_bool(request.closestCoin.up)
            self.state += self.__get_array_from_bool(request.closestCoin.right)
            self.state += self.__get_array_from_bool(request.closestCoin.down)
            self.state += self.__get_array_from_bool(request.closestCoin.left)
        elif not request.allCoinsCollected:
            self.state += self.__get_array_from_bool(request.lastDiscoveredWall.up)
            self.state += self.__get_array_from_bool(request.lastDiscoveredWall.right)
            self.state += self.__get_array_from_bool(request.lastDiscoveredWall.down)
            self.state += self.__get_array_from_bool(request.lastDiscoveredWall.left)
        else:
            self.state += self.__get_array_from_bool(request.finishDirection.up)
            self.state += self.__get_array_from_bool(request.finishDirection.right)
            self.state += self.__get_array_from_bool(request.finishDirection.down)
            self.state += self.__get_array_from_bool(request.finishDirection.left)

        self.clock_time = request.clockTime

    def set_new_state(self, request):
        self.new_state = []

        # self.new_state += self.__get_array_from_bool(request.allCoinsCollected)
        # self.new_state += self.__get_array_from_bool(request.coinInFoV)

        # self.new_state += self.__get_array_from_bool(request.closestObstacle.up)
        # self.new_state += self.__get_array_from_bool(request.closestObstacle.right)
        # self.new_state += self.__get_array_from_bool(request.closestObstacle.down)
        # self.new_state += self.__get_array_from_bool(request.closestObstacle.left)

        if request.coinInFoV:
            self.new_state += self.__get_array_from_bool(request.closestCoin.up)
            self.new_state += self.__get_array_from_bool(request.closestCoin.right)
            self.new_state += self.__get_array_from_bool(request.closestCoin.down)
            self.new_state += self.__get_array_from_bool(request.closestCoin.left)
        elif not request.allCoinsCollected:
            self.new_state += self.__get_array_from_bool(request.lastDiscoveredWall.up)
            self.new_state += self.__get_array_from_bool(request.lastDiscoveredWall.right)
            self.new_state += self.__get_array_from_bool(request.lastDiscoveredWall.down)
            self.new_state += self.__get_array_from_bool(request.lastDiscoveredWall.left)
            print("no coin")
        else:
            self.new_state += self.__get_array_from_bool(request.finishDirection.up)
            self.new_state += self.__get_array_from_bool(request.finishDirection.right)
            self.new_state += self.__get_array_from_bool(request.finishDirection.down)
            self.new_state += self.__get_array_from_bool(request.finishDirection.left)
            print("finish")

        self.reward = request.reward
        self.game_over = request.gameOver

        # if request.iteration == 20:
        #     self.agent.save_neural_network()

    def learn(self):
        print("Timer: {}, Actual Reward: {}, State: {}".format(self.clock_time, self.reward, self.new_state))
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
    def __get_array_from_bool(bool_state):
        if bool_state:
            return [1]
        else:
            return [0]
