//用于接入VZ的人脸抓拍相机的应用程序接口
#ifndef _VZ_LPR_FACE_CLIENT_SDK_
#define _VZ_LPR_FACE_CLIENT_SDK_
#include <VzClientSDKDefine.h>



#ifdef  LINUX
#ifdef __cplusplus
extern "C"
{
#endif
#endif

/**
*  @brief 人脸抓拍结果
*  @param [OUT] face_result 人脸结果
*  @param [OUT] pUserData 用户自定义数据
*/
typedef void (__STDCALL *VZLPRC_FACE_RESULT_CALLBACK)(VzLPRClientHandle handle, TH_FaceResult* face_result, void* pUserData);

/**
*  @brief 人脸抓拍结果扩展
*  @param [OUT] face_result 人脸结果
*  @param [OUT] pUserData 用户自定义数据
*/
typedef void (__STDCALL *VZLPRC_FACE_RESULT_EX_CALLBACK)(VzLPRClientHandle handle, TH_FaceResultEx* face_result, void* pUserData);

/**
*  @brief 设置人脸抓拍结果回调
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] func 回调接口
*  @param [IN] pUserData 用户自定义数据
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzLPRClient_SetFaceResultCallBack(VzLPRClientHandle handle, VZLPRC_FACE_RESULT_CALLBACK func, void* pUserData);

/**
*  @brief 设置人脸抓拍结果回调（扩展)
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] func 回调接口
*  @param [IN] pUserData 用户自定义数据
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzLPRClient_SetFaceResultExCallBack(VzLPRClientHandle handle, VZLPRC_FACE_RESULT_EX_CALLBACK func, void* pUserData);


/**
*  @brief 人数统计结果
*  @param [OUT] area1_num 区域一人数
*  @param [OUT] area2_num 区域二人数
*  @param [OUT] pUserData 用户自定义数据
*/
typedef void (__STDCALL *VZLPRC_FACE_COUNT_STAT_CALLBACK)(VzLPRClientHandle handle, int area1_num, int area2_num, void* pUserData);

/**
*  @brief 设置人数统计结果回调
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] func 回调接口
*  @param [IN] pUserData 用户自定义数据
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzLPRClient_SetFaceCountStatCallBack(VzLPRClientHandle handle, VZLPRC_FACE_COUNT_STAT_CALLBACK func, void* pUserData);


/**
*  @brief 获取人脸识别区域的规则
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [OUT] face_rule_area 人脸识别规则
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzLPRClient_GetFaceRuleArea(VzLPRClientHandle handle, TH_FaceRuleArea* face_rule_area);

/**
*  @brief 设置人脸识别区域的规则
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] face_rule_area 人脸识别规则
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzLPRClient_SetFaceRuleArea(VzLPRClientHandle handle, TH_FaceRuleArea* face_rule_area);

/**
*  @brief 获取人脸屏蔽区域的规则
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [OUT] face_rule_area 人脸屏蔽区域
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzLPRClient_GetFaceShieldArea(VzLPRClientHandle handle, TH_FaceShieldArea* face_shield_area);

/**
*  @brief 设置人脸屏蔽区域的规则
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] face_rule_area 人脸屏蔽区域
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzLPRClient_SetFaceShieldArea(VzLPRClientHandle handle, TH_FaceShieldArea* face_shield_area);

/**
*  @brief 设置人脸IRCUT的状态
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] ircut 视频参数
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzLPRClient_SetFaceIrcutParams(VzLPRClientHandle handle, int ircut);

/**
*  @brief 获取人脸IRCUT的状态
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] ircut 视频参数
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzLPRClient_GetFaceIrcutParams(VzLPRClientHandle handle, int* ircut);

/**
*  @brief 区域流动人员统计数据清空
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzLPRClient_FaceResetCounter(VzLPRClientHandle handle);

/**
*  @brief 设置是否绘制识别框
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] bDraw  按位表示： 0x01: 人脸 0x02 背脸 0x04: 人形
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzLPRClient_FaceSetIsDrawTargetRect(VzLPRClientHandle handle, int bDraw);

/**
*  @brief 查询图片列表
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzLPRClient_FaceQueryPicList(VzLPRClientHandle handle, int type, int sub_type, const char* start_time, const char* end_time, int page_num, int page_size, VZ_PIC_LIST_RESULT *picture_result);


/**
*  @brief 结构化查询
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzLPRClient_FaceQueryReccordData(VzLPRClientHandle handle, int data_type, int page_num, int page_size, const char* start_time, const char* end_time, VZ_FACE_QUERY_CONDITION *condition, VZ_FACE_RECORD_RESULT *record_result);


/**
*  @brief 区域计数结果
*  @param [OUT] count_result区域计数结果
*  @param [OUT] pUserData 用户自定义数据
*/
typedef void (__STDCALL *VZLPRC_FACE_AREA_COUNT_CALLBACK)(VzLPRClientHandle handle, TH_AreaCountResult* count_result, void* pUserData);

/**
*  @brief 设置区域计数结果回调
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] func 回调接口
*  @param [IN] pUserData 用户自定义数据
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzLPRClient_SetFaceAreaCountCallBack(VzLPRClientHandle handle, VZLPRC_FACE_AREA_COUNT_CALLBACK func, void* pUserData);

/**
*  @brief 获取当前区域人数
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [OUT] people_num 人数结果
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzLPRClient_FaceGetAreaPeopleNum(VzLPRClientHandle handle, int* people_num);

/**
*  @brief 安装向导推送结果
*  @param [OUT] count_result区域计数结果
*  @param [OUT] pUserData 用户自定义数据
*/
typedef void (__STDCALL *VZLPRC_FACE_GUIDE_DATA_PUSH_CALLBACK)(VzLPRClientHandle handle, TH_FaceGuideData* guide_data, void* pUserData);

/**
*  @brief 设置安装向导推送回调
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] func 回调接口
*  @param [IN] pUserData 用户自定义数据
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzLPRClient_SetGuideDataCallBack(VzLPRClientHandle handle, VZLPRC_FACE_GUIDE_DATA_PUSH_CALLBACK func, void* pUserData);

/**
*  @brief 获取当前绊线统计人数
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [OUT] area1_num 区域1人数
*  @param [OUT] area2_num 区域2人数
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzLPRClient_FaceGetCrossingLineResult(VzLPRClientHandle handle, int* area1_num, int* area2_num);

/**
*  @brief 设置中心服务器参数
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] pParam 中心服务器参数
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzLPRClient_FaceSetCenterServer(VzClientHandle handle, const VZ_CENTER_SERVER_INFO *pParam);

/**
*  @brief 获取中心服务器参数
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [OUT] pParam 中心服务器参数
*  @
*/
VZ_API int __STDCALL VzLPRClient_FaceGetCenterServer(VzClientHandle handle, VZ_CENTER_SERVER_INFO *pParam);

/**
*  @brief 设置到中心服务器的设备注册信息
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] pParam 设备注册信息
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzLPRClient_FaceSetCenterServerDevReg(VzClientHandle handle, const VZ_CENTER_SERVER_DEV_REG *pParam);

/**
*  @brief 获取到中心服务器的设备注册信息
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [OUT] pParam 设备注册信息
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzLPRClient_FaceGetCenterServerDevReg(VzClientHandle handle,VZ_CENTER_SERVER_DEV_REG *pParam);

/**
*  @brief 设置到中心服务器的报警（识别结果）推送参数
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] pParam 推送参数
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzLPRClient_FaceSetCenterServerAlarm(VzClientHandle handle, const VZ_CENTER_SERVER_ALARM_PARAM *pParam);

/**
*  @brief 获取到中心服务器的报警（识别结果）推送参数
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [OUT] pParam 推送参数
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzLPRClient_FaceGetCenterServerAlarm(VzClientHandle handle,VZ_CENTER_SERVER_ALARM_PARAM *pParam);
/**
*  @brief 设置人脸抓拍（检测）参数
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] pSnapParam 相机的抓拍参数
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzLPRClient_FaceSetSnapshotParam(VzClientHandle handle,const VZ_FACE_SNAPSHOT_PARAM *pParam);

/**
*  @brief 获取人脸抓拍（检测）参数
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [OUT] pSnapParam 相机的抓拍参数
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzLPRClient_FaceGetSnapshotParam(VzClientHandle handle, VZ_FACE_SNAPSHOT_PARAM *pParam);

/**
*  @brief 去重人脸结构化记录查询
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzLPRClient_FaceQueryDelrepData(VzLPRClientHandle handle, int data_type, int page_num, int page_size, const char* start_time, const char* end_time, VZ_FACE_QUERY_CONDITION *condition, VZ_FACE_RECORD_RESULT *record_result);

/**
*  @brief 清理人脸结构化数据
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzLPRClient_FaceReleaseDelrepData(VzLPRClientHandle handle, VZ_FACE_RECORD_RESULT *record_result);


/**
*  @brief 人脸抓拍框回调规则结果
*  @param [OUT] pTargets区域计数结果
*  @param [OUT] pUserData 用户自定义数据
*/
typedef void (__STDCALL *VZLPRC_FACE_TARGET_INFO_CALLBACK)(VzLPRClientHandle handle, VzTargetsInfo *pTargets, void* pUserData);

/**
*  @brief 设置人脸抓拍框规则回调
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] func 回调接口
*  @param [IN] pUserData 用户自定义数据
*  @param [IN] draw_rect 设置成0代表不绘制人脸框，由客户自己绘制
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzLPRClient_SetFaceTargetInfoCallBack(VzLPRClientHandle handle, VZLPRC_FACE_TARGET_INFO_CALLBACK func, void* pUserData, int draw_rect);

/**
*  @brief 上传logo
*  @param  [IN]handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN]file_path 导出文件路径名
*  @return 0表示成功，-1表示失败
*  @ingroup group_device
*/
VZ_API int __STDCALL VzLPRClient_FaceUploadLogo(VzLPRClientHandle handle, const char* file_path);

/**
*  @brief 上传背景图
*  @param  [IN]handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN]import_ability 导出参数配置
*  @param  [IN]file_path 导出文件路径名
*  @return 0表示成功，-1表示失败
*  @ingroup group_device
*/
VZ_API int __STDCALL VzLPRClient_FaceUploadBg(VzLPRClientHandle handle, const char* file_path);

/**
*  @brief 上传Css
*  @param  [IN]handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN]import_ability 导出参数配置
*  @param  [IN]file_path 导出文件路径名
*  @return 0表示成功，-1表示失败
*  @ingroup group_device
*/
VZ_API int __STDCALL VzLPRClient_FaceUploadCss(VzLPRClientHandle handle, const char* file_path);


//*******************************************************************************************
//   begin 人脸门禁相关

/**
*  @brief 人脸抓拍结果扩展
*  @param [OUT] face_result 人脸结果
*  @param [OUT] pUserData 用户自定义数据
*/
typedef void (__STDCALL *VZ_FACE_GATE_RECOG_INFO_CALLBACK)(VzClientHandle handle, FaceRecoInfo* faceRecoInfo, void* pUserData);

/**
*  @brief 设置人脸门禁结果回调
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] func 回调接口
*  @param [IN] pUserData 用户自定义数据
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_SetFaceGateRecogInfoCallBack(VzClientHandle handle, VZ_FACE_GATE_RECOG_INFO_CALLBACK func, void* pUserData);


/**
*  @brief 人脸查询结果
*  @param [OUT] face_result 人脸结果
*  @param [OUT] pUserData 用户自定义数据
*/
typedef void (__STDCALL *VZ_FACE_GATE_QUERY_INFO_CALLBACK)(VzClientHandle handle, QueryFaceInfoEx* faceInfo, void* pUserData);

/**
*  @brief 设置人脸门禁结果回调
*  @param [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param [IN] func 回调接口
*  @param [IN] pUserData 用户自定义数据
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_SetFaceGateQueryInfoCallBack(VzClientHandle handle, VZ_FACE_GATE_QUERY_INFO_CALLBACK func, void* pUserData);

/**
/**
*  @brief 通过人员角色查询
*  @param  [IN] cam 要查看的相机句柄
*  @param  [IN] role 要查询的人员角色 0：普通人员 1：白名单人员 2：黑名单人员。 -1：所有人员。
*  @param  [IN] page_no      要查询的页码
*  @param  [IN] page_size    每页的数据条数，用于数据分页 最大值100
*  @param  [IN] featureFlags 特征查询标记，是否查询特征信息，0表示需要，非0表示不需要
*  @param  [IN] imgFlags 是否查询人脸图像
*  @return 返回值为0表示成功，返回负数表示失败
*/
VZ_API int __STDCALL VzClient_QueryByRole(VzClientHandle handle, int role, int page_no, int page_size, char featureFlags, char imgFlags);


/**
*  @brief 删除人脸门禁用户数据
*  @param [IN] handle 由VzClient_Open函数获得的句柄
*  @param [IN] per_id 人脸数据id 
*  @param [IN] role_type 0,删除指定 ID 人员 1删除白名单人员 2删除黑名单人员 3删除普通人员 4删除所有人员
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_FaceGateUserDelete(VzClientHandle handle, const char *per_id, int role_type);

/**
*  @brief 获取人脸门禁已录入人员的个数
*  @param [IN] handle 由VzClient_Open函数获得的句柄
*  @param [OUT] total_count 人员总数 
*  @return 返回值为0表示成功，返回其他值表示失败。
*/
VZ_API int __STDCALL VzClient_FaceGateUserCount(VzClientHandle handle, int *total_count);

/**
*  @brief 查询人脸门禁的识别记录
*  @param [IN] handle 由VzClient_Open函数获得的句柄
*  @param [IN] start_time 起始时间
*  @param [IN] end_time   结束时间
*  @param [OUT] start_seq  起始ID
*  @param [OUT] end_seq    结束ID
*/
VZ_API int __STDCALL VzClient_FaceGateQueryRecordByTime(VzClientHandle handle, const char *start_time, const char* end_time, int *start_seq, int *end_seq);

/**
*  @brief 根据seq获取记录
*  @param [IN] handle 由VzClient_Open函数获得的句柄
*  @param [IN] seq  起始ID
*  @param [OUT] faceRecoInfo  人脸信息
*/
VZ_API int __STDCALL VzClient_FaceGateGetRecordBySeq(VzClientHandle handle, int seq, FaceRecoInfo* faceRecoInfo);

// end   人脸门禁相关
//*******************************************************************************************

#ifdef  LINUX
#ifdef __cplusplus
}
#endif
#endif


#endif
