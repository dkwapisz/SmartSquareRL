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
        self.agent = DoubleDQN(lr=0.001, gamma=0.9, action_dims=4, input_dims=18, eps=0.90)
        self.reward = 0
        self.clock_time = 0

    def set_state(self, request):
        self.state = []

        self.state += self.__get_array_from_bool(request.allCoinsCollected)
        self.state += self.__get_array_from_bool(request.coinInFoV)

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

        self.state += self.__get_array_from_bool(request.lastDiscoveredWall.up)
        self.state += self.__get_array_from_bool(request.lastDiscoveredWall.right)
        self.state += self.__get_array_from_bool(request.lastDiscoveredWall.down)
        self.state += self.__get_array_from_bool(request.lastDiscoveredWall.left)

        self.clock_time = request.clockTime

    def set_new_state(self, request):
        self.new_state = []

        self.new_state += self.__get_array_from_bool(request.allCoinsCollected)
        self.new_state += self.__get_array_from_bool(request.coinInFoV)

        self.new_state += self.__get_array_from_bool(request.closestObstacle.up)
        self.new_state += self.__get_array_from_bool(request.closestObstacle.right)
        self.new_state += self.__get_array_from_bool(request.closestObstacle.down)
        self.new_state += self.__get_array_from_bool(request.closestObstacle.left)

        self.new_state += self.__get_array_from_bool(request.closestCoin.up)
        self.new_state += self.__get_array_from_bool(request.closestCoin.right)
        self.new_state += self.__get_array_from_bool(request.closestCoin.down)
        self.new_state += self.__get_array_from_bool(request.closestCoin.left)

        self.new_state += self.__get_array_from_bool(request.finishDirection.up)
        self.new_state += self.__get_array_from_bool(request.finishDirection.right)
        self.new_state += self.__get_array_from_bool(request.finishDirection.down)
        self.new_state += self.__get_array_from_bool(request.finishDirection.left)

        self.new_state += self.__get_array_from_bool(request.lastDiscoveredWall.up)
        self.new_state += self.__get_array_from_bool(request.lastDiscoveredWall.right)
        self.new_state += self.__get_array_from_bool(request.lastDiscoveredWall.down)
        self.new_state += self.__get_array_from_bool(request.lastDiscoveredWall.left)

        self.reward = request.reward
        self.game_over = request.gameOver

    def learn(self):
        #print("_____________________________________________________________________")
        print("Timer: {}, Actual Reward: {}".format(self.clock_time, self.reward))
        #print("State: {}".format(self.new_state))
        #print("---------------------------------------------------------------------")
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

    @staticmethod
    def __get_array_from_bool(bool_state):
        if bool_state:
            return [1]
        else:
            return [0]
