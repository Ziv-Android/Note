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

func_note = "设置MTU"
# cmd = '{"type":"set_module_app_cfg","module":"MODULE_CONFIG_INFO","body":{"app":[{"name":"xtp_push_app","enable":1},{"name":"onvif_server_app","enable":1},{"name":"stp_server_app","enable":1},{"name":"link_visual_app","enable":1},{"name":"onenet_server_app","enable":1},{"name":"oem_multicast_app","enable":1},{"name":"interact_device_app","enable":0}]}}'
# cmd = '{"type":"AVS_SET_LED_CTRL","body":{"time_ctrl":[{"time_begin":"00:00:00","time_end":"04:30:00","timectrl_enable":true,"led_level":2,"id":0},{"time_begin":"04:30:00","time_end":"10:45:00","timectrl_enable":false,"led_level":-1,"id":1},{"time_begin":"10:45:00","time_end":"24:00:00","timectrl_enable":true,"led_level":0,"id":2}],"led_mode":2}}'
# cmd = '{"type":"set_flashlamp_info","module":"EVS_BUS_REQUEST","body":{"output_gpio":0,"input_gpio":0,"light_mode":4,"flash_info":{"delay_time":50,"light_time":3000}}}'
# cmd = '{"type":"set_voice_cfg","body":{"voice_type":0,"greetings":"5oKo5aW9","tag":"5LiA6Lev6aG66aOO","voice_male":1,"voice_interval":900,"voice_time_inv_level":[{"start_time":"00:00:00","end_time":"07:00:00","voice_volume":60},{"start_time":"07:00:00","end_time":"20:00:00","voice_volume":100},{"start_time":"20:00:00","end_time":"24:00:00","voice_volume":60}],"start_mode":1}}'
cmd = '''{
  "type": "set_net_mtu",
  "body": {
    "mtu": 1500
  }
}'''

params = []
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
        if param == 'module':
            continue
        param_str += ', %s={%s}' % (param, param)
    return param_str


print("allure_step:", create_allure_step(params))


# def create_params_url()


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
            if param == 'module':
                continue
            default_value = data["body"][param]
            # print(param, default_value)
            if isinstance(default_value, str):
                default_value = f'"{default_value}"'
            param_str += f', {param}={default_value}'
    else:
        for param in param_list:
            if param == 'module':
                continue
            default_value = data[param]
            if isinstance(default_value, str):
                default_value = f'"{default_value}"'
            param_str += f', {param}={default_value}'

    return param_str


print("params:", create_params(cmd, params))


def create_doc(param_list):
    param_str = ""
    for param in param_list:
        if param == 'module':
            continue
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
        param_str += ', "body": {'
        for param in param_list:
            if param == 'module':
                continue
            if param == 'mode':
                continue
            # default_value = data["body"][param]
            # print(param, default_value)
            param_str += f'"{param}": {param}, '
        param_str += '}'
    else:
        for param in param_list:
            if param == 'module':
                param_str += f', "{param}": "{data[param]}", '
                continue
            param_str += f', "{param}": {param}, '

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
        response = self.post(ask_url, data=json.dumps(data_body))
        assert response.status_code == 200
        assert self.get_text(response.text, 'state') == 200
        return response.text
    except Exception as err:
        traceback.print_exc()
        raise err
'''
)

