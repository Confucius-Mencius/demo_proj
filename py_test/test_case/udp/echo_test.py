# -*- coding: utf-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import os
import sys

sys.path.append('%s/../../../../py_tools' % os.path.split(os.path.realpath(__file__))[0])  # 导入上级目录中的模块
# print(sys.path)

from base.udp_client import *

from test_action.udp.echo_req import *


def test001():
    client = UdpClient(conf.demo_server_addr, conf.demo_server_udp_port, 3)
    echo_req = EchoReq(client)
    ret = echo_req.echo()
    assert ret == 0


if __name__ == '__main__':
    test001()
