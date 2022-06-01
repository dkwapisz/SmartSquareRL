#include <grpc/support/log.h>
#include <grpcpp/grpcpp.h>
#include "../ProtoFiles/test.grpc.pb.h"

#include <iostream>
#include <memory>
#include <thread>

using grpc::Channel;
using grpc::ClientAsyncResponseReader;
using grpc::ClientContext;
using grpc::CompletionQueue;
using grpc::Status;

using Test::GetInfo;
using Test::LevelInfoReplay;
using Test::LevelInfoRequest;


class TestClient {
public:
    explicit TestClient(std::shared_ptr<Channel> channel) : stub_(GetInfo::NewStub(channel)) {}

    void GetLevelInfo(const std::int32_t& playerCoins, const std::int32_t& levelCoins) {
        LevelInfoRequest request;
        request.set_playercoins(playerCoins);
        request.set_levelcoins(levelCoins);

        auto* call = new AsyncClientCall;

        call->response_reader =
                stub_ -> PrepareAsyncGetLevelInfo(&call->context, request, &cq_);

        call->response_reader->StartCall();

        call->response_reader->Finish(&call->reply, &call->status, (void*)call);
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

            if (call->status.ok()) {
                std::cout << "Greeter received coins: " << call-> reply.playercoins() << std::endl;
                std::cout << "Greeter received levelCoins: " << call -> reply.levelcoins() << std::endl;
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
        LevelInfoReplay reply;

        // Context for the client. It could be used to convey extra information to
        // the server and/or tweak certain RPC behaviors.
        ClientContext context;

        // Storage for the status of the RPC upon completion.
        Status status;

        std::unique_ptr<ClientAsyncResponseReader<LevelInfoReplay>> response_reader;
    };

    // Out of the passed in Channel comes the stub, stored here, our view of the
    // server's exposed services.
    std::unique_ptr<GetInfo::Stub> stub_;

    // The producer-consumer queue we use to communicate asynchronously with the
    // gRPC runtime.
    CompletionQueue cq_;
};

int main() {
    // Instantiate the client. It requires a channel, out of which the actual RPCs
    // are created. This channel models a connection to an endpoint (in this case,
    // localhost at port 50051). We indicate that the channel isn't authenticated
    // (use of InsecureChannelCredentials()).
    TestClient getLevelInfo(grpc::CreateChannel(
            "localhost:50051", grpc::InsecureChannelCredentials()));

    // Spawn reader thread that loops indefinitely
    std::thread thread_ = std::thread(&TestClient::AsyncCompleteRpc, &getLevelInfo);

    for (int i = 0; i < 100; i++) {
        getLevelInfo.GetLevelInfo(10, 10);  // The actual RPC call!
    }

    std::cout << "Press control-c to quit" << std::endl << std::endl;
    thread_.join();  // blocks forever

    return 0;
}