# -*- coding: utf-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import os
import sys

sys.path.append('%s/../../../../py_tools' % os.path.split(os.path.realpath(__file__))[0])
# print(sys.path)

from util.proto_tcp_client import *
from test_action.proto_tcp.demo200_req import *


def test_001():
    client = Client(conf.demo_server_addr, conf.demo_server_proto_tcp_port)
    demo200_req = Demo200Req(client)
    ret = demo200_req.demo200()
    assert ret == 0


if __name__ == '__main__':
    test_001()
