#include "ProtoClient.hpp"

using namespace GameMessage;

char *ProtoClient::StateAction(GameStateHandling *gameStateHandling, int32_t clockTime, int32_t iteration) {

    State request;

    request.set_clocktime(clockTime);
    request.set_iteration(iteration);

    request.set_closestobstacleisbox(gameStateHandling->closestObstacleIsBox);
    request.set_allcoinscollected(gameStateHandling->allCoinsCollected);
    request.set_coininfov(gameStateHandling->coinInFoV);

    request.set_raydistances(gameStateHandling->rayDistances);
    request.set_closestdestinationdistx(gameStateHandling->closestDestinationDirX);
    request.set_closestdestinationdisty(gameStateHandling->closestDestinationDirY);
    request.set_closestenemydistx(gameStateHandling->closestEnemyDirX);
    request.set_closestenemydisty(gameStateHandling->closestEnemyDirY);


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


bool ProtoClient::StateReset(GameStateHandling *gameStateHandling) {

    State request;

    request.set_reward(gameStateHandling->reward);
    request.set_gameover(gameStateHandling->gameOver);

    request.set_closestobstacleisbox(gameStateHandling->closestObstacleIsBox);
    request.set_allcoinscollected(gameStateHandling->allCoinsCollected);
    request.set_coininfov(gameStateHandling->coinInFoV);

    request.set_raydistances(gameStateHandling->rayDistances);
    request.set_closestdestinationdistx(gameStateHandling->closestDestinationDirX);
    request.set_closestdestinationdisty(gameStateHandling->closestDestinationDirY);
    request.set_closestenemydistx(gameStateHandling->closestEnemyDirX);
    request.set_closestenemydisty(gameStateHandling->closestEnemyDirY);

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