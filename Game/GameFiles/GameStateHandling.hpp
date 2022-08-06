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
public:
    bool closestObstacleIsBox;
    bool allCoinsCollected;
    bool gameOver;
    int32_t reward;

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
    } enemyDirection ;
    struct {
        bool UP;
        bool RIGHT;
        bool DOWN;
        bool LEFT;
    } finishDirection ;

    GameStateHandling();
    void calculateClosestObstacleDir(std::vector<Wall *> *walls, std::vector<Box *> *boxes, Player *player);
    void calculateClosestEnemyDir(std::vector<StaticDanger *> *staticDangers,
                                         std::vector<MovingDanger *> *movingDangers, Player *player);
    void calculateClosestCoinDir(std::vector<Coin *> *coins, Player *player, bool coinInFoV);
    void calculateFinishDirectionDir(std::vector<Finish *> *finishes, Player *player);
};

#endif