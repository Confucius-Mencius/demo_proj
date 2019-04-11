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


def proc1():
    assert send_to_server1(False) == 0
    assert send_to_server1(True) == 0


def test001():
    run_multi_process(10000, proc1)


def proc2():
    assert send_to_server2(False) == 0
    assert send_to_server2(True) == 0


def test002():
    run_multi_process(10000, proc2)


if __name__ == '__main__':
    test001()
    test002()
