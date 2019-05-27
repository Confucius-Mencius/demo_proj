# -*- coding: utf-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import ssl
import httplib
import urllib
from util.log_util import *

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


def multipart_post(s, query, body_len):
    try:
        if s:
            http_conn = httplib.HTTPSConnection(conf.demo_server_addr, conf.demo_server_web_security_port)
            LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_web_security_port))
        else:
            http_conn = httplib.HTTPConnection(conf.demo_server_addr, conf.demo_server_web_port)
            LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_web_port))

        if query:
            http_conn.request('POST', '/demo?x=aaa&y=100', 'x' * body_len)
        else:
            http_conn.request('POST', '/demo', 'x' * body_len)

        http_rsp = http_conn.getresponse()
        LOG_DEBUG('rsp code: %d(%s)' % (http_rsp.status, http_rsp.reason if http_rsp.reason else ''))
        assert http_rsp.status == httplib.OK

        rsp_headers = http_rsp.getheaders()
        for h in rsp_headers:
            LOG_DEBUG('%s: %s' % (h[0], h[1]))

        rsp_body = http_rsp.read()
        LOG_DEBUG('rsp body: %s' % rsp_body)
        assert rsp_body == 'x' * body_len

        http_conn.close()
        ret = 0
    except Exception as e:
        LOG_ERROR('exception: %s' % e)
        ret = -1

    return ret


def test_003():
    assert 0 == multipart_post(False, False, 1024)
    assert 0 == multipart_post(False, True, 1024)
    # assert 0 == post1(True, False, 1024)
    # assert 0 == post1(True, True, 1024)

    assert 0 == multipart_post(False, False, 16385)
    assert 0 == multipart_post(False, True, 16385)
    # assert 0 == post1(True, False, 16385)
    # assert 0 == post1(True, True, 16385)


if __name__ == '__main__':
    # test_001()
    # test_002()
    test_003()
