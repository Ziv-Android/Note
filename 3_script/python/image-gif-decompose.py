#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
gif图分解
"""

import os
from PIL import Image


def analyse_image(path):
    im = Image.open(path)
    results = {
        'size': im.size,
        'mode': 'full',
    }
    try:
        while True:
            if im.tile:
                title = im.tile[0]
                update_region = title[1]
                update_region_dimensions = update_region[2:]
                if update_region_dimensions != im.size:
                    results['mode'] = 'partial'
                    break
            im.seek(im.tell() + 1)
    except EOFError:
        pass
    return results


def process_image(path):
    mode = analyse_image(path)['mode']
    im = Image.open(path)

    i = 0
    p = im.getpalette()
    last_frame = im.convert('RGBA')

    try:
        file_name = "".join(os.path.basename(path).split('.')[:-1])
        if not os.path.exists(file_name):
            os.makedirs(file_name)
            print('create %s path' % file_name)

        while True:
            print("saving %s (%s) frame %d, %s %s" % (path, mode, i, im.size, im.tile))
            if not im.getpalette():
                im.putpalette(p)

            new_frame = Image.new('RGBA', im.size)

            if mode == 'partial':
                new_frame.paste(last_frame)

            new_frame.paste(im, (0, 0), im.convert('RGBA'))
            new_frame.save("%s/%s-%d.png" % (file_name, file_name, i), "PNG")

            i += 1
            last_frame = new_frame
            im.seek(im.tell() + 1)
    except EOFError:
        pass


def main():
    path = 'assets/20170824200309749.gif'
    print(path)
    process_image(path)


if __name__ == '__main__':
    main()
