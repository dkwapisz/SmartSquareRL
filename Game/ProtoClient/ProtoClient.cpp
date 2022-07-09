#include <grpc/support/log.h>
#include <grpcpp/grpcpp.h>
#include "ProtoFiles/game.grpc.pb.h"
#include "ProtoClient.hpp"

#include <iostream>
#include <memory>
#include <thread>

using grpc::Channel;
using grpc::ClientAsyncResponseReader;
using grpc::ClientContext;
using grpc::CompletionQueue;
using grpc::Status;

using GameMessage::ExchangeGameState;
using GameMessage::GameState;
using GameMessage::Action;

void ProtoClient::Exchange(bool closestObstacleBox,
                           int32_t coinsNeeded,
                           GameMessage::GameState_ObjectDirection closestObstacleDir,
                           GameMessage::GameState_ObjectDirection closestCoinDir,
                           GameMessage::GameState_ObjectDirection closestEnemyDir,
                           GameMessage::GameState_ObjectDirection finishDir) {

    GameState request;

    request.set_isclosestobstaclebox(closestObstacleBox);
    request.set_coinsneeded(coinsNeeded);
    request.set_closestobstacle(closestObstacleDir);
    request.set_closestcoin(closestCoinDir);
    request.set_closestenemy(closestEnemyDir);
    request.set_finishdirection(finishDir);

    auto call = new AsyncClientCall;

    call -> response_reader = stub_ -> PrepareAsyncExchange(&call -> context, request, &cq_);
    call -> response_reader -> StartCall();
    call -> response_reader -> Finish(&call -> reply, &call -> status, (void*) call);
}


void ProtoClient::AsyncCompleteRpc() {
    void* got_tag;
    bool ok = false;
    while (cq_.Next(&got_tag, &ok)) {
        auto* call = static_cast<AsyncClientCall*>(got_tag);

        GPR_ASSERT(ok);

        if (call -> status.ok()) {
            setMoveAction(call -> reply.movedirection());
            setShotAction(call -> reply.shotdirection());
        }
        else {
            std::cout << "RPC failed" << std::endl;
        }

        delete call;
    }
}

void ProtoClient::setMoveAction(GameMessage::Action_ActionDirection moveDirection) {
    switch (moveDirection) {
        case GameMessage::Action_ActionDirection_UP:
            this -> moveAction = 'U';
            break;
        case GameMessage::Action_ActionDirection_DOWN:
            this -> moveAction = 'D';
            break;
        case GameMessage::Action_ActionDirection_RIGHT:
            this -> moveAction = 'R';
            break;
        case GameMessage::Action_ActionDirection_LEFT:
            this -> moveAction = 'L';
            break;
        default:
            this -> moveAction = 'N';
    }
}

void ProtoClient::setShotAction(GameMessage::Action_ActionDirection shotDirection) {
    switch (shotDirection) {
        case GameMessage::Action_ActionDirection_UP:
            this -> shotAction = 'U';
            break;
        case GameMessage::Action_ActionDirection_DOWN:
            this -> shotAction = 'D';
            break;
        case GameMessage::Action_ActionDirection_RIGHT:
            this -> shotAction = 'R';
            break;
        case GameMessage::Action_ActionDirection_LEFT:
            this -> shotAction = 'L';
            break;
        default:
            this -> shotAction = 'N';
    }
}

char ProtoClient::getMoveAction() const {
    return this -> moveAction;
}

char ProtoClient::getShotAction() const {
    return this -> shotAction;
}