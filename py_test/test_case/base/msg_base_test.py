# -*- coding: utf-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import os
import sys

sys.path.append('%s/../../../../py_tools' % os.path.split(os.path.realpath(__file__))[0])  # 导入上级目录中的模块
# print(sys.path)

from base.msg_codec import MIN_TOTAL_MSG_LEN

import socket
import struct
from util.log_util import *


def send_multi_time(msg_id):
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    ret = 0

    try:
        sock.connect((conf.demo_server_addr, conf.demo_server_tcp_port))
        LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_tcp_port))

        sock.send(struct.pack('!i', MIN_TOTAL_MSG_LEN))  # msg_len
        sock.send(struct.pack('!I', 0))  # checksum，假的
        sock.send(struct.pack('!i', 0))  # passback
        sock.send(struct.pack('!i', msg_id))  # msg_id

        rsp = sock.recv(conf.max_tcp_msg_len)

        if rsp and (4 + MIN_TOTAL_MSG_LEN) == len(rsp):
            rsp_total_msg_len, = struct.unpack('!i', rsp[0:4])
            checksum_peer, = struct.unpack('!I', rsp[4:8])
            rsp_passback, = struct.unpack('!i', rsp[8:12])
            rsp_msg_id, = struct.unpack('!i', rsp[12:16])

            LOG_DEBUG('rsp_total_msg_len: %d, peer checksum: %u, rsp_passback: %d, '
                      'rsp_msg_id: %d' % (rsp_total_msg_len, checksum_peer, rsp_passback, rsp_msg_id))

            # server配置为校验checksum时返回-105，不校验checksum时msg_id返回-106
            if conf.do_checksum:
                assert rsp_msg_id == -105
            else:
                assert rsp_msg_id == -106
        else:
            assert False
    except socket.error as e:
        LOG_ERROR('exception: %s' % e)
        ret = -1

    sock.close()
    return ret


def test001():
    assert send_multi_time(0) == 0


def send_once(msg_id):
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    ret = 0

    try:
        sock.connect((conf.demo_server_addr, conf.demo_server_tcp_port))
        LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_tcp_port))

        sock.send(struct.pack('!iIii', MIN_TOTAL_MSG_LEN, 0, 0, msg_id))

        rsp = sock.recv(conf.max_tcp_msg_len)

        if rsp and (4 + MIN_TOTAL_MSG_LEN) == len(rsp):
            rsp_total_msg_len, = struct.unpack('!i', rsp[0:4])
            checksum_peer, = struct.unpack('!I', rsp[4:8])
            rsp_passback, = struct.unpack('!i', rsp[8:12])
            rsp_msg_id, = struct.unpack('!i', rsp[12:16])

            LOG_DEBUG('rsp_total_msg_len: %d, peer checksum: %u, rsp_passback: %d, '
                      'rsp_msg_id: %d' % (rsp_total_msg_len, checksum_peer, rsp_passback, rsp_msg_id))

            if conf.do_checksum:
                assert rsp_msg_id == -105
            else:
                assert rsp_msg_id == -106
        else:
            assert False
    except socket.error as e:
        LOG_ERROR('exception: %s' % e)
        ret = -1

    sock.close()
    return ret


def test002():
    assert send_once(0) == 0


# 消息体有2个字节,只发送1个字节。该测试会等待服务器60秒超时，先注释掉
# def test003():
#     sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#     ret = 0
#
#     try:
#         sock.connect((conf.demo_server_addr, conf.demo_server_tcp_port))
#         LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_tcp_port))
#
#         msg_id = 0
#         sock.send(struct.pack('!iIii', MIN_TOTAL_MSG_LEN + 2, 0, 0, msg_id))
#         sock.send('a')
#
#         rsp = sock.recv(conf.max_tcp_msg_len)  # part msg服务器会等待60秒，然后将连接关掉
#         assert 0 == len(rsp)
#     except socket.error as e:
#         LOG_ERROR('exception: %s' % e)
#         ret = -1
#
#     sock.close()
#     return ret


if __name__ == '__main__':
    test001()
    test002()
