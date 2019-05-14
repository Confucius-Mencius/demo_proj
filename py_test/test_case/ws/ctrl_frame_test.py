# -*- coding: utf-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import os
import sys
import ssl

sys.path.append('%s/../../../../py_tools' % os.path.split(os.path.realpath(__file__))[0])  # 导入上级目录中的模块
# print(sys.path)

from websocket import create_connection, ABNF, STATUS_NORMAL, \
    STATUS_MESSAGE_TOO_BIG, STATUS_INVALID_EXTENSION, STATUS_TLS_HANDSHAKE_ERROR
from util.log_util import *


def ping(s):
    try:
        if s:
            ws = create_connection('wss://%s:%d/' % (conf.demo_server_addr, conf.demo_server_web_security_port),
                                   header=["Sec-WebSocket-Protocol: xxx"],
                                   cookie='xx',
                                   host='www.qq.com',
                                   sslopt={"cert_reqs": ssl.CERT_NONE})  # disable ssl cert verification
            LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_web_security_port))
        else:
            ws = create_connection('ws://%s:%d/' % (conf.demo_server_addr, conf.demo_server_web_port),
                                   header=["Sec-WebSocket-Protocol: xxx"],
                                   cookie='xx',
                                   host='www.qq.com')
            LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_web_port))

        ws.ping("i am a ping")

        rsp = ws.recv_frame()
        LOG_DEBUG(rsp)

        ws.close()
        ret = 0
    except Exception as e:
        LOG_ERROR('exception: %s' % e)
        ret = -1

    return ret


def test_001():
    assert 0 == ping(False)


def pong(s):
    try:
        if s:
            ws = create_connection('wss://%s:%d/' % (conf.demo_server_addr, conf.demo_server_web_security_port),
                                   header=["Sec-WebSocket-Protocol: xxx"],
                                   cookie='xx',
                                   host='www.qq.com',
                                   sslopt={"cert_reqs": ssl.CERT_NONE})  # disable ssl cert verification
            LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_web_security_port))
        else:
            ws = create_connection('ws://%s:%d/' % (conf.demo_server_addr, conf.demo_server_web_port),
                                   header=["Sec-WebSocket-Protocol: xxx"],
                                   cookie='xx',
                                   host='www.qq.com')
            LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_web_port))

        ws.pong("i am a pong")

        # rsp = ws.recv_frame()
        # LOG_DEBUG(rsp)

        ws.close()
        ret = 0
    except Exception as e:
        LOG_ERROR('exception: %s' % e)
        ret = -1

    return ret


def test_002():
    assert 0 == pong(False)


def close(s, close_code):
    try:
        if s:
            ws = create_connection('wss://%s:%d/' % (conf.demo_server_addr, conf.demo_server_web_security_port),
                                   header=["Sec-WebSocket-Protocol: xxx"],
                                   cookie='xx',
                                   host='www.qq.com',
                                   sslopt={"cert_reqs": ssl.CERT_NONE})  # disable ssl cert verification
            LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_web_security_port))
        else:
            ws = create_connection('ws://%s:%d/' % (conf.demo_server_addr, conf.demo_server_web_port),
                                   header=["Sec-WebSocket-Protocol: xxx"],
                                   cookie='xx',
                                   host='www.qq.com')
            LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_web_port))

        ws.send_close(close_code)
        ret = 0

        # ret = ws.recv()
        # print(ret)
    except Exception as e:
        LOG_ERROR('exception: %s' % e)
        ret = -1

    return ret


def test_003():
    assert 0 == close(False, STATUS_NORMAL)
    assert 0 == close(False, STATUS_MESSAGE_TOO_BIG)
    assert 0 == close(False, STATUS_INVALID_EXTENSION)
    assert 0 == close(False, STATUS_TLS_HANDSHAKE_ERROR)


if __name__ == '__main__':
    test_001()
    test_002()
    test_003()
