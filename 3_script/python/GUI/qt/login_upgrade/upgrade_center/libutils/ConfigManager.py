#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import os
import configparser


class ConfigManager:
    def __init__(self, path):
        self.cfg = configparser.RawConfigParser()
        if path is None:
            path = os.path.join(os.getcwd(), "configs", "config.ini")
        if not os.path.exists(path):
            return

        try:
            self.cfg.read(path, encoding="utf-8")
        except Exception as e:
            print("ConfigManager init exception:", e)

    def get_url_pdns(self):
        pdns = self.cfg["url"]["pdns"]
        return pdns

    def get_account_username(self):
        username = self.cfg["account"]["username"]
        return username

    def get_account_password(self):
        password = self.cfg["account"]["password"]
        return password

    def get_account_access_key_id(self):
        id = self.cfg["account"]["access_key_id"]
        return id

    def get_account_access_key_secret(self):
        secret = self.cfg["account"]["access_key_secret"]
        return secret

    def get_path_login(self):
        login = self.cfg["path"]["login"]
        return login

    def get_path_logout(self):
        logout = self.cfg["path"]["logout"]
        return logout

    def get_path_info(self):
        info = self.cfg["path"]["info"]
        return info

    def get_path_upgrade(self):
        upgrade = self.cfg["path"]["upgrade"]
        return upgrade

    def get_path_heart_beat(self):
        heart_beat = self.cfg["path"]["heart_beat"]
        return heart_beat

    def get_params_user_info(self):
        user_info = self.cfg["params"]["user_info"]
        return user_info

    def get_params_logout_info(self):
        logout_info = self.cfg["params"]["logout_info"]
        return logout_info

    def get_params_device_info(self):
        device_info = self.cfg["params"]["device_info"]
        return device_info

    def get_params_heart_beat_info(self):
        heart_beat_info = self.cfg["params"]["heart_beat_info"]
        return heart_beat_info

    def get_switch_use_access(self):
        use_access = self.cfg["switch"]["use_access"]
        return use_access
