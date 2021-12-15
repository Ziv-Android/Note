import sys
import time
import ctypes
import socket
import struct
import threading


try:
    import netifaces
except:
    print('netifaces')

class CFindDevice(threading.Thread):
    def __init__(self, pwm=None):
        threading.Thread.__init__(self)
        self.is_run = True
        self.devices = {}
        self.pwm = pwm
        self.local_addrs = self.get_addrs()

    #
    def receiver(self):
        mcast_group_port = 22100
        mcast_group_ip = "228.5.6.2"

        # 建立接收socket，和正常UDP数据包没区别
        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)

        # 允许端口复用
        sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

        # 绑定监听多播数据包的端口
        sock.bind(('0.0.0.0', mcast_group_port))

        # 加入组播组:要把
        for host in self.local_addrs:
            print('CFindDevice IP_ADD_MEMBERSHIP %s' % host)
            sock.setsockopt(socket.IPPROTO_IP,
                            socket.IP_ADD_MEMBERSHIP,
                            socket.inet_aton(mcast_group_ip) + socket.inet_aton(host))

        # 设置非阻塞
        # sock.setblocking(0)
        sock.settimeout(2)

        while self.is_run:
            try:
                device = {}
                data, addr = sock.recvfrom(2048)
                if b'VZ' == data[0:2]:
                    # print(addr[0])
                    device['addr'] = addr[0]

                    serial_h = int.from_bytes(data[20:24], byteorder='little', signed=False)
                    serial_l = int.from_bytes(data[24:28], byteorder='little', signed=False)
                    serial = '0x%08x-0x%08x' % (serial_h, serial_l)
                    device['s'] = serial
                    device['sl'] = serial_l
                    device['sh'] = serial_h
                    # print('serial:0x%08x-0x%08x' % (serial_h, serial_l))

                    board_version = int.from_bytes(data[40:42], byteorder='little', signed=False)
                    # print('board_version:0x%x' % (board_version))
                    device['bv'] = board_version
                    device['timeout'] = 5
                    self.devices[serial] = device
            except:
                # print("while receive message error occur")
                pass
        print("find device exit")


    def sender(self, data, size):
        mcast_group_port = 23456
        mcast_group_ip = "228.5.6.2"
        # 建立接收socket，和正常UDP数据包没区别
        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)

        # 允许端口复用
        sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

        # 绑定监听多播数据包的端口
        sock.bind(('0.0.0.0', mcast_group_port))

        # Set Time-to-live (optional)
        ttl_bin = struct.pack('@i', MYTTL)
        sock.setsockopt(socket.IPPROTO_IP, socket.IP_MULTICAST_TTL, socket.ttl_bin)
        status = s.setsockopt(IPPROTO_IP,
                              IP_ADD_MEMBERSHIP,
                              inet_aton(MYGROUP) + inet_aton(SENDERIP))  # 加入到组播组
        while True:
            data = 'cisco'
            s.sendto(data + '\0', (MYGROUP, MYPORT))
            print
            "send data ok !"
            time.sleep(10)

    #
    def sender(self, sh, sl, host, gateway, netmask):
        buf = ctypes.create_string_buffer(20)
        struct.pack_into(">I", buf, 0, sh)
        struct.pack_into(">I", buf, 4, sl)
        struct.pack_into(">I", buf, 8, host)
        struct.pack_into(">I", buf, 12, gateway)
        struct.pack_into(">I", buf, 16, netmask)


    #
    def get_addrs(self):
        addrs = []
        try:
            for interface in netifaces.interfaces():
                if netifaces.AF_INET in netifaces.ifaddresses(interface).keys():
                    host = netifaces.ifaddresses(interface)[netifaces.AF_INET][0]['addr']
                    if host == '127.0.0.1':
                        continue
                    addrs.append(host)
            return addrs
        except:
            print('get_addrs')
            return addrs

    def set_addrs(self, addrs):
        print('laddrs %s addrs %s' % (self.local_addrs[0], addrs[0]))
        if self.local_addrs[0] != addrs[0]:
            self.local_addrs = addrs
    
    #
    def get_devices(self):
        return self.devices

    #
    def clear_devices(self):
        self.devices.clear()

    #
    def run(self):
        self.receiver()

    def stop(self):
        self.is_run = False
        print("stop")

# fd = CFindDevice()
# addrs = fd.get_addrs()
# print(addrs)

# for interface in netifaces.interfaces():
#     try:
#         routingIPAddr = netifaces.ifaddresses(interface)[netifaces.AF_INET][0]['addr']
#         print(routingIPAddr)
#     except KeyError:
#         pass