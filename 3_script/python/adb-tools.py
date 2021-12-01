#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import argparse
import sys
import subprocess
import os

# python apk-build.py -t debug -n fx6 fx2 mk8
 
FLAVOR_MAP = {
  'fx6': "temperature",
  'fx2': "dayi",
  'mk8': "qiaojiangyun",
  'meeting': "cmz",
  'cbs': "cbs",
}

# DEFAULT_FLAVOR = ['fx6', 'fx2', 'mk8']
DEFAULT_FLAVOR = ['fx6']

class ArgParser(argparse.ArgumentParser):
  def __init__(self):
    super(ArgParser, self).__init__()

    self.add_argument(
      "-t", "--type", type=str, choices=["debug", "release", "all"], default="debug", 
      help="创建渠道包类型，测试环境debug，生产环境release，所有all"
    )

    self.add_argument(
      "-n", "--name", type=str, nargs="+", default=DEFAULT_FLAVOR, 
      help="至少选择一个渠道：['fx6', 'fx2', 'mk8']"
    )

def ex(cmd):
  print("执行：", cmd)
  subprocess.call(cmd, shell=True)

def main(args):
  apk_type = args.type
  if apk_type == "all":
    apk_type = ""
  apk_type = apk_type.strip().capitalize()
  flavor_list = args.name

  print("版本：", apk_type)
  print("渠道：", flavor_list)

  for flavor in flavor_list:
    flavorName = flavor.strip()
    flavorName = FLAVOR_MAP[flavorName].capitalize()
    ex("gradlew assemble%s%s" % (flavorName, apk_type))


if __name__ == "__main__":
    args = ArgParser().parse_args()
    if args.type != "debug":
        ex("gradlew clean")
    main(args)
    