import os
import configparser


class ConfigClient:
    def __init__(self, path):
        self.cfg = configparser.ConfigParser()

        fpath = path + 'customer.ini'
        self.is_ok = False
        if os.path.exists(fpath) == False:
            print('%s 文件不存在,打开失败' % path)
            return

        try:
            b = self.cfg.read(fpath, encoding='utf-8-sig')
            if b:
                self.is_ok = True
                print(self.cfg.get('c01', 'name'))
        except:
            print('%s 文件格式不能被解析,打开失败' % path)

    def is_init(self):
        return self.is_ok

    def get_name(self, section):
        if self.cfg.has_section(section):
            return self.cfg[section]['name']
        else:
            return None

    def get_info(self, section):
        if self.cfg.has_section(section):
            return self.cfg[section]['info']
        else:
            return None

    def get_conf_pname(self, section):
        if self.cfg.has_section(section):
            return self.cfg[section]['pname']
        else:
            return None

    def get_conf_library(self, section):
        if self.cfg.has_section(section):
            return self.cfg[section]['library']
        else:
            return None


# cfg = configparser.ConfigParser()
# cfg.read("E:/2021SRC/oqc_tool/product/h1m/customer.ini")
# selections = cfg.sections()
# print(selections)
# print(cfg.get('c01', 'name'))

# cc = ConfigClient("E:/2021SRC/oqc_tool/product/h1m/")
# print(cc.get_name('c01'))
