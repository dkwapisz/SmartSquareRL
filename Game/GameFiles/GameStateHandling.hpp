// Author:       Dawid Kwapisz (dkwapisz99@gmail.com, dkwapisz@student.agh.edu.pl)
// License:      GPLv3

#ifndef GAMESTATEHANDLING_H
#define GAMESTATEHANDLING_H

#include <cstdint>
#include <vector>
#include <cmath>
#include "GameObjects/Wall.hpp"
#include "GameObjects/Box.hpp"
#include "GameObjects/Player.hpp"
#include "GameObjects/MovingDanger.hpp"
#include "GameObjects/Finish.hpp"
#include "GameObjects/Floor.hpp"

class GameStateHandling {

private:
public:
    bool allCoinsCollected;
    bool coinInFoV;
    bool gameOver;
    bool win;
    int32_t reward;
    float lastDistToCoin;
    int stepsCount;
    int MAP_SIZE;

    std::string rayDistances;

    int *mapMatrix;
    std::string mapMatrixAsString;

    explicit GameStateHandling(int mapSize);

    void calculateClosestCoinDir(std::vector<Coin *> *coins, Player *player, bool coinInFoV_, Coin *closestCoin);

    void resetAllStates();

    void calculateMapMatrix(float playerX, float playerY, std::vector<Floor *> *floors, std::vector<Finish *> *finishes);
};

#endif