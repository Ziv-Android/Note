//���ڽ���VZ���ǻۺ��ӵ�Ӧ�ó���ӿ�
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
*  @brief ��ȡ�������ӵ�����б�
*  @param [IN] handle ��VzClient_Open������õľ��
*  @param [OUT] cam_group �����Ϣ�б�
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_GetCamGroupParam(VzClientHandle handle, VZ_BOX_CAM_GROUP* cam_group);

/**
*  @brief ��ȡ�������ӵ�����б� ��չ������Ϣ 
*  @param [IN] handle ��VzClient_Open������õľ��
*  @param [OUT] cam_group �����Ϣ�б�
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_GetCamGroupParamEx(VzClientHandle handle, char *response, int max_len);

/**
*  @brief ������
*  @param [IN] handle ��VzClient_Open������õľ��
*  @param [IN] pInfo ���ͨ������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_BoxAddCam(VzClientHandle handle, const VZ_BOX_CAM_INFO *pInfo);

/**
*  @brief ����ͨ���ű༭���������޸���IP���ԣ�����Ƴ����з��飬��Ҫ�������÷�����Ϣ
*  @param [IN] handle ��VzClient_Open������õľ��
*  @param [IN] nChnId ��VzClient_GetCamGroupParam������ȡ����Ϣ��VZ_BOX_CAM_GROUP::VZ_BOX_CAM_ITEM::chn_id
*  @param [IN] pInfo ���ͨ������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_BoxSetCam(VzClientHandle handle, int nChnId, const VZ_BOX_CAM_INFO *pInfo);

/**
*  @brief ����IP��ַ����ɾ�������
*  @param [IN] handle ��VzClient_Open������õľ��
*  @param [IN] ip ��ɾ�������IP��ַ����
*  @param [IN] nNum ��ɾ�������IP��ַ���鳤��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_BoxRemoveCams(VzClientHandle handle, const char * const ip[], int nNum);

/**
*  @brief ��ƽ̨�������Ա�
*  @param [IN] handle ��VzClient_Open������õľ��
*  @param [IN] app_id ������ID����
*  @param [IN] app_count ���������
*  @param [IN] image_data ����ͼƬ����(jpg��ʽ�ļ�����)
*  @param [IN] image_len  ͼƬ���ݵĳ���
*  @param [IN] max_user_num  �����󷵻صĽ������
*  @param [IN] detail_type  �����󷵻صĽ������(0��������ͼƬ���û���ϸ��Ϣ 1������ͼƬ���û���ϸ��Ϣ)
*  @param [OUT] face_result �����ԱȽ��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_CloudFaceRecognition(VzClientHandle handle, int* app_id, int app_count, char *image_data, int image_len, int max_user_num, int detail_type, VZ_FACE_USER_RESULT *face_result);


/**
*  @brief ���������ԱȽ�����ɵ�ͼƬ����(�����˽ӿ�����������ڴ�й¶)
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_ReleaseFaceRecognitionData(VzLPRClientHandle handle, VZ_FACE_USER_RESULT *face_result);

/**
*  @brief ��ƽ̨������ʶ��
*  @param [IN] handle ��VzClient_Open������õľ��
*  @param [IN] app_id ���ƿ�ID
*  @param [IN] image_data ����ͼƬ����(jpg��ʽ�ļ�����)
*  @param [IN] image_len  ͼƬ���ݵĳ���
*  @param [OUT] plate_result ����ʶ����
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_CloudPlateRecognition(VzClientHandle handle, int app_id, char *image_data, int image_len, TH_PlateResult *plate_result);


/**
*  @brief ����ʶ������
*  @param [IN] handle ��VzClient_Open������õľ��
*  @param [IN] item ��������Ϣ
*  @param [IN] oper ��������(1�������׿� 2��ɾ���׿� 3���޸ĵ׿�)
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ� ��Ϊ��������ʱ,����ֵΪ��id > 0
*/
VZ_API int __STDCALL VzClient_FaceRecgLibOperate(VzClientHandle handle, VZ_FACE_LIB_ITEM *item, int oper);


/**
*  @brief ����������
*  @param [IN] handle ��VzClient_Open������õľ��
*  @param [OUT] lib_result ��������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_SearchFaceRecgLib(VzClientHandle handle, VZ_FACE_LIB_RESULT *lib_result);

/**
*  @brief ���������Ϣ������ʶ���
*  @param [IN] handle ��VzClient_Open������õľ��
*  @param [IN] user_info �û�����
*  @return ����ֵ���ڵ���0��ʾ�ɹ�������0ʱ��Ϊ�������id�� ��������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_FaceRecgUserAdd(VzClientHandle handle, VZ_FACE_USER_RESULT *user_info);

/**
*  @brief ���������Ϣ������ʶ����첽�ӿڣ�֧���ڴ浼��
*  @param [IN] handle ��VzClient_Open������õľ��
*  @param [IN] user_info �û�����
*  @param [OUT] err_msg ������Ϣ
*  @param [IN]  max_len  err_msg��󳤶�
*  @param [OUT] delay �ӳ�ʱ�䡣 �����ֵ����1ʱ����ǰ�豸��æ�����Ҵ�����Ϣ����ʧ�ܣ���Ҫ�ӳ�delay(����)���ش�
*  @return ����ֵ���ڵ���0��ʾ�ɹ�������0ʱ��Ϊ�������id�� ��������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_FaceRecgUserAddAsync(VzClientHandle handle, VZ_FACE_USER_RESULT *user_info, char *err_msg, int max_len, int* delay);

/**
*  @brief �༭������Ϣ����Ҫ����pic_index��
*  @param [IN] handle ��VzClient_Open������õľ��
*  @param [IN] user_info �û�����
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_FaceRecgUserEdit(VzClientHandle handle, VZ_FACE_USER_RESULT *user_info);

/**
*  @brief ɾ����������
*  @param [IN] handle ��VzClient_Open������õľ��
*  @param [IN] pic_index ��������id
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_FaceRecgUserDelete(VzClientHandle handle, int pic_index);

/**
*  @brief ����UserIdɾ����������
*  @param [IN] handle ��VzClient_Open������õľ��
*  @param [IN] user_id �����û�id
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_FaceRecgUserDeleteByUserId(VzClientHandle handle, const char* user_id);

/**
*  @brief ����UserId��ȡ������Ϣ
*  @param [IN] handle ��VzClient_Open������õľ��
*  @param [IN] user_info ������Ϣ
*  @param [IN] user_id �����û�id
*  @return ����ֵ���ڵ���0��ʾ�ɹ�������0ʱ��Ϊ�������id�� ��������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_GetFaceInfoByUserId(VzClientHandle handle, VZ_FACE_USER_ITEM *user_item, const char* user_id);

/**
*  @brief �༭������Ϣ����Ҫ����user_id��
*  @param [IN] handle ��VzClient_Open������õľ��
*  @param [IN] user_info �û�����
*  @param [IN] user_id �����û�id
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_FaceRecgUserEditByUserId(VzClientHandle handle, VZ_FACE_USER_RESULT *user_info, const char* user_id);

/**
*  @brief ����������ݵ�������
*  @param [IN] handle ��VzClient_Open������õľ��
*  @param [IN] user_item ��������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_FaceRecgAddUserToArray(VzClientHandle handle, VZ_FACE_USER_ITEM *user_item);

/**
*  @brief ��������е�����
*  @param [IN] handle ��VzClient_Open������õľ��
*  @param [IN] user_item ��������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_FaceRecgClearUserArray(VzClientHandle handle);

/**
*  @brief ִ����������
*  @param [IN] handle ��VzClient_Open������õľ��
*  @param [IN] user_item ��������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_FaceRecgBatchImportUserFromArray(VzClientHandle handle);

/**
*  @brief ��ȡ������
*  @param [IN] handle ��VzClient_Open������õľ��
*  @param [OUT] success_count �ɹ��ĸ���
*  @param [OUT] failed_count  ʧ�ܵĸ���
*  @param [OUT] total_count   ����ĸ���
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_FaceRecgGetImportResult(VzClientHandle handle, int *import_count, int *total_count);


/**
*  @brief ��ȡ����Ĵ�����Ϣ
*  @param [IN] handle ��VzClient_Open������õľ��
*  @param [OUT] err_msg �ɹ��ĸ���
*  @param [IN]  max_msg_len  ʧ�ܵĸ���
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_FaceRecgGetImportErrMsg(VzClientHandle handle, char *err_msg, int max_len);

/**
*  @brief ��������ʶ����е�����
*  @param [IN] handle ��VzClient_Open������õľ��
*  @param [IN] condition ��ѯ����
*  @param [IN] db_id �������id
*  @param [OUT] user_info ��ѯ���
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_SearchFaceRecgUser(VzClientHandle handle, VZ_FACE_LIB_SEARCH_CONDITION *condition, int db_id, VZ_FACE_USER_RESULT *user_info);

/**
*  @brief ����·����ȡͼƬ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] img_path �洢����������ͼƬ·��
*  @param  [IN] pdata  �洢ͼƬ���ڴ�
*  @param  [IN][OUT] size Ϊ���봫��ֵ������ΪͼƬ�ڴ�Ĵ�С�����ص��ǻ�ȡ��jpgͼƬ�ڴ�Ĵ�С
*  @return ����ֵΪ0��ʾ�ɹ�������-1��ʾʧ��
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_LoadFaceImageByPath(VzClientHandle handle, const char* img_path, void *pdata, int* size);

/**
*  @brief ��ȡ���ץ�ĵ�һ��������ߵĽ��
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] near_time  ʱ�䷶Χ
*  @param  [OUT] face_result �������
*  @return ����ֵΪ0��ʾ�ɹ�������-1��ʾʧ��
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_GetBestFaceResult(VzClientHandle handle, int near_time, TH_FaceResult* face_result);


/**
*  @brief ����������ȡ������ߵ�ͼƬ����(�����˽ӿ�����������ڴ�й¶)
*  @param [IN] face_result ��VzClient_GetBestFaceResult���صĽ��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_ReleaseBestFaceResult(TH_FaceResult *face_result);

/**
*  @brief ��ȡϵͳ��ǰ����������ȡ���ص�״̬
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] feature_extract_status ����������ȡ״̬�� 0��ʾδ����������ȡ��Ĭ�ϣ���1��ʾ����������ȡ
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_GetFaceFeatureExtractStatus(VzClientHandle handle, int *feature_extract_status);

/**
*  @brief ����ϵͳ����������ȡ����
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] feature_extract ����������ȡ״̬�� 0��ʾ������������ȡ��Ĭ�ϣ���1��ʾ����������ȡ
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_SetFaceFeatureExtractStatus(VzClientHandle handle, int feature_extract);

/**
*  @brief ��ȡϵͳ��ǰ����������ȡ���ص�״̬
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] feature_extract_status ����������ȡ״̬�� 0��ʾδ����������ȡ��Ĭ�ϣ���1��ʾ����������ȡ
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_BoxGetSystemModuleSwitch(VzClientHandle handle, 
													   VZ_BOX_SYS_MOD_SWITCH eSwitch,
													   unsigned char *ucEnable);

/**
*  @brief ����ϵͳ����������ȡ����
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] feature_extract ����������ȡ״̬�� 0��ʾ������������ȡ��Ĭ�ϣ���1��ʾ����������ȡ
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_BoxSetSystemModuleSwitch(VzClientHandle handle, 
													VZ_BOX_SYS_MOD_SWITCH eSwitch,
													unsigned char ucEnable);

/**
*  @brief ��ȡϵͳ������������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] glob_libs ����������
*  @param [OUT] count     ���������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_GetGlobFacialCfg(VzClientHandle handle, int* glob_libs, int* enable, int* count);

/**
*  @brief ����ϵͳ������������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] glob_libs ����������
*  @param [IN] count     ���������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_SetGlobFacialCfg(VzClientHandle handle, int* glob_libs, int enable, int count);

/**
*  @brief  ͨ���ûص�������ñ�������
*  @param  [IN] handle		��VzLPRClient_Open������õľ��
*  @param  [IN] playhandle  ���ž��(VzClient_SetRealDataCallBack�������صľ��)
*  @param  [IN] pUserData	�ص�������������
*  @param  [IN] eDataType	�������ͣ����ö��VZ_LPRC_DATA_TYPE
*  @param  [IN] pData		����֡��Ϣ������ṹ�嶨��VZ_LPRC_DATA_INFO
*  @ingroup group_callback
*/
typedef void (__STDCALL *VZ_REAL_DATA_CALLBACK)(VzClientHandle handle, int channel, int playhandle, void *pUserData,
													 VZ_LPRC_DATA_TYPE eDataType, const VZ_LPRC_DATA_INFO *pData);
#ifdef WIN32
/**
*  @brief ��ȡʵʱ��������
*  @param  [IN] handle		��VzLPRClient_Open������õľ��
*  @param  [IN] channel     ͨ����
*  @param  [IN] stream_id   ����id(0������, 1������)
*  @param  [IN] func		�ص�����
*  @param  [IN] pUserData	�ص������е�������
*  @return ���ŵľ����-1��ʾʧ��
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_SetChannelRealDataCallBack(VzLPRClientHandle handle,
												  int channel, 
												  int stream_id,
												  VZ_REAL_DATA_CALLBACK func, 
												  void *pUserData);
#endif

/**
*  @brief �豸˫���ڵ�����������á�
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] netcfg �μ�VZ_LPRC_NETCFG_EX�ṹ�嶨��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ��
*/
VZ_API int __STDCALL VzClient_SetSecondPortNetConfig(VzClientHandle handle, const VZ_LPRC_NETCFG_EX* netcfg);

/**
*  @brief ��ȡ˫���ڵ�����������á�
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] netcfg �μ�VZ_LPRC_NETCFG_EX�ṹ�嶨��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ��
*/
VZ_API int __STDCALL VzClient_GetSecondPortNetConfig(VzClientHandle handle, VZ_LPRC_NETCFG_EX* netcfg);
/**
*  @brief ����http���ͻ�������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] basecfg ���ͻ������ò���
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ��
*/
VZ_API int __STDCALL VzClient_SetHttpPushBaseConfig(VzClientHandle handle, VZ_HTTP_PUSH_BASE_CFG* basecfg);

/**
*  @brief ��ȡhttp���ͻ�������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] basecfg ���ͻ������ò���
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ��
*/
VZ_API int __STDCALL VzClient_GetHttpPushBaseConfig(VzClientHandle handle, VZ_HTTP_PUSH_BASE_CFG* basecfg);

/**
*  @brief ����http���ͽ������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] push_param ���ͽ������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ��
*/
VZ_API int __STDCALL VzClient_SetBoxHttpPushParam(VzClientHandle handle, VZ_BOX_HTTP_PUSH_PARAM* push_param);

/**
*  @brief ��ȡhttp���ͽ������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] push_param �������ò���
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ��
*/
VZ_API int __STDCALL VzClient_GetBoxHttpPushParam(VzClientHandle handle, VZ_BOX_HTTP_PUSH_PARAM* push_param);


/**
*  @brief ��������ͬ�����Ž��豸��
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] db_name �����ײ�
*  @param  [IN] db_id �����׿�ID
*  @param  [IN] cam_items �Ž��豸��Ϣ(����ip,�˿�,�û���������)
*  @param  [IN] cam_count �Ž��豸������
*  @return ����ֵΪ0��ʾ�ɹ�������-1��ʾʧ��
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_UpdateFaceLibToGateCam(VzClientHandle handle, const char* db_name, int db_id, VZ_BOX_CAM_INFO *cam_items, int cam_count);

/**
*  @brief ��ȡ�����״̬
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [OUT] state �����״̬(1���ڵ���,0�������)
*  @param  [OUT] msg ������Ϣ
*  @param  [IN/OUT] msg_len ���ݳ���
*  @return ����ֵΪ0��ʾ�ɹ�������-1��ʾʧ��
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_GetUpdateFaceGateLibState(VzClientHandle handle, int *state, char *msg, int *msg_len);

/**
*  @brief ��ȡ֧�ֵ�����豸�б�
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [OUT] cam_items �Ž��豸��Ϣ(����ip,�˿�,�û���������)
*  @param  [IN/OUT] cam_count �Ž��豸������
*  @return ����ֵΪ0��ʾ�ɹ�������-1��ʾʧ��
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_GetSupportFaceLibCam(VzClientHandle handle, VZ_BOX_CAM_INFO *cam_items, int *cam_count);

#ifdef  LINUX
#ifdef __cplusplus
}
#endif
#endif


#endif
