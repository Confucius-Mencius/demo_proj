# -*- coding: utf-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import os
import sys

sys.path.append('%s/../../../../py_tools' % os.path.split(os.path.realpath(__file__))[0])  # 导入上级目录中的模块
# print(sys.path)

from base.udp_client import *
from base.multitask_util import *

from test_action.udp.echo_req import *


def proc1():
    client = UdpClient(conf.demo_server_addr, conf.demo_server_udp_port, 3) # todo 批量跑会有revefrom超时，怀疑是udp丢包导致的
    echo_req = EchoReq(client)
    ret = echo_req.echo()
    assert ret == 0


def test001():
    run_multi_process(100, proc1)


# def test002():
#     run_multi_thread(100, proc1)


if __name__ == '__main__':
    test001()
