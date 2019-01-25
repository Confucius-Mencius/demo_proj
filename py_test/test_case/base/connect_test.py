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


def Proc1():
    l_onoff = 1
    l_linger = 0

    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # 设置为linger时，close的时候服务器"Connection reset by peer"的ERROR日志
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_LINGER, struct.pack('ii', l_onoff, l_linger))

    try:
        sock.connect((conf.demo_server_addr, conf.demo_server_tcp_port))
        LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_tcp_port))
    except socket.error as arg:
        LOG_ERROR('failed to connect server: %s' % arg)
        assert False


def Test001():
    run_multi_process(100, Proc1)


def Test002():
    l_onoff = 1
    l_linger = 0

    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # 设置为linger时，close的时候服务器"Connection reset by peer"的ERROR日志
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_LINGER, struct.pack('ii', l_onoff, l_linger))

    try:
        sock.connect((conf.demo_server_addr, conf.demo_server_tcp_port))
        LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_tcp_port))

        sock.send(struct.pack('!iIii', 1, 2, 3, 4))
        rsp = sock.recv(1024)
    except socket.error as arg:
        LOG_ERROR('failed to connect server: %s' % arg)
        assert False


if __name__ == '__main__':
    Test001()
