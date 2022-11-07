#include "GameStateHandling.hpp"
#include "GameObjects/Floor.hpp"


GameStateHandling::GameStateHandling() {
    MAP_SIZE = 7;
    resetAllStates();
}

void GameStateHandling::calculateClosestEnemyDir(std::vector<StaticDanger *> *staticDangers,
                                                 std::vector<MovingDanger *> *movingDangers, Player *player) {
//
//    float playerDistanceToStaticDanger = 99999999.f;
//    float tempDistanceStaticDanger;
//    float playerDistanceToMovingDanger = 99999999.f;
//    float tempDistanceMovingDanger;
//
//    StaticDanger closestStaticDanger;
//    MovingDanger closestMovingDanger;
//
//    for (const auto &staticDanger: *staticDangers) {
//        tempDistanceStaticDanger = std::sqrt(
//                powf((player->getCenterPosX() - staticDanger->getCenterPosX()), 2.f) +
//                powf((player->getCenterPosY() - staticDanger->getCenterPosY()), 2.f));
//
//        if (playerDistanceToStaticDanger > tempDistanceStaticDanger) {
//            playerDistanceToStaticDanger = tempDistanceStaticDanger;
//            closestStaticDanger = *staticDanger;
//        }
//    }
//
//    for (const auto &movingDanger: *movingDangers) {
//        tempDistanceMovingDanger = std::sqrt(
//                powf((player->getCenterPosX() - movingDanger->getCenterPosX()), 2.f) +
//                powf((player->getCenterPosY() - movingDanger->getCenterPosY()), 2.f));
//
//        if (playerDistanceToMovingDanger > tempDistanceMovingDanger) {
//            playerDistanceToMovingDanger = tempDistanceMovingDanger;
//            closestMovingDanger = *movingDanger;
//        }
//    }

}

void GameStateHandling::calculateClosestCoinDir(std::vector<Coin *> *coins, Player *player,
                                                bool coinInFoV_, Coin *closestCoin, int playerCoinsCount) {

    this->coinInFoV = coinInFoV_;

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
        //std::cout << "Coin is not in fov" << "\n";
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

    float coinDist = std::sqrt(
            powf((player->getCenterPosX() - closestCoin->getCenterPosX()), 2.f) +
            powf((player->getCenterPosY() - closestCoin->getCenterPosY()), 2.f));

    if (coinInFoV_) {
        if (lastDistToCoin > coinDist) {
            //reward += 1;
        } else {
            reward -= 5;
        }
        lastDistToCoin = coinDist;
    }
}

void GameStateHandling::calculateFinishDirectionDir(std::vector<Finish *> *finishes, bool finishInFoV_, Player *player) {
//    if (allCoinsCollected) {
//        float playerDistanceToFinish = 99999999.f;
//        float tempDistanceFinish;
//
//        Finish closestFinish;
//        this->finishInFoV = finishInFoV_;
//
//        for (const auto &finish: *finishes) {
//            tempDistanceFinish = std::sqrt(
//                    powf((player->getCenterPosX() - finish->getCenterPosX()), 2.f) +
//                    powf((player->getCenterPosY() - finish->getCenterPosY()), 2.f));
//
//            if (playerDistanceToFinish > tempDistanceFinish) {
//                playerDistanceToFinish = tempDistanceFinish;
//                closestFinish = *finish;
//            }
//        }
//
//        float finishDist = std::sqrt(
//                powf((player->getCenterPosX() - closestFinish.getCenterPosX()), 2.f) +
//                powf((player->getCenterPosY() - closestFinish.getCenterPosY()), 2.f));
//
//        if (this->finishInFoV) {
//            if (lastFinishDist > finishDist) {
//                reward += 3;
//            } else {
//                reward -= 10;
//            }
//            lastFinishDist = finishDist;
//        }
//    }
}

void GameStateHandling::resetAllStates() {
    mapMatrix = new int[MAP_SIZE * MAP_SIZE];
    mapMatrixAsString = "";
    stepsCount = 0;
    allCoinsCollected = false;
    coinInFoV = false;
    finishInFoV = false;
    gameOver = false;
    win = false;
    reward = 0;
    discoveredFloorCount = 0;
    lastDistToCoin = 9999999.f;
    lastFinishDist = 9999999.f;
    for (int i = 0; i < MAP_SIZE * MAP_SIZE; i++) {
        mapMatrix[i] = 0;
        mapMatrixAsString.push_back('0');
    }
}

void GameStateHandling::calculateMapMatrix(float playerX, float playerY, std::vector<Floor *> *floors, std::vector<Finish *> *finishes) {
    int playerMapPosX = (int) playerX / 30;
    int playerMapPosY = (int) (playerY - 50) / 30;

    for (int y = 0; y < MAP_SIZE; y++) {
        for (int x = 0; x < MAP_SIZE; x++) {
            if (mapMatrix[x + y * MAP_SIZE] == 8) {
                mapMatrix[x + y * MAP_SIZE] = 0;
            }
        }
    }

    for (auto &floor : *floors) {
        if (floor->discovered) {
            int floorX = (int) floor->getCenterPosX() / 30;
            int floorY = (int) (floor->getCenterPosY() - 50) / 30;
            mapMatrix[floorX + floorY * MAP_SIZE] = 9;
        }
    }

    if (allCoinsCollected) {
        for (auto &finish : *finishes) {
            int finishX = (int) finish->getCenterPosX() / 30;
            int finishY = (int) (finish->getCenterPosY() - 50) / 30;
            mapMatrix[finishX + finishY * MAP_SIZE] = 4; // If all coins are collected, set finish as coin.
        }
    }

    mapMatrix[playerMapPosX + playerMapPosY * MAP_SIZE] = 8;
    mapMatrixAsString = "";

    for (int y = 0; y < MAP_SIZE; y++) {
        for (int x = 0; x < MAP_SIZE; x++) {
            mapMatrixAsString.append(std::to_string(mapMatrix[x + y * MAP_SIZE]));
        }
        mapMatrixAsString.append("#");
    }
}