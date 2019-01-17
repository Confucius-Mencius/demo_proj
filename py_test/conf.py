# -*- coding: UTF-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import os
import sys

sys.path.append('%s/../../py_tools' % os.path.split(os.path.realpath(__file__))[0])  # 导入上级目录中的模块
# print(sys.path)

from base.msg_codec import MIN_TOTAL_MSG_LEN


demo_server_addr = '127.0.0.1'
#demo_server_addr = '10.0.4.100'
demo_server_tcp_port = 10000
demo_server_raw_tcp_port = 10001
demo_server_http_port = 8080
demo_server_https_port = 9090
demo_server_udp_port = 20000

sock_timeout = None
do_checksum = True

max_tcp_msg_len = (MIN_TOTAL_MSG_LEN + 1048576)
max_raw_tcp_msg_len = 0x100000
max_udp_msg_len = 0xffff

app_name = 'my_app'
log_file = './my_app.log'
