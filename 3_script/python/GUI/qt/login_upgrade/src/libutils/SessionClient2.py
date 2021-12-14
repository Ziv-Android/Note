import os
import sys

import execjs
import requests
from requests_toolbelt.multipart import encoder

# 支持admin:admin登录
user_info = '{"type": "login","module": "BUS_WEB_REQUEST","user_info": "%s"}'
device_info = '{"type":"get_device_info","module":"SS_BUS_REQUEST"}:'


class SessionClient:
    """
    :param:url 传入地址和端口(http://192.168.6.19:80)
    :param:username 用户名
    :param:password 密码
    """
    def __init__(self, url, username, password):
        self.url = url
        self.progress_last = 0
        self.ses = None
        # self.log = ZLog()
        self.cookies = None
        self.is_login = False       # 登录判断
        self.username = username
        self.password = password

    # 读取aes工具文件
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
        if self.is_login:
            return

        try:
            # url = self.url + "/login.php"
            # print(url)
            # # 对应login.php加密，数据为user_pwd字符串
            # en_key = '天天'

            url = self.url + "/request.php"
            print(url)
            # 对应request.php，数据为json
            en_key = 'secret08'
            user_pwd = '{}:{}'.format(self.username, self.password)
            print(user_pwd)
            aes_user_pwd = self.aes_pwd(user_pwd, en_key)
            login_info = user_info % aes_user_pwd
            print(login_info)
            resp = requests.post(url=url, data=login_info, timeout=10)
            self.cookies = resp.cookies
            # self.ses = requests.session()
            # resp = self.ses.post(url, aes_user_pwd, timeout=10)
            # resp = self.ses.post(url, user_info % aes_user_pwd, timeout=10)
            print(resp.status_code)
            if resp.status_code == 200:
                self.is_login = True
                # self.log.log_info("login success", "HTTPClient")
                # print(self.ses.cookies)
                print(self.cookies)
                print("login success", "HTTPClient")
            else:
                # self.log.log_error("login failed", "HTTPClient")
                print("login failed", "HTTPClient")
            
            print(resp.content.decode())
        except Exception:
            print("login Exception")
            if not self.ses:
                self.close()

    def info(self):
        self.login()

        try:
            url = self.url + "/systemjson.php"
            print(url)
            # print(self.ses.cookies)
            print(self.cookies)
            # resp = self.ses.post(url, device_info, timeout=10)
            # resp = self.ses.post(url, user_info % aes_user_pwd, timeout=10)
            resp = requests.post(url=url, data=device_info, timeout=10, cookies=self.cookies)
            print(resp.status_code)
            if resp.status_code == 200:
                self.is_login = True
                # self.log.log_info("login success", "HTTPClient")
                print("request success", "HTTPClient")
            else:
                # self.log.log_error("login failed", "HTTPClient")
                print("request failed", "HTTPClient")

            print(resp.content.decode())

        except Exception:
            print("login Exception")
            if not self.ses:
                self.close()

    '''
    升级
    :param filename 升级文件abs路径
    :return http状态值，response数据
    '''
    def update(self, filename):
        self.login()

        try:
            # url = self.url + "/update.php"
            url = self.url + "/upload.cgi"
            filename.replace('\\', '/')
            print(url, filename)
            name = filename.split("/")[-1]
            # file = {
            #     "file": open(filename, "rb"),
            #     "Content-Type": "application/octet-stream",
            #     "Content-Disposition": "form-data",
            #     "filename": name
            # }
            # print(self.ses.cookies)
            # print(file)
            # resp = self.ses.post(url, files=file, timeout=600)
            e = encoder.MultipartEncoder(
                fields={
                    'file': (name, open(filename, "rb"), "application/octet-stream"),
                    'filename': name,
                    "Content-Type": "application/octet-stream",
                    "Content-Disposition": "form-data",
                }
            )
            m = encoder.MultipartEncoderMonitor(e, self.progress_callback)
            headers = {
                'Content-Type': e.content_type,
            }
            print(headers)
            # resp = self.ses.post(url, data=m, headers=headers, timeout=600)
            resp = requests.post(url=url, data=m, headers=headers, cookies=self.cookies, timeout=600)
            print(resp.status_code, resp.content)
            if resp.status_code == 200:
                # self.log.log_info("success: " + filename, "update")
                print("success: " + filename, "update")
            else:
                # self.log.log_err("failed: " + filename, "update")
                print("failed: " + filename, "update")
            return resp.status_code, resp.content.decode()
        except Exception as e:
            print("update Exception", e)
            if self.ses:
                self.close()
            return 404, None

    def progress_callback(self, monitor):
        progress = round(monitor.bytes_read / monitor.len * 100, 2)
        if progress - self.progress_last > 3:
            self._heart()
            self._heart2()
            self.progress_last = progress
        print(progress)

    def _heart(self):
        url = self.url + "/vb.htm?getdate=&gettime="
        resp = requests.get(url, cookies=self.cookies)
        if resp.status_code == 200:
            # self.log.log_info("success: " + filename, "update")
            print("success: ", "vb.htm")
        else:
            # self.log.log_err("failed: " + filename, "update")
            print("failed: ", "vb.htm")

    def _heart2(self):
        url = self.url + "/webpage_relogin.php"
        resp = requests.post(url, cookies=self.cookies)
        if resp.status_code == 200:
            # self.log.log_info("success: " + filename, "update")
            print("success: ", "webpage_relogin")
        else:
            # self.log.log_err("failed: " + filename, "update")
            print("failed: ", "webpage_relogin")

    '''
    关闭
    '''
    def close(self):
        self.ses = None
        self.is_login = False
