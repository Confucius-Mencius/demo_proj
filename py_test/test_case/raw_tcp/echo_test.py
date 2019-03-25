# -*- coding: utf-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import os
import sys

sys.path.append('%s/../../../../py_tools' % os.path.split(os.path.realpath(__file__))[0])  # 导入上级目录中的模块
# print(sys.path)

import socket
import struct
from util.log_util import *


# 发送小于16k的数据
def send_to_server1():
    try:
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

        sock.connect((conf.demo_server_addr, conf.demo_server_raw_tcp_port))
        LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_raw_tcp_port))

        sock.send(struct.pack('!iIii', 1, 2, 3, 4))

        rsp = sock.recv(conf.max_tcp_msg_len)
        assert len(rsp) == 16

        (a, b, c, d) = struct.unpack('!iIii', rsp)
        assert (a == 1 and b == 2 and c == 3 and d == 4)

        # 服务器主动关闭，rsp为""
        # rsp = sock.recv(conf.max_raw_tcp_msg_len)
        # if not rsp:
        #     print('none rsp')
        # else:
        #     print(len(rsp))

        sock.close()
        ret = 0
    except socket.error as e:
        LOG_ERROR('exception: %s' % e)
        ret = -1

    return ret


def test001():
    assert send_to_server1() == 0


# 发送大于16k的数据
def send_to_server2():
    try:
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

        sock.connect((conf.demo_server_addr, conf.demo_server_raw_tcp_port))
        LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_raw_tcp_port))

        data = 'x' * 16 * 1024 + 'y'
        sock.send(data)

        want_recv_len = len(data)
        recv_len = 0
        recv_data = ''

        while recv_len < want_recv_len:
            rsp = sock.recv(want_recv_len)
            if not rsp:
                break

            LOG_DEBUG(len(rsp))
            recv_len += len(rsp)
            recv_data += rsp

        assert recv_len == len(data)
        assert recv_data == data

        sock.close()
        ret = 0
    except socket.error as e:
        LOG_ERROR('exception: %s' % e)
        ret = -1

    return ret


def test002():
    assert send_to_server2() == 0


if __name__ == '__main__':
    test001()
    test002()
