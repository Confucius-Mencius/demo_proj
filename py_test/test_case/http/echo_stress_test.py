# -*- coding: utf-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import os
import sys

sys.path.append('%s/../../../../py_tools' % os.path.split(os.path.realpath(__file__))[0])  # 导入上级目录中的模块
# print(sys.path)

from base.multitask_util import *
import echo_test


def proc1():
    echo_test.get1(False, False)
    echo_test.get1(False, True)
    echo_test.get1(True, False)
    echo_test.get1(True, True)

    echo_test.post1(False, False, 1024)
    echo_test.post1(False, True, 1024)
    echo_test.post1(True, False, 1024)
    echo_test.post1(True, True, 1024)

    echo_test.post1(False, False, 16385)
    echo_test.post1(False, True, 16385)
    echo_test.post1(True, False, 16385)
    echo_test.post1(True, True, 16385)


def test001():
    run_multi_process(10000, proc1)


if __name__ == '__main__':
    test001()
