cmake_minimum_required(VERSION 3.8)
project(SmartSquareRL)

if (MINGW)
    add_definitions(-D_WIN32_WINNT=0x600)
endif()

# SFML
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics REQUIRED)

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
        Game/GameFiles/Level.cpp Game/GameFiles/Level.hpp Game/ProtoClient/ProtoClient.cpp
)

find_package(gRPC CONFIG REQUIRED)
if(gRPC_FOUND)
    include_directories(gRPC::grpc++)
endif()

find_package(Protobuf CONFIG REQUIRED)
if(Protobuf_FOUND)
    include_directories(${Protobuf_INCLUDE_DIRS})
    include_directories(${CMAKE_CURRENT_BINARY_DIR})
endif()

target_link_libraries(SmartSquareRL sfml-system sfml-window sfml-graphics)
target_link_libraries(SmartSquareRL gRPC::grpc++)
target_link_libraries(SmartSquareRL ${Protobuf_LIBRARIES})