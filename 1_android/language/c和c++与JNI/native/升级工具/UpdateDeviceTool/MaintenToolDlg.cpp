#include "stdafx.h"
#include "MaintenTool.h"
#include "MaintenToolDlg.h"
#include <winsock.h>
#include <io.h>
#include <ShlObj.h>
#include <fstream>

#include <vector>
#include <string>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


enum
{
	MSG_DEV_FOUND = 1,
};


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

	// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)	
END_MESSAGE_MAP()


// CMaintenToolDlg 对话框
CMaintenToolDlg::CMaintenToolDlg(CWnd* pParent /*=NULL*/)
: CDialog(CMaintenToolDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	initData();
}

CMaintenToolDlg::~CMaintenToolDlg()
{

}

void CMaintenToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_TYPE, m_tabType);
}

void CMaintenToolDlg::initData()
{
	int nRet = VzLPRClient_Setup();	
}

BEGIN_MESSAGE_MAP(CMaintenToolDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_CLOSE()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_TYPE, &CMaintenToolDlg::OnTcnSelchangeTabType)
END_MESSAGE_MAP()


// CMaintenToolDlg 消息处理程序

BOOL CMaintenToolDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_tabType.InsertItem(0,"设备操作");
	// m_tabType.InsertItem(1,"云平台升级");

	m_dlgSubLocalUpdate.Create(m_dlgSubLocalUpdate.IDD,&m_tabType);
	// m_dlgSubRemoteUpdate.Create(m_dlgSubRemoteUpdate.IDD, &m_tabType);

	m_subDlgs[0] = &m_dlgSubLocalUpdate;
	// m_subDlgs[1] = &m_dlgSubRemoteUpdate;

	CRect rc;
	m_tabType.GetClientRect(&rc);
	m_tabType.AdjustRect(FALSE, &rc);
	for(int i=0;i<MAX_NUM_TAB_COUNT;i++)
	{
		if (m_subDlgs[i]) 
		{
			m_subDlgs[i]->MoveWindow(rc,0);
		}
	}

	m_curSel = 0;
	m_subDlgs[m_curSel]->ShowWindow(SW_SHOW);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMaintenToolDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMaintenToolDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMaintenToolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMaintenToolDlg::OnClose()
{
	m_dlgSubLocalUpdate.StopFindDevice();
	VzLPRClient_Cleanup();

	CDialog::OnClose();
}

void CMaintenToolDlg::OnTcnSelchangeTabType(NMHDR *pNMHDR, LRESULT *pResult)
{
	if(m_subDlgs[m_curSel]!=NULL){
		m_subDlgs[m_curSel]->ShowWindow(SW_HIDE);
	}

	m_curSel = m_tabType.GetCurSel();
	if ( m_subDlgs[m_curSel] != NULL )
	{
		m_subDlgs[m_curSel]->ShowWindow(SW_SHOW);
	}

	*pResult = 0;
}


BOOL CMaintenToolDlg::PreTranslateMessage(MSG* pMsg)
{
  if (pMsg->message == WM_KEYDOWN)
  {
    switch (pMsg->wParam)
    {
    case   VK_RETURN://屏蔽回车
      return   TRUE;
    case   VK_ESCAPE://屏蔽Esc
      return   TRUE;
    }
  }

  return CDialog::PreTranslateMessage(pMsg);
}
