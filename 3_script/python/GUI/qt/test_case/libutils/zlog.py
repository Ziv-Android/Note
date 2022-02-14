#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import os
import logging


class ZLog:
    # 定义多个日志文件
    def __init__(self, filename=None):
        self.filename = 'log.txt'
        if filename != None:
            self.filename = filename
        # 定义文件
        self.filehandle = logging.FileHandler(filename=self.filename, mode='a', encoding='utf-8')
        fmt = logging.Formatter(fmt="%(asctime)s-%(levelname)s-%(name)s:  %(message)s", datefmt='%Y-%m-%d %H:%M:%S')
        self.filehandle.setFormatter(fmt)

    def log_err(self, message='', name='', write=True):
        # 定义日志
        log_name = ''
        if name != '':
            log_name = name
        loggerhandle = logging.Logger(name=log_name, level=logging.ERROR)
        loggerhandle.addHandler(self.filehandle)
        # 写日志
        if write != True:
            return
        loggerhandle.error(msg=message)

    def log_info(self, message='', name='', write=True):
        # 定义日志
        log_name = ''
        if name != '':
            log_name = name
        loggerhandle = logging.Logger(name=log_name, level=logging.INFO)
        loggerhandle.addHandler(self.filehandle)
        # 写日志
        if write != True:
            return
        loggerhandle.info(msg=message)

    def log_debug(self, message='', name='', write=True):
        # 定义日志
        log_name = ''
        if name != '':
            log_name = name
        loggerhandle = logging.Logger(name=log_name, level=logging.DEBUG)
        loggerhandle.addHandler(self.filehandle)
        # 写日志
        if write != True:
            return
        loggerhandle.debug(msg=message)