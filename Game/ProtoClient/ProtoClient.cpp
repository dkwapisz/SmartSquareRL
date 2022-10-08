#include "ProtoClient.hpp"

using namespace GameMessage;

char *ProtoClient::StateAction(GameStateHandling *gameStateHandling, int32_t coinsLeft, int32_t iteration) {

    State request;

    request.set_stepscount(gameStateHandling->stepsCount);
    request.set_episodecount(iteration);
    request.set_coinsleft(coinsLeft);
    request.set_mapmatrix(gameStateHandling->mapMatrixAsString);


    Action response;
    ClientContext context;
    Status status = _stub->StateAction(&context, request, &response);

    if (status.ok()) {
        char *actionArray = new char[2];
        actionArray[0] = convertActionDir(response.movedirection());
        actionArray[1] = convertActionDir(response.shotdirection());
        return actionArray;
    } else {
        std::cerr << "RPC failed \n";
        std::cerr << status.error_message() << "\n";
    }
}


bool ProtoClient::StateReset(GameStateHandling *gameStateHandling, int32_t iteration, int32_t coinsLeft) {

    State request;

    request.set_reward(gameStateHandling->reward);
    request.set_gameover(gameStateHandling->gameOver);
    request.set_episodecount(iteration);
    request.set_coinsleft(coinsLeft);
    request.set_mapmatrix(gameStateHandling->mapMatrixAsString);

    Reset response;
    ClientContext context;
    Status status = _stub->StateReset(&context, request, &response);

    if (status.ok()) {
        return response.resetneeded();
    } else {
        std::cerr << "RPC failed \n";
        std::cerr << status.error_message() << "\n";
    }
}

char ProtoClient::convertActionDir(GameMessage::Action_ActionDirection actionDirection) {
    switch (actionDirection) {
        case GameMessage::Action_ActionDirection_UP:
            return 'U';
        case GameMessage::Action_ActionDirection_DOWN:
            return 'D';
        case GameMessage::Action_ActionDirection_RIGHT:
            return 'R';
        case GameMessage::Action_ActionDirection_LEFT:
            return 'L';
        default:
            return 'N';
    }
}