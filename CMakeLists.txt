cmake_minimum_required(VERSION 3.22)
project(SmartSquareRL)

set(CMAKE_CXX_STANDARD 20)

add_executable(SmartSquareRL Game/main.cpp Game/Board.cpp Game/Board.h Game/Square.cpp Game/Square.h Game/GameObjects/GameObject.cpp Game/GameObjects/GameObject.h Game/GameObjects/Player.cpp Game/GameObjects/Player.h Game/GameObjects/StaticEnemy.cpp Game/GameObjects/StaticEnemy.h Game/GameObjects/MovingEnemy.cpp Game/GameObjects/MovingEnemy.h Game/GameObjects/Box.cpp Game/GameObjects/Box.h Game/GameObjects/Coin.cpp Game/GameObjects/Coin.h Game/GameObjects/Bullet.cpp Game/GameObjects/Bullet.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics REQUIRED)

include_directories(c:/SFML/include)
target_link_libraries(SmartSquareRL sfml-system sfml-window sfml-graphics)