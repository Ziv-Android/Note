# !/usr/bin/env python
# -*- coding=utf-8 -*-

import os
import datetime
import logging
try:
    import pyinotify
except Exception as e:
    print("import error:", e)

'''
https://www.cnblogs.com/ygbh/articles/12218534.html
注：pyinotify依赖于Linux内核inotify功能。inotify是一个事件驱动的通知器，其通知接口从内核空间到用户空间通过三个系统调用。
pyinotify结合这些系统调用，并提供一个顶级的抽象和一个通用的方式来处理这些功能，并且只有在Linux内核2.6.13以后支持inotify的功能

IN_ACCESS         # 文件被读取
IN_MODIFY         # 文件被修改
IN_ATTRIB         # 元数据被修改
IN_CLOSE_WRITE    # 打开且等待写入的文件或目录被关闭
IN_CLOSE_NOWRITE  # 只读方式打开文件或目录被关闭
IN_OPEN           # 文件或目录被打开
IN_MOVED_FROM     # 监控的目录中的条目被移出监控区域
IN_MOVED_TO       # 目录或文件被移入监控区域
IN_CREATE         # 在被监控目录中创建了子目录或文件
IN_DELETE         # 被监控目录中有子目录或文件被删除
IN_CLOSE          # 文件被关闭，等同于IN_CLOSE_WRITE
IN_MOVED          # 文件被移动，等同于IN_MOVED_FROM
'''

pos = 0


def printlog():
    global pos
    try:
        fd = open("log/a.txt")
        if pos != 0:
            fd.seek(pos, 0)
            while True:
                line = fd.readline()
                if line.strip():
                    print(line.strip())
                pos = pos + len(line)
                if not line.strip():
                    break
            fd.close()
    except Exception as e:
        print(e)


class MyEventHandler(pyinotify.ProcessEvent):
    def process_IN_MODIFY(self, event):
        try:
            printlog()
        except Exception as e:
            print(e)


def main():
    printlog()
    wm = pyinotify.WatchManager()
    wm.add_watch("log/a.txt", pyinotify.ALL_EVENTS, rec=True)
    eh = MyEventHandler()
    notifier = pyinotify.Notifier(wm, eh)
    notifier.loop()


if __name__ == "__main__":
    main()
