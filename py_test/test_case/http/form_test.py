# -*- coding: utf-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import ssl
import httplib
import urllib
from util.log_util import *
import requests
from requests_toolbelt import MultipartEncoder
import json
import random
import string

sys.path.append('%s/../../../../py_tools' % os.path.split(os.path.realpath(__file__))[0])  # 导入上级目录中的模块

# 全局取消证书验证
ssl._create_default_https_context = ssl._create_unverified_context

# 定义需要进行发送的数据
params = urllib.urlencode({"cat_id": 6,
                           "news_title": "标题-Test39875",
                           "news_author": "Mobedu",
                           "news_ahome": "来源"})

# 定义一些文件头
headers = {"Content-Type": "application/x-www-form-urlencoded",
           "Connection": "Keep-Alive", "Referer": "http://192.168.1.212/newsadd.asp?action=newnew"}


# application/x-www-form-urlencoded
def urlencode_get(s, query):
    try:
        if s:
            http_conn = httplib.HTTPSConnection(conf.demo_server_addr, conf.demo_server_web_security_port)
            LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_web_security_port))
        else:
            http_conn = httplib.HTTPConnection(conf.demo_server_addr, conf.demo_server_web_port)
            LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_web_port))

        if query:
            http_conn.request(method='GET', url='/form?x=1&y=abc&' + params, headers=headers)
        else:
            http_conn.request(method='GET', url='/form?' + params, headers=headers)

        http_rsp = http_conn.getresponse()
        LOG_DEBUG('rsp code: %d(%s)' % (http_rsp.status, http_rsp.reason))
        assert http_rsp.status == httplib.OK

        rsp_headers = http_rsp.getheaders()
        for h in rsp_headers:
            LOG_DEBUG('%s: %s' % (h[0], h[1]))

        rsp_body = http_rsp.read()
        LOG_DEBUG('rsp body: %s' % rsp_body.decode('utf-8'))  # 带中文的要先转换成utf8

        http_conn.close()
        ret = 0
    except Exception as e:
        LOG_ERROR('exception: %s' % e)
        ret = -1

    return ret


def test_001():
    assert 0 == urlencode_get(False, False)
    assert 0 == urlencode_get(False, True)
    # assert 0 == urlencode_get(True, False) # 暂不支持ssl
    # assert 0 == urlencode_get(True, True)


def urlencode_post(s, query):
    try:
        if s:
            http_conn = httplib.HTTPSConnection(conf.demo_server_addr, conf.demo_server_web_security_port)
            LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_web_security_port))
        else:
            http_conn = httplib.HTTPConnection(conf.demo_server_addr, conf.demo_server_web_port)
            LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_web_port))

        if query:
            http_conn.request(method='GET', url='/form?x=1&y=abc', headers=headers, body=params)
        else:
            http_conn.request(method='GET', url='/form', headers=headers, body=params)

        http_rsp = http_conn.getresponse()
        LOG_DEBUG('rsp code: %d(%s)' % (http_rsp.status, http_rsp.reason))
        assert http_rsp.status == httplib.OK

        rsp_headers = http_rsp.getheaders()
        for h in rsp_headers:
            LOG_DEBUG('%s: %s' % (h[0], h[1]))

        rsp_body = http_rsp.read()
        LOG_DEBUG('rsp body: %s' % rsp_body.decode('utf-8'))  # 带中文的要先转换成utf8

        http_conn.close()
        ret = 0
    except Exception as e:
        LOG_ERROR('exception: %s' % e)
        ret = -1

    return ret


def test_002():
    assert 0 == urlencode_post(False, False)
    assert 0 == urlencode_post(False, True)
    # assert 0 == urlencode_post(True, False) # 暂不支持ssl
    # assert 0 == urlencode_post(True, True)


def multipart_post1(s, file_path):
    try:
        if s:
            url = 'http://%s:%d' % (conf.demo_server_addr, conf.demo_server_web_security_port)
        else:
            url = 'http://%s:%d' % (conf.demo_server_addr, conf.demo_server_web_port)

        files = {'app_key': (None, '123456'),
                 'version': (None, '2256'),
                 'platform': (None, 'ios'),
                 'image': ('test.jpg', open(file_path, 'rb'))}
        rsp = requests.request("POST", url, files=files)
        LOG_DEBUG(rsp.status_code, rsp.text)

        ret = 0
    except Exception as e:
        LOG_ERROR('exception: %s' % e)
        ret = -1

    return ret


def test_003():
    assert 0 == multipart_post1(False, './demo_test.py')


def multipart_post2(s, file_path):
    try:
        if s:
            url = 'http://%s:%d' % (conf.demo_server_addr, conf.demo_server_web_security_port)
        else:
            url = 'http://%s:%d' % (conf.demo_server_addr, conf.demo_server_web_port)

        # 头部
        headers = {
            'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; Win64; x64; rv:50.0) Gecko/20100101 Firefox/50.0',
            'Referer': url
        }

        boundary = '------' + ''.join(random.sample(string.ascii_letters + string.digits, 32))

        multipart_encoder = MultipartEncoder(
            fields={
                # 这里根据服务器需要的参数格式进行修改
                params: json.dumps({
                    'folderId': -100,
                    'type': 'onlinedisk',
                    'name': '5106024f8a22422172bd88d455be48a0.gif',
                    'size': 16043,
                    'md5': '57c1a6348e35d4f86ed4d520da8e1dc2',
                    'ignoreSame': False,
                    'autoRename': False,
                    'startPosition': 0,
                    'blockMd5': '57c1a6348e35d4f86ed4d520da8e1dc2',
                    'blockSize': 16043,
                    'quickVerifyCode': '3c91184c5c91e13a60ebbf144f13783c',
                    'repaire': False
                }),
                'file': ('file', open(file_path, 'rb'), 'application/octet-stream')
            },
            boundary=boundary
        )
        headers['Content-Type'] = multipart_encoder.content_type
        # 请求头必须包含一个特殊的头信息,类似于Content-Type: multipart/form-data; boundary=${bound}
        # 注意：这里请求头也可以自己设置Content-Type信息，用于自定义boundary
        r = requests.post(url, data=multipart_encoder, headers=headers)
        print(r.text)
        # 注意,不要设置cookies等其他参数,否则会报错

        ret = 0
    except Exception as e:
        LOG_ERROR('exception: %s' % e)
        ret = -1

    return ret


def test_004():
    assert 0 == multipart_post2(False, './demo_test.py')


if __name__ == '__main__':
    # test_001()
    # test_002()
    # test_003()
    test_004()
