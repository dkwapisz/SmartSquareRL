// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: test.proto

#include "test.pb.h"

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

namespace Test {
PROTOBUF_CONSTEXPR LevelInfoRequest::LevelInfoRequest(
    ::_pbi::ConstantInitialized)
  : playercoins_(0)
  , levelcoins_(0){}
struct LevelInfoRequestDefaultTypeInternal {
  PROTOBUF_CONSTEXPR LevelInfoRequestDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~LevelInfoRequestDefaultTypeInternal() {}
  union {
    LevelInfoRequest _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 LevelInfoRequestDefaultTypeInternal _LevelInfoRequest_default_instance_;
PROTOBUF_CONSTEXPR LevelInfoReplay::LevelInfoReplay(
    ::_pbi::ConstantInitialized)
  : playercoins_(0)
  , levelcoins_(0){}
struct LevelInfoReplayDefaultTypeInternal {
  PROTOBUF_CONSTEXPR LevelInfoReplayDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~LevelInfoReplayDefaultTypeInternal() {}
  union {
    LevelInfoReplay _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 LevelInfoReplayDefaultTypeInternal _LevelInfoReplay_default_instance_;
}  // namespace Test
static ::_pb::Metadata file_level_metadata_test_2eproto[2];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_test_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_test_2eproto = nullptr;

const uint32_t TableStruct_test_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Test::LevelInfoRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Test::LevelInfoRequest, playercoins_),
  PROTOBUF_FIELD_OFFSET(::Test::LevelInfoRequest, levelcoins_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Test::LevelInfoReplay, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Test::LevelInfoReplay, playercoins_),
  PROTOBUF_FIELD_OFFSET(::Test::LevelInfoReplay, levelcoins_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::Test::LevelInfoRequest)},
  { 8, -1, -1, sizeof(::Test::LevelInfoReplay)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::Test::_LevelInfoRequest_default_instance_._instance,
  &::Test::_LevelInfoReplay_default_instance_._instance,
};

const char descriptor_table_protodef_test_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\ntest.proto\022\004Test\";\n\020LevelInfoRequest\022\023"
  "\n\013playerCoins\030\001 \001(\005\022\022\n\nlevelCoins\030\002 \001(\005\""
  ":\n\017LevelInfoReplay\022\023\n\013playerCoins\030\001 \001(\005\022"
  "\022\n\nlevelCoins\030\002 \001(\0052J\n\007GetInfo\022\?\n\014GetLev"
  "elInfo\022\026.Test.LevelInfoRequest\032\025.Test.Le"
  "velInfoReplay\"\000b\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_test_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_test_2eproto = {
    false, false, 223, descriptor_table_protodef_test_2eproto,
    "test.proto",
    &descriptor_table_test_2eproto_once, nullptr, 0, 2,
    schemas, file_default_instances, TableStruct_test_2eproto::offsets,
    file_level_metadata_test_2eproto, file_level_enum_descriptors_test_2eproto,
    file_level_service_descriptors_test_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_test_2eproto_getter() {
  return &descriptor_table_test_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_test_2eproto(&descriptor_table_test_2eproto);
namespace Test {

// ===================================================================

class LevelInfoRequest::_Internal {
 public:
};

LevelInfoRequest::LevelInfoRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:Test.LevelInfoRequest)
}
LevelInfoRequest::LevelInfoRequest(const LevelInfoRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&playercoins_, &from.playercoins_,
    static_cast<size_t>(reinterpret_cast<char*>(&levelcoins_) -
    reinterpret_cast<char*>(&playercoins_)) + sizeof(levelcoins_));
  // @@protoc_insertion_point(copy_constructor:Test.LevelInfoRequest)
}

inline void LevelInfoRequest::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&playercoins_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&levelcoins_) -
    reinterpret_cast<char*>(&playercoins_)) + sizeof(levelcoins_));
}

LevelInfoRequest::~LevelInfoRequest() {
  // @@protoc_insertion_point(destructor:Test.LevelInfoRequest)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void LevelInfoRequest::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void LevelInfoRequest::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void LevelInfoRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:Test.LevelInfoRequest)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&playercoins_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&levelcoins_) -
      reinterpret_cast<char*>(&playercoins_)) + sizeof(levelcoins_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* LevelInfoRequest::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int32 playerCoins = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          playercoins_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int32 levelCoins = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          levelcoins_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
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

uint8_t* LevelInfoRequest::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Test.LevelInfoRequest)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 playerCoins = 1;
  if (this->_internal_playercoins() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(1, this->_internal_playercoins(), target);
  }

  // int32 levelCoins = 2;
  if (this->_internal_levelcoins() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(2, this->_internal_levelcoins(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Test.LevelInfoRequest)
  return target;
}

size_t LevelInfoRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Test.LevelInfoRequest)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // int32 playerCoins = 1;
  if (this->_internal_playercoins() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_playercoins());
  }

  // int32 levelCoins = 2;
  if (this->_internal_levelcoins() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_levelcoins());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData LevelInfoRequest::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    LevelInfoRequest::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*LevelInfoRequest::GetClassData() const { return &_class_data_; }

void LevelInfoRequest::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<LevelInfoRequest *>(to)->MergeFrom(
      static_cast<const LevelInfoRequest &>(from));
}


void LevelInfoRequest::MergeFrom(const LevelInfoRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Test.LevelInfoRequest)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_playercoins() != 0) {
    _internal_set_playercoins(from._internal_playercoins());
  }
  if (from._internal_levelcoins() != 0) {
    _internal_set_levelcoins(from._internal_levelcoins());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void LevelInfoRequest::CopyFrom(const LevelInfoRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Test.LevelInfoRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool LevelInfoRequest::IsInitialized() const {
  return true;
}

void LevelInfoRequest::InternalSwap(LevelInfoRequest* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(LevelInfoRequest, levelcoins_)
      + sizeof(LevelInfoRequest::levelcoins_)
      - PROTOBUF_FIELD_OFFSET(LevelInfoRequest, playercoins_)>(
          reinterpret_cast<char*>(&playercoins_),
          reinterpret_cast<char*>(&other->playercoins_));
}

::PROTOBUF_NAMESPACE_ID::Metadata LevelInfoRequest::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_test_2eproto_getter, &descriptor_table_test_2eproto_once,
      file_level_metadata_test_2eproto[0]);
}

// ===================================================================

class LevelInfoReplay::_Internal {
 public:
};

LevelInfoReplay::LevelInfoReplay(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:Test.LevelInfoReplay)
}
LevelInfoReplay::LevelInfoReplay(const LevelInfoReplay& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&playercoins_, &from.playercoins_,
    static_cast<size_t>(reinterpret_cast<char*>(&levelcoins_) -
    reinterpret_cast<char*>(&playercoins_)) + sizeof(levelcoins_));
  // @@protoc_insertion_point(copy_constructor:Test.LevelInfoReplay)
}

inline void LevelInfoReplay::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&playercoins_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&levelcoins_) -
    reinterpret_cast<char*>(&playercoins_)) + sizeof(levelcoins_));
}

LevelInfoReplay::~LevelInfoReplay() {
  // @@protoc_insertion_point(destructor:Test.LevelInfoReplay)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void LevelInfoReplay::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void LevelInfoReplay::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void LevelInfoReplay::Clear() {
// @@protoc_insertion_point(message_clear_start:Test.LevelInfoReplay)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&playercoins_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&levelcoins_) -
      reinterpret_cast<char*>(&playercoins_)) + sizeof(levelcoins_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* LevelInfoReplay::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int32 playerCoins = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          playercoins_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int32 levelCoins = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          levelcoins_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
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

uint8_t* LevelInfoReplay::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Test.LevelInfoReplay)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 playerCoins = 1;
  if (this->_internal_playercoins() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(1, this->_internal_playercoins(), target);
  }

  // int32 levelCoins = 2;
  if (this->_internal_levelcoins() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(2, this->_internal_levelcoins(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Test.LevelInfoReplay)
  return target;
}

size_t LevelInfoReplay::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Test.LevelInfoReplay)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // int32 playerCoins = 1;
  if (this->_internal_playercoins() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_playercoins());
  }

  // int32 levelCoins = 2;
  if (this->_internal_levelcoins() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_levelcoins());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData LevelInfoReplay::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    LevelInfoReplay::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*LevelInfoReplay::GetClassData() const { return &_class_data_; }

void LevelInfoReplay::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<LevelInfoReplay *>(to)->MergeFrom(
      static_cast<const LevelInfoReplay &>(from));
}


void LevelInfoReplay::MergeFrom(const LevelInfoReplay& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Test.LevelInfoReplay)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_playercoins() != 0) {
    _internal_set_playercoins(from._internal_playercoins());
  }
  if (from._internal_levelcoins() != 0) {
    _internal_set_levelcoins(from._internal_levelcoins());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void LevelInfoReplay::CopyFrom(const LevelInfoReplay& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Test.LevelInfoReplay)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool LevelInfoReplay::IsInitialized() const {
  return true;
}

void LevelInfoReplay::InternalSwap(LevelInfoReplay* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(LevelInfoReplay, levelcoins_)
      + sizeof(LevelInfoReplay::levelcoins_)
      - PROTOBUF_FIELD_OFFSET(LevelInfoReplay, playercoins_)>(
          reinterpret_cast<char*>(&playercoins_),
          reinterpret_cast<char*>(&other->playercoins_));
}

::PROTOBUF_NAMESPACE_ID::Metadata LevelInfoReplay::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_test_2eproto_getter, &descriptor_table_test_2eproto_once,
      file_level_metadata_test_2eproto[1]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace Test
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Test::LevelInfoRequest*
Arena::CreateMaybeMessage< ::Test::LevelInfoRequest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Test::LevelInfoRequest >(arena);
}
template<> PROTOBUF_NOINLINE ::Test::LevelInfoReplay*
Arena::CreateMaybeMessage< ::Test::LevelInfoReplay >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Test::LevelInfoReplay >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
