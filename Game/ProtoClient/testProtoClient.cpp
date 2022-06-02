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

using Game::ExchangeGameState;
using Game::GameState;
using Game::Action;


class ProtoClient {
public:
    explicit ProtoClient(std::shared_ptr<Channel> channel) : stub_(ExchangeGameState::NewStub(channel)) {}

    void Exchange() {
        GameState request;

        // TODO Constructor parameters and then put it into request.

        request.set_isclosestobstaclebox(true);
        request.set_coinsneeded(10);
        request.set_closestobstacle(Game::GameState_ObjectDirection_DOWN);
        request.set_closestcoin(Game::GameState_ObjectDirection_DOWN);
        request.set_closestenemy(Game::GameState_ObjectDirection_DOWN);
        request.set_finishdirection(Game::GameState_ObjectDirection_DOWN);

        auto* call = new AsyncClientCall;

        call -> response_reader =
                stub_ -> PrepareAsyncExchange(&call -> context, request, &cq_);

        call -> response_reader -> StartCall();

        call -> response_reader -> Finish(&call -> reply, &call -> status, (void*) call);
    }

    void AsyncCompleteRpc() {
        void* got_tag;
        bool ok = false;

        // Block until the next result is available in the completion queue "cq".
        while (cq_.Next(&got_tag, &ok)) {
            // The tag in this example is the memory location of the call object
            auto* call = static_cast<AsyncClientCall*>(got_tag);

            // Verify that the request was completed successfully. Note that "ok"
            // corresponds solely to the request for updates introduced by Finish().
            GPR_ASSERT(ok);

            if (call -> status.ok()) {
                std::cout << "Received move direction: " << call-> reply.movedirection() << std::endl;
                std::cout << "Received shot direction: " << call -> reply.shotdirection() << std::endl;
            }
            else {
                std::cout << "RPC failed" << std::endl;
            }

            // Once we're complete, deallocate the call object.
            delete call;
        }
    }

private:

    struct AsyncClientCall {
        // Container for the data we expect from the server.
        Action reply;

        // Context for the client. It could be used to convey extra information to
        // the server and/or tweak certain RPC behaviors.
        ClientContext context;

        // Storage for the status of the RPC upon completion.
        Status status;

        std::unique_ptr<ClientAsyncResponseReader<Action>> response_reader;
    };

    // Out of the passed in Channel comes the stub, stored here, our view of the
    // server's exposed services.
    std::unique_ptr<ExchangeGameState::Stub> stub_;

    // The producer-consumer queue we use to communicate asynchronously with the
    // gRPC runtime.
    CompletionQueue cq_;
};

int main() {
    // Instantiate the client. It requires a channel, out of which the actual RPCs
    // are created. This channel models a connection to an endpoint (in this case,
    // localhost at port 50051). We indicate that the channel isn't authenticated
    // (use of InsecureChannelCredentials()).
    ProtoClient client(grpc::CreateChannel(
            "localhost:50051", grpc::InsecureChannelCredentials()));

    // Spawn reader thread that loops indefinitely
    std::thread thread_ = std::thread(&ProtoClient::AsyncCompleteRpc, &client);

    for (int i=0; i < 1000; i++) {
        client.Exchange();  // The actual RPC call!
    }

    std::cout << "Press control-c to quit" << std::endl << std::endl;
    thread_.join();  // blocks forever

    return 0;
}