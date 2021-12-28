#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import telnetlib
from time import sleep


class TelnetClient:
    def __init__(self):
        self.tn = telnetlib.Telnet()

    # 此函数实现telnet登录主机
    def login_host(self, host_ip, username, password):
        try:
            self.tn.open(host_ip, port=23)
        except:
            # log.log_info('%s网络连接失败' % host_ip,write=False)
            print('%s网络连接失败' % host_ip)
            return False
        # 等待login出现后输入用户名，最多等待10秒
        self.tn.read_until(b'login: ', timeout=10)
        self.tn.write(username.encode('ascii') + b'\r\n')
        # 等待Password出现后输入用户名，最多等待10秒
        self.tn.read_until(b'Password: ', timeout=10)
        self.tn.write(password.encode('ascii') + b'\r\n')
        # 延时两秒再收取返回结果，给服务端足够响应时间
        sleep(2)
        # 获取登录结果
        # read_very_eager()获取到的是的是上次获取之后本次获取之前的所有输出
        command_result = self.tn.read_very_eager().decode('ascii')

        if 'Login incorrect' not in command_result:
            # print('%s登录成功' % host_ip, write=False)
            return True
        else:
            print('{}登录失败，用户名或密码错误'.format(host_ip), write=False)
            return False

    # 此函数实现执行传过来的命令，并输出其执行结果
    def execute_some_command(self, command):
        # 执行命令
        self.tn.write(command.encode('ascii') + b'\n')
        sleep(2)
        # 获取命令结果
        command_result = self.tn.read_very_eager().decode('ascii')
        # log.log_info('命令{}执行结果：\n【{}】'.format(command,command_result),write=False)
        return command_result

    #
    def excute_some_command_until(self, command, until):
        # 执行命令
        try:
            self.tn.write(command.encode('ascii') + b'\n')
            command_result = self.tn.read_until(until.encode('ascii'), timeout=30)
            command_result = command_result.decode('utf-8')
            start_index = command_result.find('\r\n')
            command_result = command_result[start_index + 2:]
            # 获取命令结果
            # log.log_info('命令执行结果：\n【{}】'.format(command_result))
            return command_result
        except Exception as err:
            print("执行命令{}失败".format(command))
            pass

    # 退出telnet
    def logout_host(self):
        self.tn.write(b"exit\n")
        print("{}退出登录")
