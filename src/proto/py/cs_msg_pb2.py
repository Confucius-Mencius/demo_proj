# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: cs_msg.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf.internal import enum_type_wrapper
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


import common_pb2 as common__pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='cs_msg.proto',
  package='com.moon.demo.proto.cs',
  syntax='proto3',
  serialized_options=None,
  serialized_pb=_b('\n\x0c\x63s_msg.proto\x12\x16\x63om.moon.demo.proto.cs\x1a\x0c\x63ommon.proto\"\"\n\x08\x44\x65mo1Req\x12\t\n\x01\x61\x18\x01 \x01(\x05\x12\x0b\n\x03udp\x18\x02 \x01(\x08\"8\n\x08\x44\x65mo1Rsp\x12,\n\x07\x65rr_ctx\x18\x01 \x01(\x0b\x32\x1b.com.moon.demo.proto.ErrCtx\"\"\n\x08\x44\x65mo2Req\x12\t\n\x01\x61\x18\x01 \x01(\x05\x12\x0b\n\x03udp\x18\x02 \x01(\x08\"8\n\x08\x44\x65mo2Rsp\x12,\n\x07\x65rr_ctx\x18\x01 \x01(\x0b\x32\x1b.com.moon.demo.proto.ErrCtx\"\"\n\x08\x44\x65mo3Req\x12\t\n\x01\x61\x18\x01 \x01(\x05\x12\x0b\n\x03udp\x18\x02 \x01(\x08\"8\n\x08\x44\x65mo3Rsp\x12,\n\x07\x65rr_ctx\x18\x01 \x01(\x0b\x32\x1b.com.moon.demo.proto.ErrCtx\"g\n\x08\x44\x65mo4Req\x12\t\n\x01\x61\x18\x01 \x01(\x05\x12\t\n\x01\x62\x18\x02 \x01(\x03\x12\t\n\x01\x63\x18\x03 \x01(\t\x12\t\n\x01\x64\x18\x04 \x01(\x0c\x12/\n\x04\x66lag\x18\x05 \x01(\x0e\x32!.com.moon.demo.proto.cs.Demo4Flag\"8\n\x08\x44\x65mo4Rsp\x12,\n\x07\x65rr_ctx\x18\x01 \x01(\x0b\x32\x1b.com.moon.demo.proto.ErrCtx\"6\n\x08\x44\x65mo5Req\x12\t\n\x01\x61\x18\x01 \x01(\x05\x12\t\n\x01\x62\x18\x02 \x01(\x03\x12\t\n\x01\x63\x18\x03 \x01(\t\x12\t\n\x01\x64\x18\x04 \x01(\x0c\"8\n\x08\x44\x65mo5Rsp\x12,\n\x07\x65rr_ctx\x18\x01 \x01(\x0b\x32\x1b.com.moon.demo.proto.ErrCtx\"#\n\x08\x44\x65mo6Req\x12\t\n\x01\x61\x18\x01 \x01(\x05\x12\x0c\n\x04http\x18\x02 \x01(\x08\"8\n\x08\x44\x65mo6Rsp\x12,\n\x07\x65rr_ctx\x18\x01 \x01(\x0b\x32\x1b.com.moon.demo.proto.ErrCtx*\xb5\x01\n\tDemo4Flag\x12\x13\n\x0f\x44\x45MO_4_FLAG_MIN\x10\x00\x12\x1a\n\x16\x44\x45MO_4_FLAG_IO_TO_WORK\x10\x00\x12\x1c\n\x18\x44\x45MO_4_FLAG_WORK_TO_WORK\x10\x01\x12\x1e\n\x1a\x44\x45MO_4_FLAG_WORK_TO_BURDEN\x10\x02\x12 \n\x1c\x44\x45MO_4_FLAG_BURDEN_TO_BURDEN\x10\x03\x12\x13\n\x0f\x44\x45MO_4_FLAG_MAX\x10\x04\x1a\x02\x10\x01\x62\x06proto3')
  ,
  dependencies=[common__pb2.DESCRIPTOR,])

_DEMO4FLAG = _descriptor.EnumDescriptor(
  name='Demo4Flag',
  full_name='com.moon.demo.proto.cs.Demo4Flag',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='DEMO_4_FLAG_MIN', index=0, number=0,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='DEMO_4_FLAG_IO_TO_WORK', index=1, number=0,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='DEMO_4_FLAG_WORK_TO_WORK', index=2, number=1,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='DEMO_4_FLAG_WORK_TO_BURDEN', index=3, number=2,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='DEMO_4_FLAG_BURDEN_TO_BURDEN', index=4, number=3,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='DEMO_4_FLAG_MAX', index=5, number=4,
      serialized_options=None,
      type=None),
  ],
  containing_type=None,
  serialized_options=_b('\020\001'),
  serialized_start=709,
  serialized_end=890,
)
_sym_db.RegisterEnumDescriptor(_DEMO4FLAG)

Demo4Flag = enum_type_wrapper.EnumTypeWrapper(_DEMO4FLAG)
DEMO_4_FLAG_MIN = 0
DEMO_4_FLAG_IO_TO_WORK = 0
DEMO_4_FLAG_WORK_TO_WORK = 1
DEMO_4_FLAG_WORK_TO_BURDEN = 2
DEMO_4_FLAG_BURDEN_TO_BURDEN = 3
DEMO_4_FLAG_MAX = 4



_DEMO1REQ = _descriptor.Descriptor(
  name='Demo1Req',
  full_name='com.moon.demo.proto.cs.Demo1Req',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='a', full_name='com.moon.demo.proto.cs.Demo1Req.a', index=0,
      number=1, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='udp', full_name='com.moon.demo.proto.cs.Demo1Req.udp', index=1,
      number=2, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=54,
  serialized_end=88,
)


_DEMO1RSP = _descriptor.Descriptor(
  name='Demo1Rsp',
  full_name='com.moon.demo.proto.cs.Demo1Rsp',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='err_ctx', full_name='com.moon.demo.proto.cs.Demo1Rsp.err_ctx', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=90,
  serialized_end=146,
)


_DEMO2REQ = _descriptor.Descriptor(
  name='Demo2Req',
  full_name='com.moon.demo.proto.cs.Demo2Req',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='a', full_name='com.moon.demo.proto.cs.Demo2Req.a', index=0,
      number=1, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='udp', full_name='com.moon.demo.proto.cs.Demo2Req.udp', index=1,
      number=2, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=148,
  serialized_end=182,
)


_DEMO2RSP = _descriptor.Descriptor(
  name='Demo2Rsp',
  full_name='com.moon.demo.proto.cs.Demo2Rsp',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='err_ctx', full_name='com.moon.demo.proto.cs.Demo2Rsp.err_ctx', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=184,
  serialized_end=240,
)


_DEMO3REQ = _descriptor.Descriptor(
  name='Demo3Req',
  full_name='com.moon.demo.proto.cs.Demo3Req',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='a', full_name='com.moon.demo.proto.cs.Demo3Req.a', index=0,
      number=1, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='udp', full_name='com.moon.demo.proto.cs.Demo3Req.udp', index=1,
      number=2, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=242,
  serialized_end=276,
)


_DEMO3RSP = _descriptor.Descriptor(
  name='Demo3Rsp',
  full_name='com.moon.demo.proto.cs.Demo3Rsp',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='err_ctx', full_name='com.moon.demo.proto.cs.Demo3Rsp.err_ctx', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=278,
  serialized_end=334,
)


_DEMO4REQ = _descriptor.Descriptor(
  name='Demo4Req',
  full_name='com.moon.demo.proto.cs.Demo4Req',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='a', full_name='com.moon.demo.proto.cs.Demo4Req.a', index=0,
      number=1, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='b', full_name='com.moon.demo.proto.cs.Demo4Req.b', index=1,
      number=2, type=3, cpp_type=2, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='c', full_name='com.moon.demo.proto.cs.Demo4Req.c', index=2,
      number=3, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='d', full_name='com.moon.demo.proto.cs.Demo4Req.d', index=3,
      number=4, type=12, cpp_type=9, label=1,
      has_default_value=False, default_value=_b(""),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='flag', full_name='com.moon.demo.proto.cs.Demo4Req.flag', index=4,
      number=5, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=336,
  serialized_end=439,
)


_DEMO4RSP = _descriptor.Descriptor(
  name='Demo4Rsp',
  full_name='com.moon.demo.proto.cs.Demo4Rsp',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='err_ctx', full_name='com.moon.demo.proto.cs.Demo4Rsp.err_ctx', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=441,
  serialized_end=497,
)


_DEMO5REQ = _descriptor.Descriptor(
  name='Demo5Req',
  full_name='com.moon.demo.proto.cs.Demo5Req',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='a', full_name='com.moon.demo.proto.cs.Demo5Req.a', index=0,
      number=1, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='b', full_name='com.moon.demo.proto.cs.Demo5Req.b', index=1,
      number=2, type=3, cpp_type=2, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='c', full_name='com.moon.demo.proto.cs.Demo5Req.c', index=2,
      number=3, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='d', full_name='com.moon.demo.proto.cs.Demo5Req.d', index=3,
      number=4, type=12, cpp_type=9, label=1,
      has_default_value=False, default_value=_b(""),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=499,
  serialized_end=553,
)


_DEMO5RSP = _descriptor.Descriptor(
  name='Demo5Rsp',
  full_name='com.moon.demo.proto.cs.Demo5Rsp',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='err_ctx', full_name='com.moon.demo.proto.cs.Demo5Rsp.err_ctx', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=555,
  serialized_end=611,
)


_DEMO6REQ = _descriptor.Descriptor(
  name='Demo6Req',
  full_name='com.moon.demo.proto.cs.Demo6Req',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='a', full_name='com.moon.demo.proto.cs.Demo6Req.a', index=0,
      number=1, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='http', full_name='com.moon.demo.proto.cs.Demo6Req.http', index=1,
      number=2, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=613,
  serialized_end=648,
)


_DEMO6RSP = _descriptor.Descriptor(
  name='Demo6Rsp',
  full_name='com.moon.demo.proto.cs.Demo6Rsp',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='err_ctx', full_name='com.moon.demo.proto.cs.Demo6Rsp.err_ctx', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=650,
  serialized_end=706,
)

_DEMO1RSP.fields_by_name['err_ctx'].message_type = common__pb2._ERRCTX
_DEMO2RSP.fields_by_name['err_ctx'].message_type = common__pb2._ERRCTX
_DEMO3RSP.fields_by_name['err_ctx'].message_type = common__pb2._ERRCTX
_DEMO4REQ.fields_by_name['flag'].enum_type = _DEMO4FLAG
_DEMO4RSP.fields_by_name['err_ctx'].message_type = common__pb2._ERRCTX
_DEMO5RSP.fields_by_name['err_ctx'].message_type = common__pb2._ERRCTX
_DEMO6RSP.fields_by_name['err_ctx'].message_type = common__pb2._ERRCTX
DESCRIPTOR.message_types_by_name['Demo1Req'] = _DEMO1REQ
DESCRIPTOR.message_types_by_name['Demo1Rsp'] = _DEMO1RSP
DESCRIPTOR.message_types_by_name['Demo2Req'] = _DEMO2REQ
DESCRIPTOR.message_types_by_name['Demo2Rsp'] = _DEMO2RSP
DESCRIPTOR.message_types_by_name['Demo3Req'] = _DEMO3REQ
DESCRIPTOR.message_types_by_name['Demo3Rsp'] = _DEMO3RSP
DESCRIPTOR.message_types_by_name['Demo4Req'] = _DEMO4REQ
DESCRIPTOR.message_types_by_name['Demo4Rsp'] = _DEMO4RSP
DESCRIPTOR.message_types_by_name['Demo5Req'] = _DEMO5REQ
DESCRIPTOR.message_types_by_name['Demo5Rsp'] = _DEMO5RSP
DESCRIPTOR.message_types_by_name['Demo6Req'] = _DEMO6REQ
DESCRIPTOR.message_types_by_name['Demo6Rsp'] = _DEMO6RSP
DESCRIPTOR.enum_types_by_name['Demo4Flag'] = _DEMO4FLAG
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

Demo1Req = _reflection.GeneratedProtocolMessageType('Demo1Req', (_message.Message,), dict(
  DESCRIPTOR = _DEMO1REQ,
  __module__ = 'cs_msg_pb2'
  # @@protoc_insertion_point(class_scope:com.moon.demo.proto.cs.Demo1Req)
  ))
_sym_db.RegisterMessage(Demo1Req)

Demo1Rsp = _reflection.GeneratedProtocolMessageType('Demo1Rsp', (_message.Message,), dict(
  DESCRIPTOR = _DEMO1RSP,
  __module__ = 'cs_msg_pb2'
  # @@protoc_insertion_point(class_scope:com.moon.demo.proto.cs.Demo1Rsp)
  ))
_sym_db.RegisterMessage(Demo1Rsp)

Demo2Req = _reflection.GeneratedProtocolMessageType('Demo2Req', (_message.Message,), dict(
  DESCRIPTOR = _DEMO2REQ,
  __module__ = 'cs_msg_pb2'
  # @@protoc_insertion_point(class_scope:com.moon.demo.proto.cs.Demo2Req)
  ))
_sym_db.RegisterMessage(Demo2Req)

Demo2Rsp = _reflection.GeneratedProtocolMessageType('Demo2Rsp', (_message.Message,), dict(
  DESCRIPTOR = _DEMO2RSP,
  __module__ = 'cs_msg_pb2'
  # @@protoc_insertion_point(class_scope:com.moon.demo.proto.cs.Demo2Rsp)
  ))
_sym_db.RegisterMessage(Demo2Rsp)

Demo3Req = _reflection.GeneratedProtocolMessageType('Demo3Req', (_message.Message,), dict(
  DESCRIPTOR = _DEMO3REQ,
  __module__ = 'cs_msg_pb2'
  # @@protoc_insertion_point(class_scope:com.moon.demo.proto.cs.Demo3Req)
  ))
_sym_db.RegisterMessage(Demo3Req)

Demo3Rsp = _reflection.GeneratedProtocolMessageType('Demo3Rsp', (_message.Message,), dict(
  DESCRIPTOR = _DEMO3RSP,
  __module__ = 'cs_msg_pb2'
  # @@protoc_insertion_point(class_scope:com.moon.demo.proto.cs.Demo3Rsp)
  ))
_sym_db.RegisterMessage(Demo3Rsp)

Demo4Req = _reflection.GeneratedProtocolMessageType('Demo4Req', (_message.Message,), dict(
  DESCRIPTOR = _DEMO4REQ,
  __module__ = 'cs_msg_pb2'
  # @@protoc_insertion_point(class_scope:com.moon.demo.proto.cs.Demo4Req)
  ))
_sym_db.RegisterMessage(Demo4Req)

Demo4Rsp = _reflection.GeneratedProtocolMessageType('Demo4Rsp', (_message.Message,), dict(
  DESCRIPTOR = _DEMO4RSP,
  __module__ = 'cs_msg_pb2'
  # @@protoc_insertion_point(class_scope:com.moon.demo.proto.cs.Demo4Rsp)
  ))
_sym_db.RegisterMessage(Demo4Rsp)

Demo5Req = _reflection.GeneratedProtocolMessageType('Demo5Req', (_message.Message,), dict(
  DESCRIPTOR = _DEMO5REQ,
  __module__ = 'cs_msg_pb2'
  # @@protoc_insertion_point(class_scope:com.moon.demo.proto.cs.Demo5Req)
  ))
_sym_db.RegisterMessage(Demo5Req)

Demo5Rsp = _reflection.GeneratedProtocolMessageType('Demo5Rsp', (_message.Message,), dict(
  DESCRIPTOR = _DEMO5RSP,
  __module__ = 'cs_msg_pb2'
  # @@protoc_insertion_point(class_scope:com.moon.demo.proto.cs.Demo5Rsp)
  ))
_sym_db.RegisterMessage(Demo5Rsp)

Demo6Req = _reflection.GeneratedProtocolMessageType('Demo6Req', (_message.Message,), dict(
  DESCRIPTOR = _DEMO6REQ,
  __module__ = 'cs_msg_pb2'
  # @@protoc_insertion_point(class_scope:com.moon.demo.proto.cs.Demo6Req)
  ))
_sym_db.RegisterMessage(Demo6Req)

Demo6Rsp = _reflection.GeneratedProtocolMessageType('Demo6Rsp', (_message.Message,), dict(
  DESCRIPTOR = _DEMO6RSP,
  __module__ = 'cs_msg_pb2'
  # @@protoc_insertion_point(class_scope:com.moon.demo.proto.cs.Demo6Rsp)
  ))
_sym_db.RegisterMessage(Demo6Rsp)


_DEMO4FLAG._options = None
# @@protoc_insertion_point(module_scope)