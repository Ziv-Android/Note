// UpdateIPDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MaintenTool.h"
#include "UpdateIPDlg.h"
#include "afxdialogex.h"
#include "VzLPRClientSDK.h"
#include <thread>

// CUpdateIPDlg �Ի���

IMPLEMENT_DYNAMIC(CUpdateIPDlg, CDialogEx)

CUpdateIPDlg::CUpdateIPDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CUpdateIPDlg::IDD, pParent)
{

}

CUpdateIPDlg::~CUpdateIPDlg()
{
}

void CUpdateIPDlg::DoDataExchange(CDataExchange* pDX)
{
  CDialogEx::DoDataExchange(pDX);
  DDX_Control(pDX, IDC_CMB_TYPE, m_cmbType);
  DDX_Control(pDX, IDC_IPADDRESS1, m_ipaddrIP);
  DDX_Control(pDX, IDC_IPADDRESS2, m_ipaddrMask);
  DDX_Control(pDX, IDC_IPADDRESS3, m_ipaddrGateway);
}


BEGIN_MESSAGE_MAP(CUpdateIPDlg, CDialogEx)
  ON_BN_CLICKED(IDOK, &CUpdateIPDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CUpdateIPDlg ��Ϣ�������


BOOL CUpdateIPDlg::OnInitDialog()
{
  CDialogEx::OnInitDialog();

  m_cmbType.AddString("IP����");
  m_cmbType.AddString("�̶�IP");
  m_cmbType.SetCurSel(0);

  m_ipaddrIP.SetWindowText("192.168.1.100");
  m_ipaddrMask.SetWindowText("255.255.255.0");
  m_ipaddrGateway.SetWindowText("192.168.1.1");

  return TRUE;  
}


void CUpdateIPDlg::OnBnClickedOk()
{
  int size = update_devices.size();

  CString strIP;
  m_ipaddrIP.GetWindowText(strIP);

  CString strNetmask;
  m_ipaddrMask.GetWindowText(strNetmask);

  CString strGateway;
  m_ipaddrGateway.GetWindowText(strGateway);

  DWORD ipStartNum;
  m_ipaddrIP.GetAddress(ipStartNum);

  for (auto item : update_devices) {
    if (m_cmbType.GetCurSel() == 1) {
      VzLPRClient_UpdateNetworkParam(item.SH, item.SL, strIP.GetBuffer(0), strGateway.GetBuffer(0), strNetmask.GetBuffer(0));
    }
    else 
    {
      in_addr  ia;
      ia.S_un.S_un_b.s_b1 = (ipStartNum >> 24) & 0xFF;
      ia.S_un.S_un_b.s_b2 = (ipStartNum >> 16) & 0xFF;
      ia.S_un.S_un_b.s_b3 = (ipStartNum >> 8) & 0xFF;
      ia.S_un.S_un_b.s_b4 = (ipStartNum)& 0xFF;
      if (ia.S_un.S_un_b.s_b4 < 1 || ia.S_un.S_un_b.s_b4 > 253)
      {
        ipStartNum++;
        continue;
      }

      char *newIp = inet_ntoa(ia);
      VzLPRClient_UpdateNetworkParam(item.SH, item.SL, newIp, strGateway.GetBuffer(0), strNetmask.GetBuffer(0));

      ipStartNum++;
    }
    
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }

  MessageBox(_T("�޸�����������"), _T("��ʾ"), MB_OK);
  CDialogEx::OnOK();
}
