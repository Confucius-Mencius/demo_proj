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


def send_to_server():
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    ret = 0

    try:
        sock.connect((conf.demo_server_addr, conf.demo_server_raw_tcp_port))
        LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_raw_tcp_port))

        sock.send(struct.pack('!iIii', 1, 2, 3, 4))

        rsp = sock.recv(conf.max_raw_tcp_msg_len)
        assert len(rsp) == 16

        (a, b, c, d) = struct.unpack('!iIii', rsp)
        assert (a == 1 and b == 2 and c == 3 and d == 4)

        # 服务器主动关闭，rsp为""
        # rsp = sock.recv(conf.max_raw_tcp_msg_len)
        # if not rsp:
        #     print('none rsp')
        # else:
        #     print(len(rsp))

        ret = 0
    except socket.error as e:
        LOG_ERROR('exception: %s' % e)
        ret = -1

    sock.close()
    return ret


# 发送小于512k的数据
def test001():
    assert send_to_server() == 0


# 发送大于512k的数据
def test002():
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    ret = 0

    try:
        sock.connect((conf.demo_server_addr, conf.demo_server_raw_tcp_port))
        LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_raw_tcp_port))

        data = 'x' * 512 * 1024 + 'y'
        sock.send(data)

        want_recv_len = len(data)
        recved_len = 0

        while recved_len < want_recv_len:
            rsp = sock.recv(want_recv_len)
            if not rsp:
                break

            print(len(rsp))
            recved_len += len(rsp)

        ret = 0
    except socket.error as e:
        LOG_ERROR('exception: %s' % e)
        ret = -1

    sock.close()
    assert ret == 0


if __name__ == '__main__':
    # test001()
    test002()
