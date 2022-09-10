#include "GameStateHandling.hpp"


GameStateHandling::GameStateHandling() {
    resetAllStates();
}

void GameStateHandling::calculateClosestEnemyDir(std::vector<StaticDanger *> *staticDangers,
                                                 std::vector<MovingDanger *> *movingDangers, Player *player) {

    float playerDistanceToStaticDanger = 99999999.f;
    float tempDistanceStaticDanger;
    float playerDistanceToMovingDanger = 99999999.f;
    float tempDistanceMovingDanger;

    StaticDanger closestStaticDanger;
    MovingDanger closestMovingDanger;

    for (const auto &staticDanger: *staticDangers) {
        tempDistanceStaticDanger = std::sqrt(
                powf((player->getCenterPosX() - staticDanger->getCenterPosX()), 2.f) +
                powf((player->getCenterPosY() - staticDanger->getCenterPosY()), 2.f));

        if (playerDistanceToStaticDanger > tempDistanceStaticDanger) {
            playerDistanceToStaticDanger = tempDistanceStaticDanger;
            closestStaticDanger = *staticDanger;
        }
    }

    for (const auto &movingDanger: *movingDangers) {
        tempDistanceMovingDanger = std::sqrt(
                powf((player->getCenterPosX() - movingDanger->getCenterPosX()), 2.f) +
                powf((player->getCenterPosY() - movingDanger->getCenterPosY()), 2.f));

        if (playerDistanceToMovingDanger > tempDistanceMovingDanger) {
            playerDistanceToMovingDanger = tempDistanceMovingDanger;
            closestMovingDanger = *movingDanger;
        }
    }

    if (playerDistanceToStaticDanger <= playerDistanceToMovingDanger) {
        closestEnemyDirX = closestStaticDanger.getCenterPosX() - player->getCenterPosX();
        closestEnemyDirY = closestStaticDanger.getCenterPosY() - player->getCenterPosY();
    } else {
        closestEnemyDirX = closestMovingDanger.getCenterPosX() - player->getCenterPosX();
        closestEnemyDirY = closestMovingDanger.getCenterPosY() - player->getCenterPosY();
    }
}

void GameStateHandling::calculateClosestCoinDir(std::vector<Coin *> *coins, Player *player,
                                                bool coinInFoV_, Coin *closestCoin, int playerCoinsCount) {

//    if (playerCoinsCount != 0 && coinInFoV_ && coinInFoV_ != this -> coinInFoV) {
//        reward += 30;
//    }
//
//    if (lastCoinsCount == playerCoinsCount && !coinInFoV_ && coinInFoV_ != this -> coinInFoV) {
//        reward -= 50;
//    }

    this->coinInFoV = coinInFoV_;
    this->lastCoinsCount = playerCoinsCount;

    if (coins->empty()) {
        return;
    }
    if (closestCoin == nullptr && coinInFoV_) {
        std::cerr << "Error in calculating closest coin" << "\n";
        return;
    }

    if (!this->coinInFoV) {
        float playerDistanceToCoin = 99999999.f;
        float tempDistanceCoin;
        std::cout << "coin is not in fov" << "\n";
        for (const auto &coin: *coins) {
            tempDistanceCoin = std::sqrt(
                    powf((player->getCenterPosX() - coin->getCenterPosX()), 2.f) +
                    powf((player->getCenterPosY() - coin->getCenterPosY()), 2.f));

            if (playerDistanceToCoin > tempDistanceCoin) {
                playerDistanceToCoin = tempDistanceCoin;
                closestCoin = coin;
            }
        }
    }

    closestDestinationDirX = closestCoin->getCenterPosX() - player->getCenterPosX();
    closestDestinationDirY = closestCoin->getCenterPosY() - player->getCenterPosY();

    float coinDist = std::sqrt(
            powf((player->getCenterPosX() - closestCoin->getCenterPosX()), 2.f) +
            powf((player->getCenterPosY() - closestCoin->getCenterPosY()), 2.f));

    if (coinInFoV_) {
        if (lastDistToCoin > coinDist) {
            //reward += 3;
        } else {
            reward -= 10;
        }
        lastDistToCoin = coinDist;
    }
}

void
GameStateHandling::calculateFinishDirectionDir(std::vector<Finish *> *finishes, bool finishInFoV_, Player *player) {
    float playerDistanceToFinish = 99999999.f;
    float tempDistanceFinish;

    Finish closestFinish;
    this->finishInFoV = finishInFoV_;

    for (const auto &finish: *finishes) {
        tempDistanceFinish = std::sqrt(
                powf((player->getCenterPosX() - finish->getCenterPosX()), 2.f) +
                powf((player->getCenterPosY() - finish->getCenterPosY()), 2.f));

        if (playerDistanceToFinish > tempDistanceFinish) {
            playerDistanceToFinish = tempDistanceFinish;
            closestFinish = *finish;
        }
    }

    if (allCoinsCollected) {
        float finishDist = std::sqrt(
                powf((player->getCenterPosX() - closestFinish.getCenterPosX()), 2.f) +
                powf((player->getCenterPosY() - closestFinish.getCenterPosY()), 2.f));

        if (this->finishInFoV) {
            if (lastFinishDist > finishDist) {
                //reward += 5;
            } else {
                reward -= 10;
            }
            lastFinishDist = finishDist;
        }


        closestDestinationDirX = closestFinish.getCenterPosX() - player->getCenterPosX();
        closestDestinationDirY = closestFinish.getCenterPosY() - player->getCenterPosY();
    }

}

void GameStateHandling::resetAllStates() {
    closestObstacleIsBox = false;
    allCoinsCollected = false;
    coinInFoV = false;
    finishInFoV = false;
    gameOver = false;
    reward = 0;
    lastDistToCoin = 9999999.f;
    lastCoinsCount = 0;
    lastFinishDist = 9999999.f;
}

void GameStateHandling::calculateRayDistances(float playerX, float playerY, float *rayVertexes, int arrayLen) {
    int arrayIterator = 0;
    int multiplicity = 6;
    float len;
    std::string lenString;
    for (int i = 0; i < arrayLen; i++) {
        if (i % multiplicity == 0) {
            len = std::hypot((playerX - rayVertexes[arrayIterator]), (playerY - rayVertexes[arrayIterator + 1]));
            if (len == 0) {
                len = 0.0000000001f;
            }
            lenString.append(std::to_string(len));
            if (i != arrayLen - multiplicity) {
                lenString.append("#");
            }
            arrayIterator += 2;
        }
    }
    //std::cout << (lenString) << "\n";
    rayDistances = lenString;
}
