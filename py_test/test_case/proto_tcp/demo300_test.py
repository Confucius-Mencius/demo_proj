# -*- coding: utf-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import os
import sys

sys.path.append('%s/../../../../py_tools' % os.path.split(os.path.realpath(__file__))[0])
# print(sys.path)

from util.proto_tcp_client import *
from test_action.proto_tcp.demo300_req import *


def test_001():
    client = Client(conf.demo_server_addr, conf.demo_server_proto_tcp_port)
    demo300_req = Demo300Req(client)
    ret = demo300_req.demo300()
    assert ret == 0


if __name__ == '__main__':
    test_001()
