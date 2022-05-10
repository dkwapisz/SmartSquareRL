cmake_minimum_required(VERSION 3.22)
project(SmartSquareRL)

set(CMAKE_CXX_STANDARD 20)

add_executable(SmartSquareRL Game/main.cpp Game/Game.cpp Game/Game.hpp Game/GameObjects/Player.cpp Game/GameObjects/Player.hpp Game/GameObjects/Bullet.cpp Game/GameObjects/Bullet.hpp Game/GameObjects/Wall.cpp Game/GameObjects/Wall.hpp Game/GameObjects/Box.cpp Game/GameObjects/Box.hpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics REQUIRED)

include_directories(c:/SFML/include)
target_link_libraries(SmartSquareRL sfml-system sfml-window sfml-graphics)