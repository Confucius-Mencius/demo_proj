# -*- coding: utf-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import os
import sys

sys.path.append('%s/../../../../py_tools' % os.path.split(os.path.realpath(__file__))[0])  # 导入上级目录中的模块
# print(sys.path)

from base.multitask_util import *
from util.proto_tcp_client import *
from test_action.proto_tcp.demo100_req import *
from test_action.proto_tcp.demo200_req import *
from test_action.proto_tcp.demo1_req import *


def proc1():
    client = Client(conf.demo_server_addr, conf.demo_server_proto_tcp_port)
    demo100_req = Demo100Req(client)
    ret = demo100_req.demo100()
    assert ret == 0

    client = Client(conf.demo_server_addr, conf.demo_server_proto_tcp_port)
    demo200_req = Demo200Req(client)
    ret = demo200_req.demo200()
    assert ret == 0

    client = Client(conf.demo_server_addr, conf.demo_server_proto_tcp_port)
    demo1_req = Demo1Req(client)
    ret = demo1_req.demo1()
    assert ret == 0


def test001():
    run_multi_process(200, proc1)


if __name__ == '__main__':
    test001()
