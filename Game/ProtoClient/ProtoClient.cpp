#include "ProtoClient.hpp"

using namespace GameMessage;

char* ProtoClient::StateAction(GameStateHandling *gameStateHandling, int32_t clockTime, int32_t iteration) {

    State request;

    request.set_clocktime(clockTime);
    request.set_iteration(iteration);

    request.set_closestobstacleisbox(gameStateHandling->closestObstacleIsBox);
    request.set_allcoinscollected(gameStateHandling->allCoinsCollected);

    request.mutable_closestobstacle()->set_up(gameStateHandling->obstacleDirection.UP);
    request.mutable_closestobstacle()->set_right(gameStateHandling->obstacleDirection.RIGHT);
    request.mutable_closestobstacle()->set_down(gameStateHandling->obstacleDirection.DOWN);
    request.mutable_closestobstacle()->set_left(gameStateHandling->obstacleDirection.LEFT);

    request.mutable_closestcoin()->set_up(gameStateHandling->coinDirection.UP);
    request.mutable_closestcoin()->set_right(gameStateHandling->coinDirection.RIGHT);
    request.mutable_closestcoin()->set_down(gameStateHandling->coinDirection.DOWN);
    request.mutable_closestcoin()->set_left(gameStateHandling->coinDirection.LEFT);

    request.mutable_closestenemy()->set_up(gameStateHandling->enemyDirection.UP);
    request.mutable_closestenemy()->set_right(gameStateHandling->enemyDirection.RIGHT);
    request.mutable_closestenemy()->set_down(gameStateHandling->enemyDirection.DOWN);
    request.mutable_closestenemy()->set_left(gameStateHandling->enemyDirection.LEFT);

    request.mutable_finishdirection()->set_up(gameStateHandling->finishDirection.UP);
    request.mutable_finishdirection()->set_right(gameStateHandling->finishDirection.RIGHT);
    request.mutable_finishdirection()->set_down(gameStateHandling->finishDirection.DOWN);
    request.mutable_finishdirection()->set_left(gameStateHandling->finishDirection.LEFT);

    Action response;
    ClientContext context;
    Status status = _stub -> StateAction(&context, request, &response);

    if (status.ok()) {
        char* actionArray = new char[2];
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

    request.mutable_closestobstacle()->set_up(gameStateHandling->obstacleDirection.UP);
    request.mutable_closestobstacle()->set_right(gameStateHandling->obstacleDirection.RIGHT);
    request.mutable_closestobstacle()->set_down(gameStateHandling->obstacleDirection.DOWN);
    request.mutable_closestobstacle()->set_left(gameStateHandling->obstacleDirection.LEFT);

    request.mutable_closestcoin()->set_up(gameStateHandling->coinDirection.UP);
    request.mutable_closestcoin()->set_right(gameStateHandling->coinDirection.RIGHT);
    request.mutable_closestcoin()->set_down(gameStateHandling->coinDirection.DOWN);
    request.mutable_closestcoin()->set_left(gameStateHandling->coinDirection.LEFT);

    request.mutable_closestenemy()->set_up(gameStateHandling->enemyDirection.UP);
    request.mutable_closestenemy()->set_right(gameStateHandling->enemyDirection.RIGHT);
    request.mutable_closestenemy()->set_down(gameStateHandling->enemyDirection.DOWN);
    request.mutable_closestenemy()->set_left(gameStateHandling->enemyDirection.LEFT);

    request.mutable_finishdirection()->set_up(gameStateHandling->finishDirection.UP);
    request.mutable_finishdirection()->set_right(gameStateHandling->finishDirection.RIGHT);
    request.mutable_finishdirection()->set_down(gameStateHandling->finishDirection.DOWN);
    request.mutable_finishdirection()->set_left(gameStateHandling->finishDirection.LEFT);

    Reset response;
    ClientContext context;
    Status status = _stub -> StateReset(&context, request, &response);

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