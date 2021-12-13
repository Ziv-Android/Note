
 
//==============黑白名单用的数据结构及宏定义=============
#ifndef _VZ_LPR_CLIENT_SDK_WHITE_LIST_DEFINE_H_
#define _VZ_LPR_CLIENT_SDK_WHITE_LIST_DEFINE_H_
 

#define VZ_LPR_WLIST_DATETIME_LEN	32
#define VZ_LPR_WLIST_TIME_SEG_LEN	128

#define VZ_LPR_WLIST_LP_MAX_LEN			32
#define VZ_LPR_WLIST_TIME_SEG_MAX_NUM	8

#define VZ_LPR_WLIST_MAX_KEY_LEN 32
#define	VZ_LPR_WLIST_MAX_SEARCH_STRING_LEN 128

#define VZ_LPR_WLIST_VEHICLE_CODE_LEN		32
#define VZ_LPR_WLIST_VEHICLE_COMMENT_LEN	64
#define VZ_LPR_WLIST_MAX_ENUM_VALUE_LEN		32

/**日期时间描述*/
typedef struct
{
	short nYear;	/**<年*/
	short nMonth;	/**<月*/
	short nMDay;	/**<日*/
	short nHour;	/**<时*/
	short nMin;		/**<分*/
	short nSec;		/**<秒*/
}
VZ_TM;

/**一周七天的选择掩膜*/
typedef struct
{
	char bSun;		/**<周日*/
	char bMon;		/**<周一*/
	char bTue;		/**<周二*/
	char bWed;		/**<周三*/
	char bThur;		/**<周四*/
	char bFri;		/**<周五*/
	char bSat;		/**<周六*/
	char reserved;
}
VZ_TM_WEEK_DAY;

/**一天中的时间表达*/
typedef struct
{
	short nHour;
	short nMin;
	short nSec;
	short reserved;
}
VZ_TM_DAY;

/**时间段信息*/
typedef struct
{
	unsigned		uEnable;
	VZ_TM_WEEK_DAY	struDaySelect;		/**<一周内的天数选择*/
	VZ_TM_DAY		struDayTimeStart;	/**每天的时间起点*/
	VZ_TM_DAY		struDayTimeEnd;		/**每天的时间终点*/
}
VZ_TM_WEEK_SEGMENT;

typedef struct
{
	VZ_TM		struTimeStart;		/**每天的时间起点*/
	VZ_TM		struTimeEnd;		/**每天的时间终点*/
}
VZ_TM_RANGE;

typedef struct
{
	unsigned			uEnable;										/**是否开启*/
	VZ_TM_WEEK_SEGMENT  struWeekSeg[VZ_LPR_WLIST_TIME_SEG_MAX_NUM];		/**周期时间段设置*/
}
VZ_TM_PERIOD;

typedef enum
{
	VZ_LPR_WLIST_ERROR_NO_ERROR=0,
	VZ_LPR_WLIST_ERROR_PLATEID_EXISTS,
	VZ_LPR_WLIST_ERROR_INSERT_CUSTOMERINFO_FAILED,
	VZ_LPR_WLIST_ERROR_INSERT_VEHICLEINFO_FAILED,
	VZ_LPR_WLIST_ERROR_UPDATE_CUSTOMERINFO_FAILED,
	VZ_LPR_WLIST_ERROR_UPDATE_VEHICLEINFO_FAILED,
	VZ_LPR_WLIST_ERROR_PLATEID_EMPTY,
	VZ_LPR_WLIST_ERROR_ROW_NOT_CHANGED,
	VZ_LPR_WLIST_ERROR_CUSTOMERINFO_NOT_CHANGED,
	VZ_LPR_WLIST_ERROR_VEHICLEINFO_NOT_CHANGED,
	VZ_LPR_WLIST_ERROR_CUSTOMER_VEHICLE_NOT_MATCH,
	VZ_LPR_WLIST_ERROR_SERVER_GONE,
}
VZ_LPR_WLIST_ERROR;

#define VZ_LPR_WLIST_INVAILID_ID 0xFFFFFFFF

/**黑白名单中的车辆记录*/
typedef struct
{
	unsigned	uVehicleID;										/**<车辆在数据库的ID*/
	char		strPlateID[VZ_LPR_WLIST_LP_MAX_LEN];			/**<车牌字符串*/
	unsigned	uCustomerID;									/**<客户在数据库的ID，与VZ_LPR_WLIST_CUSTOMER::uCustomerID对应*/
	unsigned	bEnable;										/**<该记录有效标记*/
	unsigned	bEnableTMEnable;								/**<是否开启生效时间*/
	unsigned	bEnableTMOverdule;								/**<是否开启过期时间*/
	VZ_TM		struTMEnable;									/**<该记录生效时间*/
	VZ_TM		struTMOverdule;									/**<该记录过期时间*/
	unsigned	bUsingTimeSeg;									/**<是否使用周期时间段*/
	VZ_TM_PERIOD struTimeSeg;									/**<周期时间段信息*/
	unsigned	bAlarm;											/**<是否触发报警（黑名单记录）*/
	int			iColor;											/**<车辆颜色*/
	int			iPlateType;										/**<车牌类型*/
	char		strCode[VZ_LPR_WLIST_VEHICLE_CODE_LEN];			/**<车辆编码*/
	char		strComment[VZ_LPR_WLIST_VEHICLE_COMMENT_LEN];	/**<车辆编码*/
}
VZ_LPR_WLIST_VEHICLE;

#define VZ_LPR_WLIST_CUSTOMER_NAME_LEN		32
#define VZ_LPR_WLIST_CUSTOMER_CODE_LEN		32

/**黑白名单记录的客户信息*/
typedef struct
{
	unsigned	uCustomerID;			/**<客户在数据库的ID，用于修改、删除操作（主键）*/
	char		strName[VZ_LPR_WLIST_CUSTOMER_NAME_LEN];	/**<客户姓名*/
	char		strCode[VZ_LPR_WLIST_CUSTOMER_CODE_LEN];	/**<客户编码*/

	char		reserved[256];
}
VZ_LPR_WLIST_CUSTOMER;

/**客户和其车辆中的一辆合成的一行数据*/
typedef struct
{
	VZ_LPR_WLIST_CUSTOMER *pCustomer;			/**<客户*/
	VZ_LPR_WLIST_VEHICLE *pVehicle;				/**<车辆，可以为空*/
}
VZ_LPR_WLIST_ROW;

/**查找数据条件*/
typedef struct
{
	char						key[VZ_LPR_WLIST_MAX_KEY_LEN];							/**<查找的字段*/
	char						search_string[VZ_LPR_WLIST_MAX_SEARCH_STRING_LEN];		/**<查找的字符串*/
}
VZ_LPR_WLIST_SEARCH_CONSTRAINT;

typedef enum
{
	VZ_LPR_WLIST_LIMIT_TYPE_ONE,						/**<查找一条*/
	VZ_LPR_WLIST_LIMIT_TYPE_ALL,						/**<查找所有*/
	VZ_LPR_WLIST_LIMIT_TYPE_RANGE						/**<查找一段*/
}
VZ_LPR_WLIST_LIMIT_TYPE;

typedef struct
{
	int startIndex;
	int count;
}
VZ_LPR_WLIST_RANGE_LIMIT;

typedef struct
{
	VZ_LPR_WLIST_LIMIT_TYPE				limitType;					/**<查找条数限制*/
	VZ_LPR_WLIST_RANGE_LIMIT			*pRangeLimit;				/**<查找哪一段数据，当limitType为VZ_LPR_WLIST_LIMIT_TYPE_RANGE时起作用*/
}
VZ_LPR_WLIST_LIMIT;

typedef enum
{
	VZ_LPR_WLIST_SORT_DIRECTION_DESC=0,
	VZ_LPR_WLIST_SORT_DIRECTION_ASC=1,
}
VZ_LPR_WLIST_SORT_DIRECTION;

/**结果的排列方式*/
typedef struct
{
	char	key[VZ_LPR_WLIST_MAX_KEY_LEN];
	VZ_LPR_WLIST_SORT_DIRECTION direction;
}
VZ_LPR_WLIST_SORT_TYPE;

/**查找数据方式*/
typedef enum{
	VZ_LPR_WLIST_SEARCH_TYPE_LIKE,				/**<包含字符*/
	VZ_LPR_WLIST_SEARCH_TYPE_EQUAL				/**<完全匹配*/
}
VZ_LPR_WLIST_SEARCH_TYPE;

typedef struct{
	VZ_LPR_WLIST_SEARCH_TYPE			searchType;					/**<查找的方式，如果是完全匹配，每个条件之间为与，是包含时，每个条件之间为或*/
	unsigned int						searchConstraintCount;		/**<查找条件个数，为0表示没有搜索条件*/
	VZ_LPR_WLIST_SEARCH_CONSTRAINT*		pSearchConstraints;			/**<查找条件数组指针*/
}
VZ_LPR_WLIST_SEARCH_WHERE;

typedef struct
{
	VZ_LPR_WLIST_SEARCH_WHERE			*pSearchWhere;				/**<查找条件*/
	VZ_LPR_WLIST_LIMIT					*pLimit;					/**<查找条数限制*/
	VZ_LPR_WLIST_SORT_TYPE				*pSortType;					/**<结果的排序方式，为空表示按默认排序*/
}
VZ_LPR_WLIST_LOAD_CONDITIONS;

/**表的列id和中文名称*/
typedef struct
{
	char	key[VZ_LPR_WLIST_MAX_KEY_LEN];
	char	name[VZ_LPR_WLIST_MAX_KEY_LEN];
}
VZ_LPR_WLIST_KEY_DEFINE;

/**以整数代表的实际内容*/
typedef struct
{
	int		iValue;
	char	strValue[VZ_LPR_WLIST_MAX_ENUM_VALUE_LEN];
}
VZ_LPR_WLIST_ENUM_VALUE;

/**批量导入每行的结果*/
typedef struct
{
	int ret;
	int error_code;
}
VZ_LPR_WLIST_IMPORT_RESULT;

typedef enum{
	VZLPRC_WLIST_CB_TYPE_ROW = 0,				/**<复合查询的结果返回*/
	VZLPRC_WLIST_CB_TYPE_CUSTOMER,				/**<客户信息查询的结果返回*/
	VZLPRC_WLIST_CB_TYPE_VEHICLE				/**<车辆信息查询的结果返回*/
}
VZLPRC_WLIST_CB_TYPE;

#ifdef WIN32
#define __STDCALL __stdcall
#else
#define __STDCALL
#endif

/**
*  @brief 白名单表和客户信息表的查询反馈结果函数
*  @param  [IN] type 返回的记录的类型
*  @param  [IN] pLP 查询的车辆信息记录
*  @param  [IN] pCustomer 查询的客户信息记录
*  @param  [IN] pUserData 回调函数中的上下文
*  @ingroup group_callback
*/
typedef void(__STDCALL *VZLPRC_WLIST_QUERY_CALLBACK)(VZLPRC_WLIST_CB_TYPE type, const VZ_LPR_WLIST_VEHICLE *pLP, \
														  const VZ_LPR_WLIST_CUSTOMER *pCustomer,    \
														  void *pUserData);


/**白名单字段名称，查询时使用*/
const  char VZLPRC_WLIST_COL_TIME_ON_CREATE[]	= "timeOnCreate";
const  char VZLPRC_WLIST_COL_TIME_ENABLE[]		= "timeEnable";
const  char VZLPRC_WLIST_COL_TIME_OVERDUE[]		= "timeOverdue";
const  char VZLPRC_WLIST_COL_ENABLE[]			= "enable";
const  char VZLPRC_WLIST_COL_LP[]				= "PlateID";
const  char VZLPRC_WLIST_COL_USING_TIME_SEC[]	= "usingTimeSeg";
const  char VZLPRC_WLIST_COL_TIME_SEG[]			= "timeSeg";
const  char VZLPRC_WLIST_COL_NEED_ALARM[]		= "needAlarm";
const  char VZLPRC_WLIST_COL_CUSTOM_ID[]		= "CustomerID";
const  char VZLPRC_WLIST_COL_CUSTOM_NAME[]		= "Name";
const  char VZLPRC_WLIST_COL_CUSTOM_IDCODE[]	= "Code";
const  char VZLPRC_WLIST_COL_VEHICLE_ID[]		= "keyIndex";
const  char VZLPRC_WLIST_COL_VEHICLE_IDCODE[]		= "VehicleCode";
const  char VZLPRC_WLIST_COL_VEHICLE_COLOR[]		= "Color";
const  char VZLPRC_WLIST_COL_VEHICLE_PLATETYPE[]	= "PlateType";
const  char VZLPRC_WLIST_COL_VEHICLE_COMMENT[]	= "VehicleComment";

#endif
