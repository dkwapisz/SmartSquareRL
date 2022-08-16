// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: game.proto

#include "game.pb.h"
#include "game.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace GameMessage {

    static const char *StateActionExchange_method_names[] = {
            "/GameMessage.StateActionExchange/StateAction",
            "/GameMessage.StateActionExchange/StateReset",
    };

    std::unique_ptr<StateActionExchange::Stub>
    StateActionExchange::NewStub(const std::shared_ptr<::grpc::ChannelInterface> &channel,
                                 const ::grpc::StubOptions &options) {
        (void) options;
        std::unique_ptr<StateActionExchange::Stub> stub(new StateActionExchange::Stub(channel, options));
        return stub;
    }

    StateActionExchange::Stub::Stub(const std::shared_ptr<::grpc::ChannelInterface> &channel,
                                    const ::grpc::StubOptions &options)
            : channel_(channel), rpcmethod_StateAction_(StateActionExchange_method_names[0], options.suffix_for_stats(),
                                                        ::grpc::internal::RpcMethod::NORMAL_RPC, channel),
              rpcmethod_StateReset_(StateActionExchange_method_names[1], options.suffix_for_stats(),
                                    ::grpc::internal::RpcMethod::NORMAL_RPC, channel) {}

    ::grpc::Status
    StateActionExchange::Stub::StateAction(::grpc::ClientContext *context, const ::GameMessage::State &request,
                                           ::GameMessage::Action *response) {
        return ::grpc::internal::BlockingUnaryCall<::GameMessage::State, ::GameMessage::Action, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
                channel_.get(), rpcmethod_StateAction_, context, request, response);
    }

    void
    StateActionExchange::Stub::async::StateAction(::grpc::ClientContext *context, const ::GameMessage::State *request,
                                                  ::GameMessage::Action *response,
                                                  std::function<void(::grpc::Status)> f) {
        ::grpc::internal::CallbackUnaryCall<::GameMessage::State, ::GameMessage::Action, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
                stub_->channel_.get(), stub_->rpcmethod_StateAction_, context, request, response, std::move(f));
    }

    void
    StateActionExchange::Stub::async::StateAction(::grpc::ClientContext *context, const ::GameMessage::State *request,
                                                  ::GameMessage::Action *response,
                                                  ::grpc::ClientUnaryReactor *reactor) {
        ::grpc::internal::ClientCallbackUnaryFactory::Create<::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
                stub_->channel_.get(), stub_->rpcmethod_StateAction_, context, request, response, reactor);
    }

    ::grpc::ClientAsyncResponseReader<::GameMessage::Action> *
    StateActionExchange::Stub::PrepareAsyncStateActionRaw(::grpc::ClientContext *context,
                                                          const ::GameMessage::State &request,
                                                          ::grpc::CompletionQueue *cq) {
        return ::grpc::internal::ClientAsyncResponseReaderHelper::Create<::GameMessage::Action, ::GameMessage::State, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
                channel_.get(), cq, rpcmethod_StateAction_, context, request);
    }

    ::grpc::ClientAsyncResponseReader<::GameMessage::Action> *
    StateActionExchange::Stub::AsyncStateActionRaw(::grpc::ClientContext *context, const ::GameMessage::State &request,
                                                   ::grpc::CompletionQueue *cq) {
        auto *result =
                this->PrepareAsyncStateActionRaw(context, request, cq);
        result->StartCall();
        return result;
    }

    ::grpc::Status
    StateActionExchange::Stub::StateReset(::grpc::ClientContext *context, const ::GameMessage::State &request,
                                          ::GameMessage::Reset *response) {
        return ::grpc::internal::BlockingUnaryCall<::GameMessage::State, ::GameMessage::Reset, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
                channel_.get(), rpcmethod_StateReset_, context, request, response);
    }

    void
    StateActionExchange::Stub::async::StateReset(::grpc::ClientContext *context, const ::GameMessage::State *request,
                                                 ::GameMessage::Reset *response,
                                                 std::function<void(::grpc::Status)> f) {
        ::grpc::internal::CallbackUnaryCall<::GameMessage::State, ::GameMessage::Reset, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
                stub_->channel_.get(), stub_->rpcmethod_StateReset_, context, request, response, std::move(f));
    }

    void
    StateActionExchange::Stub::async::StateReset(::grpc::ClientContext *context, const ::GameMessage::State *request,
                                                 ::GameMessage::Reset *response, ::grpc::ClientUnaryReactor *reactor) {
        ::grpc::internal::ClientCallbackUnaryFactory::Create<::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
                stub_->channel_.get(), stub_->rpcmethod_StateReset_, context, request, response, reactor);
    }

    ::grpc::ClientAsyncResponseReader<::GameMessage::Reset> *
    StateActionExchange::Stub::PrepareAsyncStateResetRaw(::grpc::ClientContext *context,
                                                         const ::GameMessage::State &request,
                                                         ::grpc::CompletionQueue *cq) {
        return ::grpc::internal::ClientAsyncResponseReaderHelper::Create<::GameMessage::Reset, ::GameMessage::State, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
                channel_.get(), cq, rpcmethod_StateReset_, context, request);
    }

    ::grpc::ClientAsyncResponseReader<::GameMessage::Reset> *
    StateActionExchange::Stub::AsyncStateResetRaw(::grpc::ClientContext *context, const ::GameMessage::State &request,
                                                  ::grpc::CompletionQueue *cq) {
        auto *result =
                this->PrepareAsyncStateResetRaw(context, request, cq);
        result->StartCall();
        return result;
    }

    StateActionExchange::Service::Service() {
        AddMethod(new ::grpc::internal::RpcServiceMethod(
                StateActionExchange_method_names[0],
                ::grpc::internal::RpcMethod::NORMAL_RPC,
                new ::grpc::internal::RpcMethodHandler<StateActionExchange::Service, ::GameMessage::State, ::GameMessage::Action, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
                        [](StateActionExchange::Service *service,
                           ::grpc::ServerContext *ctx,
                           const ::GameMessage::State *req,
                           ::GameMessage::Action *resp) {
                            return service->StateAction(ctx, req, resp);
                        }, this)));
        AddMethod(new ::grpc::internal::RpcServiceMethod(
                StateActionExchange_method_names[1],
                ::grpc::internal::RpcMethod::NORMAL_RPC,
                new ::grpc::internal::RpcMethodHandler<StateActionExchange::Service, ::GameMessage::State, ::GameMessage::Reset, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
                        [](StateActionExchange::Service *service,
                           ::grpc::ServerContext *ctx,
                           const ::GameMessage::State *req,
                           ::GameMessage::Reset *resp) {
                            return service->StateReset(ctx, req, resp);
                        }, this)));
    }

    StateActionExchange::Service::~Service() {
    }

    ::grpc::Status
    StateActionExchange::Service::StateAction(::grpc::ServerContext *context, const ::GameMessage::State *request,
                                              ::GameMessage::Action *response) {
        (void) context;
        (void) request;
        (void) response;
        return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }

    ::grpc::Status
    StateActionExchange::Service::StateReset(::grpc::ServerContext *context, const ::GameMessage::State *request,
                                             ::GameMessage::Reset *response) {
        (void) context;
        (void) request;
        (void) response;
        return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }


}  // namespace GameMessage

