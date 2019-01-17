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


class EchoReq(object):
    def __init__(self, client):
        self.client = client
        self.echo_msg_id = 1000
        self.echo_req = 'x' * 10240

    def __make_echo_req(self):
        return self.echo_req

    def __make_echo_rsp(self, rsp_msg_body):
        return rsp_msg_body

    def echo(self):
        LOG_DEBUG('----- echo -----')

        msg_head = MsgHead()
        msg_head.msg_id = self.echo_msg_id

        echo_req = self.__make_echo_req()

        ret = self.client.send(msg_head, echo_req, len(echo_req), conf.do_checksum)
        if ret != 0:
            LOG_ERROR('failed to send to server %s' % self.client.server())
            return -1

        ret, rsp_msg_head, rsp_msg_body = self.client.recv(conf.do_checksum)
        if ret != 0:
            LOG_ERROR('ret: %d' % ret)
            return -1

        if rsp_msg_head.msg_id != self.echo_msg_id:
            LOG_ERROR('error rsp msg id: %d' % rsp_msg_head.msg_id)
            return -1

        echo_rsp = self.__make_echo_rsp(rsp_msg_body)
        if echo_rsp != self.echo_req:
            LOG_ERROR('not echo')
            return -1

        return 0
