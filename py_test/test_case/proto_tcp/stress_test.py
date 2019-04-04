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

from test_action.tcp.demo_1_req import *
from test_action.tcp.demo_2_req import *
from test_action.tcp.demo_3_req import *


# Test001() Test002() Test003()的组合
def proc1():
    client = TcpClient(conf.demo_server_addr, conf.demo_server_tcp_port)
    demo_1_action = Demo1Req(client)
    ret = demo_1_action.demo_1()
    assert ret == 0

    demo_2_action = Demo2Req(client)
    ret = demo_2_action.demo_2()
    assert ret == 0

    ret = demo_2_action.demo_2_bad()
    assert ret == 0

    demo_3_action = Demo3Req(client)
    ret = demo_3_action.demo_3()
    assert ret == 0


def test001():
    run_multi_process(100, proc1)


# def test002():
#     run_multi_thread(100, proc1)


if __name__ == '__main__':
    test001()
