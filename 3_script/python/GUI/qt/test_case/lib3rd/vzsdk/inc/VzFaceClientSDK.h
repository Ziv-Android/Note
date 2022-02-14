//���ڽ���VZ������ץ�������Ӧ�ó���ӿ�
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
*  @brief ����ץ�Ľ��
*  @param [OUT] face_result �������
*  @param [OUT] pUserData �û��Զ�������
*/
typedef void (__STDCALL *VZLPRC_FACE_RESULT_CALLBACK)(VzLPRClientHandle handle, TH_FaceResult* face_result, void* pUserData);

/**
*  @brief ����ץ�Ľ����չ
*  @param [OUT] face_result �������
*  @param [OUT] pUserData �û��Զ�������
*/
typedef void (__STDCALL *VZLPRC_FACE_RESULT_EX_CALLBACK)(VzLPRClientHandle handle, TH_FaceResultEx* face_result, void* pUserData);

/**
*  @brief ��������ץ�Ľ���ص�
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] func �ص��ӿ�
*  @param [IN] pUserData �û��Զ�������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzLPRClient_SetFaceResultCallBack(VzLPRClientHandle handle, VZLPRC_FACE_RESULT_CALLBACK func, void* pUserData);

/**
*  @brief ��������ץ�Ľ���ص�����չ)
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] func �ص��ӿ�
*  @param [IN] pUserData �û��Զ�������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzLPRClient_SetFaceResultExCallBack(VzLPRClientHandle handle, VZLPRC_FACE_RESULT_EX_CALLBACK func, void* pUserData);


/**
*  @brief ����ͳ�ƽ��
*  @param [OUT] area1_num ����һ����
*  @param [OUT] area2_num ���������
*  @param [OUT] pUserData �û��Զ�������
*/
typedef void (__STDCALL *VZLPRC_FACE_COUNT_STAT_CALLBACK)(VzLPRClientHandle handle, int area1_num, int area2_num, void* pUserData);

/**
*  @brief ��������ͳ�ƽ���ص�
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] func �ص��ӿ�
*  @param [IN] pUserData �û��Զ�������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzLPRClient_SetFaceCountStatCallBack(VzLPRClientHandle handle, VZLPRC_FACE_COUNT_STAT_CALLBACK func, void* pUserData);


/**
*  @brief ��ȡ����ʶ������Ĺ���
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] face_rule_area ����ʶ�����
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzLPRClient_GetFaceRuleArea(VzLPRClientHandle handle, TH_FaceRuleArea* face_rule_area);

/**
*  @brief ��������ʶ������Ĺ���
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] face_rule_area ����ʶ�����
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzLPRClient_SetFaceRuleArea(VzLPRClientHandle handle, TH_FaceRuleArea* face_rule_area);

/**
*  @brief ��ȡ������������Ĺ���
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] face_rule_area ������������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzLPRClient_GetFaceShieldArea(VzLPRClientHandle handle, TH_FaceShieldArea* face_shield_area);

/**
*  @brief ����������������Ĺ���
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] face_rule_area ������������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzLPRClient_SetFaceShieldArea(VzLPRClientHandle handle, TH_FaceShieldArea* face_shield_area);

/**
*  @brief ��������IRCUT��״̬
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] ircut ��Ƶ����
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzLPRClient_SetFaceIrcutParams(VzLPRClientHandle handle, int ircut);

/**
*  @brief ��ȡ����IRCUT��״̬
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] ircut ��Ƶ����
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzLPRClient_GetFaceIrcutParams(VzLPRClientHandle handle, int* ircut);

/**
*  @brief ����������Աͳ���������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzLPRClient_FaceResetCounter(VzLPRClientHandle handle);

/**
*  @brief �����Ƿ����ʶ���
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] bDraw  ��λ��ʾ�� 0x01: ���� 0x02 ���� 0x04: ����
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzLPRClient_FaceSetIsDrawTargetRect(VzLPRClientHandle handle, int bDraw);

/**
*  @brief ��ѯͼƬ�б�
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzLPRClient_FaceQueryPicList(VzLPRClientHandle handle, int type, int sub_type, const char* start_time, const char* end_time, int page_num, int page_size, VZ_PIC_LIST_RESULT *picture_result);


/**
*  @brief �ṹ����ѯ
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzLPRClient_FaceQueryReccordData(VzLPRClientHandle handle, int data_type, int page_num, int page_size, const char* start_time, const char* end_time, VZ_FACE_QUERY_CONDITION *condition, VZ_FACE_RECORD_RESULT *record_result);


/**
*  @brief ����������
*  @param [OUT] count_result����������
*  @param [OUT] pUserData �û��Զ�������
*/
typedef void (__STDCALL *VZLPRC_FACE_AREA_COUNT_CALLBACK)(VzLPRClientHandle handle, TH_AreaCountResult* count_result, void* pUserData);

/**
*  @brief ���������������ص�
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] func �ص��ӿ�
*  @param [IN] pUserData �û��Զ�������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzLPRClient_SetFaceAreaCountCallBack(VzLPRClientHandle handle, VZLPRC_FACE_AREA_COUNT_CALLBACK func, void* pUserData);

/**
*  @brief ��ȡ��ǰ��������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] people_num �������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzLPRClient_FaceGetAreaPeopleNum(VzLPRClientHandle handle, int* people_num);

/**
*  @brief ��װ�����ͽ��
*  @param [OUT] count_result����������
*  @param [OUT] pUserData �û��Զ�������
*/
typedef void (__STDCALL *VZLPRC_FACE_GUIDE_DATA_PUSH_CALLBACK)(VzLPRClientHandle handle, TH_FaceGuideData* guide_data, void* pUserData);

/**
*  @brief ���ð�װ�����ͻص�
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] func �ص��ӿ�
*  @param [IN] pUserData �û��Զ�������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzLPRClient_SetGuideDataCallBack(VzLPRClientHandle handle, VZLPRC_FACE_GUIDE_DATA_PUSH_CALLBACK func, void* pUserData);

/**
*  @brief ��ȡ��ǰ����ͳ������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] area1_num ����1����
*  @param [OUT] area2_num ����2����
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzLPRClient_FaceGetCrossingLineResult(VzLPRClientHandle handle, int* area1_num, int* area2_num);

/**
*  @brief �������ķ���������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pParam ���ķ���������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzLPRClient_FaceSetCenterServer(VzClientHandle handle, const VZ_CENTER_SERVER_INFO *pParam);

/**
*  @brief ��ȡ���ķ���������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] pParam ���ķ���������
*  @
*/
VZ_API int __STDCALL VzLPRClient_FaceGetCenterServer(VzClientHandle handle, VZ_CENTER_SERVER_INFO *pParam);

/**
*  @brief ���õ����ķ��������豸ע����Ϣ
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pParam �豸ע����Ϣ
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzLPRClient_FaceSetCenterServerDevReg(VzClientHandle handle, const VZ_CENTER_SERVER_DEV_REG *pParam);

/**
*  @brief ��ȡ�����ķ��������豸ע����Ϣ
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] pParam �豸ע����Ϣ
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzLPRClient_FaceGetCenterServerDevReg(VzClientHandle handle,VZ_CENTER_SERVER_DEV_REG *pParam);

/**
*  @brief ���õ����ķ������ı�����ʶ���������Ͳ���
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pParam ���Ͳ���
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzLPRClient_FaceSetCenterServerAlarm(VzClientHandle handle, const VZ_CENTER_SERVER_ALARM_PARAM *pParam);

/**
*  @brief ��ȡ�����ķ������ı�����ʶ���������Ͳ���
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] pParam ���Ͳ���
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzLPRClient_FaceGetCenterServerAlarm(VzClientHandle handle,VZ_CENTER_SERVER_ALARM_PARAM *pParam);
/**
*  @brief ��������ץ�ģ���⣩����
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pSnapParam �����ץ�Ĳ���
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzLPRClient_FaceSetSnapshotParam(VzClientHandle handle,const VZ_FACE_SNAPSHOT_PARAM *pParam);

/**
*  @brief ��ȡ����ץ�ģ���⣩����
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] pSnapParam �����ץ�Ĳ���
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzLPRClient_FaceGetSnapshotParam(VzClientHandle handle, VZ_FACE_SNAPSHOT_PARAM *pParam);

/**
*  @brief ȥ�������ṹ����¼��ѯ
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzLPRClient_FaceQueryDelrepData(VzLPRClientHandle handle, int data_type, int page_num, int page_size, const char* start_time, const char* end_time, VZ_FACE_QUERY_CONDITION *condition, VZ_FACE_RECORD_RESULT *record_result);

/**
*  @brief ���������ṹ������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzLPRClient_FaceReleaseDelrepData(VzLPRClientHandle handle, VZ_FACE_RECORD_RESULT *record_result);


/**
*  @brief ����ץ�Ŀ�ص�������
*  @param [OUT] pTargets����������
*  @param [OUT] pUserData �û��Զ�������
*/
typedef void (__STDCALL *VZLPRC_FACE_TARGET_INFO_CALLBACK)(VzLPRClientHandle handle, VzTargetsInfo *pTargets, void* pUserData);

/**
*  @brief ��������ץ�Ŀ����ص�
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] func �ص��ӿ�
*  @param [IN] pUserData �û��Զ�������
*  @param [IN] draw_rect ���ó�0���������������ɿͻ��Լ�����
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzLPRClient_SetFaceTargetInfoCallBack(VzLPRClientHandle handle, VZLPRC_FACE_TARGET_INFO_CALLBACK func, void* pUserData, int draw_rect);

/**
*  @brief �ϴ�logo
*  @param  [IN]handle ��VzLPRClient_Open������õľ��
*  @param  [IN]file_path �����ļ�·����
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_device
*/
VZ_API int __STDCALL VzLPRClient_FaceUploadLogo(VzLPRClientHandle handle, const char* file_path);

/**
*  @brief �ϴ�����ͼ
*  @param  [IN]handle ��VzLPRClient_Open������õľ��
*  @param  [IN]import_ability ������������
*  @param  [IN]file_path �����ļ�·����
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_device
*/
VZ_API int __STDCALL VzLPRClient_FaceUploadBg(VzLPRClientHandle handle, const char* file_path);

/**
*  @brief �ϴ�Css
*  @param  [IN]handle ��VzLPRClient_Open������õľ��
*  @param  [IN]import_ability ������������
*  @param  [IN]file_path �����ļ�·����
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_device
*/
VZ_API int __STDCALL VzLPRClient_FaceUploadCss(VzLPRClientHandle handle, const char* file_path);


//*******************************************************************************************
//   begin �����Ž����

/**
*  @brief ����ץ�Ľ����չ
*  @param [OUT] face_result �������
*  @param [OUT] pUserData �û��Զ�������
*/
typedef void (__STDCALL *VZ_FACE_GATE_RECOG_INFO_CALLBACK)(VzClientHandle handle, FaceRecoInfo* faceRecoInfo, void* pUserData);

/**
*  @brief ���������Ž�����ص�
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] func �ص��ӿ�
*  @param [IN] pUserData �û��Զ�������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_SetFaceGateRecogInfoCallBack(VzClientHandle handle, VZ_FACE_GATE_RECOG_INFO_CALLBACK func, void* pUserData);


/**
*  @brief ������ѯ���
*  @param [OUT] face_result �������
*  @param [OUT] pUserData �û��Զ�������
*/
typedef void (__STDCALL *VZ_FACE_GATE_QUERY_INFO_CALLBACK)(VzClientHandle handle, QueryFaceInfoEx* faceInfo, void* pUserData);

/**
*  @brief ���������Ž�����ص�
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] func �ص��ӿ�
*  @param [IN] pUserData �û��Զ�������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_SetFaceGateQueryInfoCallBack(VzClientHandle handle, VZ_FACE_GATE_QUERY_INFO_CALLBACK func, void* pUserData);

/**
/**
*  @brief ͨ����Ա��ɫ��ѯ
*  @param  [IN] cam Ҫ�鿴��������
*  @param  [IN] role Ҫ��ѯ����Ա��ɫ 0����ͨ��Ա 1����������Ա 2����������Ա�� -1��������Ա��
*  @param  [IN] page_no      Ҫ��ѯ��ҳ��
*  @param  [IN] page_size    ÿҳ�������������������ݷ�ҳ ���ֵ100
*  @param  [IN] featureFlags ������ѯ��ǣ��Ƿ��ѯ������Ϣ��0��ʾ��Ҫ����0��ʾ����Ҫ
*  @param  [IN] imgFlags �Ƿ��ѯ����ͼ��
*  @return ����ֵΪ0��ʾ�ɹ������ظ�����ʾʧ��
*/
VZ_API int __STDCALL VzClient_QueryByRole(VzClientHandle handle, int role, int page_no, int page_size, char featureFlags, char imgFlags);


/**
*  @brief ɾ�������Ž��û�����
*  @param [IN] handle ��VzClient_Open������õľ��
*  @param [IN] per_id ��������id 
*  @param [IN] role_type 0,ɾ��ָ�� ID ��Ա 1ɾ����������Ա 2ɾ����������Ա 3ɾ����ͨ��Ա 4ɾ��������Ա
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_FaceGateUserDelete(VzClientHandle handle, const char *per_id, int role_type);

/**
*  @brief ��ȡ�����Ž���¼����Ա�ĸ���
*  @param [IN] handle ��VzClient_Open������õľ��
*  @param [OUT] total_count ��Ա���� 
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_FaceGateUserCount(VzClientHandle handle, int *total_count);

/**
*  @brief ��ѯ�����Ž���ʶ���¼
*  @param [IN] handle ��VzClient_Open������õľ��
*  @param [IN] start_time ��ʼʱ��
*  @param [IN] end_time   ����ʱ��
*  @param [OUT] start_seq  ��ʼID
*  @param [OUT] end_seq    ����ID
*/
VZ_API int __STDCALL VzClient_FaceGateQueryRecordByTime(VzClientHandle handle, const char *start_time, const char* end_time, int *start_seq, int *end_seq);

/**
*  @brief ����seq��ȡ��¼
*  @param [IN] handle ��VzClient_Open������õľ��
*  @param [IN] seq  ��ʼID
*  @param [OUT] faceRecoInfo  ������Ϣ
*/
VZ_API int __STDCALL VzClient_FaceGateGetRecordBySeq(VzClientHandle handle, int seq, FaceRecoInfo* faceRecoInfo);

// end   �����Ž����
//*******************************************************************************************

#ifdef  LINUX
#ifdef __cplusplus
}
#endif
#endif


#endif
