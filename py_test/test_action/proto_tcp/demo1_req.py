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


class Demo1Req(object):
    def __init__(self, client):
        self.client = client

    def __make_demo1_req(self):
        demo1_req = cs_msg_pb2.Demo1Req()
        demo1_req.a = 1

        LOG_DEBUG('%s%s' % (os.linesep, demo1_req))
        return demo1_req

    def __make_demo1_rsp(self, rsp_msg_body):
        demo1_rsp = cs_msg_pb2.Demo1Rsp()
        demo1_rsp.ParseFromString(rsp_msg_body)

        LOG_DEBUG('%s%s' % (os.linesep, demo1_rsp))
        return demo1_rsp

    def __make_demo1_nfy(self, nfy_msg_body):
        demo1_nfy = cs_msg_pb2.Demo1Nfy()
        demo1_nfy.ParseFromString(nfy_msg_body)

        LOG_DEBUG('%s%s' % (os.linesep, demo1_nfy))
        return demo1_nfy

    def demo1(self):
        LOG_DEBUG('----- demo1_req -----')

        demo1_req_msg_head = MsgHead()
        demo1_req_msg_head.msg_id = cs_msg_id_pb2.MSG_ID_DEMO1_REQ

        demo1_req = self.__make_demo1_req()

        ret = self.client.send(demo1_req_msg_head, demo1_req.SerializeToString(), demo1_req.ByteSize(), conf.proto_tcp_do_checksum)
        if ret != 0:
            LOG_ERROR('failed to send to server %s' % self.client.server())
            return -1

        # 收Demo1Rsp
        demo1_rsp_msg_head = MsgHead()

        ret, demo1_rsp_msg_head, demo1_rsp_msg_body = self.client.recv(conf.proto_tcp_do_checksum)
        if ret != 0:
            LOG_ERROR('ret: %d' % ret)
            return -1

        if demo1_rsp_msg_head.msg_id != cs_msg_id_pb2.MSG_ID_DEMO1_RSP:
            LOG_ERROR('error rsp msg id: %d' % demo1_rsp_msg_head.msg_id)
            return -1

        demo1_rsp = self.__make_demo1_rsp(demo1_rsp_msg_body)

        err_code = demo1_rsp.err_ctx.err_code
        if err_code != 0:
            LOG_ERROR('failed err code: %d' % err_code)
            return err_code

        # 收Demo1Nfy
        demo1_nfy_msg_head = MsgHead()

        ret, demo1_nfy_msg_head, demo1_nfy_msg_body = self.client.recv(conf.proto_tcp_do_checksum)
        if ret != 0:
            LOG_ERROR('ret: %d' % ret)
            return -1

        if demo1_nfy_msg_head.msg_id != cs_msg_id_pb2.MSG_ID_DEMO1_NFY:
            LOG_ERROR('error rsp msg id: %d' % demo1_nfy_msg_head.msg_id)
            return -1

        demo1_nfy = self.__make_demo1_nfy(demo1_nfy_msg_body)
        if demo1_nfy.a != 1:
            return -1

        return 0
