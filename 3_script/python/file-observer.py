# !/usr/bin/env python
# -*- coding=utf-8 -*-


pos = 0
while True:
    try:
        with open("a.txt", "r") as of:
            if pos != 0:
                of.seek(pos, 0)
            while True:
                line = of.readline()
                line_strip = line.strip()
                if line_strip:
                    print(line_strip)
                    pos = pos + len(line)
                else:
                    break
    except Exception as e:
        with open("a.txt", "w") as wf:
            print("create a.txt file")

