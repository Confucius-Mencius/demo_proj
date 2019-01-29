# -*- coding: UTF-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

# !!! python2.7 only !!!
# 本文件只是为了方便命令行执行，把需要执行的文件import进来

from test_case.tcp import echo_test

if __name__ == '__main__':
    echo_test.test001()
    echo_test.test002()
