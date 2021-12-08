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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

	// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	// ʵ��
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


// CMaintenToolDlg �Ի���
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


// CMaintenToolDlg ��Ϣ�������

BOOL CMaintenToolDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_tabType.InsertItem(0,"�豸����");
	// m_tabType.InsertItem(1,"��ƽ̨����");

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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMaintenToolDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
    case   VK_RETURN://���λس�
      return   TRUE;
    case   VK_ESCAPE://����Esc
      return   TRUE;
    }
  }

  return CDialog::PreTranslateMessage(pMsg);
}
