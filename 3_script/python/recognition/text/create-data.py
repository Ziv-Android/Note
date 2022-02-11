#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import os
import shutil
import time
from PIL import Image
from PIL import ImageFont
from PIL import ImageDraw

# 字体库路径
font_dir = "./fonts"
# 要生成的文本
label_dict = {0: '0', 1: '1', 2: '2', 3: '3', 4: '4', 5: '5', 6: '6', 7: '7', 8: '8', 9: '9', 10: '=', 11: '+', 12: '-',
              13: '×', 14: '÷'}

for key, val in label_dict.items():
    train_images_dir = "dataset" + "/" + str(key)
    if os.path.isdir(train_images_dir):
        shutil.rmtree(train_images_dir)
    os.makedirs(train_images_dir)


def make_image(labels, font_path, width=24, height=24, rotate=0):
    for value, char in labels.items():
        # 创建一个黑色背景的图片，大小是24*24
        img = Image.new("RGB", (width, height), "black")
        draw = ImageDraw.Draw(img)
        # 加载一种字体,字体大小是图片宽度的90%
        font = ImageFont.truetype(font_path, int(width * 0.9))
        # 获取字体的宽高
        font_width, font_height = draw.textsize(char, font)
        # 计算字体绘制的x,y坐标，主要是让文字画在图标中心
        x = (width - font_width - font.getoffset(char)[0]) / 2
        y = (height - font_height - font.getoffset(char)[1]) / 2
        # 绘制图片，在那里画，画啥，什么颜色，什么字体
        draw.text((x, y), char, (255, 255, 255), font)
        # 设置图片倾斜角度
        img = img.rotate(rotate)
        # 命名文件保存，命名规则：dataset/编号/img-编号_r-选择角度_时间戳.png
        time_value = int(round(time.time() * 1000))
        head, tail = os.path.split(font_path)
        img_path = "dataset/{}/img-{}_r-{}_{}.png".format(value, tail[:-4], rotate, time_value)
        img.save(img_path)


# 遍历字体
for font_name in os.listdir(font_dir):
    path_font_file = os.path.join(font_dir, font_name)
    # 遍历角度-10到10
    for i in range(1, 2):
        for r in range(-10, 10, 1):
            # 生成图片
            make_image(label_dict, path_font_file, rotate=r)
