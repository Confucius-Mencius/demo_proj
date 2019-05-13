# -*- coding: UTF-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import os
import sys

sys.path.append('%s/../../../py_tools' % os.path.split(os.path.realpath(__file__))[0])  # 导入上级目录中的模块
# print(sys.path)

from base.concurrent_log_wrapper import *
import conf

clog_wrapper = ConcurrentLogWrapper(conf.app_name, conf.log_file)

LOG_DEBUG = logging.getLogger(clog_wrapper.logger_name).debug
LOG_INFO = logging.getLogger(clog_wrapper.logger_name).info
LOG_WARN = logging.getLogger(clog_wrapper.logger_name).warning
LOG_ERROR = logging.getLogger(clog_wrapper.logger_name).error


def demo001():
    LOG_DEBUG('hello')
    LOG_DEBUG('hello %s' % 'world')


if __name__ == '__main__':
    demo001()
