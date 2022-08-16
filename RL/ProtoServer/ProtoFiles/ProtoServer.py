from concurrent import futures
from AI.GameDataHandling import GameDataHandling
import grpc
import game_pb2
import game_pb2_grpc


class StateActionExchange(game_pb2_grpc.StateActionExchangeServicer):

    def __init__(self):
        self.gameDataHandling = GameDataHandling()
        self.lastActions = []

    # CURRENTLY UNUSED: closestEnemy, closestObstacleIsBox, shotDir (!!!)

    def StateAction(self, request, context):
        self.gameDataHandling.set_state(request)

        moveDir, shotDir = self.gameDataHandling.get_action()
        self.add_action_to_list(moveAction=moveDir)

        return game_pb2.Action(moveDirection=moveDir+1, shotDirection=shotDir+1)

    def StateReset(self, request, context):
        self.gameDataHandling.set_new_state(request)

        if self.gameDataHandling.clock_time > 30 or self.check_action_duplicates():
            self.lastActions = []
            self.gameDataHandling.reward = -200
            self.gameDataHandling.game_over = True
            self.gameDataHandling.reset_env = True

        self.gameDataHandling.remember()
        self.gameDataHandling.learn()

        resetEnv = self.gameDataHandling.get_reset()
        self.gameDataHandling.set_reset(resetEnv=False, gameOver=False)

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
                   self.lastActions[0] != self.lastActions[1]


def serve():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=50))
    game_pb2_grpc.add_StateActionExchangeServicer_to_server(StateActionExchange(), server)
    server.add_insecure_port('[::]:50051')
    server.start()
    print("Server is ready")
    server.wait_for_termination()


if __name__ == '__main__':
    serve()