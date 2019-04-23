# -*- coding: utf-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import os
import sys

sys.path.append('%s/../../../../py_tools' % os.path.split(os.path.realpath(__file__))[0])
# print(sys.path)

from util.proto_tcp_client import *
from test_action.proto_tcp.demo100_req import *


def demo1100():
    try:
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

        sock.connect((conf.demo_server_addr, conf.demo_server_raw_tcp_port))
        LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_raw_tcp_port))

        sock.send('req1100')

        rsp = sock.recv(7)
        if len(rsp) != 0:
            LOG_ERROR('rsp: %s' % rsp)
            return -1

        ret = 0
    except socket.error as e:
        LOG_ERROR('exception: %s' % e)
        ret = -1

    return ret


def test_001():
    assert 0 == demo1100()


if __name__ == '__main__':
    test_001()
