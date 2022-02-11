#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import sys
import json
from urllib.parse import urlparse

import execjs
import requests
from requests_toolbelt.multipart import encoder

# 支持admin:admin登录
url_login = "/login.php"
user_info = '{"type": "login","module": "BUS_WEB_REQUEST","user_info": "%s"}'

url_info = "/systemjson.php"
# device_info = '{"type":"get_hwinfo","module":"BUS_WEB_REQUEST"}'
net_and_port = '{"type":"get_net_and_port"}'
dev_name = '{"type":"ss_get_devname"}'
device_info = '{"type":"get_device_info"}'
ntp_cfg = '{"type":"ss_get_ntp_cfg"}'

avs_json = "avsjson.php"
# 虚拟线圈和识别区域设置参数
set_virloop_prm = '{"type":"AVS_SET_VIRLOOP_PRM","body":{"virtualloop":{"max_plate_width":400,"min_plate_width":45,"dir":0,"trigger_gap":10,"loop":[{"enable":true,"point_num":4,"point":[{"x":2398,"y":12005},{"x":13985,"y":12005},{"x":15975,"y":13982},{"x":408,"y":13982}]}],"virtualloop_num":1}}}'
set_reco_prm = '{"type":"AVS_SET_RECO_PRM","body":{"recognition_area":{"polygon":[{"enable":true,"point_num":4,"point":[{"x":1279,"y":2401},{"x":15051,"y":2401},{"x":16135,"y":15924},{"x":195,"y":15924}]}],"polygon_num":1}}}'
# 获取
'{"type":"AVS_GET_CAPTURE_PRM"}'
'{"type":"AVS_GET_ALG_RESULT_PROP"}'
'{"type":"get_new_energy_plate_support"}'
'{"type":"get_car_info_support"}'
'{"type":"AVS_GET_ALG_RESULT_PARAM"}'

request_page = "/request.php"
'{"type":"evs_get_gpioin_func","module":"EVS_BUS_REQUEST"}'
'{"type":"get_live_stream_type","module":"BUS_WEB_REQUEST"}'
'{"type":"evs_get_gpioin_func","module":"EVS_BUS_REQUEST"}'
'{"type":"get_ws_stream_cfg","module":"BUS_WEB_REQUEST"}'
'{"type":"get_onenet_prm","module":"ONENET_REQUEST_MSG"}'
''
''
dboprnew = "/dboprnew.php"
'{"type":"get_wl_fuzzy"}'
'{"type":"get_wl_check_status"}'
''
''
''
''
''
''
''
''
''
''
''
''
''
''
''
''
''
''
''
''
''
''
''
''
''
''

url_upgrade = "/upload.cgi"


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
            print("SessionClient", f"login request {url}")
            url_parsed = urlparse(url)
            user_pwd = '{}:{}'.format(self.username, self.password)
            if url_parsed.path.endswith("request.php"):
                login_info = user_info % self.aes_pwd(user_pwd, 'secret08')
            elif url_parsed.path.endswith("login.php"):
                login_info = self.aes_pwd(user_pwd, '天天')
            else:
                login_info = ''
            print("SessionClient", f"login params: {login_info}")
            # login请求
            resp = self.session.post(url=url, data=login_info, timeout=10, headers=self.HEADERS)
            resp.encoding = 'utf-8'
            print("SessionClient", f"login encode: {resp.encoding}")
            self.isLogin = False
            if resp.status_code == 200:
                result = resp.content.decode(encoding="UTF-8")
                print("SessionClient",
                                  f"login result: code={resp.status_code}, cookies={self.session.cookies}, content={result}")

                if url_parsed.path.endswith("request.php"):
                    json_obj = json.loads(result)
                    state_code = json_obj['state']
                    if state_code == 200:
                        self.isLogin = True
                else:
                    self.isLogin = True
            else:
                print("SessionClient", f"login error: code={resp.status_code}")
            return self.isLogin
        except Exception as e:
            print("SessionClient", f"login exception: {e}")
            self.close()
            return False

    def info(self):
        self.login()
        try:
            global url_info
            # http://192.168.30.125:19852/02880771-fce36ba5/systemjson.php
            # url = self.host + "/systemjson.php"
            url = self.host + url_info
            print("SessionClient", f"info request {url} {self.session.cookies}")
            print("SessionClient", f"info params: {device_info}")
            resp = self.session.post(url=url, data=device_info, timeout=10, headers=self.HEADERS)
            resp.encoding = 'utf-8'
            print("SessionClient", f"info encode: {resp.encoding}")
            if resp.status_code == 200:
                result = resp.content.decode(encoding="UTF-8")
                print("SessionClient",
                                  f"info result: code={resp.status_code}, cookies={self.session.cookies}, content={result}")

                json_obj = json.loads(result)
                version = json_obj['body']['soft_ver']
            else:
                version = None
                print("SessionClient", f"info error: code={resp.status_code}")
            return version
        except Exception as e:
            print("SessionClient", f"info failed {e}")
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
            print("SessionClient", f"update request {url} {self.session.cookies}")
            print("SessionClient", f"update params: {filename}, {name}")
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
            print("SessionClient", f"update encode: {resp.encoding}, {resp.elapsed.total_seconds()}")
            print("SessionClient", f"upload result: code={resp.status_code}, content={resp.content.decode()}")
            if resp.status_code == 200:
                result = resp.content.decode(encoding="UTF-8")
                print("SessionClient", f"upload success: cookies={self.session.cookies}, content={result}")
                return True
            else:
                print("SessionClient", f"update failed: {resp.status_code} {filename}")
                if resp.content is None:
                    result = None
                else:
                    result = resp.content.decode(encoding="UTF-8")
                print("SessionClient", f"update failed: {result}")
            return False
        except Exception as e:
            print("SessionClient", f"update exception: {filename} {e}")
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
