//用于VZ的车牌识别设备的白名单相关的操作

#ifndef _VZ_LPR_CLIENT_SDK_WHITE_LIST_H_
#define _VZ_LPR_CLIENT_SDK_WHITE_LIST_H_

#include <VzLPRClientSDK.h>
#include <VzLPRClientSDK_WhiteListDefine.h>

/**
* @defgroup group_database 数据库操作函数
*/
#ifdef  LINUX
#ifdef __cplusplus
extern "C"
{
#endif
#endif

/**
*  @brief 设置白名单表和客户信息表的查询结果回调
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] func 查询结果回调函数
*  @param  [IN] pUserData 回调函数中的上下文
*  @return 0表示成功，-1表示失败
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListSetQueryCallBack(VzLPRClientHandle handle, VZLPRC_WLIST_QUERY_CALLBACK func, void *pUserData);

/**
*  @brief 获取白名单表中所有车辆信息记录的条数
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @return >=0表示所有车辆信息记录的总数，-1表示失败
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListGetVehicleCount(VzLPRClientHandle handle, unsigned *pCount,
															   VZ_LPR_WLIST_SEARCH_WHERE* pSearchWhere);
/**
*  @brief 查询白名单表车辆记录数据
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] pLoadCondition 查询条件
*  @return 0表示成功，-1表示失败
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListLoadVehicle(VzLPRClientHandle handle, 
															VZ_LPR_WLIST_LOAD_CONDITIONS *pLoadCondition);
/**
*  @brief 弃用
*  @brief 获取客户信息表中所有客户信息记录的条数
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @return >=0表示所有客户信息记录的总数，-1表示失败
*  @ingroup group_database
*/

VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListGetCustomerCount(VzLPRClientHandle handle, unsigned *pCount,
																VZ_LPR_WLIST_SEARCH_WHERE* pSearchWhere);
/**
*  @brief 弃用
*  @brief 查询白名单表客户信息数据
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] pLoadCondition 查询条件
*  @return 0表示成功，-1表示失败
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListLoadCustomer(VzLPRClientHandle handle, 
															VZ_LPR_WLIST_LOAD_CONDITIONS *pLoadCondition);

/**
*  @brief 查询白名单表客户和车辆记录条数
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [OUT] pCount 记录的条数
*  @param  [IN] search_constraints 搜索的条件
*  @return 0表示成功，-1表示失败
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListGetRowCount(VzLPRClientHandle handle, unsigned *pCount,
														   VZ_LPR_WLIST_SEARCH_WHERE* pSearchWhere);	


/**
*  @brief 查询白名单表客户和车辆记录数据
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] pLoadCondition 查询条件
*  @return 0表示成功，-1表示失败
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListLoadRow(VzLPRClientHandle handle, 
													   VZ_LPR_WLIST_LOAD_CONDITIONS *pLoadCondition);

/**
*  @brief 向白名单表导入客户和车辆记录
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] rowcount 记录的条数
*  @param  [IN] pRowDatas 记录的内容数组的地址
*  @param  [OUT] results 每条数据是否导入成功
*  @return 0表示成功，-1表示失败
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListImportRows(VzLPRClientHandle handle, 
														  unsigned rowcount, 
														  VZ_LPR_WLIST_ROW *pRowDatas,
														  VZ_LPR_WLIST_IMPORT_RESULT* pResults);	

/**
*  @brief 获取白名单表中车辆信息
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] pStrPlateID 车牌号码
*  @return 0表示成功，-1表示失败
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListLoadVehicleByPlateID(VzLPRClientHandle handle, const char *pStrPlateID);

/**
*  @brief 获取白名单表中车辆信息
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] uID 白名单信息记录的ID
*  @return 0表示成功，-1表示失败
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListLoadVehicleByID(VzLPRClientHandle handle, unsigned uID);

/**
*  @brief 获取白名单表中车辆信息
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] uID 白名单信息记录的ID
*  @return 0表示成功，-1表示失败
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListLoadVehicleByCode(VzLPRClientHandle handle, const char *pStrCode);

/**
*  @brief 弃用
*  @brief 获取白名单表中客户信息
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] uID 客户信息记录的ID
*  @return 0表示成功，-1表示失败
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListLoadCustomerByID(VzLPRClientHandle handle, unsigned uID);

/**
*  @brief 弃用
*  @brief 从客户信息表中按客户编码查询客户记录
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] pStrCode 将要查询的客户编码
*  @return 0表示成功，-1表示失败
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListLoadCustomerByCode(VzLPRClientHandle handle, const char *pStrCode);

/**
*  @brief 弃用
*  @brief 从客户信息表中按客户名称查询客户记录
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] pStrCode 将要查询的客户编码
*  @return 0表示成功，-1表示失败
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListLoadCustomersByName(VzLPRClientHandle handle, const char *pStrName);

/**
*  @brief 获取白名单表中客户的车辆信息
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] uID 客户信息记录的ID
*  @return 0表示成功，-1表示失败
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListLoadCustomerVehicles(VzLPRClientHandle handle, unsigned uID);

/**
*  @brief 弃用
*  @brief 往白名单表中更新一个客户信息
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] pCustomer 将要更新的客户信息，详见结构体定义VZ_LPR_WLIST_CUSTOMER
*  @return 0表示成功，-1表示失败
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListUpdateCustomerByID(VzLPRClientHandle handle, VZ_LPR_WLIST_CUSTOMER *pCustomer);

/**
*  @brief 弃用
*  @brief 往白名单表中更新一个客户信息,以客户编号查找
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] pCustomer 将要更新的客户信息，详见结构体定义VZ_LPR_WLIST_CUSTOMER
*  @return 0表示成功，-1表示失败
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListUpdateCustomerByCode(VzLPRClientHandle handle, VZ_LPR_WLIST_CUSTOMER *pCustomer);

/**
*  @brief 往白名单表中更新一个车辆信息
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] pVehicle 将要更新的车辆信息，详见结构体定义VZ_LPR_WLIST_VEHICLE
*  @return 0表示成功，-1表示失败
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListUpdateVehicleByID(VzLPRClientHandle handle, VZ_LPR_WLIST_VEHICLE* pVehicle);

/**
*  @brief 往白名单表中更新一个车辆信息,以车辆编号查找
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] pVehicle 将要更新的车辆信息，详见结构体定义VZ_LPR_WLIST_VEHICLE
*  @return 0表示成功，-1表示失败
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListUpdateVehicleByCode(VzLPRClientHandle handle, VZ_LPR_WLIST_VEHICLE* pVehicle);

/**
*  @brief 往白名单表中更新一个车辆信息,以车牌号码查找
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] pVehicle 将要更新的车辆信息，详见结构体定义VZ_LPR_WLIST_VEHICLE
*  @return 0表示成功，-1表示失败
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListUpdateVehicleByPlateID(VzLPRClientHandle handle, VZ_LPR_WLIST_VEHICLE* pVehicle);

/**
*  @brief 弃用
*  @brief 往白名单表中添加一个客户信息
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] pCustomer 将要加入的客户信息，详见结构体定义VZ_LPR_WLIST_CUSTOMER
*  @return 0表示成功，-1表示失败
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListInsertCustomer(VzLPRClientHandle handle, VZ_LPR_WLIST_CUSTOMER *pCustomer);

/**
*  @brief 往白名单表中添加一个车辆信息
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] pVehicle 将要加入的车辆信息，详见结构体定义VZ_LPR_WLIST_VEHICLE
*  @return 0表示成功，-1表示失败
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListInsertVehicle(VzLPRClientHandle handle, VZ_LPR_WLIST_VEHICLE* pVehicle);

/**
*  @brief 弃用
*  @brief 从数据库删除客户信息
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] uID 客户信息记录的ID
*  @return 0表示成功，-1表示失败
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListDeleteCustomerByID(VzLPRClientHandle handle, unsigned uID);

/**
*  @brief 弃用
*  @brief 从数据库删除客户信息
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] strCode 客户代码
*  @return 0表示成功，-1表示失败
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListDeleteCustomerByCode(VzLPRClientHandle handle, const char* strCode);

/**
*  @brief 从数据库删除车辆信息
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] strPlateID 车牌号码
*  @return 0表示成功，-1表示失败
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListDeleteVehicleByPlateID(VzLPRClientHandle handle, const char* strPlateID);

/**
*  @brief 从数据库删除车辆信息
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] strCode 车辆代码
*  @return 0表示成功，-1表示失败
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListDeleteVehicleByCode(VzLPRClientHandle handle, const char* strCode);


/**
*  @brief 从数据库删除车辆信息
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] uID 车辆id
*  @return 0表示成功，-1表示失败
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListDeleteVehicleByID(VzLPRClientHandle handle, unsigned uID);

/**
*  @brief 从数据库删除客户和其车辆信息
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] uID 客户信息记录的ID
*  @return 0表示成功，-1表示失败
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListDeleteCustomerAndVehiclesByCustomerID(VzLPRClientHandle handle, unsigned uID);

/**
*  @brief 从数据库删除客户的车辆信息
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] uID 客户信息记录的ID
*  @return 0表示成功，-1表示失败
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListDeleteVehicleByCustomerID(VzLPRClientHandle handle, unsigned uID);

/**
*  @brief 清空数据库客户信息和车辆信息
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @return 0表示成功，-1表示失败
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListClearCustomersAndVehicles(VzLPRClientHandle handle);

/**
*  @brief 获取车辆信息中数字代表的字符串
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] key 要查询的字段名称，现在只能是VZLPRC_WLIST_COL_VEHICLE_COLOR或者VZLPRC_WLIST_COL_VEHICLE_PLATETYPE
*  @param  [IN][OUT] pEnumValues 返回所有的数字和对应字符串结构体数组
*  @param  [IN][OUT] MaxCount 输入数组的最大长度,返回数组长度
*  @return 0表示成功，-1表示失败
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListGetEnumStrings(VzLPRClientHandle handle,const char* key,VZ_LPR_WLIST_ENUM_VALUE* pEnumValues,int *pMaxCount);


/**
*  @brief 模糊查询白名单
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] strPlateID 要查询的字段名称
*  @return 0表示成功，-1表示失败
*  @ingroup group_database
*/
VZ_LPRC_API int __STDCALL VzLPRClient_WhiteListQueryVehicleByPlate(VzLPRClientHandle handle,const char* strPlateID);

/**
*  @brief 从数据库删除客户信息
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] uID 客户信息记录的ID
*  @return 0表示成功，-1表示失败
*  @ingroup group_database
*/
VZ_LPRC_API VZ_DEPRECATED int __STDCALL VzLPRClient_WhiteListDeleteCustomer(VzLPRClientHandle handle, unsigned uID);

/**
*  @brief 从数据库删除车辆信息
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] strPlateID 车牌号码
*  @return 0表示成功，-1表示失败
*  @ingroup group_database
*/
VZ_LPRC_API VZ_DEPRECATED int __STDCALL VzLPRClient_WhiteListDeleteVehicle(VzLPRClientHandle handle, const char* strPlateID);

/**
*  @brief 弃用
*  @brief 往白名单表中更新一个客户信息
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] pCustomer 将要更新的客户信息，详见结构体定义VZ_LPR_WLIST_CUSTOMER
*  @return 0表示成功，-1表示失败
*  @ingroup group_database
*/
VZ_LPRC_API VZ_DEPRECATED int __STDCALL VzLPRClient_WhiteListUpdateCustomer(VzLPRClientHandle handle, VZ_LPR_WLIST_CUSTOMER *pCustomer);

/**
*  @brief 往白名单表中更新一个车辆信息
*  @param  [IN] handle 由VzLPRClient_Open函数获得的句柄
*  @param  [IN] pVehicle 将要更新的车辆信息，详见结构体定义VZ_LPR_WLIST_VEHICLE
*  @return 0表示成功，-1表示失败
*  @ingroup group_database
*/
VZ_LPRC_API VZ_DEPRECATED int __STDCALL VzLPRClient_WhiteListUpdateVehicle(VzLPRClientHandle handle, VZ_LPR_WLIST_VEHICLE* pVehicle);

#ifdef  LINUX
#ifdef __cplusplus
}
#endif
#endif


#endif
