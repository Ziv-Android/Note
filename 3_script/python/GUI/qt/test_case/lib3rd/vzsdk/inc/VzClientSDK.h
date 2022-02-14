//�豸ͨ�õ�Ӧ�ó���ӿ�
#ifndef _VZ_CLIENT_SDK_H_
#define _VZ_CLIENT_SDK_H_
#include <VzClientSDKDefine.h>

/**
* @defgroup group_global ȫ�ֲ�������
* @defgroup group_device �����豸��������
* @defgroup group_callback �ص�����
*/

//#ifdef  LINUX
//#ifdef __cplusplus
extern "C"
{
//#endif
//#endif

/**
*  @brief ȫ�ֳ�ʼ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note �����нӿڵ���֮ǰ����
*  @ingroup group_global
*/
VZ_API int __STDCALL VzClient_Setup();

/**
*  @brief ȫ���ͷ�
*  @note �ڳ������ʱ���ã��ͷ�SDK����Դ
*  @ingroup group_global
*/
VZ_API void __STDCALL VzClient_Cleanup();

/**
*  @brief ͨ���ûص���������ҵ����豸������Ϣ
*  @param  [IN] pStrDevName �豸����
*  @param  [IN] pStrIPAddr	�豸IP��ַ
*  @param  [IN] usPort1		�豸�˿ں�
*  @param  [IN] usPort2		Ԥ��
*  @param  [IN] SL          �豸���кŵ�λ�ֽ�
*  @param  [IN] SH			�豸���кŸ�λ�ֽ�
*  @param  [IN] pUserData	�ص�����������
*  @ingroup group_callback
*/
typedef void(__STDCALL *VZ_FIND_DEVICE_CALLBACK)(const char *pStrDevName, const char *pStrIPAddr, WORD usPort1, WORD usType, unsigned int SL, unsigned int SH, char* netmask, char* gateway, void *pUserData);

/**
*  @brief ��ʼ�����豸
*  @param  [IN] func �ҵ����豸ͨ���ûص���������
*  @param  [IN] pUserData �ص������е�������
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_global
*/
VZ_API int __STDCALL VZClient_StartFindDevice(VZ_FIND_DEVICE_CALLBACK func, void *pUserData);



/**
*  @brief ֹͣ�����豸
*  @ingroup group_global
*/
VZ_API void __STDCALL VZClient_StopFindDevice();

/**
*  @brief ͨ���ûص���������豸��һ��״̬��Ϣ
*  @param  [IN] handle		��VzClient_Open������õľ��
*  @param  [IN] pUserData	�ص�����������
*  @param  [IN] eNotify		ͨ����Ϣ��������
*  @param  [IN] pStrDetail	��ϸ�����ַ���
*  @ingroup group_callback
*/
typedef void (__STDCALL *VZ_COMMON_NOTIFY_CALLBACK)(VzClientHandle handle, void *pUserData,
													   VZ_COMMON_NOTIFY eNotify, const char *pStrDetail);

/**
*  @brief �����豸���ӷ��������صĻص�����
*  @param  [IN] func �豸���ӽ����״̬��ͨ���ûص���������
*  @param  [IN] pUserData �ص������е�������
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_global
*/
VZ_API int __STDCALL VZClient_SetCommonNotifyCallBack(VZ_COMMON_NOTIFY_CALLBACK func, void *pUserData);

/**
*  @brief ��һ���豸
*  @param  [IN] pStrIP �豸��IP��ַ
*  @param  [IN] wPort �豸�Ķ˿ں�
*  @param  [IN] pStrUserName �����豸�����û���
*  @param  [IN] pStrPassword �����豸��������
*  @return �����豸�Ĳ������������ʧ��ʱ������0
*  @ingroup group_device
*/
VZ_API VzClientHandle __STDCALL VzClient_Open(
  const char *pStrIP,
  WORD wPort,
  const char *pStrUserName,
  const char *pStrPassword);

/**
*  @brief ��һ���豸
*  @param  [IN] pStrIP �豸��IP��ַ
*  @param  [IN] wPort �豸�Ķ˿ں�
*  @param  [IN] pStrUserName �����豸�����û���
*  @param  [IN] pStrPassword �����豸��������
*  @param  [IN] wRtspPort ��ý��Ķ˿ں�,Ϊ0��ʾʹ��Ĭ��
*  @return �����豸�Ĳ������������ʧ��ʱ������0
*  @ingroup group_device
*/
VZ_API VzClientHandle __STDCALL VzClient_OpenEx(const char *pStrIP, WORD wPort, const char *pStrUserName, const char *pStrPassword,WORD wRtspPort);


/**
*  @brief �ر�һ���豸
*  @param  [IN] handle ��VzClient_Open������õľ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_Close(VzClientHandle handle);


/**
*  @brief ��ȡ����״̬
*  @param  [IN] handle ��VzClient_Open������õľ��
*  @param  [IN/OUT] pStatus �����ȡ״̬�ı�����ַ���������Ϊ 1�����ϣ�0δ����
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   �û��������ڵ��øú�����������ѯ�豸�Ƿ���ߣ��Լ����ߺ��Ƿ�ָ�����
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_IsConnected(VzClientHandle handle, BYTE *pStatus);

/**
*  @brief ����ʵʱ��Ƶ
*  @param  [IN] handle ��VzClient_Open������õľ��
*  @param  [IN] hWnd ���ڵľ��
*  @return ���ŵľ����-1��ʾʧ��
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_StartRealPlay(VzClientHandle handle, void *hWnd);

/**
*  @brief ����ʵʱ��Ƶ(֧��Ӳ������)
*  @param  [IN] handle ��VzClient_Open������õľ��
*  @param  [IN] hWnd ���ڵľ��
*  @param  [IN] type(0�������, 1Ӳ������)
*  @return ���ŵľ����-1��ʾʧ��
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_StartRealPlayEx(VzClientHandle handle, void *hWnd, int type);

/**
*  @brief ����ʵʱ��Ƶ
*  @param  [IN] handle ��VzClient_Open������õľ��
*  @param  [IN] hWnd ���ڵľ��
*  @param  [IN] channel ͨ����
*  @param  [IN] stream_id ����id(0������, 1������)
*  @return ���ŵľ����-1��ʾʧ��
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_StartRealPlayByChannel(VzClientHandle handle, void *hWnd, int channel, int stream_id);

/**
*  @brief ֹͣ����ָ���Ĳ��ž��
*  @param  [IN] nPlayHandle ���ŵľ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   ������ֹͣ�������Ժ���VzClient_StartRealPlay��VzClient_StartRealPlayFrameCallBack�Ĳ��ž��
*  @note   ֹͣ�����Ժ󣬸ò��ž����ʧЧ��
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_StopRealPlay(int nPlayHandle);

/**
*  @brief д���û�˽�����ݣ������ڶ��μ���
*  @param [IN] handle ��VzClient_Open������õľ��
*  @param [IN] pUserData �û�����
*  @param [IN] uSizeData �û����ݵĳ��ȣ����128�ֽ�
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ��
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_WriteUserData(VzClientHandle handle, const unsigned char *pUserData, unsigned uSizeData);

/**
*  @brief �����û�˽�����ݣ������ڶ��μ���
*  @param [IN] handle ��VzClient_Open������õľ��
*  @param [IN/OUT] pBuffer ���ڴ�Ŷ������û�����
*  @param [IN] uSizeBuf �û����ݻ���������С�ߴ磬��С��128�ֽ�
*  @return ����ֵΪʵ���û����ݵ��ֽ���������-1��ʾʧ��
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_ReadUserData(VzClientHandle handle, unsigned char *pBuffer, unsigned uSizeBuf);

/**
*  @brief �����豸���кţ������ڶ��μ���
*  @param [IN] handle ��VzClient_Open������õľ��
*  @param [IN/OUT] pSN ���ڴ�Ŷ������豸���кţ�������� VZ_DEV_SERIAL_NUM
*  @return ����ֵΪ0��ʾ�ɹ�������-1��ʾʧ��
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_GetSerialNumber(VzClientHandle handle, VZ_DEV_SERIAL_NUM *pSN);

/**
*  @brief ��ȡ�豸������ʱ��
*  @param [IN] handle ��VzClient_Open������õľ��
*  @param [IN/OUT] pDTInfo ���ڴ�Ż�ȡ�����豸����ʱ����Ϣ��������� VZ_DATE_TIME_INFO
*  @return ����ֵΪ0��ʾ�ɹ�������-1��ʾʧ��
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_GetDateTime(VzClientHandle handle, VZ_DATE_TIME_INFO *pDTInfo);

/**
*  @brief �����豸������ʱ��
*  @param [IN] handle ��VzClient_Open������õľ��
*  @param [IN] pDTInfo ��Ҫ���õ��豸����ʱ����Ϣ��������� VZ_DATE_TIME_INFO
*  @return ����ֵΪ0��ʾ�ɹ�������-1��ʾʧ��
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_SetDateTime(VzClientHandle handle, const VZ_DATE_TIME_INFO *pDTInfo);


/**
*  @brief ��ʼ����
*  @param  [IN] handle ��VzClient_Open������õľ��
*  @param [IN] file_path_name �����ļ�·��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_Update(VzClientHandle handle, char *file_path_name);


/**
*  @brief ��ȡ������״̬
*  @param  [IN] handle ��VzClient_Open������õľ��
*  @return ������״̬
*			0: ��δ������
*			1: �����ɹ�
*			2: �����������ϴ��У�����ȡ������
*			3: ����������дflash�У�ȡ������������
*		    4: �������⣬״̬δ֪
*		   -1: ����ʧ��
*			ʧ�ܻ�����������ʱ����ͨ��getlasterror�������������Ϣ��������UPDATE_ERROR��
*/
VZ_API int __STDCALL VzClient_GetUpdateState(VzClientHandle handle);


/**
*  @brief ȡ��������������״̬��2ʱ������ȡ������������ʱ������;
*  @param  [IN] handle ��VzClient_Open������õľ��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_StopUpdate(VzClientHandle handle);


/**
*  @brief ��ȡ�������ȣ��ϴ����Ϊ50���������Ϊ100����ǰ���50ֱ������100���м���Ȳ�����£��Ժ���
*  @param  [IN] handle ��VzClient_Open������õľ��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_GetUpdateProgress(VzClientHandle handle);

/**
* �����豸
*/
VZ_API int __STDCALL VzClient_RebootDVR( VzClientHandle handle );

/**
*  @brief ��һ���豸��֧�����������豸
*  @param  [IN] pStrIP �豸��IP��ַ
*  @param  [IN] wPort �豸�Ķ˿ں�
*  @param  [IN] pStrUserName �����豸�����û���
*  @param  [IN] pStrPassword �����豸��������
*  @param  [IN] wHttpPort ��ý��Ķ˿ں�,Ĭ��Ϊ80(���Ϊ0��ʾʹ��Ĭ�϶˿ڣ�
*  @param  [IN] network_type ��������(0������,1����-PDNS��ʽ)
*  @param  [IN] sn �豸���к�
*  @return �����豸�Ĳ������������ʧ��ʱ������0
*  @ingroup group_device
*/
VZ_API VzClientHandle __STDCALL VzClient_OpenV2(const char *pStrIP, WORD wPort, const char *pStrUserName, const char *pStrPassword,WORD wHttpPort, int network_type, char* sn);

/**
*  @brief �������ķ������¼���ʶ�����������ȣ�������Ϣ
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pAlarmParam  �¼���������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_SetCenterServerAlarm(VzLPRClientHandle handle, const VZ_CENTER_SERVER_ALARM_PARAM *pAlarmParam);

/**
*  @brief ��ȡ���ķ������¼���ʶ�����������ȣ�������Ϣ
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pAlarmParam  �¼���������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_GetCenterServerAlarm(VzLPRClientHandle handle, VZ_CENTER_SERVER_ALARM_PARAM * pAlarmParam);

/**
*  @brief ��ʽ��sd��
*  @param  [IN] handle ��VzClient_Open������õľ��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_SDFormat(VzClientHandle handle);


/**
*  @brief ���������·��
*  @param [IN] handle ��VzClient_Open������õľ��
*  @param [IN] font_path �����·��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_SetDrawFont(VzClientHandle handle, const char *font_path);

/**
*  @brief ��yuv�����л��Ƶ�����
*  @param [IN] nPlayHandle	��VzClient_StartRealPlay������õľ��
*  @param [IN] text   ��������
*  @param [IN] text_x ����x����Ϊǧ�ֱ� ��ΧΪ[0-1000]
*  @param [IN] text_y ����y����Ϊǧ�ֱ� ��ΧΪ[0-1000]
*  @param [IN] font_size �����С
*  @param [IN] r ��ɫ��ΧΪ[0-255]
*  @param [IN] g ��ɫ��ΧΪ[0-255]
*  @param [IN] b ��ɫ��ΧΪ[0-255]
*  @return �ɹ�����0��ʧ�ܷ���-1
*/
VZ_API int __STDCALL VzClient_DrawYUVText(int play_handle, const VzYUV420P *pFrame, const char *text, int text_x, int text_y, int font_size, int r, int g, int b);

/**
*  @brief ��yuv�����л��ƾ��ο�
*  @param [IN] x         ���ο�x����Ϊǧ�ֱ� ��ΧΪ[0-1000]
*  @param [IN] y         ���ο�y����Ϊǧ�ֱ� ��ΧΪ[0-1000]
*  @param [IN] width     ���ο���Ϊǧ�ֱ� ��ΧΪ[0-1000]
*  @param [IN] height    ���ο�߶�Ϊǧ�ֱ� ��ΧΪ[0-1000]
*  @param [IN] line_size ���ο��߿�
*  @param [IN] r ��ɫ��ΧΪ[0-255]
*  @param [IN] g ��ɫ��ΧΪ[0-255]
*  @param [IN] b ��ɫ��ΧΪ[0-255]
*  @return �ɹ�����0��ʧ�ܷ���-1
*/
VZ_API int __STDCALL VzClient_DrawYUVRect(int play_handle, const VzYUV420P *pFrame, int x, int y, int width, int height, int line_size, int r, int g, int b);

/**
*  @brief  ͨ���ûص��������ʵʱ����ͼ������
*  @param  [IN] nPlayHandle	��VzClient_StartRealPlay������õľ��
*  @param  [IN] pUserData	�ص�������������
*  @param  [IN] pFrame		ͼ��֡��Ϣ������ṹ�嶨��VzYUV420P
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_callback
*/
typedef void (__STDCALL *VZ_VIDEO_DECODE_DATA_CALLBACK)(long handle, void *pUserData,
													  const VzYUV420P *pFrame, unsigned uPtsSec, unsigned uPtsUSec);
/**
*  @brief ����ʵʱ����ͼ�����ݵĻص�����
*  @param  [IN] nPlayHandle		��VzClient_StartRealPlay������õľ��
*  @param  [IN] func		ʵʱͼ�����ݺ���
*  @param  [IN] pUserData	�ص������е�������
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_SetDecodeDataCallBack(int play_handle, VZ_VIDEO_DECODE_DATA_CALLBACK func, void *pUserData);

/**
*  @brief ͨ����ý���ַ������Ƶ��(֧��rtmp��rtsp��url)
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] hWnd ���ڵľ��(���Դ�null)
*  @param  [IN] pUserData	�ص������е�������
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @remark �����������ܻ�Ƚ������˽ӿڻ����������鿪�̵߳���
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_StartPlayUrlStream(VzClientHandle handle, const char* stream_url, void *hwnd);

/**
*  @brief ֹͣ��Ƶ������
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_StopPlayUrlStream(VzClientHandle handle);

/**
*  @brief ������ý���ַ������Ƶ���Ľ���ͼ�����ݵĻص�����
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] func		ʵʱͼ�����ݺ���
*  @param  [IN] pUserData	�ص������е�������
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_device
*/
VZ_API int __STDCALL VzClient_SetUrlStreamDecodeCallBack(VzClientHandle handle, VZ_VIDEO_DECODE_DATA_CALLBACK func, void *pUserData);


/**
*  @brief ��ʼ���ƶ˲���������������ƽ̨����Ƶ����������������Ƶ(ȫ�ֽӿڣ�������������ã�ֻ����һ��)
*  @param  [IN] pdns_addr ��������ַ
*  @param  [IN] username  �û���
*  @param  [IN] accesskey_id	 
*  @param  [IN] accesskey_secret 
*  @param  [IN] res       Ԥ������	
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_global
*/
VZ_API int __STDCALL VzClient_CloudSetup(const char *pdns_addr, const char *username, const char *accesskey_id, const char *accesskey_secret, const char *res);

/**
*  @brief ����ʵʱ��Ƶ(ͨ����ƽ̨��ʽ������Ƶ)
*  @param  [IN] handle ��VzClient_Open������õľ��
*  @param  [IN] hWnd ���ڵľ��
*  @return ���ŵľ����-1��ʾʧ��
*  @ingroup group_device
*/
VZ_API long __STDCALL VzClient_CloudStartRealPlay(VzClientHandle handle, void *hWnd);


/**
*  @brief ֹͣ����ʵʱ��Ƶ(ͨ����ƽ̨��ʽ������Ƶ)
*  @param  [IN] handle ��VzClient_Open������õľ��
*  @param  [IN] hWnd ���ڵľ��
*  @return ���ŵľ����-1��ʾʧ��
*  @ingroup group_device
*/
VZ_API long __STDCALL VzClient_CloudStopRealPlay(long nPlayHandle);

/**
*  @brief �ͷ���ƽ̨������(ȫ�ֽӿڣ������˳�ǰ���ã� ֻ����һ��)
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_global
*/
VZ_API int __STDCALL VzClient_CloudCleanup();


/**
*  @brief ʶ�����ص���չ
*  @param [OUT] iType�������COMMON_ALARM_RESULT_TYPE
*  @param [OUT] pResultInfo�����Ϣ JSON��ʽ
*  @param [OUT] len�����Ϣ����
*  @param [OUT] pUserData �û��Զ�������
*/
typedef void (__STDCALL *VZ_COMMON_RESULT_CALLBACK)(VzClientHandle handle, int type, const char *pResultInfo, int len, void *pUserData);

/**
*  @brief ����ͨ��ʶ�����ص�
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] func �ص��ӿ�
*  @param [IN] pUserData �û��Զ�������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_SetCommonResultCallBackEx(VzClientHandle handle, int type, VZ_COMMON_RESULT_CALLBACK func, void* pUserData);

/**
*  @brief ��ʼ¼����,¼�񱣴��mp4�ļ�
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] stream_type ������(0������, 1������)
*  @param [IN] timeout ��ʱʱ��(���룬���磺 5000)
*  @param [IN] file_path ¼���ļ������·��(����: d:/test.mp4)
*  @return ����ֵΪ0��ʾ�ɹ�������-1��ʾʧ��
*  @ingroup group_device
*/
VZ_API int __STDCALL VzLPRClient_StartRecord(VzClientHandle handle, int stream_type, int timeout, const char *file_path);

/**
*  @brief ֹͣ¼��
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @return ����ֵΪ0��ʾ�ɹ�������-1��ʾʧ��
*  @ingroup group_device
*/
VZ_API int __STDCALL VzLPRClient_StopRecord(VzClientHandle handle, int stream_type);

/**
*  @brief ��̨����
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] dir ����2:�����ƶ� 4:�����ƶ� 8:ֹͣ�����ƶ� 16:�����ƶ� 32:�����ƶ� 64:ֹͣ�����ƶ� 128:��ԭ
*  @param [IN] degree �Ƕ�[0~65535]
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_SetPtzCtrl(VzClientHandle handle, int dir, int degree);

/**
*  @brief ����/��������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] option������0:�������� 1:���� 1:����
*  @param [IN] zone_id��λid��0:��λ 1:�ҳ�λ
*  @param [IN] lock_id��id��0:��һ 1:����
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_API int __STDCALL VzClient_LockControl(VzClientHandle handle, int option, int zone_id, int lock_id);

//#ifdef  LINUX
//#ifdef __cplusplus
}
//#endif
//#endif

#endif
