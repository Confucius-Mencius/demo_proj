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
# import demo1001_test
# import demo1100_test


def proc1():
    assert 0 == echo_test.send_to_server1()


def test_001():
    run_multi_process(200, proc1)


def proc2():
    assert 0 == echo_test.send_to_server2()


def test_002():
    run_multi_process(200, proc2)


# def proc3():
#     assert 0 == demo1001_test.demo1001()


# def test_003():
#     run_multi_process(200, proc3)


# def proc4():
#     assert 0 == demo1100_test.demo1100()


# def test_004():
#     run_multi_process(200, proc4)


if __name__ == '__main__':
    test_001()
    test_002()
    # test_003()
    # test_004()
