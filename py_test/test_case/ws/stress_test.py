# -*- coding: utf-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import os
import sys

sys.path.append('%s/../../../../py_tools' % os.path.split(os.path.realpath(__file__))[0])  # 导入上级目录中的模块
# print(sys.path)

from base.multitask_util import *
import websocket
import echo_test
import ctrl_frame_test


def proc1():
    assert 0 == echo_test.send_to_server1(False)


def test_001():
    run_multi_process(200, proc1)


def proc2():
    assert 0 == echo_test.send_to_server2(False)


def test_002():
    run_multi_process(200, proc2)


def proc3():
    assert 0 == echo_test.send_to_server3(False)


def test_003():
    run_multi_process(200, proc3)


def proc4():
    assert 0 == echo_test.send_to_server4(False)


def test_004():
    run_multi_process(200, proc4)


def proc5():
    assert 0 == ctrl_frame_test.ping(False)


def test_005():
    run_multi_process(200, proc5)


def proc6():
    assert 0 == ctrl_frame_test.pong(False)


def test_006():
    run_multi_process(200, proc6)


def proc7():
    assert 0 == ctrl_frame_test.close(False, websocket.STATUS_NORMAL)


def test_007():
    run_multi_process(200, proc7)


if __name__ == '__main__':
    test_001()
    test_002()
    test_003()
    test_004()
    test_005()
    test_006()
    test_007()
