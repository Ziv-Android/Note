#!/usr/bin/env python3
# -*- coding: utf-8 -*-

list_old = ['0e7316e2-2d50efd1_渝A21A3V_6792_1647564679.mp4', ]
list_new = ['0e7316e2-2d50efd1_渝A21A3V_6792_1647564679.mp4']

# 差集（new对应old）
diff = list(set(list_new).difference(set(list_old)))

# 并集
diff = list(set(list_new).union(set(list_old)))

diff = list(set(list_new).intersection(set(list_old)))


print(len(diff), diff)
