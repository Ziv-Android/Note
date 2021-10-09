#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
gif图合成
"""

import os
import imageio


def analyse_path(path):
    result = []
    files = os.listdir(path)
    for file in files:
        if not os.path.isdir(file):
            result.append(file)
    return result


def create_image(path):
    img_list = analyse_path(path)
    gif_name = "".join(os.path.basename(path))
    # print(gif_name, img_list)
    frames = []
    for img_name in img_list:
        frames.append(imageio.imread(path + "/" + img_name))

    imageio.mimsave(("%s.gif" % gif_name), frames, 'GIF', duration=0.1)
    return


def main():
    path = '20170824200309749'
    print(path)
    create_image(path)


if __name__ == '__main__':
    main()
