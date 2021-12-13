
 
//==============�ڰ������õ����ݽṹ���궨��=============
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

/**����ʱ������*/
typedef struct
{
	short nYear;	/**<��*/
	short nMonth;	/**<��*/
	short nMDay;	/**<��*/
	short nHour;	/**<ʱ*/
	short nMin;		/**<��*/
	short nSec;		/**<��*/
}
VZ_TM;

/**һ�������ѡ����Ĥ*/
typedef struct
{
	char bSun;		/**<����*/
	char bMon;		/**<��һ*/
	char bTue;		/**<�ܶ�*/
	char bWed;		/**<����*/
	char bThur;		/**<����*/
	char bFri;		/**<����*/
	char bSat;		/**<����*/
	char reserved;
}
VZ_TM_WEEK_DAY;

/**һ���е�ʱ����*/
typedef struct
{
	short nHour;
	short nMin;
	short nSec;
	short reserved;
}
VZ_TM_DAY;

/**ʱ�����Ϣ*/
typedef struct
{
	unsigned		uEnable;
	VZ_TM_WEEK_DAY	struDaySelect;		/**<һ���ڵ�����ѡ��*/
	VZ_TM_DAY		struDayTimeStart;	/**ÿ���ʱ�����*/
	VZ_TM_DAY		struDayTimeEnd;		/**ÿ���ʱ���յ�*/
}
VZ_TM_WEEK_SEGMENT;

typedef struct
{
	VZ_TM		struTimeStart;		/**ÿ���ʱ�����*/
	VZ_TM		struTimeEnd;		/**ÿ���ʱ���յ�*/
}
VZ_TM_RANGE;

typedef struct
{
	unsigned			uEnable;										/**�Ƿ���*/
	VZ_TM_WEEK_SEGMENT  struWeekSeg[VZ_LPR_WLIST_TIME_SEG_MAX_NUM];		/**����ʱ�������*/
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

/**�ڰ������еĳ�����¼*/
typedef struct
{
	unsigned	uVehicleID;										/**<���������ݿ��ID*/
	char		strPlateID[VZ_LPR_WLIST_LP_MAX_LEN];			/**<�����ַ���*/
	unsigned	uCustomerID;									/**<�ͻ������ݿ��ID����VZ_LPR_WLIST_CUSTOMER::uCustomerID��Ӧ*/
	unsigned	bEnable;										/**<�ü�¼��Ч���*/
	unsigned	bEnableTMEnable;								/**<�Ƿ�����Чʱ��*/
	unsigned	bEnableTMOverdule;								/**<�Ƿ�������ʱ��*/
	VZ_TM		struTMEnable;									/**<�ü�¼��Чʱ��*/
	VZ_TM		struTMOverdule;									/**<�ü�¼����ʱ��*/
	unsigned	bUsingTimeSeg;									/**<�Ƿ�ʹ������ʱ���*/
	VZ_TM_PERIOD struTimeSeg;									/**<����ʱ�����Ϣ*/
	unsigned	bAlarm;											/**<�Ƿ񴥷���������������¼��*/
	int			iColor;											/**<������ɫ*/
	int			iPlateType;										/**<��������*/
	char		strCode[VZ_LPR_WLIST_VEHICLE_CODE_LEN];			/**<��������*/
	char		strComment[VZ_LPR_WLIST_VEHICLE_COMMENT_LEN];	/**<��������*/
}
VZ_LPR_WLIST_VEHICLE;

#define VZ_LPR_WLIST_CUSTOMER_NAME_LEN		32
#define VZ_LPR_WLIST_CUSTOMER_CODE_LEN		32

/**�ڰ�������¼�Ŀͻ���Ϣ*/
typedef struct
{
	unsigned	uCustomerID;			/**<�ͻ������ݿ��ID�������޸ġ�ɾ��������������*/
	char		strName[VZ_LPR_WLIST_CUSTOMER_NAME_LEN];	/**<�ͻ�����*/
	char		strCode[VZ_LPR_WLIST_CUSTOMER_CODE_LEN];	/**<�ͻ�����*/

	char		reserved[256];
}
VZ_LPR_WLIST_CUSTOMER;

/**�ͻ����䳵���е�һ���ϳɵ�һ������*/
typedef struct
{
	VZ_LPR_WLIST_CUSTOMER *pCustomer;			/**<�ͻ�*/
	VZ_LPR_WLIST_VEHICLE *pVehicle;				/**<����������Ϊ��*/
}
VZ_LPR_WLIST_ROW;

/**������������*/
typedef struct
{
	char						key[VZ_LPR_WLIST_MAX_KEY_LEN];							/**<���ҵ��ֶ�*/
	char						search_string[VZ_LPR_WLIST_MAX_SEARCH_STRING_LEN];		/**<���ҵ��ַ���*/
}
VZ_LPR_WLIST_SEARCH_CONSTRAINT;

typedef enum
{
	VZ_LPR_WLIST_LIMIT_TYPE_ONE,						/**<����һ��*/
	VZ_LPR_WLIST_LIMIT_TYPE_ALL,						/**<��������*/
	VZ_LPR_WLIST_LIMIT_TYPE_RANGE						/**<����һ��*/
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
	VZ_LPR_WLIST_LIMIT_TYPE				limitType;					/**<������������*/
	VZ_LPR_WLIST_RANGE_LIMIT			*pRangeLimit;				/**<������һ�����ݣ���limitTypeΪVZ_LPR_WLIST_LIMIT_TYPE_RANGEʱ������*/
}
VZ_LPR_WLIST_LIMIT;

typedef enum
{
	VZ_LPR_WLIST_SORT_DIRECTION_DESC=0,
	VZ_LPR_WLIST_SORT_DIRECTION_ASC=1,
}
VZ_LPR_WLIST_SORT_DIRECTION;

/**��������з�ʽ*/
typedef struct
{
	char	key[VZ_LPR_WLIST_MAX_KEY_LEN];
	VZ_LPR_WLIST_SORT_DIRECTION direction;
}
VZ_LPR_WLIST_SORT_TYPE;

/**�������ݷ�ʽ*/
typedef enum{
	VZ_LPR_WLIST_SEARCH_TYPE_LIKE,				/**<�����ַ�*/
	VZ_LPR_WLIST_SEARCH_TYPE_EQUAL				/**<��ȫƥ��*/
}
VZ_LPR_WLIST_SEARCH_TYPE;

typedef struct{
	VZ_LPR_WLIST_SEARCH_TYPE			searchType;					/**<���ҵķ�ʽ���������ȫƥ�䣬ÿ������֮��Ϊ�룬�ǰ���ʱ��ÿ������֮��Ϊ��*/
	unsigned int						searchConstraintCount;		/**<��������������Ϊ0��ʾû����������*/
	VZ_LPR_WLIST_SEARCH_CONSTRAINT*		pSearchConstraints;			/**<������������ָ��*/
}
VZ_LPR_WLIST_SEARCH_WHERE;

typedef struct
{
	VZ_LPR_WLIST_SEARCH_WHERE			*pSearchWhere;				/**<��������*/
	VZ_LPR_WLIST_LIMIT					*pLimit;					/**<������������*/
	VZ_LPR_WLIST_SORT_TYPE				*pSortType;					/**<���������ʽ��Ϊ�ձ�ʾ��Ĭ������*/
}
VZ_LPR_WLIST_LOAD_CONDITIONS;

/**�����id����������*/
typedef struct
{
	char	key[VZ_LPR_WLIST_MAX_KEY_LEN];
	char	name[VZ_LPR_WLIST_MAX_KEY_LEN];
}
VZ_LPR_WLIST_KEY_DEFINE;

/**�����������ʵ������*/
typedef struct
{
	int		iValue;
	char	strValue[VZ_LPR_WLIST_MAX_ENUM_VALUE_LEN];
}
VZ_LPR_WLIST_ENUM_VALUE;

/**��������ÿ�еĽ��*/
typedef struct
{
	int ret;
	int error_code;
}
VZ_LPR_WLIST_IMPORT_RESULT;

typedef enum{
	VZLPRC_WLIST_CB_TYPE_ROW = 0,				/**<���ϲ�ѯ�Ľ������*/
	VZLPRC_WLIST_CB_TYPE_CUSTOMER,				/**<�ͻ���Ϣ��ѯ�Ľ������*/
	VZLPRC_WLIST_CB_TYPE_VEHICLE				/**<������Ϣ��ѯ�Ľ������*/
}
VZLPRC_WLIST_CB_TYPE;

#ifdef WIN32
#define __STDCALL __stdcall
#else
#define __STDCALL
#endif

/**
*  @brief ��������Ϳͻ���Ϣ��Ĳ�ѯ�����������
*  @param  [IN] type ���صļ�¼������
*  @param  [IN] pLP ��ѯ�ĳ�����Ϣ��¼
*  @param  [IN] pCustomer ��ѯ�Ŀͻ���Ϣ��¼
*  @param  [IN] pUserData �ص������е�������
*  @ingroup group_callback
*/
typedef void(__STDCALL *VZLPRC_WLIST_QUERY_CALLBACK)(VZLPRC_WLIST_CB_TYPE type, const VZ_LPR_WLIST_VEHICLE *pLP, \
														  const VZ_LPR_WLIST_CUSTOMER *pCustomer,    \
														  void *pUserData);


/**�������ֶ����ƣ���ѯʱʹ��*/
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
