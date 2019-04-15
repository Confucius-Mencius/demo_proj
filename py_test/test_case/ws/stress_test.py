# -*- coding: utf-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import os
import sys

sys.path.append('%s/../../../../py_tools' % os.path.split(os.path.realpath(__file__))[0])  # 导入上级目录中的模块
# print(sys.path)

from base.multitask_util import *
from echo_test import send_to_server1, send_to_server2
from ctrl_frame_test import ping, pong, close


def proc1():
    assert send_to_server1(False) == 0
    assert send_to_server1(False) == 0
    assert ping(False) == 0
    assert pong(False) == 0
    assert close(False) == 0


def test_001():
    run_multi_process(200, proc1)


if __name__ == '__main__':
    test_001()
