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


class Demo100Req(object):
    def __init__(self, client):
        self.client = client

    # TODO
    def set_xx(self, xx):
        self.xx = xx

    def __make_demo100_req(self):
        demo100_req = cs_msg_pb2.Demo100Req()
        demo100_req.a = 100

        LOG_DEBUG('%s%s' % (os.linesep, demo100_req))
        return demo100_req

    def __make_demo100_rsp(self, rsp_msg_body):
        demo100_rsp = cs_msg_pb2.Demo100Rsp()
        demo100_rsp.ParseFromString(rsp_msg_body)

        LOG_DEBUG('%s%s' % (os.linesep, demo100_rsp))
        return demo100_rsp

    def demo100(self):
        LOG_DEBUG('----- demo100_req -----')

        msg_head = MsgHead()
        msg_head.msg_id = cs_msg_id_pb2.MSG_ID_DEMO100_REQ

        demo100_req = self.__make_demo100_req()

        ret = self.client.send(msg_head, demo100_req.SerializeToString(), demo100_req.ByteSize(), conf.proto_tcp_do_checksum)
        if ret != 0:
            LOG_ERROR('failed to send to server %s' % self.client.server())
            return -1

        rsp_msg_head = MsgHead()

        ret, rsp_msg_head, rsp_msg_body = self.client.recv(conf.proto_tcp_do_checksum)
        if ret != 0:
            LOG_ERROR('ret: %d' % ret)
            return -1

        if rsp_msg_head.msg_id != cs_msg_id_pb2.MSG_ID_DEMO100_RSP:
            LOG_ERROR('error rsp msg id: %d' % rsp_msg_head.msg_id)
            return -1

        demo100_rsp = self.__make_demo100_rsp(rsp_msg_body)

        err_code = demo100_rsp.err_ctx.err_code
        if err_code != 0:
            LOG_ERROR('demo100_rsp failed err code: %d' % err_code)
            return err_code

        return 0