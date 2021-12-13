import os
import json
import sys

import execjs
import requests
from libutils.zlog import ZLog


# 仅支持admin:admin登录
userinfo = '{"type" : "login","module" : "BUS_WEB_REQUEST","user_info" : "%s","body" : {}}'


class WEBClient:
    '''
    :param:url 传入地址和端口(http://192.168.6.19:80)
    :param:username 用户名
    :param:password 密码
    '''
    def __init__(self, url, username, password):
        self.url = url
        self.log = ZLog()
        self.is_login = False       # 登录判断
        self.username = username
        self.password = password

    #
    def aes_file(self):
        print(sys.argv[0])
        path = os.path.join(os.getcwd()) + "\\libutils\\Aes.js"
        print(path)
        f = open(path, 'r', encoding='utf-8')  # 打开JS文件
        line = f.readline()
        htmlstr = ''
        while line:
            htmlstr = htmlstr + line
            line = f.readline()
        return htmlstr

    #
    def aes_pwd(self, user_pwd, en_key):
        js_str = self.aes_file()
        aesctr = execjs.compile(js_str)  # 加载JS文件
        decode_str = aesctr.call('AesCtr.encrypt', user_pwd, en_key, 128)
        return decode_str

    #
    def login(self):
        if self.is_login == True:
            return

        try:
            url = self.url + "/libutils.php"
            print(url)

            # en_key = '天天'
            en_key = 'secret08'
            user_pwd = '{}:{}'.format(self.username, self.password)
            aes_user_pwd = self.aes_pwd(user_pwd, en_key)
            print(userinfo % aes_user_pwd)

            self.ses = requests.session()
            resp = self.ses.post(url, userinfo % aes_user_pwd, timeout=10)
            print(resp.status_code)
            if resp.status_code == 200:
                self.is_login = True
                self.log.log_info("login success", "HTTPClient")
            else:
                self.log.log_error("login failed", "HTTPClient")
            
            print(resp.content.decode())
        except Exception:
            print("login Exception")
            if not self.ses:
                self.close()

    '''
    升级
    :param cmd 执行命令json内容
    :return http状态值，response数据
    '''
    def posts(self, cmd):
        self.login()

        try:
            if self.ses is None:
                print("http session is None")
                return 404, None
            url = self.url + "/libutils.php"
            print(url)

            udic = json.loads(cmd)
            resp = self.ses.post(url, cmd, timeout=10)
            if resp.status_code == 200:
                self.log.log_info("success: " + udic['type'], udic['module'])
            else:
                self.log.log_err("failed: " + udic['type'], udic['module'])
            return resp.status_code, resp.content.decode()
        except Exception:
            print("posts Exception")
            if self.ses:
                self.close()
            return 404, None

    # 下载
    # 返回:状态码和二进制数据
    def download(self, url):
        self.login()

        try:
            resp = self.ses.get(url, stream=True)
            return resp.status_code, resp.content
        except Exception:
            print("download Exception")
            if self.ses:
                self.close()

    # 上传
    def upload(self, localfile, remotefile):
        self.login()

        try:
            url = self.url + "/upload.php"
            print(url)
            
            data = '{"filepath":"%s"}' % remotefile
            print(data)

            files = {'file' : open(localfile, 'rb')}
            print(files)
            headers = {"content-type":"multipart/form-data"}
            # resp = self.ses.post(url, data=data, files=files, headers=headers)
            resp = self.ses.post(url, json=data, files=files)
            if resp.status_code == 200:
                self.log.log_info("success: " + localfile, "update")
            else:
                self.log.log_err("failed: " + localfile, "update")
            return resp.status_code
        except Exception:
            print("update Exception")
            if self.ses:
                self.close()

    '''
    升级
    :param filename 升级文件abs路径
    :return http状态值，response数据
    '''
    def update(self, filename):
        self.login()

        try:
            url = self.url + "/update.php"
            print(url)

            files = {'file': open(filename, 'rb')}
            resp = self.ses.post(url, files=files)
            if resp.status_code == 200:
                self.log.log_info("success: " + filename, "update")
            else:
                self.log.log_err("failed: " + filename, "update")
            return resp.status_code, resp.content.decode()
        except Exception:
            print("update Exception")
            if self.ses:
                self.close()
            return 404, None

    '''
    关闭
    '''
    def close(self):
        self.ses = None
        self.is_login = False
