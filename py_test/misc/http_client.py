# -*- coding: utf-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import httplib, urllib


def HttpGet():
    conn1 = httplib.HTTPConnection("127.0.0.1:8080")
    conn1.request("GET", "/opt=stat")

    response1 = conn1.getresponse()
    print response1.status, response1.reason

    data1 = response1.read()
    print data1

    conn2 = httplib.HTTPConnection("127.0.0.1:8080")
    conn2.request("GET", "/opt=stat")

    response2 = conn2.getresponse()
    print response2.status, response2.reason

    data2 = response2.read()
    print data2

    conn3 = httplib.HTTPConnection("127.0.0.1:8080")
    conn3.request("GET", "/opt=stat")

    response3 = conn3.getresponse()
    print response3.status, response3.reason

    data3 = response3.read()
    print data3

    conn1.close()
    conn2.close()
    conn3.close()

    # conn1 = httplib.HTTPConnection("zane.easydown.moon.com")
    # conn1.request("GET", "/blue.cjstyles", '', {'referer':'pan.moon.com'})


def HttpPost():
    params = urllib.urlencode({'spam': 1, 'eggs': 2, 'bacon': 0})
    headers = {"Content-type": "application/x-www-form-urlencoded", "Accept": "text/plain"}

    conn = httplib.HTTPConnection("127.0.0.1:8080")
    conn.request("POST", "/cgi-bin/query", params, headers)

    response = conn.getresponse()
    print response.status, response.reason

    data = response.read()
    print data

    conn.close()


if __name__ == '__main__':
    HttpGet()
    # HttpPost()
