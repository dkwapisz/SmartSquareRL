#include "Game.hpp"
#include "PipeCommunication.h"
#include <thread>

Level *level;

void runGame() {
    Game game;
    level = game.getLevel();
    game.run();
}

void pipeCom() {
    PipeCommunication pipeCommunication;

    while (true) {
        std::wstring test = L"Coins: ";
        test += std::to_wstring(level -> getPlayerCoinsCount());
        const wchar_t *data = test.c_str();
        pipeCommunication.sendData(data);
    }
}

int main() {
    std::thread th1(runGame);
    std::thread th2(pipeCom);

    th1.join();
    th2.join();

    return 0;
}
