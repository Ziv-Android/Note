// MaintenToolDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "VzLPRClientSDK.h"

#include "DlgSubLocalUpdate.h"

#include <vector>
#include <string>
using namespace std;

const int UPDATE_THREAD_COUNT	= 5;

// CMaintenToolDlg 对话框
class CMaintenToolDlg : public CDialog
{
// 构造
public:
	CMaintenToolDlg(CWnd* pParent = NULL);	// 标准构造函数
	~CMaintenToolDlg();
	
	// 对话框数据
	enum { IDD = IDD_MAINTENTOOL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	
	void initData();

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();	
	afx_msg void OnTcnSelchangeTabType(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClose();
	DECLARE_MESSAGE_MAP()

public:
	CTabCtrl m_tabType;

	CDlgSubLocalUpdate m_dlgSubLocalUpdate;

	static const int MAX_NUM_TAB_COUNT = 1;
	CDialog* m_subDlgs[MAX_NUM_TAB_COUNT];

	int m_curSel;
    virtual BOOL PreTranslateMessage(MSG* pMsg);
};
