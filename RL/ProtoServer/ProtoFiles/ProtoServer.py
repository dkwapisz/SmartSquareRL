from concurrent import futures
from AI.GameDataHandling import GameDataHandling
import grpc
import game_pb2
import game_pb2_grpc


class StateActionExchange(game_pb2_grpc.StateActionExchangeServicer):

    def __init__(self):
        self.gameDataHandling = GameDataHandling()

    def StateAction(self, request, context):
        self.gameDataHandling.set_state(request.coinsNeeded,
                                        request.closestObstacle,
                                        request.closestCoin,
                                        request.finishDirection,
                                        request.clockTime)

        moveDir, shotDir = self.gameDataHandling.get_action()

        return game_pb2.Action(moveDirection=moveDir, shotDirection=shotDir)

    def StateReset(self, request, context):
        self.gameDataHandling.set_new_state(request.coinsNeeded,
                                            request.closestObstacle,
                                            request.closestCoin,
                                            request.finishDirection,
                                            request.reward,
                                            request.gameOver)

        if self.gameDataHandling.clockTime > 20:
            self.gameDataHandling.reward = -100
            self.gameDataHandling.gameOver = True
            self.gameDataHandling.resetEnv = True

        self.gameDataHandling.remember()
        self.gameDataHandling.reinforcement()

        resetEnv = self.gameDataHandling.get_reset()
        self.gameDataHandling.set_reset(resetEnv=False, gameOver=False)

        return game_pb2.Reset(resetNeeded=resetEnv)


def serve():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=50))
    game_pb2_grpc.add_StateActionExchangeServicer_to_server(StateActionExchange(), server)
    server.add_insecure_port('[::]:50051')
    server.start()
    print("Server is ready")
    server.wait_for_termination()


if __name__ == '__main__':
    serve()
