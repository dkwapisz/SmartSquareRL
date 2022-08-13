#include "GameStateHandling.hpp"


GameStateHandling::GameStateHandling() {
    resetAllStates();
}

void GameStateHandling::calculateClosestObstacleDir(std::vector<Wall *> *walls, std::vector<Box *> *boxes, Player *player) {
    float playerDistanceToWall = 99999999.f;
    float tempDistanceWall;
    float playerDistanceToBox = 99999999.f;
    float tempDistanceBox;

    obstacleDirection.UP = false;
    obstacleDirection.RIGHT = false;
    obstacleDirection.DOWN = false;
    obstacleDirection.LEFT = false;

    Wall closestWall;
    Box closestBox;

    for (const auto &wall: *walls) {
        tempDistanceWall = std::sqrt(
                powf((player->getCenterPosX() - wall->getCenterPosX()), 2.f) +
                powf((player->getCenterPosY() - wall->getCenterPosY()), 2.f));

        if (playerDistanceToWall > tempDistanceWall) {
            playerDistanceToWall = tempDistanceWall;
            closestWall = *wall;
        }
    }

    if (!boxes->empty()) {
        for (const auto &box: *boxes) {
            tempDistanceBox = std::sqrt(
                    powf((player->getCenterPosX() - box->getCenterPosX()), 2.f) +
                    powf((player->getCenterPosY() - box->getCenterPosY()), 2.f));

            if (playerDistanceToBox > tempDistanceBox) {
                playerDistanceToBox = tempDistanceBox;
                closestBox = *box;
            }
        }
    } else {
        playerDistanceToBox = 99999999.f;
    }

    float dirVecX;
    float dirVecY;
    SquareObject *closestObstacle;

    if (playerDistanceToBox <= playerDistanceToWall) {
        closestObstacleIsBox = true;
        closestObstacle = &closestBox;
    } else {
        closestObstacleIsBox = false;
        closestObstacle = &closestWall;
    }

    dirVecX = closestObstacle->getCenterPosX() - player -> getCenterPosX();
    dirVecY = closestObstacle->getCenterPosY() - player -> getCenterPosY();

    if (std::abs(dirVecY) >= std::abs(dirVecX)) {
        if (dirVecY >= 0) {
            obstacleDirection.DOWN = true;
        } else {
            obstacleDirection.UP = true;
        }
    } else {
        if (dirVecX >= 0) {
            obstacleDirection.RIGHT = true;
        } else {
            obstacleDirection.LEFT = true;
        }
    }

}

void GameStateHandling::calculateClosestEnemyDir(std::vector<StaticDanger *> *staticDangers,
                                                 std::vector<MovingDanger *> *movingDangers, Player *player) {

    float playerDistanceToStaticDanger = 99999999.f;
    float tempDistanceStaticDanger;
    float playerDistanceToMovingDanger = 99999999.f;
    float tempDistanceMovingDanger;

    enemyDirection.UP = false;
    enemyDirection.RIGHT = false;
    enemyDirection.DOWN = false;
    enemyDirection.LEFT = false;

    StaticDanger closestStaticDanger;
    MovingDanger closestMovingDanger;

    for (const auto& staticDanger : *staticDangers) {
        tempDistanceStaticDanger = std::sqrt(
                powf((player -> getCenterPosX() - staticDanger -> getCenterPosX()), 2.f) +
                powf((player -> getCenterPosY() - staticDanger -> getCenterPosY()), 2.f));

        if (playerDistanceToStaticDanger > tempDistanceStaticDanger) {
            playerDistanceToStaticDanger = tempDistanceStaticDanger;
            closestStaticDanger = *staticDanger;
        }
    }

    for (const auto& movingDanger : *movingDangers) {
        tempDistanceMovingDanger = std::sqrt(
                powf((player -> getCenterPosX() - movingDanger -> getCenterPosX()), 2.f) +
                powf((player -> getCenterPosY() - movingDanger -> getCenterPosY()), 2.f));

        if (playerDistanceToMovingDanger > tempDistanceMovingDanger) {
            playerDistanceToMovingDanger = tempDistanceMovingDanger;
            closestMovingDanger = *movingDanger;
        }
    }

    float dirVecX;
    float dirVecY;

    if (playerDistanceToStaticDanger <= playerDistanceToMovingDanger) {
        dirVecX = closestStaticDanger.getCenterPosX() - player -> getCenterPosX();
        dirVecY = closestStaticDanger.getCenterPosY() - player -> getCenterPosY();

        if (dirVecY >= 0) {
            enemyDirection.DOWN = true;
        } else {
            enemyDirection.UP = true;
        }
        if (dirVecX >= 0) {
            enemyDirection.RIGHT = true;
        } else {
            enemyDirection.LEFT = true;
        }

    } else {
        dirVecX = closestMovingDanger.getCenterPosX() - player -> getCenterPosX();
        dirVecY = closestMovingDanger.getCenterPosY() - player -> getCenterPosY();

        if (dirVecY >= 0) {
            enemyDirection.DOWN = true;
        } else {
            enemyDirection.UP = true;
        }
        if (dirVecX >= 0) {
            enemyDirection.RIGHT = true;
        } else {
            enemyDirection.LEFT = true;
        }

    }
}

void GameStateHandling::calculateClosestCoinDir(std::vector<Coin *> *coins, Player *player,
                                                bool coinInFoV, Coin *closestCoin, int playerCoinsCount) {

    coinDirection.UP = false;
    coinDirection.RIGHT = false;
    coinDirection.DOWN = false;
    coinDirection.LEFT = false;

    if (playerCoinsCount != 0 && coinInFoV && coinInFoV != this -> coinInFoV) {
        reward += 30;
    }


    if (lastCoinsCount == playerCoinsCount && !coinInFoV && coinInFoV != this -> coinInFoV) {
        reward -= 50;
    }

    this -> coinInFoV = coinInFoV;
    this -> lastCoinsCount = playerCoinsCount;

    if (coins -> empty()) {
        return;
    }
    if (closestCoin == nullptr && coinInFoV) {
        std::cerr << "Error in calculating closest coin" << "\n";
        return;
    }

    if (!this -> coinInFoV) {
        float playerDistanceToCoin = 99999999.f;
        float tempDistanceCoin;
        std::cout << "coin is not in fov" << "\n";
        for (const auto& coin : *coins) {
            tempDistanceCoin = std::sqrt(
                    powf((player -> getCenterPosX() - coin -> getCenterPosX()), 2.f) +
                    powf((player -> getCenterPosY() - coin -> getCenterPosY()), 2.f));

            if (playerDistanceToCoin > tempDistanceCoin) {
                playerDistanceToCoin = tempDistanceCoin;
                closestCoin = coin;
            }
        }
    }

    float dirVecX = closestCoin -> getCenterPosX() - player -> getCenterPosX();
    float dirVecY = closestCoin -> getCenterPosY() - player -> getCenterPosY();

    float coinDist = std::sqrt(
            powf((player -> getCenterPosX() - closestCoin -> getCenterPosX()), 2.f) +
            powf((player -> getCenterPosY() - closestCoin -> getCenterPosY()), 2.f));

    if (coinInFoV) {
        if (lastDistToCoin > coinDist) {
            reward += 1;
        } else {
            reward -= 10;
        }
        lastDistToCoin = coinDist;
    }

    if (player->getCenterPosX() > closestCoin->getCenterPosX() - closestCoin->getBounds().width/2
    && player->getCenterPosX() < closestCoin->getCenterPosX() + closestCoin->getBounds().width/2) {
        if (dirVecY >= 0) {
            coinDirection.DOWN = true;
        } else {
            coinDirection.UP = true;
        }
        return;
    } else if (player->getCenterPosY() > closestCoin->getCenterPosY() - closestCoin->getBounds().width/2
               && player->getCenterPosY() < closestCoin->getCenterPosY() + closestCoin->getBounds().width/2) {
        if (dirVecX >= 0) {
            coinDirection.RIGHT = true;
        } else {
            coinDirection.LEFT = true;
        }
        return;
    }
    if (dirVecY >= 0) {
        coinDirection.DOWN = true;
    } else {
        coinDirection.UP = true;
    }
    if (dirVecX >= 0) {
        coinDirection.RIGHT = true;
    } else {
        coinDirection.LEFT = true;
    }

}

void GameStateHandling::calculateFinishDirectionDir(std::vector<Finish *> *finishes, bool finishInFoV, Player *player) {
    float playerDistanceToFinish = 99999999.f;
    float tempDistanceFinish;

    finishDirection.UP = false;
    finishDirection.RIGHT = false;
    finishDirection.DOWN = false;
    finishDirection.LEFT = false;

    Finish closestFinish;
    this -> finishInFoV = finishInFoV;

    for (const auto& finish : *finishes) {
        tempDistanceFinish = std::sqrt(
                powf((player -> getCenterPosX() - finish -> getCenterPosX()), 2.f) +
                powf((player -> getCenterPosY() - finish -> getCenterPosY()), 2.f));

        if (playerDistanceToFinish > tempDistanceFinish) {
            playerDistanceToFinish = tempDistanceFinish;
            closestFinish = *finish;
        }
    }

    if (allCoinsCollected) {
        float finishDist = std::sqrt(
                powf((player -> getCenterPosX() - closestFinish.getCenterPosX()), 2.f) +
                powf((player -> getCenterPosY() - closestFinish.getCenterPosY()), 2.f));

        if (this -> finishInFoV) {
            if (lastFinishDist > finishDist) {
                reward += 1;
            } else {
                reward -= 10;
            }
            lastFinishDist = finishDist;
        }
    }

    float dirVecX = closestFinish.getCenterPosX() - player -> getCenterPosX();
    float dirVecY = closestFinish.getCenterPosY() - player -> getCenterPosY();

    if (dirVecY >= 0) {
        finishDirection.DOWN = true;
    } else {
        finishDirection.UP = true;
    }
    if (dirVecX >= 0) {
        finishDirection.RIGHT = true;
    } else {
        finishDirection.LEFT = true;
    }
}

void GameStateHandling::calculateLastDiscoveredWallDir(Wall *wall, Player *player) {

    lastDiscoveredWall.UP = false;
    lastDiscoveredWall.RIGHT = false;
    lastDiscoveredWall.DOWN = false;
    lastDiscoveredWall.LEFT = false;

    float dirVecX = wall->getCenterPosX() - player -> getCenterPosX();
    float dirVecY = wall->getCenterPosY() - player -> getCenterPosY();

//    float discoveredWallDist = std::sqrt(
//            powf((player -> getCenterPosX() - wall -> getCenterPosX()), 2.f) +
//            powf((player -> getCenterPosY() - wall -> getCenterPosY()), 2.f));

    if (!coinInFoV) {
        if (std::abs(dirVecX) > std::abs(dirVecY)) {
            if (std::abs(dirVecX) < std::abs(lastDiscoveredWallDirX)) {
                reward += 1;
            } else {
                reward -= 10;
            }
        } else {
            if (std::abs(dirVecY) < std::abs(lastDiscoveredWallDirY)) {
                reward += 1;
            } else {
                reward -= 10;
            }
        }
        lastDiscoveredWallDirX = dirVecX;
        lastDiscoveredWallDirY = dirVecY;
    }

    if (std::abs(dirVecY) >= std::abs(dirVecX)) {
        if (dirVecY >= 0) {
            lastDiscoveredWall.DOWN = true;
        } else {
            lastDiscoveredWall.UP = true;
        }
    } else {
        if (dirVecX >= 0) {
            lastDiscoveredWall.RIGHT = true;
        } else {
            lastDiscoveredWall.LEFT = true;
        }
    }

}


void GameStateHandling::initializeStructures() {
    obstacleDirection.UP = false;
    obstacleDirection.RIGHT = false;
    obstacleDirection.DOWN = false;
    obstacleDirection.LEFT = false;
    enemyDirection.UP = false;
    enemyDirection.RIGHT = false;
    enemyDirection.DOWN = false;
    enemyDirection.LEFT = false;
    coinDirection.UP = false;
    coinDirection.RIGHT = false;
    coinDirection.DOWN = false;
    coinDirection.LEFT = false;
    finishDirection.UP = false;
    finishDirection.RIGHT = false;
    finishDirection.DOWN = false;
    finishDirection.LEFT = false;
    lastDiscoveredWall.UP = false;
    lastDiscoveredWall.RIGHT = false;
    lastDiscoveredWall.DOWN = false;
    lastDiscoveredWall.LEFT = false;
}

void GameStateHandling::resetAllStates() {
    initializeStructures();
    closestObstacleIsBox = false;
    allCoinsCollected = false;
    coinInFoV = false;
    finishInFoV = false;
    gameOver = false;
    reward = 0;
    lastDistToCoin = 9999999.f;
    lastCoinsCount = 0;
    lastFinishDist = 9999999.f;
    float lastDiscoveredWallDirX = 0;
    float lastDiscoveredWallDirY = 0;
}