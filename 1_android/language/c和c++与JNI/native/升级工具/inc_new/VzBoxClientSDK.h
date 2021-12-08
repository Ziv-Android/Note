//用于接入VZ的智慧盒子的应用程序接口
#ifndef _VZ_BOX_CLIENT_SDK_
#define _VZ_BOX_CLIENT_SDK_
#include <VzClientSDKDefine.h>



#ifdef  LINUX
#ifdef __cplusplus
extern "C"
{
#endif
#endif

/**
*  @brief 获取盒子连接的相机列表
*  @param [IN] handle 由VzClient_Open函数获得的句柄
*  @param [OUT] cam_group 相机信息列表
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_GetCamGroupParam(VzClientHandle handle, VZ_BOX_CAM_GROUP* cam_group);

/**
*  @brief 获取盒子连接的相机列表 扩展分组信息 
*  @param [IN] handle 由VzClient_Open函数获得的句柄
*  @param [OUT] cam_group 相机信息列表
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_GetCamGroupParamEx(VzClientHandle handle, char *response, int max_len);

/**
*  @brief 添加相机
*  @param [IN] handle 由VzClient_Open函数获得的句柄
*  @param [IN] pInfo 相机通道属性
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_BoxAddCam(VzClientHandle handle, const VZ_BOX_CAM_INFO *pInfo);

/**
*  @brief 根据通道号编辑相机。如果修改了IP属性，则会移出已有分组，需要重新配置分组信息
*  @param [IN] handle 由VzClient_Open函数获得的句柄
*  @param [IN] nChnId 由VzClient_GetCamGroupParam函数获取的信息：VZ_BOX_CAM_GROUP::VZ_BOX_CAM_ITEM::chn_id
*  @param [IN] pInfo 相机通道属性
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_BoxSetCam(VzClientHandle handle, int nChnId, const VZ_BOX_CAM_INFO *pInfo);

/**
*  @brief 根据IP地址批量删除相机。
*  @param [IN] handle 由VzClient_Open函数获得的句柄
*  @param [IN] ip 待删除相机的IP地址数组
*  @param [IN] nNum 待删除相机的IP地址数组长度
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_BoxRemoveCams(VzClientHandle handle, const char * const ip[], int nNum);

/**
*  @brief 云平台，人脸对比
*  @param [IN] handle 由VzClient_Open函数获得的句柄
*  @param [IN] app_id 人脸库ID数组
*  @param [IN] app_count 人脸库个数
*  @param [IN] image_data 人脸图片数据(jpg格式文件数据)
*  @param [IN] image_len  图片数据的长度
*  @param [IN] max_user_num  搜索后返回的结果数量
*  @param [IN] detail_type  搜索后返回的结果数量(0：不返回图片和用户详细信息 1：返回图片与用户详细信息)
*  @param [OUT] face_result 人脸对比结果
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_CloudFaceRecognition(VzClientHandle handle, int* app_id, int app_count, char *image_data, int image_len, int max_user_num, int detail_type, VZ_FACE_USER_RESULT *face_result);


/**
*  @brief 清理人脸对比结果生成的图片数据(不调此接口清理，会造成内存泄露)
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_ReleaseFaceRecognitionData(VzLPRClientHandle handle, VZ_FACE_USER_RESULT *face_result);

/**
*  @brief 云平台，车牌识别
*  @param [IN] handle 由VzClient_Open函数获得的句柄
*  @param [IN] app_id 车牌库ID
*  @param [IN] image_data 人脸图片数据(jpg格式文件数据)
*  @param [IN] image_len  图片数据的长度
*  @param [OUT] plate_result 车牌识别结果
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_CloudPlateRecognition(VzClientHandle handle, int app_id, char *image_data, int image_len, TH_PlateResult *plate_result);


/**
*  @brief 人脸识别库操作
*  @param [IN] handle 由VzClient_Open函数获得的句柄
*  @param [IN] item 人脸库信息
*  @param [IN] oper 操作类型(1：创建底库 2：删除底库 3：修改底库)
*  @return 返回值为0表示成功，返回其他值表示失败。 当为创建操作时,返回值为库id > 0
*/
VZ_API int __STDCALL VzClient_FaceRecgLibOperate(VzClientHandle handle, VZ_FACE_LIB_ITEM *item, int oper);


/**
*  @brief 查找人脸库
*  @param [IN] handle 由VzClient_Open函数获得的句柄
*  @param [OUT] lib_result 人脸库结果
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_SearchFaceRecgLib(VzClientHandle handle, VZ_FACE_LIB_RESULT *lib_result);

/**
*  @brief 添加人脸信息到人脸识别库
*  @param [IN] handle 由VzClient_Open函数获得的句柄
*  @param [IN] user_info 用户数据
*  @return 返回值大于等于0表示成功，大于0时，为人脸库的id， 返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_FaceRecgUserAdd(VzClientHandle handle, VZ_FACE_USER_RESULT *user_info);

/**
*  @brief 添加人脸信息到人脸识别库异步接口，支持内存导入
*  @param [IN] handle 由VzClient_Open函数获得的句柄
*  @param [IN] user_info 用户数据
*  @param [OUT] err_msg 错误信息
*  @param [IN]  max_len  err_msg最大长度
*  @param [OUT] delay 延迟时间。 当这个值大于1时代表当前设备繁忙，并且此条信息导入失败，需要延迟delay(毫秒)后重传
*  @return 返回值大于等于0表示成功，大于0时，为人脸库的id， 返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_FaceRecgUserAddAsync(VzClientHandle handle, VZ_FACE_USER_RESULT *user_info, char *err_msg, int max_len, int* delay);

/**
*  @brief 编辑人脸信息（需要传入pic_index）
*  @param [IN] handle 由VzClient_Open函数获得的句柄
*  @param [IN] user_info 用户数据
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_FaceRecgUserEdit(VzClientHandle handle, VZ_FACE_USER_RESULT *user_info);

/**
*  @brief 删除人脸数据
*  @param [IN] handle 由VzClient_Open函数获得的句柄
*  @param [IN] pic_index 人脸数据id
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_FaceRecgUserDelete(VzClientHandle handle, int pic_index);

/**
*  @brief 根据UserId删除人脸数据
*  @param [IN] handle 由VzClient_Open函数获得的句柄
*  @param [IN] user_id 人脸用户id
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_FaceRecgUserDeleteByUserId(VzClientHandle handle, const char* user_id);

/**
*  @brief 根据UserId获取人脸信息
*  @param [IN] handle 由VzClient_Open函数获得的句柄
*  @param [IN] user_info 人脸信息
*  @param [IN] user_id 人脸用户id
*  @return 返回值大于等于0表示成功，大于0时，为人脸库的id， 返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_GetFaceInfoByUserId(VzClientHandle handle, VZ_FACE_USER_ITEM *user_item, const char* user_id);

/**
*  @brief 编辑人脸信息（需要传入user_id）
*  @param [IN] handle 由VzClient_Open函数获得的句柄
*  @param [IN] user_info 用户数据
*  @param [IN] user_id 人脸用户id
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_FaceRecgUserEditByUserId(VzClientHandle handle, VZ_FACE_USER_RESULT *user_info, const char* user_id);

/**
*  @brief 添加人脸数据到数组中
*  @param [IN] handle 由VzClient_Open函数获得的句柄
*  @param [IN] user_item 人脸数据
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_FaceRecgAddUserToArray(VzClientHandle handle, VZ_FACE_USER_ITEM *user_item);

/**
*  @brief 清空数组中的数据
*  @param [IN] handle 由VzClient_Open函数获得的句柄
*  @param [IN] user_item 人脸数据
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_FaceRecgClearUserArray(VzClientHandle handle);

/**
*  @brief 执行批量导入
*  @param [IN] handle 由VzClient_Open函数获得的句柄
*  @param [IN] user_item 人脸数据
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_FaceRecgBatchImportUserFromArray(VzClientHandle handle);

/**
*  @brief 获取导入结果
*  @param [IN] handle 由VzClient_Open函数获得的句柄
*  @param [OUT] success_count 成功的个数
*  @param [OUT] failed_count  失败的个数
*  @param [OUT] total_count   导入的个数
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_FaceRecgGetImportResult(VzClientHandle handle, int *import_count, int *total_count);


/**
*  @brief 获取导入的错误信息
*  @param [IN] handle 由VzClient_Open函数获得的句柄
*  @param [OUT] err_msg 成功的个数
*  @param [IN]  max_msg_len  失败的个数
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_FaceRecgGetImportErrMsg(VzClientHandle handle, char *err_msg, int max_len);

/**
*  @brief 查找人脸识别库中的数据
*  @param [IN] handle 由VzClient_Open函数获得的句柄
*  @param [IN] condition 查询条件
*  @param [IN] db_id 人脸库的id
*  @param [OUT] user_info 查询结果
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_SearchFaceRecgUser(VzClientHandle handle, VZ_FACE_LIB_SEARCH_CONDITION *condition, int db_id, VZ_FACE_USER_RESULT *user_info);

/**
*  @brief 根据路径获取图片
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] img_path 存储在相机里面的图片路径
*  @param  [IN] pdata  存储图片的内存
*  @param  [IN][OUT] size 为传入传出值，传入为图片内存的大小，返回的是获取到jpg图片内存的大小
*  @return 返回值为0表示成功，返回-1表示失败
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_LoadFaceImageByPath(VzClientHandle handle, const char* img_path, void *pdata, int* size);

/**
*  @brief 获取最近抓拍的一个评分最高的结果
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] near_time  时间范围
*  @param  [OUT] face_result 人脸结果
*  @return 返回值为0表示成功，返回-1表示失败
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_GetBestFaceResult(VzClientHandle handle, int near_time, TH_FaceResult* face_result);


/**
*  @brief 清理人脸获取评分最高的图片数据(不调此接口清理，会造成内存泄露)
*  @param [IN] face_result 由VzClient_GetBestFaceResult返回的结果
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_ReleaseBestFaceResult(TH_FaceResult *face_result);

/**
*  @brief 获取系统当前人脸特征提取开关的状态
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [OUT] feature_extract_status 人脸特征提取状态， 0表示未开启特征提取（默认），1表示开启特征提取
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_GetFaceFeatureExtractStatus(VzClientHandle handle, int *feature_extract_status);

/**
*  @brief 设置系统人脸特征提取开关
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] feature_extract 人脸特征提取状态， 0表示不开启特征提取（默认），1表示开启特征提取
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_SetFaceFeatureExtractStatus(VzClientHandle handle, int feature_extract);

/**
*  @brief 获取系统当前人脸特征提取开关的状态
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [OUT] feature_extract_status 人脸特征提取状态， 0表示未开启特征提取（默认），1表示开启特征提取
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_BoxGetSystemModuleSwitch(VzClientHandle handle, 
													   VZ_BOX_SYS_MOD_SWITCH eSwitch,
													   unsigned char *ucEnable);

/**
*  @brief 设置系统人脸特征提取开关
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] feature_extract 人脸特征提取状态， 0表示不开启特征提取（默认），1表示开启特征提取
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_BoxSetSystemModuleSwitch(VzClientHandle handle, 
													VZ_BOX_SYS_MOD_SWITCH eSwitch,
													unsigned char ucEnable);

/**
*  @brief 获取系统关联的人脸库
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [OUT] glob_libs 人脸库数组
*  @param [OUT] count     人脸库个数
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_GetGlobFacialCfg(VzClientHandle handle, int* glob_libs, int* enable, int* count);

/**
*  @brief 配置系统关联的人脸库
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] glob_libs 人脸库数组
*  @param [IN] count     人脸库个数
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_SetGlobFacialCfg(VzClientHandle handle, int* glob_libs, int enable, int count);

/**
*  @brief  通过该回调函数获得编码数据
*  @param  [IN] handle		由VzLPRClient_Open函数获得的句柄
*  @param  [IN] playhandle  播放句柄(VzClient_SetRealDataCallBack函数返回的句柄)
*  @param  [IN] pUserData	回调函数的上下文
*  @param  [IN] eDataType	数据类型，详见枚举VZ_LPRC_DATA_TYPE
*  @param  [IN] pData		数据帧信息，详见结构体定义VZ_LPRC_DATA_INFO
*  @ingroup group_callback
*/
typedef void (__STDCALL *VZ_REAL_DATA_CALLBACK)(VzClientHandle handle, int channel, int playhandle, void *pUserData,
													 VZ_LPRC_DATA_TYPE eDataType, const VZ_LPRC_DATA_INFO *pData);
#ifdef WIN32
/**
*  @brief 获取实时编码数据
*  @param  [IN] handle		由VzLPRClient_Open函数获得的句柄
*  @param  [IN] channel     通道号
*  @param  [IN] stream_id   码流id(0主码流, 1子码流)
*  @param  [IN] func		回调函数
*  @param  [IN] pUserData	回调函数中的上下文
*  @return 播放的句柄，-1表示失败
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_SetChannelRealDataCallBack(VzLPRClientHandle handle,
												  int channel, 
												  int stream_id,
												  VZ_REAL_DATA_CALLBACK func, 
												  void *pUserData);
#endif

/**
*  @brief 设备双网口的网络参数配置。
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] netcfg 参见VZ_LPRC_NETCFG_EX结构体定义
*  @return 返回值为0表示成功，返回其他值表示失败
*/
VZ_API int __STDCALL VzClient_SetSecondPortNetConfig(VzClientHandle handle, const VZ_LPRC_NETCFG_EX* netcfg);

/**
*  @brief 获取双网口的网络参数配置。
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] netcfg 参见VZ_LPRC_NETCFG_EX结构体定义
*  @return 返回值为0表示成功，返回其他值表示失败
*/
VZ_API int __STDCALL VzClient_GetSecondPortNetConfig(VzClientHandle handle, VZ_LPRC_NETCFG_EX* netcfg);
/**
*  @brief 设置http推送基础配置
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] basecfg 推送基本配置参数
*  @return 返回值为0表示成功，返回其他值表示失败
*/
VZ_API int __STDCALL VzClient_SetHttpPushBaseConfig(VzClientHandle handle, VZ_HTTP_PUSH_BASE_CFG* basecfg);

/**
*  @brief 获取http推送基础配置
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] basecfg 推送基本配置参数
*  @return 返回值为0表示成功，返回其他值表示失败
*/
VZ_API int __STDCALL VzClient_GetHttpPushBaseConfig(VzClientHandle handle, VZ_HTTP_PUSH_BASE_CFG* basecfg);

/**
*  @brief 设置http推送结果配置
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] push_param 推送结果配置
*  @return 返回值为0表示成功，返回其他值表示失败
*/
VZ_API int __STDCALL VzClient_SetBoxHttpPushParam(VzClientHandle handle, VZ_BOX_HTTP_PUSH_PARAM* push_param);

/**
*  @brief 获取http推送结果配置
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] push_param 推送配置参数
*  @return 返回值为0表示成功，返回其他值表示失败
*/
VZ_API int __STDCALL VzClient_GetBoxHttpPushParam(VzClientHandle handle, VZ_BOX_HTTP_PUSH_PARAM* push_param);


/**
*  @brief 将人脸库同步到门禁设备中
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] db_name 人脸底层
*  @param  [IN] db_id 人脸底库ID
*  @param  [IN] cam_items 门禁设备信息(填入ip,端口,用户名和密码)
*  @param  [IN] cam_count 门禁设备的数量
*  @return 返回值为0表示成功，返回-1表示失败
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_UpdateFaceLibToGateCam(VzClientHandle handle, const char* db_name, int db_id, VZ_BOX_CAM_INFO *cam_items, int cam_count);

/**
*  @brief 获取导入的状态
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [OUT] state 导入的状态(1正在导入,0导入完成)
*  @param  [OUT] msg 返回信息
*  @param  [IN/OUT] msg_len 数据长度
*  @return 返回值为0表示成功，返回-1表示失败
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_GetUpdateFaceGateLibState(VzClientHandle handle, int *state, char *msg, int *msg_len);

/**
*  @brief 获取支持导入的设备列表
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [OUT] cam_items 门禁设备信息(填入ip,端口,用户名和密码)
*  @param  [IN/OUT] cam_count 门禁设备的数量
*  @return 返回值为0表示成功，返回-1表示失败
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_GetSupportFaceLibCam(VzClientHandle handle, VZ_BOX_CAM_INFO *cam_items, int *cam_count);

#ifdef  LINUX
#ifdef __cplusplus
}
#endif
#endif


#endif
