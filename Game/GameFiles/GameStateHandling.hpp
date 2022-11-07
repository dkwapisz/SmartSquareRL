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
    bool finishInFoV;
    bool gameOver;
    bool win;
    int32_t reward;
    float lastDistToCoin;
    float lastFinishDist;
    int stepsCount;
    int discoveredFloorCount;
    int MAP_SIZE;

    std::string rayDistances;

    int* mapMatrix;
    std::string mapMatrixAsString;

    GameStateHandling();

    void calculateClosestEnemyDir(std::vector<StaticDanger *> *staticDangers,
                                  std::vector<MovingDanger *> *movingDangers, Player *player);

    void calculateClosestCoinDir(std::vector<Coin *> *coins, Player *player,
                                 bool coinInFoV_, Coin *closestCoin, int playerCoinsCount);

    void calculateFinishDirectionDir(std::vector<Finish *> *finishes, bool finishInFoV_, Player *player);

    void resetAllStates();

    void calculateMapMatrix(float playerX, float playerY, std::vector<Floor *> *floors, std::vector<Finish *> *finishes);
};

#endif