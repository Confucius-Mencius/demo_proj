# -*- coding: utf-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import os
import sys

sys.path.append('%s/../../../../py_tools' % os.path.split(os.path.realpath(__file__))[0])  # 导入上级目录中的模块
# print(sys.path)

from base.multitask_util import *
from demo_test import get1, post1
from crossdomain_test import crossdomain


def proc1():
    get1(False, False)
    get1(False, True)

    post1(False, False, 1024)
    post1(False, True, 1024)

    post1(False, False, 16385)
    post1(False, True, 16385)

    crossdomain(False)


def test_001():
    run_multi_process(200, proc1)


if __name__ == '__main__':
    test_001()
