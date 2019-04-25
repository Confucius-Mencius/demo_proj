# -*- coding: UTF-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

# !!! python2.7 only !!!
# 本文件只是为了方便命令行执行，把需要执行的文件import进来

from test_case.base import connect_test
from test_case.tcp import echo_test
from test_case.proto_tcp import demo100_test, demo200_test, demo1_test

if __name__ == '__main__':
    # connect_test.test_001()
    # echo_test.test_001()
    # echo_test.test_002()
    demo100_test.test_001()
    demo200_test.test_001()
    demo1_test.test_001()
