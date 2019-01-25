# -*- coding: UTF-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import os
import sys

sys.path.append('%s/../../py_tools' % os.path.split(os.path.realpath(__file__))[0])  # 导入上级目录中的模块
# print(sys.path)

demo_server_addr = '127.0.0.1'
demo_server_tcp_port = 10000

sock_timeout = None

app_name = 'my_app'
log_file = sys.path[0] + '/../logs/my_app.log'
