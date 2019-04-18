# -*- coding: utf-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import os
import sys

sys.path.append('%s/../../../../py_tools' % os.path.split(os.path.realpath(__file__))[0])  # 导入上级目录中的模块
# print(sys.path)

from base.multitask_util import *
import demo1_test
import demo100_test
import demo200_test


def proc1():
    assert 0 == demo1_test.demo1()


def test_001():
    run_multi_process(200, proc1)


def proc2():
    assert 0 == demo100_test.demo100()


def test_002():
    run_multi_process(200, proc2)


def proc3():
    assert 0 == demo200_test.demo200()


def test_003():
    run_multi_process(200, proc3)


if __name__ == '__main__':
    test_001()
    test_002()
    test_003()
