# -*- coding: utf-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import os
import sys

sys.path.append('%s/../../../../py_tools' % os.path.split(os.path.realpath(__file__))[0])  # 导入上级目录中的模块
# print(sys.path)

from base.tcp_client import *
from base.multitask_util import *

from test_action.tcp.echo_req import *


def proc1():
    client = TcpClient(conf.demo_server_addr, conf.demo_server_tcp_port)
    echo_req = EchoReq(client)
    ret = echo_req.echo()
    if ret != 0:
        LOG_ERROR('xxxxxxxxx ret: %d' % ret)

    assert ret == 0


def test001():
    run_multi_process(100, proc1)


# def test002():
#     run_multi_thread(100, proc1)


if __name__ == '__main__':
    test001()
