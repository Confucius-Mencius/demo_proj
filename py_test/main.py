# -*- coding: UTF-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

# !!! python2.7 only !!!
# 本文件只是为了方便命令行执行，把需要执行的文件import进来

from test_case.tcp import demo_2_test

if __name__ == '__main__':

    while True:
        demo_2_test.test001()
