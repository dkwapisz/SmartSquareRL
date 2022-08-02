#include "ProtoClient.hpp"

using namespace GameMessage;

char* ProtoClient::StateAction(bool isClosestObstacleBox, bool coinsNeeded, State_ObjectDirection closestObstacle,
                                State_ObjectDirection closestCoin, State_ObjectDirection closestEnemy,
                                State_ObjectDirection finishDirection, int32_t clockTime, int32_t iteration) {

    State request;
    request.set_isclosestobstaclebox(isClosestObstacleBox);
    request.set_coinsneeded(coinsNeeded);
    request.set_closestobstacle(closestObstacle);
    request.set_closestcoin(closestCoin);
    request.set_closestenemy(closestEnemy);
    request.set_finishdirection(finishDirection);
    request.set_clocktime(clockTime);
    request.set_iteration(iteration);

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
    }
}


bool ProtoClient::StateReset(bool isClosestObstacleBox, bool coinsNeeded, State_ObjectDirection closestObstacle,
                              State_ObjectDirection closestCoin, State_ObjectDirection closestEnemy,
                              State_ObjectDirection finishDirection, int32_t reward, bool gameOver) {

    State request;
    request.set_isclosestobstaclebox(isClosestObstacleBox);
    request.set_coinsneeded(coinsNeeded);
    request.set_closestobstacle(closestObstacle);
    request.set_closestcoin(closestCoin);
    request.set_closestenemy(closestEnemy);
    request.set_finishdirection(finishDirection);
    request.set_reward(reward);
    request.set_gameover(gameOver);

    Reset response;
    ClientContext context;
    Status status = _stub -> StateReset(&context, request, &response);

    if (status.ok()) {
        return response.resetneeded();
    } else {
        std::cerr << "RPC failed \n";
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