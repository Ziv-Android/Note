#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import subprocess
import sys, getopt

def ex(cmd):
  print("执行：", cmd)
  subprocess.call(cmd, shell=True)

def checkConnect():
    ex("adb devices")

def main(argv):
    # try:
    #     opts, args = getopt.getopt(args, "", [])
    #     print(opts, args)
    # except getopt.GetoptError:
    #     sys.exit(2)

    print("PicName:", argv)
    ex("adb shell screencap -p /sdcard/%s.png" % argv[0])
    ex("adb pull /sdcard/%s.png ." % argv[0])
    ex("adb shell rm /sdcard/%s.png" % argv[0])


if __name__ == "__main__":
    main(sys.argv[1:])
    