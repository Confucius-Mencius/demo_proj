# -*- coding: UTF-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

sock_timeout = None

app_name = 'my_app'
log_file = 'my_app.log'
print("log file: %s" % log_file)

demo_server_addr = '127.0.0.1'

demo_server_tcp_port = 5555
demo_server_proto_tcp_port = 6666
demo_server_http_ws_port = 10080
demo_server_https_wss_port = 10443
demo_server_udp_port = 7777

proto_tcp_max_msg_len = 1048576
proto_tcp_do_checksum = False
