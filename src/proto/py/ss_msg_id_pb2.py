# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: ss_msg_id.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf.internal import enum_type_wrapper
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='ss_msg_id.proto',
  package='com.moon.demo.ss',
  syntax='proto3',
  serialized_options=None,
  serialized_pb=_b('\n\x0fss_msg_id.proto\x12\x10\x63om.moon.demo.ss*\x91\x01\n\x05MsgID\x12\x10\n\x0cPLACE_HOLDER\x10\x00\x12\x16\n\x11MSG_ID_GLOBAL_REQ\x10\xd0\x0f\x12\x16\n\x11MSG_ID_GLOBAL_RSP\x10\xd1\x0f\x12\x16\n\x11MSG_ID_DEMO_1_REQ\x10\xd2\x0f\x12\x16\n\x11MSG_ID_DEMO_1_RSP\x10\xd3\x0f\x12\x16\n\x11MSG_ID_DEMO_1_NFY\x10\xd4\x0f\x62\x06proto3')
)

_MSGID = _descriptor.EnumDescriptor(
  name='MsgID',
  full_name='com.moon.demo.ss.MsgID',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='PLACE_HOLDER', index=0, number=0,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_GLOBAL_REQ', index=1, number=2000,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_GLOBAL_RSP', index=2, number=2001,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO_1_REQ', index=3, number=2002,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO_1_RSP', index=4, number=2003,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO_1_NFY', index=5, number=2004,
      serialized_options=None,
      type=None),
  ],
  containing_type=None,
  serialized_options=None,
  serialized_start=38,
  serialized_end=183,
)
_sym_db.RegisterEnumDescriptor(_MSGID)

MsgID = enum_type_wrapper.EnumTypeWrapper(_MSGID)
PLACE_HOLDER = 0
MSG_ID_GLOBAL_REQ = 2000
MSG_ID_GLOBAL_RSP = 2001
MSG_ID_DEMO_1_REQ = 2002
MSG_ID_DEMO_1_RSP = 2003
MSG_ID_DEMO_1_NFY = 2004


DESCRIPTOR.enum_types_by_name['MsgID'] = _MSGID
_sym_db.RegisterFileDescriptor(DESCRIPTOR)


# @@protoc_insertion_point(module_scope)
