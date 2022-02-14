#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import os
import os.path
import re

root_dir = './'
extern_list = ["docxcompose", "lib3rd", "libutils", "product"]
extern_item_format = lambda x: f'("..\\\\{x}", "{x}")'


# 列出目录下的所有UI文件
def listUiFile():
    lists = []
    # files = os.listdir(ui_dir)
    # for filename in files:
    #     # print(ui_dir + os.sep + filename)
    #     if os.path.splitext(filename)[1] == '.ui':
    #         lists.append(filename)

    return lists


def transPyFile(filename):
    return os.path.splitext(filename)[0] + '.py'


def runMain():
    # create spec file
    os.system("pyi-makespec oqc_app.py")
    # add extern file config
    with open("oqc_app.spec", "r", encoding='utf-8') as rf:
        file_content = rf.readlines()
        for i in range(len(file_content)):
            line = file_content[i].strip()
            if line.startswith("datas=["):
                data = []
                for extern in extern_list:
                    item = extern_item_format(extern)
                    if item not in data:
                        data.append(item)

                line = ", ".join(data)
                line = f"\t\t\t datas=[{line}],\n"
                print("add line:", line)
                break

    with open("oqc_app.spec", "w", encoding='utf-8') as wf:
        wf.writelines(file_content)
    # lists = listUiFile()
    # for uifile in lists:
    #     pyfile = transPyFile(uifile)
    #     cmd = 'pyuic5 -o ui_{pyfile} {uifile}'.format(pyfile=pyfile, uifile=uifile)
    #     print(cmd)
    #     os.system(cmd)


if __name__ == '__main__':
    runMain()
