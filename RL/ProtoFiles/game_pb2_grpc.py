# Generated by the gRPC Python protocol compiler plugin. DO NOT EDIT!
import grpc

import game_pb2 as game__pb2


class ExchangeGameStateStub(object):
  # missing associated documentation comment in .proto file
  pass

  def __init__(self, channel):
    """Constructor.

    Args:
      channel: A grpc.Channel.
    """
    self.Exchange = channel.unary_unary(
        '/Game.ExchangeGameState/Exchange',
        request_serializer=game__pb2.GameState.SerializeToString,
        response_deserializer=game__pb2.Action.FromString,
        )


class ExchangeGameStateServicer(object):
  # missing associated documentation comment in .proto file
  pass

  def Exchange(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')


def add_ExchangeGameStateServicer_to_server(servicer, server):
  rpc_method_handlers = {
      'Exchange': grpc.unary_unary_rpc_method_handler(
          servicer.Exchange,
          request_deserializer=game__pb2.GameState.FromString,
          response_serializer=game__pb2.Action.SerializeToString,
      ),
  }
  generic_handler = grpc.method_handlers_generic_handler(
      'Game.ExchangeGameState', rpc_method_handlers)
  server.add_generic_rpc_handlers((generic_handler,))
