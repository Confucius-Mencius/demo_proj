# -*- coding: utf-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import os
import sys

sys.path.append('%s/../../../../py_tools' % os.path.split(os.path.realpath(__file__))[0])  # 导入上级目录中的模块
# print(sys.path)

from util.proto_tcp_client import *
from test_action.proto_tcp.demo_1_req import *


def test001():
    client = Client(conf.demo_server_addr, conf.demo_server_proto_tcp_port)
    demo_1_req = Demo1Req(client)
    ret = demo_1_req.demo_1()
    assert ret == 0


if __name__ == '__main__':
    test001()
