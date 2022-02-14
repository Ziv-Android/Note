//设备通用的应用程序接口
#ifndef _VZ_CLIENT_SDK_H_
#define _VZ_CLIENT_SDK_H_
#include <VzClientSDKDefine.h>

/**
* @defgroup group_global 全局操作函数
* @defgroup group_device 单个设备操作函数
* @defgroup group_callback 回调函数
*/

//#ifdef  LINUX
//#ifdef __cplusplus
extern "C"
{
//#endif
//#endif

/**
*  @brief 全局初始化
*  @return 0表示成功，-1表示失败
*  @note 在所有接口调用之前调用
*  @ingroup group_global
*/
VZ_API int __STDCALL VzClient_Setup();

/**
*  @brief 全局释放
*  @note 在程序结束时调用，释放SDK的资源
*  @ingroup group_global
*/
VZ_API void __STDCALL VzClient_Cleanup();

/**
*  @brief 通过该回调函数获得找到的设备基本信息
*  @param  [IN] pStrDevName 设备名称
*  @param  [IN] pStrIPAddr	设备IP地址
*  @param  [IN] usPort1		设备端口号
*  @param  [IN] usPort2		预留
*  @param  [IN] SL          设备序列号低位字节
*  @param  [IN] SH			设备序列号高位字节
*  @param  [IN] pUserData	回调函数上下文
*  @ingroup group_callback
*/
typedef void(__STDCALL *VZ_FIND_DEVICE_CALLBACK)(const char *pStrDevName, const char *pStrIPAddr, WORD usPort1, WORD usType, unsigned int SL, unsigned int SH, char* netmask, char* gateway, void *pUserData);

/**
*  @brief 开始查找设备
*  @param  [IN] func 找到的设备通过该回调函数返回
*  @param  [IN] pUserData 回调函数中的上下文
*  @return 0表示成功，-1表示失败
*  @ingroup group_global
*/
VZ_API int __STDCALL VZClient_StartFindDevice(VZ_FIND_DEVICE_CALLBACK func, void *pUserData);



/**
*  @brief 停止查找设备
*  @ingroup group_global
*/
VZ_API void __STDCALL VZClient_StopFindDevice();

/**
*  @brief 通过该回调函数获得设备的一般状态信息
*  @param  [IN] handle		由VzClient_Open函数获得的句柄
*  @param  [IN] pUserData	回调函数上下文
*  @param  [IN] eNotify		通用信息反馈类型
*  @param  [IN] pStrDetail	详细描述字符串
*  @ingroup group_callback
*/
typedef void (__STDCALL *VZ_COMMON_NOTIFY_CALLBACK)(VzClientHandle handle, void *pUserData,
													   VZ_COMMON_NOTIFY eNotify, const char *pStrDetail);

/**
*  @brief 设置设备连接反馈结果相关的回调函数
*  @param  [IN] func 设备连接结果和状态，通过该回调函数返回
*  @param  [IN] pUserData 回调函数中的上下文
*  @return 0表示成功，-1表示失败
*  @ingroup group_global
*/
VZ_API int __STDCALL VZClient_SetCommonNotifyCallBack(VZ_COMMON_NOTIFY_CALLBACK func, void *pUserData);

/**
*  @brief 打开一个设备
*  @param  [IN] pStrIP 设备的IP地址
*  @param  [IN] wPort 设备的端口号
*  @param  [IN] pStrUserName 访问设备所需用户名
*  @param  [IN] pStrPassword 访问设备所需密码
*  @return 返回设备的操作句柄，当打开失败时，返回0
*  @ingroup group_device
*/
VZ_API VzClientHandle __STDCALL VzClient_Open(
  const char *pStrIP,
  WORD wPort,
  const char *pStrUserName,
  const char *pStrPassword);

/**
*  @brief 打开一个设备
*  @param  [IN] pStrIP 设备的IP地址
*  @param  [IN] wPort 设备的端口号
*  @param  [IN] pStrUserName 访问设备所需用户名
*  @param  [IN] pStrPassword 访问设备所需密码
*  @param  [IN] wRtspPort 流媒体的端口号,为0表示使用默认
*  @return 返回设备的操作句柄，当打开失败时，返回0
*  @ingroup group_device
*/
VZ_API VzClientHandle __STDCALL VzClient_OpenEx(const char *pStrIP, WORD wPort, const char *pStrUserName, const char *pStrPassword,WORD wRtspPort);


/**
*  @brief 关闭一个设备
*  @param  [IN] handle 由VzClient_Open函数获得的句柄
*  @return 0表示成功，-1表示失败
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_Close(VzClientHandle handle);


/**
*  @brief 获取连接状态
*  @param  [IN] handle 由VzClient_Open函数获得的句柄
*  @param  [IN/OUT] pStatus 输入获取状态的变量地址，输出内容为 1已连上，0未连上
*  @return 0表示成功，-1表示失败
*  @note   用户可以周期调用该函数来主动查询设备是否断线，以及断线后是否恢复连接
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_IsConnected(VzClientHandle handle, BYTE *pStatus);

/**
*  @brief 播放实时视频
*  @param  [IN] handle 由VzClient_Open函数获得的句柄
*  @param  [IN] hWnd 窗口的句柄
*  @return 播放的句柄，-1表示失败
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_StartRealPlay(VzClientHandle handle, void *hWnd);

/**
*  @brief 播放实时视频(支持硬件解码)
*  @param  [IN] handle 由VzClient_Open函数获得的句柄
*  @param  [IN] hWnd 窗口的句柄
*  @param  [IN] type(0软件解码, 1硬件解码)
*  @return 播放的句柄，-1表示失败
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_StartRealPlayEx(VzClientHandle handle, void *hWnd, int type);

/**
*  @brief 播放实时视频
*  @param  [IN] handle 由VzClient_Open函数获得的句柄
*  @param  [IN] hWnd 窗口的句柄
*  @param  [IN] channel 通道号
*  @param  [IN] stream_id 码流id(0主码流, 1子码流)
*  @return 播放的句柄，-1表示失败
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_StartRealPlayByChannel(VzClientHandle handle, void *hWnd, int channel, int stream_id);

/**
*  @brief 停止播放指定的播放句柄
*  @param  [IN] nPlayHandle 播放的句柄
*  @return 0表示成功，-1表示失败
*  @note   可用来停止播放来自函数VzClient_StartRealPlay和VzClient_StartRealPlayFrameCallBack的播放句柄
*  @note   停止播放以后，该播放句柄就失效了
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_StopRealPlay(int nPlayHandle);

/**
*  @brief 写入用户私有数据，可用于二次加密
*  @param [IN] handle 由VzClient_Open函数获得的句柄
*  @param [IN] pUserData 用户数据
*  @param [IN] uSizeData 用户数据的长度，最大128字节
*  @return 返回值为0表示成功，返回其他值表示失败
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_WriteUserData(VzClientHandle handle, const unsigned char *pUserData, unsigned uSizeData);

/**
*  @brief 读出用户私有数据，可用于二次加密
*  @param [IN] handle 由VzClient_Open函数获得的句柄
*  @param [IN/OUT] pBuffer 用于存放读到的用户数据
*  @param [IN] uSizeBuf 用户数据缓冲区的最小尺寸，不小于128字节
*  @return 返回值为实际用户数据的字节数，返回-1表示失败
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_ReadUserData(VzClientHandle handle, unsigned char *pBuffer, unsigned uSizeBuf);

/**
*  @brief 读出设备序列号，可用于二次加密
*  @param [IN] handle 由VzClient_Open函数获得的句柄
*  @param [IN/OUT] pSN 用于存放读到的设备序列号，详见定义 VZ_DEV_SERIAL_NUM
*  @return 返回值为0表示成功，返回-1表示失败
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_GetSerialNumber(VzClientHandle handle, VZ_DEV_SERIAL_NUM *pSN);

/**
*  @brief 获取设备的日期时间
*  @param [IN] handle 由VzClient_Open函数获得的句柄
*  @param [IN/OUT] pDTInfo 用于存放获取到的设备日期时间信息，详见定义 VZ_DATE_TIME_INFO
*  @return 返回值为0表示成功，返回-1表示失败
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_GetDateTime(VzClientHandle handle, VZ_DATE_TIME_INFO *pDTInfo);

/**
*  @brief 设置设备的日期时间
*  @param [IN] handle 由VzClient_Open函数获得的句柄
*  @param [IN] pDTInfo 将要设置的设备日期时间信息，详见定义 VZ_DATE_TIME_INFO
*  @return 返回值为0表示成功，返回-1表示失败
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_SetDateTime(VzClientHandle handle, const VZ_DATE_TIME_INFO *pDTInfo);


/**
*  @brief 开始升级
*  @param  [IN] handle 由VzClient_Open函数获得的句柄
*  @param [IN] file_path_name 升级文件路径
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_Update(VzClientHandle handle, char *file_path_name);


/**
*  @brief 获取升级的状态
*  @param  [IN] handle 由VzClient_Open函数获得的句柄
*  @return 升级的状态
*			0: 还未升过级
*			1: 升级成功
*			2: 正在升级，上传中，可以取消升级
*			3: 正在升级，写flash中，取消升级不可用
*		    4: 网络问题，状态未知
*		   -1: 升级失败
*			失败或者网络问题时可以通过getlasterror获得升级错误信息，定义在UPDATE_ERROR里
*/
VZ_API int __STDCALL VzClient_GetUpdateState(VzClientHandle handle);


/**
*  @brief 取消升级，当升级状态在2时，可以取消升级，其余时候无用途
*  @param  [IN] handle 由VzClient_Open函数获得的句柄
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_StopUpdate(VzClientHandle handle);


/**
*  @brief 获取升级进度，上传完毕为50，升级完成为100，当前会从50直接跳到100，中间进度不会更新，以后解决
*  @param  [IN] handle 由VzClient_Open函数获得的句柄
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_GetUpdateProgress(VzClientHandle handle);

/**
* 重启设备
*/
VZ_API int __STDCALL VzClient_RebootDVR( VzClientHandle handle );

/**
*  @brief 打开一个设备，支持外网访问设备
*  @param  [IN] pStrIP 设备的IP地址
*  @param  [IN] wPort 设备的端口号
*  @param  [IN] pStrUserName 访问设备所需用户名
*  @param  [IN] pStrPassword 访问设备所需密码
*  @param  [IN] wHttpPort 流媒体的端口号,默认为80(如果为0表示使用默认端口）
*  @param  [IN] network_type 网络类型(0局域网,1外网-PDNS方式)
*  @param  [IN] sn 设备序列号
*  @return 返回设备的操作句柄，当打开失败时，返回0
*  @ingroup group_device
*/
VZ_API VzClientHandle __STDCALL VzClient_OpenV2(const char *pStrIP, WORD wPort, const char *pStrUserName, const char *pStrPassword,WORD wHttpPort, int network_type, char* sn);

/**
*  @brief 设置中心服务器事件（识别结果、报警等）推送信息
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] pAlarmParam  事件推送配置
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_SetCenterServerAlarm(VzLPRClientHandle handle, const VZ_CENTER_SERVER_ALARM_PARAM *pAlarmParam);

/**
*  @brief 获取中心服务器事件（识别结果、报警等）推送信息
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] pAlarmParam  事件推送配置
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_GetCenterServerAlarm(VzLPRClientHandle handle, VZ_CENTER_SERVER_ALARM_PARAM * pAlarmParam);

/**
*  @brief 格式化sd卡
*  @param  [IN] handle 由VzClient_Open函数获得的句柄
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_SDFormat(VzClientHandle handle);


/**
*  @brief 设置字体库路径
*  @param [IN] handle 由VzClient_Open函数获得的句柄
*  @param [IN] font_path 字体库路径
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_SetDrawFont(VzClientHandle handle, const char *font_path);

/**
*  @brief 在yuv数据中绘制的文字
*  @param [IN] nPlayHandle	由VzClient_StartRealPlay函数获得的句柄
*  @param [IN] text   文字内容
*  @param [IN] text_x 文字x坐标为千分比 范围为[0-1000]
*  @param [IN] text_y 文字y坐标为千分比 范围为[0-1000]
*  @param [IN] font_size 字体大小
*  @param [IN] r 颜色范围为[0-255]
*  @param [IN] g 颜色范围为[0-255]
*  @param [IN] b 颜色范围为[0-255]
*  @return 成功返回0，失败返回-1
*/
VZ_API int __STDCALL VzClient_DrawYUVText(int play_handle, const VzYUV420P *pFrame, const char *text, int text_x, int text_y, int font_size, int r, int g, int b);

/**
*  @brief 在yuv数据中绘制矩形框
*  @param [IN] x         矩形框x坐标为千分比 范围为[0-1000]
*  @param [IN] y         矩形框y坐标为千分比 范围为[0-1000]
*  @param [IN] width     矩形框宽度为千分比 范围为[0-1000]
*  @param [IN] height    矩形框高度为千分比 范围为[0-1000]
*  @param [IN] line_size 矩形框线宽
*  @param [IN] r 颜色范围为[0-255]
*  @param [IN] g 颜色范围为[0-255]
*  @param [IN] b 颜色范围为[0-255]
*  @return 成功返回0，失败返回-1
*/
VZ_API int __STDCALL VzClient_DrawYUVRect(int play_handle, const VzYUV420P *pFrame, int x, int y, int width, int height, int line_size, int r, int g, int b);

/**
*  @brief  通过该回调函数获得实时解码图像数据
*  @param  [IN] nPlayHandle	由VzClient_StartRealPlay函数获得的句柄
*  @param  [IN] pUserData	回调函数的上下文
*  @param  [IN] pFrame		图像帧信息，详见结构体定义VzYUV420P
*  @return 0表示成功，-1表示失败
*  @ingroup group_callback
*/
typedef void (__STDCALL *VZ_VIDEO_DECODE_DATA_CALLBACK)(long handle, void *pUserData,
													  const VzYUV420P *pFrame, unsigned uPtsSec, unsigned uPtsUSec);
/**
*  @brief 设置实时解码图像数据的回调函数
*  @param  [IN] nPlayHandle		由VzClient_StartRealPlay函数获得的句柄
*  @param  [IN] func		实时图像数据函数
*  @param  [IN] pUserData	回调函数中的上下文
*  @return 0表示成功，-1表示失败
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_SetDecodeDataCallBack(int play_handle, VZ_VIDEO_DECODE_DATA_CALLBACK func, void *pUserData);

/**
*  @brief 通过流媒体地址播放视频流(支持rtmp、rtsp等url)
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] hWnd 窗口的句柄(可以传null)
*  @param  [IN] pUserData	回调函数中的上下文
*  @return 0表示成功，-1表示失败
*  @remark 打开网络流可能会比较慢，此接口会阻塞，建议开线程调用
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_StartPlayUrlStream(VzClientHandle handle, const char* stream_url, void *hwnd);

/**
*  @brief 停止视频流播放
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @return 0表示成功，-1表示失败
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_StopPlayUrlStream(VzClientHandle handle);

/**
*  @brief 设置流媒体地址播放视频流的解码图像数据的回调函数
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] func		实时图像数据函数
*  @param  [IN] pUserData	回调函数中的上下文
*  @return 0表示成功，-1表示失败
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_SetUrlStreamDecodeCallBack(VzClientHandle handle, VZ_VIDEO_DECODE_DATA_CALLBACK func, void *pUserData);


/**
*  @brief 初始化云端参数，用于连接云平台音视频服务器，播放音视频(全局接口，程序启动后调用，只调用一次)
*  @param  [IN] pdns_addr 服务器地址
*  @param  [IN] username  用户名
*  @param  [IN] accesskey_id	 
*  @param  [IN] accesskey_secret 
*  @param  [IN] res       预留参数	
*  @return 0表示成功，-1表示失败
*  @ingroup group_global
*/
VZ_API int __STDCALL VzClient_CloudSetup(const char *pdns_addr, const char *username, const char *accesskey_id, const char *accesskey_secret, const char *res);

/**
*  @brief 播放实时视频(通过云平台方式播放视频)
*  @param  [IN] handle 由VzClient_Open函数获得的句柄
*  @param  [IN] hWnd 窗口的句柄
*  @return 播放的句柄，-1表示失败
*  @ingroup group_device
*/
VZ_API long __STDCALL VzClient_CloudStartRealPlay(VzClientHandle handle, void *hWnd);


/**
*  @brief 停止播放实时视频(通过云平台方式播放视频)
*  @param  [IN] handle 由VzClient_Open函数获得的句柄
*  @param  [IN] hWnd 窗口的句柄
*  @return 播放的句柄，-1表示失败
*  @ingroup group_device
*/
VZ_API long __STDCALL VzClient_CloudStopRealPlay(long nPlayHandle);

/**
*  @brief 释放云平台的连接(全局接口，程序退出前调用， 只调用一次)
*  @return 0表示成功，-1表示失败
*  @ingroup group_global
*/
VZ_API int __STDCALL VzClient_CloudCleanup();


/**
*  @brief 识别结果回调扩展
*  @param [OUT] iType结果类型COMMON_ALARM_RESULT_TYPE
*  @param [OUT] pResultInfo结果信息 JSON格式
*  @param [OUT] len结果信息长度
*  @param [OUT] pUserData 用户自定义数据
*/
typedef void (__STDCALL *VZ_COMMON_RESULT_CALLBACK)(VzClientHandle handle, int type, const char *pResultInfo, int len, void *pUserData);

/**
*  @brief 设置通用识别结果回调
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] func 回调接口
*  @param [IN] pUserData 用户自定义数据
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_SetCommonResultCallBackEx(VzClientHandle handle, int type, VZ_COMMON_RESULT_CALLBACK func, void* pUserData);

/**
*  @brief 开始录像功能,录像保存成mp4文件
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] stream_type 流类型(0主码流, 1子码流)
*  @param [IN] timeout 超时时间(毫秒，比如： 5000)
*  @param [IN] file_path 录像文件保存的路径(例如: d:/test.mp4)
*  @return 返回值为0表示成功，返回-1表示失败
*  @ingroup group_device
*/
VZ_API int __STDCALL VzLPRClient_StartRecord(VzClientHandle handle, int stream_type, int timeout, const char *file_path);

/**
*  @brief 停止录像
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @return 返回值为0表示成功，返回-1表示失败
*  @ingroup group_device
*/
VZ_API int __STDCALL VzLPRClient_StopRecord(VzClientHandle handle, int stream_type);

/**
*  @brief 云台控制
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] dir 方向，2:向上移动 4:向下移动 8:停止上下移动 16:向左移动 32:向右移动 64:停止左右移动 128:还原
*  @param [IN] degree 角度[0~65535]
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_SetPtzCtrl(VzClientHandle handle, int dir, int degree);

/**
*  @brief 升锁/降锁操作
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] option操作，0:测试连接 1:升锁 1:降锁
*  @param [IN] zone_id车位id，0:左车位 1:右车位
*  @param [IN] lock_id锁id，0:锁一 1:锁二
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_LockControl(VzClientHandle handle, int option, int zone_id, int lock_id);

//#ifdef  LINUX
//#ifdef __cplusplus
}
//#endif
//#endif

#endif
