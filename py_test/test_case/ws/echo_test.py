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


# 发送小于16k的数据
def send_to_server1(s=False):
    try:
        if s:
            ws = create_connection('wss://%s:%d/' % (conf.demo_server_addr, conf.demo_server_wss_port),
                                   sslopt={"cert_reqs": ssl.CERT_NONE}) # disable ssl cert verification
            LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_wss_port))
        else:
            ws = create_connection('ws://%s:%d/' % (conf.demo_server_addr, conf.demo_server_ws_port))
            LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_ws_port))

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


def test001():
    assert send_to_server1() == 0
    assert send_to_server1(True) == 0


# 发送大于16k的数据
def send_to_server2(s=False):
    try:
        if s:
            ws = create_connection('wss://%s:%d/' % (conf.demo_server_addr, conf.demo_server_wss_port),
                                   sslopt={"cert_reqs": ssl.CERT_NONE})  # disable ssl cert verification
            LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_wss_port))
        else:
            ws = create_connection('ws://%s:%d/' % (conf.demo_server_addr, conf.demo_server_ws_port))
            LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_ws_port))

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


def test002():
    assert send_to_server2() == 0
    assert send_to_server2(True) == 0


if __name__ == '__main__':
    test001()
    test002()
