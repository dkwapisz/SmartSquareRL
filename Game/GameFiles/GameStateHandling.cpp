#include "GameStateHandling.hpp"
#include "GameObjects/Floor.hpp"


GameStateHandling::GameStateHandling(int mapSize) {
    MAP_SIZE = mapSize;
    resetAllStates();
}

void GameStateHandling::calculateClosestCoinDir(std::vector<Coin *> *coins, Player *player,
                                                bool coinInFoV_, Coin *closestCoin) {

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

void GameStateHandling::resetAllStates() {
    mapMatrix = new int[MAP_SIZE * MAP_SIZE];
    mapMatrixAsString = "";
    stepsCount = 0;
    allCoinsCollected = false;
    coinInFoV = false;
    gameOver = false;
    win = false;
    reward = 0;
    lastDistToCoin = 9999999.f;
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