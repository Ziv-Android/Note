Http((HTTP-Hypertext transfer protocol) - 超文本传输协议
默认端口80

Https(Hypertext Transfer Protocol over Secure Socket Layer)
默认端口443


Https请求较慢的优化建议：
1. 自定义DNS解析，直接通过IP访问，跳过运营商DNS服务
2. 解决连接无法复用问题：
   1. `Connection:Keep-Alive`或`Connection:Close`由于App端普遍请求较为分散，时间跨度较大，因此该设置对App优化不大
   2. 基于TCP长连接
   3. http long-polling/http streaming
   4. web socket
3. 解决head of line blocking：使用http pipelining，防止由于队列中的第一个数据包受阻导致所有数据受阻


Https中SSL握手建立过程：
1、客户端和服务端建立 SSL 握手，客户端通过 CA 证书来确认服务端的身份；
2、互相传递三个随机数，之后通过这随机数来生成一个密钥；
3、互相确认密钥，然后握手结束；
4、数据通讯开始，都使用同一个对话密钥来加解密；


Http响应码：
1** 信息，服务器收到请求，需要请求者继续执行操作
2** 成功，操作被成功接收并处理
3** 重定向，需要进一步的操作以完成请求
4** 客户端错误，请求包含语法错误或无法完成请求
5** 服务器错误，服务器在处理请求的过程中发生了错

TCP三次握手、四次挥手
ACK ： TCP 协议规定，只有 ACK=1 时有效，也规定连接建立后所有发送的报文的 ACK 必须为 1
SYN(SYNchronization) ： 在连接建立时用来同步序号。当 SYN=1 而 ACK=0 时，表明这是一个连接请求报文。对方若同意建立连接，则应在响应报文中使SYN=1和ACK=1. 因此, SYN置 1 就表示这是一个连接请求或连接接受报文。
FIN （finis）即完，终结的意思， 用来释放一个连接。当 FIN = 1 时，表明此报文段的发送方的数据已经发送完毕，并要求释放连接

三次握手
1. 第一次握手：客户端 -> 服务器：客户端发送连接请求报文。SYN=1，Sequence Number=x；客户端进入 SYN_SEND 状态，等待服务器的确认；
2. 第二次握手：服务器 -> 客户端：服务器收到SYN报文段，确认SYN报文段，服务器进入SYN_RECV状态
3. 第三次握手：客户端 -> 服务器：