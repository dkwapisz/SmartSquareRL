// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: game.proto
#ifndef GRPC_game_2eproto__INCLUDED
#define GRPC_game_2eproto__INCLUDED

#include "game.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/client_context.h>
#include <grpcpp/impl/codegen/completion_queue.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace GameMessage {

class ExchangeGameState final {
 public:
  static constexpr char const* service_full_name() {
    return "GameMessage.ExchangeGameState";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status Exchange(::grpc::ClientContext* context, const ::GameMessage::GameState& request, ::GameMessage::Action* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::GameMessage::Action>> AsyncExchange(::grpc::ClientContext* context, const ::GameMessage::GameState& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::GameMessage::Action>>(AsyncExchangeRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::GameMessage::Action>> PrepareAsyncExchange(::grpc::ClientContext* context, const ::GameMessage::GameState& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::GameMessage::Action>>(PrepareAsyncExchangeRaw(context, request, cq));
    }
    class async_interface {
     public:
      virtual ~async_interface() {}
      virtual void Exchange(::grpc::ClientContext* context, const ::GameMessage::GameState* request, ::GameMessage::Action* response, std::function<void(::grpc::Status)>) = 0;
      virtual void Exchange(::grpc::ClientContext* context, const ::GameMessage::GameState* request, ::GameMessage::Action* response, ::grpc::ClientUnaryReactor* reactor) = 0;
    };
    typedef class async_interface experimental_async_interface;
    virtual class async_interface* async() { return nullptr; }
    class async_interface* experimental_async() { return async(); }
   private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::GameMessage::Action>* AsyncExchangeRaw(::grpc::ClientContext* context, const ::GameMessage::GameState& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::GameMessage::Action>* PrepareAsyncExchangeRaw(::grpc::ClientContext* context, const ::GameMessage::GameState& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    ::grpc::Status Exchange(::grpc::ClientContext* context, const ::GameMessage::GameState& request, ::GameMessage::Action* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::GameMessage::Action>> AsyncExchange(::grpc::ClientContext* context, const ::GameMessage::GameState& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::GameMessage::Action>>(AsyncExchangeRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::GameMessage::Action>> PrepareAsyncExchange(::grpc::ClientContext* context, const ::GameMessage::GameState& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::GameMessage::Action>>(PrepareAsyncExchangeRaw(context, request, cq));
    }
    class async final :
      public StubInterface::async_interface {
     public:
      void Exchange(::grpc::ClientContext* context, const ::GameMessage::GameState* request, ::GameMessage::Action* response, std::function<void(::grpc::Status)>) override;
      void Exchange(::grpc::ClientContext* context, const ::GameMessage::GameState* request, ::GameMessage::Action* response, ::grpc::ClientUnaryReactor* reactor) override;
     private:
      friend class Stub;
      explicit async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class async* async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::GameMessage::Action>* AsyncExchangeRaw(::grpc::ClientContext* context, const ::GameMessage::GameState& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::GameMessage::Action>* PrepareAsyncExchangeRaw(::grpc::ClientContext* context, const ::GameMessage::GameState& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_Exchange_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status Exchange(::grpc::ServerContext* context, const ::GameMessage::GameState* request, ::GameMessage::Action* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_Exchange : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_Exchange() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_Exchange() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Exchange(::grpc::ServerContext* /*context*/, const ::GameMessage::GameState* /*request*/, ::GameMessage::Action* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestExchange(::grpc::ServerContext* context, ::GameMessage::GameState* request, ::grpc::ServerAsyncResponseWriter< ::GameMessage::Action>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_Exchange<Service > AsyncService;
  template <class BaseClass>
  class WithCallbackMethod_Exchange : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_Exchange() {
      ::grpc::Service::MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::GameMessage::GameState, ::GameMessage::Action>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::GameMessage::GameState* request, ::GameMessage::Action* response) { return this->Exchange(context, request, response); }));}
    void SetMessageAllocatorFor_Exchange(
        ::grpc::MessageAllocator< ::GameMessage::GameState, ::GameMessage::Action>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::GameMessage::GameState, ::GameMessage::Action>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_Exchange() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Exchange(::grpc::ServerContext* /*context*/, const ::GameMessage::GameState* /*request*/, ::GameMessage::Action* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* Exchange(
      ::grpc::CallbackServerContext* /*context*/, const ::GameMessage::GameState* /*request*/, ::GameMessage::Action* /*response*/)  { return nullptr; }
  };
  typedef WithCallbackMethod_Exchange<Service > CallbackService;
  typedef CallbackService ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_Exchange : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_Exchange() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_Exchange() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Exchange(::grpc::ServerContext* /*context*/, const ::GameMessage::GameState* /*request*/, ::GameMessage::Action* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_Exchange : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_Exchange() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_Exchange() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Exchange(::grpc::ServerContext* /*context*/, const ::GameMessage::GameState* /*request*/, ::GameMessage::Action* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestExchange(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_Exchange : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_Exchange() {
      ::grpc::Service::MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->Exchange(context, request, response); }));
    }
    ~WithRawCallbackMethod_Exchange() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Exchange(::grpc::ServerContext* /*context*/, const ::GameMessage::GameState* /*request*/, ::GameMessage::Action* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* Exchange(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_Exchange : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_Exchange() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::GameMessage::GameState, ::GameMessage::Action>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::GameMessage::GameState, ::GameMessage::Action>* streamer) {
                       return this->StreamedExchange(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_Exchange() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status Exchange(::grpc::ServerContext* /*context*/, const ::GameMessage::GameState* /*request*/, ::GameMessage::Action* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedExchange(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::GameMessage::GameState,::GameMessage::Action>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_Exchange<Service > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_Exchange<Service > StreamedService;
};

}  // namespace GameMessage


#endif  // GRPC_game_2eproto__INCLUDED
