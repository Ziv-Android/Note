#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from libutils.tcpclient import *
import xlrd
import xlwt

cmd_get_device_info = '{"type":"get_device_info","id":5,"module":"SS_BUS_REQUEST","block_flag":1}'

# TCP获取定制协议数据
cmd_get = """{
    "id" : 9999,
    "module" : "DP_CUSTOM_CFG_REQ",
    "block_flag":1,
    "type" : "get_usr_data"
}"""

# TCP设置定制协议数据
cmd_set = """{
    "body":{
        "secret_key": "%s",
        "sn": "%s"
    },
    "id": 9999,
    "module": "DP_CUSTOM_CFG_REQ",
    "type": "set_usr_data"
}"""


def get_device_info(client_tcp):
    json_data, image_str = client_tcp.request(cmd_get_device_info)
    try:
        state = json_data['state']
        if state == 200:
            return json_data['body']['serial_num']
        return None
    except:
        return None


def get_custom_cfg(client_tcp):
    json_data, image_str = client_tcp.request(cmd_get)
    try:
        state = json_data['state']
        if state == 200:
            return json_data['body']['secret_key'], json_data['body']['sn']
        return "", ""
    except:
        return "", ""


def set_custom_cfg(client_tcp, secret_key, secret_sn):
    cmd = cmd_set % (secret_key, secret_sn)
    json_data, image_str = client_tcp.request(cmd)
    try:
        state = json_data['state']
        return state == 200
    except:
        return False


def load_excel_data(path='.//product//晋江和康乐项目HV08P序列号-test.xls'):
    workbook = xlrd.open_workbook(path)
    worksheet = workbook.sheet_by_index(0)
    print(worksheet.name, worksheet.nrows, worksheet.ncols)
    title = worksheet.row_values(0)
    custom_sn_map = {}
    # 按行获取内容
    for i in range(1, worksheet.nrows):  # 循环打印每一行
        item_line = worksheet.row_values(i)
        # print(item_line)  # 以列表形式读出，列表中的每一项是str类型
        custom_sn_map[item_line[1]] = item_line
    # print(len(custom_sn_map), custom_sn_map)
    # 按列获取内容
    # for i in range(worksheet.ncols):
    #     print(worksheet.col_values(i))
    # custom_sn_list = worksheet.col_values(1)[1:]
    # print(len(custom_sn_list), custom_sn_list)
    workbook.release_resources()
    del worksheet
    return title, custom_sn_map


def write_excel_data(title, data, path='.//product//晋江和康乐项目HV08P序列号-test.xls'):
    workbook = xlwt.Workbook(encoding='utf-8')
    worksheet = workbook.add_sheet("Sheet1", cell_overwrite_ok=True)
    for i in range(len(title)):
        worksheet.write(0, i, title[i])
    i = 1
    for key, value in data.items():
        for j in range(len(value)):
            worksheet.write(i, j, value[j])
        i += 1

    workbook.save(path)


if __name__ == "__main__":
    titles, custom_sn_data = load_excel_data()
    # for key, value in custom_sn_data:
        # if value[]
    print(load_excel_data())
