## 登录页
### 请求
请求系统参数 Post
URL 
http://192.168.13.202/avsjson.php
Params
{"type":"AVS_GET_SYS_PRM"}	
Response
{
	"body": {
		"alg_block": false,
		"language": "zh-cn"
	},
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_GET_SYS_PRM"
}

### 操作
登录：Post
URL
http://192.168.13.202/login.php
Params
加密username和password参数，rJIMYtjY2NgYtbky3tuwOy27rg: =加密规则见下
Response
OK
Set-Cookie: sessionID=209192407

## 实时视频页
### 请求
Post
http://192.168.13.202/getauth.php

{"type":"get_user_auth"}

{
	"body": {
		"authority": 0
	},
	"state": 200,
	"type": "get_user_auth"
}

Post
http://192.168.13.202/genvictetc.php

{"type":"etc_get_enable"}

{
	"state": 401
}

Post
http://192.168.13.202/request.php

{"type":"get_web_saved_value","module":"WEB_SELF_REQUEST"}	

{
	"body": "",
	"module": "WEB_SELF_REQUEST",
	"state": 200,
	"type": "get_web_saved_value"
}

Post
http://192.168.13.202/request.php

{"type":"get_device_capacity","module":"SS_BUS_REQUEST"}	

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

Post
http://192.168.13.202/getivsctrl.php

8:1:MA	=

OK ivsctrl=8:1:MA==

Post
http://192.168.13.202/avsjson.php

{"type":"AVS_GET_ALG_RESULT_PROP"}	

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

Post
http://192.168.13.202/request.php

{"type":"get_live_stream_type","module":"BUS_WEB_REQUEST"}	

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

Get
http://192.168.13.202/ivs_result.php?_=1646033471027

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

Post
http://192.168.13.202/systemjson.php

{"type":"get_net_and_port"}	

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

Post
http://192.168.13.202/dgjson.php

{"type":"get_group_cfg"}	

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

Post
http://192.168.13.202/avsjson.php

{"type":"AVS_GET_LED_PROP"}	

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

Post
http://192.168.13.202/geteventruleexhtm.php

0

OK geteventruleex=0:0:45:400:10:0


Post
http://192.168.13.202/systemjson.php

{"type":"ss_get_devname"}	

{
	"body": {
		"title": "SVZT"
	},
	"err_msg": "All done",
	"state": 200,
	"type": "ss_get_devname"
}

Post
http://192.168.13.202/systemjson.php

{"type":"get_device_info"}	

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

Post
http://192.168.13.202/dboprnew.php

{"type":"get_wl_check_status"}	

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

Post
http://192.168.13.202/systemjson.php

{"type":"ss_get_ntp_cfg"}	

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

Post
http://192.168.13.202/avsjson.php

{"type":"AVS_GET_ENCODE_PROP"}	

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

Post
http://192.168.13.202/avsjson.php

{"type":"AVS_GET_ALG_RESULT_PROP"}	

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

Post
http://192.168.13.202/request.php

{"type":"get_avs_focus_prm","module":"AVS_REQUEST_MESSAGE"}	

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

Post
http://192.168.13.202/avsjson.php

{"type":"AVS_GET_ALG_RESULT_PARAM"}	

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

http://192.168.13.202/avsjson.php

{"type":"AVS_GET_LED_CTRL"}	

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


http://192.168.13.202/avsjson.php

{"type":"AVS_GET_ENCODE_PARAM"}	

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


http://192.168.13.202/avsjson.php

{"type":"AVS_GET_ALG_RESULT_PARAM"}	

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


http://192.168.13.202/avsjson.php

{"type":"AVS_GET_VIRLOOP_PRM"}	

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


http://192.168.13.202/avsjson.php

{"type":"AVS_GET_RECO_PRM"}	

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

Get
ws://192.168.13.202:9080/ws.flv?token=17abed60-9180-2eb7-e72b-609f6d96c0da

Post
http://192.168.13.202/webpage_relogin.php

{
	"state": 401
}

http://192.168.13.202/getauth.php
{"type":"get_user_auth"}	
{
	"body": {
		"authority": 0
	},
	"state": 200,
	"type": "get_user_auth"
}

### 操作
创建虚拟线圈 Post
http://192.168.13.202/avsjson.php

{"type":"AVS_SET_VIRLOOP_PRM","body":{"virtualloop":{"max_plate_width":400,"min_plate_width":45,"dir":0,"trigger_gap":10,"loop":[{"enable":true,"point_num":4,"point":[{"x":2395,"y":11987},{"x":13988,"y":11987},{"x":15981,"y":14013},{"x":402,"y":14013}]}],"virtualloop_num":1}}}

{
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_SET_VIRLOOP_PRM"
}

创建识别区域 Post
http://192.168.13.202/avsjson.php

{"type":"AVS_SET_RECO_PRM","body":{"recognition_area":{"polygon":[{"enable":true,"point_num":4,"point":[{"x":1276,"y":2404},{"x":15055,"y":2404},{"x":16139,"y":15937},{"x":209,"y":15937}]}],"polygon_num":1}}}

{
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_SET_RECO_PRM"
}

手动触发 Get
http://192.168.13.202/avstrigger.php?_=1646033475057

手动触发截图 Get
http://192.168.13.202/snapshot/last_ivs_result.jpg?1646035490999

出入口 Post
http://192.168.13.202/dgjson.php

{"group_cfg":{"group_vzids":[]},"state":200,"type":"set_group_cfg","vzid":{"ast_type":0,"enable_group":true,"ip_addr":"192.168.13.202","name":"bHk=&MTkyLjE2OC43LjIy","sn":"c806ca86-8de9c3f4","type":"output"}}

{
	"state": 200,
	"type": "set_group_cfg"
}

运动方向 Post
http://192.168.13.202/geteventruleexhtm.php

0

OK geteventruleex=1:1:45:400:10:1

http://192.168.13.202/seteventruleexhtm.php

1:1:45:400:10:2

OK seteventrule1

补光模式 Post
http://192.168.13.202/avsjson.php

{"type":"AVS_SET_LED_CTRL","body":{"led_mode":0}}
{"type":"AVS_SET_LED_CTRL","body":{"time_ctrl":[{"time_begin":"00:00:00","time_end":"02:00:00","timectrl_enable":true,"led_level":2,"id":0},{"time_begin":"02:00:00","time_end":"09:00:00","timectrl_enable":false,"led_level":-1,"id":1},{"time_begin":"09:00:00","time_end":"24:00:00","timectrl_enable":true,"led_level":1,"id":2}],"led_mode":3}}

{
	"err_msg": "OK",
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_SET_LED_CTRL"
}

预设省份 Post
http://192.168.13.202/avsjson.php

{"type":"AVS_SET_ALG_RESULT_PARAM","body":{"province":22}}

{
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_SET_ALG_RESULT_PARAM"
}

云台控制 Post
http://192.168.13.202/request.php

上
{"type":"set_cloud_ctrl","module":"BUS_REQUEST_MESSAGE","body":{"dir":2,"degree":2}}

下
{"type":"set_cloud_ctrl","module":"BUS_REQUEST_MESSAGE","body":{"dir":4,"degree":2}}

左
{"type":"set_cloud_ctrl","module":"BUS_REQUEST_MESSAGE","body":{"dir":32,"degree":2}}

右
{"type":"set_cloud_ctrl","module":"BUS_REQUEST_MESSAGE","body":{"dir":16,"degree":2}}

停
{"type":"set_cloud_ctrl","module":"BUS_REQUEST_MESSAGE","body":{"dir":8,"degree":0}}

{
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "set_cloud_ctrl"
}

电子变倍 Post

http://192.168.13.202/request.php

{"type":"set_avs_focus_prm","module":"AVS_REQUEST_MESSAGE","body":{"auto_focus":0,"digital_ptz_enable":false,"digital_zoom":1.6,"focus_step":0,"focus_type":0,"digital_ptz_window_size":{"height":0,"width":0,"x":0,"y":0}}}

{
	"error_msg": "",
	"state": 200,
	"type": "set_avs_focus_prm"
}

## 数据查询页
图片预览查询 Post
http://192.168.13.202/request.php

{"type":"STORE_SEARCH_IMG_REQUEST","module":"STORE_BUSINESS_REQUEST","body":{"page_size":100,"page_num":1,"condition":{"plate":"","start_time":"2022-02-28 00:00:00","end_time":"2022-02-28 16:20:45","trigger":0}}}

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

双击图片日志条目 Post
http://192.168.13.202/request.php

{"type":"STORE_READ_IMG_REQUEST","module":"STORE_BUSINESS_REQUEST","body":{"id":"5"}}

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

图片数据
http://192.168.13.202/htmldata/picdata02.pic?1646036565157

## 高级设置页
### 识别设置
#### 请求
Post
http://192.168.13.202/getivsctrl.php

8:1:MA	=

OK ivsctrl=8:1:MA==

Post
http://192.168.13.202/avsjson.php

{"type":"AVS_GET_CAPTURE_PRM"}	

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

Post
http://192.168.13.202/request.php

{"type":"evs_get_gpioin_func","module":"EVS_BUS_REQUEST"}	

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

Post
http://192.168.13.202/getivsctrl.php

4:1:MA	=

OK ivsctrl=4:1:MQ==

Post
http://192.168.13.202/geteventruleexhtm.php

0

OK geteventruleex=1:1:45:400:10:2

Post
http://192.168.13.202/avsjson.php

{"type":"AVS_GET_ALG_RESULT_PROP"}	

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

Post
http://192.168.13.202/avsjson.php

{"type":"get_new_energy_plate_support"}	

{
	"body": {
		"support": 0
	},
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "get_new_energy_plate_support"
}


Post
http://192.168.13.202/avsjson.php

{"type":"get_car_info_support"}	

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

Post
http://192.168.13.202/avsjson.php

{"type":"AVS_GET_ALG_RESULT_PARAM"}	

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

#### 操作
触发模式 - 勾选虚拟线圈 Post

http://192.168.13.202/ivsctrl.php

5:1:Mw	=

OK

http://192.168.13.202/getivsctrl.php

4:1:MA	=

OK ivsctrl=4:1:Mw==

触发模式 - 取消勾选虚拟线圈 Post

http://192.168.13.202/ivsctrl.php

5:1:MQ	=

OK

http://192.168.13.202/getivsctrl.php

4:1:MA	=

OK ivsctrl=4:1:MQ==


触发模式 - 勾选稳定识别 Post

http://192.168.13.202/ivsctrl.php

5:1:MQ	=

OK

http://192.168.13.202/getivsctrl.php

4:1:MA	=

OK ivsctrl=4:1:MQ==

触发模式 - 取消勾选稳定识别 Post

http://192.168.13.202/ivsctrl.php

5:1:MA	=

OK

http://192.168.13.202/getivsctrl.php

4:1:MA	=

OK ivsctrl=4:1:MA==

触发模式 - 勾选电平输入1 Post

http://192.168.13.202/ivsctrl.php

5:2:MTY	

OK

http://192.168.13.202/getivsctrl.php

4:1:MA	=

OK ivsctrl=4:2:MTY=

触发模式 - 取消勾选电平输入1 Post

http://192.168.13.202/ivsctrl.php

5:1:MA	=

OK

http://192.168.13.202/getivsctrl.php

4:1:MA	=

OK ivsctrl=4:1:MA==

触发模式 - 勾选电平输入2 Post

http://192.168.13.202/ivsctrl.php

5:2:MzI	

OK

http://192.168.13.202/getivsctrl.php

4:1:MA	=

OK ivsctrl=4:2:MzI=

触发模式 - 取消勾选电平输入2 Post

http://192.168.13.202/ivsctrl.php

5:1:MA	=

OK

http://192.168.13.202/getivsctrl.php

4:1:MA	=

OK ivsctrl=4:1:MA==

识别参数 - 图片分辨率 Post
http://192.168.13.202/avsjson.php

{"type":"AVS_SET_ALG_RESULT_PARAM","body":{"snap_resolution":5,"snap_image_quality":100,"fake_threshold":53}}	

640 -> 3
704 -> 5
1280 -> 9
1920 -> 10
2304 -> 11

{
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_SET_ALG_RESULT_PARAM"
}

识别参数 - 图片质量 Post
http://192.168.13.202/avsjson.php

{"type":"AVS_SET_ALG_RESULT_PARAM","body":{"snap_resolution":5,"snap_image_quality":100,"fake_threshold":53}}	

10% ~ 100%

{
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_SET_ALG_RESULT_PARAM"
}

识别参数 - 连续抓拍模式 Post
http://192.168.13.202/avsjson.php

{"type":"AVS_SET_CAPTURE_PRM","body":{"mode":1,"duration":10,"none_duration":10,"max_duration":60}}	

mode：0-关闭 1-车牌触发 2-定时触发 3-线圈触发
duration：连续触发间隔（秒）
none_duration：无车牌抓拍间隔（秒）
max_duration：最长抓拍时间(秒)

{
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_SET_CAPTURE_PRM"
}


http://192.168.13.202/avsjson.php

{"type":"AVS_GET_CAPTURE_PRM"}	
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

识别参数 - 车牌像素限制 Post
http://192.168.13.202/seteventruleexhtm.php

1:1:50:400:10:2	

车牌像素限制(像素)：50~400
相同车牌触发间隔(秒)：10

OK seteventrule1

http://192.168.13.202/geteventruleexhtm.php

0

OK geteventruleex=1:1:50:400:10:2

识别参数 - 无车牌触发 - 勾选输出无车牌信息 Post
http://192.168.13.202/ivsctrl.php

7:11:LTIxNDc0ODM2NDg	

OK

http://192.168.13.202/getivsctrl.php

8:1:MA	=

OK ivsctrl=8:10:MjE0NzQ4MzY0OA==

识别参数 - 无车牌触发 - 取消勾选输出无车牌信息 Post
http://192.168.13.202/ivsctrl.php

7:1:MA	=	

OK

http://192.168.13.202/getivsctrl.php

8:1:MA	=

OK ivsctrl=8:1:MA==

识别参数 - 无车牌触发 - 勾选车牌防伪 Post
http://192.168.13.202/ivsctrl.php

7:9:NTM2ODcwOTEy	

OK

http://192.168.13.202/getivsctrl.php

8:1:MA	=

OK ivsctrl=8:9:NTM2ODcwOTEy

http://192.168.13.202/vb.htm?filtfakeplate=1&_=1646036087952 虚假车牌告警 Get
http://192.168.13.202/vb.htm?filtfakeplate=0&_=1646036087953 虚假车牌过滤 Get

识别参数 - 无车牌触发 - 勾选车牌防伪 - 防伪匹配度 Post
http://192.168.13.202/avsjson.php

{"type":"AVS_SET_ALG_RESULT_PARAM","body":{"snap_resolution":11,"snap_image_quality":90,"fake_threshold":73}}	
低-53 中-73 高-93

{
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_SET_ALG_RESULT_PARAM"
}

识别参数 - 无车牌触发 - 取消勾选输出无车牌信息 Post
http://192.168.13.202/ivsctrl.php

7:1:MA	=	

OK

http://192.168.13.202/getivsctrl.php

8:1:MA	=

OK ivsctrl=8:1:MA==


http://192.168.13.202/avsjson.php
http://192.168.13.202/avsjson.php
http://192.168.13.202/avsjson.php
http://192.168.13.202/avsjson.php
http://192.168.13.202/avsjson.php
http://192.168.13.202/avsjson.php
http://192.168.13.202/avsjson.php


### 音视频
#### 请求



#### 操作

### 基础网络
#### 请求



#### 操作

### 白名单
#### 请求



#### 操作

### 高级网络
#### 请求



#### 操作

### 外设管理
#### 请求



#### 操作

### 屏显语音
#### 请求



#### 操作

### 出入口配置
#### 请求



#### 操作

### 联动管理
#### 请求



#### 操作

http://192.168.13.202/avsjson.php
http://192.168.13.202/avsjson.php




## 设备维护页
### 请求

### 操作































