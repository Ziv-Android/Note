#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import os
import time
import logging


class ZLog:
    # 定义多个日志文件
    def __init__(self, filename=None):
        if filename is None:
            log_name = time.strftime('%Y-%m-%d', time.localtime((time.time()))) + '.log'
            log_path = os.path.join(os.getcwd(), "log")
            if not os.path.exists(log_path):
                os.makedirs(log_path)
            filename = os.path.join(log_path, log_name)

        # 定义文件
        self.fileHandler = logging.FileHandler(filename=filename, mode='a', encoding='utf-8')
        formatter = logging.Formatter(fmt="%(asctime)s-%(levelname)s-%(name)s:  %(message)s", datefmt='%Y-%m-%d %H:%M:%S')
        self.fileHandler.setFormatter(formatter)
        self.terminalHandler = logging.StreamHandler()

    def log_info(self, tag="", message=""):
        logger = logging.Logger(name=tag, level=logging.INFO)
        logger.addHandler(self.terminalHandler)
        logger.addHandler(self.fileHandler)
        logger.info(msg=message)

    def log_debug(self, tag="", message=""):
        logger = logging.Logger(name=tag, level=logging.DEBUG)
        logger.addHandler(self.terminalHandler)
        logger.addHandler(self.fileHandler)
        logger.debug(msg=message)

    def log_warning(self, tag="", message=""):
        logger = logging.Logger(name=tag, level=logging.DEBUG)
        logger.addHandler(self.terminalHandler)
        logger.addHandler(self.fileHandler)
        logger.warning(msg=message)

    def log_error(self, tag="", message=""):
        logger = logging.Logger(name=tag, level=logging.ERROR)
        logger.addHandler(self.terminalHandler)
        logger.addHandler(self.fileHandler)
        logger.error(msg=message)

    def log_exception(self, tag="", message=""):
        logger = logging.Logger(name=tag, level=logging.ERROR)
        logger.addHandler(self.terminalHandler)
        logger.addHandler(self.fileHandler)
        logger.exception(msg=message)


if __name__ == "__main__":
    log = ZLog()
    log.log_info("info", "test_info")
    log.log_debug("debug", "test")
    log.log_error("Zlog", "test")
