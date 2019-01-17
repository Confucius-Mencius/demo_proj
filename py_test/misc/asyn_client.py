# -*- coding: UTF-8 -*-

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

import asyncore
import socket
import threading
import binascii
import struct
import time
from util.log_util import *


def CRC32(data, oldcrc=0):
    return binascii.crc32(data, oldcrc) & 0xffffffff


class AsynClient(asyncore.dispatcher):
    def __init__(self, host, port):
        asyncore.dispatcher.__init__(self)
        self.SendData = ""
        self.RecvData = ""
        self.rsp_buf = ''
        self.create_socket(socket.AF_INET, socket.SOCK_STREAM)
        self.connect((host, port))

    def handle_connect(self):
        LOG_DEBUG('connect')

    def handle_close(self):
        # print "disconnection : " + self.getpeername()[0]
        LOG_DEBUG('cant connect to server')
        self.close()

    # 收到的data
    def handle_read(self):
        self.RecvData = self.recv(4 + conf.max_tcp_msg_len)
        if len(self.RecvData) > 0:
            # print "recv : " + self.RecvData
            self.rsp_buf += self.RecvData

    # 送出data
    def handle_write(self):
        self.rsp_buf = ''

        send_byte = self.send(self.SendData)
        if send_byte > 0:
            send_out = self.SendData[:send_byte]
            self.SendData = self.SendData[send_byte:]
            # print "send : " + send_out
            self.handle_write()
        else:
            # print "send all!!"
            self.SendData = ""

    def writable(self):
        return False


class MsgLoopThread(threading.Thread):
    def __init__(self, host, port):
        self.client = AsynClient(host, port)
        threading.Thread.__init__(self)

    def run(self):
        try:
            asyncore.loop()
        except:
            pass

    def SendMsgToServer(self, version, passback, msg_id, msg_body, msg_body_len):
        req_msg_len = struct.pack('!i', 16 + msg_body_len)

        if not msg_body:
            req_msg_part = struct.pack('!iii', version, passback, msg_id)
        else:
            req_msg_part = struct.pack('!iii', version, passback, msg_id) + msg_body

        checksum = 0
        if conf.do_checksum:
            checksum = CRC32(req_msg_part)
        req_checksum = struct.pack('!I', checksum)

        self.client.SendData = req_msg_len + req_checksum + req_msg_part
        self.client.handle_write()

    def GetMsgListFromServer(self, wait_rsp_seconds):
        time.sleep(wait_rsp_seconds)  # 回复消息不止一个时，等待全部收到

        rsp_data_len = len(self.client.rsp_buf)
        offset = 0
        data_left = rsp_data_len
        rsp_msg_list = []

        while data_left > 4:
            rsp_msg_len = struct.unpack('!i', self.client.rsp_buf[offset:offset + 4])[0]
            LOG_DEBUG('rsp msg len: %d' % rsp_msg_len)

            if data_left - 4 >= rsp_msg_len:
                rsp_msg = self.client.rsp_buf[offset + 4:offset + 4 + rsp_msg_len]
                checksum_of_rsp_data = CRC32(rsp_msg[4:])
                rsp_checksum, = struct.unpack('!I', rsp_msg[0:4])

                if conf.do_checksum and rsp_checksum != checksum_of_rsp_data:
                    LOG_ERROR('checksum not match: %u<->%u' % (rsp_checksum, checksum_of_rsp_data))
                    return None

                rsp_version, = struct.unpack('!i', rsp_msg[4:8])
                rsp_passback, = struct.unpack('!i', rsp_msg[8:12])
                rsp_msg_id, = struct.unpack('!i', rsp_msg[12:16])

                if rsp_msg_len > 16:
                    rsp_msg_list.append((rsp_version, rsp_passback, rsp_msg_id, rsp_msg[16:]))
                else:
                    rsp_msg_list.append((rsp_version, rsp_passback, rsp_msg_id, None))

                offset += (4 + rsp_msg_len)
                data_left -= (4 + rsp_msg_len)

        return rsp_msg_list


def SendMsgToServer(server_addr, server_port, version, passback, msg_id, msg_body, msg_body_len, wait_rsp_seconds):
    msg_loop_thread = MsgLoopThread(server_addr, server_port)
    msg_loop_thread.setDaemon(True)  # 设置为true时,父线程退出时子线程一起退出
    msg_loop_thread.start()

    msg_loop_thread.SendMsgToServer(version, passback, msg_id, msg_body, msg_body_len)
    return msg_loop_thread.GetMsgListFromServer(wait_rsp_seconds)
