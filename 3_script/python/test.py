#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# year = 8200 * 12
# total = 0
# for i in range(1, 31):
#     total += year
#     print(f"第{i}年, year：{year}, total:{total}")
#     year *= 0.977

import docx

doc = docx.Document("tcp_interface.docx")
cache = ""
dep = -1
index = 1
for p in doc.paragraphs:
    graph = p.text
    if len(graph) > 0:
        if graph.startswith("请求命令参数"):
            dep = 0
            continue
        if dep == 0 and graph.find("{") != -1:
            cache += graph
            dep += 1
            continue
        if dep > 0 and graph.find("}") != -1:
            cache += graph
            dep -= 1
            continue
        if dep > 0:
            cache += graph
            continue
        if graph.startswith("结果返回"):
            dep = 0
            print(index, cache)
            index += 1
            cache = ""
            continue




# with open("tcp_interface_auto.py", "w") as of:
#     cache = ""
#     for p in doc.paragraphs:
#         graph = p.text
#         if graph.startwith("请求命令参数"):
#         of.write()
#         print("----", p)

