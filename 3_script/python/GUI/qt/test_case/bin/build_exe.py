#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
使用Python调用命令，通过spec文件完成打包PyQt，删除没用的文件并压缩为zip功能

环境需求：window环境，pyinstaller打包，7-Zip压缩
"""
import os.path
import subprocess
import sys


def ex(cmd):
    print("ex", cmd)
    subprocess.call(cmd, shell=True)


def clear_no_use_file():
    path_oqc_app = os.path.join(os.getcwd(), 'dist', 'oqc_app')
    print(path_oqc_app)
    try:
        ex(f"del {path_oqc_app}\\libopenblas.*")
    except:
        print('libopenblas 文件不存在或已删除')

    if os.path.exists(os.path.join(path_oqc_app, 'opengl32sw.dll')):
        ex(f"del {path_oqc_app}\\opengl32sw.dll")

    path_vzsdk = os.path.join(os.getcwd(), 'dist', 'oqc_app', 'lib3rd', 'vzsdk')
    print(path_vzsdk)
    if os.path.exists(os.path.join(path_vzsdk, 'inc')):
        ex(f"rmdir /s/q {path_vzsdk}\\inc")
    if os.path.exists(os.path.join(path_vzsdk, 'Fonts')):
        ex(f"rmdir /s/q {path_vzsdk}\\Fonts")
    files = os.listdir(path_vzsdk)
    for f in files:
        if f.endswith('.dll'):
            continue
        else:
            ex(f"del {path_vzsdk}\\{f}")

    path_libutils = os.path.join(os.getcwd(), 'dist', 'oqc_app', 'libutils')
    print(path_libutils)
    if os.path.exists(os.path.join(path_libutils, '__pycache__')):
        ex(f"rmdir /s/q {path_libutils}\\__pycache__")
    files = os.listdir(path_libutils)
    print(files)
    for f in files:
        if f.endswith('.py'):
            ex(f"del {path_libutils}\\{f}")
        else:
            continue


def py_to_exe(version=""):
    # 打包exe文件
    ex(r"pyinstaller oqc_app.spec --clean --noconfirm")

    # 清理不需要的文件
    clear_no_use_file()

    # 删除上一次的同名压缩zip包
    ex(f"del oqc_app_temp.zip oqc_app({version}).zip")

    # 压缩zip包
    ex(r"D:\7-Zip\7z.exe a oqc_app_temp.zip .\dist\oqc_app\*")

    # 修改zip文件名
    ex(f"rename oqc_app_temp.zip oqc_app({version}).zip")

    # 打开目标文件夹
    os.startfile(os.getcwd())


if __name__ == '__main__':
    params = sys.argv
    version = None
    if len(params) >= 2:
        version = str(sys.argv[1])
    py_to_exe(version)
