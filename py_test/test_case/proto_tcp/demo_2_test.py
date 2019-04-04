# -*- coding: utf-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import os
import sys

sys.path.append('%s/../../../../py_tools' % os.path.split(os.path.realpath(__file__))[0])  # 导入上级目录中的模块
# print(sys.path)

from base.tcp_client import *

from test_action.tcp.demo_2_req import *


def test001():
    client = TcpClient(conf.demo_server_addr, conf.demo_server_tcp_port)
    demo_2_req = Demo2Req(client)
    ret = demo_2_req.demo_2()
    assert ret == 0


def test002():
    client = TcpClient(conf.demo_server_addr, conf.demo_server_tcp_port)
    demo_2_action = Demo2Req(client)
    ret = demo_2_action.demo_2_bad()
    assert ret == 0


if __name__ == '__main__':
    test001()
    # test002()
