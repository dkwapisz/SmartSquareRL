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
            std::cout << "Received move direction: " << call -> reply.movedirection() << std::endl;
            std::cout << "Received shot direction: " << call -> reply.shotdirection() << std::endl;
        }
        else {
            std::cout << "RPC failed" << std::endl;
        }

        delete call;
    }
}
