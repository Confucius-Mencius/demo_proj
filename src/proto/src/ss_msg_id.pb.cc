// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ss_msg_id.proto

#include "ss_msg_id.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

namespace com {
namespace moon {
namespace demo {
namespace ss {
}  // namespace ss
}  // namespace demo
}  // namespace moon
}  // namespace com
namespace protobuf_ss_5fmsg_5fid_2eproto {
void InitDefaults() {
}

const ::google::protobuf::EnumDescriptor* file_level_enum_descriptors[1];
const ::google::protobuf::uint32 TableStruct::offsets[1] = {};
static const ::google::protobuf::internal::MigrationSchema* schemas = NULL;
static const ::google::protobuf::Message* const* file_default_instances = NULL;

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "ss_msg_id.proto", schemas, file_default_instances, TableStruct::offsets,
      NULL, file_level_enum_descriptors, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\017ss_msg_id.proto\022\020com.moon.demo.ss*\310\025\n\005"
      "MsgID\022\020\n\014PLACE_HOLDER\020\000\022\025\n\020MSG_ID_DEMO2_"
      "REQ\020\320\017\022\025\n\020MSG_ID_DEMO2_RSP\020\321\017\022\025\n\020MSG_ID_"
      "DEMO3_REQ\020\322\017\022\025\n\020MSG_ID_DEMO3_RSP\020\323\017\022\025\n\020M"
      "SG_ID_DEMO4_REQ\020\324\017\022\025\n\020MSG_ID_DEMO4_RSP\020\325"
      "\017\022\025\n\020MSG_ID_DEMO5_REQ\020\326\017\022\025\n\020MSG_ID_DEMO5"
      "_RSP\020\327\017\022\025\n\020MSG_ID_DEMO6_REQ\020\330\017\022\025\n\020MSG_ID"
      "_DEMO6_RSP\020\331\017\022\025\n\020MSG_ID_DEMO7_REQ\020\332\017\022\025\n\020"
      "MSG_ID_DEMO7_RSP\020\333\017\022\025\n\020MSG_ID_DEMO8_REQ\020"
      "\334\017\022\025\n\020MSG_ID_DEMO8_RSP\020\335\017\022\025\n\020MSG_ID_DEMO"
      "9_REQ\020\336\017\022\025\n\020MSG_ID_DEMO9_RSP\020\337\017\022\026\n\021MSG_I"
      "D_DEMO10_REQ\020\340\017\022\026\n\021MSG_ID_DEMO10_RSP\020\341\017\022"
      "\026\n\021MSG_ID_DEMO20_REQ\020\342\017\022\026\n\021MSG_ID_DEMO20"
      "_RSP\020\343\017\022\026\n\021MSG_ID_DEMO50_REQ\020\344\017\022\026\n\021MSG_I"
      "D_DEMO50_RSP\020\345\017\022\026\n\021MSG_ID_DEMO90_REQ\020\346\017\022"
      "\026\n\021MSG_ID_DEMO90_RSP\020\347\017\022\025\n\020MSG_ID_DEMO2_"
      "NFY\020\350\017\022\025\n\020MSG_ID_DEMO5_NFY\020\351\017\022\025\n\020MSG_ID_"
      "DEMO9_NFY\020\352\017\022\030\n\023MSG_ID_DEMO1002_REQ\020\353\017\022\030"
      "\n\023MSG_ID_DEMO1002_RSP\020\354\017\022\030\n\023MSG_ID_DEMO1"
      "003_REQ\020\355\017\022\030\n\023MSG_ID_DEMO1003_RSP\020\356\017\022\030\n\023"
      "MSG_ID_DEMO1004_REQ\020\357\017\022\030\n\023MSG_ID_DEMO100"
      "4_RSP\020\360\017\022\030\n\023MSG_ID_DEMO1005_REQ\020\361\017\022\030\n\023MS"
      "G_ID_DEMO1005_RSP\020\362\017\022\030\n\023MSG_ID_DEMO1006_"
      "REQ\020\363\017\022\030\n\023MSG_ID_DEMO1006_RSP\020\364\017\022\030\n\023MSG_"
      "ID_DEMO1007_REQ\020\365\017\022\030\n\023MSG_ID_DEMO1007_RS"
      "P\020\366\017\022\030\n\023MSG_ID_DEMO1008_REQ\020\367\017\022\030\n\023MSG_ID"
      "_DEMO1008_RSP\020\370\017\022\030\n\023MSG_ID_DEMO1009_REQ\020"
      "\371\017\022\030\n\023MSG_ID_DEMO1009_RSP\020\372\017\022\030\n\023MSG_ID_D"
      "EMO1010_REQ\020\373\017\022\030\n\023MSG_ID_DEMO1010_RSP\020\374\017"
      "\022\030\n\023MSG_ID_DEMO1020_REQ\020\375\017\022\030\n\023MSG_ID_DEM"
      "O1020_RSP\020\376\017\022\030\n\023MSG_ID_DEMO1050_REQ\020\377\017\022\030"
      "\n\023MSG_ID_DEMO1050_RSP\020\200\020\022\030\n\023MSG_ID_DEMO1"
      "090_REQ\020\201\020\022\030\n\023MSG_ID_DEMO1090_RSP\020\202\020\022\030\n\023"
      "MSG_ID_DEMO1002_NFY\020\203\020\022\030\n\023MSG_ID_DEMO100"
      "5_NFY\020\204\020\022\030\n\023MSG_ID_DEMO1009_NFY\020\205\020\022\030\n\023MS"
      "G_ID_DEMO2002_REQ\020\206\020\022\030\n\023MSG_ID_DEMO2002_"
      "RSP\020\207\020\022\030\n\023MSG_ID_DEMO2003_REQ\020\210\020\022\030\n\023MSG_"
      "ID_DEMO2003_RSP\020\211\020\022\030\n\023MSG_ID_DEMO2004_RE"
      "Q\020\212\020\022\030\n\023MSG_ID_DEMO2004_RSP\020\213\020\022\030\n\023MSG_ID"
      "_DEMO2005_REQ\020\214\020\022\030\n\023MSG_ID_DEMO2005_RSP\020"
      "\215\020\022\030\n\023MSG_ID_DEMO2006_REQ\020\216\020\022\030\n\023MSG_ID_D"
      "EMO2006_RSP\020\217\020\022\030\n\023MSG_ID_DEMO2007_REQ\020\220\020"
      "\022\030\n\023MSG_ID_DEMO2007_RSP\020\221\020\022\030\n\023MSG_ID_DEM"
      "O2008_REQ\020\222\020\022\030\n\023MSG_ID_DEMO2008_RSP\020\223\020\022\030"
      "\n\023MSG_ID_DEMO2009_REQ\020\224\020\022\030\n\023MSG_ID_DEMO2"
      "009_RSP\020\225\020\022\030\n\023MSG_ID_DEMO2010_REQ\020\226\020\022\030\n\023"
      "MSG_ID_DEMO2010_RSP\020\227\020\022\030\n\023MSG_ID_DEMO202"
      "0_REQ\020\230\020\022\030\n\023MSG_ID_DEMO2020_RSP\020\231\020\022\030\n\023MS"
      "G_ID_DEMO2050_REQ\020\232\020\022\030\n\023MSG_ID_DEMO2050_"
      "RSP\020\233\020\022\030\n\023MSG_ID_DEMO2090_REQ\020\234\020\022\030\n\023MSG_"
      "ID_DEMO2090_RSP\020\235\020\022\030\n\023MSG_ID_DEMO2002_NF"
      "Y\020\236\020\022\030\n\023MSG_ID_DEMO2005_NFY\020\237\020\022\030\n\023MSG_ID"
      "_DEMO2009_NFY\020\240\020\022\030\n\023MSG_ID_DEMO3002_REQ\020"
      "\241\020\022\030\n\023MSG_ID_DEMO3002_RSP\020\242\020\022\030\n\023MSG_ID_D"
      "EMO3003_REQ\020\243\020\022\030\n\023MSG_ID_DEMO3003_RSP\020\244\020"
      "\022\030\n\023MSG_ID_DEMO3004_REQ\020\245\020\022\030\n\023MSG_ID_DEM"
      "O3004_RSP\020\246\020\022\030\n\023MSG_ID_DEMO3005_REQ\020\247\020\022\030"
      "\n\023MSG_ID_DEMO3005_RSP\020\250\020\022\030\n\023MSG_ID_DEMO3"
      "006_REQ\020\251\020\022\030\n\023MSG_ID_DEMO3006_RSP\020\252\020\022\030\n\023"
      "MSG_ID_DEMO3007_REQ\020\253\020\022\030\n\023MSG_ID_DEMO300"
      "7_RSP\020\254\020\022\030\n\023MSG_ID_DEMO3008_REQ\020\255\020\022\030\n\023MS"
      "G_ID_DEMO3008_RSP\020\256\020\022\030\n\023MSG_ID_DEMO3009_"
      "REQ\020\257\020\022\030\n\023MSG_ID_DEMO3009_RSP\020\260\020\022\030\n\023MSG_"
      "ID_DEMO3010_REQ\020\261\020\022\030\n\023MSG_ID_DEMO3010_RS"
      "P\020\262\020\022\030\n\023MSG_ID_DEMO3020_REQ\020\263\020\022\030\n\023MSG_ID"
      "_DEMO3020_RSP\020\264\020\022\030\n\023MSG_ID_DEMO3050_REQ\020"
      "\265\020\022\030\n\023MSG_ID_DEMO3050_RSP\020\266\020\022\030\n\023MSG_ID_D"
      "EMO3090_REQ\020\267\020\022\030\n\023MSG_ID_DEMO3090_RSP\020\270\020"
      "\022\030\n\023MSG_ID_DEMO3002_NFY\020\271\020\022\030\n\023MSG_ID_DEM"
      "O3005_NFY\020\272\020\022\030\n\023MSG_ID_DEMO3009_NFY\020\273\020b\006"
      "proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 2806);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "ss_msg_id.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_ss_5fmsg_5fid_2eproto
namespace com {
namespace moon {
namespace demo {
namespace ss {
const ::google::protobuf::EnumDescriptor* MsgID_descriptor() {
  protobuf_ss_5fmsg_5fid_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_ss_5fmsg_5fid_2eproto::file_level_enum_descriptors[0];
}
bool MsgID_IsValid(int value) {
  switch (value) {
    case 0:
    case 2000:
    case 2001:
    case 2002:
    case 2003:
    case 2004:
    case 2005:
    case 2006:
    case 2007:
    case 2008:
    case 2009:
    case 2010:
    case 2011:
    case 2012:
    case 2013:
    case 2014:
    case 2015:
    case 2016:
    case 2017:
    case 2018:
    case 2019:
    case 2020:
    case 2021:
    case 2022:
    case 2023:
    case 2024:
    case 2025:
    case 2026:
    case 2027:
    case 2028:
    case 2029:
    case 2030:
    case 2031:
    case 2032:
    case 2033:
    case 2034:
    case 2035:
    case 2036:
    case 2037:
    case 2038:
    case 2039:
    case 2040:
    case 2041:
    case 2042:
    case 2043:
    case 2044:
    case 2045:
    case 2046:
    case 2047:
    case 2048:
    case 2049:
    case 2050:
    case 2051:
    case 2052:
    case 2053:
    case 2054:
    case 2055:
    case 2056:
    case 2057:
    case 2058:
    case 2059:
    case 2060:
    case 2061:
    case 2062:
    case 2063:
    case 2064:
    case 2065:
    case 2066:
    case 2067:
    case 2068:
    case 2069:
    case 2070:
    case 2071:
    case 2072:
    case 2073:
    case 2074:
    case 2075:
    case 2076:
    case 2077:
    case 2078:
    case 2079:
    case 2080:
    case 2081:
    case 2082:
    case 2083:
    case 2084:
    case 2085:
    case 2086:
    case 2087:
    case 2088:
    case 2089:
    case 2090:
    case 2091:
    case 2092:
    case 2093:
    case 2094:
    case 2095:
    case 2096:
    case 2097:
    case 2098:
    case 2099:
    case 2100:
    case 2101:
    case 2102:
    case 2103:
    case 2104:
    case 2105:
    case 2106:
    case 2107:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace ss
}  // namespace demo
}  // namespace moon
}  // namespace com
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
