// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ss_msg_id.proto

#ifndef PROTOBUF_INCLUDED_ss_5fmsg_5fid_2eproto
#define PROTOBUF_INCLUDED_ss_5fmsg_5fid_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_protobuf_ss_5fmsg_5fid_2eproto 

namespace protobuf_ss_5fmsg_5fid_2eproto {
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
}  // namespace protobuf_ss_5fmsg_5fid_2eproto
namespace com {
namespace moon {
namespace demo {
namespace ss {
}  // namespace ss
}  // namespace demo
}  // namespace moon
}  // namespace com
namespace com {
namespace moon {
namespace demo {
namespace ss {

enum MsgID {
  PLACE_HOLDER = 0,
  MSG_ID_DEMO2_REQ = 2000,
  MSG_ID_DEMO2_RSP = 2001,
  MSG_ID_DEMO3_REQ = 2002,
  MSG_ID_DEMO3_RSP = 2003,
  MSG_ID_DEMO4_REQ = 2004,
  MSG_ID_DEMO4_RSP = 2005,
  MSG_ID_DEMO5_REQ = 2006,
  MSG_ID_DEMO5_RSP = 2007,
  MSG_ID_DEMO6_REQ = 2008,
  MSG_ID_DEMO6_RSP = 2009,
  MSG_ID_DEMO7_REQ = 2010,
  MSG_ID_DEMO7_RSP = 2011,
  MSG_ID_DEMO8_REQ = 2012,
  MSG_ID_DEMO8_RSP = 2013,
  MSG_ID_DEMO9_REQ = 2014,
  MSG_ID_DEMO9_RSP = 2015,
  MSG_ID_DEMO10_REQ = 2016,
  MSG_ID_DEMO10_RSP = 2017,
  MSG_ID_DEMO20_REQ = 2018,
  MSG_ID_DEMO20_RSP = 2019,
  MSG_ID_DEMO50_REQ = 2020,
  MSG_ID_DEMO50_RSP = 2021,
  MSG_ID_DEMO90_REQ = 2022,
  MSG_ID_DEMO90_RSP = 2023,
  MSG_ID_DEMO2_NFY = 2024,
  MSG_ID_DEMO5_NFY = 2025,
  MSG_ID_DEMO9_NFY = 2026,
  MSG_ID_DEMO1002_REQ = 2027,
  MSG_ID_DEMO1002_RSP = 2028,
  MSG_ID_DEMO1003_REQ = 2029,
  MSG_ID_DEMO1003_RSP = 2030,
  MSG_ID_DEMO1004_REQ = 2031,
  MSG_ID_DEMO1004_RSP = 2032,
  MSG_ID_DEMO1005_REQ = 2033,
  MSG_ID_DEMO1005_RSP = 2034,
  MSG_ID_DEMO1006_REQ = 2035,
  MSG_ID_DEMO1006_RSP = 2036,
  MSG_ID_DEMO1007_REQ = 2037,
  MSG_ID_DEMO1007_RSP = 2038,
  MSG_ID_DEMO1008_REQ = 2039,
  MSG_ID_DEMO1008_RSP = 2040,
  MSG_ID_DEMO1009_REQ = 2041,
  MSG_ID_DEMO1009_RSP = 2042,
  MSG_ID_DEMO1010_REQ = 2043,
  MSG_ID_DEMO1010_RSP = 2044,
  MSG_ID_DEMO1020_REQ = 2045,
  MSG_ID_DEMO1020_RSP = 2046,
  MSG_ID_DEMO1050_REQ = 2047,
  MSG_ID_DEMO1050_RSP = 2048,
  MSG_ID_DEMO1090_REQ = 2049,
  MSG_ID_DEMO1090_RSP = 2050,
  MSG_ID_DEMO1002_NFY = 2051,
  MSG_ID_DEMO1005_NFY = 2052,
  MSG_ID_DEMO1009_NFY = 2053,
  MSG_ID_DEMO2002_REQ = 2054,
  MSG_ID_DEMO2002_RSP = 2055,
  MSG_ID_DEMO2003_REQ = 2056,
  MSG_ID_DEMO2003_RSP = 2057,
  MSG_ID_DEMO2004_REQ = 2058,
  MSG_ID_DEMO2004_RSP = 2059,
  MSG_ID_DEMO2005_REQ = 2060,
  MSG_ID_DEMO2005_RSP = 2061,
  MSG_ID_DEMO2006_REQ = 2062,
  MSG_ID_DEMO2006_RSP = 2063,
  MSG_ID_DEMO2007_REQ = 2064,
  MSG_ID_DEMO2007_RSP = 2065,
  MSG_ID_DEMO2008_REQ = 2066,
  MSG_ID_DEMO2008_RSP = 2067,
  MSG_ID_DEMO2009_REQ = 2068,
  MSG_ID_DEMO2009_RSP = 2069,
  MSG_ID_DEMO2010_REQ = 2070,
  MSG_ID_DEMO2010_RSP = 2071,
  MSG_ID_DEMO2020_REQ = 2072,
  MSG_ID_DEMO2020_RSP = 2073,
  MSG_ID_DEMO2050_REQ = 2074,
  MSG_ID_DEMO2050_RSP = 2075,
  MSG_ID_DEMO2090_REQ = 2076,
  MSG_ID_DEMO2090_RSP = 2077,
  MSG_ID_DEMO2002_NFY = 2078,
  MSG_ID_DEMO2005_NFY = 2079,
  MSG_ID_DEMO2009_NFY = 2080,
  MSG_ID_DEMO3002_REQ = 2081,
  MSG_ID_DEMO3002_RSP = 2082,
  MSG_ID_DEMO3003_REQ = 2083,
  MSG_ID_DEMO3003_RSP = 2084,
  MSG_ID_DEMO3004_REQ = 2085,
  MSG_ID_DEMO3004_RSP = 2086,
  MSG_ID_DEMO3005_REQ = 2087,
  MSG_ID_DEMO3005_RSP = 2088,
  MSG_ID_DEMO3006_REQ = 2089,
  MSG_ID_DEMO3006_RSP = 2090,
  MSG_ID_DEMO3007_REQ = 2091,
  MSG_ID_DEMO3007_RSP = 2092,
  MSG_ID_DEMO3008_REQ = 2093,
  MSG_ID_DEMO3008_RSP = 2094,
  MSG_ID_DEMO3009_REQ = 2095,
  MSG_ID_DEMO3009_RSP = 2096,
  MSG_ID_DEMO3010_REQ = 2097,
  MSG_ID_DEMO3010_RSP = 2098,
  MSG_ID_DEMO3020_REQ = 2099,
  MSG_ID_DEMO3020_RSP = 2100,
  MSG_ID_DEMO3050_REQ = 2101,
  MSG_ID_DEMO3050_RSP = 2102,
  MSG_ID_DEMO3090_REQ = 2103,
  MSG_ID_DEMO3090_RSP = 2104,
  MSG_ID_DEMO3002_NFY = 2105,
  MSG_ID_DEMO3005_NFY = 2106,
  MSG_ID_DEMO3009_NFY = 2107,
  MsgID_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  MsgID_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool MsgID_IsValid(int value);
const MsgID MsgID_MIN = PLACE_HOLDER;
const MsgID MsgID_MAX = MSG_ID_DEMO3009_NFY;
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

}  // namespace ss
}  // namespace demo
}  // namespace moon
}  // namespace com

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::com::moon::demo::ss::MsgID> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::com::moon::demo::ss::MsgID>() {
  return ::com::moon::demo::ss::MsgID_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_ss_5fmsg_5fid_2eproto
