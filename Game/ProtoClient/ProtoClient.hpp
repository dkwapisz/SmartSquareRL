#ifndef PROTOCLIENT_HPP
#define PROTOCLIENT_HPP

#include <grpc/support/log.h>
#include <grpcpp/grpcpp.h>
#include "ProtoFiles/game.grpc.pb.h"

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

class ProtoClient {
private:
    struct AsyncClientCall {
        Action reply;
        ClientContext context;
        Status status;
        std::unique_ptr<ClientAsyncResponseReader<Action>> response_reader;
    };
    std::unique_ptr<ExchangeGameState::Stub> stub_;
    CompletionQueue cq_;
    char shotAction;
    char moveAction;
    void setMoveAction(GameMessage::Action_ActionDirection moveDirection);
    void setShotAction(GameMessage::Action_ActionDirection moveDirection);
public:
    explicit ProtoClient(std::shared_ptr<Channel> channel) : stub_(ExchangeGameState::NewStub(channel)) {}
    void Exchange(bool closestObstacleBox,
                              int32_t coinsNeeded,
                              GameMessage::GameState_ObjectDirection closestObstacleDir,
                              GameMessage::GameState_ObjectDirection closestCoinDir,
                              GameMessage::GameState_ObjectDirection closestEnemyDir,
                              GameMessage::GameState_ObjectDirection finishDir,
                              int32_t reward);

    void AsyncCompleteRpc();
    char getMoveAction() const;
    char getShotAction() const;
};

#endif //PROTOCLIENT_HPP
