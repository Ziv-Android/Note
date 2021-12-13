//���ڽ���VZ�ĳ���ʶ���豸����������ʶ��һ���������ʶ���ն˵ȣ���Ӧ�ó���ӿ�
#ifndef _VZ_LPRC_SDK_H_
#define _VZ_LPRC_SDK_H_
#include <VzLPRClientSDKDefine.h>

/**
* @defgroup group_global ȫ�ֲ�������
* @defgroup group_device �����豸��������
* @defgroup group_callback �ص�����
*/

#ifdef  LINUX
#ifdef __cplusplus
extern "C"
{
#endif
#endif

/**
*  @brief ȫ�ֳ�ʼ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note �����нӿڵ���֮ǰ����
*  @ingroup group_global
*/
VZ_LPRC_API int __STDCALL VzLPRClient_Setup();

/**
*  @brief ȫ���ͷ�
*  @note �ڳ������ʱ���ã��ͷ�SDK����Դ
*  @ingroup group_global
*/
VZ_LPRC_API void __STDCALL VzLPRClient_Cleanup();

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
typedef void (__STDCALL *VZLPRC_FIND_DEVICE_CALLBACK)(const char *pStrDevName, const char *pStrIPAddr, WORD usPort1, WORD usPort2, unsigned int SL,unsigned int SH, void *pUserData);

/**
*  @brief ��ʼ�����豸
*  @param  [IN] func �ҵ����豸ͨ���ûص���������
*  @param  [IN] pUserData �ص������е�������
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_global
*/
VZ_LPRC_API int __STDCALL VZLPRClient_StartFindDevice(VZLPRC_FIND_DEVICE_CALLBACK func, void *pUserData);

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
typedef void(__STDCALL *VZLPRC_FIND_DEVICE_CALLBACK_EX)(const char *pStrDevName, const char *pStrIPAddr, WORD usPort1, WORD usType, unsigned int SL, unsigned int SH, char* netmask, char* gateway, void *pUserData);

/**
*  @brief ��ʼ�����豸
*  @param  [IN] func �ҵ����豸ͨ���ûص���������
*  @param  [IN] pUserData �ص������е�������
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_global
*/
VZ_LPRC_API int __STDCALL VZLPRClient_StartFindDeviceEx(VZLPRC_FIND_DEVICE_CALLBACK_EX func, void *pUserData);


/**
*  @brief ͨ���ûص���������ҵ����豸������Ϣ
*  @param  [IN] pStrDevName �豸����
*  @param  [IN] pStrIPAddr	�豸IP��ַ
*  @param  [IN] usPort1		  �豸�˿ں�
*  @param  [IN] usPort2		  Ԥ��
*  @param  [IN] SL            �豸���кŵ�λ�ֽ�
*  @param  [IN] SH			  �豸���кŸ�λ�ֽ�
*  @param  [IN] ext_json_data ��չjson��ʽ����
*  @param  [IN] data_len	  ���ݳ���
*  @param  [IN] pUserData	  �ص�����������
*  @ingroup group_callback
*/
typedef void(__STDCALL *VZLPRC_FIND_DEVICE_CALLBACK_EX2)(const char *pStrDevName, const char *pStrIPAddr, WORD usPort1, WORD usType, unsigned int SL, unsigned int SH, char* netmask, char* gateway, char* ext_json_data, int data_len, void *pUserData);

/**
*  @brief ��ʼ�����豸
*  @param  [IN] func �ҵ����豸ͨ���ûص���������
*  @param  [IN] pUserData �ص������е�������
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_global
*/
VZ_LPRC_API int __STDCALL VZLPRClient_StartFindDeviceEx2(VZLPRC_FIND_DEVICE_CALLBACK_EX2 func, void *pUserData);

/**
*  @brief ֹͣ�����豸
*  @ingroup group_global
*/
VZ_LPRC_API void __STDCALL VZLPRClient_StopFindDevice();

/**
*  @brief ͨ���ûص���������豸��һ��״̬��Ϣ
*  @param  [IN] handle		��VzLPRClient_Open������õľ��
*  @param  [IN] pUserData	�ص�����������
*  @param  [IN] eNotify		ͨ����Ϣ��������
*  @param  [IN] pStrDetail	��ϸ�����ַ���
*  @ingroup group_callback
*/
typedef void (__STDCALL *VZLPRC_COMMON_NOTIFY_CALLBACK)(VzLPRClientHandle handle, void *pUserData,
													   VZ_LPRC_COMMON_NOTIFY eNotify, const char *pStrDetail);

/**
*  @brief �����豸���ӷ��������صĻص�����
*  @param  [IN] func �豸���ӽ����״̬��ͨ���ûص���������
*  @param  [IN] pUserData �ص������е�������
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_global
*/
VZ_LPRC_API int __STDCALL VZLPRClient_SetCommonNotifyCallBack(VZLPRC_COMMON_NOTIFY_CALLBACK func, void *pUserData);

/**
*  @brief ��һ���豸
*  @param  [IN] pStrIP �豸��IP��ַ
*  @param  [IN] wPort �豸�Ķ˿ں�
*  @param  [IN] pStrUserName �����豸�����û���
*  @param  [IN] pStrPassword �����豸��������
*  @return �����豸�Ĳ������������ʧ��ʱ������0
*  @ingroup group_device
*/
VZ_LPRC_API VzLPRClientHandle __STDCALL VzLPRClient_Open(
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
VZ_LPRC_API VzLPRClientHandle __STDCALL VzLPRClient_OpenEx(const char *pStrIP, WORD wPort, const char *pStrUserName, const char *pStrPassword,WORD wRtspPort);

/**
*  @brief ��һ���豸
*  @param  [IN] pStrIP �豸��IP��ַ
*  @param  [IN] wPort �豸�Ķ˿ں�
*  @param  [IN] pStrUserName �����豸�����û���
*  @param  [IN] pStrPassword �����豸��������
*  @param  [IN] wRtspPort ��ý��Ķ˿ں�,Ϊ0��ʾʹ��Ĭ��
*  @param  [IN] wTcpPort tcp�˿ں�,Ϊ0��ʾʹ��Ĭ��
*  @return �����豸�Ĳ������������ʧ��ʱ������0
*  @ingroup group_device
*/
VZ_LPRC_API VzLPRClientHandle __STDCALL VzLPRClient_OpenEx2(const char *pStrIP, WORD wPort, const char *pStrUserName, const char *pStrPassword,WORD wRtspPort, WORD wTcpPort);

/**
*  @brief �ر�һ���豸
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_Close(VzLPRClientHandle handle);

/**
*  @brief ͨ��IP��ַ�ر�һ���豸
*  @param  [IN] pStrIP �豸��IP��ַ
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_CloseByIP(const char *pStrIP);

/**
*  @brief ��ȡ����״̬
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN/OUT] pStatus �����ȡ״̬�ı�����ַ���������Ϊ 1�����ϣ�0δ����
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   �û��������ڵ��øú�����������ѯ�豸�Ƿ���ߣ��Լ����ߺ��Ƿ�ָ�����
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_IsConnected(VzLPRClientHandle handle, BYTE *pStatus);

/**
*  @brief ����ʵʱ��Ƶ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] hWnd ���ڵľ��
*  @return ���ŵľ����-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_StartRealPlay(VzLPRClientHandle handle, void *hWnd);

/**
*  @brief ֹͣ����ָ���Ĳ��ž��
*  @param  [IN] nPlayHandle ���ŵľ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   ������ֹͣ�������Ժ���VzLPRClient_StartRealPlay��VzLPRClient_StartRealPlayFrameCallBack�Ĳ��ž��
*  @note   ֹͣ�����Ժ󣬸ò��ž����ʧЧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_StopRealPlay(int nPlayHandle);

/**
*  @brief  ͨ���ûص��������ʵʱͼ������
*  @param  [IN] handle		��VzLPRClient_Open������õľ��
*  @param  [IN] pUserData	�ص�������������
*  @param  [IN] pFrame		ͼ��֡��Ϣ������ṹ�嶨��VzYUV420P
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_callback
*/
typedef void (__STDCALL *VZLPRC_VIDEO_FRAME_CALLBACK)(VzLPRClientHandle handle, void *pUserData,
													  const VzYUV420P *pFrame);
/**
*  @brief ����ʵʱͼ�����ݵĻص�����
*  @param  [IN] handle		��VzLPRClient_Open������õľ��
*  @param  [IN] func		ʵʱͼ�����ݺ���
*  @param  [IN] pUserData	�ص������е�������
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   DEPRECATED: ��ת��Ϊʹ��VzLPRClient_StartRealPlayFrameCallBack(handle, NULL, func, pUserData);
*  @ingroup group_device
*/
VZ_DEPRECATED VZ_LPRC_API int __STDCALL VzLPRClient_SetVideoFrameCallBack(VzLPRClientHandle handle, VZLPRC_VIDEO_FRAME_CALLBACK func, void *pUserData);

/**
*  @brief  ͨ���ûص��������ʵʱͼ������
*  @param  [IN] handle		��VzLPRClient_Open������õľ��
*  @param  [IN] pUserData	�ص�������������
*  @param  [IN] pFrame		ͼ��֡��Ϣ������ṹ�嶨��VZ_LPRC_IMAGE_INFO
*  @ingroup group_callback
*/
typedef void (__STDCALL *VZLPRC_VIDEO_FRAME_CALLBACK_EX)(VzLPRClientHandle handle, void *pUserData,
														 const VZ_LPRC_IMAGE_INFO *pFrame);
/**
*  @brief ��ȡʵʱ��Ƶ֡��ͼ������ͨ���ص��������û��㣬�û��ɸĶ�ͼ�����ݣ�������ʾ������
*  @param  [IN] handle		��VzLPRClient_Open������õľ��
*  @param  [IN] hWnd		���ڵľ�������Ϊ��Чֵ������Ƶͼ�����ʾ���ô����ϣ����Ϊ�գ�����ʾ��Ƶͼ��
*  @param  [IN] func		ʵʱͼ�����ݺ���
*  @param  [IN] pUserData	�ص������е�������
*  @return ���ŵľ����-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_StartRealPlayFrameCallBack(VzLPRClientHandle handle, void *hWnd,
												  VZLPRC_VIDEO_FRAME_CALLBACK_EX func, void *pUserData);

/**
*  @brief  ͨ���ûص�������ñ�������
*  @param  [IN] handle		��VzLPRClient_Open������õľ��
*  @param  [IN] pUserData	�ص�������������
*  @param  [IN] eDataType	�������ͣ����ö��VZ_LPRC_DATA_TYPE
*  @param  [IN] pData		����֡��Ϣ������ṹ�嶨��VZ_LPRC_DATA_INFO
*  @ingroup group_callback
*/
typedef void (__STDCALL *VZLPRC_VIDEO_DATA_CALLBACK)(VzLPRClientHandle handle, void *pUserData,
													 VZ_LPRC_DATA_TYPE eDataType, const VZ_LPRC_DATA_INFO *pData);

/**
*  @brief ��ȡʵʱ��������
*  @param  [IN] handle		��VzLPRClient_Open������õľ��
*  @param  [IN] func		�ص�����
*  @param  [IN] pUserData	�ص������е�������
*  @return ���ŵľ����-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetRealDataCallBack(VzLPRClientHandle handle,
												  VZLPRC_VIDEO_DATA_CALLBACK func, void *pUserData);

/**
*  @brief ͨ���ûص�������ó���ʶ����Ϣ
*  @param  [IN] handle			��VzLPRClient_Open������õľ��
*  @param  [IN] pUserData		�ص�������������
*  @param  [IN] pResult			������Ϣ�����׵�ַ������ṹ�嶨�� TH_PlateResult
*  @param  [IN] uNumPlates		���������еĳ��Ƹ���
*  @param  [IN] eResultType		����ʶ�������ͣ����ö�����Ͷ���VZ_LPRC_RESULT_TYPE
*  @param  [IN] pImgFull		��ǰ֡��ͼ�����ݣ�����ṹ�嶨��VZ_LPRC_IMAGE_INFO
*  @param  [IN] pImgPlateClip	��ǰ֡�г��������ͼ���������飬���е�Ԫ���복����Ϣ�����еĶ�Ӧ
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   �����Ҫ�ûص��������ؽ�ͼ���� pImgFull ��pImgPlateClip����Ҫ�����ûص�������VzLPRClient_SetPlateInfoCallBack��ʱ�����ͼ���ݣ�����ûص��������ص�������ָ��Ϊ�գ�
*  @note   ʵʱ�����VZ_LPRC_RESULT_REALTIME���Ļص��ǲ�����ͼ���ݵ�
*  @ingroup group_callback
*/
typedef int (__STDCALL *VZLPRC_PLATE_INFO_CALLBACK)(VzLPRClientHandle handle, void *pUserData,
													const TH_PlateResult *pResult, unsigned uNumPlates,
													VZ_LPRC_RESULT_TYPE eResultType,
													const VZ_LPRC_IMAGE_INFO *pImgFull,
													const VZ_LPRC_IMAGE_INFO *pImgPlateClip);

/**
*  @brief ͨ���ûص�������ó���ʶ����Ϣ(����)
*  @param  [IN] handle			��VzLPRClient_Open������õľ��
*  @param  [IN] pUserData		�ص�������������
*  @param  [IN] exitEntryInfo	�����������Ϣ 0 Ϊ��ڣ�1 Ϊ����
*  @param  [IN] exitIvsInfo		����������Ϣ�����豸Ϊ����豸ʱ���ֶ���Ϣ��Ч��
*  @param  [IN] entryIvsInfo	���������Ϣ
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_callback
*/

typedef int (__STDCALL *VZLPRC_PLATE_GROUP_INFO_CALLBACK)(VzLPRClientHandle handle, 
														  void *pUserData,
														  int exitEntryInfo,
														  const TH_PlateResult *exitIvsInfo, 
														  const TH_PlateResult *entryIvsInfo, 
														  const IVS_DG_DEVICE_INFO *exitDGInfo, 
														  const IVS_DG_DEVICE_INFO *entryDGInfo);
/**
*  @brief ����ʶ�����Ļص�����
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] func ʶ�����ص����������ΪNULL�����ʾ�رոûص������Ĺ���
*  @param  [IN] pUserData �ص������е�������
*  @param  [IN] bEnableImage ָ��ʶ�����Ļص��Ƿ���Ҫ������ͼ��Ϣ��1Ϊ��Ҫ��0Ϊ����Ҫ
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetPlateInfoCallBack(VzLPRClientHandle handle, VZLPRC_PLATE_INFO_CALLBACK func, void *pUserData, int bEnableImage);

/**
*  @brief ����ʶ�����Ļص�������������
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] func ʶ�����ص����������ΪNULL�����ʾ�رոûص������Ĺ��ܣ�������
*  @param  [IN] pUserData �ص������е�������
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_device
*/

VZ_LPRC_API int __STDCALL VzLPRClient_SetPlateGroupInfoCallBack(VzLPRClientHandle handle, VZLPRC_PLATE_GROUP_INFO_CALLBACK func, void *pUserData);


/**
*  @brief �����ѻ�����Ļص�����
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] func ʶ�����ص����������ΪNULL�����ʾ�رոûص������Ĺ���
*  @param  [IN] pUserData �ص������е�������
*  @param  [IN] bEnableImage ָ��ʶ�����Ļص��Ƿ���Ҫ������ͼ��Ϣ��1Ϊ��Ҫ��0Ϊ����Ҫ
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetOfflinePlateInfoCallBack(VzLPRClientHandle handle, VZLPRC_PLATE_INFO_CALLBACK func, void *pUserData, int bEnableImage);


/**
*  @brief ������������źţ�ǿ�ƴ���ǰʱ�̵����ݲ�������
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   ����ʶ����ͨ���ص������ķ�ʽ���أ������ǰ��Ƶ�������޳��ƣ����ʶ����Ϊ"_��_"
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_ForceTrigger(VzLPRClientHandle handle);

/**
*  @brief  ��չ�ӿڣ���Tcp��ʽ������������źţ�ǿ�ƴ���ǰʱ�̵����ݲ�������
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   ����ʶ����ͨ���ص������ķ�ʽ���أ������ǰ��Ƶ�������޳��ƣ����ʶ����Ϊ"_��_"
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_ForceTriggerEx(VzLPRClientHandle handle);

/**
*  @brief ����������Ȧ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] pVirtualLoops ������Ȧ�Ľṹ��ָ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetVirtualLoop(VzLPRClientHandle handle, const VZ_LPRC_VIRTUAL_LOOPS *pVirtualLoops);

/**
*  @brief ��ȡ�����õ�������Ȧ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] pVirtualLoops ������Ȧ�Ľṹ��ָ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetVirtualLoop(VzLPRClientHandle handle,  VZ_LPRC_VIRTUAL_LOOPS *pVirtualLoops);

/**
*  @brief ����������Ȧ����Ȧ֧�ָ���Ķ���
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] pVirtualLoops ������Ȧ�Ľṹ��ָ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetVirtualLoopEx(VzLPRClientHandle handle, const VZ_LPRC_VIRTUAL_LOOPS_EX *pVirtualLoops);

/**
*  @brief ��ȡ�����õ�������Ȧ����Ȧ֧�ָ���Ķ���
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] pVirtualLoops ������Ȧ�Ľṹ��ָ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetVirtualLoopEx(VzLPRClientHandle handle,  VZ_LPRC_VIRTUAL_LOOPS_EX *pVirtualLoops);

/**
*  @brief ����ʶ������
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] pROI ʶ������Ľṹ��ָ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   ������ʶ�������вŻᱻʶ��
*  @note   ʶ��������������θ��ӻ����ĸ��ŵȣ����ʶ���ٶȺ�׼ȷ�ԣ�������ʶ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetRegionOfInterest(VzLPRClientHandle handle, const VZ_LPRC_ROI *pROI);

/**
*  @brief ��ȡ�����õ�ʶ������
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] pROI ʶ������Ľṹ��ָ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetRegionOfInterest(VzLPRClientHandle handle, VZ_LPRC_ROI *pROI);

/**
*  @brief ����ʶ������
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] pROI ʶ������Ľṹ��ָ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   ������ʶ�������вŻᱻʶ��
*  @note   ʶ��������������θ��ӻ����ĸ��ŵȣ����ʶ���ٶȺ�׼ȷ�ԣ�������ʶ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetRegionOfInterestEx(VzLPRClientHandle handle, const VZ_LPRC_ROI_EX *pROI);

/**
*  @brief ��ȡ�����õ�ʶ������
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] pROI ʶ������Ľṹ��ָ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetRegionOfInterestEx(VzLPRClientHandle handle, VZ_LPRC_ROI_EX *pROI);
/**
*  @brief ��ȡ�����õ�Ԥ��ʡ��
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] pProvInfo Ԥ��ʡ����Ϣָ��
*  @return 0��ʾ�ɹ�����0��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetSupportedProvinces(VzLPRClientHandle handle, VZ_LPRC_PROVINCE_INFO *pProvInfo);

/**
*  @brief ����Ԥ��ʡ��
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] nIndex ����Ԥ��ʡ�ݵ���ţ������Ҫ�ο�VZ_LPRC_PROVINCE_INFO::strProvinces�е�˳�򣬴�0��ʼ�����С��0�����ʾ������Ԥ��ʡ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_PresetProvinceIndex(VzLPRClientHandle handle, int nIndex);

/**
*  @brief ��ͼ�񱣴�ΪJPEG��ָ��·��
*  @param  [IN] pImgInfo ͼ��ṹ�壬Ŀǰֻ֧��Ĭ�ϵĸ�ʽ����ImageFormatRGB
*  @param  [IN] pFullPathName �������·����JPG��׺�����ļ����ַ���
*  @param  [IN] nQuality JPEGѹ����������ȡֵ��Χ1~100��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   �������ļ����е�·����Ҫ����
*  @ingroup group_global
*/
VZ_LPRC_API int __STDCALL VzLPRClient_ImageSaveToJpeg(const VZ_LPRC_IMAGE_INFO *pImgInfo, const char *pFullPathName, int nQuality);

/**
*  @brief ��ͼ�����ΪJPEG�����浽ָ���ڴ�
*  @param  [IN] pImgInfo ͼ��ṹ�壬Ŀǰֻ֧��Ĭ�ϵĸ�ʽ����ImageFormatRGB
*  @param  [IN/OUT] pDstBuf JPEG���ݵ�Ŀ�Ĵ洢�׵�ַ
*  @param  [IN] uSizeBuf JPEG���ݵ�ַ���ڴ�����ߴ磻
*  @param  [IN] nQuality JPEGѹ����������ȡֵ��Χ1~100��
*  @return >0��ʾ�ɹ����������ĳߴ磬-1��ʾʧ�ܣ�-2��ʾ������ѹ�����ݵ��ڴ�ߴ粻����
*  @ingroup group_global
*/
VZ_LPRC_API int __STDCALL VzLPRClient_ImageEncodeToJpeg(const VZ_LPRC_IMAGE_INFO *pImgInfo, void *pDstBuf, unsigned uSizeBuf, int nQuality);

/**
*  @brief ��JPEG���뵽ͼ���ڴ�
*  @param  [IN] pSrcData JPEG���ݴ洢�׵�ַ
*  @param  [IN] uSizeData JPEG���ݳߴ�
*  @param  [OUT] pImgInfo ������ͼ������
*  @param  [IN] pBufExt �ⲿ����һ�����ڱ���������ڴ�ĵ�ַ��
*  @param  [IN] uSizeBufExt �ⲿ�����ڴ�ĳߴ磬��Ҫ���ڵ���JPEGͼ������ĵ�RGB�ڴ�ߴ�
*  @return 0��ʾ�ɹ���-1��ʾʧ�ܣ�>0��ʾ�ⲿ�������ڴ治������Ҫ�������ڵ��ڴ˳ߴ���ڴ��ַ
*  @note  ���û��Ԥ֪JPEG������ͼ��ֱ��ʣ���ô�ͽ�uSizeBufExtָ��Ϊ0���ӿڽ�����������С�ڴ�ߴ磬������ڴ���ٵ��øýӿڽ��н���
*  @ingroup group_global
*/
VZ_LPRC_API int __STDCALL VzLPRClient_JpegDecodeToImage(void *pSrcData, unsigned uSizeData, VZ_LPRC_IMAGE_INFO *pImgInfo, void *pBufExt, unsigned uSizeBufExt);

/**
*  @brief �������ڲ��ŵ���Ƶ�ĵ�ǰ֡�Ľ�ͼ��ָ��·��
*  @param  [IN] hWnd ���ڲ�����Ƶ�Ĵ��ڵľ��
*  @param  [IN] pFullPathName �������·����JPG��׺�����ļ����ַ���
*  @param  [IN] nQuality JPEGѹ����������ȡֵ��Χ1~100��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   ǰ��������ָ����hWnd�Ĵ����Ѿ�������VzLPRClient_StartRealPlay����ʵʱ��Ƶ
*  @note   ʹ�õ��ļ����е�·����Ҫ����
*  @note   DEPRECATED: ��תΪʹ��VzLPRClient_GetSnapShootToJpeg2
*  @ingroup group_device
*/
VZ_DEPRECATED VZ_LPRC_API int __STDCALL VzLPRClient_GetSnapShootToJpeg(void *hWnd, const char *pFullPathName, int nQuality);

/**
*  @brief �������ڲ��ŵ���Ƶ�ĵ�ǰ֡�Ľ�ͼ��ָ��·��
*  @param  [IN] nPlayHandle ���ŵľ��
*  @param  [IN] pFullPathName �������·����JPG��׺�����ļ����ַ���
*  @param  [IN] nQuality JPEGѹ����������ȡֵ��Χ1~100��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   ʹ�õ��ļ����е�·����Ҫ����
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetSnapShootToJpeg2(int nPlayHandle, const char *pFullPathName, int nQuality);

/**
*  @brief ��ȡIO�����״̬
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] uChnId IO�����ͨ���ţ���0��ʼ
*  @param  [OUT] pOutput IO�����״̬��0��ʾ�̵�����·��1��ʾ�̵�����·
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetIOOutput(VzLPRClientHandle handle, unsigned uChnId, int *pOutput);

/**
*  @brief ����IO�����״̬
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] uChnId IO�����ͨ���ţ���0��ʼ
*  @param  [OUT] nOutput ��Ҫ���õ�IO�����״̬��0��ʾ�̵�����·��1��ʾ�̵�����·
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetIOOutput(VzLPRClientHandle handle, unsigned uChnId, int nOutput);

/**
*  @brief ���ô��ڲ���
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] nSerialPort ָ��ʹ���豸�Ĵ�����ţ�0��ʾ��һ�����ڣ�1��ʾ�ڶ�������
*  @param  [IN] pParameter ��Ҫ���õĴ��ڲ������������ VZ_SERIAL_PARAMETER
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetSerialParameter(VzLPRClientHandle handle, int nSerialPort,
														 const VZ_SERIAL_PARAMETER *pParameter);

/**
*  @brief ��ȡ���ڲ���
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] nSerialPort ָ��ʹ���豸�Ĵ�����ţ�0��ʾ��һ�����ڣ�1��ʾ�ڶ�������
*  @param  [OUT] pParameter ��Ҫ��ȡ�Ĵ��ڲ������������ VZ_SERIAL_PARAMETER
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetSerialParameter(VzLPRClientHandle handle, int nSerialPort,
														 VZ_SERIAL_PARAMETER *pParameter);
/**
*  @brief ͨ���ûص��������͸��ͨ�����յ�����
*  @param  [IN] nSerialHandle VzLPRClient_SerialStart���صľ��
*  @param  [IN] pRecvData	���յ����ݵ��׵�ַ
*  @param  [IN] uRecvSize	���յ����ݵĳߴ�
*  @param  [IN] pUserData	�ص�����������
*  @ingroup group_callback
*/
typedef void (__STDCALL *VZDEV_SERIAL_RECV_DATA_CALLBACK)(int nSerialHandle, const unsigned char *pRecvData, unsigned uRecvSize, void *pUserData);

/**
*  @brief ����͸��ͨ��
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] nSerialPort ָ��ʹ���豸�Ĵ�����ţ�0��ʾ��һ�����ڣ�1��ʾ�ڶ�������
*  @param  [IN] func �������ݵĻص�����
*  @param  [IN] pUserData �������ݻص�������������
*  @return ����͸��ͨ�������0��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SerialStart(VzLPRClientHandle handle, int nSerialPort,
												  VZDEV_SERIAL_RECV_DATA_CALLBACK func, void *pUserData);
/**
*  @brief ͸��ͨ����������
*  @param [IN] nSerialHandle ��VzLPRClient_SerialStart������õľ��
*  @param [IN] pData ��Ҫ��������ݿ���׵�ַ
*  @param [IN] uSizeData ��Ҫ��������ݿ���ֽ���
*  @return 0��ʾ�ɹ�������ֵ��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SerialSend(int nSerialHandle, const unsigned char *pData, unsigned uSizeData);

/**
*  @brief ͸��ͨ��ֹͣ��������
*  @param [IN] nSerialHandle ��VzLPRClient_SerialStart������õľ��
*  @return 0��ʾ�ɹ�������ֵ��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SerialStop(int nSerialHandle);

/**
*  @brief �����豸��ͷ�ı䱶�;۽�
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] eOPT �������ͣ��������VZ_LENS_OPT
*  @return 0��ʾ�ɹ�������ֵ��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_CtrlLens(VzLPRClientHandle handle, VZ_LENS_OPT eOPT);

/**
*  @brief ��ȡLED��ǰ���ȵȼ���������ȵȼ�
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] pLevelNow ���������ǰ���ȵȼ��ĵ�ַ
*  @param [OUT] pLevelMax �������������ȵȼ��ĵ�ַ
*  @return 0��ʾ�ɹ�������ֵ��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetLEDLightStatus(VzLPRClientHandle handle, int *pLevelNow, int *pLevelMax);

/**
*  @brief ����LED���ȵȼ�
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] nLevel��LED���ȵȼ�
*  @return 0��ʾ�ɹ�������ֵ��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetLEDLightLevel(VzLPRClientHandle handle, int nLevel);

/**
*  @brief ��ȡLED��ǰ����ģʽ
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] pCtrl ���������ǰLED���ؿ���ģʽ�ĵ�ַ��������� VZ_LED_CTRL
*  @return 0��ʾ�ɹ�������ֵ��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetLEDLightControlMode(VzLPRClientHandle handle, VZ_LED_CTRL *pCtrl);

/**
*  @brief ����LED����ģʽ
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] eCtrl ����LED����ģʽ��������� VZ_LED_CTRL
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetLEDLightControlMode(VzLPRClientHandle handle, VZ_LED_CTRL eCtrl);

/**
*  @brief д���û�˽�����ݣ������ڶ��μ���
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pUserData �û�����
*  @param [IN] uSizeData �û����ݵĳ��ȣ����128�ֽ�
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WriteUserData(VzLPRClientHandle handle, const unsigned char *pUserData, unsigned uSizeData);

/**
*  @brief �����û�˽�����ݣ������ڶ��μ���
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN/OUT] pBuffer ���ڴ�Ŷ������û�����
*  @param [IN] uSizeBuf �û����ݻ���������С�ߴ磬��С��128�ֽ�
*  @return ����ֵΪʵ���û����ݵ��ֽ���������-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_ReadUserData(VzLPRClientHandle handle, unsigned char *pBuffer, unsigned uSizeBuf);

/**
*  @brief �����豸���кţ������ڶ��μ���
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN/OUT] pSN ���ڴ�Ŷ������豸���кţ�������� VZ_DEV_SERIAL_NUM
*  @return ����ֵΪ0��ʾ�ɹ�������-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetSerialNumber(VzLPRClientHandle handle, VZ_DEV_SERIAL_NUM *pSN);

/**
*  @brief ��ȡ�豸������ʱ��
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN/OUT] pDTInfo ���ڴ�Ż�ȡ�����豸����ʱ����Ϣ��������� VZ_DATE_TIME_INFO
*  @return ����ֵΪ0��ʾ�ɹ�������-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetDateTime(VzLPRClientHandle handle, VZ_DATE_TIME_INFO *pDTInfo);

/**
*  @brief �����豸������ʱ��
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pDTInfo ��Ҫ���õ��豸����ʱ����Ϣ��������� VZ_DATE_TIME_INFO
*  @return ����ֵΪ0��ʾ�ɹ�������-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetDateTime(VzLPRClientHandle handle, const VZ_DATE_TIME_INFO *pDTInfo);

/**
*  @brief ��ȡ�豸�Ĵ洢��Ϣ
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN/OUT] pDTInfo ���ڴ�Ż�ȡ�����豸����ʱ����Ϣ��������� VZ_DATE_TIME_INFO
*  @return ����ֵΪ0��ʾ�ɹ�������-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetStorageDeviceInfo(VzLPRClientHandle handle, VZ_STORAGE_DEVICES_INFO *pSDInfo);

/**
*  @brief ��ʼ¼����
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] sFileName ¼���ļ���·��
*  @return ����ֵΪ0��ʾ�ɹ�������-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SaveRealData(VzLPRClientHandle handle,char *sFileName);

/**
*  @brief ֹͣ¼��
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @return ����ֵΪ0��ʾ�ɹ�������-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_StopSaveRealData(VzLPRClientHandle handle);

/**
*  @brief ������ƵOSD������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @return ����ֵΪ0��ʾ�ɹ�������-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetOsdParam(VzLPRClientHandle handle, VZ_LPRC_OSD_Param *pParam);

/**
*  @brief ��ȡ��ƵOSD������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @return ����ֵΪ0��ʾ�ɹ�������-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetOsdParam(VzLPRClientHandle handle, VZ_LPRC_OSD_Param *pParam);

/**
*  @brief �����ѻ���飬ʵ���ѻ��Զ��л��������Ĺ��ܡ�
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] pUserData �������ݻص�������������
*  @note   ��Чǰ�᣺�豸�ġ����������ҳ��ġ���������֤��TABҳ�еġ���������������������Ϊ���ѻ��Զ����á�
*  @note   ���øýӿڣ��豸����øýӿڵĿͻ���֮��ͻ��γɰ󶨣�����ͻ������豸֮��������������ô�豸�ϵİ�������Ϊͣ��״̬���������IO�źſ��Ƶ�բ̧�˺����485����Э�飻
*  @note   ����ͻ������豸�豸֮���������ˣ����߿ͻ��˹رգ����ߵ����˹ر��ѻ���飨CancelOfflineCheck���ӿڣ���ô�豸�ϵİ����������ã��豸���ݰ��������Ƶ�բ̧�˺����485����Э�飻
*  @return ����ֵΪ0��ʾ�ɹ�������-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetOfflineCheck(VzLPRClientHandle handle);

/**
*  @brief �ر��ѻ����
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] pUserData �������ݻص�������������
*  @note   ��Чǰ�᣺�豸�ġ����������ҳ��ġ���������֤��TABҳ�еġ���������������������Ϊ���ѻ��Զ����á�
*  @note   �ر��ѻ���飬�豸���ڰ����������IO�źſ��Ƶ�բ̧�˺����485����Э�顣
*  @return ����ֵΪ0��ʾ�ɹ�������-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_CancelOfflineCheck(VzLPRClientHandle handle);

/**
*  @brief ����ID��ѯ��¼
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] nID ���Ƽ�¼�������е�ID
*  @return ����ֵΪ0��ʾ�ɹ�������-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_QueryPlateRecordByID(VzLPRClientHandle handle, int nID);

/**
*  @brief ������ʼʱ��ͳ��ƹؼ��ֲ�ѯ��¼
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] pStartTime ��ʼʱ�䣬��ʽ��"2015-01-02 12:20:30"
*  @param  [IN] pEndTime   ��ʼʱ�䣬��ʽ��"2015-01-02 19:20:30"
*  @param  [IN] keyword    ���ƺŹؼ���, ��"��"
*  @return ����ֵΪ0��ʾ�ɹ�������-1��ʾʧ��
*  @˵��   ͨ���ص��������ݣ���෵��100�����ݣ�����ʱ����÷�ҳ��ѯ�Ľӿ�
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_QueryRecordByTimeAndPlate(VzLPRClientHandle handle, const char *pStartTime, const char *pEndTime, const char *keyword);


/**
*  @brief ����ʱ��ͳ��ƺŲ�ѯ��¼����
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] pStartTime ��ʼʱ�䣬��ʽ��"2015-01-02 12:20:30"
*  @param  [IN] pEndTime   ��ʼʱ�䣬��ʽ��"2015-01-02 19:20:30"
*  @param  [IN] keyword    ���ƺŹؼ���, ��"��"
*  @return ����ֵΪ0��ʾʧ�ܣ�����0��ʾ��¼����
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_QueryCountByTimeAndPlate(VzLPRClientHandle handle, const char *pStartTime, const char *pEndTime, const char *keyword);

/**
*  @brief ����ʱ��ͳ��ƺŲ�ѯ��ҳ��¼
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] pStartTime ��ʼʱ�䣬��ʽ��"2015-01-02 12:20:30"
*  @param  [IN] pEndTime   ��ʼʱ�䣬��ʽ��"2015-01-02 19:20:30"
*  @param  [IN] keyword    ���ƺŹؼ���, ��"��"
*  @param  [IN] start      ��ʼλ�ô���0,С�ڽ���λ��
*  @param  [IN] end        ����λ�ô���0,������ʼλ�ã���ȡ��¼�������ܴ���100
*  @return ����ֵΪ0��ʾ�ɹ�������-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_QueryPageRecordByTimeAndPlate(VzLPRClientHandle handle, const char *pStartTime, const char *pEndTime, const char *keyword, int start, int end);


/**
*  @brief ���ò�ѯ���Ƽ�¼�Ļص�����
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] func ʶ�����ص����������ΪNULL�����ʾ�رոûص������Ĺ���
*  @param  [IN] pUserData �ص������е�������
*  @param  [IN] bEnableImage ָ��ʶ�����Ļص��Ƿ���Ҫ������ͼ��Ϣ��1Ϊ��Ҫ��0Ϊ����Ҫ
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetQueryPlateCallBack(VzLPRClientHandle handle, VZLPRC_PLATE_INFO_CALLBACK func, void *pUserData);


/**
*  @brief ����ID��ȡ����ͼƬ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] id     ���Ƽ�¼��ID
*  @param  [IN] pdata  �洢ͼƬ���ڴ�
*  @param  [IN][OUT] size Ϊ���봫��ֵ������ΪͼƬ�ڴ�Ĵ�С�����ص��ǻ�ȡ��jpgͼƬ�ڴ�Ĵ�С
*  @return ����ֵΪ0��ʾ�ɹ�������-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_LoadImageById(VzLPRClientHandle handle, int id, void *pdata, int* size);


/**
*  @brief ����·����ȡͼƬ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] img_path �洢����������ͼƬ·��
*  @param  [IN] pdata  �洢ͼƬ���ڴ�
*  @param  [IN][OUT] size Ϊ���봫��ֵ������ΪͼƬ�ڴ�Ĵ�С�����ص��ǻ�ȡ��jpgͼƬ�ڴ�Ĵ�С
*  @return ����ֵΪ0��ʾ�ɹ�������-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_LoadImageByPath(VzLPRClientHandle handle, const char* img_path, void *pdata, int* size);

/**
*  @brief ��ȡ��Ƶ�Ŀ�Ⱥ͸߶�
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [OUT] pWidth		��Ƶͼ���ȱ����ĵ�ַ
*  @param  [OUT] pHeight	��Ƶͼ��߶ȱ����ĵ�ַ
*  @return ����ֵΪ0��ʾ�ɹ�������-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetVideoFrameSize(VzLPRClientHandle handle, int *pWidth, int *pHeight);

/**
*  @brief ��ȡ��Ƶ�ı��뷽ʽ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [OUT] pEncType	���صı��뷽ʽ, 0:H264  1:MPEG4  2:JPEG  ����:����
*  @return ����ֵΪ0��ʾ�ɹ�������-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetVideoEncodeType(VzLPRClientHandle handle, int *pEncType);

/**
*  @brief ��ȡGPIO��״̬
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] gpioIn ����Ϊ0��1
*  @param  [OUT] value 0�����·��1����·
*  @return ����ֵΪ0��ʾ�ɹ�������-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetGPIOValue(VzLPRClientHandle handle, int gpioIn, int *value);

/**
*  @brief ����ʱ���ѯ�ѻ���¼����
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] pStartTime ��ʼʱ�䣬��ʽ��"2015-01-02 12:20:30"
*  @param  [IN] pEndTime   ��ʼʱ�䣬��ʽ��"2015-01-02 19:20:30"
*  @return ����ֵΪ0��ʾʧ�ܣ�����0��ʾ��¼����
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_QueryOfflineCountByTime(VzLPRClientHandle handle, const char *pStartTime, const char *pEndTime);

/**
*  @brief ����ʱ��ͳ��ƺŷ�ҳ��ѯ�ѻ���¼
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] pStartTime ��ʼʱ�䣬��ʽ��"2015-01-02 12:20:30"
*  @param  [IN] pEndTime   ��ʼʱ�䣬��ʽ��"2015-01-02 19:20:30"
*  @param  [IN] start      ��ʼλ�ô���0,С�ڽ���λ��
*  @param  [IN] end        ����λ�ô���0,������ʼλ�ã���ȡ��¼�������ܴ���100
*  @return ����ֵΪ0��ʾ�ɹ�������-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_QueryPageOfflineRecordByTime(VzLPRClientHandle handle, const char *pStartTime, const char *pEndTime, int start, int end);


/**
*  @brief ��ȡϵͳ��־
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] iLogType ��־������
*  @param [IN/OUT] pstrLogBuffer ��־���ݻ���
*  @param [IN/OUT] iBufferLen ��־���ݻ���������,������־����
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetLog(VzLPRClientHandle handle, int iLogType,char* pstrLogBuffer, unsigned int* iBufferLen);

/**
*  @brief ��ȫ�ָ�Ĭ�ϲ�����
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_RestoreConfig(VzLPRClientHandle handle);

/**
*  @brief ���ָֻ�Ĭ�ϲ�����ip�˿����ã��û����ã��豸��������
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_RestoreConfigPartly(VzLPRClientHandle handle);

/**      
*  @brief ��ȡ�豸�汾�ţ��汾����4����ֵ���
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @return ����ֵΪ0��ʾ�ɹ�;
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetRemoteSoftWareVersion(VzLPRClientHandle handle, int *ver1, int *ver2, int *ver3, int *ver4);

/**
*  @brief ��ʽ��sd��
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SDFormat(VzLPRClientHandle handle);

//����
/**
*  @brief ��������ļ��汾��
*  @param [IN] file_path_name �����ļ�·��
*  @param [OUT] ver1 �汾��1
*  @param [OUT] ver2 �汾��2
*  @param [OUT] ver3 �汾��3
*  @param [OUT] ver4 �汾��4
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetUpdateFileVersion(char *file_path_name, int *ver1, int *ver2, int *ver3, int *ver4);

/**
*  @brief ��ʼ����
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] file_path_name �����ļ�·��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_Update(VzLPRClientHandle handle, char *file_path_name);


/**
*  @brief ��ȡ������״̬
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @return ������״̬
*			0: ��δ������
*			1: �����ɹ�
*			2: �����������ϴ��У�����ȡ������
*			3: ����������дflash�У�ȡ������������
*		    4: �������⣬״̬δ֪
*		   -1: ����ʧ��
*			ʧ�ܻ�����������ʱ����ͨ��getlasterror�������������Ϣ��������UPDATE_ERROR��
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetUpdateState(VzLPRClientHandle handle);


/**
*  @brief ȡ��������������״̬��2ʱ������ȡ������������ʱ������;
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_StopUpdate(VzLPRClientHandle handle);


/**
*  @brief ��ȡ�������ȣ��ϴ����Ϊ50���������Ϊ100����ǰ���50ֱ������100���м���Ȳ�����£��Ժ���
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetUpdateProgress(VzLPRClientHandle handle);

/**
*  @brief �豸����������á�
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] netcfg �μ�VZ_LPRC_NETCFG�ṹ�嶨��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetNetConfig(VzLPRClientHandle handle, VZ_LPRC_NETCFG* netcfg);

/**
*  @brief ��ȡ�豸����������á�
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] netcfg �μ�VZ_LPRC_NETCFG�ṹ�嶨��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetNetConfig(VzLPRClientHandle handle, VZ_LPRC_NETCFG* netcfg);


/**
*  @brief ����IO��������Զ���λ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] uChnId IO�����ͨ���ţ���0��ʼ
*  @param  [IN] nDuration ��ʱʱ�䣬ȡֵ��Χ[500, 5000]����
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetIOOutputAuto(VzLPRClientHandle handle, unsigned uChnId, int nDuration);

/**
* ��ȡ LastError
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetLastError();

/**
* �����豸
*/
VZ_LPRC_API int __STDCALL VzLPRClient_RebootDVR( VzLPRClientHandle handle );

/**
*  @brief �Զ��佹�Ĺ���
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @return ����ֵ������ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ��
*/
VZ_LPRC_API int __STDCALL VzLPRClient_DoAutoFocus(VzLPRClientHandle handle);

/**
*  @brief ������Ҫʶ��ĳ�������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] uBitsRecType ��Ҫʶ��ĳ������Ͱ�λ���ֵ����������λ�������VZ_LPRC_REC_XXX
*  @return ����ֵ������ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ��
*  @note  ����Ҫʶ���ض�����ʱ�����øýӿ������ã�����ͬ���͵ĳ���λ����ȡ�򣬵õ��Ľ����Ϊ�������룻
*  @note  �ڲ���Ҫ������£�ʹ�����ٵĳ���ʶ�����ͣ�������޶����ʶ���ʣ�
*  @note  Ĭ��ʶ�����ƺͻ��ƣ�
*  @note  ���磬��Ҫʶ�����ơ����ơ����ƣ���ô�������uBitsRecType = VZ_LPRC_REC_BLUE|VZ_LPRC_REC_YELLOW|VZ_LPRC_REC_POLICE
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetPlateRecType(VzLPRClientHandle handle, unsigned uBitsRecType);

/**
*  @brief ��ȡ�����õ���Ҫʶ��ĳ�������λ
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] pBitsRecType ��Ҫʶ��ĳ������Ͱ�λ��ı����ĵ�ַ����������λ�������VZ_LPRC_REC_XXX
*  @return ����ֵ������ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ��
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetPlateRecType(VzLPRClientHandle handle, unsigned *pBitsRecType);

/**
*  @brief ��ȡϵͳ�汾��
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN/OUT] pstrVersion ���淵�ذ汾�ŵ�BUF
*  @param [IN] uSizeBuf ���淵�ذ汾�ŵ�BUF��С
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetSystemVersion(VzLPRClientHandle handle, char *pstrVersion, unsigned uSizeBuf);

/**
*  @brief ��������ĳ���ʶ�𴥷�����
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] uBitsTrigType ����ĳ���ʶ�𴥷����Ͱ�λ���ֵ������������λ�������VZ_LPRC_TRIG_ENABLE_XXX
*  @return ����ֵ������ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ��
*  @note  ������ò�����ĳ�����͵Ĵ�������ô�������͵Ĵ������Ҳ���ᱣ�����豸��SD����
*  @note  Ĭ������ȶ�������������Ȧ����
*  @note  ����Ӱ���ֶ�������IO���봥��
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetPlateTrigType(VzLPRClientHandle handle, unsigned uBitsTrigType);

/**
*  @brief ��ȡ�����õ�����ĳ���ʶ�𴥷�����
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] pBitsTrigType ����ĳ���ʶ�𴥷����Ͱ�λ��ı����ĵ�ַ������������λ�������VZ_LPRC_TRIG_ENABLE_XXX
*  @return ����ֵ������ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ��
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetPlateTrigType(VzLPRClientHandle handle, unsigned *pBitsTrigType);


/**
*  @brief ���ó���ͼƬ���Ƿ���ʾ���ƿ�
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] bShow �Ƿ���ʾ���ƿ�����ֵ(0��1)��1������ʾ��0������ʾ
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetIsShowPlateRect(VzLPRClientHandle handle, int bShow);

/**
*  @brief ��ȡ�û��Զ�������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] buffer ���淵�����õ�buffer
*  @param [IN] buffer_len ���淵�ص�buffer��С
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetUserDefinedConfig(VzLPRClientHandle handle, char* buffer, int buffer_len);

/**
*  @brief �����û��Զ�������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] buffer �������ݣ�����Ϊ�ַ���
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetUserDefinedConfig(VzLPRClientHandle handle, char* buffer);

/**
*  @brief �޸��������
*  @param  [IN] SL        �豸���кŵ�λ�ֽ�
*  @param  [IN] SH		  �豸���кŸ�λ�ֽ�	
*  @param [IN] strNewIP   ��IP     ��ʽ��"192.168.3.109"
*  @param [IN] strGateway ����     ��ʽ��"192.168.3.1"
*  @param [IN] strNetmask �������� ��ʽ��"255.255.255.0"
*  @note ��������ʵ�ֿ������޸�IP�Ĺ���
*  @ingroup group_global
*/
VZ_LPRC_API int __STDCALL VzLPRClient_UpdateNetworkParam(unsigned int SL, unsigned int SH, const char* strNewIP, const char* strGateway, const char *strNetmask);


/**
*  @brief ��ȡ�豸�������ͺ͵�ǰ��������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pData ������Ϣ
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetEMS(VzLPRClientHandle handle, VZ_LPRC_ACTIVE_ENCRYPT* pData);

/**
*  @brief �����豸��������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pCurrentKey ��ǰʶ������
*  @param [IN] nEncyptId	�޸ĵļ�������ID 
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetEncrypt(VzLPRClientHandle handle, const void* pCurrentKey, const unsigned nEncyptId);

/**
*  @brief �޸��豸ʶ������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pCurrentKey ��ǰʶ������
*  @param [IN] pNewKey	��ʶ������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_ChangeEncryptKey(VzLPRClientHandle handle, const void* pCurrentKey, const void* pNewKey);

/**
*  @brief �����豸ʶ������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pPrimeKey ��ǰ�豸������
*  @param [IN] pNewKey	��ʶ������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_ResetEncryptKey(VzLPRClientHandle handle, const void* pPrimeKey, const void* pNewKey);

/**
*  @brief GPIO����ص�����
*  @param [IN] nGPIOId GPIO����ID
*  @param [IN] nVal	GPIO����ֵ
*  @param [IN] pUserData �û��Զ�������
*/
typedef void (__STDCALL *VZLPRC_GPIO_RECV_CALLBACK)(VzLPRClientHandle handle, int nGPIOId, int nVal, void* pUserData);

/**
*  @brief ����GPIO����ص�����
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] func GPIO����ص�����
*  @param [IN] pUserData �û��Զ�������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetGPIORecvCallBack(VzLPRClientHandle handle, VZLPRC_GPIO_RECV_CALLBACK func, void* pUserData);


// #ifdef _DEV_ENCRYPT_
/**
*  @brief ��ȡ�û�����
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pPrimeKey ������
*  @param [IN] pUserKey	 ���ܹ����û�����
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*  @note �˽ӿڲ������ṩ
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetEncryptKey(VzLPRClientHandle handle, const void* pPrimeKey, const void* pUserKey);

//#endif

VZ_LPRC_API int __STDCALL VzLPRClient_GetSesID(VzLPRClientHandle handle, char* buffer,int buffer_len);

/**
*  @brief ��ͼ�񱣴�ΪJPEG��ָ��·������ָ��ͼ��ߴ��ģʽ
*  @param  [IN] pImgInfo ͼ��ṹ�壬Ŀǰֻ֧��Ĭ�ϵĸ�ʽ����ImageFormatRGB
*  @param  [IN] pFullPathName �������·����JPG��׺�����ļ����ַ���
*  @param  [IN] nQuality JPEGѹ����������ȡֵ��Χ1~100��
*  @param  [IN] mode     ͼ���С��ģʽ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   �������ļ����е�·����Ҫ����
*/
VZ_LPRC_API int __STDCALL VzLPRClient_ImageSaveToJpegEx(const VZ_LPRC_IMAGE_INFO *pImgInfo, const char *pFullPathName, int nQuality, IMG_SIZE_MODE mode);

/**
*  @brief ��ͼ�����ΪJPEG�����浽ָ���ڴ棬��ָ��ͼ��ߴ��ģʽ
*  @param  [IN] pImgInfo ͼ��ṹ�壬Ŀǰֻ֧��Ĭ�ϵĸ�ʽ����ImageFormatRGB
*  @param  [IN/OUT] pDstBuf JPEG���ݵ�Ŀ�Ĵ洢�׵�ַ
*  @param  [IN] uSizeBuf JPEG���ݵ�ַ���ڴ�����ߴ磻
*  @param  [IN] nQuality JPEGѹ����������ȡֵ��Χ1~100��
*  @param  [IN] mode     ͼ���С��ģʽ��
*  @return >0��ʾ�ɹ����������ĳߴ磬-1��ʾʧ�ܣ�-2��ʾ������ѹ�����ݵ��ڴ�ߴ粻����
*/
VZ_LPRC_API int __STDCALL VzLPRClient_ImageEncodeToJpegEx(const VZ_LPRC_IMAGE_INFO *pImgInfo, void *pDstBuf, unsigned uSizeBuf, int nQuality, IMG_SIZE_MODE mode);

/**
*  @brief �����Ƿ����ʵʱ���
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] bOutput �Ƿ����
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetIsOutputRealTimeResult( VzLPRClientHandle handle, bool bOutput );

/**
*  @brief ��ȡ�豸Ӳ����Ϣ
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] status ״̬ 0 û��ȡ��Ӳ����Ϣ��1�л�����Ϣ��2�л�������չ��Ϣ
*  @param [OUT] mac ���mac��ַ�������ַ������峤������Ϊ20
*  @param [OUT] serialno ������кţ������ַ������峤������Ϊ20
*  @param [OUT] device_type �豸���ͣ��ο�IVS_TYPE����
*  @param [OUT] pdata_ex ��չӲ����Ϣ���ο�VZ_FS_INFO_EX����
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetHwInfo( VzLPRClientHandle handle, int* status, char* mac, char* serialno,int *device_type,VZ_FS_INFO_EX *pdata_ex);


/**
*  @brief ����ץͼ���ݵ�Jpeg�ļ�
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pFullPathName ͼƬ·��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SaveSnapImageToJpeg(VzLPRClientHandle handle, const char *pFullPathName);

/**
*  @brief ����ץͼ���ݵ�������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pDstBuf ����ͼƬ�Ļ�����
*  @param [OUT] uSizeBuf ����ͼƬ�Ļ���������
*  @return ����ֵΪ����0��ʾ����ͼƬ�ĳ��ȣ���������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetSnapImage(VzLPRClientHandle handle, void  *pDstBuf, int  uSizeBuf);


/**
*  @brief ����
*  @brief ��ȡ��ǰ�������豸��Ϣ
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pData ��ǰ���������ӵ������豸
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetOvzid(VzLPRClientHandle handle, VZ_OVZID_RESULT* pData);

/**
*  @brief ����
*  @brief ��������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pInfo �����豸��Ϣ
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_EnableDevicegroup(VzLPRClientHandle handle, VZ_OVZID_INFO *pData);

/**
*  @brief ����/�رա���������ʶ������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] bEnable true : ����;false : �ر�
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetDGResultEnable(VzLPRClientHandle handle, bool bEnable);

/**
*  @brief ��ȡ�������ֱ��ʣ�
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] sizeval ���VZDEV_FRAMESIZE_�궨��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetVideoFrameSizeIndex(VzLPRClientHandle handle, int *sizeval);

/**
*  @brief �����������ֱ��ʣ�
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] sizeval ���VZDEV_FRAMESIZE_�궨��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetVideoFrameSizeIndex(VzLPRClientHandle handle, int sizeval);

/**
*  @brief ��ȡ������֡��
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] Rateval ֡�ʣ���Χ1-25
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetVideoFrameRate(VzLPRClientHandle handle, int *Rateval);//1-25

/**
*  @brief ����������֡�ʣ�
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] Rateval ֡�ʣ���Χ1-25
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetVideoFrameRate(VzLPRClientHandle handle, int Rateval);//1-25

/**
*  @brief ��ȡ������ѹ��ģʽ��
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] modeval ���VZDEV_VIDEO_COMPRESS_�궨��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetVideoCompressMode(VzLPRClientHandle handle, int *modeval);//VZDEV_VIDEO_COMPRESS_XXX

/**
*  @brief ����������ѹ��ģʽ��
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] modeval ���VZDEV_VIDEO_COMPRESS_�궨��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetVideoCompressMode(VzLPRClientHandle handle, int modeval);//VZDEV_VIDEO_COMPRESS_XXX


/**
*  @brief ��ȡ�����������ʣ�
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] rateval ��ǰ��Ƶ������
*  @param [OUT] ratelist ��ʱ����
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetVideoCBR(VzLPRClientHandle handle, int *rateval/*Kbps*/, int *ratelist);

/**
*  @brief ���������������ʣ�
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] rateval ��ǰ��Ƶ������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetVideoCBR(VzLPRClientHandle handle, int rateval/*Kbps*/);

/**
*  @brief ��ȡ������Ƶ��ʾģʽ
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] pDrawMode ��ʾģʽ���ο�VZ_LPRC_DRAWMODE
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetDrawMode(VzLPRClientHandle handle, VZ_LPRC_DRAWMODE * pDrawMode);

/**
*  @brief ����������Ƶ��ʾģʽ
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pDrawMode ��ʾģʽ���ο�VZ_LPRC_DRAWMODE
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetDrawMode(VzLPRClientHandle handle, VZ_LPRC_DRAWMODE * pDrawMode);

/**
*  @brief ��ȡ��Ƶ������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] brt ����
*  @param [OUT] cst �Աȶ�
*  @param [OUT] sat ���Ͷ�
*  @param [OUT] hue ɫ��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetVideoPara(VzLPRClientHandle handle, int *brt, int *cst, int *sat, int *hue);

/**
*  @brief ������Ƶ������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] brt ����
*  @param [IN] cst �Աȶ�
*  @param [IN] sat ���Ͷ�
*  @param [IN] hue ɫ��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetVideoPara(VzLPRClientHandle handle, int brt, int cst, int sat, int hue);

/**
*  @brief ����ͨ�����������뷽ʽ
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] cmd    ���صı��뷽ʽ, 0->H264  1->MPEG4  2->JPEG  ����->����
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetVideoEncodeType(VzLPRClientHandle handle, int cmd);

/**
*  @brief ��ȡ��Ƶͼ��������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] levelval //0~6��6���
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetVideoVBR(VzLPRClientHandle handle, int *levelval);

/**
*  @brief ������Ƶͼ��������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] levelval //0~6��6���
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetVideoVBR(VzLPRClientHandle handle, int levelval);


/**
*  @brief ��ȡ��Ƶ��ʽ��
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] frequency 0:MaxOrZero, 1: 50Hz, 2:60Hz
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetFrequency(VzLPRClientHandle handle, int *frequency);

/**
*  @brief ������Ƶ��ʽ��
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] frequency 0:MaxOrZero, 1: 50Hz, 2:60Hz
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetFrequency(VzLPRClientHandle handle, int frequency);

/**
*  @brief ��ȡ�ع�ʱ�䣻
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] shutter 2:>0~8ms ͣ�����Ƽ�, 3: 0~4ms, 4:0~2ms �����Ƽ�
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetShutter(VzLPRClientHandle handle, int *shutter);

/**
*  @brief �����ع�ʱ�䣻
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] shutter 2:>0~8ms ͣ�����Ƽ�, 3: 0~4ms, 4:0~2ms �����Ƽ�
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetShutter(VzLPRClientHandle handle, int shutter);

/**
*  @brief ��ȡͼ��ת��
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] flip, 0: ԭʼͼ��, 1:���·�ת, 2:���ҷ�ת, 3:���ķ�ת
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetFlip(VzLPRClientHandle handle, int *flip);

/**
*  @brief ����ͼ��ת��
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] flip, 0: ԭʼͼ��, 1:���·�ת, 2:���ҷ�ת, 3:���ķ�ת
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetFlip(VzLPRClientHandle handle, int flip);


/**
*  @brief ���ó���ʶ�𴥷��ӳ�ʱ��
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] nDelay �����ӳ�ʱ��,ʱ�䷶Χ[0, 10000)
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetTriggerDelay(VzLPRClientHandle handle, int nDelay);

/**
*  @brief ��ȡ����ʶ�𴥷��ӳ�ʱ��
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [OUT] nDelay �����ӳ�ʱ��,ʱ�䷶Χ[0, 10000)
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetTriggerDelay(VzLPRClientHandle handle, int* nDelay);

/**
*  @brief ���ð�������֤ģʽ
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] nType 0 �ѻ��Զ�����;1 ����;2 ������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetWLCheckMethod(VzLPRClientHandle handle, int nType);

/**
*  @brief ��ȡ��������֤ģʽ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT]	nType 0 �ѻ��Զ�����;1 ����;2 ������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetWLCheckMethod(VzLPRClientHandle handle, int* nType);

/**
*  @brief ���ð�����ģ��ƥ��
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] nFuzzyType 0  ��ȷƥ��;1 �����ַ�ƥ��;2 ��ͨ�ַ�ģ��ƥ��
*  @param [IN] nFuzzyLen  ������ʶ�𳤶�
*  @param [IN] nFuzzyType ���Ժ���
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetWLFuzzy(VzLPRClientHandle handle, int nFuzzyType, int nFuzzyLen, bool bFuzzyCC);

/**
*  @brief ��ȡ������ģ��ƥ��
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] nFuzzyType 0  ��ȷƥ��;1 �����ַ�ƥ��;2 ��ͨ�ַ�ģ��ƥ��
*  @param [IN] nFuzzyLen  ������ʶ�𳤶�
*  @param [IN] nFuzzyType ���Ժ���
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetWLFuzzy(VzLPRClientHandle handle, int* nFuzzyType, int* nFuzzyLen, bool* bFuzzyCC);

/**
*  @brief �����������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pOutputConfig �������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetOutputConfig(VzLPRClientHandle handle, VZ_OutputConfigInfo* pOutputConfigInfo);

/**
*  @brief ��ȡ�������0
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pOutputConfig �������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetOutputConfig(VzLPRClientHandle handle, VZ_OutputConfigInfo* pOutputConfigInfo);

/**
*  @brief ��ȡ�豸���кţ�
*  @param [IN] ip ipͳһʹ���ַ�������ʽ����
*  @param [IN] port ʹ�ú͵�¼ʱ��ͬ�Ķ˿�
*  @param [OUT] SerHi ���кŸ�λ
*  @param [OUT] SerLo ���кŵ�λ
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetSerialNo(char *ip, WORD port, unsigned int *SerHi, unsigned int *SerLo);

/**
*  @brief ��ʼʵʱͼ��������������ʵʱ��ȡͼ������
*  @param  [IN] handle		��VzLPRClient_Open������õľ��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_StartRealPlayDecData(VzLPRClientHandle handle);

/**
*  @brief ֹͣʵʱͼ��������
*  @param  [IN] handle		��VzLPRClient_Open������õľ��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_StopRealPlayDecData(VzLPRClientHandle handle);


/**
*  @brief �ӽ������л�ȡJPEGͼ�񣬱��浽ָ���ڴ�
*  @param  [IN] handle		��VzLPRClient_Open������õľ��
*  @param  [IN/OUT] pDstBuf JPEG���ݵ�Ŀ�Ĵ洢�׵�ַ
*  @param  [IN] uSizeBuf JPEG���ݵ�ַ���ڴ�����ߴ磻
*  @param  [IN] nQuality JPEGѹ����������ȡֵ��Χ1~100��
*  @return >0��ʾ�ɹ����������ĳߴ磬-1��ʾʧ�ܣ�-2��ʾ������ѹ�����ݵ��ڴ�ߴ粻����
*  @ingroup group_global
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetJpegStreamFromRealPlayDec(VzLPRClientHandle handle, void *pDstBuf, unsigned uSizeBuf, int nQuality);

/**
*  @brief ��ȡ������������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pConfigInfo ������������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetRS485PushConfig(VzLPRClientHandle handle, VZ_RS485_Config* pConfigInfo);

/**
*  @brief ���ô�����������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pConfigInfo ������������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetRS485PushConfig(VzLPRClientHandle handle, VZ_RS485_Config* pConfigInfo);


/**
*  @brief aes���ܹ���
*  @param [IN] hertextb    ������16���Ƶ�����
*  @param [IN] password    ����
*  @param [IN] nTextBits   ���ݳ���
*  @param [IN] decryptText �����ַ���
*  @param [IN] decryptLen  ��������ַ���buffer�ĳ���
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_AesCtrDecrypt(const char* hertextb, int nTextBits, const char* password, char *decryptText, int decryptLen);

/**
*  @brief ����ID��ȡ��������Ĵ�ͼƬ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] id     ���Ƽ�¼��ID
*  @param  [IN] sn     �豸���к�
*  @param  [IN] pdata  �洢ͼƬ���ڴ�
*  @param  [IN][OUT] size Ϊ���봫��ֵ������ΪͼƬ�ڴ�Ĵ�С�����ص��ǻ�ȡ��jpgͼƬ�ڴ�Ĵ�С
*  @return ����ֵΪ0��ʾ�ɹ�������-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_LoadGroupFullImageById(VzLPRClientHandle handle, int id, const char* sn, void* pdata, int* size);

/**
*  @brief ����ID��ȡ���������СͼƬ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] id     ���Ƽ�¼��ID
*  @param  [IN] sn     �豸���к�
*  @param  [IN] pdata  �洢ͼƬ���ڴ�
*  @param  [IN][OUT] size Ϊ���봫��ֵ������ΪͼƬ�ڴ�Ĵ�С�����ص��ǻ�ȡ��jpgͼƬ�ڴ�Ĵ�С
*  @return ����ֵΪ0��ʾ�ɹ�������-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_LoadGroupClipImageById(VzLPRClientHandle handle, int id, const char* sn, void* pdata, int* size);

/**
*  @brief ��ȡNTP����
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] ntp_server_name ��������ַ
*  @param [IN] name_size ��������ַ����������
*  @param [OUT] ntp_enable �Ƿ�����NTP
*  @param [OUT] frequency_time ͬ����ʱ��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetNtpConfig(VzLPRClientHandle handle, char* ntp_server_name, int name_size, bool* ntp_enable, int* frequency_time);

/**
*  @brief ����NTP����
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] ntp_server_name ��������ַ
*  @param [IN] ntp_enable �Ƿ�����NTP
*  @param [IN] frequency_time ͬ����ʱ��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetNtpConfig(VzLPRClientHandle handle, const char* ntp_server_name, bool ntp_enable, int frequency_time);


/**
*  @brief ��ʼ���ε�¼
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pData ������Ϣ
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_StartLogin(VzLPRClientHandle handle, VZ_LPRC_ACTIVE_ENCRYPT* pData);


/**
*  @brief ִ�ж��ε�¼
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] key �û�����
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_LoginAuth(VzLPRClientHandle handle, const char* key);

/**
*  @brief ����
*  @brief ��
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] key �û�����
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_OpenAuth(const char *pStrIP, WORD wPort, const char *pStrUserName, const char *pStrPassword, const char* key);


/**
*  @brief ���õ�ǰ����ΪĬ������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetUserDefaultCfg(VzLPRClientHandle handle);


/**
*  @brief �������Ź���
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] voice ���ŵ���������
*  @param [IN] interval �����ļ��Ĳ��ż��(0-5000)ms
*  @param [IN] volume ������С(0-100)
*  @param [IN] male ��������(����0��Ů��1)
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_PlayVoice(VzLPRClientHandle handle, const char *voice, int interval, int volume, int male);

/**
*  @brief ������������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] interval �����ļ��Ĳ��ż��(0-5000)
*  @param [IN] volume ������С(0-100)
*  @param [IN] male ��������(����0��Ů��1)
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetVoiceConfig(VzLPRClientHandle handle, int interval, int volume, int male);


/**
*  @brief ������������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] interval �����ļ��Ĳ��ż��(0-5000)
*  @param [OUT] volume ������С(0-100)
*  @param [OUT] male ��������(����0��Ů��1)
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetVoiceConfig(VzLPRClientHandle handle, int* interval, int* volume, int* male);


//**************************************************************
// ���ķ���������
/**
*  @brief �������ķ���������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pCenterServerNet  ���ķ�������Ϣ�ṹ
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/

VZ_LPRC_API int __STDCALL VzLPRClient_SetCenterServerNet(VzLPRClientHandle handle, VZ_LPRC_CENTER_SERVER_NET * pCenterServerNet);

/**
*  @brief ��ȡ���ķ���������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pCenterServerNet  ���ķ�������Ϣ�ṹ
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetCenterServerNet(VzLPRClientHandle handle, VZ_LPRC_CENTER_SERVER_NET * pCenterServerNet);

/**
*  @brief �������ķ������豸ע��
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pCenterServerDeviceReg  ���ķ�����ע��ṹ
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetCenterServerDeviceReg(VzLPRClientHandle handle, VZ_LPRC_CENTER_SERVER_DEVICE_REG * pCenterServerDeviceReg);

/**
*  @brief ��ȡ���ķ������豸ע��
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pCenterServerDeviceReg  ���ķ�����ע��ṹ
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetCenterServerDeviceReg(VzLPRClientHandle handle, VZ_LPRC_CENTER_SERVER_DEVICE_REG * pCenterServerDeviceReg);


/**
*  @brief �������ķ��������糵��������Ϣ
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pCenterServerPlate  ���ķ���������������Ϣ
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetCenterServerPlate(VzLPRClientHandle handle, VZ_LPRC_CENTER_SERVER_PLATE * pCenterServerPlate);

/**
*  @brief ��ȡ���ķ��������糵��������Ϣ
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pCenterServerPlate  ���ķ���������������Ϣ
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetCenterServerPlate(VzLPRClientHandle handle, VZ_LPRC_CENTER_SERVER_PLATE * pCenterServerPlate);

/**
*  @brief �������ķ���������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pCenterServerNet  ���ķ�������Ϣ
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetCenterServerGionin(VzLPRClientHandle handle, VZ_LPRC_CENTER_SERVER_GIONIN * pCenterServerGionin);

/**
*  @brief ��ȡ���ķ���������˿ڴ�����Ϣ
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pCenterServerGionin  ���ķ������˿ڴ�����Ϣ
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetCenterServerGionin(VzLPRClientHandle handle, VZ_LPRC_CENTER_SERVER_GIONIN * pCenterServerGionin);

/**
*  @brief �������ķ��������紮����Ϣ
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pCenterServerSerial  ���ķ�����������Ϣ
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetCenterServerSerial(VzLPRClientHandle handle, VZ_LPRC_CENTER_SERVER_SERIAL * pCenterServerSerial);

/**
*  @brief ��ȡ���ķ��������紮����Ϣ
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pCenterServerSerial  ���ķ�����������Ϣ
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetCenterServerSerial(VzLPRClientHandle handle, VZ_LPRC_CENTER_SERVER_SERIAL * pCenterServerSerial);

/**
*  @brief �������ķ�������������������Ϣ
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pCenterServerHostBak  ���ķ���������������Ϣ  ����:"192.168.3.5;192.168.3.6"
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetCenterServerHostBak(VzLPRClientHandle handle,  char * pCenterServerHostBak);

/**
*  @brief ��ȡ���ķ�������������������Ϣ
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pCenterServerHostBak  ���ķ���������������Ϣ  ����:"192.168.3.5;192.168.3.6"
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetCenterServerHostBak(VzLPRClientHandle handle,  char * pCenterServerHostBak);

//**************************************************************
// �豸��Чʱ��
/**
*  @brief �����豸��Чʱ��
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] status  0 �������ʱ����Ҳ�����豸���Բ�����ʱ���ʹ�á�1 �����ʱ����
*  @param [IN] active_time �������һ������Ϊ��λ�ĳ�ʱʱ�䡣��� active_status �����˳�ʱ����Ļ�����ô�����豸���У����ʱ����𲽼��٣�
*              ֱ��Ϊ0 ����ô�豸�ͻ᲻�ٶ����������ʶ�����ˡ�
*  @param [IN] pCurrentKey ��ǰʶ������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetDeviceActiveStatus( VzLPRClientHandle handle, int status, int times, const char* pCurrentKey );


/**
*  @brief ��ȡ�豸��Чʱ��
*  @param [IN]  handle ��VzLPRClient_Open������õľ��
*  @param [OUT] status  0 �������ʱ����Ҳ�����豸���Բ�����ʱ���ʹ�á�1 �����ʱ����
*  @param [OUT] active_time �������һ������Ϊ��λ�ĳ�ʱʱ�䡣��� active_status �����˳�ʱ����Ļ�����ô�����豸���У����ʱ����𲽼��٣�
*               ֱ��Ϊ0 ����ô�豸�ͻ᲻�ٶ����������ʶ�����ˡ�
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetDeviceActiveStatus( VzLPRClientHandle handle, int* status, int* times );


/**
*  @brief ��ȡ�豸Ӳ����Ϣ
*  @param [IN]  handle ��VzLPRClient_Open������õľ��
*  @param [OUT] board_version  �豸����
*  @param [OUT] exdataSize �������ݳ��ȡ�
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetHwBoardVersion( VzLPRClientHandle handle, int* board_version, long long* exdataSize );


/**
*  @brief ��ȡ�豸Ӳ������
*  @param [IN]  handle ��VzLPRClient_Open������õľ��
*  @param [OUT] board_type  �豸����(0:3730,1:6446,2:8127)
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetHwBoardType( VzLPRClientHandle handle, int* board_type );


/**
*  @brief ��ȡ���⳵������
*  @param [IN]  handle ��VzLPRClient_Open������õľ��
*  @param [OUT] pCfgBuf�������� 
*  @param [IN] �������ݵĳ���
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetSpecialPlatesCfg(VzLPRClientHandle handle, char* pCfgBuf, int len);

/**
*  @brief �������⳵������
*  @param [IN]  handle ��VzLPRClient_Open������õľ��
*  @param [IN] pCfgBuf��������
*  @param [IN] len�������ݳ���
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetSpecialPlatesCfg(VzLPRClientHandle handle, char* pCfgBuf, int len);

/**
*  @brief ��ȡ�������Ʋ���
*  @param [IN] iUserID VZC_Login�������ص��û�ID
*  @param [OUT] comp_enable���ñ�����
*  @param [OUT] ivt_time�����ӳ�ʱ��
*  @param [OUT] dealy_time��������ʱ�� 
*  @param [OUT] dealy_out_time�����ӳ�ʱ��
*  @param [OUT] gpio_in�ظ������
*  @param [IN]  in_count���ݳ���
*  @param [OUT] gpio_out�������ƿ�
*  @param [IN]  out_count���ݳ���
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetLedComplensating(VzLPRClientHandle handle, bool* comp_enable, int* ivt_time, int* dealy_time, int* dealy_out_time, char* gpio_in, int in_count, char* gpio_out, int out_count);

/**
*  @brief ���ñ������Ʋ���
*  @param [IN] iUserID VZC_Login�������ص��û�ID
*  @param [IN] comp_enable���ñ�����
*  @param [IN] ivt_time�����ӳ�ʱ��
*  @param [IN] dealy_time��������ʱ�� 
*  @param [IN] dealy_out_time�����ӳ�ʱ��
*  @param [IN] gpio_in�ظ������
*  @param [IN]  in_count���ݳ���
*  @param [IN] gpio_out�������ƿ�
*  @param [IN]  out_count���ݳ���
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetLedComplensating(VzLPRClientHandle handle, bool comp_enable, int ivt_time, int dealy_time, int dealy_out_time, char* gpio_in, int in_count, char* gpio_out, int out_count);


/**
*  @brief ��ȡͼ����ǿ����
*  @param [IN]  handle ��VzLPRClient_Open������õľ��
*  @param [OUT] mode  �豸����
*  @param [OUT] strength �������ݳ��ȡ�
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetDenoise( VzLPRClientHandle handle, int *mode, int *strength );


/**
*  @brief ����ͼ����ǿ����
*  @param [IN]  handle ��VzLPRClient_Open������õľ��
*  @param [OUT] mode  �豸����
*  @param [OUT] strength �������ݳ��ȡ�
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetDenoise( VzLPRClientHandle handle, int mode, int strength );


/**
*  @brief ���ݾ����ȡ�豸��IP
*  @param [IN]  handle ��VzLPRClient_Open������õľ��
*  @param [OUT] ip  �豸ip
*  @param [IN] max_count ����IP buffer�ĳ��ȡ�
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetDeviceIP( VzLPRClientHandle handle, char* ip, int max_count );

/**
*  @brief ����ץͼ���ݵ�������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pDstBuf ����ͼƬ�Ļ�����
*  @param [IN] uSizeBuf ����ͼƬ�Ļ��������ȣ�Ҫ�����BUF��С��С��200k�����򷵻�ʧ�ܡ�
*  @return ����ֵΪ����0��ʾͼƬ�ĳ��ȣ���������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetSnapImageToBuf(VzLPRClientHandle handle, void  *pDstBuf, int  uSizeBuf);


/**
*  @brief ��ȡ�������ֱ��ʣ�
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] sizeval 
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetVideoFrameSizeIndexEx(VzLPRClientHandle handle, int *sizeval);

/**
*  @brief �����������ֱ��ʣ�
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] sizeval 
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetVideoFrameSizeIndexEx(VzLPRClientHandle handle, int sizeval);

/**
*  @brief �����Զ��䱶�Ĺ���
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @return ����ֵ������ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ��
*/
VZ_LPRC_API int __STDCALL VzLPRClient_DoFastFocus(VzLPRClientHandle handle);

/**
*  @brief ͨ���ûص��������TCp serverͨ��������������
*  @param  [IN] handle		��VzLPRClient_Open������õľ��
*  @param  [IN] pUserData	�ص�����������
*  @param  [IN] pData		���ݵ�����
*  @param  [IN] dataLen	    ���ݳ���
*  @ingroup 
*/
typedef void (__STDCALL *VZLPRC_TCPSERVER_RECV_CALLBACK)(VzLPRClientHandle handle, const char* pData,int dataLen,void *pUserData);

/**
*  @brief ����tcpserverͨ�����ݵ����ݻص�
*  @param [IN]  handle ��VzLPRClient_Open������õľ��
*  @param [IN] pCfgBuf��������
*  @param [IN] len�������ݳ���
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetTcpServerRecvCallBack(VzLPRClientHandle handle,VZLPRC_TCPSERVER_RECV_CALLBACK func, void *pUserData);


/**
*  @brief ע��tcpserverͨ��(�����յ�TCp���ص�����)
*  @param [IN]  handle ��VzLPRClient_Open������õľ��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_RegisterTcpServerChannal( VzLPRClientHandle handle);

/**
*  @brief ��TCPServerͨ����������
*  @param [IN]  handle ��VzLPRClient_Open������õľ��
*  @param [IN] pData  ��tcp���͵�����
*  @param [IN] len    ���͵����ݳ���
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SendTcpServerData( VzLPRClientHandle handle,void* pData, int len);

/**
*  @brief ����
*  @brief �������"������"��ʶ���¼�Ļص�����
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] func ʶ�����ص����������ΪNULL�����ʾ�رոûص������Ĺ���
*  @param  [IN] pUserData �ص������е�������
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetDisconnectPlatesCallBack(VzLPRClientHandle handle, VZLPRC_PLATE_INFO_CALLBACK func, void *pUserData);


/**
*  @brief ����
*  @brief ��ȡ"������"��ʶ���¼
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   ���߼�¼�Ķ��壺  ���ȿͻ��˵���VzLPRClient_SetOfflineCheck�ӿ�������γɰ󶨡�����ͻ��������֮������������SDK�յ�ʶ�������������ظ�һ����Ϣ������յ���Ϣ�󣬻��������"���Ƽ�¼"���ݿ��н�������¼���Ϊ"����"��
*  @note   �����߼�¼�Ķ��壺"���Ƽ�¼"���ݿ���û�аѼ�¼���Ϊ"����"״̬�ļ�¼����Ϊ"������"�ļ�¼�������¼��������
1. �ͻ���û�е���VzLPRClient_SetOfflineCheck����ӿڣ����е�ʶ���¼��������Ϊ"����"��
2. �ͻ��˵�����VzLPRClient_SetOfflineCheck����ӿڣ����ǿͻ����������������쳣ʱ���ͻ���û�н��յ�ʶ�����������Ѿ����յ����������SDK������ظ���Ϣ�����û���յ�����ʱ�����������¼���Ϊ"����"��
3. �ͻ��˳�����������߹رյ��ͻ��ˡ����еļ�¼��������Ϊ"����"��

*  @note   ʹ������ӿڿ��ܳ��ֵ������
1. ���������Ա���12������¼�����֮ǰ�ͻ���û�е����VzLPRClient_SetOfflineCheck�ӿڻ���һֱ���ѻ����У�ʹ������ӿڿ����������12�������Ƽ�¼��
2. ����ͻ����Ѿ��յ�ʶ����������SDK������ظ���Ϣ�����û���յ���������¼�ı����"������"���ᵼ�³��Ƽ�¼�����ظ������������������ֳ����粻�ȶ��������ż������֡������ڿͻ��˵����ݿⱣ�泵�Ƽ�¼id,����id�������ظ����ݡ�
3. �ص�һ�����һ�����ݣ�����������100�����ݡ�ȡ��100�����ݺ󣬻��������100�����ݡ���������ߵļ�¼�϶࣬�������Ứ�ϳ�ʱ�䡣

*  @note   �ӿڲ�����������ʹ"������"��¼�ܶ������¡�
*  @note   ���ú��������"������"�ļ�¼�����ڿͻ���������ʱ����á�֮���ٲ���"������"��¼���������������Ҫ���µ�������ӿڡ�
*  @return ����ֵΪ0��ʾ�ɹ�������-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_LoadDisconnectPlates(VzLPRClientHandle handle);

/**
*  @brief ��ȡR����ı��������
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] iChannel ͨ����
*  @param [IN] stream 0������ 1������
*  @param [OUT] param �������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_RGet_Encode_Param(VzLPRClientHandle handle, int stream, VZ_LPRC_R_ENCODE_PARAM *param);

/**
*  @brief ����R����ı��������
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] iChannel ͨ����
*  @param [IN] stream 0������ 1������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_RSet_Encode_Param(VzLPRClientHandle handle, int stream, VZ_LPRC_R_ENCODE_PARAM *param);

/**
*  @brief ��ȡR���֧�ֵı��������
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] iChannel ͨ����
*  @param [IN] stream 0������ 1������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_RGet_Encode_Param_Property(VzLPRClientHandle handle, VZ_LPRC_R_ENCODE_PARAM_PROPERTY *param);


/**
*  @brief ��ȡR�������Ƶ������
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] param ��Ƶ����
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_RGet_Video_Param(VzLPRClientHandle handle, VZ_LPRC_R_VIDEO_PARAM *param);

/**
*  @brief ��ȡR�������Ƶ������
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] iChannel ͨ����
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_RSet_Video_Param(VzLPRClientHandle handle, VZ_LPRC_R_VIDEO_PARAM *param);


/**
*  @brief ��ȡX����״̬
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] status����״̬
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_XGet_RegistrationStatusParam(VzLPRClientHandle handle, int *status);

/**
*  @brief ����X�����׼����
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] request_status(0����ʼ������׼�ļ�,1����ʼУ����׼�ļ�)
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_XSet_RegistrationParam(VzLPRClientHandle handle, int request_status);


/**
*  @brief ������ʽ��У��ģ��
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] distance 3x3���̸���������Ǿ��룬�Ժ���Ϊ��λ
*  @param [IN] deltax ƥ����������Ϊ��λ
*  @param [IN] error_ratio �������������ٷֱ�
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_XSet_ModelCheckStatus(VzLPRClientHandle handle, int distance, float deltax, float error_ratio);

/**
*  @brief ��ȡ��ʽ��У��ģ��״̬
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] status   s-3 : û���ҵ�ģ�ͣ�������׼�� -2 : û���ҵ����̸񣨵��������̬��-1 : ģ�Ͳ�����׼ȷ��������׼��0:δ��ʼ 1:ģ�Ͳ���׼ȷ��PASS�� 2: У����
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_XGet_ModelCheckStatus(VzLPRClientHandle handle, int* status);

/**
*  @brief ��ȡ�豸Ӳ����Ϣ
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] oem_info ������Ϣ
*  @param [IN]  oem_len  ������Ϣ����,���Ȳ�С��8
*  @param [OUT] company_info ��˾��Ϣ
*  @param [IN]  company_len ��˾��Ϣ���ȣ����Ȳ�С��32
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetOEMInfo(VzLPRClientHandle handle, char* oem_info, int oem_len, char* company_info, int company_len);

/**
*  @brief ����x���˫Ŀͼ���л�
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] image_mode  ģʽ��0���  1����
*  @param [IN] small_image ����Сͼ 1���ӣ�����ֵ������
*  @param [IN] deep_image  �������ͼ 1���ӣ�����ֵ������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_XSet_ImgModePrm(VzLPRClientHandle handle, int image_mode, int small_image, int deep_image);

/**
*  @brief ��ȡx���˫Ŀͼ���л�
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] image_mode  ģʽ��0���  1����
*  @param [OUT] small_image ����Сͼ 1���ӣ�����ֵ������
*  @param [OUT] deep_image  �������ͼ 1���ӣ�����ֵ������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_XGet_ImgModePrm(VzLPRClientHandle handle, int* image_mode, int* small_image, int* deep_image);


/**
*  @brief ���Flash���������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_CleanFlash(VzLPRClientHandle handle);


/**
*  @brief ����͸��ͨ��(64λ�ӿ�)
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] nSerialPort ָ��ʹ���豸�Ĵ�����ţ�0��ʾ��һ�����ڣ�1��ʾ�ڶ�������
*  @param  [IN] func �������ݵĻص�����
*  @param  [IN] pUserData �������ݻص�������������
*  @return ����͸��ͨ�������0��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API long long __STDCALL VzLPRClient_SerialStart_V2(VzLPRClientHandle handle, int nSerialPort,
	VZDEV_SERIAL_RECV_DATA_CALLBACK func, void *pUserData);
/**
*  @brief ͸��ͨ����������(64λ�ӿ�)
*  @param [IN] nSerialHandle ��VzLPRClient_SerialStart������õľ��
*  @param [IN] pData ��Ҫ��������ݿ���׵�ַ
*  @param [IN] uSizeData ��Ҫ��������ݿ���ֽ���
*  @return 0��ʾ�ɹ�������ֵ��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SerialSend_V2(long long nSerialHandle, const unsigned char *pData, unsigned uSizeData);

/**
*  @brief ͸��ͨ��ֹͣ��������(64λ�ӿ�)
*  @param [IN] nSerialHandle ��VzLPRClient_SerialStart������õľ��
*  @return 0��ʾ�ɹ�������ֵ��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SerialStop_V2(long long nSerialHandle);

/**
*  @brief ����ʱ��ͳ��ƺŲ�ѯ��¼����
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] count ��¼���� ���ڵ���1��С�ڵ���100
*  @return ����ֵΪ0��ʾʧ�ܣ�����0��ʾ��¼����
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_QueryNearestCountRecord(VzLPRClientHandle handle, int count);

/**
*  @brief ��ʼ����
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @parmm [IN] client_win_size �ͻ��˴��ڴ�С
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_StartTalk(VzLPRClientHandle handle, int client_win_size);

/**
*  @brief �����㲥��Ϣ
*  @param [OUT] state ״ֵ̬
*  @param [OUT] error_msg	������Ϣ
*  @param [OUT] pUserData �û��Զ�������
*/
typedef void (__STDCALL *VZLPRC_REQUEST_TALK_CALLBACK)(VzLPRClientHandle handle, int state, const char* error_msg, void* pUserData);

/**
*  @brief ����GPIO����ص�����
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] func GPIO����ص�����
*  @param [IN] pUserData �û��Զ�������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetRequestTalkCallBack(VzLPRClientHandle handle, VZLPRC_REQUEST_TALK_CALLBACK func, void* pUserData);


/**
*  @brief ֹͣ����
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @parmm [IN] device_ip �豸IP
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_StopTalk(VzLPRClientHandle handle);


/**
*  @brief ��ʼ¼��
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @parmm [IN] file_path ��Ƶ�ļ�·��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_StartRecordAudio(VzLPRClientHandle handle, const char* file_path);


/**
*  @brief ֹͣ¼��
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_StopRecordAudio(VzLPRClientHandle handle);


/**
*  @brief ��ȡ�����汾�����װ����
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] reco_dis��װ���� 0:2-4��, 2: 4-6��, 1: 6-8��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetAlgResultParam(VzLPRClientHandle handle, int* reco_dis);


/**
*  @brief ���ö����汾�����װ����
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] reco_dis��װ���� 0:2-4��, 2: 4-6��, 1: 6-8��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetAlgResultParam(VzLPRClientHandle handle, int reco_dis);


/**
*  @brief LED����
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] ctrl_param���Ʋ���
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetLedCtrl(VzLPRClientHandle handle, VZ_LPRC_CTRL_PARAM* ctrl_param);

/**
*  @brief ��ȡLED���Ʋ���
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] ctrl_param���Ʋ���
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetLedCtrl(VzLPRClientHandle handle, VZ_LPRC_CTRL_PARAM* ctrl_param);

/**
*  @brief ����x�����OSD����
*  @param [IN] iUserID VZC_Login�������ص��û�ID
*  @param [IN] iChannel ͨ����
*  @param [IN] pParam  OSD����
*  @param [IN] pShowParam  ��ʾ�Ĳ���
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_XSet_OSDParam(VzLPRClientHandle handle, VZ_LPRC_OSD_Param *pParam, VZ_LPRC_REALTIME_SHOW_PARAM* pShowParam);

/**
*  @brief ��ȡx�����OSD����
*  @param [IN] iUserID VZC_Login�������ص��û�ID
*  @param [IN] iChannel ͨ����
*  @param [IN] pParam  OSD����
*  @param [IN] pShowParam  ��ʾ�Ĳ���
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_XGet_OSDParam(VzLPRClientHandle handle, VZ_LPRC_OSD_Param *pParam, VZ_LPRC_REALTIME_SHOW_PARAM* pShowParam);

/**
*  @brief ��ȡ�豸Ӳ����Ϣ
*  @param [IN] ip ipͳһʹ���ַ�������ʽ����
*  @param [IN] port ʹ�ú͵�¼ʱ��ͬ�Ķ˿�
*  @param [OUT] status ״̬ 0 û��ȡ��Ӳ����Ϣ��1�л�����Ϣ��2�л�������չ��Ϣ
*  @param [OUT] mac ���mac��ַ�������ַ������峤������Ϊ20
*  @param [OUT] serialno ������кţ������ַ������峤������Ϊ20
*  @param [OUT] device_type �豸���ͣ��ο�IVS_TYPE����
*  @param [OUT] pdata_ex ��չӲ����Ϣ���ο�VZ_FS_INFO_EX����
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetHwInfoEx( const char *ip, WORD port, int* status, char* mac, char* serialno,int *device_type,VZ_FS_INFO_EX *pdata_ex);

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
VZ_LPRC_API VzLPRClientHandle __STDCALL VzLPRClient_OpenV2(const char *pStrIP, WORD wPort, const char *pStrUserName, const char *pStrPassword,WORD wHttpPort, int network_type, char* sn);


/**
*  @brief ��һ���豸V4
*  @param  [IN] pLoginParam ��¼��Ϣ����
*  @return �����豸�Ĳ������������ʧ��ʱ������0
*  @ingroup group_device
*/
VZ_LPRC_API VzLPRClientHandle __STDCALL VzLPRClient_OpenV4(VZ_LPRC_LOGIN_PARAM * pLoginParam);

/**
*  @brief �����ػ����� 
*  @param [IN] iUserID VZC_Login�������ص��û�ID
*  @param [IN] control  //1����ʼ�ػ���0�������ػ�
*  @param [IN] pShowParam  ��ʾ�Ĳ���
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetRecycleControl(VzLPRClientHandle handle, int control);

/**
*  @brief ��ȡ�豸���ƣ�
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] name �豸��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetDeviceName(VzLPRClientHandle handle, char *name);

/**
*  @brief �����豸���ƣ�
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] name  �豸��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetDeviceName(VzLPRClientHandle handle, const char *name);

/**
*  @brief ����IO��������Զ���λ[�˽ӿڻ�ȴ���������Ƿ�բ�ɹ�]
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] uChnId IO�����ͨ���ţ���0��ʼ
*  @param  [IN] nDuration ��ʱʱ�䣬ȡֵ��Χ[500, 5000]����
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetIOOutputAutoResp(VzLPRClientHandle handle, unsigned uChnId, int nDuration);

/**
*  @brief �����û��Զ���OSD����(֧������)
*  @param [IN] iUserID VZC_Login�������ص��û�ID
*  @param [IN] iChannel ͨ����
*  @param [IN] pOsdParam �û��Զ���osd����
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetUserOsdParam(VzLPRClientHandle handle, VZ_LPRC_USER_OSD_PARAM* pOsdParam);

/**
*  @brief ��ȡ�û��Զ���OSD����(֧������)
*  @param [IN] iUserID VZC_Login�������ص��û�ID
*  @param [IN] iChannel ͨ����
*  @param [OUT] pOsdParam �û��Զ���osd����
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetUserOsdParam(VzLPRClientHandle handle, VZ_LPRC_USER_OSD_PARAM* pOsdParam);

/**
*  @brief �����û��Զ���OSD����(֧������)
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pOsdParam �û��Զ���osd����
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetUserOsdParamEx(VzLPRClientHandle handle, VZ_LPRC_USER_OSD_EX_PARAM* pOsdParam);

/**
*  @brief ��ȡ�û��Զ���OSD����(֧������)
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] pOsdParam �û��Զ���osd����
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetUserOsdParamEx(VzLPRClientHandle handle, VZ_LPRC_USER_OSD_EX_PARAM* pOsdParam);

/**
*  @brief ����������ʵʱ��Ƶ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] hWnd ���ڵľ��
*  @return ���ŵľ����-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_StartSubStreamRealPlay(VzLPRClientHandle handle, void *hWnd);

/**
*  @brief ����������ʵʱͼ�����ݵĻص�����
*  @param  [IN] handle		��VzLPRClient_Open������õľ��
*  @param  [IN] func		ʵʱͼ�����ݺ���
*  @param  [IN] pUserData	�ص������е�������
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @note   DEPRECATED: ��ת��Ϊʹ��VzLPRClient_StartRealPlayFrameCallBack(handle, NULL, func, pUserData);
*  @ingroup group_device
*/
VZ_DEPRECATED VZ_LPRC_API int __STDCALL VzLPRClient_SetSubStreamVideoFrameCallBack(VzLPRClientHandle handle, VZLPRC_VIDEO_FRAME_CALLBACK func, void *pUserData);

/**
*  @brief ��ȡ�������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] command ��������
*  @param [IN] channel ͨ���ţ�Ĭ��Ϊ0
*  @param [OUT] pOutBuffer ���ص�����
*  @param [IN] dwOutBufferSize ���ݵĳ���
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetCameraConfig(VzLPRClientHandle handle, int command, short channel, void *pOutBuffer, int dwOutBufferSize);

/**
*  @brief �����������
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] command ��������
*  @param [IN] channel ͨ���ţ�Ĭ��Ϊ0
*  @param [IN] pInBuffer ���ص�����
*  @param [IN] dwInBufferSize ���ݵĳ���
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetCameraConfig(VzLPRClientHandle handle, int command, short channel, void *pInBuffer, int dwInBufferSize);

/**
*  @brief  ��ȡ�ƶ��豸mjpeg����url
*  @param  [IN] pStrIP �豸��IP��ַ
*  @param  [IN] wPort �豸�Ķ˿ں�
*  @param  [IN] sn �豸���к�
*  @param  [IN] mjpeg_port ��Ƶ���Ķ˿ں�
*  @param  [OUT] mjpeg_url ���ص�url��ַ
*  @param  [IN] url_len ����url�ĳ���
*  @param  [IN] app_id ��ȫ��֤id
*  @param  [IN] app_key ��ȫ��֤key
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetMjpegURL(const char *pStrIP, WORD wPort, char* sn, WORD mjpeg_port, char* mjpeg_url, int url_len, const char* app_id, const char* app_key);

/**
*  @brief �Ʒ������ӿ�,����appid��email��ȡ�µ�appkey��appid
*  @param  [IN]  deviceip    �Ʒ�������deviceip
*  @param  [IN]  port        �Ʒ�������port
*  @param  [IN]  email       �˺�
*  @param  [IN]  password    ����
*  @param  [OUT] new_appid   �µ�appid
*  @param  [IN]  appid_len   appid����
*  @param  [OUT] new_appkey  �µ�appkey
*  @param  [IN]  appkey_len  appkey����
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_PDNSGetAppKeyAndID(const char *deviceip, int port, const char *email, const char *password, char* new_appid, int appid_len, char* new_appkey, int appkey_len);

/**
*  @brief �Ʒ������ӿ�,���豸
*  @param  [IN] deviceip �Ʒ�������deviceip
*  @param  [IN] port     �Ʒ�������port
*  @param  [IN] email    �˺�
*  @param  [IN] app_id   ��ȫ��֤id
*  @param  [IN] appkey   �˺�
*  @parm   [IN] sn       �豸���к�
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_PDNSBindDevice(const char *deviceip, int port, const char *email, const char* appid, const char *appkey, const char *sn);

/**
*  @brief �Ʒ������ӿ�,��ȡ�˺��µ������豸
*  @param  [IN] deviceip �Ʒ�������deviceip
*  @param  [IN] port     �Ʒ�������port
*  @param  [IN] email    �˺�
*  @param  [IN] app_id   ��ȫ��֤id
*  @param  [IN] appkey   �˺�
*  @parm   [IN] sn       �豸���к�
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_PDNSGetDevice(const char *deviceip, int port, const char *email, const char* appid, const char *appkey, const char *sn, VZ_LPRC_PDNS_DEVICE_LIST *device_list);

/**
*  @brief �Ʒ������ӿ�,��ȡ�˺��µķ�����Ϣ
*  @param  [IN] deviceip �Ʒ�������deviceip
*  @param  [IN] port     �Ʒ�������port
*  @param  [IN] email    �˺�
*  @param  [IN] app_id   ��ȫ��֤id
*  @param  [IN] appkey   �˺�
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_PDNSGetGroup(const char *deviceip, int port, const char *email, const char* appid, const char *appkey, VZ_LPRC_PDNS_GROUP_LIST *group_list);

/**
*  @brief �Ʒ������ӿ�,����group_id��ȡ�豸�б�
*  @param  [IN] deviceip �Ʒ�������deviceip
*  @param  [IN] port     �Ʒ�������port
*  @param  [IN] email    �˺�
*  @param  [IN] app_id   ��ȫ��֤id
*  @param  [IN] appkey   �˺�
*  @parm   [IN] sn       �豸���к�
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_PDNSGetDeviceByGroupID(const char *deviceip, int port, const char *email, const char* appid, const char *appkey, int group_id, VZ_LPRC_PDNS_DEVICE_LIST *device_list);

/**
*  @brief ��ȡ��ƽ̨��IP��˿� 
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] deviceip �豸IP
*  @param [IN]  �����IP�ַ�������P
*  @param [OUT] port �豸�˿�
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_PDNSGetHttpInfo(VzLPRClientHandle handle, char *deviceip, int ip_len, int *port);


/**
*  @brief �Ʒ������ӿ�,���������ȡ�豸
*  @param  [IN] deviceip �Ʒ�������deviceip
*  @param  [IN] port     �Ʒ�������port
*  @param  [IN] app_id   ��ȫ��֤id
*  @param  [IN] appkey   �˺�
*  @parm   [IN] region_name ����
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_PDNSGetRegionDevice(const char *deviceip, int port, const char* appid, const char *appkey, const char *region_name, VZ_LPRC_PDNS_DEVICE_LIST *device_list);


/**
*  @brief ��������ص�����
*  @param [OUT] type ��������
*  @param [OUT] nVal	GPIO����ֵ
*  @param [OUT] pUserData �û��Զ�������
*/
typedef void (__STDCALL *VZLPRC_ALARM_PUSH_CALLBACK)(VzLPRClientHandle handle, int type, const char* content, void* pUserData);

/**
*  @brief ���ñ�������ص�����
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] func ��������ص�����
*  @param [IN] pUserData �û��Զ�������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetAlarmPushCallBack(VzLPRClientHandle handle, VZLPRC_ALARM_PUSH_CALLBACK func, void* pUserData);


/**
*  @brief ����ʵʱ��Ƶ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @return ���ŵľ����-1��ʾʧ��
*  @note   ��Ƶ�����������ţ��Ȳ�����Ƶ������������Ƶ
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_StartPlayAudio(VzLPRClientHandle handle);

/**
*  @brief ֹͣ������Ƶ
*  @param  [IN]handle ��VzLPRClient_Open������õľ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_StopPlayAudio(VzLPRClientHandle handle);


/**
*  @brief ��������
*  @param  [IN]handle ��VzLPRClient_Open������õľ��
*  @param  [IN]level 1,����������������û����ݡ���¼����Ļ���������Ϣ  2, �������������IP��ַ�ȣ� 4, �����û����� 8, ������¼����
*  @param  [IN]user_name �û���
*  @param  [IN]user_pwd ����
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_ParaExport(VzLPRClientHandle handle, int level, const char* user_name, const char* user_pwd);


/**
*  @brief ���������Ļص�����
*  @param [OUT] content     ��������
*  @param [OUT] content_len	���ݳ���
*  @param [OUT] end	�Ƿ����
*  @param [OUT] pUserData �û��Զ�������
*/
typedef void (__STDCALL *VZLPRC_PARA_EXPORT_CALLBACK)(VzLPRClientHandle handle, const char* content, int content_len, int end, void* pUserData);

/**
*  @brief ���ñ�������ص�����
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] func ��������ص�����
*  @param [IN] pUserData �û��Զ�������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetParaExportCallBack(VzLPRClientHandle handle, VZLPRC_PARA_EXPORT_CALLBACK func, void* pUserData);


/**
*  @brief ��������
*  @param  [IN]handle ��VzLPRClient_Open������õľ��
*  @param  [IN]level 1,����������������û����ݡ���¼����Ļ���������Ϣ  2, �������������IP��ַ�ȣ� 4, �����û����� 8, ������¼����
*  @param  [IN]user_name �û���
*  @param  [IN]user_pwd ����
*  @param  [IN]para_data ��������
*  @param  [IN]count ��������
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_ParaImport(VzLPRClientHandle handle, int level, const char* user_name, const char* user_pwd, const char* para_data, int count);

/**
*  @brief  ת������ƽ̨��IP�Ͷ˿ں�
*  @param  [IN]ip   ��ƽ̨��IP��ַ
*  @param  [IN]port ��ƽ̨�Ķ˿ں�
*  @param  [IN]sn   �豸���к�
*  @param  [IN]dest_port Ŀ��˿ں�
*  @param  [OUT]new_ip ͨ����ƽ̨ת����IP��ַ
*  @param  [IN]new_port ͨ����ƽ̨ת���Ķ˿�
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_ConvertPDNSNetworkParam(const char *ip, WORD port, const char* sn, WORD dest_port, char* new_ip, WORD* new_port);

/**
*  @brief  ���¼�����Ȧ��ʶ���������
*  @param  [IN]handle ��VzLPRClient_Open������õľ��
*  @param  [IN]playhandle ���ž��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_ReloadDrawRules(VzLPRClientHandle handle, int playhandle);


/**
*  @brief IO��բ����Ļص�����
*  @param [OUT]handle ��VzLPRClient_Open������õľ��
*  @param [OUT] io_result GPIO����ID
*  @param [OUT] pUserData �û��Զ�������
*/
typedef void (__STDCALL *VZLPRC_IOCTRL_RECV_CALLBACK)(VzLPRClientHandle handle, VZ_IO_RESULT* io_result, void* pUserData);

/**
*  @brief ����IO��բ����Ļص�����
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] func GPIO����ص�����
*  @param [IN] pUserData �û��Զ�������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetIoCtrlRecvCallBack(VzLPRClientHandle handle, VZLPRC_IOCTRL_RECV_CALLBACK func, void* pUserData);

/**
*  @brief ��ȡ�豸��Ϣ��json����
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [OUT] data ���������
*  @param [IN]  data_len ���ݳ���
*  @return ����ֵ����0��ʾ�ɹ�������-2��ʾ������ڴ��С������-1��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetHwInfoData(VzLPRClientHandle handle, char *data, int data_len);

/**
*  @brief ����ID��ȡ���ƺͿ�բ��Ϣ
*  @param  [IN]  handle ��VzLPRClient_Open������õľ��
*  @param  [IN]  ids     ���Ƽ�¼��ID����
*  @param  [OUT] results ���Ƽ�¼�Ϳ�բ���������
*  @param  [IN]  count   ����id�ĸ�������Χ��(1-20)֮��
*  @return ����ֵΪ0��ʾ�ɹ�������-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_QueryPlateIoResultByIDs(VzLPRClientHandle handle, int* ids, VZ_PLATE_IO_RESULT* results, int count);

/**
*  @brief ��ʼ¼����(¼��˽���ļ���ʽ)
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] sFileName ¼���ļ���·��
*  @return ����ֵΪ0��ʾ�ɹ�������-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_StartPVFRecord(VzLPRClientHandle handle,char *sFileName);

/**
*  @brief ֹͣ¼��(¼��˽���ļ���ʽ)
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @return ����ֵΪ0��ʾ�ɹ�������-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzLPRClient_StopPVFRecord(VzLPRClientHandle handle);

/**
*  @brief ����wifi
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] wifi  ������Ϣ
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_LinkWifi(VzLPRClientHandle handle, VZ_LINK_WIFI_INFO *wifi);

/**
*  @brief �ϴ��ļ�
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] file_path �ļ���·��(��d:\\test.wav)
*  @param [IN] type �ϴ��ļ�������(0:�����ļ�, 1�����ļ�, 2�����Դ��)
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_UpdateLoadFile(VzLPRClientHandle handle, const char* file_path, int type);

/**
*  @brief �����ϴ������ļ�
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] file_name �����ļ���(��:test.wav)
*  @param [IN] volumn    ����������С��1-100��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_PlayWavFile(VzLPRClientHandle handle, const char* file_name, int volumn);

/**
*  @brief ��ȡ�ϴ��ļ�״̬)
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @return �ϴ���״̬
*			0: ��δ�ϴ�
*			1: �ϴ��ɹ�
            2: �����ϴ�
*		   -1: �ϴ�ʧ��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetUpdateLoadState(VzLPRClientHandle handle);


/**
*  @brief ·��ͣ��ʶ����
*  @param [OUT] face_result �������
*  @param [OUT] pUserData �û��Զ�������
*/
typedef void (__STDCALL *VZLPRC_ROAD_SITE_RESULT_CALLBACK)(VzLPRClientHandle handle, TH_RoadSiteResult* face_result, void* pUserData);

/**
*  @brief ����·��ͣ��ʶ�����ص�
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] func �ص��ӿ�
*  @param [IN] pUserData �û��Զ�������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetRoadSiteResultCallBack(VzLPRClientHandle handle, VZLPRC_ROAD_SITE_RESULT_CALLBACK func, void* pUserData);

/**
*  @brief ��ȡ�豸Ӳ����Ϣ
*  @param [IN] ip ipͳһʹ���ַ�������ʽ����
*  @param [IN] port ʹ�ú͵�¼ʱ��ͬ�Ķ˿�
*  @param [OUT] board_version �豸Ӳ���ͺ�
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetBoardVersionInfo( const char *ip, WORD port, int* board_version);

/**
*  @brief ����ץ�Ĳ���
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] image_qualityͼƬ����(10 ,20, 30 40, 50, 60, 70, 80, 90, 100)
*  @param [IN] img_sizeͼ���С(2:352*288 3: 640*360 5:704*576 9:1280*720 10:1920*1080)
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetOutputImageSize(VzLPRClientHandle handle, int image_quality, int img_size);

/**
*  @brief ͸��http����
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] url �����url��ַ
*  @param [IN] cmd ������������
*  @param [OUT] response ���ص�
*  @param [IN] cmd ������������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_HttpTransSend(VzLPRClientHandle handle, const char* url, const char* cmd, char* response, int max_response_len, int type);

/**
*  @brief ȫ�������¼���ļ��б��ѯ
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] sub_type ��ѯ������ 1 ����ץ�� 2 ����ʶ�� 0 ȫ��
*  @param [IN] start_time ��ʼʱ�䣬ʱ���ʽ YYYY-MM-DD HH24:mm:SS
*  @param [IN] end_time   ����ʱ�䣬ʱ���ʽ YYYY-MM-DD HH24:mm:SS
*  @param [IN] page_num ҳ��
*  @param [OUT] record_video �ļ��б�
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzFicClient_QueryRecordVideo(VzLPRClientHandle handle, int sub_type, const char* start_time, const char* end_time, int page_num, VZ_FIC_RECORD_VIDEO_INFO* record_video);


/**
*  @brief �޸ĵ�¼����
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] password ��¼����
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetLoginAccount(VzLPRClientHandle handle, const char* password);

/**
*  @brief ���ò��Ŵ��ڵĴ�С
*  @param  [IN] nPlayHandle ���ŵľ��
*  @param  [IN] width  ���ڿ��
*  @param  [IN] height ���ڸ߶�
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetPlayWndSize(int nPlayHandle, int width, int height);


/**
*  @brief ����ʱ���ѯSD���е�¼���ļ�
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] start_time   ��ʼʱ��
*  @param  [IN] end_time     ����ʱ��
*  @param  [IN] page_index   ��ǰҳ����
*  @param  [IN] record_video ¼���ļ����
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SearchRecordFile(VzLPRClientHandle handle, const char* start_time, const char* end_time, int page_index, VZ_FIC_RECORD_VIDEO_INFO* record_video);

/**
*  @brief ��ʱ�������¼���ļ���ͨ���ص�������Ƶ����
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pStartTime ������ʼʱ�� (2018-12-12 10:01:02)
*  @param [IN] pEndTime ���Ž���ʱ�� (2018-12-12 10:59:59)
*  @return ���ž��: -1��ʾʧ��,����ֵ����ɹ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_DownLoadFileByTime(VzLPRClientHandle handle, const char* pStartTime, const char* pEndTime, VZLPRC_VIDEO_DATA_CALLBACK func, void *pUserData);

/**
*  @brief ��ȡ¼�����ؽ���
*  @param [IN] playhandle ��VzLPRClient_DownLoadFileByTime������õĲ��ž��
*  @return ����ֵΪ��ǰ���ؽ��Ȱٷֱ� [0, 100];
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetDownLoadProgress(int playhandle);


/**
*  @brief ��ʱ�������¼���ļ�, ����Ϊmp4��ʽ���ļ�(һ̨�豸һ��ֻ������һ���ļ�)
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] pStartTime ������ʼʱ�� (2018-12-12 10:01:02)
*  @param [IN] pEndTime ���Ž���ʱ�� (2018-12-12 10:02:59)
*  @param [IN] file_path �ļ�·��
*  @return ���ž��: -1��ʾʧ��,����ֵ����ɹ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_DownLoadMP4FileByTime(VzLPRClientHandle handle, const char* pStartTime, const char* pEndTime, const char* file_path);


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
VZ_LPRC_API int __STDCALL VzClient_CloudSetup(const char *pdns_addr, const char *username, const char *accesskey_id, const char *accesskey_secret, const char *res);

/**
*  @brief ж����ƽ̨
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_global
*/
VZ_LPRC_API int __STDCALL VzClient_CloudCleanup();

/**
*  @brief ����ʵʱ��Ƶ(ͨ����ƽ̨��ʽ������Ƶ)
*  @param  [IN] handle ��VzClient_Open������õľ��
*  @param  [IN] hWnd ���ڵľ��
*  @return ���ŵľ����-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API long __STDCALL VzClient_CloudStartRealPlay(VzLPRClientHandle handle, void *hWnd);

/**
*  @brief ֹͣ����ʵʱ��Ƶ(ͨ����ƽ̨��ʽ������Ƶ)
*  @param  [IN] handle ��VzClient_Open������õľ��
*  @param  [IN] hWnd ���ڵľ��
*  @return ���ŵľ����-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API long __STDCALL VzClient_CloudStopRealPlay(long nPlayHandle);

/**
*  @brief ���������Խ�
*  @param  [IN] handle ��VzClient_Open������õľ��
*  @param  [IN] hWnd ���ڵľ��
*  @return �����Խ��ľ����-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API long __STDCALL VzClient_CloudStreamTalk(VzLPRClientHandle handle);

/**
*  @brief ���������Խ�����
*  @param  [IN] handle ��VzClient_Open������õľ��
*  @param  [IN] hWnd ���ڵľ��
*  @return �����Խ��ľ����-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API int __STDCALL VzClient_CloudSendTalkData(long talk_handle, char *buf, int len, unsigned int stamp);

/**
*  @brief ֹͣ�����Խ�
*  @param  [IN] handle ��VzClient_Open������õľ��
*  @param  [IN] hWnd ���ڵľ��
*  @return �����Խ��ľ����-1��ʾʧ��
*  @ingroup group_device
*/
VZ_LPRC_API long __STDCALL VzClient_CloudStopTalk(long talk_handle);

/**
*  @brief ��̨����
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] dir ����2:�����ƶ� 4:�����ƶ� 8:ֹͣ�����ƶ� 16:�����ƶ� 32:�����ƶ� 64:ֹͣ�����ƶ� 128:��ԭ
*  @param [IN] degree �Ƕ�[0~65535]
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzClient_SetPtzCtrl(VzLPRClientHandle handle, int dir, int degree);

/**
*  @brief ͸��tcp����
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] cmd ������������
*  @param [OUT] response ���ص�
*  @param [IN] max_response_len ����ֵ�ĳ���
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_TcpTransSend(VzLPRClientHandle handle, const char* cmd_type, const char* cmd, char* response, int max_response_len);

/**
*  @brief ʶ�����ص�
*  @param [OUT] type�������(0:����ʶ����)
*  @param [OUT] pResultInfo�����Ϣ JSON��ʽ
*  @param [OUT] len�����Ϣ����
*  @param [OUT] imgsͼƬ��Ϣ
*  @param [OUT] countͼƬ����
*  @param [OUT] pUserData �û��Զ�������
*/
typedef void (__STDCALL *VZ_COMMON_RESULT_CALLBACK)(VzLPRClientHandle handle, int type, const char *pResultInfo, int len, VZ_IMAGE_INFO *imgs, int count, void *pUserData);

/**
*  @brief ����ͨ��ʶ�����ص�
*  @param [IN] handle ��VzLPRClient_Open������õľ��
*  @param [IN] func �ص��ӿ�
*  @param [IN] pUserData �û��Զ�������
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzClient_SetCommonResultCallBack(VzLPRClientHandle handle, int type, VZ_COMMON_RESULT_CALLBACK func, void* pUserData);

/**
*  @brief ��ѯ�ƴ洢��¼���ļ�����б�
*  @param [IN]  handle ��VzLPRClient_Open������õľ��
*  @param [IN]  query_info ��ѯ����
*  @param [OUT] record_list ���صĲ�ѯ���
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzClient_QueryCloudRecordList(VzLPRClientHandle handle, VzStream_RecordQueryInfo* query_info, VzStream_RecordList* record_list);

/**
*  @brief �ƴ�¼��㲥����ȡhls�ļ�url
*  @param [IN]  handle ��VzLPRClient_Open������õľ��
*  @param [IN]  file_name ¼���ļ���
*  @param [OUT] out_code ���ֵ��200��ok
*  @param [OUT] out_buffer ���ֵ��hls�ļ�url
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzClient_StreamCloudVod(VzLPRClientHandle handle, char* file_name, int* out_code, char* out_buffer, int out_len);

/**
*  @brief �ƴ�hls�ļ�����
*  @param [IN]  url �ƴ�¼���ļ�url
*  @param [IN]  seek_time �����¼��ʼʱ���ƫ�ƣ���λ����
*  @param [OUT] hWnd ���ھ����������Ⱦ����������������ݻص�����ֵ��NULL
*  @param [OUT] out_buffer ���ֵ��hls�ļ�url
*  @return ����0ʧ�ܣ���0ֵ����
*  @note ֹͣ���ţ�����VzClient_CloudStopRealPlay�ӿ�
*/
VZ_LPRC_API long __STDCALL VzClient_StreamOpenHLS(char* url, int seek_time, void* hWnd);


/**
*  @brief ͨ����ƽ̨��¼��ʽ��һ���豸
*  @param  [IN] pStrIP �豸��IP��ַ
*  @param  [IN] wPort �豸�Ķ˿ں�
*  @param  [IN] pStrUserName �����豸�����û���
*  @param  [IN] pStrPassword �����豸��������
*  @param  [IN] wHttpPort http�Ķ˿ں�,Ĭ��Ϊ80(���Ϊ0��ʾʹ��Ĭ�϶˿ڣ�
*  @param  [IN] network_type ��������(1����-PDNS��ʽ)
*  @param  [IN] sn �豸���к�
*  @param  [IN] app_id ��ƽ̨��¼�˺�
*  @param  [IN] app_key ��ƽ̨��¼����
*  @param  [IN] pStrExtData Ԥ������
*  @return �����豸�Ĳ������������ʧ��ʱ������0
*  @ingroup group_device
*/
VZ_LPRC_API VzLPRClientHandle __STDCALL VzLPRClient_CloudOpen(const char *pStrIP, WORD wPort, const char *pStrUserName, const char *pStrPassword, WORD wHttpPort, int network_type, char* sn, const char* appid, const char *appkey, const char *pStrExtData);


/**
*  @brief RG��ȡָ�����»���������Ϣ
*  @param [IN]  handle ��VzLPRClient_Open������õľ��
*  @param [OUT] VZ_LPRC_MATE_INFO  RG���»�������Ϣ
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetMateInfo(VzLPRClientHandle handle, VZ_LPRC_MATE_INFO* mateinfo );


/**
*  @brief RG��ȡ���»���Rtsp������Ϣ
*  @param [IN]  handle ��VzLPRClient_Open������õľ��
*  @param [IN]  sn ָ��Rtsp�ĸ����豸sn
*  @param [OUT] VZ_LPRC_RTSP_INFO  RG���»���Rtsp������Ϣ
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetRtspInfo(VzLPRClientHandle handle,const char *sn,VZ_LPRC_RTSP_INFO * rtspinfo);

/**
*  @brief RG��ȡ���»�������������Ϣ
*  @param [IN]  handle ��VzLPRClient_Open������õľ��
*  @param [IN]  sn ָ����������ĸ����豸sn
*  @param [IN]  window_size ���������ڴ�С��ÿ�η������ݰ��Ĵ�
*  @param [OUT] VZ_LPRC_REQUEST_TALK_INFO  RG���»�������������Ϣ
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/

VZ_LPRC_API int __STDCALL VzLPRClient_GetRequestTalkInfo(VzLPRClientHandle handle,const char *sn,const int window_size,VZ_LPRC_REQUEST_TALK_INFO * talkinfo);

/**
*  @brief ����Rg�˳������¼��ϱ�ʹ��
*  @param [IN]  handle ��VzLPRClient_Open������õľ��
*  @param [IN] enable  ʹ�ܿ��أ�0���رգ�1��
*  @return ����ֵΪ0��ʾ�ɹ�����������ֵ��ʾʧ�ܡ�
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetStayEventEnable(VzLPRClientHandle handle,int enable);

/**
*  @brief ����gpio������״̬
*  @param [IN]  handle ��VzLPRClient_Open������õľ��
*  @param  [IN] ioout  ioout����� 0����1
*  @param  [IN] status 0 ���� 1�ߵ�ƽ���� 2 �͵�ƽ����
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*/
VZ_LPRC_API int __STDCALL VzLPRClient_SetIoLockStatus(VzLPRClientHandle handle, int ioout, int status);


/**
*  @brief ��ȡgpio������״̬
*  @param [IN]  handle ��VzLPRClient_Open������õľ��
*  @param  [IN] ioout  ioout����� 0����1
*  @param  [OUT] status 0 ���� 1�ߵ�ƽ���� 2 �͵�ƽ����
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*/
VZ_LPRC_API int __STDCALL VzLPRClient_GetIoLockStatus(VzLPRClientHandle handle, int ioout, int *status);

#ifdef  LINUX
#ifdef __cplusplus
}
#endif
#endif

#endif
