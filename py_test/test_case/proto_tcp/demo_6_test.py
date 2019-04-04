# -*- coding: utf-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import os
import sys

sys.path.append('%s/../../../../py_tools' % os.path.split(os.path.realpath(__file__))[0])  # 导入上级目录中的模块
# print(sys.path)

from base.tcp_client import *

from test_action.tcp.demo_6_req import *


def test001():
    client = TcpClient(conf.demo_server_addr, conf.demo_server_tcp_port)
    demo_6_req = Demo6Req(client)
    ret = demo_6_req.demo_6()
    assert ret == 0


if __name__ == '__main__':
    test001()
