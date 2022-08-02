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

using namespace GameMessage;

class ProtoClient {
private:
    std::unique_ptr<StateActionExchange::Stub> _stub;
    char convertActionDir(GameMessage::Action_ActionDirection actionDirection);

public:
    ProtoClient(std::shared_ptr<Channel> channel) : _stub{StateActionExchange::NewStub(channel)} {}
    // TODO Wrap State into nested message to easier handling

    char *StateAction(bool isClosestObstacleBox, bool coinsNeeded,
                      State_ObjectDirection closestObstacle, State_ObjectDirection closestCoin,
                      State_ObjectDirection closestEnemy, State_ObjectDirection finishDirection,
                      int32_t clockTime, int32_t iteration);

    bool StateReset(bool isClosestObstacleBox, bool coinsNeeded,
                    State_ObjectDirection closestObstacle, State_ObjectDirection closestCoin,
                    State_ObjectDirection closestEnemy, State_ObjectDirection finishDirection,
                    int32_t reward, bool gameOver);
};

