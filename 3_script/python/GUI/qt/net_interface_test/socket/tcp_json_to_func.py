#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import json

import docx


class JsonToFunc:
    def __init__(self, cmd_file):
        self.cmd_file = cmd_file

        self.cmd_note = ""
        self.cmd_cache = ""

        self.cmd = ""
        self.func_name = ""
        self.func_name_sub = ""
        self.func_params = []
        self.func_body = ""
        self.func_end = ""

        self.readDocFile()

    def reset(self):
        self.cmd_note = ""
        self.cmd_cache = ""

        self.cmd = ""
        self.func_name = ""
        self.func_name_sub = ""
        self.func_params = []
        self.func_body = ""
        self.func_end = ""

    # 从word中提取json命令
    def readDocFile(self):
        dep = -1
        index = 1
        doc = docx.Document(self.cmd_file)
        # 覆盖写
        with open("tcp_interface_auto_func.txt", "w", encoding="utf-8") as of:
            for p in doc.paragraphs:
                graph = p.text
                # print(graph)
                if len(graph) > 0:
                    if graph.startswith("请求命令参数"):
                        dep = 0
                        print(self.cmd_note)
                        # print(graph)
                        continue
                    if dep >= 0:
                        self.cmd_cache += graph
                        json_start = graph.count("{")
                        json_end = graph.count("}")
                        dep = dep + json_start - json_end
                        # print(dep, graph)
                        if dep == 0:
                            self.cmd_cache = self.cmd_cache.replace("”", "\"").replace("“", "\"").replace(" ", "").replace("\t", "")

                            print(self.cmd_note)
                            print(index, self.cmd_cache)
                            try:
                                self.json_parser("", json.loads(self.cmd_cache))
                            except Exception as e:
                                print("json exception", e, self.cmd_cache)
                            func = self.create_function(self.cmd_cache)

                            of.write(func)
                            of.write('\n')

                            dep = -1
                            self.reset()
                            index += 1
                        continue
                    self.cmd_note = graph

    def json_parser(self, root, json_obj):
        if isinstance(json_obj, dict):
            print("dict:", len(json_obj), root, json_obj)
            for key, value in json_obj.items():
                if key == "id":
                    continue
                elif key == "cmd":
                    self.func_name = value
                    self.cmd = value
                    if self.func_name.startswith("get"):
                        self.func_end = "return data"
                elif key in ["type", "operator_type", "alg_prm_type", "sucmd", "sub_cmd"]:
                    self.func_name_sub = value
                else:
                    self.json_parser(key, value)
        elif isinstance(json_obj, list):
            print("list:", len(json_obj), root, json_obj)
            self.func_params.append(root)
            # for item in json_obj:
            #     json_parser(root, item)
        else:
            self.func_params.append(root)
            print("value:", root, json_obj)

    def create_function(self, cmd_json):
        if self.func_name_sub != "":
            self.func_name = f"{self.func_name}_{self.func_name_sub}"
        return f'''
    def {self.func_name}(self, cmd_string_data=None):
        """
        {self.cmd_note}
        :return:
        """
        if cmd_string_data is None:
            cmd_string_data = '{cmd_json}'
        data = self.tcp_send_msg_base(cmd_string_data)[0]
        assert data.get('cmd') == '{self.cmd}'
        assert data.get('state_code') == 200
        {self.func_end}
        '''


JsonToFunc("tcp_interface.docx")
