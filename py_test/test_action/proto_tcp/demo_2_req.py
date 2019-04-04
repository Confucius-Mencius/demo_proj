# -*- coding: utf-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import os
import sys

sys.path.append('%s/../../../../py_tools' % os.path.split(os.path.realpath(__file__))[0])  # 导入上级目录中的模块
# print(sys.path)

from base.msg_codec import *

from util.log_util import *
import conf
from data.err_code import *

from com.moon.demo.proto.cs import cs_msg_id_pb2
from com.moon.demo.proto.cs import cs_msg_pb2


class Demo2Req(object):
    def __init__(self, client):
        self.client = client

    def __make_demo_2_req(self):
        demo_2_req = cs_msg_pb2.Demo2Req()
        demo_2_req.a = 300

        LOG_DEBUG('%s%s' % (os.linesep, demo_2_req))
        return demo_2_req

    def __make_demo_2_rsp(self, rsp_msg_body):
        demo_2_rsp = cs_msg_pb2.Demo2Rsp()
        demo_2_rsp.ParseFromString(rsp_msg_body)

        LOG_DEBUG('%s%s' % (os.linesep, demo_2_rsp))
        return demo_2_rsp

    def demo_2(self):
        LOG_DEBUG('----- demo_2_req -----')

        msg_head = MsgHead()
        msg_head.msg_id = cs_msg_id_pb2.MSG_ID_DEMO_2_REQ

        demo_2_req = self.__make_demo_2_req()

        ret = self.client.send(msg_head, demo_2_req.SerializeToString(), demo_2_req.ByteSize(), conf.do_checksum)
        if ret != 0:
            LOG_ERROR('failed to send to server %s' % self.client.server())
            return -1

        rsp_msg_head = MsgHead()

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

        return 0

    # 构造非法消息，使得服务器解包失败
    def demo_2_bad(self):
        LOG_DEBUG('----- demo2 bad req -----')

        msg_head = MsgHead()
        msg_head.msg_id = cs_msg_id_pb2.MSG_ID_DEMO_2_REQ

        msg_body = 'abc'
        msg_body_len = 3

        ret = self.client.send(msg_head, msg_body, msg_body_len, conf.do_checksum)
        if ret != 0:
            LOG_ERROR('failed to send to server %s' % self.client.server())
            return -1

        rsp_msg_head = MsgHead()

        ret, rsp_msg_head, rsp_msg_body = self.client.recv(conf.do_checksum)
        if ret != 0:
            LOG_ERROR('ret: %d' % ret)
            return -1

        if rsp_msg_head.msg_id != cs_msg_id_pb2.MSG_ID_DEMO_2_RSP:
            LOG_ERROR('error rsp msg id: %d' % rsp_msg_head.msg_id)
            return -1

        demo_2_rsp = self.__make_demo_2_rsp(rsp_msg_body)

        err_code = demo_2_rsp.err_ctx.err_code
        if err_code != ERR_INVALID_PARAM:
            LOG_ERROR('demo_2_rsp failed err code: %d' % err_code)
            return err_code

        return 0
