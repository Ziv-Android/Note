## 登录页
#### 请求
##### 获取系统参数 
http://192.168.13.202/avsjson.php POST    
Params    
```json
{"type":"AVS_GET_SYS_PRM"} 
```    
Response      
```json
{
	"body": {
		"alg_block": false,
		"language": "zh-cn"
	},
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_GET_SYS_PRM"
}
```
#### 操作
##### 登录
http://192.168.13.202/login.php POST    
Params   
```
加密username和password参数，rJIMYtjY2NgYtbky3tuwOy27rg:==加密规则见下    
```
Response 
```
OK
Set-Cookie: sessionID=209192407
```

## 实时视频页
#### 请求
##### 获取用户权限
http://192.168.13.202/getauth.php POST    
Params    
```json
{"type":"get_user_auth"}
```   
Response   
```json    
{
	"body": {
		"authority": 0
	},
	"state": 200,
	"type": "get_user_auth"
}
```
##### 获取？ 
http://192.168.13.202/genvictetc.php POST    
Params    
```json
{"type":"etc_get_enable"}
```   
Response   
```json    
{
	"state": 401
}
```
##### 获取设备类型
http://192.168.13.202/request.php POST    
Params    
```json
{"type":"get_web_saved_value","module":"WEB_SELF_REQUEST"}    
```   
Response   
```json    
{
	"body": "",
	"module": "WEB_SELF_REQUEST",
	"state": 200,
	"type": "get_web_saved_value"
}
```
##### 获取设备能力
http://192.168.13.202/request.php POST    
Params    
```json
{"type":"get_device_capacity","module":"SS_BUS_REQUEST"}    
```   
Response   
```json    
{
	"body": {
		"ado_enable": 1,
		"e4g_num": 1,
		"fan_num": 0,
		"img_reset_num": 0,
		"io_in_num": 2,
		"io_out_num": 2,
		"key_reset_num": 1,
		"led_num": 0,
		"mcu_num": 0,
		"moto_num": 0,
		"onenet_enable": 1,
		"opensdk_en": 1,
		"stp_enable": 1,
		"ttl_num": 0,
		"tty_num": 1,
		"wifi_num": 0
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_device_capacity"
}
```
##### 获取？ 
http://192.168.13.202/getivsctrl.php POST    
Params    
```
8:1:MA==
```
Response   
``` 
OK ivsctrl=8:1:MA==
```

第一位字段 | 释义
--- | ---
2 | 获取支持的省份
4 | 获取车牌过滤模式
5 | 设置车牌过滤模式
6 | 获取算法版本号
7 | 设置识别参数
8 | 获取识别类型

第二位字段：数据长度  
第三位字段：数据Base64值  

##### 获取算法结果配置
http://192.168.13.202/avsjson.php POST    
Params    
```json
{"type":"AVS_GET_ALG_RESULT_PROP"}    
```   
Response   
```json    
{
	"body": {
		"fake_threshold": {
			"default": 0,
			"types": [{
				"content": "5L2O",
				"type": 0
			}, {
				"content": "5Lit",
				"type": 1
			}, {
				"content": "6auY",
				"type": 2
			}]
		},
		"out_result_type": {
			"default": 18,
			"types": [{
				"content": "56iz5a6a6K+G5Yir6Kem5Y+R",
				"type": 1
			}, {
				"content": "6Jma5ouf57q/5ZyI",
				"type": 2
			}, {
				"content": "SU8x6Kem5Y+R",
				"type": 16
			}, {
				"content": "SU8y6Kem5Y+R",
				"type": 32
			}, {
				"content": "SU8z6Kem5Y+R",
				"type": 64
			}, {
				"content": "SU806Kem5Y+R",
				"type": 128
			}]
		},
		"province": {
			"default": 255,
			"types": [{
				"content": "5Lqs",
				"type": 0
			}, {
				"content": "5rSl",
				"type": 1
			}, {
				"content": "5YaA",
				"type": 2
			}, {
				"content": "5pmL",
				"type": 3
			}, {
				"content": "6JKZ",
				"type": 4
			}, {
				"content": "6L69",
				"type": 5
			}, {
				"content": "5ZCJ",
				"type": 6
			}, {
				"content": "6buR",
				"type": 7
			}, {
				"content": "5rKq",
				"type": 8
			}, {
				"content": "6IuP",
				"type": 9
			}, {
				"content": "5rWZ",
				"type": 10
			}, {
				"content": "55qW",
				"type": 11
			}, {
				"content": "6Ze9",
				"type": 12
			}, {
				"content": "6LWj",
				"type": 13
			}, {
				"content": "6bKB",
				"type": 14
			}, {
				"content": "6LGr",
				"type": 15
			}, {
				"content": "6YSC",
				"type": 16
			}, {
				"content": "5rmY",
				"type": 17
			}, {
				"content": "57Kk",
				"type": 18
			}, {
				"content": "5qGC",
				"type": 19
			}, {
				"content": "55C8",
				"type": 20
			}, {
				"content": "5rid",
				"type": 21
			}, {
				"content": "5bed",
				"type": 22
			}, {
				"content": "6LS1",
				"type": 23
			}, {
				"content": "5LqR",
				"type": 24
			}, {
				"content": "6JeP",
				"type": 25
			}, {
				"content": "6ZmV",
				"type": 26
			}, {
				"content": "55SY",
				"type": 27
			}, {
				"content": "6Z2S",
				"type": 28
			}, {
				"content": "5a6B",
				"type": 29
			}, {
				"content": "5paw",
				"type": 30
			}]
		},
		"reco_dis": {
			"default": 0,
			"types": [{
				"content": "2-4m",
				"type": 0
			}, {
				"content": "6-8m",
				"type": 1
			}, {
				"content": "4-6m",
				"type": 2
			}]
		},
		"recognition_type": {
			"default": 550970,
			"types": [{
				"content": "6JOd54mM",
				"type": 1
			}, {
				"content": "6buE54mM",
				"type": 24
			}, {
				"content": "5pWZ57uD6L2m",
				"type": 8192
			}, {
				"content": "6K2m6L2m",
				"type": 32
			}, {
				"content": "5q2m6K2m6L2m",
				"type": 229440
			}, {
				"content": "5Yab6L2m",
				"type": 768
			}, {
				"content": "5riv5r6z",
				"type": 18432
			}, {
				"content": "5L2/6aaG6L2m",
				"type": 1024
			}, {
				"content": "5rCR6Iiq",
				"type": 262144
			}, {
				"content": "5paw6IO95rqQ",
				"type": 1572864
			}, {
				"content": "5bqU5oCl6L2m",
				"type": 2097152
			}, {
				"content": "6aKG5LqL6aaG",
				"type": 4194304
			}, {
				"content": "5peg",
				"type": 8388608
			}]
		},
		"run_mode": {
			"default": 0,
			"types": [{
				"content": "6buY6K6k",
				"type": 0
			}, {
				"content": "5YGc6L2m5Zy6",
				"type": 1
			}, {
				"content": "5Y2h5Y+j",
				"type": 2
			}]
		},
		"snap_image_quality": {
			"default": 70,
			"max": 100,
			"min": 0
		},
		"snap_resolution": {
			"default": 10,
			"types": [{
				"content": "640*360",
				"type": 3
			}, {
				"content": "704*576",
				"type": 5
			}, {
				"content": "1280*720",
				"type": 9
			}, {
				"content": "1920*1080",
				"type": 10
			}, {
				"content": "2304*1296",
				"type": 11
			}]
		}
	},
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_GET_ALG_RESULT_PROP"
}
```
##### 获取视频流参数
http://192.168.13.202/request.php POST    
Params    
```json
{"type":"get_live_stream_type","module":"BUS_WEB_REQUEST"}    
```   
Response   
```json    
{
	"body": {
		"enable_auth": true,
		"live_stream_type": "flv",
		"port": 9080,
		"pubkey": "LS0tLS1CRUdJTiBQVUJMSUMgS0VZLS0tLS0KTUlHZk1BMEdDU3FHU0liM0RRRUJBUVVBQTRHTkFEQ0JpUUtCZ1FDNGFXNDUzVEFqdnFsQXlwTTluQUFPNTFZTwpuQk1iQ1ovUEpZekNUR0l1WFBWTzFIM0tSdTBIOWJRUlRWY2VFMUtKNVM5ZVg3UmppSGZWektEaWlVR2NDU0dpCkdIOEtoUEdaR0hHbDhXVFVsczVER3dvRVEybVBmTmROREdVRldOMzRkcVN2VlpBWVRjTE5tMVM0YXlJeElncXUKVVJhbDN2SDBtbHpkKzdoVVJ3SURBUDdWCi0tLS0tRU5EIFBVQkxJQyBLRVktLS0tLQo=",
		"token": "17abed60-9180-2eb7-e72b-609f6d96c0da",
		"transport_type": {
			"0": "ws",
			"1": "http"
		}
	},
	"err_msg": "OK",
	"state": 200,
	"type": "get_live_stream_type"
}
```
##### 获取手动触发算法识别结果？ 
http://192.168.13.202/ivs_result.php?_=1646033471027 GET    
```   
Response   
```json    
{
	"body": {
		"PlateResult": {
			"car_head_bottom": 0,
			"car_head_left": 0,
			"car_head_right": 0,
			"car_head_top": 0,
			"color": 0,
			"image_path": "L21lZGlhL21tY2JsazBwMS9WeklQQ0NhcC8yMDE4XzA4XzIwLzEzNTMyMTYxMDRfX+aXoF8uanBn",
			"is_fake_plate": 0,
			"license": "X+aXoF8=",
			"nType": 0,
			"plate_bottom": 0,
			"plate_distance": 0,
			"plate_left": 0,
			"plate_right": 0,
			"plate_top": 0,
			"plate_true_width": 0,
			"trigger_time": "2018-08-20 13:53:21",
			"uBitsTrigType": 4,
			"uId": 0
		}
	},
	"error_msg": "success",
	"state": 200,
	"type": "GET_LAST_IVS_RECORD"
}
```
##### 获取网络信息
http://192.168.13.202/systemjson.php POST    
Params    
```json
{"type":"get_net_and_port"}    
```   
Response   
```json    
{
	"body": {
		"dhcp": 0,
		"dns": "114.114.114.114",
		"dns2": "8.8.8.8",
		"gateway": "192.168.1.11",
		"http_port": 80,
		"https_en": 0,
		"ip": "192.168.13.202",
		"netmask": "255.255.128.0",
		"rtsp_port": 8557
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_net_and_port"
}
```
##### 获取主辅相机配置
http://192.168.13.202/dgjson.php POST    
Params    
```json
{"type":"get_group_cfg"}    
```   
Response   
```json    
{
	"group_cfg": {
		"group_vzids": []
	},
	"state": 200,
	"type": "get_group_cfg",
	"vzid": {
		"ast_type": 0,
		"enable_group": true,
		"ip_addr": "192.168.13.202",
		"name": "bHk=&MTkyLjE2OC43LjIy",
		"sn": "c806ca86-8de9c3f4",
		"type": "input"
	}
}
```
##### 获取补光灯配置
http://192.168.13.202/avsjson.php POST    
Params    
```json
{"type":"AVS_GET_LED_PROP"}    
```   
Response   
```json    
{
	"body": {
		"led_level": {
			"default": 2,
			"max": 4,
			"min": -1,
			"types": [{
				"content": "5YWz6Zet",
				"type": -1
			}, {
				"content": "Muexsw==",
				"type": 0
			}, {
				"content": "NOexsw==",
				"type": 1
			}, {
				"content": "Nuexsw==",
				"type": 2
			}, {
				"content": "N+exsw==",
				"type": 3
			}, {
				"content": "OOexsw==",
				"type": 4
			}]
		},
		"led_mode": [{
			"content": "5pm66IO9",
			"type": 0
		}, {
			"content": "5bi45Lqu",
			"type": 1
		}, {
			"content": "5bi454Gt",
			"type": 2
		}, {
			"content": "5pe26Ze05q61",
			"type": 3
		}]
	},
	"err_msg": "OK",
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_GET_LED_PROP"
}
```
##### 获取运动方向和车牌像素限制都有相关？ 
http://192.168.13.202/geteventruleexhtm.php POST    
Params    
```
0  
```   
Response   
```    
OK geteventruleex=0:0:45:400:10:0
```
##### 获取设备名称
http://192.168.13.202/systemjson.php POST    
Params    
```json
{"type":"ss_get_devname"}    
```   
Response   
```json    
{
	"body": {
		"title": "SVZT"
	},
	"err_msg": "All done",
	"state": 200,
	"type": "ss_get_devname"
}
```
##### 获取设备信息
http://192.168.13.202/systemjson.php POST    
Params    
```json
{"type":"get_device_info"}    
```   
Response   
```json    
{
	"body": {
		"alg_ver": "3.1.2021120815",
		"batch_number": "504949505056494948",
		"board_version": 12378,
		"dev_type": 13,
		"drv_ver": "C3R3_3.0.111301722",
		"exdataSize": 2852128853,
		"exdata_checker": 46,
		"ext_info": {
			"monitor_numbers": 0,
			"product_code": "VTC820A",
			"product_name": "5pm66IO96L2m54mM6K+G5Yir55u45py6",
			"product_type": "R3-V1.0"
		},
		"hw_flag": 13,
		"hw_version": "09.00.00.0d",
		"isp_ver": "ISP_3510.0.20211105",
		"mac_addr": "48:a2:b8:10:71:b2",
		"oem_info": "00.00.03.78.78.78.78",
		"oem_serial_num": "1234-5689",
		"profocus_flag": 2,
		"serial_num": "c806ca86-8de9c3f4",
		"soft_ver": "12.1.1.202112230",
		"system_ver": "x029.u029.k015.r083",
		"title": "SVZT",
		"write_status": 654647313
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_device_info"
}
```
##### 获取白名单检查结果
http://192.168.13.202/dboprnew.php POST    
Params    
```json
{"type":"get_wl_check_status"}    
```   
Response   
```json    
{
	"body": {
		"dev_time": {
			"time_day": 28,
			"time_hour": 15,
			"time_min": 32,
			"time_mon": 2,
			"time_sec": 42,
			"time_year": 2022
		},
		"filter_enable": 0,
		"offline_status": 0,
		"white_list_flag": 1
	},
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "get_wl_check_status"
}
```
##### 获取NTP配置
http://192.168.13.202/systemjson.php POST    
Params    
```json
{"type":"ss_get_ntp_cfg"}    
```   
Response   
```json    
{
	"body": {
		"cycle": 600,
		"enable": 1,
		"server": "ntp.ntsc.ac.cn"
	},
	"err_msg": "All done",
	"state": 200,
	"type": "ss_get_ntp_cfg"
}
```
##### 获取视频编码信息？ 
http://192.168.13.202/avsjson.php POST    
Params    
```json
{"type":"AVS_GET_ENCODE_PROP"}    
```   
Response   
```json    
{
	"body": {
		"encode_param": [{
			"data_rate": {
				"default": 3072000,
				"enable": true,
				"max": 5000000,
				"min": 512000
			},
			"encode_type": {
				"default": 0,
				"enable": true,
				"types": [{
					"content": "H264",
					"type": 0
				}, {
					"content": "H265",
					"type": 3
				}]
			},
			"frame_rate": {
				"default": 25,
				"enable": true,
				"max": 25,
				"min": 1
			},
			"rate_type": {
				"default": 1,
				"enable": true,
				"types": [{
					"content": "5a6a56CB5rWB",
					"type": 0
				}, {
					"content": "5Y+Y56CB5rWB",
					"type": 1
				}]
			},
			"resolution": {
				"default": 10,
				"enable": true,
				"types": [{
					"content": "640*360",
					"type": 3
				}, {
					"content": "704*576",
					"type": 5
				}, {
					"content": "1280*720",
					"type": 9
				}, {
					"content": "1920*1080",
					"type": 10
				}, {
					"content": "2304*1296",
					"type": 11
				}]
			},
			"stream_id": 0,
			"video_quality": {
				"default": 5,
				"enable": true,
				"types": [{
					"content": "5pyA5rWB55WF",
					"type": 0
				}, {
					"content": "6L6D5rWB55WF",
					"type": 1
				}, {
					"content": "5rWB55WF",
					"type": 2
				}, {
					"content": "5Lit562J",
					"type": 3
				}, {
					"content": "5riF5pmw",
					"type": 4
				}, {
					"content": "6L6D5riF5pmw",
					"type": 5
				}, {
					"content": "5pyA5riF5pmw",
					"type": 6
				}]
			}
		}, {
			"data_rate": {
				"default": 512000,
				"enable": true,
				"max": 1800000,
				"min": 512000
			},
			"encode_type": {
				"default": 0,
				"enable": true,
				"types": [{
					"content": "H264",
					"type": 0
				}, {
					"content": "H265",
					"type": 3
				}]
			},
			"frame_rate": {
				"default": 15,
				"enable": true,
				"max": 25,
				"min": 1
			},
			"rate_type": {
				"default": 0,
				"enable": true,
				"types": [{
					"content": "5a6a56CB5rWB",
					"type": 0
				}, {
					"content": "5Y+Y56CB5rWB",
					"type": 1
				}]
			},
			"resolution": {
				"default": 5,
				"enable": true,
				"types": [{
					"content": "352*288",
					"type": 2
				}, {
					"content": "640*360",
					"type": 3
				}, {
					"content": "704*576",
					"type": 5
				}]
			},
			"stream_id": 1,
			"video_quality": {
				"default": 3,
				"enable": true,
				"types": [{
					"content": "5pyA5rWB55WF",
					"type": 0
				}, {
					"content": "6L6D5rWB55WF",
					"type": 1
				}, {
					"content": "5rWB55WF",
					"type": 2
				}, {
					"content": "5Lit562J",
					"type": 3
				}, {
					"content": "5riF5pmw",
					"type": 4
				}, {
					"content": "6L6D5riF5pmw",
					"type": 5
				}, {
					"content": "5pyA5riF5pmw",
					"type": 6
				}]
			}
		}, {
			"data_rate": {
				"default": 512000,
				"enable": true,
				"max": 2400000,
				"min": 120000
			},
			"encode_type": {
				"default": 0,
				"enable": true,
				"types": [{
					"content": "MJPEG",
					"type": 1
				}]
			},
			"frame_rate": {
				"default": 15,
				"enable": true,
				"max": 15,
				"min": 1
			},
			"rate_type": {
				"default": 0,
				"enable": true,
				"types": [{
					"content": "5a6a56CB5rWB",
					"type": 0
				}]
			},
			"resolution": {
				"default": 5,
				"enable": true,
				"types": [{
					"content": "640*360",
					"type": 3
				}, {
					"content": "704*576",
					"type": 5
				}, {
					"content": "1280*720",
					"type": 9
				}, {
					"content": "1920*1080",
					"type": 10
				}]
			},
			"stream_id": 2,
			"video_quality": {
				"default": 3,
				"enable": true,
				"types": [{
					"content": "5pyA5rWB55WF",
					"type": 0
				}, {
					"content": "6L6D5rWB55WF",
					"type": 1
				}, {
					"content": "5rWB55WF",
					"type": 2
				}, {
					"content": "5Lit562J",
					"type": 3
				}, {
					"content": "5riF5pmw",
					"type": 4
				}, {
					"content": "6L6D5riF5pmw",
					"type": 5
				}, {
					"content": "5pyA5riF5pmw",
					"type": 6
				}]
			}
		}],
		"encode_stream": {
			"default": 0,
			"enable": true,
			"types": [{
				"content": "5Li756CB5rWB",
				"type": 0
			}, {
				"content": "5a2Q56CB5rWBKEZMVik=",
				"type": 1
			}, {
				"content": "56ys5LiJ56CB5rWBKE1KUEVHKQ==",
				"type": 2
			}]
		}
	},
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_GET_ENCODE_PROP"
}
```
##### 获取算法结果配置
http://192.168.13.202/avsjson.php POST    
Params    
```json
{"type":"AVS_GET_ALG_RESULT_PROP"}    
```   
Response   
```json    
{
	"body": {
		"fake_threshold": {
			"default": 0,
			"types": [{
				"content": "5L2O",
				"type": 0
			}, {
				"content": "5Lit",
				"type": 1
			}, {
				"content": "6auY",
				"type": 2
			}]
		},
		"out_result_type": {
			"default": 18,
			"types": [{
				"content": "56iz5a6a6K+G5Yir6Kem5Y+R",
				"type": 1
			}, {
				"content": "6Jma5ouf57q/5ZyI",
				"type": 2
			}, {
				"content": "SU8x6Kem5Y+R",
				"type": 16
			}, {
				"content": "SU8y6Kem5Y+R",
				"type": 32
			}, {
				"content": "SU8z6Kem5Y+R",
				"type": 64
			}, {
				"content": "SU806Kem5Y+R",
				"type": 128
			}]
		},
		"province": {
			"default": 255,
			"types": [{
				"content": "5Lqs",
				"type": 0
			}, {
				"content": "5rSl",
				"type": 1
			}, {
				"content": "5YaA",
				"type": 2
			}, {
				"content": "5pmL",
				"type": 3
			}, {
				"content": "6JKZ",
				"type": 4
			}, {
				"content": "6L69",
				"type": 5
			}, {
				"content": "5ZCJ",
				"type": 6
			}, {
				"content": "6buR",
				"type": 7
			}, {
				"content": "5rKq",
				"type": 8
			}, {
				"content": "6IuP",
				"type": 9
			}, {
				"content": "5rWZ",
				"type": 10
			}, {
				"content": "55qW",
				"type": 11
			}, {
				"content": "6Ze9",
				"type": 12
			}, {
				"content": "6LWj",
				"type": 13
			}, {
				"content": "6bKB",
				"type": 14
			}, {
				"content": "6LGr",
				"type": 15
			}, {
				"content": "6YSC",
				"type": 16
			}, {
				"content": "5rmY",
				"type": 17
			}, {
				"content": "57Kk",
				"type": 18
			}, {
				"content": "5qGC",
				"type": 19
			}, {
				"content": "55C8",
				"type": 20
			}, {
				"content": "5rid",
				"type": 21
			}, {
				"content": "5bed",
				"type": 22
			}, {
				"content": "6LS1",
				"type": 23
			}, {
				"content": "5LqR",
				"type": 24
			}, {
				"content": "6JeP",
				"type": 25
			}, {
				"content": "6ZmV",
				"type": 26
			}, {
				"content": "55SY",
				"type": 27
			}, {
				"content": "6Z2S",
				"type": 28
			}, {
				"content": "5a6B",
				"type": 29
			}, {
				"content": "5paw",
				"type": 30
			}]
		},
		"reco_dis": {
			"default": 0,
			"types": [{
				"content": "2-4m",
				"type": 0
			}, {
				"content": "6-8m",
				"type": 1
			}, {
				"content": "4-6m",
				"type": 2
			}]
		},
		"recognition_type": {
			"default": 550970,
			"types": [{
				"content": "6JOd54mM",
				"type": 1
			}, {
				"content": "6buE54mM",
				"type": 24
			}, {
				"content": "5pWZ57uD6L2m",
				"type": 8192
			}, {
				"content": "6K2m6L2m",
				"type": 32
			}, {
				"content": "5q2m6K2m6L2m",
				"type": 229440
			}, {
				"content": "5Yab6L2m",
				"type": 768
			}, {
				"content": "5riv5r6z",
				"type": 18432
			}, {
				"content": "5L2/6aaG6L2m",
				"type": 1024
			}, {
				"content": "5rCR6Iiq",
				"type": 262144
			}, {
				"content": "5paw6IO95rqQ",
				"type": 1572864
			}, {
				"content": "5bqU5oCl6L2m",
				"type": 2097152
			}, {
				"content": "6aKG5LqL6aaG",
				"type": 4194304
			}, {
				"content": "5peg",
				"type": 8388608
			}]
		},
		"run_mode": {
			"default": 0,
			"types": [{
				"content": "6buY6K6k",
				"type": 0
			}, {
				"content": "5YGc6L2m5Zy6",
				"type": 1
			}, {
				"content": "5Y2h5Y+j",
				"type": 2
			}]
		},
		"snap_image_quality": {
			"default": 70,
			"max": 100,
			"min": 0
		},
		"snap_resolution": {
			"default": 10,
			"types": [{
				"content": "640*360",
				"type": 3
			}, {
				"content": "704*576",
				"type": 5
			}, {
				"content": "1280*720",
				"type": 9
			}, {
				"content": "1920*1080",
				"type": 10
			}, {
				"content": "2304*1296",
				"type": 11
			}]
		}
	},
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_GET_ALG_RESULT_PROP"
}
```
##### 获取多媒体模块对焦参数
http://192.168.13.202/request.php POST    
Params    
```json
{"type":"get_avs_focus_prm","module":"AVS_REQUEST_MESSAGE"}    
```   
Response   
```json    
{
	"body": {
		"auto_focus": 0,
		"digital_ptz_enable": false,
		"digital_ptz_window_size": {
			"height": 0,
			"width": 0,
			"x": 0,
			"y": 0
		},
		"digital_zoom": 1.399999976158142,
		"focus_step": 0,
		"focus_type": 0
	},
	"error_msg": "",
	"state": 200,
	"type": "get_avs_focus_prm"
}
```
##### 多媒体模块获取算法结果参数
http://192.168.13.202/avsjson.php POST    
Params    
```json
{"type":"AVS_GET_ALG_RESULT_PARAM"}    
```   
Response   
```json    
{
	"body": {
		"alg_version": "2016LPRALG",
		"fake_threshold": 0,
		"out_result_type": 1,
		"province": 1,
		"reco_dis": 0,
		"recognition_type": 0,
		"run_mode": 0,
		"snap_image_quality": 100,
		"snap_resolution": 0,
		"time_zone": 0
	},
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_GET_ALG_RESULT_PARAM"
}
```
##### 获取补光灯控制？ 
http://192.168.13.202/avsjson.php Post    
Params    
```json  
{"type":"AVS_GET_LED_CTRL"}    
```   
Response   
```json    
{
	"body": {
		"led_level": 2,
		"led_mode": 3,
		"time_ctrl": [{
			"id": 0,
			"led_level": 2,
			"time_begin": "00:00:00",
			"time_end": "02:03:34",
			"timectrl_enable": true
		}, {
			"id": 1,
			"led_level": 6,
			"time_begin": "02:03:34",
			"time_end": "09:02:23",
			"timectrl_enable": true
		}, {
			"id": 2,
			"led_level": 1,
			"time_begin": "18:00:00",
			"time_end": "24:00:00",
			"timectrl_enable": true
		}]
	},
	"err_msg": "OK",
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_GET_LED_CTRL"
}
```
##### 获取视频编码配置？ 
http://192.168.13.202/avsjson.php Post    
Params    
```json  
{"type":"AVS_GET_ENCODE_PARAM"}    
```   
Response   
```json    
{
	"body": {
		"default_stream": 0,
		"encode_param": [{
			"data_rate": 3072000,
			"encode_type": 0,
			"frame_rate": 25,
			"rate_type": 1,
			"resolution": 10,
			"stream_id": 0,
			"video_quality": 5
		}, {
			"data_rate": 512000,
			"encode_type": 0,
			"frame_rate": 25,
			"rate_type": 1,
			"resolution": 5,
			"stream_id": 1,
			"video_quality": 3
		}, {
			"data_rate": 1024000,
			"encode_type": 1,
			"frame_rate": 15,
			"rate_type": 0,
			"resolution": 9,
			"stream_id": 2,
			"video_quality": 3
		}]
	},
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_GET_ENCODE_PARAM"
}
```
##### 获取算法结果参数
http://192.168.13.202/avsjson.php Post    
Params    
```json  
{"type":"AVS_GET_ALG_RESULT_PARAM"}    
```   
Response   
```json    
{
	"body": {
		"alg_version": "2016LPRALG",
		"fake_threshold": 0,
		"out_result_type": 1,
		"province": 1,
		"reco_dis": 0,
		"recognition_type": 0,
		"run_mode": 0,
		"snap_image_quality": 100,
		"snap_resolution": 0,
		"time_zone": 0
	},
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_GET_ALG_RESULT_PARAM"
}
```
##### 获取识别区域？ 
http://192.168.13.202/avsjson.php Post    
Params    
```json  
{"type":"AVS_GET_VIRLOOP_PRM"}    
```   
Response   
```json    
{
	"body": {
		"virtualloop": {
			"dir": 0,
			"loop": [{
				"enable": false,
				"point": [],
				"point_num": 0
			}],
			"max_plate_width": 400,
			"min_plate_width": 45,
			"trigger_gap": 10,
			"virtualloop_num": 0
		}
	},
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_GET_VIRLOOP_PRM"
}
```
##### 获取虚拟线圈？ 
http://192.168.13.202/avsjson.php Post    
Params    
```json  
{"type":"AVS_GET_RECO_PRM"}    
```   
Response   
```json    
{
	"body": {
		"recognition_area": {
			"polygon": [{
				"enable": false,
				"point": [],
				"point_num": 0
			}],
			"polygon_num": 0
		}
	},
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_GET_RECO_PRM"
}
```
##### 获取视频数据
ws://192.168.13.202:9080/ws.flv?token=17abed60-9180-2eb7-e72b-609f6d96c0da GET    

##### 心跳接口
http://192.168.13.202/webpage_relogin.php POST    
Params    
```json

```   
Response   
```json    
{
	"state": 401
}
```
##### 获取用户权限
http://192.168.13.202/getauth.php POST
Params    
```json
{"type":"get_user_auth"}    
```   
Response   
```json    
{
	"body": {
		"authority": 0
	},
	"state": 200,
	"type": "get_user_auth"
}
0 管理员
```
#### 操作
##### 创建虚拟线圈 
http://192.168.13.202/avsjson.php POST    
Params    
```json  
{"type":"AVS_SET_VIRLOOP_PRM","body":{"virtualloop":{"max_plate_width":400,"min_plate_width":45,"dir":0,"trigger_gap":10,"loop":[{"enable":true,"point_num":4,"point":[{"x":2395,"y":11987},{"x":13988,"y":11987},{"x":15981,"y":14013},{"x":402,"y":14013}]}],"virtualloop_num":1}}}
```   
Response   
```json    
{
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_SET_VIRLOOP_PRM"
}
```
##### 创建识别区域 
http://192.168.13.202/avsjson.php POST    
Params    
```json  
{"type":"AVS_SET_RECO_PRM","body":{"recognition_area":{"polygon":[{"enable":true,"point_num":4,"point":[{"x":1276,"y":2404},{"x":15055,"y":2404},{"x":16139,"y":15937},{"x":209,"y":15937}]}],"polygon_num":1}}}  
```   
Response   
```json    
{
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_SET_RECO_PRM"
}
```
##### 手动触发
http://192.168.13.202/avstrigger.php?_=1646033475057 GET    
Response   
```json    
OK
```
##### 手动触发视频截图
http://192.168.13.202/snapshot/last_ivs_result.jpg?1646035490999 GET    
Response   
```json    
图像数据
```
##### 出入口 
http://192.168.13.202/dgjson.php POST    
Params    
```json  
出口 - {"group_cfg":{"group_vzids":[]},"state":200,"type":"set_group_cfg","vzid":{"ast_type":0,"enable_group":true,"ip_addr":"192.168.13.202","name":"","sn":"c806ca86-8de9c3f4","type":"output"}}  
入口 - {"group_cfg":{"group_vzids":[]},"state":200,"type":"set_group_cfg","vzid":{"ast_type":0,"enable_group":true,"ip_addr":"192.168.13.202","name":"","sn":"c806ca86-8de9c3f4","type":"input"}}  
```   
Response   
```json    
{
	"state": 200,
	"type": "set_group_cfg"
}
```
##### 运动方向 
http://192.168.13.202/seteventruleexhtm.php POST    
Params    
```json  
双向 - 1:1:50:400:10:0
从上至下 - 1:1:50:400:10:1
从下至上 - 1:1:45:400:10:2  
```   
Response   
```json    
OK seteventrule1
```
http://192.168.13.202/geteventruleexhtm.php POST    
Params    
```json  
0
```   
Response   
```json    
OK geteventruleex=1:1:45:400:10:1
```
##### 补光模式 
http://192.168.13.202/avsjson.php POST    
Params    
```json  
关闭补光 - {"type":"AVS_SET_LED_CTRL","body":{"time_ctrl":[{"time_begin":"00:00:00","time_end":"04:30:00","timectrl_enable":true,"led_level":2,"id":0},{"time_begin":"04:30:00","time_end":"10:45:00","timectrl_enable":false,"led_level":-1,"id":1},{"time_begin":"10:45:00","time_end":"24:00:00","timectrl_enable":true,"led_level":0,"id":2}],"led_mode":2}}
智能补光 - {"type":"AVS_SET_LED_CTRL","body":{"led_mode":0}}
手动补光 - {"type":"AVS_SET_LED_CTRL","body":{"time_ctrl":[{"time_begin":"00:00:00","time_end":"04:30:00","timectrl_enable":true,"led_level":2,"id":0},{"time_begin":"04:30:00","time_end":"10:45:00","timectrl_enable":false,"led_level":-1,"id":1},{"time_begin":"10:45:00","time_end":"24:00:00","timectrl_enable":true,"led_level":0,"id":2}],"led_mode":3}}
```   
Response   
```json    
{
	"err_msg": "OK",
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_SET_LED_CTRL"
}
```
##### 补光参数
http://192.168.13.202/avsjson.php POST    
Params    
```json  
{"type":"AVS_SET_LED_CTRL","body":{"time_ctrl":[{"time_begin":"00:00:00","time_end":"02:00:00","timectrl_enable":true,"led_level":2,"id":0},{"time_begin":"02:00:00","time_end":"09:00:00","timectrl_enable":false,"led_level":-1,"id":1},{"time_begin":"09:00:00","time_end":"24:00:00","timectrl_enable":true,"led_level":1,"id":2}],"led_mode":3}}
```   
Response   
```json    
{
	"err_msg": "OK",
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_SET_LED_CTRL"
}
```
##### 预设省份 
http://192.168.13.202/avsjson.php POST    
Params    
```json  
{"type":"AVS_SET_ALG_RESULT_PARAM","body":{"province":22}}
```   
Response   
```json    
{
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_SET_ALG_RESULT_PARAM"
}
```
##### 云台控制 
http://192.168.13.202/request.php POST    
Params    
```json  
上 - {"type":"set_cloud_ctrl","module":"BUS_REQUEST_MESSAGE","body":{"dir":2,"degree":2}}
下 - {"type":"set_cloud_ctrl","module":"BUS_REQUEST_MESSAGE","body":{"dir":4,"degree":2}}
左 - {"type":"set_cloud_ctrl","module":"BUS_REQUEST_MESSAGE","body":{"dir":32,"degree":2}}
右 - {"type":"set_cloud_ctrl","module":"BUS_REQUEST_MESSAGE","body":{"dir":16,"degree":2}}
停 - {"type":"set_cloud_ctrl","module":"BUS_REQUEST_MESSAGE","body":{"dir":8,"degree":0}}
```   
Response   
```json    
{
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "set_cloud_ctrl"
}
```
##### 电子变倍
http://192.168.13.202/request.php POST    
Params    
```json  
{"type":"set_avs_focus_prm","module":"AVS_REQUEST_MESSAGE","body":{"auto_focus":0,"digital_ptz_enable":false,"digital_zoom":1.6,"focus_step":0,"focus_type":0,"digital_ptz_window_size":{"height":0,"width":0,"x":0,"y":0}}}
```   
Response   
```json    
{
	"error_msg": "",
	"state": 200,
	"type": "set_avs_focus_prm"
}
```
## 数据查询页
#### 操作
##### 图片预览查询 
http://192.168.13.202/request.php POST    
Params    
```json  
{"type":"STORE_SEARCH_IMG_REQUEST","module":"STORE_BUSINESS_REQUEST","body":{"page_size":100,"page_num":1,"condition":{"plate":"","start_time":"2022-02-28 00:00:00","end_time":"2022-02-28 16:20:45","trigger":0}}}
```   
Response   
```json    
{
	"body": {
		"pics_cnt": 1,
		"pics_total": 1,
		"rows": [{
			"alarm": 0,
			"block_index": 2,
			"channel": 0,
			"event_rec_time": 0,
			"id": 5,
			"image_size": 323384,
			"page_index": 17,
			"plate": "_无_",
			"recg_time": 1646035581,
			"retry": 0,
			"struct_size": 152,
			"trigger": 4
		}]
	},
	"err_msg": "All Done",
	"state": 200,
	"type": "STORE_SEARCH_IMG_REQUEST"
}
```
##### 双击图片日志条目
http://192.168.13.202/request.php POST    
Params    
```json  
{"type":"STORE_READ_IMG_REQUEST","module":"STORE_BUSINESS_REQUEST","body":{"id":"5"}}
```   
Response   
```json    
{
	"body": {
		"image_path": "/htmldata/picdata02.pic",
		"image_size": 323384,
		"struct_size": 152
	},
	"err_msg": "All Done",
	"state": 200,
	"type": "STORE_READ_IMG_REQUEST"
}
```
##### 图片数据
http://192.168.13.202/htmldata/picdata02.pic?1646036565157 GET    

Response   
``` 
图片数据
```
## 高级设置页
### 识别设置
#### 请求
##### 获取识别车牌
http://192.168.13.202/getivsctrl.php POST    
Params    
```json  
8:1:MA==
```   
Response   
```json    
OK ivsctrl=8:1:MA==
```
##### 获取相机参数
http://192.168.13.202/avsjson.php POST    
Params    
```json  
{"type":"AVS_GET_CAPTURE_PRM"}    
```   
Response   
```json    
{
	"body": {
		"duration": 10,
		"max_duration": 60,
		"mode": 0,
		"none_duration": 10
	},
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_GET_CAPTURE_PRM"
}
```
##### 获取语音对讲 - 对讲设置
http://192.168.13.202/request.php Post    
Params    
```json  
{"type":"evs_get_gpioin_func","module":"EVS_BUS_REQUEST"}    
```   
Response   
```json    
{
	"body": [{
		"is_enable": 0,
		"msg_module": "",
		"msg_type": "",
		"source": 0,
		"tri_state": 0
	}, {
		"is_enable": 0,
		"msg_module": "",
		"msg_type": "",
		"source": 1,
		"tri_state": 0
	}],
	"err_msg": "All done",
	"state": 200,
	"type": "evs_get_gpioin_func"
}
```
##### 获取？ 
http://192.168.13.202/getivsctrl.php Post    
Params    
```  
4:1:MA==
```   
Response   
```    
OK ivsctrl=4:1:MQ==
```
##### 获取？ 
http://192.168.13.202/geteventruleexhtm.php Post    
Params    
```  
0
```   
Response   
```    
OK geteventruleex=1:1:45:400:10:2
```

##### 获取算法结果配置
http://192.168.13.202/avsjson.php Post    
Params    
```json  
{"type":"AVS_GET_ALG_RESULT_PROP"}    
```   
Response   
```json    
{
	"body": {
		"fake_threshold": {
			"default": 0,
			"types": [{
				"content": "5L2O",
				"type": 0
			}, {
				"content": "5Lit",
				"type": 1
			}, {
				"content": "6auY",
				"type": 2
			}]
		},
		"out_result_type": {
			"default": 18,
			"types": [{
				"content": "56iz5a6a6K+G5Yir6Kem5Y+R",
				"type": 1
			}, {
				"content": "6Jma5ouf57q/5ZyI",
				"type": 2
			}, {
				"content": "SU8x6Kem5Y+R",
				"type": 16
			}, {
				"content": "SU8y6Kem5Y+R",
				"type": 32
			}, {
				"content": "SU8z6Kem5Y+R",
				"type": 64
			}, {
				"content": "SU806Kem5Y+R",
				"type": 128
			}]
		},
		"province": {
			"default": 255,
			"types": [{
				"content": "5Lqs",
				"type": 0
			}, {
				"content": "5rSl",
				"type": 1
			}, {
				"content": "5YaA",
				"type": 2
			}, {
				"content": "5pmL",
				"type": 3
			}, {
				"content": "6JKZ",
				"type": 4
			}, {
				"content": "6L69",
				"type": 5
			}, {
				"content": "5ZCJ",
				"type": 6
			}, {
				"content": "6buR",
				"type": 7
			}, {
				"content": "5rKq",
				"type": 8
			}, {
				"content": "6IuP",
				"type": 9
			}, {
				"content": "5rWZ",
				"type": 10
			}, {
				"content": "55qW",
				"type": 11
			}, {
				"content": "6Ze9",
				"type": 12
			}, {
				"content": "6LWj",
				"type": 13
			}, {
				"content": "6bKB",
				"type": 14
			}, {
				"content": "6LGr",
				"type": 15
			}, {
				"content": "6YSC",
				"type": 16
			}, {
				"content": "5rmY",
				"type": 17
			}, {
				"content": "57Kk",
				"type": 18
			}, {
				"content": "5qGC",
				"type": 19
			}, {
				"content": "55C8",
				"type": 20
			}, {
				"content": "5rid",
				"type": 21
			}, {
				"content": "5bed",
				"type": 22
			}, {
				"content": "6LS1",
				"type": 23
			}, {
				"content": "5LqR",
				"type": 24
			}, {
				"content": "6JeP",
				"type": 25
			}, {
				"content": "6ZmV",
				"type": 26
			}, {
				"content": "55SY",
				"type": 27
			}, {
				"content": "6Z2S",
				"type": 28
			}, {
				"content": "5a6B",
				"type": 29
			}, {
				"content": "5paw",
				"type": 30
			}]
		},
		"reco_dis": {
			"default": 0,
			"types": [{
				"content": "2-4m",
				"type": 0
			}, {
				"content": "6-8m",
				"type": 1
			}, {
				"content": "4-6m",
				"type": 2
			}]
		},
		"recognition_type": {
			"default": 550970,
			"types": [{
				"content": "6JOd54mM",
				"type": 1
			}, {
				"content": "6buE54mM",
				"type": 24
			}, {
				"content": "5pWZ57uD6L2m",
				"type": 8192
			}, {
				"content": "6K2m6L2m",
				"type": 32
			}, {
				"content": "5q2m6K2m6L2m",
				"type": 229440
			}, {
				"content": "5Yab6L2m",
				"type": 768
			}, {
				"content": "5riv5r6z",
				"type": 18432
			}, {
				"content": "5L2/6aaG6L2m",
				"type": 1024
			}, {
				"content": "5rCR6Iiq",
				"type": 262144
			}, {
				"content": "5paw6IO95rqQ",
				"type": 1572864
			}, {
				"content": "5bqU5oCl6L2m",
				"type": 2097152
			}, {
				"content": "6aKG5LqL6aaG",
				"type": 4194304
			}, {
				"content": "5peg",
				"type": 8388608
			}]
		},
		"run_mode": {
			"default": 0,
			"types": [{
				"content": "6buY6K6k",
				"type": 0
			}, {
				"content": "5YGc6L2m5Zy6",
				"type": 1
			}, {
				"content": "5Y2h5Y+j",
				"type": 2
			}]
		},
		"snap_image_quality": {
			"default": 70,
			"max": 100,
			"min": 0
		},
		"snap_resolution": {
			"default": 10,
			"types": [{
				"content": "640*360",
				"type": 3
			}, {
				"content": "704*576",
				"type": 5
			}, {
				"content": "1280*720",
				"type": 9
			}, {
				"content": "1920*1080",
				"type": 10
			}, {
				"content": "2304*1296",
				"type": 11
			}]
		}
	},
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_GET_ALG_RESULT_PROP"
}
```
##### 获取新能源车牌字段限制
http://192.168.13.202/avsjson.php POST    
Params    
```json  
{"type":"get_new_energy_plate_support"}    
```   
Response   
```json    
{
	"body": {
		"support": 0
	},
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "get_new_energy_plate_support"
}
```
##### 获取输出车辆信息
http://192.168.13.202/avsjson.php Post    
Params    
```json  
{"type":"get_car_info_support"}    
```   
Response   
```json    
{
	"body": {
		"car_brand_support": 0,
		"car_color_support": 0,
		"car_type_support": 0
	},
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "get_car_info_support"
}
```
##### 获取算法结果配置
http://192.168.13.202/avsjson.php POST    
Params    
```json  
{"type":"AVS_GET_ALG_RESULT_PARAM"}    
```   
Response   
```json    
{
	"body": {
		"alg_version": "2016LPRALG",
		"fake_threshold": 0,
		"out_result_type": 1,
		"province": 22,
		"reco_dis": 0,
		"recognition_type": 0,
		"run_mode": 0,
		"snap_image_quality": 100,
		"snap_resolution": 0,
		"time_zone": 0
	},
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_GET_ALG_RESULT_PARAM"
}
```
#### 操作
##### 触发模式 - 获取视频触发状态
http://192.168.13.202/getivsctrl.php POST    
Params    
```  
4:1:MA==
```   
Response   
```json    
OK ivsctrl=4:1:Mw==
```
##### 触发模式 - 视频触发 - 勾选虚拟线圈
http://192.168.13.202/ivsctrl.php POST    
Params    
```  
5:1:Mw==
```   
Response   
```    
OK
```
##### 触发模式 - 视频触发 - 取消勾选虚拟线圈
http://192.168.13.202/ivsctrl.php POST    
Params    
```  
5:1:MQ==
```   
Response   
```    
OK
```
##### 触发模式 - 视频触发 - 勾选稳定识别
http://192.168.13.202/ivsctrl.php POST    
Params    
```  
5:1:MQ==
```   
Response   
```    
OK
```
##### 触发模式 - 视频触发 - 取消勾选稳定识别
http://192.168.13.202/ivsctrl.php POST    
Params    
```  
5:1:MA==
```   
Response   
```    
OK
```
##### 触发模式 - 外部触发 - 勾选电平输入1
http://192.168.13.202/ivsctrl.php POST    
Params    
```  
5:2:MTY	
```   
Response   
```    
OK
```
##### 触发模式 - 外部触发 - 取消勾选电平输入1
http://192.168.13.202/ivsctrl.php POST    
Params    
```  
5:1:MA==
```   
Response   
```    
OK
```
##### 触发模式 - 外部触发 - 勾选电平输入2
http://192.168.13.202/ivsctrl.php POST    
Params    
```  
5:2:MzI	
```   
Response   
```    
OK
```
##### 触发模式 - 外部触发 - 取消勾选电平输入2
http://192.168.13.202/ivsctrl.php POST    
Params    
```  
5:1:MA==
```   
Response   
```    
OK
```
##### 识别参数 - 图片分辨率 
http://192.168.13.202/avsjson.php POST    
Params    
```json  
{"type":"AVS_SET_ALG_RESULT_PARAM","body":{"snap_resolution":3,"snap_image_quality":100,"fake_threshold":53}}
snap_resolution: 640 -> 3 ,704 -> 5 ,1280 -> 9 ,1920 -> 10 ,2304 -> 11
```   
Response   
```json    
{
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_SET_ALG_RESULT_PARAM"
}
```
##### 识别参数 - 图片质量 
http://192.168.13.202/avsjson.php POST    
Params    
```json  
{"type":"AVS_SET_ALG_RESULT_PARAM","body":{"snap_resolution":5,"snap_image_quality":100,"fake_threshold":53}}	
snap_image_quality: 10~100, 步进10
```   
Response   
```json    
{
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_SET_ALG_RESULT_PARAM"
}
```
##### 识别参数 - 连续抓拍模式
http://192.168.13.202/avsjson.php POST    
Params    
```json  
{"type":"AVS_SET_CAPTURE_PRM","body":{"mode":1,"duration":10,"none_duration":10,"max_duration":60}}
mode：0-关闭 1-车牌触发 2-定时触发 3-线圈触发
duration：连续触发间隔（秒）
none_duration：无车牌抓拍间隔（秒）
max_duration：最长抓拍时间(秒)
```   
Response   
```json    
{
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_SET_CAPTURE_PRM"
}
```
##### 获取相机参数
http://192.168.13.202/avsjson.php POST    
Params    
```json  
{"type":"AVS_GET_CAPTURE_PRM"}    
```   
Response   
```json    
{
	"body": {
		"duration": 10,
		"max_duration": 60,
		"mode": 1,
		"none_duration": 10
	},
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_GET_CAPTURE_PRM"
}
```
##### 识别参数 - 车牌像素限制 
http://192.168.13.202/seteventruleexhtm.php POST    
Params    
```  
1:1:50:400:10:2
```
车牌像素限制(像素)：50~400
相同车牌触发间隔(秒)：10 
Response   
```    
OK seteventrule1
```
##### 获取车牌识别参数规则
http://192.168.13.202/geteventruleexhtm.php
Params    
```  
0
```   
Response   
```    
OK geteventruleex=1:1:50:400:10:2
```
##### 识别参数 - 无车牌触发 - 勾选输出无车牌信息 
http://192.168.13.202/ivsctrl.php POST    
Params    
```  
7:11:LTIxNDc0ODM2NDg	
```   
Response   
```    
OK
```
##### 识别参数 - 获取无车牌暑输出状态
http://192.168.13.202/getivsctrl.php POST    
Params    
```  
8:1:MA==
```   
Response   
```    
OK ivsctrl=8:10:MjE0NzQ4MzY0OA==
```

##### 识别参数 - 无车牌触发 - 取消勾选输出无车牌信息 
http://192.168.13.202/ivsctrl.php POST    
Params    
```
7:1:MA==	
```   
Response   
```    
OK
```
##### 识别参数 - 无车牌触发 - 勾选车牌防伪 POST    
http://192.168.13.202/ivsctrl.php POST    
Params    
```  
7:9:NTM2ODcwOTEy	
```   
Response   
```    
OK
```
##### 识别参数 - 勾选车牌防伪 - 虚假车牌告警
http://192.168.13.202/vb.htm?filtfakeplate=1&_=1646036087952  Get

##### 识别参数 - 勾选车牌防伪 - 虚假车牌过滤
http://192.168.13.202/vb.htm?filtfakeplate=0&_=1646036087953  Get

##### 识别参数 - 勾选车牌防伪 - 防伪匹配度 
http://192.168.13.202/avsjson.php POST    
Params    
```json  
{"type":"AVS_SET_ALG_RESULT_PARAM","body":{"snap_resolution":11,"snap_image_quality":90,"fake_threshold":73}}
fake_threshold: 低-53 中-73 高-93
```   
Response   
```json    
{
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_SET_ALG_RESULT_PARAM"
}
```
##### 识别参数 - 无车牌触发 - 取消勾选输出无车牌信息 
http://192.168.13.202/ivsctrl.php POST    
Params    
```  
7:1:MA==	
```   
Response   
```    
OK
```
##### 识别参数 - 输出车辆信息 - 勾选输出车标信息 
http://192.168.13.202/avsjson.php POST    
Params    
```json  
{"type":"set_car_info_support","body":{"car_brand_support":1,"car_type_support":0,"car_color_support":0}}	
car_brand_support 输出车标信息 1, 0
car_type_support 识别车辆类型 1, 0
car_color_support 识别车身颜色 1, 0
```   
Response   
```json    
{
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "set_car_info_support"
}
```
##### 获取输出车辆信息
http://192.168.13.202/avsjson.php POST    
Params    
```json  
{"type":"get_car_info_support"}    
```   
Response   
```json    
{
	"body": {
		"car_brand_support": 1,
		"car_color_support": 0,
		"car_type_support": 0
	},
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "get_car_info_support"
}
```
##### 识别参数 - 新能源车牌字段限制 - 支持D与F 
http://192.168.13.202/avsjson.php POST    
Params    
```json  
{"type":"set_new_energy_plate_support","body":{"support":1}}
```   
Response   
```json    
{
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "set_new_energy_plate_support"
}
```
##### 获取新能源车牌字段限制
http://192.168.13.202/avsjson.php POST    
Params    
```json  
{"type":"get_new_energy_plate_support"}    
```   
Response   
```json    
{
	"body": {
		"support": 1
	},
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "get_new_energy_plate_support"
}
```
##### 识别车牌 - 蓝牌
http://192.168.13.202/ivsctrl.php POST    
Params    
```  
7:1:Mg==
```   
Response   
```    
OK
```
### 音视频
#### 请求
##### 获取视频流播放配置
http://192.168.13.202/request.php POST    
Params    
```json  
{"type":"get_live_stream_type","module":"BUS_WEB_REQUEST"}
```   
Response   
```json    
{
	"body": {
		"enable_auth": true,
		"live_stream_type": "flv",
		"port": 9080,
		"pubkey": "LS0tLS1CRUdJTiBQVUJMSUMgS0VZLS0tLS0KTUlHZk1BMEdDU3FHU0liM0RRRUJBUVVBQTRHTkFEQ0JpUUtCZ1FEQkphZ3JZMmcvYjVkbDJoS2x5WEs4bXBjdwpxeWZVRDYwK09tZmVxdFUvOHkyaE5NL1pnbStiM05MS3ZvbE0yZ3VZUU9tS2M4cWNlVm84WGVLMTJHQmk0QUNBClF2WUlBbGVVUHZqbkZCM1J3Y01SVlhwUUVxQ2lnWnRtbFE3U1ZadTZneC8zdm9MKzFPaXBmN3lZM3pGOS91UjgKNXFTNlFKdmRGeFN6QWg3aVBRSURBUDdWCi0tLS0tRU5EIFBVQkxJQyBLRVktLS0tLQo=",
		"token": "d088a2e4-7087-56b4-8e92-c8322519d523",
		"transport_type": {
			"0": "ws",
			"1": "http"
		}
	},
	"err_msg": "OK",
	"state": 200,
	"type": "get_live_stream_type"
}
```
##### 获取相辅相机开关量
http://192.168.13.202/dgjson.php POST  
params
```json
{"type":"get_group_shared_io"}	
```
Response    
```json
{
	"state": 200,
	"type": "get_group_shared_io",
	"value": 0
}
```
##### 获取外设防伪车牌后获取了什么东西
http://192.168.13.202/vb.htm?boa_eventjsonreq={"type":"get_addition_gpio"}&_=1646102553605 GET     
Response   
```json    
OK={"body":{"delay_stop_time":0,"enable":0,"frequency_time":1000,"input_gpio":0,"output_gpio":0},"err_msg":"All done","state":200,"type":"get_addition_gpio"}
```
##### 获取语音对讲 - 对讲设置
http://192.168.13.202/request.php POST    
Params    
```json  
{"type":"evs_get_gpioin_func","module":"EVS_BUS_REQUEST"}    
```   
Response   
```json    
{
	"body": [{
		"is_enable": 0,
		"msg_module": "",
		"msg_type": "",
		"source": 0,
		"tri_state": 0
	}, {
		"is_enable": 0,
		"msg_module": "",
		"msg_type": "",
		"source": 1,
		"tri_state": 0
	}],
	"err_msg": "All done",
	"state": 200,
	"type": "evs_get_gpioin_func"
}
```
##### 获取音频配置
http://192.168.13.202/getvoiceinfo.php POST    
Params    
```json  
{"type":"AVS_GET_AUDIO_PROP"}    
```   
Response   
```json    
{
	"body": {
		"audio_input": {
			"default": 0,
			"enable": true,
			"types": [{
				"content": "TGluZSBpbg==",
				"type": 0
			}, {
				"content": "TWljIGlu",
				"type": 1
			}]
		},
		"audio_level": {
			"default": 20,
			"enable": true,
			"max": 100,
			"min": 0
		},
		"audio_out_level": {
			"default": 20,
			"enable": true,
			"max": 100,
			"min": 0
		},
		"noise_filter": {
			"default": 0,
			"enable": true,
			"types": [{
				"content": "5YWz6Zet",
				"type": 0
			}, {
				"content": "5omT5byA",
				"type": 1
			}]
		}
	},
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_GET_AUDIO_PROP"
}
```
##### 获取图像解码参数信息
http://192.168.13.202/avsjson.php POST    
Params    
```json  
{"type":"AVS_GET_ENCODE_PROP"}	
```
##### 获取授权配置
http://192.168.13.202/request.php POST    
Params    
```json  
{"type":"get_ws_stream_cfg","module":"BUS_WEB_REQUEST"}    
```   
Response   
```json    
{
	"body": {
		"flv_enable": true,
		"flv_enable_auth": true,
		"mjpeg_enable": false,
		"mjpeg_enable_auth": false
	},
	"err_msg": "OK",
	"state": 200,
	"type": "get_ws_stream_cfg"
}
```
##### 获取用户OSD参数
http://192.168.13.202/avsjson.php POST    
Params    
```json  
{"type":"AVS_GET_OSD_USER_PRM"}    
```   
Response   
```json    
{
	"body": {
		"user_osd": {
			"user_osd_param": [{
				"color": 0,
				"display": 1,
				"front_size": 3,
				"id": 0,
				"text": "56ys5LiA6KGM"
			}, {
				"color": 1,
				"display": 1,
				"front_size": 3,
				"id": 1,
				"text": "c2Vjb25kIGxpbmU="
			}, {
				"color": 2,
				"display": 1,
				"front_size": 3,
				"id": 2,
				"text": "dGjkuInooYw="
			}, {
				"color": 3,
				"display": 1,
				"front_size": 3,
				"id": 3,
				"text": "56ys5Zub6KGMT1NEIFRDUCA="
			}],
			"x_pos": 10,
			"y_pos": 10
		}
	},
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_GET_OSD_USER_PRM"
}
```
##### 获取OSD参数
http://192.168.13.202/avsjson.php POST    
{"type":"AVS_GET_OSD_PARAM"}    
```   
Response   
```json    
{
	"body": {
		"osd_param": {
			"date": {
				"date_format": 1,
				"enable": 1,
				"pos": 1310736
			},
			"datetime": {
				"enable": 1,
				"pos": 35913750,
				"time_format": 1
			},
			"text": {
				"context": "T1NEIFRleHQ=",
				"enable": 1,
				"pos": 34603537
			}
		},
		"realtime_show": {
			"car_info": 0,
			"distance": null,
			"extend_on_bottom": 1,
			"plate_pos": true,
			"realtime_result": 1,
			"virtualloop_area": 1
		}
	},
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_GET_OSD_PARAM"
}
```
##### 获取视频配置信息
http://192.168.13.202/avsjson.php POST    
Params    
```json  
{"type":"AVS_GET_VIDEO_PARAM_PROPERTY"}	
```
##### 获取图像解码参数信息
http://192.168.13.202/avsjson.php POST    
Params    
```json  
{"type":"AVS_GET_ENCODE_PROP"}    
```   
Response   
```json    
{
	"body": {
		"brightness": {
			"default": 50,
			"enable": true,
			"max": 100,
			"min": 0
		},
		"contrast": {
			"default": 50,
			"enable": true,
			"max": 100,
			"min": 0
		},
		"flip": {
			"default": 0,
			"enable": true,
			"types": [{
				"content": "5Y6f5aeL5Zu+5YOP",
				"type": 0
			}, {
				"content": "5LiK5LiL57+76L2s",
				"type": 1
			}, {
				"content": "5bem5Y+z57+76L2s",
				"type": 2
			}, {
				"content": "5Lit5b+D57+76L2s",
				"type": 3
			}]
		},
		"max_exposure": {
			"default": 3,
			"types": [{
				"content": "0~1ms",
				"type": 1
			}, {
				"content": "0~2ms",
				"type": 2
			}, {
				"content": "0~3ms",
				"type": 3
			}, {
				"content": "0~4ms",
				"type": 4
			}]
		},
		"max_gain": {
			"default": 50,
			"enable": true,
			"max": 100,
			"min": 0
		},
		"saturation": {
			"default": 50,
			"enable": true,
			"max": 100,
			"min": 0
		}
	},
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_GET_VIDEO_PARAM_PROPERTY"
}
```
##### 获取音频输入参数
http://192.168.13.202/getvoiceinfo.php POST    
Params    
```json  
{"type":"AVS_GET_AUDIO_PRM"}    
```   
Response   
```json    
{
	"body": {
		"audio_input": 0,
		"audio_level": 100,
		"audio_out_level": 100,
		"noise_filter": 0
	},
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_GET_AUDIO_PRM"
}
```
##### 获取视频参数
http://192.168.13.202/avsjson.php POST    
Params    
```json  
{"type":"AVS_GET_VIDEO_PARAM"}    
```   
Response   
```json    
{
	"body": {
		"video_param": {
			"brightness": 50,
			"contrast": 50,
			"flip": 0,
			"max_exposure": 3,
			"max_exposure_ms": null,
			"max_gain": 50,
			"saturation": 50
		}
	},
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_GET_VIDEO_PARAM"
}
```
#### 操作
##### 图像参数
http://192.168.13.202/avsjson.php POST    
Params    
```json  
{"type":"AVS_SET_VIDEO_PARAM","body":{"video_param":{"brightness":80}}}	
brightness - 亮度
{"type":"AVS_SET_VIDEO_PARAM","body":{"video_param":{"contrast":25}}}
contrast - 对比度 
{"type":"AVS_SET_VIDEO_PARAM","body":{"video_param":{"saturation":39}}}	
saturation - 饱和度
{"type":"AVS_SET_VIDEO_PARAM","body":{"video_param":{"max_gain":62}}}	
max_gain - 最大增益
{"type":"AVS_SET_VIDEO_PARAM","body":{"video_param":{"max_exposure":1}}}	
max_exposure - 曝光时间 0~1ms
{"type":"AVS_SET_VIDEO_PARAM","body":{"video_param":{"flip":1}}}
flip - 图像翻转 0 原始 1 上下 2 左右 3 中心
{"type":"AVS_SET_VIDEO_PARAM","body":{"video_param":{"brightness":50,"contrast":50,"saturation":50,"max_gain":50,"max_exposure":3,"flip":0}}}	
恢复默认 - "brightness":50,"contrast":50,"saturation":50,"max_gain":50,"max_exposure":3,"flip":0
```   
Response   
```json    
{
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_SET_VIDEO_PARAM"
}
```
##### 获取图像参数
http://192.168.13.202/avsjson.php POST    
Params    
```json  
{"type":"AVS_GET_VIDEO_PARAM"}    
```   
Response   
```json    
{
	"body": {
		"video_param": {
			"brightness": 80,
			"contrast": 50,
			"flip": 0,
			"max_exposure": 3,
			"max_exposure_ms": 3.33299994468689,
			"max_gain": 50,
			"saturation": 50
		}
	},
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_GET_VIDEO_PARAM"
}
```
##### OSD用户参数
http://192.168.13.202/avsjson.php POST    
Params    
```json  
{"type":"AVS_SET_OSD_USER_PRM","body":{"user_osd":{"user_osd_param":[{"id":0,"display":1,"color":0,"front_size":3,"text":"56ys5LiA6KGM"},{"id":1,"display":1,"color":1,"front_size":3,"text":"c2Vjb25kIGxpbmU="},{"id":2,"display":1,"color":2,"front_size":3,"text":"dGjkuInooYw="},{"id":3,"display":1,"color":3,"front_size":3,"text":"56ys5Zub6KGMT1NEIFRDUCA="}],"x_pos":10,"y_pos":10}}}
```   
Response   
```json    
{
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_SET_OSD_USER_PRM"
}
```
##### OSD参数
http://192.168.13.202/avsjson.php POST    
Params    
```json  
{"type":"AVS_SET_OSD_PARAM","body":{"realtime_show":{"realtime_result":0,"virtualloop_area":1,"car_info":0,"extend_on_bottom":1},"osd_param":{"date":{"enable":1,"pos":1376273,"date_format":1},"datetime":{"enable":1,"pos":35979287,"time_format":1},"text":{"enable":1,"pos":34603538,"context":"T1NEIFRleHQ="}}}}
```   
Response   
```json    
{
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_SET_OSD_PARAM"
}
```
##### 获取OSD用户参数
http://192.168.13.202/avsjson.php POST    
Params    
```json  
{"type":"AVS_GET_OSD_USER_PRM"}    
```   
Response   
```json    
{
	"body": {
		"user_osd": {
			"user_osd_param": [{
				"color": 0,
				"display": 1,
				"front_size": 3,
				"id": 0,
				"text": "56ys5LiA6KGM"
			}, {
				"color": 1,
				"display": 1,
				"front_size": 3,
				"id": 1,
				"text": "c2Vjb25kIGxpbmU="
			}, {
				"color": 2,
				"display": 1,
				"front_size": 3,
				"id": 2,
				"text": "dGjkuInooYw="
			}, {
				"color": 3,
				"display": 1,
				"front_size": 3,
				"id": 3,
				"text": "56ys5Zub6KGMT1NEIFRDUCA="
			}],
			"x_pos": 10,
			"y_pos": 10
		}
	},
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_GET_OSD_USER_PRM"
}
```
##### 获取OSD参数
http://192.168.13.202/avsjson.php POST    
Params    
```json  
{"type":"AVS_GET_OSD_PARAM"}
```   
Response   
```json    
{
	"body": {
		"osd_param": {
			"date": {
				"date_format": 1,
				"enable": 1,
				"pos": 1376273
			},
			"datetime": {
				"enable": 1,
				"pos": 35979287,
				"time_format": 1
			},
			"text": {
				"context": "T1NEIFRleHQ=",
				"enable": 1,
				"pos": 34603538
			}
		},
		"realtime_show": {
			"car_info": 0,
			"distance": null,
			"extend_on_bottom": 1,
			"plate_pos": true,
			"realtime_result": 0,
			"virtualloop_area": 1
		}
	},
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_GET_OSD_PARAM"
}
```
##### 编码参数 - FLV
http://192.168.13.202/avsjson.php POST    
Params    
```json  
{"type":"AVS_SET_ENCODE_PARAM","body":{"default_stream":0,"encode_param":[{"stream_id":0,"data_rate":3072000,"frame_rate":25,"resolution":10,"encode_type":0,"rate_type":1,"video_quality":5}]}}
{"type":"AVS_SET_ENCODE_PARAM","body":{"default_stream":1,"encode_param":[{"stream_id":1,"data_rate":512000,"frame_rate":25,"resolution":5,"encode_type":0,"rate_type":1,"video_quality":3}]}}
{"type":"AVS_SET_ENCODE_PARAM","body":{"default_stream":2,"encode_param":[{"stream_id":2,"data_rate":1024000,"frame_rate":15,"resolution":9,"encode_type":1,"rate_type":0,"video_quality":3}]}}
```   
Response   
```json    
{
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_SET_ENCODE_PARAM"
}
```
##### 获取编码参数
http://192.168.13.202/avsjson.php POST    
Params    
```json  
{"type":"AVS_GET_ENCODE_PARAM"}
```   
Response   
```json    
{
	"body": {
		"default_stream": 0,
		"encode_param": [{
			"data_rate": 3072000,
			"encode_type": 0,
			"frame_rate": 25,
			"rate_type": 1,
			"resolution": 10,
			"stream_id": 0,
			"video_quality": 5
		}, {
			"data_rate": 512000,
			"encode_type": 0,
			"frame_rate": 25,
			"rate_type": 1,
			"resolution": 5,
			"stream_id": 1,
			"video_quality": 3
		}, {
			"data_rate": 1024000,
			"encode_type": 1,
			"frame_rate": 15,
			"rate_type": 0,
			"resolution": 9,
			"stream_id": 2,
			"video_quality": 3
		}]
	},
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_GET_ENCODE_PARAM"
}
```
##### 语音对讲 - 对讲设置
http://192.168.13.202/request.php POST    
Params    
```json  
{"type":"evs_set_gpioin_func","module":"EVS_BUS_REQUEST","body":[{"is_enable":1,"msg_module":"PS_TALK_REQUESTION","msg_type":{"type":"AVS_TALK_REQUEST"},"source":0,"tri_state":0},{"is_enable":0,"msg_module":"","msg_type":"","source":1,"tri_state":0}]}
{"type":"evs_set_gpioin_func","module":"EVS_BUS_REQUEST","body":[{"is_enable":0,"msg_module":"PS_TALK_REQUESTION","msg_type":{"type":"AVS_TALK_REQUEST"},"source":0,"tri_state":0},{"is_enable":1,"msg_module":"PS_TALK_REQUESTION","msg_type":{"type":"AVS_TALK_REQUEST"},"source":1,"tri_state":0}]}
```   
Response   
```json    
{
	"err_msg": "All done",
	"state": 200,
	"type": "evs_set_gpioin_func"
}
```
##### 获取语音对讲 - 对讲设置
http://192.168.13.202/request.php POST    
Params    
```json  
{"type":"evs_get_gpioin_func","module":"EVS_BUS_REQUEST"}
```   
Response   
```json    
{
	"body": [{
		"is_enable": 1,
		"msg_module": "PS_TALK_REQUESTION",
		"msg_type": {
			"type": "AVS_TALK_REQUEST"
		},
		"source": 0,
		"tri_state": 0
	}, {
		"is_enable": 0,
		"msg_module": "",
		"msg_type": "",
		"source": 1,
		"tri_state": 0
	}],
	"err_msg": "All done",
	"state": 200,
	"type": "evs_get_gpioin_func"
}
```
##### 语音对讲 - 音频设置
http://192.168.13.202/getvoiceinfo.php POST    
Params    
```json  
{"type":"AVS_SET_AUDIO_PRM","body":{"audio_level":100,"audio_out_level":100,"audio_input":1,"noise_filter":0}}
{"type":"AVS_SET_AUDIO_PRM","body":{"audio_level":100,"audio_out_level":30,"audio_input":1,"noise_filter":1}}
```   
Response   
```json    
{
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_SET_AUDIO_PRM"
}
```
##### 设置ws流配置
http://192.168.13.202/request.php POST 
params
```json
{"type":"set_ws_stream_cfg","module":"BUS_WEB_REQUEST","body":{"flv_enable":false,"flv_enable_auth":true,"mjpeg_enable":true,"mjpeg_enable_auth":false}}
```
Response    
```json
{
	"err_msg": "OK",
	"state": 200,
	"type": "set_ws_stream_cfg"
}
```
##### 获取ws流配置
http://192.168.13.202/request.php POST 
params
```json
{"type":"get_ws_stream_cfg","module":"BUS_WEB_REQUEST"}
```
Response    
```
{
	"body": {
		"flv_enable": false,
		"flv_enable_auth": true,
		"mjpeg_enable": true,
		"mjpeg_enable_auth": false
	},
	"err_msg": "OK",
	"state": 200,
	"type": "get_ws_stream_cfg"
}
```
##### 获取live流配置
http://192.168.13.202/request.php POST    
params
```json
{"type":"get_live_stream_type","module":"BUS_WEB_REQUEST"}
```
Response    
```
{
	"body": {
		"enable_auth": false,
		"live_stream_type": "mjpeg",
		"port": 9080,
		"pubkey": "LS0tLS1CRUdJTiBQVUJMSUMgS0VZLS0tLS0KTUlHZk1BMEdDU3FHU0liM0RRRUJBUVVBQTRHTkFEQ0JpUUtCZ1FESEJMelV0blFkYlVYZVZRNHc2WVJqSW14aQpwdENBOWk0WTJ5d0tsazJ0K1lUeGlKM3R5N2FRN3laVE93VHJXZU5Kb1lHODZWUTBURi8xUzlpUERRQUsrRnpvCmxjNVpPMDY1VW1yTElxbVZTTTZ0bHhQRWs3QlUrM3JRSzJTVFRmQy9LK2U3UzBiQmN2VDYwTFRUczJxTHV3UVAKRU1Sb2dWdS81bWJ1WW9ZR0ZRSURBUDdWCi0tLS0tRU5EIFBVQkxJQyBLRVktLS0tLQo=",
		"token": "039258ae-3a87-42f2-1248-9def7a849a6c",
		"transport_type": {
			"0": "ws",
			"1": "http"
		}
	},
	"err_msg": "OK",
	"state": 200,
	"type": "get_live_stream_type"
}
```
### 基础网络
#### 请求
##### 获取网络基本配置
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"get_net_and_port"}    
```   
Response   
```json    
{
	"body": {
		"dhcp": 0,
		"dns": "114.114.114.114",
		"dns2": "8.8.8.8",
		"gateway": "192.168.1.11",
		"http_port": 80,
		"https_en": 0,
		"ip": "192.168.13.202",
		"netmask": "255.255.128.0",
		"rtsp_port": 8557
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_net_and_port"
}
```
##### 获取UPNP配置
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"ss_get_upnp_net"}    
```   
Response   
```json    
{
	"body": {
		"enable": 0,
		"http_port": 30001,
		"rtsp_port": 30002,
		"status": 0
	},
	"err_msg": "All done",
	"state": 200,
	"type": "ss_get_upnp_net"
}
```
##### 获取DDNS配置
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"ss_get_ddns_net"}    
```   
Response   
```json    
{
	"body": {
		"brandurl": "www.3322.net",
		"enable": 0,
		"name": "",
		"password": "123456",
		"status": 0,
		"username": "root"
	},
	"err_msg": "All done",
	"state": 200,
	"type": "ss_get_ddns_net"
}
```
##### 获取设备发现
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"get_discover"}    
```   
Response   
```json    
{
	"body": {
		"discover_mode": 0
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_discover"
}
```
##### 获取MTU参数
http://192.168.13.202/mtujson.php POST    
Params    
```json  
{"type":"get_net_mtu"}    
```   
Response   
```json    
{
	"body": {
		"mtu": 1500
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_net_mtu"
}
```
##### 获取APN配置参数
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"get_apn_config"}    
```   
Response   
```json    
{
	"body": {
		"apnaddr": "192.168.1.12",
		"authentication": 0,
		"passwd": "apn_pass",
		"username": "apn_user"
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_apn_config"
}
```
##### 获取￥G当前状态
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"get_4g_cur_state"}    
```   
Response   
```json    
{
	"body": {
		"4g_iccid": "",
		"call_way": 1,
		"imei": "",
		"ip": "",
		"link_company": 0,
		"link_state": 0,
		"net_state": 0,
		"net_type": 0,
		"singal_state": 0
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_4g_cur_state"
}
```
##### 获取ONENET参数
http://192.168.13.202/request.php POST    
Params    
```json  
{"type":"get_onenet_prm","module":"ONENET_REQUEST_MSG"}    
```   
Response   
```json    
{
	"body": {
		"onenet": {
			"enable": 0,
			"key": "",
			"mqttport": 1883,
			"mqttserver": "",
			"productid": ""
		},
		"push_property": {
			"location": {
				"altitude": 0,
				"coordinate": 1,
				"enable": 0,
				"latitude": 0,
				"longitude": 0
			},
			"sn": {
				"enable": 0
			},
			"software": {
				"enable": 0
			},
			"time_span": 0
		}
	},
	"state": 200,
	"type": "get_onenet_prm"
}
```

#### 操作
##### 设置基础网络
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"set_net_and_port","body":{"ip":"192.168.13.201","netmask":"255.255.128.0","gateway":"192.168.1.11","dns":"114.114.114.114","dns2":"8.8.8.8","http_port":80,"rtsp_port":8557}}
```
##### 4G设置 - 基础配置
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"set_4g_config","body":{"link_level":1,"cloud_addr":"61.139.2.69","net_priority":0}}
net_priority 0 有线优先 1 4G优先
{
	"err_msg": "All done",
	"state": 200,
	"type": "set_4g_config"
}
```
##### 4G设置 - APN
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"set_apn_config","body":{"apnaddr":"192.168.1.12","username":"apn_user","passwd":"apn_pass","authentication":0}}
authentication 0 关闭 1 PAP 2 CHAP 3 PAP或CHAP
{
	"err_msg": "All done",
	"state": 200,
	"type": "set_4g_config"
}
```
##### 获取APN设置
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"get_apn_config"}
{
	"body": {
		"apnaddr": "192.168.1.12",
		"authentication": 0,
		"passwd": "apn_pass",
		"username": "apn_user"
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_apn_config"
}
```
##### 4G设置 - 基础配置
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"set_4g_config","body":{"link_level":1,"cloud_addr":"61.139.2.69","net_priority":0}}
{
	"err_msg": "All done",
	"state": 200,
	"type": "set_4g_config"
}
```

##### 设置DDNS
http://192.168.13.202/sys_request_message.php POST    
Params    
```json  
{"type":"ss_set_ddns_net","body":{"enable":1,"brandurl":"www.3322.net","name":"192.168.1.1","username":"root","password":"123456","status":0}}
{
	"err_msg": "All done",
	"state": 200,
	"type": "ss_set_ddns_net"
}
```
##### 获取DDNS设置
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"ss_get_ddns_net"}
{
	"body": {
		"brandurl": "www.3322.net",
		"enable": 0,
		"name": "192.168.1.1",
		"password": "123456",
		"status": 0,
		"username": "root"
	},
	"err_msg": "All done",
	"state": 200,
	"type": "ss_get_ddns_net"
}
```
##### 设置UPNP
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"ss_set_upnp_net","body":{"enable":0,"http_port":30001,"rtsp_port":30002}}
{
	"err_msg": "All done",
	"state": 200,
	"type": "ss_set_upnp_net"
}
```
##### 获取UPNP设置
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"ss_get_upnp_net"}
{
	"body": {
		"enable": 0,
		"http_port": 30001,
		"rtsp_port": 30002,
		"status": 0
	},
	"err_msg": "All done",
	"state": 200,
	"type": "ss_get_upnp_net"
}
```
##### 网络诊断？ 
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"ss_help_network","body":{"cmd":"killall ping traceroute nslookup"}}
{"type":"ss_help_network","body":{"cmd":"ping -w 200"}}
{
	"err_msg": "All done",
	"state": 200,
	"type": "ss_help_network"
}
```
##### 设置设备发现
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"set_discover","body":{"discover_mode":0}}
discover_mode: 0 主动 1 被动
{
	"err_msg": "All done",
	"state": 200,
	"type": "set_discover"
}
##### 获取设备发现
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"get_discover"}
{
	"body": {
		"discover_mode": 0
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_discover"
}
```
##### 设置MTU
http://192.168.13.202/mtujson.php POST    
Params    
```json  
{"type":"set_net_mtu","body":{"mtu":1500}}
{
	"err_msg": "All done",
	"state": 200,
	"type": "set_net_mtu"
}
```
##### 获取MTU设置
http://192.168.13.202/mtujson.php POST    
Params    
```json  
{"type":"get_net_mtu"}
{
	"body": {
		"mtu": 1500
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_net_mtu"
}
```
##### 设置ONENET
http://192.168.13.202/request.php POST    
Params    
```json  
{"type":"set_onenet_prm","module":"ONENET_REQUEST_MSG","body":{"onenet":{"enable":0,"mqttport":1883,"mqttserver":"","productid":"","key":""},"push_property":{"time_span":0,"location":{"enable":0,"altitude":0,"coordinate":1,"latitude":0,"longitude":0},"software":{"enable":0},"sn":{"enable":0}}}}
{
	"body": null,
	"state": 200,
	"type": "set_onenet_prm"
}
```
##### 获取ONENET设置
http://192.168.13.202/request.php POST    
Params    
```json  
{"type":"get_onenet_prm","module":"ONENET_REQUEST_MSG"}
{
	"body": {
		"onenet": {
			"enable": 0,
			"key": "",
			"mqttport": 1883,
			"mqttserver": "",
			"productid": ""
		},
		"push_property": {
			"location": {
				"altitude": 0,
				"coordinate": 1,
				"enable": 0,
				"latitude": 0,
				"longitude": 0
			},
			"sn": {
				"enable": 0
			},
			"software": {
				"enable": 0
			},
			"time_span": 60
		}
	},
	"state": 200,
	"type": "get_onenet_prm"
}
```
### 白名单
#### 请求
##### 获取白名单模糊匹配
http://192.168.13.202/dboprnew.php POST    
Params    
```json  
{"type":"get_wl_fuzzy"}    
```   
Response   
```json    
{
	"body": {
		"fuzzy_ignore_cc": 0,
		"fuzzy_query_len": 0,
		"fuzzy_query_type": 0
	},
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "get_wl_fuzzy"
}
```
##### 获取白名单检查状态
http://192.168.13.202/dboprnew.php POST    
Params    
```json  
{"type":"get_wl_check_status"}    
```   
Response   
```json    
{
	"body": {
		"dev_time": {
			"time_day": 1,
			"time_hour": 13,
			"time_min": 59,
			"time_mon": 3,
			"time_sec": 26,
			"time_year": 2022
		},
		"filter_enable": 0,
		"offline_status": 0,
		"white_list_flag": 1
	},
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "get_wl_check_status"
}
```
#### 操作
##### 白名单启用条件
http://192.168.13.202/dboprnew.php POST    
Params    
```json  
{"type":"set_wl_check_status","body":{"filter_enable":1}}
filter_enable: 0 脱机自动启动 1 启用 2 不启用
{
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "set_wl_check_status"
}
```
##### 白名单模糊匹配
http://192.168.13.202/dboprnew.php POST    
Params    
```json  
{"type":"set_wl_fuzzy","body":{"fuzzy_query_type":1,"fuzzy_query_len":1,"fuzzy_ignore_cc":0}}
fuzzy_query_type: 0 精确 1 相似 2 模糊
fuzzy_query_len: 模糊模式下 允许误识别长度 1 2 3
fuzzy_ignore_cc: 忽略汉字 0 不勾选 1 勾选
```   
Response   
```json    
{
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "set_wl_fuzzy"
}
```
##### 白名单查询
http://192.168.13.202/dbopr.php POST    
Params    
```json  
{"cmd":"white_list_operator","id":"999999","operator_type":"select_count_by_plate","plate":""}    
```   
Response   
```json    
{
	"cmd": "white_list_operator",
	"id": "999999",
	"operator_type": "select_count_by_plate",
	"state_code": 200,
	"total_count": 2
}
```
##### 白名单查询
http://192.168.13.202/dbopr.php POST    
Params    
```json  
{"cmd":"white_list_operator","id":"999999","operator_type":"select_fuzzy","plate":"","start_pos":0,"select_count":50}    
```   
Response   
```json    
{
	"cmd": "white_list_operator",
	"dldb_rec": [{
		"context": "",
		"enable": 1,
		"enable_time": "2021-12-31 09:46:00",
		"need_alarm": 0,
		"overdue_time": "2022-01-02 09:46:00",
		"plate": "粤BF47625",
		"seg_time_end": "00:00:00",
		"seg_time_start": "00:00:00",
		"time_seg_enable": 0
	}, {
		"context": "",
		"enable": 1,
		"enable_time": "2021-12-31 09:43:00",
		"need_alarm": 0,
		"overdue_time": "2022-01-02 09:43:00",
		"plate": "粤BU55S6",
		"seg_time_end": "00:00:00",
		"seg_time_start": "00:00:00",
		"time_seg_enable": 0
	}],
	"id": "999999",
	"operator_type": "select_fuzzy",
	"state_code": 200
}
```
### 高级网络
#### 请求
##### 获取所有HTTP设置
http://192.168.13.202/vb.htm?gethttpconfigall={"type":"get_http_cfg"}&_=1646113962019 GET    
Response    
```
OK={"body":{"centerserver":{"enable_ssl":0,"hostname":"MTkyLjE2OC4xLjEwNg==","http_timeout":5,"port":80,"ssl_port":443},"cs_alarm_gioin":{"enable":0,"uri":"L2RldmljZW1hbmFnZW1lbnQvcGhwL2dpby5waHA="},"cs_alarm_plate":{"big_img":0,"enable":0,"plate_rlt_level":0,"retransmission":0,"small_img":0,"uri":"L2RldmljZW1hbmFnZW1lbnQvcGhwL3BsYXRlcmVzdWx0LnBocA=="},"cs_dev_reg":{"enable":0,"uri":"L2RldmljZW1hbmFnZW1lbnQvcGhwL3JlY2VpdmVkZXZpY2VpbmZvLnBocA=="},"cs_serial":{"enable":0,"uri":"L2RldmljZW1hbmFnZW1lbnQvcGhwL3NlcmlhbC5waHA="},"http_ip_ext":{"IpExt":[]},"offline_status":0,"proxy_http":{"big_img":0,"enable":0,"small_img":0,"uri":"L2RldmljZW1hbmFnZW1lbnQvcGhwL3BsYXRlcmVzdWx0LnBocA=="},"repush_nums":0,"serv_poll_status":0,"ssl_ca":{"ca_enable":0,"ca_file_exist":0}},"err_msg":"OK","state":200,"state_code":200,"type":"get_http_cfg"}
```
##### 获取VPN配置
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"ss_get_vpn_net"}    
```   
Response   
```json    
{
	"body": {
		"cfg_data": "",
		"check_file": [],
		"enable": 0
	},
	"err_msg": "All done",
	"state": 200,
	"type": "ss_get_vpn_net"
}
```
##### 获取ftp配置
http://192.168.13.202/vb.htm?gethttpconfigall={"type":"get_ftp_cfg"}&_=1646113962020 GET    
Response    
```
OK={"body":{"enable":0,"foldername":"default_name","password":"ftpuser","port":21,"server_ip":"192.168.1.16","username":"ftpuser"},"err_msg":"OK","state":200,"state_code":200,"type":"get_ftp_cfg"}
```
##### 获取stp配置
http://192.168.13.202/stp.php POST    
Params    
```json  
{"type":"get_stp_conf"}    
```   
Response   
```json    
{
	"body": {
		"addr": "https://device.pdns.cloud",
		"connected": 0,
		"enabled": 1
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_stp_conf"
}
```
##### 获取1400配置
http://192.168.13.202/request.php POST    
Params    
```json  
{"type":"get_http_t1400_cfg","module":"HTTPSENDER_GAT1400_CONFIG_ALL"}    
```   
Response   
```json    
{
	"body": {
		"connected": 0,
		"device_id": "MzIwNTA1MDAwMDEzMjAwMDAwMDc=",
		"enable": 0,
		"heartbeat_uri": "L1ZJSUQvU3lzdGVtL0tlZXBhbGl2ZQ==",
		"motor_vehicles_uri": "L1ZJSUQvTW90b3JWZWhpY2xlcw==",
		"register_uri": "L1ZJSUQvU3lzdGVtL1JlZ2lzdGVy",
		"server_auth": "HWIAAAAAHWIyAWjDiYjRsVbxlw==",
		"server_ip": "MTkyLjE2OC4xLjE2",
		"server_port": 8080,
		"timeout": 5,
		"unregister_uri": "L1ZJSUQvU3lzdGVtL1VuUmVnaXN0ZXI="
	},
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "get_http_t1400_cfg"
}
```
#### 操作
##### HTTP推送设置
http://192.168.13.202/vb.htm?sethttpconfigall={"type":"set_http_cfg","body":{"centerserver":{"hostname":"MTkyLjE2OC4xLjEwNg==","port":80,"enable_ssl":0,"ssl_port":443,"http_timeout":5},"cs_dev_reg":{"enable":0,"uri":"L2RldmljZW1hbmFnZW1lbnQvcGhwL3JlY2VpdmVkZXZpY2VpbmZvLnBocA=="},"cs_alarm_plate":{"clear_offline":0,"enable":0,"retransmission":0,"uri":"L2RldmljZW1hbmFnZW1lbnQvcGhwL3BsYXRlcmVzdWx0LnBocA==","plate_rlt_level":0,"big_img":0,"small_img":0},"cs_alarm_gioin":{"enable":0,"uri":"L2RldmljZW1hbmFnZW1lbnQvcGhwL2dpby5waHA="},"cs_serial":{"enable":0,"uri":"L2RldmljZW1hbmFnZW1lbnQvcGhwL3NlcmlhbC5waHA="},"http_ip_ext":{"IpExt":[]},"ssl_ca":{"ca_enable":0},"offline_status":0,"serv_poll_status":0,"repush_nums":0,"proxy_http":{"enable":0,"uri":"L2RldmljZW1hbmFnZW1lbnQvcGhwL3BsYXRlcmVzdWx0LnBocA==","big_img":0,"small_img":0}}}&_=1646191759041 GET    
Response   
```json    
OK {"err_msg":"OK","state":200,"state_code":200,"type":"set_http_cfg"}
```
##### 获取HTTP推送设置
http://192.168.13.202/vb.htm?gethttpconfigall={"type":"get_http_cfg"}&_=1646191759042 GET    
Response   
```json    
OK={"body":{"centerserver":{"enable_ssl":0,"hostname":"MTkyLjE2OC4xLjEwNg==","http_timeout":5,"port":80,"ssl_port":443},"cs_alarm_gioin":{"enable":0,"uri":"L2RldmljZW1hbmFnZW1lbnQvcGhwL2dpby5waHA="},"cs_alarm_plate":{"big_img":0,"enable":0,"plate_rlt_level":0,"retransmission":0,"small_img":0,"uri":"L2RldmljZW1hbmFnZW1lbnQvcGhwL3BsYXRlcmVzdWx0LnBocA=="},"cs_dev_reg":{"enable":0,"uri":"L2RldmljZW1hbmFnZW1lbnQvcGhwL3JlY2VpdmVkZXZpY2VpbmZvLnBocA=="},"cs_serial":{"enable":0,"uri":"L2RldmljZW1hbmFnZW1lbnQvcGhwL3NlcmlhbC5waHA="},"http_ip_ext":{"IpExt":[]},"offline_status":0,"proxy_http":{"big_img":0,"enable":0,"small_img":0,"uri":"L2RldmljZW1hbmFnZW1lbnQvcGhwL3BsYXRlcmVzdWx0LnBocA=="},"repush_nums":0,"serv_poll_status":0,"ssl_ca":{"ca_enable":0,"ca_file_exist":0}},"err_msg":"OK","state":200,"state_code":200,"type":"get_http_cfg"}
```
##### HTTP推送测试 - 开始
http://192.168.13.202/vb.htm?testhttpserver={"type":"test_http_server","body":{"start_test":1}}&_=1646191759043 GET    
Response   
```json    
OK {"err_msg":"OK","state":200,"state_code":200,"type":"test_http_server"}
```
##### HTTP推送测试 - 停止
http://192.168.13.202/vb.htm?testhttpserver={"type":"test_http_server","body":{"start_test":0}}&_=1646191759051 GET    
Response   
```json    
OK {"err_msg":"OK","state":200,"state_code":200,"type":"test_http_server"}
```
##### FTP - 发送测试
http://192.168.13.202/sendftptestfile.php POST    
Params    
```json  
{"type":"send_ftp_test_file"}
```   
Response   
```json    
{
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"test_file": "ftp://192.168.1.16/default_name/ftp_test.txt",
	"type": "send_ftp_test_file"
}
```
##### FTP配置 - 启用 1 关闭 0
http://192.168.13.202/vb.htm?sethttpconfigall={"body":{"enable":1,"server_ip":"192.168.1.16","port":21,"username":"ftpuser","password":"ftpuser","foldername":"default_name"},"type":"set_ftp_cfg"}&_=1646191759052 GET    
enable: 启用 1 关闭 0
```   
Response   
```json    
OK {"err_msg":"OK","state":200,"state_code":200,"type":"set_ftp_cfg"}
```
##### 获取FTP配置
http://192.168.13.202/vb.htm?gethttpconfigall={"type":"get_ftp_cfg"}&_=1646191759053 GET    
```   
Response   
```json    
OK={"body":{"enable":1,"foldername":"default_name","password":"ftpuser","port":21,"server_ip":"192.168.1.16","username":"ftpuser"},"err_msg":"OK","state":200,"state_code":200,"type":"get_ftp_cfg"}
```

##### PNDS配置
http://192.168.13.202/stp.php POST    
Params    
```json  
{"type":"set_stp_conf","body":{"enabled":1,"addr":"https://device.pdns.cloud"}}
{
	"err_msg": "All done",
	"state": 200,
	"type": "set_stp_conf"
}
```
##### 获取PNDS配置
http://192.168.13.202/stp.php POST    
Params    
```json  
{"type":"get_stp_conf"}
{
	"body": {
		"addr": "https://device.pdns.cloud",
		"connected": 2,
		"enabled": 1
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_stp_conf"
}
```
##### VPN配置
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"ss_set_vpn_net","body":{"enable":1,"hostname":"192.168.1.1","port":10000}}
```   
Response   
```json    
{
	"err_msg": "All done",
	"state": 200,
	"type": "ss_set_vpn_net"
}
```
##### 获取VPN配置
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"ss_get_vpn_net"}
```   
Response   
```json    
{
	"body": {
		"cfg_data": "",
		"check_file": [],
		"enable": 1
	},
	"err_msg": "All done",
	"state": 200,
	"type": "ss_get_vpn_net"
}
```
##### 获取1400配置
http://192.168.13.202/request.php POST    
Params    
```json  
{"type":"get_http_t1400_cfg","module":"HTTPSENDER_GAT1400_CONFIG_ALL"}    
```   
Response   
```json    
{
	"body": {
		"connected": 0,
		"device_id": "MzIwNTA1MDAwMDEzMjAwMDAwMDc=",
		"enable": 0,
		"heartbeat_uri": "L1ZJSUQvU3lzdGVtL0tlZXBhbGl2ZQ==",
		"motor_vehicles_uri": "L1ZJSUQvTW90b3JWZWhpY2xlcw==",
		"register_uri": "L1ZJSUQvU3lzdGVtL1JlZ2lzdGVy",
		"server_auth": "HmIAAAAAHmLQTAPFgvHAqvqUqg==",
		"server_ip": "MTkyLjE2OC4xLjE2",
		"server_port": 8080,
		"timeout": 5,
		"unregister_uri": "L1ZJSUQvU3lzdGVtL1VuUmVnaXN0ZXI="
	},
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "get_http_t1400_cfg"
}
```
##### 配置1400参数
http://192.168.13.202/request.php POST    
Params    
```json  
{"type":"set_http_t1400_cfg","module":"HTTPSENDER_GAT1400_CONFIG_ALL","body":{"enable":0,"server_port":8080,"timeout":5,"server_ip":"MTkyLjE2OC4xLjE2","server_auth":"Ie0eYuLi4uJn6yAaNL8k83o9Jg==","register_uri":"L1ZJSUQvU3lzdGVtL1JlZ2lzdGVy","unregister_uri":"L1ZJSUQvU3lzdGVtL1VuUmVnaXN0ZXI=","motor_vehicles_uri":"L1ZJSUQvTW90b3JWZWhpY2xlcw==","heartbeat_uri":"L1ZJSUQvU3lzdGVtL0tlZXBhbGl2ZQ==","device_id":"MzIwNTA1MDAwMDEzMjAwMDAwMDc="}}
{
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "set_http_t1400_cfg"
}
```
### 外设管理
#### 请求
##### 获取语音配置？ 
http://192.168.13.202/avsjson.php POST    
Params    
```json  
{"type":"ps_get_voice_config"}    
```   
Response   
```json    
{
	"error_msg": "OK",
	"state": 200,
	"talk_io": 0,
	"type": "ps_get_voice_config",
	"voice_defalut_interval": 100,
	"voice_defalut_male": 1,
	"voice_defalut_volume": 100
}
```
##### 输出配置 - 获取防伪车牌
http://192.168.13.202/vb.htm?getlinkagecfg&_=1646113962022 GET    
Response    
```
OK getlinkagecfg={
   "black_list" : [],
   "device_capacity" : {
      "ado_enable" : 1,
      "e4g_num" : 1,
      "fan_num" : 0,
      "img_reset_num" : 0,
      "io_in_num" : 2,
      "io_out_num" : 2,
      "key_reset_num" : 1,
      "led_num" : 0,
      "mcu_num" : 0,
      "moto_num" : 0,
      "opensdk_en" : 1,
      "stp_enable" : 1,
      "ttl_num" : 0,
      "tty_num" : 2,
      "wifi_num" : 0
   },
   "enable_fake_plate" : 1,
   "ext_ioctl1" : [],
   "ext_ioctl2" : [],
   "ext_ioctl3" : [],
   "ext_ioctl4" : [],
   "no_licence" : [],
   "not_white_list" : [],
   "special_plates" : [],
   "white_list" : [ 56 ]
}
```
##### 获取GPIO开闸默认时间 
http://192.168.13.202/vb.htm?boa_busjsonreq={"type":"get_def_out_time"}&_=1646113962023 GET    
Response    
```
OK={"body":{"def_out_time":500},"err_msg":"OK","state":200,"state_code":200,"type":"get_def_out_time"}
```
##### 获取外设防伪车牌后获取了什么东西
http://192.168.13.202/vb.htm?boa_eventjsonreq={"type":"get_addition_gpio"}&_=1646113962024 GET    
Response    
```
OK={"body":{"delay_stop_time":0,"enable":0,"frequency_time":1000,"input_gpio":0,"output_gpio":0},"err_msg":"All done","state":200,"type":"get_addition_gpio"}
```
##### 获取外设车辆配置
http://192.168.13.202/vb.htm?getwebspesialplates={"type":"get_special_plates"}&_=1646113962025 GET    
Response    
```
OK={"body":{"plates":[{"index":0,"name":"5pyq55+l6L2m54mM","status":0},{"index":1,"name":"6JOd54mM","status":0},{"index":2,"name":"6buR54mM","status":0},{"index":3,"name":"5Y2V5o6S6buE54mM","status":0},{"index":4,"name":"5Y+M5o6S6buE54mM","status":0},{"index":5,"name":"6K2m6L2m6L2m54mM","status":0},{"index":6,"name":"5q2m6K2m6L2m54mM","status":0},{"index":7,"name":"5Liq5oCn5YyW6L2m54mM","status":0},{"index":8,"name":"5Y2V5o6S5Yab6L2m54mM","status":0},{"index":9,"name":"5Y+M5o6S5Yab6L2m54mM","status":0},{"index":10,"name":"5L2/6aaG6L2m54mM","status":0},{"index":11,"name":"6aaZ5riv6L+b5Ye65Lit5Zu95aSn6ZmG6L2m54mM","status":0},{"index":12,"name":"5Yac55So6L2m54mM","status":0},{"index":13,"name":"5pWZ57uD6L2m54mM","status":0},{"index":14,"name":"5r6z6Zeo6L+b5Ye65Lit5Zu95aSn6ZmG6L2m54mM","status":0},{"index":15,"name":"5Y+M5bGC5q2m6K2m6L2m54mM","status":0},{"index":16,"name":"5q2m6K2m5oC76Zif6L2m54mM","status":1},{"index":17,"name":"5Y+M5bGC5q2m6K2m5oC76Zif6L2m54mM","status":0},{"index":18,"name":"5rCR6Iiq6L2m54mM","status":0},{"index":19,"name":"5paw6IO95rqQ6L2m54mM","status":0},{"index":20,"name":"5paw6IO95rqQ6buE54mM","status":0},{"index":21,"name":"5bqU5oCl6L2m54mM","status":0},{"index":22,"name":"6aKG5LqL6aaG6L2m54mM","status":0}]},"err_msg":"OK","state":200,"state_code":200,"type":"get_special_plates"}
```
##### 获取串口
http://192.168.13.202/vb.htm?paratest=uart.0&_=1646113962026 GET    
Response    
```
OK uart.0=OTYwMDowOjg6MQ==
```

##### 获取补光灯？ 
http://192.168.13.202/avsjson.php POST    
Params    
```json  
{"type":"AVS_GET_LED_PROP"}    
```   
Response   
```json    
{
	"body": {
		"led_level": {
			"default": 2,
			"max": 4,
			"min": -1,
			"types": [{
				"content": "5YWz6Zet",
				"type": -1
			}, {
				"content": "Muexsw==",
				"type": 0
			}, {
				"content": "NOexsw==",
				"type": 1
			}, {
				"content": "Nuexsw==",
				"type": 2
			}, {
				"content": "N+exsw==",
				"type": 3
			}, {
				"content": "OOexsw==",
				"type": 4
			}]
		},
		"led_mode": [{
			"content": "5pm66IO9",
			"type": 0
		}, {
			"content": "5bi45Lqu",
			"type": 1
		}, {
			"content": "5bi454Gt",
			"type": 2
		}, {
			"content": "5pe26Ze05q61",
			"type": 3
		}]
	},
	"err_msg": "OK",
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_GET_LED_PROP"
}
```
##### 获取外置补光灯
http://192.168.13.202/request.php POST    
Params    
```json  
{"type":"get_flashlamp_info","module":"EVS_BUS_REQUEST"}    
```   
Response   
```json    
{
	"body": {
		"flash_info": {
			"delay_time": 50,
			"light_time": 3000
		},
		"input_gpio": 0,
		"light_mode": 4,
		"output_gpio": 0,
		"time_ctrl": [{
			"id": 0,
			"time_begin": "00:00:00",
			"time_end": "09:00:00",
			"timectrl_enable": 0
		}, {
			"id": 0,
			"time_begin": "09:00:00",
			"time_end": "18:00:00",
			"timectrl_enable": 0
		}, {
			"id": 0,
			"time_begin": "18:00:00",
			"time_end": "24:00:00",
			"timectrl_enable": 0
		}]
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_flashlamp_info"
}
```
##### 获取？ 
http://192.168.13.202/evtjson.php POST    
Params    
```json  
{"type":"evs_gpio_test_ctrl","body":{"io_number":0,"io_opera":2,"io_type":1}}    
```   
Response   
```json    
{
	"body": {
		"io_status": 1
	},
	"err_msg": "All done",
	"state": 200,
	"type": "evs_gpio_test_ctrl"
}
```
##### 获取？ 
http://192.168.13.202/evtjson.php POST    
Params    
```json  
{"type":"evs_gpio_test_ctrl","body":{"io_number":1,"io_opera":2,"io_type":1}}    
```   
Response   
```json    
{
	"body": {
		"io_status": 1
	},
	"err_msg": "All done",
	"state": 200,
	"type": "evs_gpio_test_ctrl"
}
```
##### 获取？ 
http://192.168.13.202/evtjson.php POST    
Params    
```json  
{"type":"evs_gpio_test_ctrl","body":{"io_number":0,"io_opera":2,"io_type":2}}    
```   
Response   
```json    
{
	"body": {
		"io_status": 0
	},
	"err_msg": "All done",
	"state": 200,
	"type": "evs_gpio_test_ctrl"
}
```
##### 获取？ 
http://192.168.13.202/evtjson.php POST    
Params    
```json  
{"type":"evs_gpio_test_ctrl","body":{"io_number":1,"io_opera":2,"io_type":2}}    
```   
Response   
```json    
{
	"body": {
		"io_status": 0
	},
	"err_msg": "All done",
	"state": 200,
	"type": "evs_gpio_test_ctrl"
}
```
##### 获取补光灯控制？
http://192.168.13.202/avsjson.php POST    
Params    
```json  
{"type":"AVS_GET_LED_CTRL"}    
```   
Response   
```json    
{
	"body": {
		"led_level": -1,
		"led_mode": 3,
		"time_ctrl": [{
			"id": 0,
			"led_level": 2,
			"time_begin": "00:00:00",
			"time_end": "04:30:00",
			"timectrl_enable": true
		}, {
			"id": 1,
			"led_level": -1,
			"time_begin": "04:30:00",
			"time_end": "09:00:00",
			"timectrl_enable": false
		}, {
			"id": 2,
			"led_level": 1,
			"time_begin": "09:00:00",
			"time_end": "24:00:00",
			"timectrl_enable": true
		}]
	},
	"err_msg": "OK",
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_GET_LED_CTRL"
}
```

#### 操作
##### 输出配置 - 防伪车牌
http://192.168.13.202/vb.htm?setlinkagecfg={"white_list":[56,40,1485],"not_white_list":[56,40,1485],"no_licence":[56,40,1485],"black_list":[56,40,1485],"special_plates":[56,40,1485],"ext_ioctl1":[56,40],"ext_ioctl2":[56,40],"ext_ioctl3":[],"ext_ioctl4":[],"offline_alarm":[],"enable_fake_plate":0}&_=1646185193572
Response    
```
OK setlinkagecfg
```
##### 输出配置 - 获取防伪车牌
http://192.168.13.202/vb.htm?boa_eventjsonreq={"type":"get_addition_gpio"}&_=1646185193565
Response    
```
OK getlinkagecfg={
   "black_list" : [ 56, 40, 1485 ],
   "device_capacity" : {
      "ado_enable" : 1,
      "e4g_num" : 1,
      "fan_num" : 0,
      "img_reset_num" : 0,
      "io_in_num" : 2,
      "io_out_num" : 2,
      "key_reset_num" : 1,
      "led_num" : 0,
      "mcu_num" : 0,
      "moto_num" : 0,
      "opensdk_en" : 1,
      "stp_enable" : 1,
      "ttl_num" : 0,
      "tty_num" : 2,
      "wifi_num" : 0
   },
   "enable_fake_plate" : 0,
   "ext_ioctl1" : [ 56, 40 ],
   "ext_ioctl2" : [ 56, 40 ],
   "ext_ioctl3" : [],
   "ext_ioctl4" : [],
   "no_licence" : [ 56, 40, 1485 ],
   "not_white_list" : [ 56, 40, 1485 ],
   "special_plates" : [ 56, 40, 1485 ],
   "white_list" : [ 56, 40, 1485 ]
}
```
##### 获取防伪车牌后获取了什么东西？
http://192.168.13.202/vb.htm?getlinkagecfg&_=1646185193564 GET    
Response    
```
OK={"body":{"delay_stop_time":0,"enable":0,"frequency_time":1000,"input_gpio":0,"output_gpio":0},"err_msg":"All done","state":200,"type":"get_addition_gpio"}
```

##### 串口配置
http://192.168.13.202/vb.htm?uart=OTYwMDowOjg6MQ==.0&_=1646185193575 GET    
Response    
```
OK uart
```

##### GPIO开闸 - 默认开闸时间
http://192.168.13.202/vb.htm?boa_busjsonreq={"type":"set_def_out_time","body":{"def_out_time":500}}&_=1646185193576 GET    
Response    
```
OK={"err_msg":"OK","state":200,"state_code":200,"type":"set_def_out_time"}
```
##### 获取GPIO开闸默认时间
http://192.168.13.202/vb.htm?boa_busjsonreq={"type":"get_def_out_time"}&_=1646185193578 GET    
Response    
```
OK={"body":{"def_out_time":500},"err_msg":"OK","state":200,"state_code":200,"type":"get_def_out_time"}
```
##### GPIO开闸 - 二次开闸配置
http://192.168.13.202/vb.htm?boa_eventjsonreq={"type":"set_addition_gpio","body":{"enable":0,"frequency_time":1000,"delay_stop_time":0,"input_gpio":0,"output_gpio":0}}&_=1646185193577 GET    
Response    
```
OK={"err_msg":"All done","state":200,"type":"set_addition_gpio"}
```
##### GPIO开闸 - 获取二次开闸配置
http://192.168.13.202/vb.htm?boa_eventjsonreq={"type":"get_addition_gpio"}&_=1646185193580 GET    
Response    
```
OK={"body":{"delay_stop_time":0,"enable":0,"frequency_time":1000,"input_gpio":0,"output_gpio":0},"err_msg":"All done","state":200,"type":"get_addition_gpio"}
```
##### 特殊车牌
http://192.168.13.202/vb.htm?getwebspesialplates={"type":"set_special_plates","body":{"plates":[{"index":0,"status":1},{"index":1,"status":0},{"index":2,"status":0},{"index":3,"status":0},{"index":4,"status":0},{"index":5,"status":0},{"index":6,"status":0},{"index":7,"status":0},{"index":8,"status":0},{"index":9,"status":0},{"index":10,"status":0},{"index":11,"status":0},{"index":12,"status":0},{"index":13,"status":0},{"index":14,"status":0},{"index":15,"status":0},{"index":16,"status":1},{"index":17,"status":0},{"index":18,"status":0},{"index":19,"status":0},{"index":21,"status":0},{"index":22,"status":0}]}}&_=1646185193591 GET    
Response    
```
```
##### 补光灯配置
http://192.168.13.202/avsjson.php POST    
Params    
```json  
{"type":"AVS_SET_LED_CTRL","body":{"time_ctrl":[{"time_begin":"00:00:00","time_end":"04:30","timectrl_enable":true,"led_level":2,"id":0},{"time_begin":"04:30","time_end":"09:00","timectrl_enable":false,"led_level":-1,"id":1},{"time_begin":"09:00","time_end":"24:00:00","timectrl_enable":true,"led_level":1,"id":2}],"led_mode":3}}
{
	"err_msg": "OK",
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_SET_LED_CTRL"
}
```
##### 外置补光灯
http://192.168.13.202/request.php POST    
Params    
```json  
{"type":"set_flashlamp_info","module":"EVS_BUS_REQUEST","body":{"output_gpio":0,"input_gpio":0,"light_mode":4,"flash_info":{"delay_time":50,"light_time":3000}}}
{
	"err_msg": "All done",
	"state": 200,
	"type": "set_flashlamp_info"
}
```
##### 获取外置补光灯
http://192.168.13.202/request.php POST    
Params    
```json  
{"type":"get_flashlamp_info","module":"EVS_BUS_REQUEST"}
{
	"body": {
		"flash_info": {
			"delay_time": 50,
			"light_time": 3000
		},
		"input_gpio": 0,
		"light_mode": 4,
		"output_gpio": 0,
		"time_ctrl": [{
			"id": 0,
			"time_begin": "00:00:00",
			"time_end": "09:00:00",
			"timectrl_enable": 0
		}, {
			"id": 0,
			"time_begin": "09:00:00",
			"time_end": "18:00:00",
			"timectrl_enable": 0
		}, {
			"id": 0,
			"time_begin": "18:00:00",
			"time_end": "24:00:00",
			"timectrl_enable": 0
		}]
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_flashlamp_info"
}
```

##### 外设检测 - 开关电平输入1
http://192.168.13.202/evtjson.php POST    
Params    
```json  
{"type":"evs_gpio_test_ctrl","body":{"io_number":0,"io_opera":2,"io_type":1}}
```   
Response   
```json    
{
	"body": {
		"io_status": 1
	},
	"err_msg": "All done",
	"state": 200,
	"type": "evs_gpio_test_ctrl"
}
```
##### 外设检测 - 开关电平输入2
http://192.168.13.202/evtjson.php POST    
Params    
```json  
{"type":"evs_gpio_test_ctrl","body":{"io_number":1,"io_opera":2,"io_type":1}}
```   
Response   
```json    
{
	"body": {
		"io_status": 1
	},
	"err_msg": "All done",
	"state": 200,
	"type": "evs_gpio_test_ctrl"
}
```
##### 外设检测 - 开关量输出1 - 0 -> 1 
http://192.168.13.202/evtjson.php POST    
Params    
```json  
{"type":"evs_gpio_test_ctrl","body":{"io_number":0,"io_opera":1,"io_type":2,"io_status":1}}
{
	"err_msg": "All done",
	"state": 200,
	"type": "evs_gpio_test_ctrl"
}
```
http://192.168.13.202/evtjson.php POST    
Params    
```json  
{"type":"evs_gpio_test_ctrl","body":{"io_number":0,"io_opera":2,"io_type":2}}
{
	"body": {
		"io_status": 1
	},
	"err_msg": "All done",
	"state": 200,
	"type": "evs_gpio_test_ctrl"
}
```
##### 外设检测 - 开关量输出1 - 1 -> 0 
http://192.168.13.202/evtjson.php POST    
Params    
```json  
{"type":"evs_gpio_test_ctrl","body":{"io_number":0,"io_opera":1,"io_type":2}}
{
	"err_msg": "All done",
	"state": 200,
	"type": "evs_gpio_test_ctrl"
}
```
http://192.168.13.202/evtjson.php POST    
Params    
```json  
{"type":"evs_gpio_test_ctrl","body":{"io_number":0,"io_opera":2,"io_type":2}}
{
	"body": {
		"io_status": 0
	},
	"err_msg": "All done",
	"state": 200,
	"type": "evs_gpio_test_ctrl"
}
```
##### 外设检测 - 开关量输出2 - 0 -> 1 
http://192.168.13.202/evtjson.php POST    
Params    
```json  
{"type":"evs_gpio_test_ctrl","body":{"io_number":1,"io_opera":1,"io_type":2,"io_status":1}}
{
	"err_msg": "All done",
	"state": 200,
	"type": "evs_gpio_test_ctrl"
}
```
http://192.168.13.202/evtjson.php POST    
Params    
```json  
{"type":"evs_gpio_test_ctrl","body":{"io_number":1,"io_opera":2,"io_type":2}}
{
	"body": {
		"io_status": 1
	},
	"err_msg": "All done",
	"state": 200,
	"type": "evs_gpio_test_ctrl"
}
```
##### 外设检测 - 开关量输出2 - 1 -> 0 
http://192.168.13.202/evtjson.php POST    
Params    
```json  
{"type":"evs_gpio_test_ctrl","body":{"io_number":1,"io_opera":1,"io_type":2}}
{
	"err_msg": "All done",
	"state": 200,
	"type": "evs_gpio_test_ctrl"
}
```
http://192.168.13.202/evtjson.php POST    
Params    
```json  
{"type":"evs_gpio_test_ctrl","body":{"io_number":1,"io_opera":2,"io_type":2}}
{
	"body": {
		"io_status": 0
	},
	"err_msg": "All done",
	"state": 200,
	"type": "evs_gpio_test_ctrl"
}
```
### 屏显语音
#### 请求
##### 获取语音配置？ 
http://192.168.13.202/avsjson.php POST    
Params    
```json  
{"type":"ps_get_voice_config"}    
```   
Response   
```json    
{
	"error_msg": "OK",
	"state": 200,
	"talk_io": 0,
	"type": "ps_get_voice_config",
	"voice_defalut_interval": 100,
	"voice_defalut_male": 1,
	"voice_defalut_volume": 100
}
```
##### 获取主辅相机配置
http://192.168.13.202/dgjson.php POST    
Params    
```json  
{"type":"get_group_cfg"}    
```   
Response   
```json    
{
	"group_cfg": {
		"group_vzids": []
	},
	"state": 200,
	"type": "get_group_cfg",
	"vzid": {
		"ast_type": 0,
		"enable_group": true,
		"ip_addr": "192.168.13.202",
		"name": "bHk=&MTkyLjE2OC43LjIy",
		"sn": "c806ca86-8de9c3f4",
		"type": "output"
	}
}
```
##### 获取A协议的485推送配置
http://192.168.13.202/bbjson.php POST    
Params    
```json  
{"type":"get_rs485_push"}    
```   
Response   
```json    
{
	"body": {
		"comm_push_cfg": [{
			"header": "BB88"
		}, {
			"enable": ""
		}, {
			"licensecolor": ""
		}, {
			"license": ""
		}, {
			"confidence": ""
		}, {
			"wlresult": ""
		}, {
			"direction": ""
		}, {
			"checkbegin": "2"
		}, {
			"checkend": "14"
		}, {
			"checksum": "xor"
		}, {
			"end": ""
		}]
	},
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "get_rs485_push"
}
```
##### 获取屏显协议
http://192.168.13.202/bbjson.php POST    
Params    
```json  
{"type":"get_led_ctrl_cfg"}    
```   
Response   
```json    
{
	"body": {
		"led_status": 0,
		"line_num": 4,
		"muticast_ip": "",
		"screen_ctrl_pro_type": 0,
		"screen_isopen": 0,
		"use_serial_port": 1,
		"voice_sync_screen": 0
	},
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "get_led_ctrl_cfg"
}
```
##### 获取停车数据？ 
http://192.168.13.202/dgjson.php POST    
Params    
```json  
{"type":"get_total_parking"}    
```   
Response   
```json    
{
	"current_parking": 0,
	"state": 200,
	"total_parking": 0,
	"type": "get_total_parking"
}
```
##### 获取语音播报配置
http://192.168.13.202/voicecfg.php POST    
Params    
```json  
{"type":"get_voice_cfg"}    
```   
Response   
```json    
{
	"body": {
		"greetings": "xPq6ww==",
		"start_mode": 1,
		"tag": "0rvCt8uzt+c=",
		"voice_interval": 100,
		"voice_male": 1,
		"voice_time_inv_level": [{
			"end_time": "07:00:00",
			"start_time": "00:00:00",
			"voice_volume": 0
		}, {
			"end_time": "20:00:00",
			"start_time": "07:00:00",
			"voice_volume": 0
		}, {
			"end_time": "24:00:00",
			"start_time": "24:00:00",
			"voice_volume": 0
		}],
		"voice_type": 0
	},
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "get_voice_cfg"
}
```
#### 操作
##### 设置屏显协议
http://192.168.13.202/bbjson.php POST    
Params    
```json  
{"type":"set_led_ctrl_cfg","body":{"screen_ctrl_pro_type":0}}    
```   
Response   
```json    
{
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "set_led_ctrl_cfg"
}
```
##### 设置屏显协议配置？ 
http://192.168.13.202/bbjson.php POST    
Params    
```json  
{"type":"set_rs485_push","body":{"comm_push_cfg":[{"header":"BB88"},{"enable":"0"},{"licensecolor":"0"},{"license":"0"},{"confidence":"0"},{"wlresult":"0"},{"direction":"0"},{"checkbegin":"2"},{"checkend":"14"},{"checksum":"xor"},{"end":""},{"encode":"1"},{"edian":"little"},{"ne_compatible":"0"}]}}    
```   
Response   
```json    
{
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "set_rs485_push"
}
```
##### 获取屏显协议
http://192.168.13.202/bbjson.php POST    
Params    
```json  
{"type":"get_led_ctrl_cfg"}    
```   
Response   
```json    
{
	"body": {
		"led_status": 0,
		"line_num": 4,
		"muticast_ip": "",
		"screen_ctrl_pro_type": 0,
		"screen_isopen": 0,
		"use_serial_port": 0,
		"voice_sync_screen": 0
	},
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "get_led_ctrl_cfg"
}
```
##### 设置语音播报数据
http://192.168.13.201/voicecfg.php POST    
Params    
```json  
{"type":"set_voice_cfg","body":{"voice_type":0,"greetings":"5oKo5aW9","tag":"5LiA6Lev6aG66aOO","voice_male":1,"voice_interval":900,"voice_time_inv_level":[{"start_time":"00:00:00","end_time":"07:00:00","voice_volume":60},{"start_time":"07:00:00","end_time":"20:00:00","voice_volume":100},{"start_time":"20:00:00","end_time":"24:00:00","voice_volume":60}],"start_mode":1}}
```   
Response   
```json    
{
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "set_voice_cfg"
}
```
### 出入口配置
#### 请求
##### 获取触发模式
http://192.168.13.202/dgjson.php POST    
Params    
```json  
{"type":"get_ast_mode"}    
```   
Response   
```json    
{
	"dealy_time": "faster",
	"state": 200,
	"type": "get_ast_mode"
}
```
##### 获取主辅相机延迟等待
http://192.168.13.202/dgjson.php POST    
Params    
```json  
{"type":"get_ast_dealy_time"}    
```   
Response   
```json    
{
	"dealy_time": 500,
	"state": 200,
	"type": "get_ast_dealy_time"
}
```
##### 获取主辅相机匹配规则
http://192.168.13.202/dgjson.php POST    
Params    
```json  
{"type":"get_device_match_mode"}    
```   
Response   
```json    
{
	"mode": "exact_mode",
	"state": 200,
	"type": "get_device_match_mode"
}
```
##### 获取辅助相机IO
http://192.168.13.202/dgjson.php POST    
Params    
```json  
{"type":"get_group_shared_io"}    
```   
Response   
```json    
{
	"state": 200,
	"type": "get_group_shared_io",
	"value": 0
}
```
##### 获取停车数据？ 
http://192.168.13.202/dgjson.php POST    
Params    
```json  
{"type":"get_total_parking"}    
```   
Response   
```json    
{
	"current_parking": 0,
	"state": 200,
	"total_parking": 0,
	"type": "get_total_parking"
}
```
##### 获取主辅相机模式
http://192.168.13.202/dgjson.php POST    
Params    
```json  
{"type":"get_group_model"}    
```   
Response   
```json    
{
	"enable": 0,
	"state": 200,
	"type": "get_group_model"
}
```
##### 主辅相机开关
http://192.168.13.202/dgjson.php POST    
Params    
```json  
{"type":"get_group_switch"}    
```   
Response   
```json    
{
	"enable": 0,
	"state": 200,
	"type": "get_group_switch"
}
```
##### 获取主辅相机配置
http://192.168.13.202/dgjson.php POST    
Params    
```json  
{"type":"get_group_cfg"}    
```   
Response   
```json    
{
	"group_cfg": {
		"group_vzids": []
	},
	"state": 200,
	"type": "get_group_cfg",
	"vzid": {
		"ast_type": 0,
		"enable_group": true,
		"ip_addr": "192.168.13.202",
		"name": "bHk=&MTkyLjE2OC43LjIy",
		"sn": "c806ca86-8de9c3f4",
		"type": "output"
	}
}
```
#### 操作
##### 开启主辅相机模式（设备重启）
http://192.168.13.202/dgjson.php POST    
Params    
```json  
关闭 - {"type":"set_group_model","enable":0}	
开启 - {"type":"set_group_model","enable":1}    
```   
Response   
```json    
{
	"state": 200,
	"type": "set_group_model"
}
```
##### 获取开启主辅相机模式
http://192.168.13.202/dgjson.php POST    
Params    
```json  
{"type":"get_group_model"}    
```   
Response   
```json    
{
	"enable": 1,
	"state": 200,
	"type": "get_group_model"
}
```
##### 设置主辅相机配置
http://192.168.13.202/dgjson.php POST    
Params    
```json  
{"group_cfg":{"group_vzids":[]},"state":200,"type":"set_group_cfg","vzid":{"ast_type":0,"enable_group":true,"ip_addr":"192.168.13.202","name":"","sn":"c806ca86-8de9c3f4","type":"output"}}    
```   
Response   
```json    
{
	"state": 200,
	"type": "set_group_cfg"
}
```
##### 触发模式
http://192.168.13.202/dgjson.php POST    
Params    
```json  
延迟等待模式 - {"type":"set_ast_mode","mode":"aggregated"}
多结果模式 - {"type":"set_ast_mode","mode":"direct"}    
```   
Response   
```json    
{
	"state": 200,
	"type": "set_ast_mode"
}
```
##### 获取触发模式
http://192.168.13.202/dgjson.php POST    
Params    
```json  
{"type":"get_ast_mode"}    
```   
Response   
```json    
{
	"mode": "direct",
	"state": 200,
	"type": "get_ast_mode"
}
```
##### 延迟等待
http://192.168.13.202/dgjson.php POST    
Params    
```json  
{"type":"set_ast_dealy_time","dealy_time":550}    
```   
Response   
```json    
{
	"state": 200,
	"type": "set_ast_dealy_time"
}
```
##### 获取延迟等待配置
http://192.168.13.202/dgjson.php POST    
Params    
```json  
{"type":"get_ast_dealy_time"}    
```   
Response   
```json    
{
	"dealy_time": 550,
	"state": 200,
	"type": "get_ast_dealy_time"
}
```
##### 匹配规则
http://192.168.13.202/dgjson.php POST    
Params    
```json  
精准匹配 - {"type":"set_device_match_mode","mode":"exact_mode"}	
相似字符 - {"type":"set_device_match_mode","mode":"fuzzy_mode"}
```   
Response   
```json    
{
	"state": 200,
	"type": "set_device_match_mode"
}
```
##### 获取匹配规则
http://192.168.13.202/dgjson.php POST    
Params    
```json  
{"type":"get_device_match_mode"}
```   
Response   
```json    
{
	"mode": "fuzzy_mode",
	"state": 200,
	"type": "get_device_match_mode"
}
```
##### 相辅相机IO 
http://192.168.13.202/dgjson.php POST    
Params    
```json  
开关量1 - {"type":"set_group_shared_io","value":65536}	
开关量2 - {"type":"set_group_shared_io","value":131073}
开关量输出1 - {"type":"set_group_shared_io","value":1}
开关量输出2 - {"type":"set_group_shared_io","value":2}
```   
Response   
```json    
{
	"state": 200,
	"type": "set_group_shared_io"
}
```

##### 获取相辅相机开关量
http://192.168.13.202/dgjson.php POST    
Params    
```json  
{"type":"get_group_shared_io"}    
```   
Response   
```json    
{
	"state": 200,
	"type": "get_group_shared_io",
	"value": 131073
}
```
##### 停车场配置 - 开启停车场组网（重启）
http://192.168.13.202/dgjson.php POST    
Params    
```json  
开启 - {"type":"set_group_switch","enable":1}	
关闭 - {"type":"set_group_switch","enable":0}    
```   
Response   
```json    
{
	"state": 200,
	"type": "set_group_switch"
}
```
##### 停车场配置 - 修改出入口
http://192.168.13.202/dgjson.php POST    
Params    
```json  
{"type":"set_group_cfg","state":200,"group_cfg":{"group_vzids":[]},"vzid":{"enable_group":true,"ip_addr":"192.168.13.202","name":"","sn":"c806ca86-8de9c3f4","type":"input","ast_type":0}}	
{"type":"set_group_cfg","state":200,"group_cfg":{"group_vzids":[]},"vzid":{"enable_group":true,"ip_addr":"192.168.13.202","name":"6L2m5bqTNzE=&MTkyLjE2OC4xMy4yMDI=#","sn":"c806ca86-8de9c3f4","type":"input"}}
```   
Response   
```json    
{
	"state": 200,
	"type": "set_group_cfg"
}
```
### 联动管理
#### 请求
##### 获取联动管理数据
http://192.168.13.202/request.php POST    
Params    
```json  
{"type":"get_all_mate","module":"PM_WEB_REQUEST"}
```
Response   
```json
{
	"body": "",
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": ""
}
```
#### 操作
##### 联动管理 - 查找设备
http://192.168.13.202/request.php POST    
Params    
```json  
{"type":"search_all_mate","module":"PM_WEB_REQUEST"}    
```   
Response   
```json    
{
	"state": 400,
	"state_code": 400,
	"type": ""
}
```
## 设备维护页
### 设备信息
#### 请求
##### 获取设备类型
http://192.168.13.202/request.php POST    
Params    
```json  
{"type":"get_web_saved_value","module":"WEB_SELF_REQUEST"}    
```   
Response   
```json    
{
	"body": "",
	"module": "WEB_SELF_REQUEST",
	"state": 200,
	"type": "get_web_saved_value"
}
```
##### 获取设备信息
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"get_device_info"}    
```   
Response   
```json    
{
	"body": {
		"alg_ver": "3.1.2021120815",
		"batch_number": "504949505056494948",
		"board_version": 12378,
		"dev_type": 13,
		"drv_ver": "C3R3_3.0.111301722",
		"exdataSize": 2852128853,
		"exdata_checker": 46,
		"ext_info": {
			"monitor_numbers": 0,
			"product_code": "VTC820A",
			"product_name": "5pm66IO96L2m54mM6K+G5Yir55u45py6",
			"product_type": "R3-V1.0"
		},
		"hw_flag": 13,
		"hw_version": "09.00.00.0d",
		"isp_ver": "ISP_3510.0.20211105",
		"mac_addr": "48:a2:b8:10:71:b2",
		"oem_info": "00.00.03.78.78.78.78",
		"oem_serial_num": "1234-5689",
		"profocus_flag": 2,
		"serial_num": "c806ca86-8de9c3f4",
		"soft_ver": "12.1.1.202112230",
		"system_ver": "x029.u029.k015.r083",
		"title": "SVZT",
		"write_status": 654647313
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_device_info"
}
```
##### 获取设备名称
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"ss_get_devname"}    
```   
Response   
```json    
{
	"body": {
		"title": "SVZT"
	},
	"err_msg": "All done",
	"state": 200,
	"type": "ss_get_devname"
}
```
#### 操作
##### 设置设备名称
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"ss_set_devname","body":{"title":"SVZTMQ=="}}
{
	"err_msg": "All done",
	"state": 200,
	"type": "ss_set_devname"
}
```
##### 获取设备名称
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"ss_get_devname"}    
```   
Response   
```json    
{
	"body": {
		"title": "SVZTMQ=="
	},
	"err_msg": "All done",
	"state": 200,
	"type": "ss_get_devname"
}
```
##### 设置设备类型
http://192.168.13.202/request.php POST    
Params    
```json  
{"type":"set_web_saved_value","module":"WEB_SELF_REQUEST","body":{"device_type":"300万高清车牌识别一体机1"}}
{
	"module": "WEB_SELF_REQUEST",
	"state": 200,
	"type": "set_web_saved_value"
}
```
##### 获取设备类型
http://192.168.13.202/request.php POST    
Params    
```json  
{"type":"get_web_saved_value","module":"WEB_SELF_REQUEST"}
{
	"body": {
		"device_type": "300万高清车牌识别一体机1"
	},
	"module": "WEB_SELF_REQUEST",
	"state": 200,
	"type": "get_web_saved_value"
}
```
### 用户管理
#### 请求
##### 获取用户信息
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"ss_get_accounts","body":{"remote_id":""}}    
```   
Response   
```json    
{
	"body": [{
		"auth": "HWIAAAAAHWIyAWjDiYjRsVbxlw==",
		"authority": 0,
		"encrypt_level": 1,
		"heartbeat_timeout": 20,
		"sign_in_timeout": 15
	}],
	"err_msg": "All done",
	"state": 200,
	"type": "ss_get_accounts"
}
```

#### 操作
##### 用户管理 - 添加
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"ss_set_account","body":{"remote_id":"","auth":"yMgdYh8fHx/VU2eJ4cEp","authority":0,"control":"add"}}    
```   
Response   
```json    
{
	"err_msg": "All done",
	"state": 200,
	"type": "ss_set_account"
}
```
##### 用户管理 - 编辑
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"ss_set_account","body":{"remote_id":"","auth":"QMkdYpGRkZGRmEY/Zk09","authority":1,"control":"add"}}    
```   
Response   
```json    
{
	"err_msg": "All done",
	"state": 200,
	"type": "ss_set_account"
}
```
##### 用户管理 - 删除
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"ss_set_account","body":{"remote_id":"","auth":"k8kdYoqKioqt6LPVCw==","authority":"","control":"del"}}
{
	"err_msg": "All done",
	"state": 200,
	"type": "ss_set_account"
}
```
##### 设置登陆超时
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"ss_set_account","body":{"sign_in_timeout":15,"control":"add"}}	
15分钟
{
	"err_msg": "All done",
	"state": 200,
	"type": "ss_set_account"
}
```
### 时间设置
#### 请求
##### 获取ntp配置
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"ss_get_ntp_cfg"}    
```   
Response   
```json    
{
	"body": {
		"cycle": 600,
		"enable": 1,
		"server": "ntp.ntsc.ac.cn"
	},
	"err_msg": "All done",
	"state": 200,
	"type": "ss_get_ntp_cfg"
}
```
##### 获取当前时间日期
http://192.168.13.202/vb.htm?getdate=&gettime=&_=1646113962033
```
OK getdate=2022-03-01 Tue
OK gettime=14:28:20
```

##### 获取时区
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"get_timezone"}    
```   
Response   
```json    
{
	"body": {
		"timezone": 480
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_timezone"
}
```
##### 获取夏令时
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"get_DST"}    
```   
Response   
```json    
{
	"body": {
		"CurrentZONE": 480,
		"DST_enable": 0,
		"DST_offset": 30,
		"EndTime": {
			"dday": 1,
			"dhour": 0,
			"dmon": 1,
			"dweek": 1
		},
		"StartTime": {
			"dday": 1,
			"dhour": 0,
			"dmon": 1,
			"dweek": 1
		}
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_DST"
}
```
#### 操作
时区设置
##### 设置时区
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"set_timezone","body":{"timezone":540}}    
```   
Response   
```json    
{
	"err_msg": "All done",
	"state": 200,
	"type": "set_timezone"
}
```
##### 设置时区伴随的请求与算法相关
http://192.168.13.202/avsjson.php POST    
Params    
```json  
{"type":"AVS_SET_ALG_RESULT_PARAM","body":{"time_zone":540}}    
```   
Response   
```json    
{
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_SET_ALG_RESULT_PARAM"
}
```
##### 获取时区
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"get_timezone"}    
```   
Response   
```json    
{
	"body": {
		"timezone": 540
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_timezone"
}
```
##### 设置夏令时
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"set_DST","body":{"CurrentZONE":540,"DST_enable":1,"DST_offset":30,"StartTime":{"dmon":1,"dweek":1,"dday":1,"dhour":0},"EndTime":{"dmon":2,"dweek":1,"dday":1,"dhour":0}}}    
```   
Response   
```json    
{
	"err_msg": "All done",
	"state": 200,
	"type": "set_DST"
}
```
##### 获取夏令时
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"get_DST"}    
```   
Response   
```json    
{
	"body": {
		"CurrentZONE": 540,
		"DST_enable": 1,
		"DST_offset": 30,
		"EndTime": {
			"dday": 1,
			"dhour": 0,
			"dmon": 2,
			"dweek": 1
		},
		"StartTime": {
			"dday": 1,
			"dhour": 0,
			"dmon": 1,
			"dweek": 1
		}
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_DST"
}
```
##### 手动设置时间
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"ss_set_timing","body":{"datetime":"2022-03-02 00:00:00"}}    
```   
Response   
```json    
{
	"err_msg": "All done",
	"state": 200,
	"type": "ss_set_timing"
}
```
##### 同步本地时间
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"ss_set_timing","body":{"datetime":"2022-03-01 15:15:56"}}    
```   
Response   
```json    
{
	"err_msg": "All done",
	"state": 200,
	"type": "ss_set_timing"
}
```
##### NTP校时
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"ss_set_ntp_cfg","body":{"enable":1,"server":"ntp.ntsc.ac.cn","cycle":600}}    
```   
Response   
```json    
{
	"err_msg": "All done",
	"state": 200,
	"type": "ss_set_ntp_cfg"
}
```
### 存储管理
#### 请求
##### 获取存储状态
http://192.168.13.202/request.php POST    
Params    
```json  
{"type":"STORE_STAT_REQUEST","module":"STORE_BUSINESS_REQUEST"}    
```   
Response   
```json    
{
	"body": {
		"vzfs": [{
			"dev_infos": [{
				"path": "/dev/mtdblock17",
				"size": 16777216
			}, {
				"path": "/dev/mtdblock18",
				"size": 16777216
			}],
			"fmt_seconds": 0,
			"pic_size": 18874368,
			"pic_used": 6291456,
			"rec_size": 0,
			"rec_used": 0,
			"size": 18874368,
			"state": 0,
			"type": "flash",
			"used": 6291456
		}]
	},
	"err_msg": "All Done",
	"state": 200,
	"type": "STORE_STAT_REQUEST"
}
```
##### 获取录像？ 的什么东西
http://192.168.13.202/request.php POST    
Params    
```json  
{"type":"STORE_GET_RECORD_PARA_REQUEST","module":"STORE_BUSINESS_REQUEST"}    
```   
Response   
```json    
{
	"body": {
		"channel": [{
			"chan_id": 0,
			"event_param": {
				"event_mode": 1,
				"period": 180
			},
			"mode": 0,
			"rec_type": 1,
			"record_param": {
				"time": [{
					"id": 0,
					"period": [{
						"end_hour": 23,
						"end_minute": 59,
						"id": 0,
						"start_hour": 0,
						"start_minute": 0
					}]
				}, {
					"id": 1,
					"period": [{
						"end_hour": 23,
						"end_minute": 59,
						"id": 0,
						"start_hour": 0,
						"start_minute": 0
					}]
				}, {
					"id": 2,
					"period": [{
						"end_hour": 23,
						"end_minute": 59,
						"id": 0,
						"start_hour": 0,
						"start_minute": 0
					}]
				}, {
					"id": 3,
					"period": [{
						"end_hour": 23,
						"end_minute": 59,
						"id": 0,
						"start_hour": 0,
						"start_minute": 0
					}]
				}, {
					"id": 4,
					"period": [{
						"end_hour": 23,
						"end_minute": 59,
						"id": 0,
						"start_hour": 0,
						"start_minute": 0
					}]
				}, {
					"id": 5,
					"period": [{
						"end_hour": 23,
						"end_minute": 59,
						"id": 0,
						"start_hour": 0,
						"start_minute": 0
					}]
				}, {
					"id": 6,
					"period": [{
						"end_hour": 23,
						"end_minute": 59,
						"id": 0,
						"start_hour": 0,
						"start_minute": 0
					}]
				}]
			}
		}]
	},
	"err_msg": "All Done",
	"state": 200,
	"type": "STORE_GET_RECORD_PARA_REQUEST"
}
```
#### 操作
存储管理 - 格式化

录像计划

### 日志检测
#### 请求

#### 操作
##### 日志查询
http://192.168.13.202/logsearch.php POST    
Params    
```json  
{"type":"log_search","module":"BUS_WEB_REQUEST","body":{"type_mask":30,"start_time":{"sec":1646064000,"usec":0},"end_time":{"sec":1646150399,"usec":0},"limit":100,"qnode":{"qtype":1,"is_first":1,"max_id":0,"min_id":0,"start_id":0}}}
{"type":"log_search","module":"BUS_WEB_REQUEST","body":{"type_mask":30,"start_time":{"sec":1646064000,"usec":0},"end_time":{"sec":1646150399,"usec":0},"limit":100,"qnode":{"qtype":1,"is_first":0,"max_id":17284,"min_id":17081,"start_id":17184}}}	
{"type":"log_search","module":"BUS_WEB_REQUEST","body":{"type_mask":30,"start_time":{"sec":1646064000,"usec":0},"end_time":{"sec":1646150399,"usec":0},"limit":100,"qnode":{"qtype":1,"is_first":0,"max_id":17284,"min_id":17081,"start_id":17084}}}	
{"type":"log_search","module":"BUS_WEB_REQUEST","body":{"type_mask":30,"start_time":{"sec":1646064000,"usec":0},"end_time":{"sec":1646150399,"usec":0},"limit":100,"qnode":{"qtype":1,"is_first":0,"max_id":17284,"min_id":17081,"start_id":17081}}}    
```   
Response   
```json    
{
	"body": {
		"logs": [{
			"data": "163,24,Etern device write GPIO OUT, source[1], value 0, clock time:15844 ms",
			"level": 5,
			"time": "2022-03-01 15:00:50",
			"type": 2
		}, {
			"data": "163,24,Etern device write GPIO OUT, source[0], value 0, clock time:15844 ms",
			"level": 5,
			"time": "2022-03-01 15:00:50",
			"type": 2
		}, {
			"data": "1220 system start. (12.1.1.202112230)app compile Dec 23 2021 17:56:09",
			"level": 5,
			"time": "2022-03-01 15:00:49",
			"type": 4
		}, {
			"data": "2420 Web Server Start Reboot Dev.",
			"level": 5,
			"time": "2022-03-01 15:00:26",
			"type": 4
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 14:59:55",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 14:54:55",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 14:49:54",
			"type": 2
		}, {
			"data": "1206 user config reboot time {\"enable\":0,\"minute\":0,\"wday\":\"1,3\"}\n.",
			"level": 5,
			"time": "2022-03-01 14:47:35",
			"type": 16
		}, {
			"data": "1206 config reboot param.",
			"level": 5,
			"time": "2022-03-01 14:47:35",
			"type": 16
		}, {
			"data": "1206 user config reboot time {\"enable\":1,\"minute\":0,\"wday\":\"1,3\"}\n.",
			"level": 5,
			"time": "2022-03-01 14:47:13",
			"type": 16
		}, {
			"data": "1206 config reboot param.",
			"level": 5,
			"time": "2022-03-01 14:47:13",
			"type": 16
		}, {
			"data": "1206 user config reboot time {\"enable\":1,\"minute\":0,\"wday\":\"1\"}\n.",
			"level": 5,
			"time": "2022-03-01 14:47:00",
			"type": 16
		}, {
			"data": "1206 config reboot param.",
			"level": 5,
			"time": "2022-03-01 14:47:00",
			"type": 16
		}, {
			"data": "1206 user config reboot time {\"enable\":1,\"minute\":0,\"wday\":\"\"}\n.",
			"level": 5,
			"time": "2022-03-01 14:46:09",
			"type": 16
		}, {
			"data": "1206 config reboot param.",
			"level": 5,
			"time": "2022-03-01 14:46:09",
			"type": 16
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 14:44:54",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 14:39:54",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 14:34:54",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 14:29:54",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 14:24:54",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 14:19:54",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 14:14:53",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 14:09:53",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 14:04:53",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 13:59:53",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 13:54:53",
			"type": 2
		}, {
			"data": "1213 user manual timing {\"datetime\":\"2022-03-01 13:52:41\",\"type\":\"login\"}.",
			"level": 5,
			"time": "2022-03-01 13:52:42",
			"type": 16
		}, {
			"data": "1213 usr set time.",
			"level": 5,
			"time": "2022-03-01 13:52:42",
			"type": 16
		}, {
			"data": "1228 login set time.",
			"level": 5,
			"time": "2022-03-01 13:52:42",
			"type": 16
		}, {
			"data": "1218 link is up.",
			"level": 5,
			"time": "2022-03-01 13:50:58",
			"type": 4
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 13:49:53",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 13:44:53",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 13:39:53",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 13:34:53",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 13:29:53",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 13:24:52",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 13:19:52",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 13:14:52",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 13:09:52",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 13:04:52",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 12:59:52",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 12:54:51",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 12:49:51",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 12:44:51",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 12:39:51",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 12:34:51",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 12:29:51",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 12:24:50",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 12:19:50",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 12:14:51",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 12:09:50",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 12:04:50",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 11:59:50",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 11:54:49",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 11:49:49",
			"type": 2
		}, {
			"data": "1217 link is down.",
			"level": 5,
			"time": "2022-03-01 11:45:41",
			"type": 8
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 11:44:50",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 11:39:50",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 11:34:49",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 11:29:49",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 11:24:49",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 11:19:48",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 11:14:49",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 11:09:49",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 11:04:49",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 10:59:49",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 10:54:48",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 10:49:48",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 10:44:48",
			"type": 2
		}, {
			"data": "1213 user manual timing {\"datetime\":\"2022-03-01 10:41:33\",\"type\":\"login\"}.",
			"level": 5,
			"time": "2022-03-01 10:41:33",
			"type": 16
		}, {
			"data": "165,62,the time is changed: 2022-3-1 10:41:33.\n",
			"level": 5,
			"time": "2022-03-01 10:43:07",
			"type": 2
		}, {
			"data": "1213 usr set time.",
			"level": 5,
			"time": "2022-03-01 10:43:07",
			"type": 16
		}, {
			"data": "1228 login set time.",
			"level": 5,
			"time": "2022-03-01 10:43:07",
			"type": 16
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 10:41:22",
			"type": 2
		}, {
			"data": "1218 link is up.",
			"level": 5,
			"time": "2022-03-01 10:40:17",
			"type": 4
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 10:36:22",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 10:31:22",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 10:26:22",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 10:21:21",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 10:16:21",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 10:11:21",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 10:06:21",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 10:01:21",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 09:56:21",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 09:51:21",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 09:46:20",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 09:41:20",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 09:36:20",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 09:31:19",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 09:26:20",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 09:21:20",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 09:16:19",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 09:11:19",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 09:06:19",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 09:01:19",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 08:56:19",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 08:51:18",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 08:46:19",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 08:41:19",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 08:36:19",
			"type": 2
		}],
		"qnode": {
			"is_first": true,
			"last_id": 17184,
			"max_id": 17284,
			"min_id": 17081,
			"qtype": 1,
			"start_id": 4294967295
		},
		"rec_size": 100
	},
	"err_msg": "ok",
	"module": "BUS_WEB_REQUEST",
	"state": 200,
	"type": "log_search"
}
```
##### 日志导出
提示需要使用IE浏览器

### 配置管理
#### 请求
##### 获取模块管理参数
http://192.168.13.202/request.php POST    
Params    
```json  
{"type":"get_module_app_cfg","module":"MODULE_CONFIG_INFO"}    
```   
Response   
```json    
{
	"body": {
		"app": [{
			"alias": "5YWs5YWx5o6o6YCB5qih5Z2X",
			"enable": 1,
			"name": "xtp_push_app",
			"rss": 5
		}, {
			"alias": "b252aWbmqKHlnZc=",
			"enable": 1,
			"name": "onvif_server_app",
			"rss": 5
		}, {
			"alias": "6Ie75LqR5qih5Z2X",
			"enable": 1,
			"name": "stp_server_app",
			"rss": 5
		}, {
			"alias": "bGluayB2aXN1YWzmqKHlnZc=",
			"enable": 1,
			"name": "link_visual_app",
			"rss": 6
		}, {
			"alias": "b25lbmV0eOWNj+iuruaooeWdlw==",
			"enable": 1,
			"name": "onenet_server_app",
			"rss": 4
		}, {
			"alias": "T0VN5a6a5Yi25Y2P6K6u5qih5Z2X",
			"enable": 1,
			"name": "oem_multicast_app",
			"rss": 0
		}, {
			"alias": "6IGU5Yqo566h55CG5qih5Z2X",
			"enable": 1,
			"name": "interact_device_app",
			"rss": 4
		}]
	},
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "get_module_app_cfg"
}
```
#### 操作
##### 参数导出
http://192.168.13.202/configbackup.php POST    
Params    
```json  
{"type":"config_backup","body":{"general":1,"system":1,"security":1}}	
general 通用 1, 0 system 系统 1, 0 security 安全 1, 0
```   
Response   
```json    
{
	"body": {
		"data": "ZG93bmxvYWQucGhwL1Z6Q29uZmlnL2NvbmZpZ2JhY2t1cDAwLmNmZw=="
	},
	"err_msg": "All done",
	"state": 200,
	"type": "config_backup"
}
```
##### 参数导出文件下载地址
http://192.168.13.202/download.php/VzConfig/configbackup00.cfg GET    

##### 参数导入（会导致重启）
http://192.168.13.202/configrestore.cgi POST    

##### 模块管理 - 设置模块状态
http://192.168.13.202/request.php POST    
Params    
```json  
{"type":"set_module_app_cfg","module":"MODULE_CONFIG_INFO","body":{"app":[{"name":"xtp_push_app","enable":1},{"name":"onvif_server_app","enable":1},{"name":"stp_server_app","enable":1},{"name":"link_visual_app","enable":1},{"name":"onenet_server_app","enable":1},{"name":"oem_multicast_app","enable":1},{"name":"interact_device_app","enable":0}]}}    
```   
Response   
```json    
{
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "set_module_app_cfg"
}
```
##### 模块管理 - 恢复默认
http://192.168.13.202/request.php POST    
Params    
```json  
{"type":"reset_module_app_cfg","module":"MODULE_CONFIG_INFO"}    
```   
Response   
```json    
{
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "reset_module_app_cfg"
}
```
### LOGO
#### 请求

#### 操作
##### 删除logo
http://192.168.13.202/vb.htm?paratest=removelogofile&_=1646113962236 GET    

Response   
```json    
OK removelogofile=0
```
##### 上传Logo
http://192.168.13.202/cgi-bin/upload.cgi


### 系统维护
#### 请求
##### 获取设备信息
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"get_device_info"}    
```   
Response   
```json    
{
	"body": {
		"alg_ver": "3.1.2021120815",
		"batch_number": "504949505056494948",
		"board_version": 12378,
		"dev_type": 13,
		"drv_ver": "C3R3_3.0.111301722",
		"exdataSize": 2852128853,
		"exdata_checker": 46,
		"ext_info": {
			"monitor_numbers": 0,
			"product_code": "VTC820A",
			"product_name": "5pm66IO96L2m54mM6K+G5Yir55u45py6",
			"product_type": "R3-V1.0"
		},
		"hw_flag": 13,
		"hw_version": "09.00.00.0d",
		"isp_ver": "ISP_3510.0.20211105",
		"mac_addr": "48:a2:b8:10:71:b2",
		"oem_info": "00.00.03.78.78.78.78",
		"oem_serial_num": "1234-5689",
		"profocus_flag": 2,
		"serial_num": "c806ca86-8de9c3f4",
		"soft_ver": "12.1.1.202112230",
		"system_ver": "x029.u029.k015.r083",
		"title": "SVZT",
		"write_status": 654647313
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_device_info"
}
```
##### 获取日期时间
http://192.168.13.202/vb.htm?getdate=&gettime=&_=1646113962069
Response    
```
OK getdate=2022-03-01 Tue
OK gettime=14:36:06
```

##### 获取重启设备配置
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"get_reboot_timing"}    
```   
Response   
```json    
{
	"body": {
		"enable": 0,
		"minute": 0,
		"wday": ""
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_reboot_timing"
}
```
#### 操作
##### 重启设备 - 立即重启
http://192.168.13.201/vb.htm?ipcamrestartcmd=&_=1646273279427 GET
OK ipcamrestartcmd


##### 重启设备 - 自动重启
http://192.168.13.202/systemjson.php POST    
Params    
```json  
{"type":"set_reboot_timing","body":{"enable":1,"wday":"1,3","minute":0}}    
```   
Response   
```json    
{
	"err_msg": "All done",
	"state": 200,
	"type": "set_reboot_timing"
}
```
##### 恢复出厂 - 完全恢复
http://192.168.13.201/vb.htm?democfg=0&_=1646273380300
Response   
```
OK democfg
```
##### 恢复出厂 - 部分恢复
http://192.168.13.201/vb.htm?democfg=1&_=1646273380300
Response   
```
OK democfg
```
##### 升级设备
http://192.168.13.202/upload.cgi


