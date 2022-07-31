import asyncio
from concurrent import futures
from AI.GameDataHandling import GameDataHandling
from grpc import aio
import game_pb2
import game_pb2_grpc
import multiprocessing


class ExchangeGameState(game_pb2_grpc.ExchangeGameStateServicer):

    def __init__(self):
        self.gameDataHandling = GameDataHandling()
        self.time = 0

    def handle_game_data(self, request):
        self.gameDataHandling.set_state(request.coinsNeeded,
                                        request.closestObstacle,
                                        request.closestCoin,
                                        request.finishDirection,
                                        request.reward,
                                        request.clockTime,
                                        request.gameOver)

        moveDir, shotDir = self.gameDataHandling.get_action()
        resetEnv = self.gameDataHandling.get_reset()
        self.gameDataHandling.set_reset(resetEnv=False, gameOver=False)
        self.gameDataHandling.reinforcement()

        return moveDir, shotDir, resetEnv

    def Exchange(self, request, context):
        # isClosestObstacleBox = request.isClosestObstacleBox
        # closestEnemy = request.closestEnemy,

        moveDir, shotDir, resetEnv = self.handle_game_data(request)
        # remember
        # learn
        # state = get_state
        # action = choose_action()

        return game_pb2.Action(moveDirection=moveDir, shotDirection=shotDir, setReset=resetEnv)


async def serve():
    server = aio.server()
    game_pb2_grpc.add_ExchangeGameStateServicer_to_server(ExchangeGameState(), server)
    server.add_insecure_port('[::]:50051')
    await server.start()
    print("Server is ready")
    await server.wait_for_termination()


if __name__ == '__main__':
    asyncio.run(serve())