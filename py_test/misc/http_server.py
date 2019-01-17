# -*- coding: utf-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

'''
基于BaseHTTPServer的http server实现，包括get，post方法，get参数接收，post参数接收。
'''

from BaseHTTPServer import BaseHTTPRequestHandler, HTTPServer
import io
import shutil
import urllib
import json


class MyRequestHandler(BaseHTTPRequestHandler):
    def do_GET(self):
        self.JsonRsp()
        # self.process(2)

    def do_POST(self):
        self.JsonRsp()
        # self.process(1)

    def JsonRsp(self):
        dict = {"flag": 1}

        enc = "UTF-8"
        content = json.dumps(dict).encode(enc)

        #           print content,len(content)
        f = io.BytesIO()
        f.write(content)

        f.seek(0)
        self.send_response(200)
        self.send_header("Content-Length", str(len(content)))
        self.end_headers()

        shutil.copyfileobj(f, self.wfile)

    def process(self, type):
        content = ""

        if type == 1:  # post方法，接收post参数
            datas = self.rfile.read(int(self.headers['content-length']))
            datas = urllib.unquote(datas).decode("utf-8", 'ignore')  # 指定编码方式

            datas = transDicts(datas)  # 将参数转换为字典
            if datas.has_key('data'):
                content = "data:" + datas['data'] + "\r\n"
                enc = "UTF-8"
                content = content.encode(enc)

                f = io.BytesIO()
                f.write(content)

                f.seek(0)
                self.send_response(200)
                self.send_header("Content-type", "text/html; charset=%s" % enc)
                self.send_header("Content-Length", str(len(content)))
                self.end_headers()

                shutil.copyfileobj(f, self.wfile)

        if '?' in self.path:
            query = urllib.splitquery(self.path)
            action = query[0]

            if query[1]:  # 接收get参数
                queryParams = {}

                for qp in query[1].split('&'):
                    kv = qp.split('=')
                    if kv[0] == 'echostr':
                        queryParams[kv[0]] = urllib.unquote(kv[1]).decode("utf-8", 'ignore')  # 指定编码方式
                        #                       content += kv[0]+':'+queryParams[kv[0]]+"\r\n"
                        content = queryParams[kv[0]] + "\r\n"

            # 指定返回编码
            enc = "UTF-8"
            content = content.encode(enc)

            #           print content,len(content)
            f = io.BytesIO()
            f.write(content)

            f.seek(0)
            self.send_response(200)
            self.send_header("Content-type", "text/html; charset=%s" % enc)
            self.send_header("Content-Length", str(len(content)))
            self.end_headers()

            shutil.copyfileobj(f, self.wfile)


def transDicts(params):
    dicts = {}

    if len(params) == 0:
        return

    params = params.split('&')
    for param in params:
        dicts[param.split('=')[0]] = param.split('=')[1]

    return dicts


if __name__ == '__main__':
    try:
        server = HTTPServer(('', 9090), MyRequestHandler)
        print 'start http server... %s %s' % (server.server_address, server.server_port)
        server.serve_forever()
    except KeyboardInterrupt:
        server.socket.close()
    pass

#
# do_GET
# curl -i http://127.0.0.1:8000?timestap=232323\&nonce=2331221\&echostr=3434\&signature=23dsw3w2
# wget http://127.0.0.1:8000?timestap=232323\&nonce=2331221\&echostr=3434\&signature=23dsw3w2

# do_POST
# curl -i -d "data=postdata" http://127.0.0.1:8000?test=post
#
