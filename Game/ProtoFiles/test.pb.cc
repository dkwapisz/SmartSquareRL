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
constexpr LevelInfo::LevelInfo(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : playercoins_(0)
  , levelcoins_(0){}
struct LevelInfoDefaultTypeInternal {
  constexpr LevelInfoDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~LevelInfoDefaultTypeInternal() {}
  union {
    LevelInfo _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT LevelInfoDefaultTypeInternal _LevelInfo_default_instance_;
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_test_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_test_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_test_2eproto = nullptr;

const uint32_t TableStruct_test_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::LevelInfo, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::LevelInfo, playercoins_),
  PROTOBUF_FIELD_OFFSET(::LevelInfo, levelcoins_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::LevelInfo)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_LevelInfo_default_instance_),
};

const char descriptor_table_protodef_test_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\ntest.proto\"4\n\tLevelInfo\022\023\n\013playerCoins"
  "\030\001 \001(\005\022\022\n\nlevelCoins\030\002 \001(\005b\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_test_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_test_2eproto = {
  false, false, 74, descriptor_table_protodef_test_2eproto, "test.proto", 
  &descriptor_table_test_2eproto_once, nullptr, 0, 1,
  schemas, file_default_instances, TableStruct_test_2eproto::offsets,
  file_level_metadata_test_2eproto, file_level_enum_descriptors_test_2eproto, file_level_service_descriptors_test_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_test_2eproto_getter() {
  return &descriptor_table_test_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_test_2eproto(&descriptor_table_test_2eproto);

// ===================================================================

class LevelInfo::_Internal {
 public:
};

LevelInfo::LevelInfo(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:LevelInfo)
}
LevelInfo::LevelInfo(const LevelInfo& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&playercoins_, &from.playercoins_,
    static_cast<size_t>(reinterpret_cast<char*>(&levelcoins_) -
    reinterpret_cast<char*>(&playercoins_)) + sizeof(levelcoins_));
  // @@protoc_insertion_point(copy_constructor:LevelInfo)
}

inline void LevelInfo::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&playercoins_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&levelcoins_) -
    reinterpret_cast<char*>(&playercoins_)) + sizeof(levelcoins_));
}

LevelInfo::~LevelInfo() {
  // @@protoc_insertion_point(destructor:LevelInfo)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void LevelInfo::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void LevelInfo::ArenaDtor(void* object) {
  LevelInfo* _this = reinterpret_cast< LevelInfo* >(object);
  (void)_this;
}
void LevelInfo::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void LevelInfo::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void LevelInfo::Clear() {
// @@protoc_insertion_point(message_clear_start:LevelInfo)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&playercoins_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&levelcoins_) -
      reinterpret_cast<char*>(&playercoins_)) + sizeof(levelcoins_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* LevelInfo::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
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

uint8_t* LevelInfo::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:LevelInfo)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 playerCoins = 1;
  if (this->_internal_playercoins() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_playercoins(), target);
  }

  // int32 levelCoins = 2;
  if (this->_internal_levelcoins() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(2, this->_internal_levelcoins(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:LevelInfo)
  return target;
}

size_t LevelInfo::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:LevelInfo)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // int32 playerCoins = 1;
  if (this->_internal_playercoins() != 0) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32SizePlusOne(this->_internal_playercoins());
  }

  // int32 levelCoins = 2;
  if (this->_internal_levelcoins() != 0) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32SizePlusOne(this->_internal_levelcoins());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData LevelInfo::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    LevelInfo::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*LevelInfo::GetClassData() const { return &_class_data_; }

void LevelInfo::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<LevelInfo *>(to)->MergeFrom(
      static_cast<const LevelInfo &>(from));
}


void LevelInfo::MergeFrom(const LevelInfo& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:LevelInfo)
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

void LevelInfo::CopyFrom(const LevelInfo& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:LevelInfo)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool LevelInfo::IsInitialized() const {
  return true;
}

void LevelInfo::InternalSwap(LevelInfo* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(LevelInfo, levelcoins_)
      + sizeof(LevelInfo::levelcoins_)
      - PROTOBUF_FIELD_OFFSET(LevelInfo, playercoins_)>(
          reinterpret_cast<char*>(&playercoins_),
          reinterpret_cast<char*>(&other->playercoins_));
}

::PROTOBUF_NAMESPACE_ID::Metadata LevelInfo::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_test_2eproto_getter, &descriptor_table_test_2eproto_once,
      file_level_metadata_test_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::LevelInfo* Arena::CreateMaybeMessage< ::LevelInfo >(Arena* arena) {
  return Arena::CreateMessageInternal< ::LevelInfo >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>