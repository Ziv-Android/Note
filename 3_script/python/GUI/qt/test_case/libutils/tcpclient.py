#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import json
import socket
import traceback
from ctypes import create_string_buffer

import select
import struct
from time import sleep, time


# TCP阻塞通信,使用request发送消息获取回执
class TCPClient:
    def connect(self, host, port):
        self.host = host;
        self.port = port;

        self.tc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        # self.tc.setblocking(0)  # 非阻塞模式
        try:
            self.tc.connect((self.host, self.port))
        except socket.error:
            print('Fail to setup socket connection. err is {}'.format(socket.error))
            self.tc.close()

    #
    def recv(self, buffer=1024):
        self.tc.recv(buffer)

    #
    def close(self):
        self.tc.close()

    # 向TCP连接上发送数据
    def send_cmd(self, cmd):
        cmd_len = len(cmd)
        # init all \x00
        buf = create_string_buffer(cmd_len + 8)
        struct.pack_into(">2B", buf, 0, 86, 90)  # 'VZ'
        struct.pack_into(">I", buf, 4, cmd_len)
        struct.pack_into(">" + str(cmd_len) + "s", buf, 8, cmd)

        try:
            self.tc.sendall(buf)
        except socket.error:
            print('连接错误{}'.format(socket.errno))
            raise

    # 心跳
    def send_heartbeat(self):
        buf = create_string_buffer(8)
        struct.pack_into(">2B", buf, 0, 86, 90)
        struct.pack_into(">B", buf, 2, 1)  # 0x01
        struct.pack_into(">I", buf, 4, 0)
        self.tc.sendall(buf)

    #
    def recv_ret(self, timeout=10):
        json_res = {}  # 数据处理后的结果
        wait_count = 0  # 收到心跳包次数（防止死循环在心跳包中）
        image_str = ''
        try:
            while True:
                # 设置 recv 超时时间
                ready = select.select([self.tc], [], [], timeout)
                if ready[0]:
                    # 接收结果
                    response = self.tc.recv(8)      # head
                    if (b'VZ' == response[0:2]):
                        data_len = struct.unpack('>i', bytes(response[4:8]))
                        # sleep(1)
                        response = self.tc.recv(data_len[0])
                        if response == b'':
                            continue

                        # 数据分割定位
                        sear_str_byte = b'}\n'
                        split_index = response.find(sear_str_byte)

                        # 获取非图片部分的json值
                        temp = response[0:split_index + 1]
                        response_str = str(temp, encoding='gbk')
                        # response_str = str(temp,encoding='utf-8')
                        json_res = json.loads(response_str)

                        # 具有图片数据
                        if len(response[split_index:]) > 100:
                            # 获取图片数据
                            image_str = response[split_index + len(sear_str_byte) + 1:]
                        break

                    elif response == b'':  # 心跳包返回空字串
                        wait_count += 1
                        if wait_count <= 1:
                            print('tcp_recv_data 循环等待次数 {}'.format(wait_count))
                            continue
                        else:
                            break
        except Exception as err:
            # print('Fail err is  %s' % (err))
            print('response = {}'.format(response))
        finally:
            # 发送一个心跳
            self.send_heartbeat()
        return json_res, image_str

    #
    def request(self, cmd=''):
        json_data = {}  # 接受数据
        image_str = ''
        if cmd == '':
            return json_data
        try:
            # 发送命令
            self.send_cmd(cmd)
            json_data, image_str = self.recv_ret()

        except Exception as err:
            print('function {} err is {}  json_data={}'.format(self.__class__.__name__, err, json_data))
            json_data = {}

        return json_data, image_str


