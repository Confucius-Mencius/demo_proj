# -*- coding: utf-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import os
import sys

sys.path.append('%s/../../../../py_tools' % os.path.split(os.path.realpath(__file__))[0])  # 导入上级目录中的模块
# print(sys.path)

from base.multitask_util import *
from echo_test import send_to_server


def proc1():
    assert send_to_server() == 0


def test001():
    run_multi_process(100, proc1)


if __name__ == '__main__':
    test001()
