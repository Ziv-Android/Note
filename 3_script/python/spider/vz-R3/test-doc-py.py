#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# year = 8200 * 12
# total = 0
# for i in range(1, 31):
#     total += year
#     print(f"第{i}年, year：{year}, total:{total}")
#     year *= 0.977
import json

import docx

# doc = docx.Document("R3-HTTP-interface.docx")
# last_line = ""
#
# cache = ""
# dep = -1
# index = 1
# # 数据提取
# for p in doc.paragraphs:
#     graph = p.text
#     print(graph)

# cmd = '{"type":"set_reboot_timing","body":{"enable":1,"wday":"1,3","minute":0}}'
# cmd = '{"type":"reset_module_app_cfg","module":"MODULE_CONFIG_INFO"} '
cmd = '{"type":"set_module_app_cfg","module":"MODULE_CONFIG_INFO","body":{"app":[{"name":"xtp_push_app","enable":1},{"name":"onvif_server_app","enable":1},{"name":"stp_server_app","enable":1},{"name":"link_visual_app","enable":1},{"name":"onenet_server_app","enable":1},{"name":"oem_multicast_app","enable":1},{"name":"interact_device_app","enable":0}]}}'

params = []
func_note = "配置自动重启"
func_name = ""
func_body = ""
func_end = ""


def json_parser(root, json_obj):
    global func_name, params, func_end
    try:
        if isinstance(json_obj, dict):
            print("dict:", len(json_obj), root, json_obj)
            for key, value in json_obj.items():
                if key == "id":
                    continue
                elif key == "type":
                    func_name = value
                    if func_name.startswith("get"):
                        func_end = "return data"
                else:
                    json_parser(key, value)
        elif isinstance(json_obj, list):
            print("list:", len(json_obj), root, json_obj)
            params.append(root)
            # for item in json_obj:
            #     json_parser(root, item)
        else:
            params.append(root)
            print("value:", root, json_obj)
    except Exception as e:
        print(e)


# # def create_func_body(json_obj, params_b):
# #     try:
# #         body_params = json_obj["body"]
# #
# #
# #     except Exception as e:
# #         print(e)
#
json_parser("", json.loads(cmd))
# func_body = create_func_body(json.loads(cmd), params)
print(func_name, params, func_body, func_end)
print("------------------------------------------------------------------------")


def create_allure_step(param_list):
    param_str = "url={url}, cmd_type={cmd_type}"
    for param in param_list:
        param_str += ', %s={%s}' % (param, param)
    return param_str


print("allure_step:", create_allure_step(params))


def create_params(data_json, param_list):
    data = json.loads(data_json)
    param_str = ""
    cmd_body = None

    try:
        cmd_body = data["body"]
    except Exception as e:
        print('cmd not has body')

    if cmd_body is not None:
        for param in param_list:
            default_value = data["body"][param]
            # print(param, default_value)
            if isinstance(default_value, str):
                default_value = f'"{default_value}"'
            param_str += f', "{param}"={default_value}'
    return param_str


print("params:", create_params(cmd, params))


def create_doc(param_list):
    param_str = ""
    for param in param_list:
        param_str += f'\t:param {param}: \n'
    return param_str[:-1]


print("doc:", create_doc(params))


def create_data_body(data_json, param_list):
    data = json.loads(data_json)
    param_str = ""
    cmd_type = None
    cmd_body = None
    try:
        cmd_type = data["type"]
    except Exception as e:
        print('cmd not has type')

    if cmd_type is not None:
        param_str += '{"type": cmd_type'

    try:
        cmd_body = data["body"]
    except Exception as e:
        print('cmd not has body')

    if cmd_body is not None:
        param_str += ', {"body": '
        for param in param_list:
            default_value = data["body"][param]
            # print(param, default_value)
            param_str += f'"{param}"={param}, '
        param_str += '}'

    param_str += '}'
    return param_str


print("data_body:", create_data_body(cmd, params))


def create_ask_url():
    return "'http://{}/{}'.format(self.ip, url)"


print("ask_url:", create_ask_url())
print("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n")
print(
f'''
@allure.step('{func_note}：{create_allure_step(params)}')
def {func_name}(self, url=SYSTEMJSON_URL, cmd_type="{func_name}"{create_params(cmd, params)}):
    """
    {func_note}
{create_doc(params)}
    :return:
    """
    try:
        data_body = {create_data_body(cmd, params)}
        ask_url = {create_ask_url()}
        # response = requests.request("POST", ask_url, data=json.dumps(data_body), headers=self.HEADERS)
        response = self.post(ask_url, data=json.dumps(data_body))
        assert response.status_code == 200
        assert self.get_text(response.text, 'state') == 200
        return response.text
    except Exception as err:
        traceback.print_exc()
        raise err
'''
)

