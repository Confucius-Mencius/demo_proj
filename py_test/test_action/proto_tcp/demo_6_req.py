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


class Demo6Req(object):
    def __init__(self, client):
        self.client = client

    def __make_demo_6_req(self):
        demo_6_req = cs_msg_pb2.Demo6Req()
        demo_6_req.a = 600

        LOG_DEBUG('%s%s' % (os.linesep, demo_6_req))
        return demo_6_req

    def __make_demo_6_rsp(self, rsp_msg_body):
        demo_6_rsp = cs_msg_pb2.Demo6Rsp()
        demo_6_rsp.ParseFromString(rsp_msg_body)

        LOG_DEBUG('%s%s' % (os.linesep, demo_6_rsp))
        return demo_6_rsp

    def demo_6(self):
        LOG_DEBUG('----- demo_6_req -----')

        msg_head = MsgHead()
        msg_head.msg_id = cs_msg_id_pb2.MSG_ID_DEMO_6_REQ

        demo_6_req = self.__make_demo_6_req()

        ret = self.client.send(msg_head, demo_6_req.SerializeToString(), demo_6_req.ByteSize(), conf.do_checksum)
        if ret != 0:
            LOG_ERROR('failed to send to server %s' % self.client.server())
            return -1

        rsp_msg_head = MsgHead()

        ret, rsp_msg_head, rsp_msg_body = self.client.recv(conf.do_checksum)
        if ret != 0:
            LOG_ERROR('ret: %d' % ret)
            return -1

        if rsp_msg_head.msg_id != cs_msg_id_pb2.MSG_ID_DEMO_6_RSP:
            LOG_ERROR('error rsp msg id: %d' % rsp_msg_head.msg_id)
            return -1

        demo_6_rsp = self.__make_demo_6_rsp(rsp_msg_body)

        err_code = demo_6_rsp.err_ctx.err_code
        if err_code != 0:
            LOG_ERROR('demo_6_rsp failed err code: %d' % err_code)
            return err_code

        return 0
