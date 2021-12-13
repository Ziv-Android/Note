import sys
import struct
import time
import socket
# import PyQt5.QtNetwork as QTN

any_host = "0.0.0.0"
mcast_group_ip = "228.5.6.2"
mcast_group_port = 22100


def receiver():
    # 创建UDP socket
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)

    # 允许端口复用
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

    # 绑定监听多播数据包的端口
    # sock.bind((any_host, mcast_group_port))
    sock.bind((any_host, mcast_group_port))

    # 声明该socket为多播类型
    # sock.setsockopt(socket.IPPROTO_IP, socket.IP_MULTICAST_TTL, 255)

    # 加入多播组，组地址由第三个参数制定
    sock.setsockopt(socket.IPPROTO_IP,
                    socket.IP_ADD_MEMBERSHIP,
                    socket.inet_aton(mcast_group_ip) + socket.inet_aton('192.168.6.18'))

    # 设置非阻塞，看到很多教程都有也没想清楚有什么用，我这里直接注释掉
    # sock.setblocking(0)
    # sock.sendto(b'asds', (mcast_group_ip, mcast_group_port))

    while True:
        try:
            message, addr = sock.recvfrom(1024)
            print("hello worlds")
            print(
                f'{time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())}: Receive data from {addr}')
            # print(f'{time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())}: Receive data from {addr}: {message.decode()}')
        except :
            print("while receive message error occur")

# def receiver():
#     groupaddr = QTN.QHostAddress(mcast_group_ip)
#     udp = QTN.QUdpSocket()
#     udp.setSocketOption(QTN.QAbstractSocket.MulticastLoopbackOption, 1)
#     udp.setSocketOption(QTN.QAbstractSocket.MulticastTtlOption, 32)
#     udp.bind(QTN.QHostAddress.AnyIPv4, mcast_group_port, QTN.QUdpSocket.ShareAddress)
#     ni = QTN.QNetworkInterface()
#     udp.joinMulticastGroup(groupaddr, ni)
#
#     while True:
#         # print("hello worlds 1")
#         if udp.hasPendingDatagrams():
#             print("hello worlds 2")
#             data, host, port = udp.readDatagram(udp.pendingDatagramSize())
#             # print(data)
#             print(host)
#             # udp.leaveMulticastGroup(groupaddr)
#             # udp.close()
#             # break


if __name__ == "__main__":
    receiver()
