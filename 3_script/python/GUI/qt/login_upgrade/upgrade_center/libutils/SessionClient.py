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
from .ConfigManager import *

# 支持admin:admin登录
# user_info = '{"type": "login","module": "BUS_WEB_REQUEST","user_info": "%s"}'
# device_info = '{"type":"get_hwinfo","module":"BUS_WEB_REQUEST"}'
# device_info_rx = '{"type":"get_device_info"}'
url_login = ""
url_info = ""
url_upgrade = ""
url_heart_beat = "/webpage_relogin.php"

user_info = ''
device_info = ''


class SessionClient:
    HEADERS = {
        "X-Requested-With": "XMLHttpRequest",
        "Accept-Language": "en-US,en;zh-CN,zh",
        "Accept-Encoding": "gzip, deflate",
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/97.0.4692.71 Safari/537.36",
        "Connection": "Keep-Alive",
        "Cache-Control": "no-cache",
    }

    """
    :param:url 传入地址和端口(http://192.168.6.19:80)
    :param:username 用户名
    :param:password 密码
    """
    def __init__(self, host, username, password, config_path=None):
        self.host = host
        self.username = username
        self.password = password
        self.session = None
        self.config = None
        self.isLogin = False  # 登录判断
        self.log = ZLog()
        self.read_config(config_path)

    def read_config(self, path):
        global user_info, device_info, url_login, url_info, url_upgrade
        self.config = ConfigManager(path)
        try:
            user_info = self.config.get_params_user_info()
            device_info = self.config.get_params_device_info()
            url_login = self.config.get_path_login()
            url_info = self.config.get_path_info()
            url_upgrade = self.config.get_path_upgrade()
        except Exception as e:
            print("SessionClient read_config exception", e)
        finally:
            del self.config

    # 读取aes工具文件
    def aes_file(self):
        print(sys.argv[0])
        path = os.path.join(os.getcwd(), "assets", "Aes.js")
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
            global url_login
            # http://192.168.30.125:19852/02880771-fce36ba5/login.php
            # url = self.host + "/login.php"
            url = self.host + url_login
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
            resp = self.session.post(url=url, data=login_info, timeout=10, headers=self.HEADERS)
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
            global url_info
            # http://192.168.30.125:19852/02880771-fce36ba5/systemjson.php
            # url = self.host + "/systemjson.php"
            url = self.host + url_info
            self.log.log_info("SessionClient", f"info request {url} {self.session.cookies}")
            self.log.log_info("SessionClient", f"info params: {device_info}")
            resp = self.session.post(url=url, data=device_info, timeout=10, headers=self.HEADERS)
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
            global url_upgrade
            # http://192.168.30.127:18008/02880771-fce36ba5/upload.cgi
            # url = self.host + "/upload.cgi"
            url = self.host + url_upgrade
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
            headers = self.HEADERS
            headers['Content-Type'] = e.content_type
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

    def send_heart_beat(self):
        self.login()
        try:
            global url_heart_beat
            # http://192.168.30.125:19852/02880771-fce36ba5/systemjson.php
            # url = self.host + "/webpage_relogin.php"
            url = self.host + url_heart_beat
            self.log.log_info("SessionClient", f"heart_beat request {url} {self.session.cookies}")
            resp = self.session.post(url=url, data="", timeout=10, headers=self.HEADERS)
            resp.encoding = 'utf-8'
            self.log.log_info("SessionClient", f"heart_beat encode: {resp.encoding}")
            if resp.status_code == 200:
                result = resp.content.decode(encoding="UTF-8")
                self.log.log_info("SessionClient",
                                  f"info result: code={resp.status_code}, cookies={self.session.cookies}, content={result}")

        except Exception as e:
            self.log.log_error("SessionClient", f"info failed {e}")

    # 关闭会话并复位状态
    def close(self):
        if self.session is not None:
            self.session.close()
        self.session = None
        self.isLogin = False
