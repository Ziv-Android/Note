#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import os
import struct
import zlib

# filepath = "VZ_RF2_7.3.1.202112246_u1022211140k1213211647r4a202112246.bin"
filepath = "VZ_RX_8.2.2.202109030_u28k30r46a09030 (1).bin"
# filepath = "VZ_S1L_2.1.1.202010210_u906k906r908a992.bin"
# filepath = "tetete.txt"

size = os.path.getsize(filepath) #获得文件大小
print(size)
with open(filepath, "rb") as of:
    data = of.read(64)
    print(data[62:64])
    num = struct.unpack("<H", data[62:64])
    print("bin header version: <H", num[0])

    if num[0] == 0:
        print(data[20:36])
        for index in range(20, 36, 4):
            num = struct.unpack("<I", data[index:index+4])
            print("bin version: <I", num[0])
    elif num[0] == 160:
        print(data[24:32])
        num = struct.unpack("B", data[24:25])
        print("bin version: 产品", num[0])
        num = struct.unpack("B", data[25:26])
        print("bin version: 项目", num[0])
        num = struct.unpack("<H", data[26:28])
        print("bin version: 主版本", num[0])
        num = struct.unpack("<I", data[28:32])
        print("bin version: 子版本", num[0])

    # for item in range(0, 64, 4):
    #     num = struct.unpack("<I", data[item:item+4])
    #     print(item, num[0])
