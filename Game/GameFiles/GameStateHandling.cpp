#include "GameStateHandling.hpp"
#include "GameObjects/Floor.hpp"


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
        std::cout << "Coin is not in fov" << "\n";
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
            reward += 3;
        } else {
            reward -= 10;
        }
        lastDistToCoin = coinDist;
    }
}

void GameStateHandling::calculateFinishDirectionDir(std::vector<Finish *> *finishes, bool finishInFoV_, Player *player) {
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
                reward += 5;
            } else {
                reward -= 10;
            }
            lastFinishDist = finishDist;
        }

    }

}

void GameStateHandling::resetAllStates() {
    mapMatrix = new int[20 * 20];
    mapMatrixAsString = "";
    stepsCount = 0;
    allCoinsCollected = false;
    coinInFoV = false;
    finishInFoV = false;
    gameOver = false;
    reward = 0;
    discoveredFloorCount = 0;
    lastDistToCoin = 9999999.f;
    lastFinishDist = 9999999.f;
    for (int i = 0; i < 400; i++) {
        mapMatrix[i] = 0;
        mapMatrixAsString.push_back('0');
    }
}

void GameStateHandling::calculateMapMatrix(float playerX, float playerY, std::vector<Floor *> *floors) {
    int playerMapPosX = (int) playerX / 30;
    int playerMapPosY = (int) (playerY - 50) / 30;

    for (int y = 0; y < 20; y++) {
        for (int x = 0; x < 20; x++) {
            if (mapMatrix[x + y * 20] == 8) {
                mapMatrix[x + y * 20] = 0;
            }
        }
    }

    int discoveredFloorActualStep = 0;
    for (auto &floor : *floors) {
        if (floor->discovered) {
            discoveredFloorActualStep++;
            int floorX = (int) floor->getCenterPosX() / 30;
            int floorY = (int) (floor->getCenterPosY() - 50) / 30;
            mapMatrix[floorX + floorY * 20] = 9;
        }
    }

    if (discoveredFloorCount < discoveredFloorActualStep && stepsCount > 3) {
        reward += (discoveredFloorActualStep - discoveredFloorCount)*2;
    }
    discoveredFloorCount = discoveredFloorActualStep;

    mapMatrix[playerMapPosX + playerMapPosY * 20] = 8;
    mapMatrixAsString = "";

    for (int y = 0; y < 20; y++) {
        for (int x = 0; x < 20; x++) {
            mapMatrixAsString.append(std::to_string(mapMatrix[x + y * 20]));
        }
        mapMatrixAsString.append("#");
    }
}