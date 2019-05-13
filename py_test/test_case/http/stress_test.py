# -*- coding: utf-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import os
import sys

sys.path.append('%s/../../../../py_tools' % os.path.split(os.path.realpath(__file__))[0])  # 导入上级目录中的模块
# print(sys.path)

from base.multitask_util import *
import demo_test
import crossdomain_test

PROC_COUNT = 200


def proc1():
    assert 0 == demo_test.get1(False, False)


def test_001():
    run_multi_process(PROC_COUNT, proc1)


def proc2():
    assert 0 == demo_test.get1(False, True)


def test_002():
    run_multi_process(PROC_COUNT, proc2)


def proc3():
    assert 0 == demo_test.post1(False, False, 1024)


def test_003():
    run_multi_process(PROC_COUNT, proc3)


def proc4():
    assert 0 == demo_test.post1(False, True, 1024)


def test_004():
    run_multi_process(PROC_COUNT, proc4)


def proc5():
    assert 0 == demo_test.post1(False, False, 16385)


def test_005():
    run_multi_process(PROC_COUNT, proc5)


def proc6():
    assert 0 == demo_test.post1(False, True, 16385)


def test_006():
    run_multi_process(PROC_COUNT, proc6)


def proc7():
    assert 0 == crossdomain_test.crossdomain(False)


def test_007():
    run_multi_process(PROC_COUNT, proc7)


if __name__ == '__main__':
    test_001()
    test_002()
    test_003()
    test_004()
    test_005()
    test_006()
    test_007()
