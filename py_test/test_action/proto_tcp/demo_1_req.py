# -*- coding: utf-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import os
import sys

sys.path.append('%s/../../../../py_tools' % os.path.split(os.path.realpath(__file__))[0])  # 导入上级目录中的模块
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
        demo1_req.a = 300

        LOG_DEBUG('%s%s' % (os.linesep, demo1_req))
        return demo1_req

    def __make_demo1_rsp(self, rsp_msg_body):
        demo1_rsp = cs_msg_pb2.Demo1Rsp()
        demo1_rsp.ParseFromString(rsp_msg_body)

        LOG_DEBUG('%s%s' % (os.linesep, demo1_rsp))
        return demo1_rsp

    def __make_demo_2_rsp(self, rsp_msg_body):
        demo_2_rsp = cs_msg_pb2.Demo2Rsp()
        demo_2_rsp.ParseFromString(rsp_msg_body)

        LOG_DEBUG('%s%s' % (os.linesep, demo_2_rsp))
        return demo_2_rsp

    def demo1(self):
        LOG_DEBUG('----- demo1_req -----')

        msg_head = MsgHead()
        msg_head.msg_id = cs_msg_id_pb2.MSG_ID_DEMO_1_REQ

        demo_1_req = self.__make_demo_1_req()

        ret = self.client.send(msg_head, demo_1_req.SerializeToString(), demo_1_req.ByteSize(), conf.proto_tcp_do_checksum)
        if ret != 0:
            LOG_ERROR('failed to send to server %s' % self.client.server())
            return -1

        # 回复3个消息
        rsp_msg_head = MsgHead()

        # 1. MSG_ID_DEMO_1_RSP
        ret, rsp_msg_head, rsp_msg_body = self.client.recv(conf.do_checksum)
        if ret != 0:
            LOG_ERROR('ret: %d' % ret)
            return -1

        if rsp_msg_head.msg_id != cs_msg_id_pb2.MSG_ID_DEMO_1_RSP:
            LOG_ERROR('error rsp msg id: %d' % rsp_msg_head.msg_id)
            return -1

        demo_1_rsp = self.__make_demo_1_rsp(rsp_msg_body)

        err_code = demo_1_rsp.err_ctx.err_code
        if err_code != 0:
            LOG_ERROR('demo_1_rsp failed err code: %d' % err_code)
            return err_code

        # 2. MSG_ID_DEMO_2_RSP
        ret, rsp_msg_head, rsp_msg_body = self.client.recv(conf.do_checksum)
        if ret != 0:
            LOG_ERROR('ret: %d' % ret)
            return -1

        if rsp_msg_head.msg_id != cs_msg_id_pb2.MSG_ID_DEMO_2_RSP:
            LOG_ERROR('error rsp msg id: %d' % rsp_msg_head.msg_id)
            return -1

        demo_2_rsp = self.__make_demo_2_rsp(rsp_msg_body)

        err_code = demo_2_rsp.err_ctx.err_code
        if err_code != 0:
            LOG_ERROR('demo_2_rsp failed err code: %d' % err_code)
            return err_code

        # 3. MSG_ID_DEMO_1_RSP
        ret, rsp_msg_head, rsp_msg_body = self.client.recv(conf.do_checksum)
        if ret != 0:
            LOG_ERROR('ret: %d' % ret)
            return -1

        if rsp_msg_head.msg_id != cs_msg_id_pb2.MSG_ID_DEMO_1_RSP:
            LOG_ERROR('error rsp msg id: %d' % rsp_msg_head.msg_id)
            return -1

        demo_1_rsp = self.__make_demo_1_rsp(rsp_msg_body)

        err_code = demo_1_rsp.err_ctx.err_code
        if err_code != 0:
            LOG_ERROR('demo_1_rsp failed err code: %d' % err_code)
            return err_code

        return 0
