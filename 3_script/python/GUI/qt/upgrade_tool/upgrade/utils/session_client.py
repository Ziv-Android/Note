# -*- coding: utf-8 -*-

import os
import json
from urllib.parse import urlparse

import execjs
import requests
from requests_toolbelt.multipart import encoder
from log import Log

# 支持admin:admin登录
user_info = '{"type": "login","module": "BUS_WEB_REQUEST","user_info": "%s"}'
device_info = '{"type":"get_hwinfo","module":"BUS_WEB_REQUEST"}'


# 读取aes工具文件
def read_aes_file():
    path = os.path.join(os.path.abspath('../..'), "assets", "Aes.js")
    # path = os.path.join(os.getcwd()) + "\\assets\\Aes.js"
    print("read_aes_file:", path)

    # 打开JS文件
    with open(path, 'r', encoding='utf-8') as of:
        aes_script = of.read()

    return aes_script


# 生成aes加密结果
def aes_pwd(user_pwd, en_key):
    js_context = execjs.compile(read_aes_file())  # 加载JS文件
    decode_str = js_context.call('AesCtr.encrypt', user_pwd, en_key, 128)
    return decode_str


class SessionClient:
    """
    :param:host 请求接口host
    :param:username 用户名
    :param:password 密码
    """
    def __init__(self, host, username, password):
        self.host = host
        self.username = username
        self.password = password
        self.session = None
        self.isLogin = False  # 登录判断
        self.log = Log()

    def __del__(self):
        self.close()

    # 登录
    def login(self):
        if self.isLogin:
            return
        try:
            url = self.host + "/request.php"
            # 创建会话
            self.session = requests.session()
            # 根据请求url处理加密参数
            self.log.i("SessionClient", f"login request {url}")
            url_parsed = urlparse(url)
            user_pwd = '{}:{}'.format(self.username, self.password)
            if url_parsed.path.endswith("request.php"):
                login_info = user_info % aes_pwd(user_pwd, 'secret08')
            elif url_parsed.path.endswith("login.php"):
                login_info = aes_pwd(user_pwd, '天天')
            else:
                login_info = ''
            self.log.i("SessionClient", f"login params: {login_info}")
            # login请求
            resp = self.session.post(url=url, data=login_info, timeout=10)
            self.log.i("SessionClient", f"login encode: {resp.encoding}")
            self.isLogin = False
            if resp.status_code == 200:
                resp.encoding = 'utf-8'
                result = resp.content.decode(encoding="UTF-8")
                self.log.i("SessionClient",
                           f"login result: code={resp.status_code}, cookies={self.session.cookies}, content={result}")
                if len(result) > 0:
                    json_obj = json.loads(result)
                    state_code = json_obj['state']
                    if state_code == 200:
                        self.isLogin = True
            else:
                self.log.e("SessionClient", f"login error: code={resp.status_code}")
            return self.isLogin
        except Exception as e:
            self.log.e("SessionClient", f"login exception: {e}")
            self.close()
            return False

    # 获取设备信息
    def info(self):
        self.login()
        try:
            url = self.host + "/request.php"
            self.log.i("SessionClient", f"info request {url} {self.session.cookies}")
            self.log.i("SessionClient", f"info params: {device_info}")
            resp = self.session.post(url=url, data=device_info, timeout=10)
            self.log.i("SessionClient", f"info encode: {resp.encoding}")
            resp.encoding = 'utf-8'
            if resp.status_code == 200:
                result = resp.content.decode(encoding="UTF-8")
                self.log.i("SessionClient",
                           f"info result: code={resp.status_code}, cookies={self.session.cookies}, content={result}")
            else:
                result = None
                self.log.e("SessionClient", f"info error: code={resp.status_code}")
            return result
        except Exception as e:
            self.log.e("SessionClient", f"info failed {e}")
            self.close()
            return None

    # 升级
    def update(self, filename, callback):
        self.login()
        try:
            url = self.host + "/update.php"
            name = filename.replace('\\', '/').split("/")[-1]
            self.log.i("SessionClient", f"update request {url} {self.session.cookies}")
            self.log.i("SessionClient", f"update params: {filename}, {name}")
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
            resp = self.session.post(url, data=m, headers=headers, timeout=60)
            self.log.i("SessionClient", f"update encode: {resp.encoding}")
            resp.encoding = 'utf-8'
            if resp.status_code == 200:
                result = resp.content.decode(encoding="UTF-8")
                self.log.i("SessionClient",
                           f"upload result: code={resp.status_code}, cookies={self.session.cookies}, content={result}")
            else:
                self.log.e("SessionClient", f"update failed: {resp.status_code} {filename}")
                if resp.content is None:
                    result = None
                else:
                    result = resp.content.decode(encoding="UTF-8")
                self.log.e("SessionClient", f"update failed: {result}")
            return resp.status_code, result
        except Exception as e:
            self.log.e("SessionClient", f"update exception: {filename} {e}")
            return 404, None
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
