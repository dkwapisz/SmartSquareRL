cmake_minimum_required(VERSION 3.8)
project(SmartSquareRL)

#find_package(SFML COMPONENTS system window graphics REQUIRED)

include(gRPC.cmake)

get_filename_component(testProto "Game/ProtoClient/ProtoFiles/test.proto" ABSOLUTE)
get_filename_component(testProtoPath "${testProto}" PATH)
set(testProtoSrcs "Game/ProtoClient/ProtoFiles/test.pb.cc")
set(testProtoHdrs "Game/ProtoClient/ProtoFiles/test.pb.h")
set(testGrpcSrcs "Game/ProtoClient/ProtoFiles/test.grpc.pb.cc")
set(testGrpcHdrs "Game/ProtoClient/ProtoFiles/test.grpc.pb.h")

#add_custom_command(
#        OUTPUT "${testProtoSrcs}" "${testProtoHdrs}" "${testGrpcSrcs}" "${testGrpcHdrs}"
#        COMMAND ${_PROTOBUF_PROTOC}
#        ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
#        --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
#        -I "${testProtoPath}"
#        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
#        "${testProto}"
#        DEPENDS "${testProto}")

include_directories("${CMAKE_CURRENT_BINARY_DIR}")

add_library(gRPC_Client
        ${testProtoSrcs}
        ${testProtoHdrs}
        ${testGrpcSrcs}
        ${testGrpcHdrs})

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
        Game/GameFiles/Level.cpp Game/GameFiles/Level.hpp Game/ProtoClient/testProtoClient.cpp)

target_link_libraries(SmartSquareRL
        gRPC_Client
        sfml-system
        sfml-window
        sfml-graphics
        ${_REFLECTION}
        ${_GRPC_GRPCPP}
        ${_PROTOBUF_LIBPROTOBUF})