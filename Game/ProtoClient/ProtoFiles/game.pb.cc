// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: game.proto

#include "game.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace Game {
PROTOBUF_CONSTEXPR GameState::GameState(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.isclosestobstaclebox_)*/false
  , /*decltype(_impl_.coinsneeded_)*/0
  , /*decltype(_impl_.closestobstacle_)*/0
  , /*decltype(_impl_.closestcoin_)*/0
  , /*decltype(_impl_.closestenemy_)*/0
  , /*decltype(_impl_.finishdirection_)*/0
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct GameStateDefaultTypeInternal {
  PROTOBUF_CONSTEXPR GameStateDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~GameStateDefaultTypeInternal() {}
  union {
    GameState _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 GameStateDefaultTypeInternal _GameState_default_instance_;
PROTOBUF_CONSTEXPR Action::Action(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.movedirection_)*/0
  , /*decltype(_impl_.shotdirection_)*/0
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct ActionDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ActionDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~ActionDefaultTypeInternal() {}
  union {
    Action _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ActionDefaultTypeInternal _Action_default_instance_;
}  // namespace Game
static ::_pb::Metadata file_level_metadata_game_2eproto[2];
static const ::_pb::EnumDescriptor* file_level_enum_descriptors_game_2eproto[2];
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_game_2eproto = nullptr;

const uint32_t TableStruct_game_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Game::GameState, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Game::GameState, _impl_.isclosestobstaclebox_),
  PROTOBUF_FIELD_OFFSET(::Game::GameState, _impl_.coinsneeded_),
  PROTOBUF_FIELD_OFFSET(::Game::GameState, _impl_.closestobstacle_),
  PROTOBUF_FIELD_OFFSET(::Game::GameState, _impl_.closestcoin_),
  PROTOBUF_FIELD_OFFSET(::Game::GameState, _impl_.closestenemy_),
  PROTOBUF_FIELD_OFFSET(::Game::GameState, _impl_.finishdirection_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Game::Action, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Game::Action, _impl_.movedirection_),
  PROTOBUF_FIELD_OFFSET(::Game::Action, _impl_.shotdirection_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::Game::GameState)},
  { 12, -1, -1, sizeof(::Game::Action)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::Game::_GameState_default_instance_._instance,
  &::Game::_Action_default_instance_._instance,
};

const char descriptor_table_protodef_game_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\ngame.proto\022\004Game\"\346\002\n\tGameState\022\034\n\024isCl"
  "osestObstacleBox\030\001 \001(\010\022\023\n\013coinsNeeded\030\002 "
  "\001(\005\0228\n\017closestObstacle\030\003 \001(\0162\037.Game.Game"
  "State.ObjectDirection\0224\n\013closestCoin\030\004 \001"
  "(\0162\037.Game.GameState.ObjectDirection\0225\n\014c"
  "losestEnemy\030\005 \001(\0162\037.Game.GameState.Objec"
  "tDirection\0228\n\017finishDirection\030\006 \001(\0162\037.Ga"
  "me.GameState.ObjectDirection\"E\n\017ObjectDi"
  "rection\022\013\n\007DEFAULT\020\000\022\006\n\002UP\020\001\022\t\n\005RIGHT\020\002\022"
  "\010\n\004DOWN\020\003\022\010\n\004LEFT\020\004\"\271\001\n\006Action\0223\n\rmoveDi"
  "rection\030\001 \001(\0162\034.Game.Action.ActionDirect"
  "ion\0223\n\rshotDirection\030\002 \001(\0162\034.Game.Action"
  ".ActionDirection\"E\n\017ActionDirection\022\013\n\007D"
  "EFAULT\020\000\022\006\n\002UP\020\001\022\t\n\005RIGHT\020\002\022\010\n\004DOWN\020\003\022\010\n"
  "\004LEFT\020\0042@\n\021ExchangeGameState\022+\n\010Exchange"
  "\022\017.Game.GameState\032\014.Game.Action\"\000b\006proto"
  "3"
  ;
static ::_pbi::once_flag descriptor_table_game_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_game_2eproto = {
    false, false, 641, descriptor_table_protodef_game_2eproto,
    "game.proto",
    &descriptor_table_game_2eproto_once, nullptr, 0, 2,
    schemas, file_default_instances, TableStruct_game_2eproto::offsets,
    file_level_metadata_game_2eproto, file_level_enum_descriptors_game_2eproto,
    file_level_service_descriptors_game_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_game_2eproto_getter() {
  return &descriptor_table_game_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_game_2eproto(&descriptor_table_game_2eproto);
namespace Game {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* GameState_ObjectDirection_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_game_2eproto);
  return file_level_enum_descriptors_game_2eproto[0];
}
bool GameState_ObjectDirection_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      return true;
    default:
      return false;
  }
}

#if (__cplusplus < 201703) && (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))
constexpr GameState_ObjectDirection GameState::DEFAULT;
constexpr GameState_ObjectDirection GameState::UP;
constexpr GameState_ObjectDirection GameState::RIGHT;
constexpr GameState_ObjectDirection GameState::DOWN;
constexpr GameState_ObjectDirection GameState::LEFT;
constexpr GameState_ObjectDirection GameState::ObjectDirection_MIN;
constexpr GameState_ObjectDirection GameState::ObjectDirection_MAX;
constexpr int GameState::ObjectDirection_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Action_ActionDirection_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_game_2eproto);
  return file_level_enum_descriptors_game_2eproto[1];
}
bool Action_ActionDirection_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      return true;
    default:
      return false;
  }
}

#if (__cplusplus < 201703) && (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))
constexpr Action_ActionDirection Action::DEFAULT;
constexpr Action_ActionDirection Action::UP;
constexpr Action_ActionDirection Action::RIGHT;
constexpr Action_ActionDirection Action::DOWN;
constexpr Action_ActionDirection Action::LEFT;
constexpr Action_ActionDirection Action::ActionDirection_MIN;
constexpr Action_ActionDirection Action::ActionDirection_MAX;
constexpr int Action::ActionDirection_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))

// ===================================================================

class GameState::_Internal {
 public:
};

GameState::GameState(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:Game.GameState)
}
GameState::GameState(const GameState& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  GameState* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.isclosestobstaclebox_){}
    , decltype(_impl_.coinsneeded_){}
    , decltype(_impl_.closestobstacle_){}
    , decltype(_impl_.closestcoin_){}
    , decltype(_impl_.closestenemy_){}
    , decltype(_impl_.finishdirection_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&_impl_.isclosestobstaclebox_, &from._impl_.isclosestobstaclebox_,
    static_cast<size_t>(reinterpret_cast<char*>(&_impl_.finishdirection_) -
    reinterpret_cast<char*>(&_impl_.isclosestobstaclebox_)) + sizeof(_impl_.finishdirection_));
  // @@protoc_insertion_point(copy_constructor:Game.GameState)
}

inline void GameState::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.isclosestobstaclebox_){false}
    , decltype(_impl_.coinsneeded_){0}
    , decltype(_impl_.closestobstacle_){0}
    , decltype(_impl_.closestcoin_){0}
    , decltype(_impl_.closestenemy_){0}
    , decltype(_impl_.finishdirection_){0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

GameState::~GameState() {
  // @@protoc_insertion_point(destructor:Game.GameState)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void GameState::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void GameState::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void GameState::Clear() {
// @@protoc_insertion_point(message_clear_start:Game.GameState)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&_impl_.isclosestobstaclebox_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&_impl_.finishdirection_) -
      reinterpret_cast<char*>(&_impl_.isclosestobstaclebox_)) + sizeof(_impl_.finishdirection_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* GameState::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // bool isClosestObstacleBox = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _impl_.isclosestobstaclebox_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int32 coinsNeeded = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          _impl_.coinsneeded_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .Game.GameState.ObjectDirection closestObstacle = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 24)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_closestobstacle(static_cast<::Game::GameState_ObjectDirection>(val));
        } else
          goto handle_unusual;
        continue;
      // .Game.GameState.ObjectDirection closestCoin = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 32)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_closestcoin(static_cast<::Game::GameState_ObjectDirection>(val));
        } else
          goto handle_unusual;
        continue;
      // .Game.GameState.ObjectDirection closestEnemy = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 40)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_closestenemy(static_cast<::Game::GameState_ObjectDirection>(val));
        } else
          goto handle_unusual;
        continue;
      // .Game.GameState.ObjectDirection finishDirection = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 48)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_finishdirection(static_cast<::Game::GameState_ObjectDirection>(val));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* GameState::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Game.GameState)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // bool isClosestObstacleBox = 1;
  if (this->_internal_isclosestobstaclebox() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteBoolToArray(1, this->_internal_isclosestobstaclebox(), target);
  }

  // int32 coinsNeeded = 2;
  if (this->_internal_coinsneeded() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(2, this->_internal_coinsneeded(), target);
  }

  // .Game.GameState.ObjectDirection closestObstacle = 3;
  if (this->_internal_closestobstacle() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      3, this->_internal_closestobstacle(), target);
  }

  // .Game.GameState.ObjectDirection closestCoin = 4;
  if (this->_internal_closestcoin() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      4, this->_internal_closestcoin(), target);
  }

  // .Game.GameState.ObjectDirection closestEnemy = 5;
  if (this->_internal_closestenemy() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      5, this->_internal_closestenemy(), target);
  }

  // .Game.GameState.ObjectDirection finishDirection = 6;
  if (this->_internal_finishdirection() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      6, this->_internal_finishdirection(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Game.GameState)
  return target;
}

size_t GameState::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Game.GameState)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bool isClosestObstacleBox = 1;
  if (this->_internal_isclosestobstaclebox() != 0) {
    total_size += 1 + 1;
  }

  // int32 coinsNeeded = 2;
  if (this->_internal_coinsneeded() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_coinsneeded());
  }

  // .Game.GameState.ObjectDirection closestObstacle = 3;
  if (this->_internal_closestobstacle() != 0) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_closestobstacle());
  }

  // .Game.GameState.ObjectDirection closestCoin = 4;
  if (this->_internal_closestcoin() != 0) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_closestcoin());
  }

  // .Game.GameState.ObjectDirection closestEnemy = 5;
  if (this->_internal_closestenemy() != 0) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_closestenemy());
  }

  // .Game.GameState.ObjectDirection finishDirection = 6;
  if (this->_internal_finishdirection() != 0) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_finishdirection());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData GameState::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    GameState::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GameState::GetClassData() const { return &_class_data_; }


void GameState::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<GameState*>(&to_msg);
  auto& from = static_cast<const GameState&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:Game.GameState)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_isclosestobstaclebox() != 0) {
    _this->_internal_set_isclosestobstaclebox(from._internal_isclosestobstaclebox());
  }
  if (from._internal_coinsneeded() != 0) {
    _this->_internal_set_coinsneeded(from._internal_coinsneeded());
  }
  if (from._internal_closestobstacle() != 0) {
    _this->_internal_set_closestobstacle(from._internal_closestobstacle());
  }
  if (from._internal_closestcoin() != 0) {
    _this->_internal_set_closestcoin(from._internal_closestcoin());
  }
  if (from._internal_closestenemy() != 0) {
    _this->_internal_set_closestenemy(from._internal_closestenemy());
  }
  if (from._internal_finishdirection() != 0) {
    _this->_internal_set_finishdirection(from._internal_finishdirection());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void GameState::CopyFrom(const GameState& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Game.GameState)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GameState::IsInitialized() const {
  return true;
}

void GameState::InternalSwap(GameState* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(GameState, _impl_.finishdirection_)
      + sizeof(GameState::_impl_.finishdirection_)
      - PROTOBUF_FIELD_OFFSET(GameState, _impl_.isclosestobstaclebox_)>(
          reinterpret_cast<char*>(&_impl_.isclosestobstaclebox_),
          reinterpret_cast<char*>(&other->_impl_.isclosestobstaclebox_));
}

::PROTOBUF_NAMESPACE_ID::Metadata GameState::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_game_2eproto_getter, &descriptor_table_game_2eproto_once,
      file_level_metadata_game_2eproto[0]);
}

// ===================================================================

class Action::_Internal {
 public:
};

Action::Action(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:Game.Action)
}
Action::Action(const Action& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  Action* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.movedirection_){}
    , decltype(_impl_.shotdirection_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&_impl_.movedirection_, &from._impl_.movedirection_,
    static_cast<size_t>(reinterpret_cast<char*>(&_impl_.shotdirection_) -
    reinterpret_cast<char*>(&_impl_.movedirection_)) + sizeof(_impl_.shotdirection_));
  // @@protoc_insertion_point(copy_constructor:Game.Action)
}

inline void Action::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.movedirection_){0}
    , decltype(_impl_.shotdirection_){0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

Action::~Action() {
  // @@protoc_insertion_point(destructor:Game.Action)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Action::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void Action::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void Action::Clear() {
// @@protoc_insertion_point(message_clear_start:Game.Action)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&_impl_.movedirection_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&_impl_.shotdirection_) -
      reinterpret_cast<char*>(&_impl_.movedirection_)) + sizeof(_impl_.shotdirection_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Action::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // .Game.Action.ActionDirection moveDirection = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_movedirection(static_cast<::Game::Action_ActionDirection>(val));
        } else
          goto handle_unusual;
        continue;
      // .Game.Action.ActionDirection shotDirection = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_shotdirection(static_cast<::Game::Action_ActionDirection>(val));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Action::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Game.Action)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // .Game.Action.ActionDirection moveDirection = 1;
  if (this->_internal_movedirection() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      1, this->_internal_movedirection(), target);
  }

  // .Game.Action.ActionDirection shotDirection = 2;
  if (this->_internal_shotdirection() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      2, this->_internal_shotdirection(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Game.Action)
  return target;
}

size_t Action::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Game.Action)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .Game.Action.ActionDirection moveDirection = 1;
  if (this->_internal_movedirection() != 0) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_movedirection());
  }

  // .Game.Action.ActionDirection shotDirection = 2;
  if (this->_internal_shotdirection() != 0) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_shotdirection());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Action::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    Action::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Action::GetClassData() const { return &_class_data_; }


void Action::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<Action*>(&to_msg);
  auto& from = static_cast<const Action&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:Game.Action)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_movedirection() != 0) {
    _this->_internal_set_movedirection(from._internal_movedirection());
  }
  if (from._internal_shotdirection() != 0) {
    _this->_internal_set_shotdirection(from._internal_shotdirection());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Action::CopyFrom(const Action& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Game.Action)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Action::IsInitialized() const {
  return true;
}

void Action::InternalSwap(Action* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Action, _impl_.shotdirection_)
      + sizeof(Action::_impl_.shotdirection_)
      - PROTOBUF_FIELD_OFFSET(Action, _impl_.movedirection_)>(
          reinterpret_cast<char*>(&_impl_.movedirection_),
          reinterpret_cast<char*>(&other->_impl_.movedirection_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Action::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_game_2eproto_getter, &descriptor_table_game_2eproto_once,
      file_level_metadata_game_2eproto[1]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace Game
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Game::GameState*
Arena::CreateMaybeMessage< ::Game::GameState >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Game::GameState >(arena);
}
template<> PROTOBUF_NOINLINE ::Game::Action*
Arena::CreateMaybeMessage< ::Game::Action >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Game::Action >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>