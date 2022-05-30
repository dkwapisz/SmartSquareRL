import grpc
import testPython_pb2_grpc as pb2GRPC
import testPython_pb2 as pb2
from concurrent import futures


class SquareRootServiceServicer(pb2GRPC.SquareRootServiceServicer):

    def squareRoot(self, request, context):
        resultA = request.input * request.input
        return pb2.Result(resultA=resultA)


def main():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=5))
    pb2GRPC.add_SquareRootServiceServicer_to_server(SquareRootServiceServicer(), server)
    server.add_insecure_port('[::]:50052')
    server.start()
    server.wait_for_termination()


if __name__ == "__main__":
    main()
