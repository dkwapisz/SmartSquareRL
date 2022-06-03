cmake_minimum_required(VERSION 3.8)
project(SmartSquareRL)

find_package(SFML COMPONENTS system window graphics REQUIRED)

include(gRPC.cmake)

get_filename_component(gameProto "Game/ProtoClient/ProtoFiles/game.proto" ABSOLUTE)
get_filename_component(gameProtoPath "${gameProto}" PATH)
set(gameProtoSrcs "Game/ProtoClient/ProtoFiles/game.pb.cc")
set(gameProtoHdrs "Game/ProtoClient/ProtoFiles/game.pb.h")
set(gameGrpcSrcs "Game/ProtoClient/ProtoFiles/game.grpc.pb.cc")
set(gameGrpcHdrs "Game/ProtoClient/ProtoFiles/game.grpc.pb.h")

include_directories("${CMAKE_CURRENT_BINARY_DIR}")

add_library(gRPC_Client
        ${gameProtoSrcs}
        ${gameProtoHdrs}
        ${gameGrpcSrcs}
        ${gameGrpcHdrs})

add_executable(
        SmartSquareRL Game/GameFiles/main.cpp
        Game/GameFiles/Game.cpp Game/GameFiles/Game.hpp
        Game/GameFiles/GameObjects/Player.cpp Game/GameFiles/GameObjects/Player.hpp
        Game/GameFiles/GameObjects/Bullet.cpp Game/GameFiles/GameObjects/Bullet.hpp
        Game/GameFiles/GameObjects/Wall.cpp Game/GameFiles/GameObjects/Wall.hpp
        Game/GameFiles/GameObjects/Box.cpp Game/GameFiles/GameObjects/Box.hpp
        Game/GameFiles/GameObjects/StaticDanger.cpp Game/GameFiles/GameObjects/StaticDanger.hpp
        Game/GameFiles/GameObjects/Coin.cpp Game/GameFiles/GameObjects/Coin.hpp
        Game/GameFiles/GameObjects/SquareObject.cpp Game/GameFiles/GameObjects/SquareObject.hpp
        Game/GameFiles/GameObjects/CircleObject.cpp Game/GameFiles/GameObjects/CircleObject.hpp
        Game/GameFiles/GameObjects/MovingDanger.cpp Game/GameFiles/GameObjects/MovingDanger.hpp
        Game/GameFiles/GameObjects/Finish.cpp Game/GameFiles/GameObjects/Finish.hpp
        Game/GameFiles/Level.cpp Game/GameFiles/Level.hpp Game/ProtoClient/ProtoClient.cpp Game/ProtoClient/ProtoClient.hpp)

target_link_libraries(SmartSquareRL
        gRPC_Client
        sfml-system
        sfml-window
        sfml-graphics
        ${_REFLECTION}
        ${_GRPC_GRPCPP}
        ${_PROTOBUF_LIBPROTOBUF})