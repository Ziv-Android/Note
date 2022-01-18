#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import json
import requests
import os
import re
import time
import random

'''
#encoding='utf-8'
Author:Mr.Pan_学狂
start_time:2021/4/23/18:30
finish_time:2021/4/23/21:50
用requests库
实现json数据的爬取，存储json数据，
读取json数据，提取标题和图片
'''


class Json_Process:
    def __init__(self):
        self.Json_data = ''  # 设置一个空字符串
        self.headers = {

            'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.132 Safari/537.36 QIHU 360SE'
        }

    def spyder(self):  # 定义一个爬虫函数
        url = 'https://node.video.qq.com/x/api/wuji_cache/object?appid=detail_page_conf&schemaid=t_detail_vid_next&schemakey=e4755c269167488797f1acbef5c6b053&size=total&filter=c_is_valid%3Dtrue'
        response = requests.get(url, headers=self.headers, verify=False)  # 传入参数url地址，请求头headers,证书为False
        response.encoding = 'utf-8'  # 以utf-8的方式编码
        self.Json_data = response.json()  # 以字典格式返回
        print(self.Json_data)#打印数据
        # print(type(self.Json_data))#查看数据类型
        # print(self.Json_data['data'])

    def Json_storage(self):
        pass
        # if os.path.exists('G:/Json'):  # 若路径存在执行追加写
        #     with open('G:/Json/综艺节目.json', 'a+', encoding='utf-8') as f:
        #         json.dump(self.Json_data, f, indent=0)
        # else:  # 否则
        #     os.mkdir('G:/Json')  # 创建Json文件夹
        #     with open('G:/Json/综艺节目.json', 'a+', encoding='utf-8') as f:
        #         json.dump(self.Json_data, f, indent=0)

    def read_file(self):  # 定义一个读取文件的函数
        pass
        # with open('G:/Json/综艺节目.json', 'r+', encoding='utf-8') as f:
        #     file = f.read()  # 读取全部内容
        # json_data = json.loads(file)  # 加载内容
        # # print(json_data)
        # Data_ls = json_data['data']  # 取出data对应的值，是list列表类型
        # title_dt = {
        # }  # 定义一个空字典，用于存储标题和对应的图片链接
        # for D in Data_ls:
        #     try:  # 加入异常处理机制，使不满足条件的时候跳过，而不报错。
        #         if type(D) is dict:
        #             title_dt[D['c_next_title']] = D['c_next_imgurl']
        #             '''
        #             将字典的c_next_title值设置为空字典title_dt的键，
        #             字典的c_next_imgurl对应空字典title_dt的值。
        #             相当于是标题对应图片链接。
        #             '''
        #     except Exception:  # 出现异常的时候，跳过
        #         continue
        # # print(title_dt)#打印字典
        # return title_dt
        # # print(type(json_data))

    def get_img_and_save_file(self):
        pass
        # img_dt = Json_Process.read_file(self)  # 调用函数，接收返回值
        # # print(img_dt)
        #
        # if os.path.exists('G:/images'):  # 如果存在存在这个路径，则执行执行追加写入
        #     for img_name in img_dt:
        #         img_url = img_dt[img_name]  # 从字典中获取图片的地址
        #         img = requests.get(img_url, headers=self.headers, verify=False)
        #         with open('G:/images/{}.jpg'.format(img_name), 'wb+') as f:
        #             f.write(img.content)
        #
        # else:  # 否则，执行创建文件夹，并追加写入
        #     os.mkdir('G:/images')  # 创建一个文件夹，用于存储image图片
        #     for img_name in img_dt:
        #         img_url = img_dt[img_name]  # 从字典中获取图片的地址
        #         img = requests.get(img_url, headers=self.headers, verify=False)
        #         with open('G:/images/{}.jpg'.format(img_name), 'wb+') as f:  # 图片是以二进制的形式写入
        #             f.write(img.content)  # 获取图片内容


if __name__ == '__main__':
    JP = Json_Process()  # 实例化对象
    JP.spyder()  # 调用函数
    JP.Json_storage()  # 存储json数据
    JP.read_file()  # 读取json文件，提取图片
    JP.get_img_and_save_file()  # 获取图片以及保存图片
