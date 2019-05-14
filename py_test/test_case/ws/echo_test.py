# -*- coding: utf-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import os
import sys
import ssl

sys.path.append('%s/../../../../py_tools' % os.path.split(os.path.realpath(__file__))[0])  # 导入上级目录中的模块
# print(sys.path)

from websocket import create_connection, ABNF
from util.log_util import *


# 发送小于16k的数据
def send_to_server1(s):
    try:
        if s:
            ws = create_connection('wss://%s:%d/' % (conf.demo_server_addr, conf.demo_server_web_security_port),
                                   timeout=60,
                                   header=["Sec-WebSocket-Protocol: xxx"],
                                   cookie='xx',
                                   host='www.qq.com',
                                   sslopt={"cert_reqs": ssl.CERT_NONE})  # disable ssl cert verification
            LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_web_security_port))
        else:
            ws = create_connection('ws://%s:%d/' % (conf.demo_server_addr, conf.demo_server_web_port),
                                   timeout=60,
                                   header=["Sec-WebSocket-Protocol: xxx"],
                                   cookie='xx',
                                   host='www.qq.com')
            LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_web_port))

        data = 'Hello, World'
        ws.send(data)

        rsp = ws.recv()
        LOG_DEBUG(rsp)

        assert rsp == data

        ws.close()
        ret = 0
    except Exception as e:
        LOG_ERROR('exception: %s' % e)
        ret = -1

    return ret


def test_001():
    assert 0 == send_to_server1(False)
    # assert 0 == send_to_server1(True)


# 发送大于16k的数据
def send_to_server2(s):
    try:
        if s:
            ws = create_connection('wss://%s:%d/' % (conf.demo_server_addr, conf.demo_server_web_security_port),
                                   timeout=60,
                                   header=["Sec-WebSocket-Protocol: xxx"],
                                   cookie='xx',
                                   host='www.qq.com',
                                   sslopt={"cert_reqs": ssl.CERT_NONE})  # disable ssl cert verification
            LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_web_security_port))
        else:
            ws = create_connection('ws://%s:%d/' % (conf.demo_server_addr, conf.demo_server_web_port),
                                   timeout=60,
                                   header=["Sec-WebSocket-Protocol: xxx"],
                                   cookie='xx',
                                   host='www.qq.com')
            LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_web_port))

        data = 'x' * 16 * 1024 + 'y'
        ws.send(data)

        rsp = ws.recv()
        LOG_DEBUG(rsp)
        assert rsp == data

        ws.close()
        ret = 0
    except Exception as e:
        LOG_ERROR('exception: %s' % e)
        ret = -1

    return ret


def test_002():
    assert 0 == send_to_server2(False)
    # assert 0 == send_to_server2(True)


# 分帧发送text frames
def send_to_server3(s):
    try:
        if s:
            ws = create_connection('wss://%s:%d/' % (conf.demo_server_addr, conf.demo_server_web_security_port),
                                   timeout=60,
                                   header=["Sec-WebSocket-Protocol: xxx"],
                                   cookie='xx',
                                   host='www.qq.com',
                                   sslopt={"cert_reqs": ssl.CERT_NONE})  # disable ssl cert verification
            LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_web_security_port))
        else:
            ws = create_connection('ws://%s:%d/' % (conf.demo_server_addr, conf.demo_server_web_port),
                                   timeout=60,
                                   header=["Sec-WebSocket-Protocol: xxx"],
                                   cookie='xx',
                                   host='www.qq.com')
            LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_web_port))

        frame = ABNF.create_frame("Hello, ", ABNF.OPCODE_TEXT, 0)
        ws.send_frame(frame)
        cont_frame = ABNF.create_frame("My name is ", ABNF.OPCODE_CONT, 0)
        ws.send_frame(cont_frame)
        cont_frame = ABNF.create_frame("Foo Bar", ABNF.OPCODE_CONT, 1)
        ws.send_frame(cont_frame)

        rsp = ws.recv()
        LOG_DEBUG(rsp)
        assert rsp == 'Hello, My name is Foo Bar'

        ws.close()
        ret = 0
    except Exception as e:
        LOG_ERROR('exception: %s' % e)
        ret = -1

    return ret


def test_003():
    assert 0 == send_to_server3(False)
    # assert 0 == send_to_server3(True)


# 分帧发送binary frames
def send_to_server4(s):
    try:
        if s:
            ws = create_connection('wss://%s:%d/' % (conf.demo_server_addr, conf.demo_server_web_security_port),
                                   timeout=60,
                                   header=["Sec-WebSocket-Protocol: xxx"],
                                   cookie='xx',
                                   host='www.qq.com',
                                   sslopt={"cert_reqs": ssl.CERT_NONE})  # disable ssl cert verification
            LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_web_security_port))
        else:
            ws = create_connection('ws://%s:%d/' % (conf.demo_server_addr, conf.demo_server_web_port),
                                   timeout=60,
                                   header=["Sec-WebSocket-Protocol: xxx"],
                                   cookie='xx',
                                   host='www.qq.com')
            LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_web_port))

        frame = ABNF.create_frame("Hello, ", ABNF.OPCODE_BINARY, 0)
        ws.send_frame(frame)
        cont_frame = ABNF.create_frame("My name is ", ABNF.OPCODE_CONT, 0)
        ws.send_frame(cont_frame)
        cont_frame = ABNF.create_frame("Foo Bar", ABNF.OPCODE_CONT, 1)
        ws.send_frame(cont_frame)

        rsp = ws.recv()
        LOG_DEBUG(rsp)
        assert rsp == 'Hello, My name is Foo Bar'

        ws.close()
        ret = 0
    except Exception as e:
        LOG_ERROR('exception: %s' % e)
        ret = -1

    return ret


def test_004():
    assert 0 == send_to_server4(False)
    # assert 0 == send_to_server4(True)


if __name__ == '__main__':
    test_001()
    test_002()
    test_003()
    test_004()
