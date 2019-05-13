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


class Demo300Req(object):
    def __init__(self, client):
        self.client = client

    def __make_demo300_req(self):
        demo300_req = cs_msg_pb2.Demo300Req()
        demo300_req.a = 300

        LOG_DEBUG('%s%s' % (os.linesep, demo300_req))
        return demo300_req

    def __make_demo300_rsp(self, rsp_msg_body):
        demo300_rsp = cs_msg_pb2.Demo300Rsp()
        demo300_rsp.ParseFromString(rsp_msg_body)

        LOG_DEBUG('%s%s' % (os.linesep, demo300_rsp))
        return demo300_rsp

    def demo300(self):
        LOG_DEBUG('----- demo300_req -----')

        demo300_req_msg_head = MsgHead()
        demo300_req_msg_head.msg_id = cs_msg_id_pb2.MSG_ID_DEMO300_REQ

        demo300_req = self.__make_demo300_req()

        ret = self.client.send(demo300_req_msg_head, demo300_req.SerializeToString(), demo300_req.ByteSize(), conf.proto_tcp_do_checksum)
        if ret != 0:
            LOG_ERROR('failed to send to server %s' % self.client.server())
            return -1

        # 收3个回复
        for i in range(0, 3):
            demo300_rsp_msg_head = MsgHead()

            ret, demo300_rsp_msg_head, demo300_rsp_msg_body = self.client.recv(conf.proto_tcp_do_checksum)
            if ret != 0:
                LOG_ERROR('ret: %d' % ret)
                return -1

            if demo300_rsp_msg_head.msg_id != cs_msg_id_pb2.MSG_ID_DEMO300_RSP:
                LOG_ERROR('error rsp msg id: %d' % demo300_rsp_msg_head.msg_id)
                return -1

            demo300_rsp = self.__make_demo300_rsp(demo300_rsp_msg_body)

            err_code = demo300_rsp.err_ctx.err_code
            if err_code != 0:
                LOG_ERROR('failed err code: %d' % err_code)
                return err_code

        return 0
