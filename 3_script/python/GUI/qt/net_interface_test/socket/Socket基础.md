Socket 具有三大属性：域、类型、协议。

域：AF_UNIX（Unix 文件系统，地址为文件名，对应文件 IO） 和 AF_INET（Internet 网络，常用）两类  
类型：SOCK_STREAM（流，对应 TCP） 和 SOCK_DGRAM（数据报，对应 UDP）
协议：只要底层的传输机制允许不止一个协议来提供要求的套接字类型，  
我们就可以为套接字选择一个特定的协议。通常只需要使用默认值 0。

服务端套接字函数  
bind：将地址绑定到套接字  
listen：开始 TCP 监听，参数为两次 backlog 的间隔时间  
accept：被动接受 TCP 客户端连接，（阻塞式）等待连续的到来；返回一个新的 socket 连接和接入连接的地址

客户端套接字函数  
connect：主动初始化 TCP 服务器连接  
connect_ex：connect( ) 函数扩展版本，出错时返回出错码而不是抛出异常

公共用途的套接字函数  
recv：接受数据  
send：发送数据  
sendall：发送完整 TCP 数据（在发送完所有数据前不会返回，这会花费更长时间）  
revcfrom：接受 UDP 数据，返回该数据和接入连接的地址  
sendto：发送 UDP 数据（to 和 from 是因为 UDP 是无状态的连接，每次连接需知晓来源和目标）  
getpeername：连接到当前套接字的远端地址（TCP连接）  
getsockname：获取当前套接字的地址  
getsockopt：返回指定套接字的参数  
setsockopt：设置指定套接字的参数  
close：关闭套接字（如果不关闭套接字，系统通常不会自动关闭）

注：recv 和 recvfrom 可以替换使用，send 和 sendto 亦然  
区别是后者比前者多了两个接受对端地址信息的参数，针对 UDP 这种无状态协议，而 TCP 是对端连接，所以多余的两个参数没有用处

Socket 通信 - TCP 实现  
服务端
```python
import socket
address = ('127.0.0.1', 5005)  # 服务端地址和端口
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(address)  # 绑定服务端地址和端口
s.listen(5)
conn, addr = s.accept()  # 返回客户端地址和一个新的 socket 连接
print('[+] Connected with', addr)
while True:
    data = conn.recv(1024)  # buffersize 等于 1024
    data = data.decode()
    if not data:
        break
    print('[Received]', data)
    send = input('Input: ')
    conn.sendall(send.encode())
conn.close()
s.close()
```

客户端
```python
import socket
import sys
address = ('127.0.0.1', 5005)  # 服务端地址和端口
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
try:
    s.connect(address)  # 尝试连接服务端
except Exception:
    print('[!] Server not found ot not open')
    sys.exit()
while True:
    trigger = input('Input: ')
    s.sendall(trigger.encode())
    data = s.recv(1024)
    data = data.decode()
    print('[Recieved]', data)
    if trigger == '###':  # 自定义结束字符串
        break
s.close()
```

Socket 通信 - UDP 实现  
服务端
```python
import socket
address = ('127.0.0.1', 31500)  # 服务端地址和端口
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind(address)  # 绑定服务端地址和端口
while True:
    data, addr = s.recvfrom(1024)  # 返回数据和接入连接的（客户端）地址
    data = data.decode()
    if not data:
        break
    print('[Received]', data)
    send = input('Input: ')
    s.sendto(send.encode(), addr)  # UDP 是无状态连接，所以每次连接都需要给出目的地址
s.close()
```

客户端
```python
import socket
address = ('127.0.0.1', 31500)  # 服务端地址和端口
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
while True:
    trigger = input('Input: ')
    s.sendto(trigger.encode(), address)
    data, addr = s.recvfrom(1024)  # 返回数据和接入连接的（服务端）地址
    data = data.decode()
    print('[Recieved]', data)
    if trigger == '###':  # 自定义结束字符串
        break
s.close()
```
