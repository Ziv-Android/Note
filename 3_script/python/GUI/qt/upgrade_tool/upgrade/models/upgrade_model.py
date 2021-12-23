#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import pandas
import os

path_config = os.path.join(os.path.abspath('../..'), "config")
if not os.path.exists(path_config):
    os.makedirs(path_config)
filename = os.path.join(path_config, "template.csv")

df = pandas.read_csv(filename)
print(df)


# https://blog.csdn.net/islinyoubiao/article/details/105577081