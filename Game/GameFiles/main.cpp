#include "Game.hpp"
#include <thread>
#include <grpcpp/create_channel.h>
#include "../ProtoClient/ProtoClient.hpp"

void runGame(Game *game) {
    game->run();
}

GameMessage::GameState_ObjectDirection convertDirFromChar(char dir) {
    // TODO IMPORTANT - ADD NEW ENUM VALUE, DIFFERENT THAN 0 WHICH DESCRIBES STATE "OBJECT NOT ON THE MAP"
    // TODO BOOL FALSE VALUE IS A DEFAULT VALUE - DOES NOT APPEAR ON REQUEST IN SERVER SIDE

    if (dir == 'U') {
        return GameMessage::GameState_ObjectDirection_UP;
    }
    else if (dir == 'R') {
        return GameMessage::GameState_ObjectDirection_RIGHT;
    }
    else if (dir == 'D') {
        return GameMessage::GameState_ObjectDirection_DOWN;
    }
    else if (dir == 'L') {
        return GameMessage::GameState_ObjectDirection_LEFT;
    } else {
        return GameMessage::GameState_ObjectDirection_DEFAULT;
    }
}

void sendToServer(ProtoClient *client, Level *level) {
    while (true) {
        client -> Exchange(level -> isClosestObstacleBox(),
                           level -> getCoinsNeeded(),
                           convertDirFromChar(level -> getClosestObstacleDir()),
                           convertDirFromChar(level -> getClosestCoinDir()),
                           convertDirFromChar(level -> getClosestEnemyDir()),
                           convertDirFromChar(level -> getFinishDirectionDir()));
        sleep(1); // If not sleep, it crushes whole system after a couple of seconds.
    }

}

int main() {
    ProtoClient client(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));

    Game game;

    std::thread threadGame = std::thread(runGame, &game);
    std::thread threadClient = std::thread(&ProtoClient::AsyncCompleteRpc, &client);
    std::thread threadExchange = std::thread(sendToServer, &client, game.getLevel());

    threadGame.join();
    threadClient.join();
    threadExchange.join();

    return 0;
}
