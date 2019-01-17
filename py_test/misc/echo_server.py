# -*- coding: utf-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import SocketServer
from SocketServer import StreamRequestHandler as SRH
import conf

host = '0.0.0.0'
port = 9999
addr = (host, port)


class Servers(SRH):
    def handle(self):
        print 'got connection from ', self.client_address
        # self.wfile.write('connection %s:%s at %s succeed!' % (host,port,ctime()))

        while True:
            data = self.request.recv(conf.max_tcp_msg_len)
            if not data:
                break

            print "recv from ", self.client_address[0]
            # print data
            self.request.send(data)


print 'echo server is running....'
server = SocketServer.ThreadingTCPServer(addr, Servers)
server.serve_forever()
