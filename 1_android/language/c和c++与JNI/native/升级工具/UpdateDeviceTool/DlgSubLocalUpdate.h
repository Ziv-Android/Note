#pragma once
#include "afxwin.h"
#include "MaintenTool.h"
#include "UpdateDevice.h"
#include "LocalDevice.h"

#include <atomic>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;

class CDlgSubLocalUpdate : public CDialog
{
	DECLARE_DYNAMIC(CDlgSubLocalUpdate)

public:
	CDlgSubLocalUpdate(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgSubLocalUpdate();

// Dialog Data
	enum { IDD = IDD_DLG_LOCAL_UPDATE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	afx_msg LRESULT OnUserMsg(WPARAM w,LPARAM l);
	afx_msg LRESULT OnShowVersionMsg(WPARAM w, LPARAM l);
	afx_msg void OnBnClickedBtnSearchDevice();
	afx_msg void OnCustomdrawList(NMHDR*, LRESULT*);
	afx_msg void OnLvnColumnclickListMultiIp(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickListMultiIp(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedBtnMultiUpdate();
	afx_msg LRESULT OnUpdateMsg(WPARAM w, LPARAM l);
	afx_msg LRESULT OnProcessMsg(WPARAM w, LPARAM l);
    afx_msg void OnNMDblclkListMultiIp(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg LRESULT OnImportMsg(WPARAM w, LPARAM l);
    afx_msg void OnClose();
    virtual void OnOK();
    afx_msg void OnBnClickedBtnUpdateIp();
    afx_msg void OnBnClickedBtnBrow();
    afx_msg void OnBnClickedBtnParam();
    afx_msg void OnBnClickedBtnMultiUpdateDevice();
    afx_msg void OnCbnSelchangeCmbVersion();
	DECLARE_MESSAGE_MAP()

public:
	void GetDeviceVersion();
	bool GetNoVersionDevice(LocalDeviceInfo &device_info);
	bool GetVersionProc(LocalDeviceInfo &device_info);
	void StopFindDevice();
	bool ShowUpdateStauts(CString ip, CString strStatus);
	bool ShowUpdateProcess(CString ip, CString strStatus);
	void SetCtrlEnable(BOOL enable);

	void MutiUpdateDevices();
	bool GetNotUpdateDevice(LocalDeviceInfo &device_info);
    bool GetUpdateDevice(std::string ip, LocalDeviceInfo &device_info);

    void ImportParam(VzLPRClientHandle handle, int level, LocalDeviceInfo &device_info);
    void UpdateDeviceInfo(std::string device_ip, std::string version);
    bool IsDeviceInfoSuitable(LocalDeviceInfo *device_info);
    bool FindDeviceItem(std::string device_ip);
    void AddDevice(LocalDeviceInfo *device_info);

    void ShowDeviceCount();

private:
	CListCtrl m_oMultiIPList;

	int m_nSelectCount;
	int m_nSuccessCount;
	int m_nFailedCount;

	CString m_strMultiStatus;

	std::vector<LocalDeviceInfo> m_vecSearchDevice;
	std::mutex m_mtxGetVerion;

    std::thread m_VersionThread;
	bool m_get_version;

	static const int MAX_THREAD_COUNT = 10;
    std::thread m_MutiUpdateThreads[MAX_THREAD_COUNT];

	std::vector<LocalDeviceInfo> m_vecUpdateDevice;
    std::mutex m_mtxMutiUpdate;
	BOOL m_SearchFlag;

    static const int MAX_IMPORT_COUNT = 2;
    std::thread import_thread_[MAX_IMPORT_COUNT];
    int time_count_;
    std::atomic<bool>  import_param_;
    CButton m_btn_check;
    CButton search_button_;
    CEdit update_file_edit_;
    CString update_file_path_;

    CEdit param_file_edit_;
    CString import_file_path_;  
    CComboBox version_combo_;
    CStatic count_lable_;
};
