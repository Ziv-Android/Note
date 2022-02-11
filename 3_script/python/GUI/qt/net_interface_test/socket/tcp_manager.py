#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import socket
import struct
import threading
import time
from ctypes import create_string_buffer


class TcpManager:
    def __init__(self, ip="", port=8131):
        if ip == "":
            return
        self.ip = ip
        self.port = port
        self.s = None
        self.start()

    def start(self):
        self.s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        try:
            self.s.connect((self.ip, self.port))
            self.start_heart_beat_thread()
        except socket.error as e:
            print("TCP connect exception:", e)
            self.close()

    def start_heart_beat_thread(self):
        job_thread = threading.Thread(target=self.send_heart_beat)
        job_thread.start()

    def send_heart_beat(self):
        while self.s is not None:
            print("[TCP send]:", "heart beat")
            buf = create_string_buffer(8)
            struct.pack_into(">2B", buf, 0, 86, 90)
            struct.pack_into(">B", buf, 2, 1)  # 0x01
            struct.pack_into(">I", buf, 4, 0)
            self.s.sendall(buf)
            self.recv()
            time.sleep(5)

    def send_base(self, cmd_data):
        cmd_len = len(cmd_data)
        # init all \x00
        buf = create_string_buffer(cmd_len + 8)
        struct.pack_into(">2B", buf, 0, 86, 90)  # 'VZ'
        struct.pack_into(">I", buf, 4, cmd_len)
        struct.pack_into(">" + str(cmd_len) + "s", buf, 8, cmd_data)
        try:
            print("[TCP send]:", cmd_data)
            self.s.sendall(buf)
        except socket.error as e:
            print("TCP send exception", e)

    def send(self, cmd):
        if self.s is None:
            return
        if not cmd.startswith("{"):
            return
        self.send_base(cmd.encode())

    def recv(self):
        # while self.s is not None:
        #     time.sleep(1)
        response = self.s.recv(8)
        if (b'VZ' == response[0:2]):
            data_len = struct.unpack('>i', bytes(response[4:8]))[0]
            print("[TCP recv] data size:", data_len)
            if data_len > 0:
                response = self.s.recv(data_len)
                if data_len < 100000:
                    data = response.decode()
                    print("[TCP recv]:", data)
                    return data
                else:
                    return response
        return ""

    def close(self):
        if self.s is None:
            return
        self.s.close()
        self.s = None


client = TcpManager("192.168.13.202")
# client.send('{"cmd":"get_reco_prop","id":"132156"}')
# client.send('{"cmd":"get_led_para","id":"132156"}')
# client.recv()
with open("tcp_interface_auto_cmd.txt", "r") as rf:
    with open("tcp_interface_auto_cmd_result.txt", "w", encoding="utf-8") as wf:
        cmds = rf.readlines()
        for cmd in cmds:
            wf.write(f"[send]:{cmd}")
            if cmd.startswith("{"):
                client.send(cmd)
                time.sleep(0.5)
                wf.write(f"[recv]:{client.recv()}")
                time.sleep(1)
            wf.write('\n')
client.close()
