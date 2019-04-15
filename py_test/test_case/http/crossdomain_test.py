# -*- coding: utf-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import ssl
import httplib
from util.log_util import *

# 全局取消证书验证
ssl._create_default_https_context = ssl._create_unverified_context


def crossdomain(s):
    try:
        if s:
            http_conn = httplib.HTTPSConnection(conf.demo_server_addr, conf.demo_server_https_wss_port)
            LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_https_wss_port))
        else:
            http_conn = httplib.HTTPConnection(conf.demo_server_addr, conf.demo_server_http_ws_port)
            LOG_DEBUG('connect to %s:%d ok' % (conf.demo_server_addr, conf.demo_server_http_ws_port))

        http_conn.request('GET', '/crossdomain.xml')

        http_rsp = http_conn.getresponse()
        LOG_DEBUG('rsp code: %d(%s)' % (http_rsp.status, http_rsp.reason))
        assert http_rsp.status == httplib.OK

        rsp_headers = http_rsp.getheaders()
        for h in rsp_headers:
            LOG_DEBUG('%s: %s' % (h[0], h[1]))

        rsp_body = http_rsp.read()
        LOG_DEBUG('rsp body: %s' % rsp_body)

        assert rsp_body == '''<?xml version="1.0" encoding="UTF-8"?>
<cross-domain-policy>
<allow-access-from domain="*"/>
</cross-domain-policy>'''

        http_conn.close()
        ret = 0
    except Exception as e:
        LOG_ERROR('exception: %s' % e)
        ret = -1

    return ret


def test_001():
    assert crossdomain(False) == 0


if __name__ == '__main__':
    test_001()
