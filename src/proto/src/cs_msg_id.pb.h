// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: cs_msg_id.proto

#ifndef PROTOBUF_INCLUDED_cs_5fmsg_5fid_2eproto
#define PROTOBUF_INCLUDED_cs_5fmsg_5fid_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_cs_5fmsg_5fid_2eproto 

namespace protobuf_cs_5fmsg_5fid_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_cs_5fmsg_5fid_2eproto
namespace com {
namespace moon {
namespace demo {
namespace proto {
namespace cs {
}  // namespace cs
}  // namespace proto
}  // namespace demo
}  // namespace moon
}  // namespace com
namespace com {
namespace moon {
namespace demo {
namespace proto {
namespace cs {

enum MsgID {
  PLACE_HOLDER = 0,
  MSG_ID_DEMO_1_REQ = 1000,
  MSG_ID_DEMO_1_RSP = 1001,
  MSG_ID_DEMO_2_REQ = 1002,
  MSG_ID_DEMO_2_RSP = 1003,
  MSG_ID_DEMO_3_REQ = 1004,
  MSG_ID_DEMO_3_RSP = 1005,
  MSG_ID_DEMO_4_REQ = 1006,
  MSG_ID_DEMO_4_RSP = 1007,
  MSG_ID_DEMO_5_REQ = 1008,
  MSG_ID_DEMO_5_RSP = 1009,
  MSG_ID_DEMO_6_REQ = 1010,
  MSG_ID_DEMO_6_RSP = 1011,
  MsgID_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  MsgID_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool MsgID_IsValid(int value);
const MsgID MsgID_MIN = PLACE_HOLDER;
const MsgID MsgID_MAX = MSG_ID_DEMO_6_RSP;
const int MsgID_ARRAYSIZE = MsgID_MAX + 1;

const ::google::protobuf::EnumDescriptor* MsgID_descriptor();
inline const ::std::string& MsgID_Name(MsgID value) {
  return ::google::protobuf::internal::NameOfEnum(
    MsgID_descriptor(), value);
}
inline bool MsgID_Parse(
    const ::std::string& name, MsgID* value) {
  return ::google::protobuf::internal::ParseNamedEnum<MsgID>(
    MsgID_descriptor(), name, value);
}
// ===================================================================


// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace cs
}  // namespace proto
}  // namespace demo
}  // namespace moon
}  // namespace com

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::com::moon::demo::proto::cs::MsgID> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::com::moon::demo::proto::cs::MsgID>() {
  return ::com::moon::demo::proto::cs::MsgID_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_cs_5fmsg_5fid_2eproto