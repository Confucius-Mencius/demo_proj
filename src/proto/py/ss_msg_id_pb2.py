# -*- coding: utf-8 -*-
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
  serialized_pb=_b('\n\x0fss_msg_id.proto\x12\x10\x63om.moon.demo.ss*\xc8\x15\n\x05MsgID\x12\x10\n\x0cPLACE_HOLDER\x10\x00\x12\x15\n\x10MSG_ID_DEMO2_REQ\x10\xd0\x0f\x12\x15\n\x10MSG_ID_DEMO2_RSP\x10\xd1\x0f\x12\x15\n\x10MSG_ID_DEMO3_REQ\x10\xd2\x0f\x12\x15\n\x10MSG_ID_DEMO3_RSP\x10\xd3\x0f\x12\x15\n\x10MSG_ID_DEMO4_REQ\x10\xd4\x0f\x12\x15\n\x10MSG_ID_DEMO4_RSP\x10\xd5\x0f\x12\x15\n\x10MSG_ID_DEMO5_REQ\x10\xd6\x0f\x12\x15\n\x10MSG_ID_DEMO5_RSP\x10\xd7\x0f\x12\x15\n\x10MSG_ID_DEMO6_REQ\x10\xd8\x0f\x12\x15\n\x10MSG_ID_DEMO6_RSP\x10\xd9\x0f\x12\x15\n\x10MSG_ID_DEMO7_REQ\x10\xda\x0f\x12\x15\n\x10MSG_ID_DEMO7_RSP\x10\xdb\x0f\x12\x15\n\x10MSG_ID_DEMO8_REQ\x10\xdc\x0f\x12\x15\n\x10MSG_ID_DEMO8_RSP\x10\xdd\x0f\x12\x15\n\x10MSG_ID_DEMO9_REQ\x10\xde\x0f\x12\x15\n\x10MSG_ID_DEMO9_RSP\x10\xdf\x0f\x12\x16\n\x11MSG_ID_DEMO10_REQ\x10\xe0\x0f\x12\x16\n\x11MSG_ID_DEMO10_RSP\x10\xe1\x0f\x12\x16\n\x11MSG_ID_DEMO20_REQ\x10\xe2\x0f\x12\x16\n\x11MSG_ID_DEMO20_RSP\x10\xe3\x0f\x12\x16\n\x11MSG_ID_DEMO50_REQ\x10\xe4\x0f\x12\x16\n\x11MSG_ID_DEMO50_RSP\x10\xe5\x0f\x12\x16\n\x11MSG_ID_DEMO90_REQ\x10\xe6\x0f\x12\x16\n\x11MSG_ID_DEMO90_RSP\x10\xe7\x0f\x12\x15\n\x10MSG_ID_DEMO2_NFY\x10\xe8\x0f\x12\x15\n\x10MSG_ID_DEMO5_NFY\x10\xe9\x0f\x12\x15\n\x10MSG_ID_DEMO9_NFY\x10\xea\x0f\x12\x18\n\x13MSG_ID_DEMO1002_REQ\x10\xeb\x0f\x12\x18\n\x13MSG_ID_DEMO1002_RSP\x10\xec\x0f\x12\x18\n\x13MSG_ID_DEMO1003_REQ\x10\xed\x0f\x12\x18\n\x13MSG_ID_DEMO1003_RSP\x10\xee\x0f\x12\x18\n\x13MSG_ID_DEMO1004_REQ\x10\xef\x0f\x12\x18\n\x13MSG_ID_DEMO1004_RSP\x10\xf0\x0f\x12\x18\n\x13MSG_ID_DEMO1005_REQ\x10\xf1\x0f\x12\x18\n\x13MSG_ID_DEMO1005_RSP\x10\xf2\x0f\x12\x18\n\x13MSG_ID_DEMO1006_REQ\x10\xf3\x0f\x12\x18\n\x13MSG_ID_DEMO1006_RSP\x10\xf4\x0f\x12\x18\n\x13MSG_ID_DEMO1007_REQ\x10\xf5\x0f\x12\x18\n\x13MSG_ID_DEMO1007_RSP\x10\xf6\x0f\x12\x18\n\x13MSG_ID_DEMO1008_REQ\x10\xf7\x0f\x12\x18\n\x13MSG_ID_DEMO1008_RSP\x10\xf8\x0f\x12\x18\n\x13MSG_ID_DEMO1009_REQ\x10\xf9\x0f\x12\x18\n\x13MSG_ID_DEMO1009_RSP\x10\xfa\x0f\x12\x18\n\x13MSG_ID_DEMO1010_REQ\x10\xfb\x0f\x12\x18\n\x13MSG_ID_DEMO1010_RSP\x10\xfc\x0f\x12\x18\n\x13MSG_ID_DEMO1020_REQ\x10\xfd\x0f\x12\x18\n\x13MSG_ID_DEMO1020_RSP\x10\xfe\x0f\x12\x18\n\x13MSG_ID_DEMO1050_REQ\x10\xff\x0f\x12\x18\n\x13MSG_ID_DEMO1050_RSP\x10\x80\x10\x12\x18\n\x13MSG_ID_DEMO1090_REQ\x10\x81\x10\x12\x18\n\x13MSG_ID_DEMO1090_RSP\x10\x82\x10\x12\x18\n\x13MSG_ID_DEMO1002_NFY\x10\x83\x10\x12\x18\n\x13MSG_ID_DEMO1005_NFY\x10\x84\x10\x12\x18\n\x13MSG_ID_DEMO1009_NFY\x10\x85\x10\x12\x18\n\x13MSG_ID_DEMO2002_REQ\x10\x86\x10\x12\x18\n\x13MSG_ID_DEMO2002_RSP\x10\x87\x10\x12\x18\n\x13MSG_ID_DEMO2003_REQ\x10\x88\x10\x12\x18\n\x13MSG_ID_DEMO2003_RSP\x10\x89\x10\x12\x18\n\x13MSG_ID_DEMO2004_REQ\x10\x8a\x10\x12\x18\n\x13MSG_ID_DEMO2004_RSP\x10\x8b\x10\x12\x18\n\x13MSG_ID_DEMO2005_REQ\x10\x8c\x10\x12\x18\n\x13MSG_ID_DEMO2005_RSP\x10\x8d\x10\x12\x18\n\x13MSG_ID_DEMO2006_REQ\x10\x8e\x10\x12\x18\n\x13MSG_ID_DEMO2006_RSP\x10\x8f\x10\x12\x18\n\x13MSG_ID_DEMO2007_REQ\x10\x90\x10\x12\x18\n\x13MSG_ID_DEMO2007_RSP\x10\x91\x10\x12\x18\n\x13MSG_ID_DEMO2008_REQ\x10\x92\x10\x12\x18\n\x13MSG_ID_DEMO2008_RSP\x10\x93\x10\x12\x18\n\x13MSG_ID_DEMO2009_REQ\x10\x94\x10\x12\x18\n\x13MSG_ID_DEMO2009_RSP\x10\x95\x10\x12\x18\n\x13MSG_ID_DEMO2010_REQ\x10\x96\x10\x12\x18\n\x13MSG_ID_DEMO2010_RSP\x10\x97\x10\x12\x18\n\x13MSG_ID_DEMO2020_REQ\x10\x98\x10\x12\x18\n\x13MSG_ID_DEMO2020_RSP\x10\x99\x10\x12\x18\n\x13MSG_ID_DEMO2050_REQ\x10\x9a\x10\x12\x18\n\x13MSG_ID_DEMO2050_RSP\x10\x9b\x10\x12\x18\n\x13MSG_ID_DEMO2090_REQ\x10\x9c\x10\x12\x18\n\x13MSG_ID_DEMO2090_RSP\x10\x9d\x10\x12\x18\n\x13MSG_ID_DEMO2002_NFY\x10\x9e\x10\x12\x18\n\x13MSG_ID_DEMO2005_NFY\x10\x9f\x10\x12\x18\n\x13MSG_ID_DEMO2009_NFY\x10\xa0\x10\x12\x18\n\x13MSG_ID_DEMO3002_REQ\x10\xa1\x10\x12\x18\n\x13MSG_ID_DEMO3002_RSP\x10\xa2\x10\x12\x18\n\x13MSG_ID_DEMO3003_REQ\x10\xa3\x10\x12\x18\n\x13MSG_ID_DEMO3003_RSP\x10\xa4\x10\x12\x18\n\x13MSG_ID_DEMO3004_REQ\x10\xa5\x10\x12\x18\n\x13MSG_ID_DEMO3004_RSP\x10\xa6\x10\x12\x18\n\x13MSG_ID_DEMO3005_REQ\x10\xa7\x10\x12\x18\n\x13MSG_ID_DEMO3005_RSP\x10\xa8\x10\x12\x18\n\x13MSG_ID_DEMO3006_REQ\x10\xa9\x10\x12\x18\n\x13MSG_ID_DEMO3006_RSP\x10\xaa\x10\x12\x18\n\x13MSG_ID_DEMO3007_REQ\x10\xab\x10\x12\x18\n\x13MSG_ID_DEMO3007_RSP\x10\xac\x10\x12\x18\n\x13MSG_ID_DEMO3008_REQ\x10\xad\x10\x12\x18\n\x13MSG_ID_DEMO3008_RSP\x10\xae\x10\x12\x18\n\x13MSG_ID_DEMO3009_REQ\x10\xaf\x10\x12\x18\n\x13MSG_ID_DEMO3009_RSP\x10\xb0\x10\x12\x18\n\x13MSG_ID_DEMO3010_REQ\x10\xb1\x10\x12\x18\n\x13MSG_ID_DEMO3010_RSP\x10\xb2\x10\x12\x18\n\x13MSG_ID_DEMO3020_REQ\x10\xb3\x10\x12\x18\n\x13MSG_ID_DEMO3020_RSP\x10\xb4\x10\x12\x18\n\x13MSG_ID_DEMO3050_REQ\x10\xb5\x10\x12\x18\n\x13MSG_ID_DEMO3050_RSP\x10\xb6\x10\x12\x18\n\x13MSG_ID_DEMO3090_REQ\x10\xb7\x10\x12\x18\n\x13MSG_ID_DEMO3090_RSP\x10\xb8\x10\x12\x18\n\x13MSG_ID_DEMO3002_NFY\x10\xb9\x10\x12\x18\n\x13MSG_ID_DEMO3005_NFY\x10\xba\x10\x12\x18\n\x13MSG_ID_DEMO3009_NFY\x10\xbb\x10\x62\x06proto3')
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
      name='MSG_ID_DEMO2_REQ', index=1, number=2000,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO2_RSP', index=2, number=2001,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO3_REQ', index=3, number=2002,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO3_RSP', index=4, number=2003,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO4_REQ', index=5, number=2004,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO4_RSP', index=6, number=2005,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO5_REQ', index=7, number=2006,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO5_RSP', index=8, number=2007,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO6_REQ', index=9, number=2008,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO6_RSP', index=10, number=2009,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO7_REQ', index=11, number=2010,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO7_RSP', index=12, number=2011,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO8_REQ', index=13, number=2012,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO8_RSP', index=14, number=2013,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO9_REQ', index=15, number=2014,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO9_RSP', index=16, number=2015,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO10_REQ', index=17, number=2016,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO10_RSP', index=18, number=2017,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO20_REQ', index=19, number=2018,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO20_RSP', index=20, number=2019,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO50_REQ', index=21, number=2020,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO50_RSP', index=22, number=2021,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO90_REQ', index=23, number=2022,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO90_RSP', index=24, number=2023,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO2_NFY', index=25, number=2024,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO5_NFY', index=26, number=2025,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO9_NFY', index=27, number=2026,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO1002_REQ', index=28, number=2027,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO1002_RSP', index=29, number=2028,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO1003_REQ', index=30, number=2029,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO1003_RSP', index=31, number=2030,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO1004_REQ', index=32, number=2031,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO1004_RSP', index=33, number=2032,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO1005_REQ', index=34, number=2033,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO1005_RSP', index=35, number=2034,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO1006_REQ', index=36, number=2035,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO1006_RSP', index=37, number=2036,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO1007_REQ', index=38, number=2037,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO1007_RSP', index=39, number=2038,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO1008_REQ', index=40, number=2039,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO1008_RSP', index=41, number=2040,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO1009_REQ', index=42, number=2041,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO1009_RSP', index=43, number=2042,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO1010_REQ', index=44, number=2043,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO1010_RSP', index=45, number=2044,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO1020_REQ', index=46, number=2045,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO1020_RSP', index=47, number=2046,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO1050_REQ', index=48, number=2047,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO1050_RSP', index=49, number=2048,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO1090_REQ', index=50, number=2049,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO1090_RSP', index=51, number=2050,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO1002_NFY', index=52, number=2051,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO1005_NFY', index=53, number=2052,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO1009_NFY', index=54, number=2053,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO2002_REQ', index=55, number=2054,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO2002_RSP', index=56, number=2055,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO2003_REQ', index=57, number=2056,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO2003_RSP', index=58, number=2057,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO2004_REQ', index=59, number=2058,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO2004_RSP', index=60, number=2059,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO2005_REQ', index=61, number=2060,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO2005_RSP', index=62, number=2061,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO2006_REQ', index=63, number=2062,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO2006_RSP', index=64, number=2063,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO2007_REQ', index=65, number=2064,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO2007_RSP', index=66, number=2065,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO2008_REQ', index=67, number=2066,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO2008_RSP', index=68, number=2067,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO2009_REQ', index=69, number=2068,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO2009_RSP', index=70, number=2069,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO2010_REQ', index=71, number=2070,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO2010_RSP', index=72, number=2071,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO2020_REQ', index=73, number=2072,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO2020_RSP', index=74, number=2073,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO2050_REQ', index=75, number=2074,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO2050_RSP', index=76, number=2075,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO2090_REQ', index=77, number=2076,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO2090_RSP', index=78, number=2077,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO2002_NFY', index=79, number=2078,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO2005_NFY', index=80, number=2079,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO2009_NFY', index=81, number=2080,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO3002_REQ', index=82, number=2081,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO3002_RSP', index=83, number=2082,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO3003_REQ', index=84, number=2083,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO3003_RSP', index=85, number=2084,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO3004_REQ', index=86, number=2085,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO3004_RSP', index=87, number=2086,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO3005_REQ', index=88, number=2087,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO3005_RSP', index=89, number=2088,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO3006_REQ', index=90, number=2089,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO3006_RSP', index=91, number=2090,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO3007_REQ', index=92, number=2091,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO3007_RSP', index=93, number=2092,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO3008_REQ', index=94, number=2093,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO3008_RSP', index=95, number=2094,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO3009_REQ', index=96, number=2095,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO3009_RSP', index=97, number=2096,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO3010_REQ', index=98, number=2097,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO3010_RSP', index=99, number=2098,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO3020_REQ', index=100, number=2099,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO3020_RSP', index=101, number=2100,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO3050_REQ', index=102, number=2101,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO3050_RSP', index=103, number=2102,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO3090_REQ', index=104, number=2103,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO3090_RSP', index=105, number=2104,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO3002_NFY', index=106, number=2105,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO3005_NFY', index=107, number=2106,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ID_DEMO3009_NFY', index=108, number=2107,
      serialized_options=None,
      type=None),
  ],
  containing_type=None,
  serialized_options=None,
  serialized_start=38,
  serialized_end=2798,
)
_sym_db.RegisterEnumDescriptor(_MSGID)

MsgID = enum_type_wrapper.EnumTypeWrapper(_MSGID)
PLACE_HOLDER = 0
MSG_ID_DEMO2_REQ = 2000
MSG_ID_DEMO2_RSP = 2001
MSG_ID_DEMO3_REQ = 2002
MSG_ID_DEMO3_RSP = 2003
MSG_ID_DEMO4_REQ = 2004
MSG_ID_DEMO4_RSP = 2005
MSG_ID_DEMO5_REQ = 2006
MSG_ID_DEMO5_RSP = 2007
MSG_ID_DEMO6_REQ = 2008
MSG_ID_DEMO6_RSP = 2009
MSG_ID_DEMO7_REQ = 2010
MSG_ID_DEMO7_RSP = 2011
MSG_ID_DEMO8_REQ = 2012
MSG_ID_DEMO8_RSP = 2013
MSG_ID_DEMO9_REQ = 2014
MSG_ID_DEMO9_RSP = 2015
MSG_ID_DEMO10_REQ = 2016
MSG_ID_DEMO10_RSP = 2017
MSG_ID_DEMO20_REQ = 2018
MSG_ID_DEMO20_RSP = 2019
MSG_ID_DEMO50_REQ = 2020
MSG_ID_DEMO50_RSP = 2021
MSG_ID_DEMO90_REQ = 2022
MSG_ID_DEMO90_RSP = 2023
MSG_ID_DEMO2_NFY = 2024
MSG_ID_DEMO5_NFY = 2025
MSG_ID_DEMO9_NFY = 2026
MSG_ID_DEMO1002_REQ = 2027
MSG_ID_DEMO1002_RSP = 2028
MSG_ID_DEMO1003_REQ = 2029
MSG_ID_DEMO1003_RSP = 2030
MSG_ID_DEMO1004_REQ = 2031
MSG_ID_DEMO1004_RSP = 2032
MSG_ID_DEMO1005_REQ = 2033
MSG_ID_DEMO1005_RSP = 2034
MSG_ID_DEMO1006_REQ = 2035
MSG_ID_DEMO1006_RSP = 2036
MSG_ID_DEMO1007_REQ = 2037
MSG_ID_DEMO1007_RSP = 2038
MSG_ID_DEMO1008_REQ = 2039
MSG_ID_DEMO1008_RSP = 2040
MSG_ID_DEMO1009_REQ = 2041
MSG_ID_DEMO1009_RSP = 2042
MSG_ID_DEMO1010_REQ = 2043
MSG_ID_DEMO1010_RSP = 2044
MSG_ID_DEMO1020_REQ = 2045
MSG_ID_DEMO1020_RSP = 2046
MSG_ID_DEMO1050_REQ = 2047
MSG_ID_DEMO1050_RSP = 2048
MSG_ID_DEMO1090_REQ = 2049
MSG_ID_DEMO1090_RSP = 2050
MSG_ID_DEMO1002_NFY = 2051
MSG_ID_DEMO1005_NFY = 2052
MSG_ID_DEMO1009_NFY = 2053
MSG_ID_DEMO2002_REQ = 2054
MSG_ID_DEMO2002_RSP = 2055
MSG_ID_DEMO2003_REQ = 2056
MSG_ID_DEMO2003_RSP = 2057
MSG_ID_DEMO2004_REQ = 2058
MSG_ID_DEMO2004_RSP = 2059
MSG_ID_DEMO2005_REQ = 2060
MSG_ID_DEMO2005_RSP = 2061
MSG_ID_DEMO2006_REQ = 2062
MSG_ID_DEMO2006_RSP = 2063
MSG_ID_DEMO2007_REQ = 2064
MSG_ID_DEMO2007_RSP = 2065
MSG_ID_DEMO2008_REQ = 2066
MSG_ID_DEMO2008_RSP = 2067
MSG_ID_DEMO2009_REQ = 2068
MSG_ID_DEMO2009_RSP = 2069
MSG_ID_DEMO2010_REQ = 2070
MSG_ID_DEMO2010_RSP = 2071
MSG_ID_DEMO2020_REQ = 2072
MSG_ID_DEMO2020_RSP = 2073
MSG_ID_DEMO2050_REQ = 2074
MSG_ID_DEMO2050_RSP = 2075
MSG_ID_DEMO2090_REQ = 2076
MSG_ID_DEMO2090_RSP = 2077
MSG_ID_DEMO2002_NFY = 2078
MSG_ID_DEMO2005_NFY = 2079
MSG_ID_DEMO2009_NFY = 2080
MSG_ID_DEMO3002_REQ = 2081
MSG_ID_DEMO3002_RSP = 2082
MSG_ID_DEMO3003_REQ = 2083
MSG_ID_DEMO3003_RSP = 2084
MSG_ID_DEMO3004_REQ = 2085
MSG_ID_DEMO3004_RSP = 2086
MSG_ID_DEMO3005_REQ = 2087
MSG_ID_DEMO3005_RSP = 2088
MSG_ID_DEMO3006_REQ = 2089
MSG_ID_DEMO3006_RSP = 2090
MSG_ID_DEMO3007_REQ = 2091
MSG_ID_DEMO3007_RSP = 2092
MSG_ID_DEMO3008_REQ = 2093
MSG_ID_DEMO3008_RSP = 2094
MSG_ID_DEMO3009_REQ = 2095
MSG_ID_DEMO3009_RSP = 2096
MSG_ID_DEMO3010_REQ = 2097
MSG_ID_DEMO3010_RSP = 2098
MSG_ID_DEMO3020_REQ = 2099
MSG_ID_DEMO3020_RSP = 2100
MSG_ID_DEMO3050_REQ = 2101
MSG_ID_DEMO3050_RSP = 2102
MSG_ID_DEMO3090_REQ = 2103
MSG_ID_DEMO3090_RSP = 2104
MSG_ID_DEMO3002_NFY = 2105
MSG_ID_DEMO3005_NFY = 2106
MSG_ID_DEMO3009_NFY = 2107


DESCRIPTOR.enum_types_by_name['MsgID'] = _MSGID
_sym_db.RegisterFileDescriptor(DESCRIPTOR)


# @@protoc_insertion_point(module_scope)
