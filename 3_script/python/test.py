#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# year = 8200 * 12
# total = 0
# for i in range(1, 31):
#     total += year
#     print(f"第{i}年, year：{year}, total:{total}")
#     year *= 0.977
import json

import docx

doc = docx.Document("tcp_interface.docx")
last_line = ""

cache = ""
dep = -1
index = 1
# 数据提取
# for p in doc.paragraphs:
#     graph = p.text
#     # print(graph)
#     if len(graph) > 0:
#         if graph.startswith("请求命令参数"):
#             dep = 0
#             print(last_line)
#             # print(graph)
#             continue
#         if dep >= 0:
#             cache += graph
#             json_start = graph.count("{")
#             json_end = graph.count("}")
#             dep = dep + json_start - json_end
#             # print(dep, graph)
#             if dep == 0:
#                 cache = cache.replace("”", "\"").replace(" ", "").replace("\t", "")
#                 print(index, cache)
#                 dep = -1
#                 cache = ""
#                 index += 1
#             continue
#         last_line = graph

# 暂存文件
# with open("tcp_interface_auto_cmd.txt", "w") as of:
#     for p in doc.paragraphs:
#         graph = p.text
#         # print(graph)
#         if len(graph) > 0:
#             if graph.startswith("请求命令参数"):
#                 dep = 0
#                 print(last_line)
#                 # print(graph)
#                 continue
#             if dep >= 0:
#                 cache += graph
#                 json_start = graph.count("{")
#                 json_end = graph.count("}")
#                 dep = dep + json_start - json_end
#                 # print(dep, graph)
#                 if dep == 0:
#                     cache = cache.replace("”", "\"").replace(" ", "").replace("\t", "")
#                     of.write(cache)
#                     print(index, cache)
#                     of.write('\n')
#                     dep = -1
#                     cache = ""
#                     index += 1
#                 continue
#             last_line = graph

cmd = '{"body":{"recognition_area":{"polygon_num":1,"polygon":[{"id":1,"enable":true,"point_num":4,"point":[{"x":4096,"y":4096},{"x":12288,"y":4096},{"x":13926,"y":13926},{"x":2457,"y":13926}]}]}},"cmd":"set_reco_para","id":"132156"}'

def json_parse(json_obj):
    if isinstance(json_obj, dict):
        for key, value in json_obj.items():
            if isinstance(value, (dict, list)):
                json_parse(value)
            else:
                pass
    elif isinstance(json_obj, list):
        for i in range(len(json_obj)):
            v = json_obj[i]
            if isinstance(v, (dict, list)):
                json_parse(v)
            else:
                pass

try:
    jl = json.loads(cmd)
    if isinstance(jl, dict):
        for key, value in jl.items():
            if key == "id":
                continue
            elif key == "cmd":
                pass
            else:
                if isinstance(value, list):
                    pass
                elif isinstance(value, str):
                    pass
                elif isinstance(value, (int, float)):
                    pass
                elif isinstance(value, bool):
                    pass
                else:
                    pass

except Exception as e:
    print(e)
