#include <grpcpp/grpcpp.h>
#include "ProtoFiles/game.grpc.pb.h"
#include "../GameFiles/GameStateHandling.hpp"

#include <iostream>
#include <memory>
#include <thread>

using grpc::Channel;
using grpc::ClientAsyncResponseReader;
using grpc::ClientContext;
using grpc::CompletionQueue;
using grpc::Status;

using namespace GameMessage;

class ProtoClient {
private:
    std::unique_ptr<StateActionExchange::Stub> _stub;

    char convertActionDir(GameMessage::Action_ActionDirection actionDirection);

public:
    ProtoClient(std::shared_ptr<Channel> channel) : _stub{StateActionExchange::NewStub(channel)} {}

    char *StateAction(GameStateHandling *gameStateHandling, int32_t iteration);

    bool StateReset(GameStateHandling *gameStateHandling);
};

