#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import os
import configparser


class ConfigProduct:
    def __init__(self, path):
        self.cfg = configparser.ConfigParser()

        self.is_ok = False
        if os.path.exists(path) == False:
            print('%s 文件不存在,打开失败' % path)
            return
        try:
            b = self.cfg.read(path, encoding='utf-8-sig')
            if b:
                self.is_ok = True
                print(self.get_desc())
        except:
            print('%s 文件格式不能被解析,打开失败' % path)

    def is_init(self):
        return self.is_ok

    def get_desc(self):
        return self.cfg['info']['desc']

    def get_board_version(self):
        return self.cfg['info']['bv']

    def get_image_path(self):
        return self.cfg['info']['path']

    def get_capacity(self):
        return self.cfg.items('capacity')

    def get_capacity_num(self, option):
        try:
            if self.cfg.has_option('capacity', option):
                return self.cfg.getint('capacity', option)
        except:
            print('get_capacity_num failed %s' % option)
        return -1

    def get_capacity_str(self, option):
        try:
            if self.cfg.has_option('capacity', option):
                return self.cfg.get('capacity', option)
        except:
            print('get_capacity_str failed %s' % option)
        return None
