from concurrent import futures
import logging

import grpc
import testPython_pb2
import testPython_pb2_grpc


class LevelInfo(testPython_pb2_grpc.GetInfoServicer):

    def GetLevelInfo(self, request, context):
        print(request)
        return testPython_pb2.LevelInfoReply(playerCoins=5, levelCoins=5)


def serve():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    testPython_pb2_grpc.add_GetInfoServicer_to_server(LevelInfo(), server)
    server.add_insecure_port('[::]:50051')
    server.start()
    server.wait_for_termination()


if __name__ == '__main__':
    logging.basicConfig()
    serve()