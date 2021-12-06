#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import csv


data = []

for i in range(100):
    data.append(["请输入序列号", "", "", ""])

print(len(data))
data = list(filter(lambda item: item[0].isnumeric() == True, data))
print(data)
data.append(["123", "", "", ""])
data.append(["123", "2", "2", ""])
data.append(["123", "1", "2", ""])
data.append(["321", "1", "2", ""])


data = ["123", "123", "321"]
data = list(set(data))
print(data)
data.sort()
print(data)

with open("GUI/qt/login_upgrade/src/template.csv", 'w', encoding='utf-8') as openf:
    csv_write = csv.writer(openf)
    csv_head = ["序列号"]
    csv_write.writerow(csv_head)
