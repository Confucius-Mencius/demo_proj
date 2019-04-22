# -*- coding: utf-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

# import os
# import sys

# sys.path.append('%s/../../../../py_tools' % os.path.split(os.path.realpath(__file__))[0])  # 导入上级目录中的模块
# # print(sys.path)

# import socket
# from util.log_util import *


# def demo1001():
#     try:
#         sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

#         sock.connect((conf.demo_server_addr, conf.demo_server_raw_tcp_port))
#         LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_raw_tcp_port))

#         sock.send('req1001')

#         rsp = sock.recv(7)
#         assert 'rsp1001' == rsp

#         nfy = sock.recv(7)
#         assert 'nfy1001' == nfy

#         nfy = sock.recv(7)
#         assert 'nfy1003' == nfy

#         sock.close()
#         ret = 0
#     except socket.error as e:
#         LOG_ERROR('exception: %s' % e)
#         ret = -1

#     return ret


# def test_001():
#     assert 0 == demo1001()


# if __name__ == '__main__':
#     test_001()
