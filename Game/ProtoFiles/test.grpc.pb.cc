// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: test.proto

#include "test.pb.h"
#include "test.grpc.pb.h"

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
namespace Test {

static const char* GetInfo_method_names[] = {
  "/Test.GetInfo/GetLevelInfo",
};

std::unique_ptr< GetInfo::Stub> GetInfo::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< GetInfo::Stub> stub(new GetInfo::Stub(channel, options));
  return stub;
}

GetInfo::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_GetLevelInfo_(GetInfo_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status GetInfo::Stub::GetLevelInfo(::grpc::ClientContext* context, const ::Test::LevelInfoRequest& request, ::Test::LevelInfoReplay* response) {
  return ::grpc::internal::BlockingUnaryCall< ::Test::LevelInfoRequest, ::Test::LevelInfoReplay, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetLevelInfo_, context, request, response);
}

void GetInfo::Stub::async::GetLevelInfo(::grpc::ClientContext* context, const ::Test::LevelInfoRequest* request, ::Test::LevelInfoReplay* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::Test::LevelInfoRequest, ::Test::LevelInfoReplay, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetLevelInfo_, context, request, response, std::move(f));
}

void GetInfo::Stub::async::GetLevelInfo(::grpc::ClientContext* context, const ::Test::LevelInfoRequest* request, ::Test::LevelInfoReplay* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetLevelInfo_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::Test::LevelInfoReplay>* GetInfo::Stub::PrepareAsyncGetLevelInfoRaw(::grpc::ClientContext* context, const ::Test::LevelInfoRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::Test::LevelInfoReplay, ::Test::LevelInfoRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetLevelInfo_, context, request);
}

::grpc::ClientAsyncResponseReader< ::Test::LevelInfoReplay>* GetInfo::Stub::AsyncGetLevelInfoRaw(::grpc::ClientContext* context, const ::Test::LevelInfoRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetLevelInfoRaw(context, request, cq);
  result->StartCall();
  return result;
}

GetInfo::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      GetInfo_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< GetInfo::Service, ::Test::LevelInfoRequest, ::Test::LevelInfoReplay, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](GetInfo::Service* service,
             ::grpc::ServerContext* ctx,
             const ::Test::LevelInfoRequest* req,
             ::Test::LevelInfoReplay* resp) {
               return service->GetLevelInfo(ctx, req, resp);
             }, this)));
}

GetInfo::Service::~Service() {
}

::grpc::Status GetInfo::Service::GetLevelInfo(::grpc::ServerContext* context, const ::Test::LevelInfoRequest* request, ::Test::LevelInfoReplay* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace Test

