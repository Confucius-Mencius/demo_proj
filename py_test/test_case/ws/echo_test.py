# -*- coding: utf-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import os
import sys

sys.path.append('%s/../../../../py_tools' % os.path.split(os.path.realpath(__file__))[0])  # 导入上级目录中的模块
# print(sys.path)

from websocket import create_connection
from util.log_util import *


# 发送小于16k的数据
def send_to_server1():
    try:
        ws = create_connection('ws://%s:%d/' % (conf.demo_server_addr, conf.demo_server_ws_port))
        LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_ws_port))

        ws.send('Hello, World')
        rsp = ws.recv()
        print(rsp)
        assert rsp == 'Hello, World'
        ws.close()

        ret = 0
    except Exception as e:
        LOG_ERROR('exception: %s' % e)
        ret = -1

    return ret


def test001():
    assert send_to_server1() == 0


# 发送大于16k的数据
# def send_to_server2():
#     sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#
#     try:
#         sock.connect((conf.demo_server_addr, conf.demo_server_tcp_port))
#         LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_tcp_port))
#
#         data = 'x' * 16 * 1024 + 'y'
#         sock.send(data)
#
#         want_recv_len = len(data)
#         recv_len = 0
#
#         while recv_len < want_recv_len:
#             rsp = sock.recv(want_recv_len)
#             if not rsp:
#                 break
#
#             print(len(rsp))
#             recv_len += len(rsp)
#
#         assert recv_len == len(data)
#         ret = 0
#     except socket.error as e:
#         LOG_ERROR('exception: %s' % e)
#         ret = -1
#
#     sock.close()
#     return ret
#
#
# def test002():
#     assert send_to_server2() == 0


if __name__ == '__main__':
    test001()
    # test002()
