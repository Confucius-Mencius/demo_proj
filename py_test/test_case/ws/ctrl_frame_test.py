# -*- coding: utf-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import os
import sys
import ssl

sys.path.append('%s/../../../../py_tools' % os.path.split(os.path.realpath(__file__))[0])  # 导入上级目录中的模块
# print(sys.path)

from websocket import create_connection
from util.log_util import *


def ping(s):
    try:
        if s:
            ws = create_connection('wss://%s:%d/' % (conf.demo_server_addr, conf.demo_server_https_wss_port),
                                   header=["Sec-WebSocket-Protocol: xxx"],
                                   cookie='xx',
                                   host='www.qq.com',
                                   sslopt={"cert_reqs": ssl.CERT_NONE})  # disable ssl cert verification
            LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_https_wss_port))
        else:
            ws = create_connection('ws://%s:%d/' % (conf.demo_server_addr, conf.demo_server_http_ws_port),
                                   header=["Sec-WebSocket-Protocol: lws-minimal"],
                                   cookie='xx',
                                   host='www.qq.com')
            LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_http_ws_port))

        ws.ping("i am a ping")

        rsp = ws.recv_frame()
        LOG_DEBUG(rsp)

        ws.close()
        ret = 0
    except Exception as e:
        LOG_ERROR('exception: %s' % e)
        ret = -1

    return ret


def test001():
    assert ping(False) == 0


def pong(s):
    try:
        if s:
            ws = create_connection('wss://%s:%d/' % (conf.demo_server_addr, conf.demo_server_https_wss_port),
                                   header=["Sec-WebSocket-Protocol: xxx"],
                                   cookie='xx',
                                   host='www.qq.com',
                                   sslopt={"cert_reqs": ssl.CERT_NONE})  # disable ssl cert verification
            LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_https_wss_port))
        else:
            ws = create_connection('ws://%s:%d/' % (conf.demo_server_addr, conf.demo_server_http_ws_port),
                                   header=["Sec-WebSocket-Protocol: lws-minimal"],
                                   cookie='xx',
                                   host='www.qq.com')
            LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_http_ws_port))

        ws.pong("i am a pong")

        rsp = ws.recv_frame()
        LOG_DEBUG(rsp)

        ws.close()
        ret = 0
    except Exception as e:
        LOG_ERROR('exception: %s' % e)
        ret = -1

    return ret


def test002():
    assert pong(False) == 0


def close(s):
    try:
        if s:
            ws = create_connection('wss://%s:%d/' % (conf.demo_server_addr, conf.demo_server_https_wss_port),
                                   header=["Sec-WebSocket-Protocol: xxx"],
                                   cookie='xx',
                                   host='www.qq.com',
                                   sslopt={"cert_reqs": ssl.CERT_NONE})  # disable ssl cert verification
            LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_https_wss_port))
        else:
            ws = create_connection('ws://%s:%d/' % (conf.demo_server_addr, conf.demo_server_http_ws_port),
                                   header=["Sec-WebSocket-Protocol: lws-minimal"],
                                   cookie='xx',
                                   host='www.qq.com')
            LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_http_ws_port))

        ws.send_close()

        rsp = ws.recv_frame()
        LOG_DEBUG(rsp)
        # assert rsp == data

        ret = ws.recv()
        print(ret)
    except Exception as e:
        LOG_ERROR('exception: %s' % e)
        ret = -1

    return ret


def test003():
    assert close(False) == 0


if __name__ == '__main__':
    test001()
    # test002()
    # test003()
