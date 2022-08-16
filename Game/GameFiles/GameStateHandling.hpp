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
    void initializeStructures();

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
    float lastDiscoveredWallDirX;
    float lastDiscoveredWallDirY;

    struct {
        bool UP;
        bool RIGHT;
        bool DOWN;
        bool LEFT;
    } obstacleDirection;
    struct {
        bool UP;
        bool RIGHT;
        bool DOWN;
        bool LEFT;
    } coinDirection;
    struct {
        bool UP;
        bool RIGHT;
        bool DOWN;
        bool LEFT;
    } enemyDirection;
    struct {
        bool UP;
        bool RIGHT;
        bool DOWN;
        bool LEFT;
    } finishDirection;
    struct {
        bool UP;
        bool RIGHT;
        bool DOWN;
        bool LEFT;
    } lastDiscoveredWall;

    GameStateHandling();

    void calculateClosestObstacleDir(std::vector<Wall *> *walls, std::vector<Box *> *boxes, Player *player);

    void calculateClosestEnemyDir(std::vector<StaticDanger *> *staticDangers,
                                  std::vector<MovingDanger *> *movingDangers, Player *player);

    void calculateClosestCoinDir(std::vector<Coin *> *coins, Player *player,
                                 bool coinInFoV_, Coin *closestCoin, int playerCoinsCount);

    void calculateFinishDirectionDir(std::vector<Finish *> *finishes, bool finishInFoV_, Player *player);

    void calculateLastDiscoveredWallDir(Wall *wall, Player *player);

    void resetAllStates();
};

#endif