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

class GameStateHandling {

private:
    int lastCoinsCount;
public:
    bool closestObstacleIsBox;
    bool allCoinsCollected;
    bool coinInFoV;
    bool finishInFoV;
    bool gameOver;
    int32_t reward;
    float lastDistToCoin;
    float lastFinishDist;

    std::string rayDistances;

    float closestDestinationDirX;
    float closestDestinationDirY;
    float closestEnemyDirX;
    float closestEnemyDirY;

    GameStateHandling();

    void calculateClosestEnemyDir(std::vector<StaticDanger *> *staticDangers,
                                  std::vector<MovingDanger *> *movingDangers, Player *player);

    void calculateClosestCoinDir(std::vector<Coin *> *coins, Player *player,
                                 bool coinInFoV_, Coin *closestCoin, int playerCoinsCount);

    void calculateFinishDirectionDir(std::vector<Finish *> *finishes, bool finishInFoV_, Player *player);

    void calculateRayDistances(float playerX, float playerY, float *rayVertexes, int arrayLen);

    void resetAllStates();
};

#endif