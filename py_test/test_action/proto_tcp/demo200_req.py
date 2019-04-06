# -*- coding: utf-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import os
import sys

sys.path.append('%s/../../../../py_tools' % os.path.split(os.path.realpath(__file__))[0])
# print(sys.path)

from util.proto_msg_codec import *
import conf
from data.err_code import *

from com.moon.demo.cs import cs_msg_id_pb2
from com.moon.demo.cs import cs_msg_pb2


class Demo200Req(object):
    def __init__(self, client):
        self.client = client

    def __make_demo200_req(self):
        demo200_req = cs_msg_pb2.Demo200Req()
        demo200_req.a = 200

        LOG_DEBUG('%s%s' % (os.linesep, demo200_req))
        return demo200_req

    def __make_demo200_rsp(self, rsp_msg_body):
        demo200_rsp = cs_msg_pb2.Demo200Rsp()
        demo200_rsp.ParseFromString(rsp_msg_body)

        LOG_DEBUG('%s%s' % (os.linesep, demo200_rsp))
        return demo200_rsp

    def demo200(self):
        LOG_DEBUG('----- demo200_req -----')

        demo200_req_msg_head = MsgHead()
        demo200_req_msg_head.msg_id = cs_msg_id_pb2.MSG_ID_DEMO200_REQ

        demo200_req = self.__make_demo200_req()

        ret = self.client.send(demo200_req_msg_head, demo200_req.SerializeToString(), demo200_req.ByteSize(), conf.proto_tcp_do_checksum)
        if ret != 0:
            LOG_ERROR('failed to send to server %s' % self.client.server())
            return -1

        demo200_rsp_msg_head = MsgHead()

        ret, demo200_rsp_msg_head, demo200_rsp_msg_body = self.client.recv(conf.proto_tcp_do_checksum)
        if ret != -1:
            LOG_ERROR('ret: %d' % ret)
            return -1

        return 0
