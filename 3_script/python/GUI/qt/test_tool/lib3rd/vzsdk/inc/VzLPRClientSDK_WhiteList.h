//����VZ�ĳ���ʶ���豸�İ�������صĲ���

#ifndef _VZ_LPR_CLIENT_SDK_WHITE_LIST_H_
#define _VZ_LPR_CLIENT_SDK_WHITE_LIST_H_

#include <VzLPRClientSDK.h>
#include <VzLPRClientSDK_WhiteListDefine.h>

/**
* @defgroup group_database ���ݿ��������
*/
#ifdef  LINUX
#ifdef __cplusplus
extern "C"
{
#endif
#endif

/**
*  @brief ���ð�������Ϳͻ���Ϣ��Ĳ�ѯ����ص�
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] func ��ѯ����ص�����
*  @param  [IN] pUserData �ص������е�������
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListSetQueryCallBack(VzLPRClientHandle handle, VZLPRC_WLIST_QUERY_CALLBACK func, void *pUserData);

/**
*  @brief ��ȡ�������������г�����Ϣ��¼������
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @return >=0��ʾ���г�����Ϣ��¼��������-1��ʾʧ��
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListGetVehicleCount(VzLPRClientHandle handle, unsigned *pCount,
															   VZ_LPR_WLIST_SEARCH_WHERE* pSearchWhere);
/**
*  @brief ��ѯ������������¼����
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] pLoadCondition ��ѯ����
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListLoadVehicle(VzLPRClientHandle handle, 
															VZ_LPR_WLIST_LOAD_CONDITIONS *pLoadCondition);
/**
*  @brief ����
*  @brief ��ȡ�ͻ���Ϣ�������пͻ���Ϣ��¼������
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @return >=0��ʾ���пͻ���Ϣ��¼��������-1��ʾʧ��
*  @ingroup group_database
*/

VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListGetCustomerCount(VzLPRClientHandle handle, unsigned *pCount,
																VZ_LPR_WLIST_SEARCH_WHERE* pSearchWhere);
/**
*  @brief ����
*  @brief ��ѯ��������ͻ���Ϣ����
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] pLoadCondition ��ѯ����
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListLoadCustomer(VzLPRClientHandle handle, 
															VZ_LPR_WLIST_LOAD_CONDITIONS *pLoadCondition);

/**
*  @brief ��ѯ��������ͻ��ͳ�����¼����
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [OUT] pCount ��¼������
*  @param  [IN] search_constraints ����������
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListGetRowCount(VzLPRClientHandle handle, unsigned *pCount,
														   VZ_LPR_WLIST_SEARCH_WHERE* pSearchWhere);	


/**
*  @brief ��ѯ��������ͻ��ͳ�����¼����
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] pLoadCondition ��ѯ����
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListLoadRow(VzLPRClientHandle handle, 
													   VZ_LPR_WLIST_LOAD_CONDITIONS *pLoadCondition);

/**
*  @brief �����������ͻ��ͳ�����¼
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] rowcount ��¼������
*  @param  [IN] pRowDatas ��¼����������ĵ�ַ
*  @param  [OUT] results ÿ�������Ƿ���ɹ�
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListImportRows(VzLPRClientHandle handle, 
														  unsigned rowcount, 
														  VZ_LPR_WLIST_ROW *pRowDatas,
														  VZ_LPR_WLIST_IMPORT_RESULT* pResults);	

/**
*  @brief ��ȡ���������г�����Ϣ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] pStrPlateID ���ƺ���
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListLoadVehicleByPlateID(VzLPRClientHandle handle, const char *pStrPlateID);

/**
*  @brief ��ȡ���������г�����Ϣ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] uID ��������Ϣ��¼��ID
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListLoadVehicleByID(VzLPRClientHandle handle, unsigned uID);

/**
*  @brief ��ȡ���������г�����Ϣ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] uID ��������Ϣ��¼��ID
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListLoadVehicleByCode(VzLPRClientHandle handle, const char *pStrCode);

/**
*  @brief ����
*  @brief ��ȡ���������пͻ���Ϣ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] uID �ͻ���Ϣ��¼��ID
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListLoadCustomerByID(VzLPRClientHandle handle, unsigned uID);

/**
*  @brief ����
*  @brief �ӿͻ���Ϣ���а��ͻ������ѯ�ͻ���¼
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] pStrCode ��Ҫ��ѯ�Ŀͻ�����
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListLoadCustomerByCode(VzLPRClientHandle handle, const char *pStrCode);

/**
*  @brief ����
*  @brief �ӿͻ���Ϣ���а��ͻ����Ʋ�ѯ�ͻ���¼
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] pStrCode ��Ҫ��ѯ�Ŀͻ�����
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListLoadCustomersByName(VzLPRClientHandle handle, const char *pStrName);

/**
*  @brief ��ȡ���������пͻ��ĳ�����Ϣ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] uID �ͻ���Ϣ��¼��ID
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListLoadCustomerVehicles(VzLPRClientHandle handle, unsigned uID);

/**
*  @brief ����
*  @brief �����������и���һ���ͻ���Ϣ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] pCustomer ��Ҫ���µĿͻ���Ϣ������ṹ�嶨��VZ_LPR_WLIST_CUSTOMER
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListUpdateCustomerByID(VzLPRClientHandle handle, VZ_LPR_WLIST_CUSTOMER *pCustomer);

/**
*  @brief ����
*  @brief �����������и���һ���ͻ���Ϣ,�Կͻ���Ų���
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] pCustomer ��Ҫ���µĿͻ���Ϣ������ṹ�嶨��VZ_LPR_WLIST_CUSTOMER
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListUpdateCustomerByCode(VzLPRClientHandle handle, VZ_LPR_WLIST_CUSTOMER *pCustomer);

/**
*  @brief �����������и���һ��������Ϣ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] pVehicle ��Ҫ���µĳ�����Ϣ������ṹ�嶨��VZ_LPR_WLIST_VEHICLE
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListUpdateVehicleByID(VzLPRClientHandle handle, VZ_LPR_WLIST_VEHICLE* pVehicle);

/**
*  @brief �����������и���һ��������Ϣ,�Գ�����Ų���
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] pVehicle ��Ҫ���µĳ�����Ϣ������ṹ�嶨��VZ_LPR_WLIST_VEHICLE
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListUpdateVehicleByCode(VzLPRClientHandle handle, VZ_LPR_WLIST_VEHICLE* pVehicle);

/**
*  @brief �����������и���һ��������Ϣ,�Գ��ƺ������
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] pVehicle ��Ҫ���µĳ�����Ϣ������ṹ�嶨��VZ_LPR_WLIST_VEHICLE
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListUpdateVehicleByPlateID(VzLPRClientHandle handle, VZ_LPR_WLIST_VEHICLE* pVehicle);

/**
*  @brief ����
*  @brief ���������������һ���ͻ���Ϣ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] pCustomer ��Ҫ����Ŀͻ���Ϣ������ṹ�嶨��VZ_LPR_WLIST_CUSTOMER
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListInsertCustomer(VzLPRClientHandle handle, VZ_LPR_WLIST_CUSTOMER *pCustomer);

/**
*  @brief ���������������һ��������Ϣ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] pVehicle ��Ҫ����ĳ�����Ϣ������ṹ�嶨��VZ_LPR_WLIST_VEHICLE
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListInsertVehicle(VzLPRClientHandle handle, VZ_LPR_WLIST_VEHICLE* pVehicle);

/**
*  @brief ����
*  @brief �����ݿ�ɾ���ͻ���Ϣ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] uID �ͻ���Ϣ��¼��ID
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListDeleteCustomerByID(VzLPRClientHandle handle, unsigned uID);

/**
*  @brief ����
*  @brief �����ݿ�ɾ���ͻ���Ϣ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] strCode �ͻ�����
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListDeleteCustomerByCode(VzLPRClientHandle handle, const char* strCode);

/**
*  @brief �����ݿ�ɾ��������Ϣ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] strPlateID ���ƺ���
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListDeleteVehicleByPlateID(VzLPRClientHandle handle, const char* strPlateID);

/**
*  @brief �����ݿ�ɾ��������Ϣ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] strCode ��������
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListDeleteVehicleByCode(VzLPRClientHandle handle, const char* strCode);


/**
*  @brief �����ݿ�ɾ��������Ϣ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] uID ����id
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListDeleteVehicleByID(VzLPRClientHandle handle, unsigned uID);

/**
*  @brief �����ݿ�ɾ���ͻ����䳵����Ϣ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] uID �ͻ���Ϣ��¼��ID
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListDeleteCustomerAndVehiclesByCustomerID(VzLPRClientHandle handle, unsigned uID);

/**
*  @brief �����ݿ�ɾ���ͻ��ĳ�����Ϣ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] uID �ͻ���Ϣ��¼��ID
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListDeleteVehicleByCustomerID(VzLPRClientHandle handle, unsigned uID);

/**
*  @brief ������ݿ�ͻ���Ϣ�ͳ�����Ϣ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListClearCustomersAndVehicles(VzLPRClientHandle handle);

/**
*  @brief ��ȡ������Ϣ�����ִ�����ַ���
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] key Ҫ��ѯ���ֶ����ƣ�����ֻ����VZLPRC_WLIST_COL_VEHICLE_COLOR����VZLPRC_WLIST_COL_VEHICLE_PLATETYPE
*  @param  [IN][OUT] pEnumValues �������е����ֺͶ�Ӧ�ַ����ṹ������
*  @param  [IN][OUT] MaxCount �����������󳤶�,�������鳤��
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListGetEnumStrings(VzLPRClientHandle handle,const char* key,VZ_LPR_WLIST_ENUM_VALUE* pEnumValues,int *pMaxCount);


/**
*  @brief ģ����ѯ������
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] strPlateID Ҫ��ѯ���ֶ�����
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListQueryVehicleByPlate(VzLPRClientHandle handle,const char* strPlateID);

/**
*  @brief �����ݿ�ɾ���ͻ���Ϣ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] uID �ͻ���Ϣ��¼��ID
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_database
*/
VZ_LPRC_API VZ_DEPRECATED int __STDCALL VzLPRClient_WhiteListDeleteCustomer(VzLPRClientHandle handle, unsigned uID);

/**
*  @brief �����ݿ�ɾ��������Ϣ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] strPlateID ���ƺ���
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_database
*/
VZ_LPRC_API VZ_DEPRECATED int __STDCALL VzLPRClient_WhiteListDeleteVehicle(VzLPRClientHandle handle, const char* strPlateID);

/**
*  @brief ����
*  @brief �����������и���һ���ͻ���Ϣ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] pCustomer ��Ҫ���µĿͻ���Ϣ������ṹ�嶨��VZ_LPR_WLIST_CUSTOMER
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_database
*/
VZ_LPRC_API VZ_DEPRECATED int __STDCALL VzLPRClient_WhiteListUpdateCustomer(VzLPRClientHandle handle, VZ_LPR_WLIST_CUSTOMER *pCustomer);

/**
*  @brief �����������и���һ��������Ϣ
*  @param  [IN] handle ��VzLPRClient_Open������õľ��
*  @param  [IN] pVehicle ��Ҫ���µĳ�����Ϣ������ṹ�嶨��VZ_LPR_WLIST_VEHICLE
*  @return 0��ʾ�ɹ���-1��ʾʧ��
*  @ingroup group_database
*/
VZ_LPRC_API VZ_DEPRECATED int __STDCALL VzLPRClient_WhiteListUpdateVehicle(VzLPRClientHandle handle, VZ_LPR_WLIST_VEHICLE* pVehicle);

#ifdef  LINUX
#ifdef __cplusplus
}
#endif
#endif


#endif
