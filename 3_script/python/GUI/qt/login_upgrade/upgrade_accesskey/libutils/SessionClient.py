#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import sys
import json
from urllib.parse import urlparse

import execjs
import requests
from requests_toolbelt.multipart import encoder
from .Zlog import *

# 支持admin:admin登录
user_info = '{"type": "login","module": "BUS_WEB_REQUEST","user_info": "%s"}'
device_info = '{"type":"get_hwinfo","module":"BUS_WEB_REQUEST"}'
device_info_rx = '{"type":"get_device_info"}'


class SessionClient:
    """
    :param:url 传入地址和端口(http://192.168.6.19:80)
    :param:username 用户名
    :param:password 密码
    """

    def __init__(self, host, username, password):
        self.host = host
        self.username = username
        self.password = password
        self.session = None
        self.isLogin = False  # 登录判断
        self.log = ZLog()

    # 读取aes工具文件
    def aes_file(self):
        print(sys.argv[0])
        path = os.path.join(os.getcwd(), "assets", "Aes.js")
        # path = os.path.join(os.getcwd()) + "\\libutils\\Aes.js"
        print(path)
        with open(path, 'r', encoding='utf-8') as of:
            htmlstr = of.read()
        return htmlstr

    # 生成aes加密结果
    def aes_pwd(self, user_pwd, en_key):
        js_str = self.aes_file()
        aesctr = execjs.compile(js_str)  # 加载JS文件
        decode_str = aesctr.call('AesCtr.encrypt', user_pwd, en_key, 128)
        return decode_str

    '''
    登录
    '''
    def login(self):
        if self.isLogin:
            return True

        try:
            # http://192.168.30.125:19852/02880771-fce36ba5/login.php
            # url = self.host + "/login.php"
            url = self.host + "/request.php"
            # 创建会话
            self.session = requests.session()
            # 根据请求url处理加密参数
            self.log.log_info("SessionClient", f"login request {url}")
            url_parsed = urlparse(url)
            user_pwd = '{}:{}'.format(self.username, self.password)
            if url_parsed.path.endswith("request.php"):
                login_info = user_info % self.aes_pwd(user_pwd, 'secret08')
            elif url_parsed.path.endswith("login.php"):
                login_info = self.aes_pwd(user_pwd, '天天')
            else:
                login_info = ''
            self.log.log_info("SessionClient", f"login params: {login_info}")
            # login请求
            resp = self.session.post(url=url, data=login_info, timeout=10)
            resp.encoding = 'utf-8'
            self.log.log_info("SessionClient", f"login encode: {resp.encoding}")
            self.isLogin = False
            if resp.status_code == 200:
                result = resp.content.decode(encoding="UTF-8")
                self.log.log_info("SessionClient",
                                  f"login result: code={resp.status_code}, cookies={self.session.cookies}, content={result}")

                if url_parsed.path.endswith("request.php"):
                    json_obj = json.loads(result)
                    state_code = json_obj['state']
                    if state_code == 200:
                        self.isLogin = True
                else:
                    self.isLogin = True
            else:
                self.log.log_error("SessionClient", f"login error: code={resp.status_code}")
            return self.isLogin
        except Exception as e:
            self.log.log_error("SessionClient", f"login exception: {e}")
            self.close()
            return False

    def info(self):
        self.login()
        try:
            # http://192.168.30.125:19852/02880771-fce36ba5/systemjson.php
            # url = self.host + "/systemjson.php"
            url = self.host + "/request.php"
            self.log.log_info("SessionClient", f"info request {url} {self.session.cookies}")
            self.log.log_info("SessionClient", f"info params: {device_info}")
            resp = self.session.post(url=url, data=device_info, timeout=10)
            resp.encoding = 'utf-8'
            self.log.log_info("SessionClient", f"info encode: {resp.encoding}")
            if resp.status_code == 200:
                result = resp.content.decode(encoding="UTF-8")
                self.log.log_info("SessionClient",
                                  f"info result: code={resp.status_code}, cookies={self.session.cookies}, content={result}")

                json_obj = json.loads(result)
                version = json_obj['body']['soft_ver']
            else:
                version = None
                self.log.log_error("SessionClient", f"info error: code={resp.status_code}")
            return version
        except Exception as e:
            self.log.log_error("SessionClient", f"info failed {e}")
            self.close()
            return None

    '''
    升级
    :param filename 升级文件abs路径
    :return http状态值，response数据
    '''
    def update(self, filename, callback):
        self.login()
        try:
            # http://192.168.30.127:18008/02880771-fce36ba5/upload.cgi
            # url = self.host + "/upload.cgi"
            url = self.host + "/update.php"
            name = filename.replace('\\', '/').split("/")[-1]
            self.log.log_info("SessionClient", f"update request {url} {self.session.cookies}")
            self.log.log_info("SessionClient", f"update params: {filename}, {name}")
            e = encoder.MultipartEncoder(
                fields={
                    'file': (name, open(filename, "rb"), "application/octet-stream"),
                    'filename': name,
                    "Content-Type": "application/octet-stream",
                    "Content-Disposition": "form-data",
                }
            )
            m = encoder.MultipartEncoderMonitor(e, callback)
            headers = {
                'Content-Type': e.content_type,
            }
            resp = requests.post(url, data=m, headers=headers, timeout=60)
            resp.encoding = 'utf-8'
            self.log.log_info("SessionClient", f"update encode: {resp.encoding}, {resp.elapsed.total_seconds()}")
            self.log.log_info("SessionClient", f"upload result: code={resp.status_code}, content={resp.content.decode()}")
            if resp.status_code == 200:
                result = resp.content.decode(encoding="UTF-8")
                self.log.log_info("SessionClient", f"upload success: cookies={self.session.cookies}, content={result}")
                return True
            else:
                self.log.log_error("SessionClient", f"update failed: {resp.status_code} {filename}")
                if resp.content is None:
                    result = None
                else:
                    result = resp.content.decode(encoding="UTF-8")
                self.log.log_error("SessionClient", f"update failed: {result}")
            return False
        except Exception as e:
            self.log.log_error("SessionClient", f"update exception: {filename} {e}")
            return False
        finally:
            self.close()

    # def progress_callback(self, monitor):
    #     print(round(monitor.bytes_read/monitor.len*100, 2))

    # 关闭会话并复位状态
    def close(self):
        if self.session is not None:
            self.session.close()
        self.session = None
        self.isLogin = False
