#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import logging
import os
import time


class Log:
    def __init__(self, filename=None):
        if filename is None:
            log_name = time.strftime('%Y-%m-%d', time.localtime((time.time()))) + '.log'
            # log_path = os.path.join(os.getcwd(), "log")
            log_path = os.path.join(os.path.abspath("../.."), "log")
            if not os.path.exists(log_path):
                os.makedirs(log_path)
            filename = os.path.join(log_path, log_name)

        # 定义文件
        self.fileHandler = logging.FileHandler(filename=filename, mode='a', encoding='utf-8')
        formatter = logging.Formatter(fmt="%(asctime)s-%(levelname)s-%(name)s:  %(message)s",
                                      datefmt='%Y-%m-%d %H:%M:%S')
        self.fileHandler.setFormatter(formatter)
        self.terminalHandler = logging.StreamHandler()

    def i(self, tag="", message=""):
        logger = logging.Logger(name=tag, level=logging.INFO)
        logger.addHandler(self.terminalHandler)
        logger.addHandler(self.fileHandler)
        logger.info(msg=message)

    def d(self, tag="", message=""):
        logger = logging.Logger(name=tag, level=logging.DEBUG)
        logger.addHandler(self.terminalHandler)
        logger.addHandler(self.fileHandler)
        logger.debug(msg=message)

    def w(self, tag="", message=""):
        logger = logging.Logger(name=tag, level=logging.WARNING)
        logger.addHandler(self.terminalHandler)
        logger.addHandler(self.fileHandler)
        logger.warning(msg=message)

    def e(self, tag="", message=""):
        logger = logging.Logger(name=tag, level=logging.ERROR)
        logger.addHandler(self.terminalHandler)
        logger.addHandler(self.fileHandler)
        logger.error(msg=message)

    def exception(self, tag="", message=""):
        logger = logging.Logger(name=tag, level=logging.ERROR)
        logger.addHandler(self.terminalHandler)
        logger.addHandler(self.fileHandler)
        logger.exception(msg=message)


if __name__ == "__main__":
    log = Log()
    log.i("info", "test_info")
    log.d("debug", "test")
    log.e("Zlog", "test")
