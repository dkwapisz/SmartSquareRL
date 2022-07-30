from concurrent import futures
from AI.GameDataHandling import GameDataHandling
import grpc
import game_pb2
import game_pb2_grpc


class ExchangeGameState(game_pb2_grpc.ExchangeGameStateServicer):

    def __init__(self):
        self.gameDataHandling = GameDataHandling()
        self.time = 0

    def Exchange(self, request, context):
        # isClosestObstacleBox = request.isClosestObstacleBox
        # closestEnemy = request.closestEnemy,
        self.time += 1

        self.gameDataHandling.set_state(request.coinsNeeded,
                                        request.closestObstacle,
                                        request.closestCoin,
                                        request.finishDirection,
                                        request.reward,
                                        request.clockTime)

        moveDir, shotDir = self.gameDataHandling.get_action()
        resetEnv = self.gameDataHandling.get_reset()
        self.gameDataHandling.set_reset(False)

        return game_pb2.Action(moveDirection=moveDir, shotDirection=shotDir, setReset=resetEnv)


def serve():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    game_pb2_grpc.add_ExchangeGameStateServicer_to_server(ExchangeGameState(), server)
    server.add_insecure_port('[::]:50051')
    server.start()
    print("Server is ready")
    server.wait_for_termination()


if __name__ == '__main__':
    serve()
