# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: google/protobuf/internal/more_messages.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='google/protobuf/internal/more_messages.proto',
  package='google.protobuf.internal',
  syntax='proto2',
  serialized_options=None,
  serialized_pb=_b('\n,google/protobuf/internal/more_messages.proto\x12\x18google.protobuf.internal\"h\n\x10OutOfOrderFields\x12\x17\n\x0foptional_sint32\x18\x05 \x01(\x11\x12\x17\n\x0foptional_uint32\x18\x03 \x01(\r\x12\x16\n\x0eoptional_int32\x18\x01 \x01(\x05*\x04\x08\x04\x10\x05*\x04\x08\x02\x10\x03:C\n\x0foptional_uint64\x12*.google.protobuf.internal.OutOfOrderFields\x18\x04 \x01(\x04:B\n\x0eoptional_int64\x12*.google.protobuf.internal.OutOfOrderFields\x18\x02 \x01(\x03')
)


OPTIONAL_UINT64_FIELD_NUMBER = 4
optional_uint64 = _descriptor.FieldDescriptor(
  name='optional_uint64', full_name='google.protobuf.internal.optional_uint64', index=0,
  number=4, type=4, cpp_type=4, label=1,
  has_default_value=False, default_value=0,
  message_type=None, enum_type=None, containing_type=None,
  is_extension=True, extension_scope=None,
  serialized_options=None, file=DESCRIPTOR)
OPTIONAL_INT64_FIELD_NUMBER = 2
optional_int64 = _descriptor.FieldDescriptor(
  name='optional_int64', full_name='google.protobuf.internal.optional_int64', index=1,
  number=2, type=3, cpp_type=2, label=1,
  has_default_value=False, default_value=0,
  message_type=None, enum_type=None, containing_type=None,
  is_extension=True, extension_scope=None,
  serialized_options=None, file=DESCRIPTOR)


_OUTOFORDERFIELDS = _descriptor.Descriptor(
  name='OutOfOrderFields',
  full_name='google.protobuf.internal.OutOfOrderFields',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='optional_sint32', full_name='google.protobuf.internal.OutOfOrderFields.optional_sint32', index=0,
      number=5, type=17, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='optional_uint32', full_name='google.protobuf.internal.OutOfOrderFields.optional_uint32', index=1,
      number=3, type=13, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='optional_int32', full_name='google.protobuf.internal.OutOfOrderFields.optional_int32', index=2,
      number=1, type=5, cpp_type=1, label=1,
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
  is_extendable=True,
  syntax='proto2',
  extension_ranges=[(4, 5), (2, 3), ],
  oneofs=[
  ],
  serialized_start=74,
  serialized_end=178,
)

DESCRIPTOR.message_types_by_name['OutOfOrderFields'] = _OUTOFORDERFIELDS
DESCRIPTOR.extensions_by_name['optional_uint64'] = optional_uint64
DESCRIPTOR.extensions_by_name['optional_int64'] = optional_int64
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

OutOfOrderFields = _reflection.GeneratedProtocolMessageType('OutOfOrderFields', (_message.Message,), dict(
  DESCRIPTOR = _OUTOFORDERFIELDS,
  __module__ = 'google.protobuf.internal.more_messages_pb2'
  # @@protoc_insertion_point(class_scope:google.protobuf.internal.OutOfOrderFields)
  ))
_sym_db.RegisterMessage(OutOfOrderFields)

OutOfOrderFields.RegisterExtension(optional_uint64)
OutOfOrderFields.RegisterExtension(optional_int64)

# @@protoc_insertion_point(module_scope)
