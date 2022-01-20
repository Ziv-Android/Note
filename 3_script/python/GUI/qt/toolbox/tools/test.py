#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import sys

mode_base = ["ECB", "CBC", "CFB", "OFB", "CTR", "OPENPGP"]
mode_aes = [*mode_base, "CCM", "EAX", "SIV", "GCM", "OCB"]
mode_other = [*mode_base, "EAX"]

print(mode_aes)
print(mode_other)


class Object:
    def create(self):
        print(f'当前类名称：{self.__class__.__name__}')
        print(f"当前方法名：{sys._getframe().f_code.co_name}")


o = Object()
o.create()

