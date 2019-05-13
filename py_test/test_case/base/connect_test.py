# -*- coding: utf-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import os
import sys

sys.path.append('%s/../../../../py_tools' % os.path.split(os.path.realpath(__file__))[0])  # 导入上级目录中的模块
# print(sys.path)

from base.multitask_util import *

import socket
import struct
from util.log_util import *


def proc1():
    try:
        l_onoff = 1
        l_linger = 0

        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

        # 设置为linger时，close的时候服务器"Connection reset by peer"的ERROR日志
        sock.setsockopt(socket.SOL_SOCKET, socket.SO_LINGER, struct.pack('ii', l_onoff, l_linger))

        sock.connect((conf.demo_server_addr, conf.demo_server_tcp_port))
        LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_tcp_port))
    except socket.error as arg:
        LOG_ERROR('failed to connect server: %s' % arg)
        assert False


def test_001():
    run_multi_process(200, proc1)


if __name__ == '__main__':
    test_001()
