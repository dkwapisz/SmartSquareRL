#include "Game.hpp"
#include <thread>
#include <grpcpp/create_channel.h>
#include "../ProtoClient/ProtoClient.hpp"

void runGame(Game *game, ProtoClient *client) {
    game -> run(client);
}

int main() {
    ProtoClient client(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));

    Game game;

    std::thread threadGame = std::thread(runGame, &game, &client);
    std::thread threadClient = std::thread(&ProtoClient::AsyncCompleteRpc, &client);

    threadGame.join();
    threadClient.join();

    return 0;
}
