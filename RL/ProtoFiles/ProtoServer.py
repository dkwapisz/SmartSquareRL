from grpc import aio
import asyncio
import logging
import os

import testPython_pb2_grpc as pb2GRPC
import testPython_pb2 as pb2

async def run() -> None:
    async with aio.insecure_channel('0.0.0.0:50051', options=(('grpc.enable_http_proxy', 0),)) as channel:
        stub = pb2GRPC.GetInfoStub(channel)
        response = await stub.GetLevelInfo(pb2.LevelInfoRequest(playerCoins=5, levelCoins=5))

    print("Client received: " + response.playerCoins)
    print("Client received: " + response.levelCoins)


if __name__ == '__main__':
    logging.basicConfig()
    asyncio.run(run())

# status = StatusCode.UNAVAILABLE
# "failed to connect to all addresses"