#include "Game.hpp"
#include <thread>

Level *level;

void runGame() {
    Game game;
    level = game.getLevel();
    game.run();
}

int main() {
    std::thread th1(runGame);
    //std::thread th2();

    th1.join();
    //th2.join();

    return 0;
}
