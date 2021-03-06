def create_one_hot_encoding(state, length):
    one_hot = []
    for _ in range(length - 1):
        one_hot.append(0)
    one_hot.insert(state - 1, 1)

    return one_hot


class StateActionHandling:

    # Actions
    def __init__(self):
        self.moveDir = 1
        self.shotDir = 5
        self.state = []
        self.resetEnv = False
        self.ticks = 0

    def set_state(self, coinsNeeded, closestObstacle, closestCoin, finishDirection, reward):

        # testing reset
        self.ticks += 1
        print(self.ticks)
        if self.ticks > 500:
            self.resetEnv = True
            self.ticks = 0
        # testing reset

        if coinsNeeded == 0:
            self.state += [0, 1]
        else:
            self.state += [1, 0]

        self.state += create_one_hot_encoding(closestObstacle, 4)
        self.state += create_one_hot_encoding(closestCoin, 5)
        self.state += create_one_hot_encoding(finishDirection, 4)

        if reward < 0:
            self.moveDir = 3
        else:
            self.moveDir = 1

    def get_action(self):
        return self.moveDir, self.shotDir

    def get_reset(self):
        return self.resetEnv

    def set_reset(self, resetEnv):
        self.resetEnv = resetEnv
