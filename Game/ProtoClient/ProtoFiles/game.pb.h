// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: game.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_game_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_game_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021001 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_game_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_game_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_game_2eproto;
namespace Game {
class Action;
struct ActionDefaultTypeInternal;
extern ActionDefaultTypeInternal _Action_default_instance_;
class GameState;
struct GameStateDefaultTypeInternal;
extern GameStateDefaultTypeInternal _GameState_default_instance_;
}  // namespace Game
PROTOBUF_NAMESPACE_OPEN
template<> ::Game::Action* Arena::CreateMaybeMessage<::Game::Action>(Arena*);
template<> ::Game::GameState* Arena::CreateMaybeMessage<::Game::GameState>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace Game {

enum GameState_ObjectDirection : int {
  GameState_ObjectDirection_DEFAULT = 0,
  GameState_ObjectDirection_UP = 1,
  GameState_ObjectDirection_RIGHT = 2,
  GameState_ObjectDirection_DOWN = 3,
  GameState_ObjectDirection_LEFT = 4,
  GameState_ObjectDirection_GameState_ObjectDirection_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  GameState_ObjectDirection_GameState_ObjectDirection_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool GameState_ObjectDirection_IsValid(int value);
constexpr GameState_ObjectDirection GameState_ObjectDirection_ObjectDirection_MIN = GameState_ObjectDirection_DEFAULT;
constexpr GameState_ObjectDirection GameState_ObjectDirection_ObjectDirection_MAX = GameState_ObjectDirection_LEFT;
constexpr int GameState_ObjectDirection_ObjectDirection_ARRAYSIZE = GameState_ObjectDirection_ObjectDirection_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* GameState_ObjectDirection_descriptor();
template<typename T>
inline const std::string& GameState_ObjectDirection_Name(T enum_t_value) {
  static_assert(::std::is_same<T, GameState_ObjectDirection>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function GameState_ObjectDirection_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    GameState_ObjectDirection_descriptor(), enum_t_value);
}
inline bool GameState_ObjectDirection_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, GameState_ObjectDirection* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<GameState_ObjectDirection>(
    GameState_ObjectDirection_descriptor(), name, value);
}
enum Action_ActionDirection : int {
  Action_ActionDirection_DEFAULT = 0,
  Action_ActionDirection_UP = 1,
  Action_ActionDirection_RIGHT = 2,
  Action_ActionDirection_DOWN = 3,
  Action_ActionDirection_LEFT = 4,
  Action_ActionDirection_Action_ActionDirection_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  Action_ActionDirection_Action_ActionDirection_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool Action_ActionDirection_IsValid(int value);
constexpr Action_ActionDirection Action_ActionDirection_ActionDirection_MIN = Action_ActionDirection_DEFAULT;
constexpr Action_ActionDirection Action_ActionDirection_ActionDirection_MAX = Action_ActionDirection_LEFT;
constexpr int Action_ActionDirection_ActionDirection_ARRAYSIZE = Action_ActionDirection_ActionDirection_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Action_ActionDirection_descriptor();
template<typename T>
inline const std::string& Action_ActionDirection_Name(T enum_t_value) {
  static_assert(::std::is_same<T, Action_ActionDirection>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function Action_ActionDirection_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    Action_ActionDirection_descriptor(), enum_t_value);
}
inline bool Action_ActionDirection_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, Action_ActionDirection* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<Action_ActionDirection>(
    Action_ActionDirection_descriptor(), name, value);
}
// ===================================================================

class GameState final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Game.GameState) */ {
 public:
  inline GameState() : GameState(nullptr) {}
  ~GameState() override;
  explicit PROTOBUF_CONSTEXPR GameState(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  GameState(const GameState& from);
  GameState(GameState&& from) noexcept
    : GameState() {
    *this = ::std::move(from);
  }

  inline GameState& operator=(const GameState& from) {
    CopyFrom(from);
    return *this;
  }
  inline GameState& operator=(GameState&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const GameState& default_instance() {
    return *internal_default_instance();
  }
  static inline const GameState* internal_default_instance() {
    return reinterpret_cast<const GameState*>(
               &_GameState_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(GameState& a, GameState& b) {
    a.Swap(&b);
  }
  inline void Swap(GameState* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(GameState* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  GameState* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<GameState>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const GameState& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const GameState& from) {
    GameState::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(GameState* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Game.GameState";
  }
  protected:
  explicit GameState(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  typedef GameState_ObjectDirection ObjectDirection;
  static constexpr ObjectDirection DEFAULT =
    GameState_ObjectDirection_DEFAULT;
  static constexpr ObjectDirection UP =
    GameState_ObjectDirection_UP;
  static constexpr ObjectDirection RIGHT =
    GameState_ObjectDirection_RIGHT;
  static constexpr ObjectDirection DOWN =
    GameState_ObjectDirection_DOWN;
  static constexpr ObjectDirection LEFT =
    GameState_ObjectDirection_LEFT;
  static inline bool ObjectDirection_IsValid(int value) {
    return GameState_ObjectDirection_IsValid(value);
  }
  static constexpr ObjectDirection ObjectDirection_MIN =
    GameState_ObjectDirection_ObjectDirection_MIN;
  static constexpr ObjectDirection ObjectDirection_MAX =
    GameState_ObjectDirection_ObjectDirection_MAX;
  static constexpr int ObjectDirection_ARRAYSIZE =
    GameState_ObjectDirection_ObjectDirection_ARRAYSIZE;
  static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
  ObjectDirection_descriptor() {
    return GameState_ObjectDirection_descriptor();
  }
  template<typename T>
  static inline const std::string& ObjectDirection_Name(T enum_t_value) {
    static_assert(::std::is_same<T, ObjectDirection>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function ObjectDirection_Name.");
    return GameState_ObjectDirection_Name(enum_t_value);
  }
  static inline bool ObjectDirection_Parse(::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
      ObjectDirection* value) {
    return GameState_ObjectDirection_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  enum : int {
    kIsClosestObstacleBoxFieldNumber = 1,
    kCoinsNeededFieldNumber = 2,
    kClosestObstacleFieldNumber = 3,
    kClosestCoinFieldNumber = 4,
    kClosestEnemyFieldNumber = 5,
    kFinishDirectionFieldNumber = 6,
  };
  // bool isClosestObstacleBox = 1;
  void clear_isclosestobstaclebox();
  bool isclosestobstaclebox() const;
  void set_isclosestobstaclebox(bool value);
  private:
  bool _internal_isclosestobstaclebox() const;
  void _internal_set_isclosestobstaclebox(bool value);
  public:

  // int32 coinsNeeded = 2;
  void clear_coinsneeded();
  int32_t coinsneeded() const;
  void set_coinsneeded(int32_t value);
  private:
  int32_t _internal_coinsneeded() const;
  void _internal_set_coinsneeded(int32_t value);
  public:

  // .Game.GameState.ObjectDirection closestObstacle = 3;
  void clear_closestobstacle();
  ::Game::GameState_ObjectDirection closestobstacle() const;
  void set_closestobstacle(::Game::GameState_ObjectDirection value);
  private:
  ::Game::GameState_ObjectDirection _internal_closestobstacle() const;
  void _internal_set_closestobstacle(::Game::GameState_ObjectDirection value);
  public:

  // .Game.GameState.ObjectDirection closestCoin = 4;
  void clear_closestcoin();
  ::Game::GameState_ObjectDirection closestcoin() const;
  void set_closestcoin(::Game::GameState_ObjectDirection value);
  private:
  ::Game::GameState_ObjectDirection _internal_closestcoin() const;
  void _internal_set_closestcoin(::Game::GameState_ObjectDirection value);
  public:

  // .Game.GameState.ObjectDirection closestEnemy = 5;
  void clear_closestenemy();
  ::Game::GameState_ObjectDirection closestenemy() const;
  void set_closestenemy(::Game::GameState_ObjectDirection value);
  private:
  ::Game::GameState_ObjectDirection _internal_closestenemy() const;
  void _internal_set_closestenemy(::Game::GameState_ObjectDirection value);
  public:

  // .Game.GameState.ObjectDirection finishDirection = 6;
  void clear_finishdirection();
  ::Game::GameState_ObjectDirection finishdirection() const;
  void set_finishdirection(::Game::GameState_ObjectDirection value);
  private:
  ::Game::GameState_ObjectDirection _internal_finishdirection() const;
  void _internal_set_finishdirection(::Game::GameState_ObjectDirection value);
  public:

  // @@protoc_insertion_point(class_scope:Game.GameState)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    bool isclosestobstaclebox_;
    int32_t coinsneeded_;
    int closestobstacle_;
    int closestcoin_;
    int closestenemy_;
    int finishdirection_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_game_2eproto;
};
// -------------------------------------------------------------------

class Action final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Game.Action) */ {
 public:
  inline Action() : Action(nullptr) {}
  ~Action() override;
  explicit PROTOBUF_CONSTEXPR Action(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Action(const Action& from);
  Action(Action&& from) noexcept
    : Action() {
    *this = ::std::move(from);
  }

  inline Action& operator=(const Action& from) {
    CopyFrom(from);
    return *this;
  }
  inline Action& operator=(Action&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Action& default_instance() {
    return *internal_default_instance();
  }
  static inline const Action* internal_default_instance() {
    return reinterpret_cast<const Action*>(
               &_Action_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Action& a, Action& b) {
    a.Swap(&b);
  }
  inline void Swap(Action* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Action* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Action* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Action>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Action& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const Action& from) {
    Action::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Action* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Game.Action";
  }
  protected:
  explicit Action(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  typedef Action_ActionDirection ActionDirection;
  static constexpr ActionDirection DEFAULT =
    Action_ActionDirection_DEFAULT;
  static constexpr ActionDirection UP =
    Action_ActionDirection_UP;
  static constexpr ActionDirection RIGHT =
    Action_ActionDirection_RIGHT;
  static constexpr ActionDirection DOWN =
    Action_ActionDirection_DOWN;
  static constexpr ActionDirection LEFT =
    Action_ActionDirection_LEFT;
  static inline bool ActionDirection_IsValid(int value) {
    return Action_ActionDirection_IsValid(value);
  }
  static constexpr ActionDirection ActionDirection_MIN =
    Action_ActionDirection_ActionDirection_MIN;
  static constexpr ActionDirection ActionDirection_MAX =
    Action_ActionDirection_ActionDirection_MAX;
  static constexpr int ActionDirection_ARRAYSIZE =
    Action_ActionDirection_ActionDirection_ARRAYSIZE;
  static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
  ActionDirection_descriptor() {
    return Action_ActionDirection_descriptor();
  }
  template<typename T>
  static inline const std::string& ActionDirection_Name(T enum_t_value) {
    static_assert(::std::is_same<T, ActionDirection>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function ActionDirection_Name.");
    return Action_ActionDirection_Name(enum_t_value);
  }
  static inline bool ActionDirection_Parse(::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
      ActionDirection* value) {
    return Action_ActionDirection_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  enum : int {
    kMoveDirectionFieldNumber = 1,
    kShotDirectionFieldNumber = 2,
  };
  // .Game.Action.ActionDirection moveDirection = 1;
  void clear_movedirection();
  ::Game::Action_ActionDirection movedirection() const;
  void set_movedirection(::Game::Action_ActionDirection value);
  private:
  ::Game::Action_ActionDirection _internal_movedirection() const;
  void _internal_set_movedirection(::Game::Action_ActionDirection value);
  public:

  // .Game.Action.ActionDirection shotDirection = 2;
  void clear_shotdirection();
  ::Game::Action_ActionDirection shotdirection() const;
  void set_shotdirection(::Game::Action_ActionDirection value);
  private:
  ::Game::Action_ActionDirection _internal_shotdirection() const;
  void _internal_set_shotdirection(::Game::Action_ActionDirection value);
  public:

  // @@protoc_insertion_point(class_scope:Game.Action)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    int movedirection_;
    int shotdirection_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_game_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// GameState

// bool isClosestObstacleBox = 1;
inline void GameState::clear_isclosestobstaclebox() {
  _impl_.isclosestobstaclebox_ = false;
}
inline bool GameState::_internal_isclosestobstaclebox() const {
  return _impl_.isclosestobstaclebox_;
}
inline bool GameState::isclosestobstaclebox() const {
  // @@protoc_insertion_point(field_get:Game.GameState.isClosestObstacleBox)
  return _internal_isclosestobstaclebox();
}
inline void GameState::_internal_set_isclosestobstaclebox(bool value) {
  
  _impl_.isclosestobstaclebox_ = value;
}
inline void GameState::set_isclosestobstaclebox(bool value) {
  _internal_set_isclosestobstaclebox(value);
  // @@protoc_insertion_point(field_set:Game.GameState.isClosestObstacleBox)
}

// int32 coinsNeeded = 2;
inline void GameState::clear_coinsneeded() {
  _impl_.coinsneeded_ = 0;
}
inline int32_t GameState::_internal_coinsneeded() const {
  return _impl_.coinsneeded_;
}
inline int32_t GameState::coinsneeded() const {
  // @@protoc_insertion_point(field_get:Game.GameState.coinsNeeded)
  return _internal_coinsneeded();
}
inline void GameState::_internal_set_coinsneeded(int32_t value) {
  
  _impl_.coinsneeded_ = value;
}
inline void GameState::set_coinsneeded(int32_t value) {
  _internal_set_coinsneeded(value);
  // @@protoc_insertion_point(field_set:Game.GameState.coinsNeeded)
}

// .Game.GameState.ObjectDirection closestObstacle = 3;
inline void GameState::clear_closestobstacle() {
  _impl_.closestobstacle_ = 0;
}
inline ::Game::GameState_ObjectDirection GameState::_internal_closestobstacle() const {
  return static_cast< ::Game::GameState_ObjectDirection >(_impl_.closestobstacle_);
}
inline ::Game::GameState_ObjectDirection GameState::closestobstacle() const {
  // @@protoc_insertion_point(field_get:Game.GameState.closestObstacle)
  return _internal_closestobstacle();
}
inline void GameState::_internal_set_closestobstacle(::Game::GameState_ObjectDirection value) {
  
  _impl_.closestobstacle_ = value;
}
inline void GameState::set_closestobstacle(::Game::GameState_ObjectDirection value) {
  _internal_set_closestobstacle(value);
  // @@protoc_insertion_point(field_set:Game.GameState.closestObstacle)
}

// .Game.GameState.ObjectDirection closestCoin = 4;
inline void GameState::clear_closestcoin() {
  _impl_.closestcoin_ = 0;
}
inline ::Game::GameState_ObjectDirection GameState::_internal_closestcoin() const {
  return static_cast< ::Game::GameState_ObjectDirection >(_impl_.closestcoin_);
}
inline ::Game::GameState_ObjectDirection GameState::closestcoin() const {
  // @@protoc_insertion_point(field_get:Game.GameState.closestCoin)
  return _internal_closestcoin();
}
inline void GameState::_internal_set_closestcoin(::Game::GameState_ObjectDirection value) {
  
  _impl_.closestcoin_ = value;
}
inline void GameState::set_closestcoin(::Game::GameState_ObjectDirection value) {
  _internal_set_closestcoin(value);
  // @@protoc_insertion_point(field_set:Game.GameState.closestCoin)
}

// .Game.GameState.ObjectDirection closestEnemy = 5;
inline void GameState::clear_closestenemy() {
  _impl_.closestenemy_ = 0;
}
inline ::Game::GameState_ObjectDirection GameState::_internal_closestenemy() const {
  return static_cast< ::Game::GameState_ObjectDirection >(_impl_.closestenemy_);
}
inline ::Game::GameState_ObjectDirection GameState::closestenemy() const {
  // @@protoc_insertion_point(field_get:Game.GameState.closestEnemy)
  return _internal_closestenemy();
}
inline void GameState::_internal_set_closestenemy(::Game::GameState_ObjectDirection value) {
  
  _impl_.closestenemy_ = value;
}
inline void GameState::set_closestenemy(::Game::GameState_ObjectDirection value) {
  _internal_set_closestenemy(value);
  // @@protoc_insertion_point(field_set:Game.GameState.closestEnemy)
}

// .Game.GameState.ObjectDirection finishDirection = 6;
inline void GameState::clear_finishdirection() {
  _impl_.finishdirection_ = 0;
}
inline ::Game::GameState_ObjectDirection GameState::_internal_finishdirection() const {
  return static_cast< ::Game::GameState_ObjectDirection >(_impl_.finishdirection_);
}
inline ::Game::GameState_ObjectDirection GameState::finishdirection() const {
  // @@protoc_insertion_point(field_get:Game.GameState.finishDirection)
  return _internal_finishdirection();
}
inline void GameState::_internal_set_finishdirection(::Game::GameState_ObjectDirection value) {
  
  _impl_.finishdirection_ = value;
}
inline void GameState::set_finishdirection(::Game::GameState_ObjectDirection value) {
  _internal_set_finishdirection(value);
  // @@protoc_insertion_point(field_set:Game.GameState.finishDirection)
}

// -------------------------------------------------------------------

// Action

// .Game.Action.ActionDirection moveDirection = 1;
inline void Action::clear_movedirection() {
  _impl_.movedirection_ = 0;
}
inline ::Game::Action_ActionDirection Action::_internal_movedirection() const {
  return static_cast< ::Game::Action_ActionDirection >(_impl_.movedirection_);
}
inline ::Game::Action_ActionDirection Action::movedirection() const {
  // @@protoc_insertion_point(field_get:Game.Action.moveDirection)
  return _internal_movedirection();
}
inline void Action::_internal_set_movedirection(::Game::Action_ActionDirection value) {
  
  _impl_.movedirection_ = value;
}
inline void Action::set_movedirection(::Game::Action_ActionDirection value) {
  _internal_set_movedirection(value);
  // @@protoc_insertion_point(field_set:Game.Action.moveDirection)
}

// .Game.Action.ActionDirection shotDirection = 2;
inline void Action::clear_shotdirection() {
  _impl_.shotdirection_ = 0;
}
inline ::Game::Action_ActionDirection Action::_internal_shotdirection() const {
  return static_cast< ::Game::Action_ActionDirection >(_impl_.shotdirection_);
}
inline ::Game::Action_ActionDirection Action::shotdirection() const {
  // @@protoc_insertion_point(field_get:Game.Action.shotDirection)
  return _internal_shotdirection();
}
inline void Action::_internal_set_shotdirection(::Game::Action_ActionDirection value) {
  
  _impl_.shotdirection_ = value;
}
inline void Action::set_shotdirection(::Game::Action_ActionDirection value) {
  _internal_set_shotdirection(value);
  // @@protoc_insertion_point(field_set:Game.Action.shotDirection)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace Game

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::Game::GameState_ObjectDirection> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::Game::GameState_ObjectDirection>() {
  return ::Game::GameState_ObjectDirection_descriptor();
}
template <> struct is_proto_enum< ::Game::Action_ActionDirection> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::Game::Action_ActionDirection>() {
  return ::Game::Action_ActionDirection_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_game_2eproto