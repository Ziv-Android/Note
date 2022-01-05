#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import base64
import binascii
import sys

from Crypto.Cipher import AES
from Crypto.Util import Counter
from cryptography.hazmat.primitives import padding
from cryptography.hazmat.primitives.ciphers import algorithms


# str不是32的倍数那就补足为16的倍数
def add_to_32(value):
    while len(value) % 32 != 0:
        value += '\0'
    return str.encode(value)  # 返回bytes


def add_to_16(value):
    while len(value) % 16 != 0:
        value += '\0'
    return str.encode(value)  # 返回bytes


# data = "欢迎来到chacuo.net"
# data = '{"type":"avs_focus","module":"AVS_REQUEST_MESSAGE","body":{"option":0,"motor":0,"runmode":1,"value":1}}'
data = '{"parking_no":"浙A12345","io_count":100}'
key = b"B0623EE1498FC9EB7E1600245D745313" # zekrXpu8nVCnx+zith8Vxb9Qqc36NJGZ/VBxIj11aD4=
nonce_data = b"RF_50_00000001"

# pad_data = padding.PKCS7(algorithms.AES.block_size).padder()
# pad = pad_data.update(data.encode('utf-8')) + pad_data.finalize()
# print("pad1:", pad)

# BLOCK_SIZE = 32 # Bytes
# # 数据进行 PKCS5Padding 的填充
# pad = lambda s: (s + (BLOCK_SIZE - len(s.encode('utf-8')) % BLOCK_SIZE) * chr(BLOCK_SIZE - len(s.encode('utf-8')) % BLOCK_SIZE))
# print("pad2:", pad(data).encode('utf-8'))
# # 截断函数, 去掉 PKCS5Padding 的填充
# unpad = lambda s: s[:-ord(s[len(s.encode('utf-8')) - 1:])]


data_bytes = int.from_bytes(nonce_data, sys.byteorder)
print("data_bytes:", data_bytes, len(str(data_bytes)))

nonce = int(binascii.hexlify(nonce_data), 16)
print("nonce:", nonce, len(str(nonce)))
counter = Counter.new(128, initial_value=nonce)
print("counter:", counter)

cipher = AES.new(key, AES.MODE_CTR, counter=counter)
# data = pad(data)
print("pad_data:", data.encode("utf-8"))
enc = cipher.encrypt(data.encode("utf-8"))
print("enc:", enc)

msg = base64.encodebytes(enc)
print("msg:", msg.decode("utf-8"))

# decrypted = unpad(cipher.decrypt(base64.decodebytes(msg)))
# print("decrypted:", decrypted)
"""
AES支持三种长度的密钥：128位，192位，256位
AES加密并不是一次性将明文加密成密文的，而是把明文拆分成一个个独立的明文块，且每个明文块128bit
加密算法提供了五种不同的工作模式：
1. ECB：电码本模式（Electronic Codebook Book）每一个明文块的加密都是完全独立，互不干涉的，简单可并行计算，安全性较低
2. CBC：密码分组链接模式（Cipher Block Chaining）引入了初始向量IV，依次异或操作，误差传递；不容易主动攻击，安全性好于ECB，适合传输长度长的报文，是SSL、IPSec的标准
3. CTR：计算器模式（Counter）
4. CFB：密码反馈模式（Cipher FeedBack）
5. OFB：输出反馈模式（Output FeedBack）

https://www.cnblogs.com/yoyoketang/p/11717282.html
"""