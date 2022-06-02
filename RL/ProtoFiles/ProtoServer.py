from concurrent import futures
import logging

import grpc
import game_pb2
import game_pb2_grpc


class ExchangeGameState(game_pb2_grpc.ExchangeGameStateServicer):

    def Exchange(self, request, context):
        print(request)
        return game_pb2.Action(moveDirection=0, shotDirection=0)


def serve():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    game_pb2_grpc.add_ExchangeGameStateServicer_to_server(ExchangeGameState(), server)
    server.add_insecure_port('[::]:50051')
    server.start()
    server.wait_for_termination()


if __name__ == '__main__':
    logging.basicConfig()
    serve()

