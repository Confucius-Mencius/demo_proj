# -*- coding: utf-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import ssl
import httplib
from util.log_util import *

# 全局取消证书验证
ssl._create_default_https_context = ssl._create_unverified_context


def get1(s, query):
    try:
        if s:
            http_conn = httplib.HTTPSConnection(conf.demo_server_addr, conf.demo_server_https_wss_port)
            LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_https_wss_port))
        else:
            http_conn = httplib.HTTPConnection(conf.demo_server_addr, conf.demo_server_http_ws_port)
            LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_http_ws_port))

        if query:
            http_conn.request('GET', '/demo?x=1&y=abc')
        else:
            http_conn.request('GET', '/demo')

        http_rsp = http_conn.getresponse()
        LOG_DEBUG('rsp code: %d(%s)' % (http_rsp.status, http_rsp.reason))
        assert http_rsp.status == httplib.OK

        rsp_headers = http_rsp.getheaders()
        for h in rsp_headers:
            LOG_DEBUG('%s: %s' % (h[0], h[1]))

        rsp_body = http_rsp.read()
        LOG_DEBUG('rsp body: %s' % rsp_body)
        assert rsp_body == 'hello, world'

        http_conn.close()
        ret = 0
    except Exception as e:
        LOG_ERROR('exception: %s' % e)
        ret = -1

    return ret


def test_001():
    assert get1(False, False) == 0
    assert get1(False, True) == 0
    # assert get1(True, False) == 0 # 暂不支持ssl
    # assert get1(True, True) == 0


def post1(s, query, body_len):
    try:
        if s:
            http_conn = httplib.HTTPSConnection(conf.demo_server_addr, conf.demo_server_https_wss_port)
            LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_https_wss_port))
        else:
            http_conn = httplib.HTTPConnection(conf.demo_server_addr, conf.demo_server_http_ws_port)
            LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_http_ws_port))

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


def test_002():
    assert post1(False, False, 1024) == 0
    assert post1(False, True, 1024) == 0
    # assert post1(True, False, 1024) == 0
    # assert post1(True, True, 1024) == 0

    assert post1(False, False, 16385) == 0
    assert post1(False, True, 16385) == 0
    # assert post1(True, False, 16385) == 0
    # assert post1(True, True, 16385) == 0


if __name__ == '__main__':
    test_001()
    test_002()
