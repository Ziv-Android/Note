#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "LocalDevice.h"
#include <vector>

// CUpdateIPDlg �Ի���

class CUpdateIPDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CUpdateIPDlg)

public:
	CUpdateIPDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CUpdateIPDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
  virtual BOOL OnInitDialog();
  CComboBox m_cmbType;
  CIPAddressCtrl m_ipaddrIP;
  CIPAddressCtrl m_ipaddrMask;
  CIPAddressCtrl m_ipaddrGateway;
  afx_msg void OnBnClickedOk();

  std::vector<LocalDeviceInfo> update_devices;
};
