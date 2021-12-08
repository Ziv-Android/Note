// DlgSubVideoCfgR1.cpp : implementation file
//

#include "stdafx.h"
#include "DlgSubLocalUpdate.h"
#include "VzLPRClientSDK.h"
#include "VzFile.h"
#include "UpdateIPDlg.h"
#include <json/json.h>
#include <mutex>

std::mutex _search_devce_mutex;
std::vector<LocalDeviceInfo> _search_device;

void __stdcall findFunc(const char *pStrDevName, const char *pStrIPAddr,
  WORD usPort1, WORD usPort2, unsigned int SL, unsigned int SH, char* netmask, char* gateway, void *pUserData)
{
  CDlgSubLocalUpdate* pToolDlg = static_cast<CDlgSubLocalUpdate*>(pUserData);
  if (!pToolDlg)
    return;


  string* sIP = new string;
  sIP->append(pStrIPAddr);
  ::PostMessage(pToolDlg->GetSafeHwnd(), WM_USER_MSG, (WPARAM)usPort1, (LPARAM)sIP);

  LocalDeviceInfo device_info;
  device_info.ip = *sIP;
  device_info.SH = SH;
  device_info.SL = SL;

  {
    std::lock_guard<std::mutex> lock(_search_devce_mutex);
    _search_device.push_back(device_info);
  }
}

// CDlgSubVideoCfgR1 dialog

IMPLEMENT_DYNAMIC(CDlgSubLocalUpdate, CDialog)

CDlgSubLocalUpdate::CDlgSubLocalUpdate(CWnd* pParent /*=NULL*/)
  : CDialog(CDlgSubLocalUpdate::IDD, pParent)
{
  m_get_version = false;

  m_nSelectCount = 0;
  m_nSuccessCount = 0;
  m_nFailedCount = 0;
  import_param_ = false;
}

CDlgSubLocalUpdate::~CDlgSubLocalUpdate()
{

}

void CDlgSubLocalUpdate::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);

  DDX_Control(pDX, IDC_LIST_MULTI_IP, m_oMultiIPList);
  DDX_Text(pDX, IDC_LBL_MULTI_STATUS, m_strMultiStatus);
  DDX_Control(pDX, IDC_BTN_MULTI_UPDATE, m_btn_check);
  DDX_Control(pDX, IDC_BTN_SEARCH_DEVICE, search_button_);
  DDX_Control(pDX, IDC_UPDATE_FILE_EDIT, update_file_edit_);
  DDX_Control(pDX, IDC_PARAM_FILE_EDIT, param_file_edit_);
  DDX_Control(pDX, IDC_CMB_VERSION, version_combo_);
  DDX_Control(pDX, IDC_LBL_TOTAL, count_lable_);
}


BEGIN_MESSAGE_MAP(CDlgSubLocalUpdate, CDialog)
  ON_MESSAGE(WM_IMPORT_MSG, &CDlgSubLocalUpdate::OnImportMsg)
  ON_MESSAGE(WM_USER_MSG, &CDlgSubLocalUpdate::OnUserMsg)
  ON_NOTIFY(NM_CUSTOMDRAW, IDC_LIST_MULTI_IP, &CDlgSubLocalUpdate::OnCustomdrawList)
  ON_BN_CLICKED(IDC_BTN_SEARCH_DEVICE, &CDlgSubLocalUpdate::OnBnClickedBtnSearchDevice)
  ON_MESSAGE(WM_VERSION_MSG, &CDlgSubLocalUpdate::OnShowVersionMsg)
  ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST_MULTI_IP, &CDlgSubLocalUpdate::OnLvnColumnclickListMultiIp)
  ON_NOTIFY(NM_CLICK, IDC_LIST_MULTI_IP, &CDlgSubLocalUpdate::OnNMClickListMultiIp)
  ON_BN_CLICKED(IDC_BTN_MULTI_UPDATE, &CDlgSubLocalUpdate::OnBnClickedBtnMultiUpdate)
  ON_MESSAGE(WM_UPDATE_MSG, &CDlgSubLocalUpdate::OnUpdateMsg)
  ON_MESSAGE(WM_PROCESS_MSG, &CDlgSubLocalUpdate::OnProcessMsg)
  ON_NOTIFY(NM_DBLCLK, IDC_LIST_MULTI_IP, &CDlgSubLocalUpdate::OnNMDblclkListMultiIp)
  ON_WM_CLOSE()
  ON_BN_CLICKED(IDC_BTN_UPDATE_IP, &CDlgSubLocalUpdate::OnBnClickedBtnUpdateIp)
  ON_BN_CLICKED(IDC_BTN_BROW, &CDlgSubLocalUpdate::OnBnClickedBtnBrow)
  ON_BN_CLICKED(IDC_BTN_PARAM, &CDlgSubLocalUpdate::OnBnClickedBtnParam)
  ON_BN_CLICKED(IDC_BTN_MULTI_UPDATE_DEVICE, &CDlgSubLocalUpdate::OnBnClickedBtnMultiUpdateDevice)
  ON_CBN_SELCHANGE(IDC_CMB_VERSION, &CDlgSubLocalUpdate::OnCbnSelchangeCmbVersion)
END_MESSAGE_MAP()


// CDlgSubLocalUpdate message handlers
BOOL CDlgSubLocalUpdate::OnInitDialog()
{
  CDialog::OnInitDialog();

  m_oMultiIPList.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);
  m_oMultiIPList.InsertColumn(0, "全选", LVCFMT_CENTER, 50);
  m_oMultiIPList.InsertColumn(1, "设备IP", LVCFMT_LEFT, 120);
  m_oMultiIPList.InsertColumn(2, "端口", LVCFMT_LEFT, 50);
  m_oMultiIPList.InsertColumn(3, "设备版本", LVCFMT_LEFT, 160);
  m_oMultiIPList.InsertColumn(4, "升级进度", LVCFMT_LEFT, 440);
  m_oMultiIPList.InsertColumn(5, "参数导入结果", LVCFMT_LEFT, 120);

  version_combo_.AddString("全部软件版本");
  version_combo_.SetCurSel(0);

  m_SearchFlag = FALSE;
  return TRUE;
}

void CDlgSubLocalUpdate::OnCancel()
{
  // CDialog::OnCancel();
}

// 搜索本地设备
void CDlgSubLocalUpdate::OnBnClickedBtnSearchDevice()
{
  CString button_text;
  search_button_.GetWindowText(button_text);

  if (button_text == "开始搜索") {
    search_button_.SetWindowText("停止搜索");

    if (m_SearchFlag) {
      StopFindDevice();
    }

    m_oMultiIPList.DeleteAllItems();
    m_vecSearchDevice.clear();

    VZLPRClient_StartFindDeviceEx(findFunc, this);

    m_SearchFlag = TRUE;
    m_get_version = true;

    if (m_VersionThread.joinable()) {
      m_VersionThread.join();
    }

    m_VersionThread = std::thread([&]() {
      GetDeviceVersion();
      });
  }
  else {
    search_button_.SetWindowText("开始搜索");

    VZLPRClient_StopFindDevice();
    m_SearchFlag = FALSE;
  }
}

void split(std::string& s, std::string& delim, std::vector< std::string >* ret)
{
  size_t last = 0;
  size_t index = s.find_first_of(delim, last);

  while (index != std::string::npos)
  {
    ret->push_back(s.substr(last, index - last));
    last = index + 1;
    index = s.find_first_of(delim, last);
  }

  if (index - last > 0)
  {
    ret->push_back(s.substr(last, index - last));
  }
}

bool lessthen(const std::string& ip1, const std::string& ip2)
{
  vector<string> ipVec1;
  split(string(ip1), string("."), &ipVec1);

  vector<string> ipVec2;
  split(string(ip2), string("."), &ipVec2);

  if (ipVec1.size() == 4 && ipVec2.size() == 4)
  {
    for (int nIndex = 0; nIndex < 4; ++nIndex)
    {
      int nVal1 = atoi(ipVec1[nIndex].c_str());
      int nVal2 = atoi(ipVec2[nIndex].c_str());
      if (nVal1 < nVal2)
        return true;
      else if (nVal1 > nVal2)
        return false;
    }
  }
  return false;
}


void CDlgSubLocalUpdate::AddDevice(LocalDeviceInfo *device_info) {
  int nIndex = 0;
  //根据IP大小进行排序
  //插入到链表的中间部分
  for (int it = 0; it < m_oMultiIPList.GetItemCount(); ++it)
  {
    CString strCompareIP = m_oMultiIPList.GetItemText(it, 1);
    string cur_ip(strCompareIP.GetBuffer(0));
    if (lessthen(device_info->ip, cur_ip))
    {
      break;
    }
    ++nIndex;
  }

  m_oMultiIPList.InsertItem(nIndex, "");
  m_oMultiIPList.SetItemState(nIndex, LVNI_FOCUSED | LVIS_SELECTED, LVNI_FOCUSED | LVIS_SELECTED);
  m_oMultiIPList.SetItemText(nIndex, 1, (LPCTSTR)device_info->ip.c_str());
  if (device_info->version != "") {
    m_oMultiIPList.SetItemText(nIndex, 3, device_info->version.c_str());
  }

  char szPort[32] = { 0 };
  sprintf_s(szPort, "%d", device_info->port);
  m_oMultiIPList.SetItemText(nIndex, 2, szPort);
}

LRESULT CDlgSubLocalUpdate::OnUserMsg(WPARAM w, LPARAM l)
{
  int port = (int)w;

  string* sIP = reinterpret_cast<string*> (l);
  if (sIP)
  {
    LocalDeviceInfo device_info;
    device_info.ip = *sIP;
    device_info.port = port;

    if (version_combo_.GetCurSel() == 0) {
      AddDevice(&device_info);
      ShowDeviceCount();
    }

    {
      std::lock_guard<std::mutex> lock(m_mtxGetVerion);
      m_vecSearchDevice.push_back(device_info);
    }

    delete sIP;
  }

  return 0;
}

void CDlgSubLocalUpdate::OnCustomdrawList(NMHDR *pNMHDR, LRESULT *pResult)
{
  NMLVCUSTOMDRAW* pLVCD = reinterpret_cast<NMLVCUSTOMDRAW*>(pNMHDR);

  if (CDDS_PREPAINT == pLVCD->nmcd.dwDrawStage)
  {
    *pResult = CDRF_NOTIFYITEMDRAW;
  }
  else if (CDDS_ITEMPREPAINT == pLVCD->nmcd.dwDrawStage)
  {
    COLORREF crBk;

    int nItem = (pLVCD->nmcd.dwItemSpec);

    int value = (int)m_oMultiIPList.GetItemData(nItem);
    if (value > 0 && value <= 3)
    {
      if (value == 1)
      {
        crBk = RGB(96, 123, 139);
      }
      else if (value == 2)
      {
        crBk = RGB(64, 224, 205);
      }
      else
      {
        crBk = RGB(255, 127, 80);
      }

      pLVCD->clrTextBk = crBk;
    }

    *pResult = CDRF_NEWFONT;
  }
}

void CDlgSubLocalUpdate::GetDeviceVersion()
{
  while (m_get_version)
  {
    LocalDeviceInfo devcie_info;
    if (GetNoVersionDevice(devcie_info))
    {
      if (GetVersionProc(devcie_info))
      {
        UpdateDeviceInfo(devcie_info.ip, devcie_info.version);
        LocalDeviceInfo *device_version = new LocalDeviceInfo(devcie_info);

        ::PostMessage(this->GetSafeHwnd(), WM_VERSION_MSG, (WPARAM)device_version, (LPARAM)NULL);
      }
    }

    Sleep(20);
  }
}

void CDlgSubLocalUpdate::UpdateDeviceInfo(std::string device_ip, std::string version) {
  std::lock_guard<std::mutex> lock(m_mtxGetVerion);
  for (auto& item : m_vecSearchDevice) {
    if (item.ip == device_ip) {
      item.version = version;
      break;
    }
  }
}

bool CDlgSubLocalUpdate::GetNoVersionDevice(LocalDeviceInfo &device_info)
{
  bool ret = false;

  std::lock_guard<std::mutex> lock(m_mtxGetVerion);

  int device_count = m_vecSearchDevice.size();
  for (int i = 0; i < device_count; i++)
  {
    if (!m_vecSearchDevice[i].get_version)
    {
      device_info = m_vecSearchDevice[i];
      m_vecSearchDevice[i].get_version = true;
      ret = true;
      break;
    }
  }

  return ret;
}

bool CDlgSubLocalUpdate::GetVersionProc(LocalDeviceInfo &device_info)
{
  bool ret = false;

  VzLPRClientHandle handle = VzLPRClient_Open(device_info.ip.c_str(), device_info.port, "admin", "admin");
  if (handle != NULL)
  {
    int ver1 = 0, ver2 = 0, ver3 = 0, ver4 = 0;
    for (int i = 0; i < 3; i++)
    {
      int result = VzLPRClient_GetRemoteSoftWareVersion(handle, &ver1, &ver2, &ver3, &ver4);
      if (result == 0)
      {
        break;
      }

      if (!m_get_version)
      {
        break;
      }

      Sleep(1000);
    }

    if (ver1 > 0)
    {
      char version[128] = { 0 };
      sprintf_s(version, sizeof(version), "%d.%d.%d.%d", ver1, ver2, ver3, ver4);
      device_info.version = version;

      ret = true;
    }

    VzLPRClient_Close(handle);
    handle = NULL;
  }

  return ret;
}

LRESULT CDlgSubLocalUpdate::OnShowVersionMsg(WPARAM w, LPARAM l)
{
  LocalDeviceInfo *device_version = (LocalDeviceInfo *)w;
  if (device_version != NULL)
  {
    // 没有找到对应ip, 先添加进去
    if (!FindDeviceItem(device_version->ip) && IsDeviceInfoSuitable(device_version)) {
      AddDevice(device_version);
      ShowDeviceCount();
    }

    for (int i = 0; i < m_oMultiIPList.GetItemCount(); ++i)
    {
      CString strIP = m_oMultiIPList.GetItemText(i, 1);
      if (strIP == device_version->ip.c_str())
      {
        m_oMultiIPList.SetItemText(i, 3, device_version->version.c_str());
      }
    }

    bool find = false;
    std::string version;

    for (int i = 0; i < version_combo_.GetCount(); i++) {
      CString item_version;
      version_combo_.GetLBText(i, item_version);
      
      int pos = device_version->version.find_last_of(".");
      if (pos > 0) {
        version = device_version->version.substr(0, pos);
      }

      if (strcmp(item_version.GetBuffer(0), version.c_str()) == 0) {
        find = true;
        break;
      }
    }

    if (!find && version != "") {
      version_combo_.AddString(version.c_str());
    }

    delete device_version;
    device_version = NULL;
  }

  return 0;
}

void CDlgSubLocalUpdate::StopFindDevice()
{
  VZLPRClient_StopFindDevice();
  m_get_version = false;
  if (m_VersionThread.joinable()) {
    m_VersionThread.join();
  }
}


void CDlgSubLocalUpdate::OnLvnColumnclickListMultiIp(NMHDR *pNMHDR, LRESULT *pResult)
{
  LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
  if (pNMLV->iSubItem == 0)
  {
    static BOOL bAllCheck = TRUE;

    for (int i = 0; i < m_oMultiIPList.GetItemCount(); ++i)
    {
      m_oMultiIPList.SetCheck(i, bAllCheck);
    }
    bAllCheck = !bAllCheck;
  }
}

void CDlgSubLocalUpdate::OnNMClickListMultiIp(NMHDR *pNMHDR, LRESULT *pResult)
{
  LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
  if (pNMItemActivate->iSubItem == 1)
  {
    CString strIP = m_oMultiIPList.GetItemText(pNMItemActivate->iItem, 1);
    if (strIP == "")
    {
      return;
    }
  }

  *pResult = 0;
}

void CDlgSubLocalUpdate::OnBnClickedBtnMultiUpdate()
{
  import_param_ = false;
  for (int i = 0; i < MAX_IMPORT_COUNT; i++) {
    if (import_thread_[i].joinable()) {
      import_thread_[i].join();
    }
  }

  param_file_edit_.GetWindowText(import_file_path_);
  if (import_file_path_ == "") {
    MessageBox("请选择待导入参数的文件", "提示", MB_OK);
    return;
  }

  m_nSelectCount = 0;
  m_nSuccessCount = 0;
  m_nFailedCount = 0;
  time_count_ = 0;

  int select_count = 0;
  import_param_ = true;

  m_vecUpdateDevice.clear();
  LocalDeviceInfo device_info;

  for (int i = 0; i < m_oMultiIPList.GetItemCount(); ++i)
  {
    if (!m_oMultiIPList.GetCheck(i))
      continue;

    CString strIP = m_oMultiIPList.GetItemText(i, 1);
    if (strIP == "") {
      return;
    }

    CString strPort = m_oMultiIPList.GetItemText(i, 2);
    int port = atoi(strPort.GetBuffer(0));

    m_oMultiIPList.SetItemText(i, 5, "正在导入");

    device_info.ip = strIP.GetBuffer(0);
    device_info.port = port;
    device_info.username = "admin";
    device_info.pwd = "admin";
    m_vecUpdateDevice.push_back(device_info);

    select_count++;
  }

  if (select_count > 0)
  {
    m_nSelectCount = select_count;

    char szMultiStatus[64] = { 0 };
    sprintf_s(szMultiStatus, sizeof(szMultiStatus), "共选择%d台", select_count);
    m_strMultiStatus = szMultiStatus;
    UpdateData(FALSE);
    SetCtrlEnable(FALSE);

    for (int i = 0; i < MAX_IMPORT_COUNT; i++) {
      import_thread_[i] = std::thread([&]() {
        LocalDeviceInfo device_info;
        while (GetNotUpdateDevice(device_info))
        {
          if (!import_param_) {
            break;
          }

          VzLPRClientHandle handle = VzLPRClient_Open(device_info.ip.c_str(), device_info.port, device_info.username.c_str(), device_info.pwd.c_str());
          if (handle != NULL && handle != -1) {
            if (import_param_) {
              ImportParam(handle, 0, device_info);
            }

            VzLPRClient_Close(handle);
          }
          else {
            const int kMaxIpLen = 32;
            char *ip = new char[kMaxIpLen];
            memset(ip, 0, kMaxIpLen);
            strcpy_s(ip, kMaxIpLen, device_info.ip.c_str());
            PostMessage(WM_IMPORT_MSG, (WPARAM)3, (LPARAM)ip);
          }
        }
        });
    }
  }
  else {
    MessageBox("请选择待导入参数的设备", "提示", MB_OK);
  }
}

void CDlgSubLocalUpdate::ImportParam(VzLPRClientHandle handle, int level, LocalDeviceInfo &device_info)
{
  const int kMaxIpLen = 32;
  char *ip = new char[kMaxIpLen];
  memset(ip, 0, kMaxIpLen);
  strcpy_s(ip, kMaxIpLen, device_info.ip.c_str());

  PostMessage(WM_IMPORT_MSG, (WPARAM)0, (LPARAM)ip);

  int ret_upload = -1;

  int ret = VzLPRClient_UpdateLoadFile(handle, import_file_path_.GetBuffer(0), 1);
  if (ret == 0)
  {
    for (int i = 0; i < 95; i++) {
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      ret_upload = VzLPRClient_GetUpdateLoadState(handle);
      if (ret_upload == 1) {
        break;
      }
      else if (ret_upload == -1) {
        break;
      }
    }
  }

  char *ip2 = new char[kMaxIpLen];
  memset(ip2, 0, kMaxIpLen);
  strcpy_s(ip2, kMaxIpLen, device_info.ip.c_str());

  if (ret_upload == 1)
  {
    PostMessage(WM_IMPORT_MSG, (WPARAM)1, (LPARAM)ip2);

    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    VzLPRClient_RebootDVR(handle);
  }
  else
  {
    PostMessage(WM_IMPORT_MSG, (WPARAM)2, (LPARAM)ip2);
  }
}

bool CDlgSubLocalUpdate::ShowUpdateStauts(CString ip, CString strStatus)
{
  bool ret = false;

  for (int i = 0; i < m_oMultiIPList.GetItemCount(); ++i)
  {
    CString strIP = m_oMultiIPList.GetItemText(i, 1);
    if (strIP == ip)
    {
      m_oMultiIPList.SetItemText(i, 4, strStatus);

      if (strStatus == "升级设备成功！")
      {
        std::string n_ip = ip.GetBuffer(0);
        VzLPRClientHandle handle = VzLPRClient_Open(n_ip.c_str(), 80, "admin", "admin");
        if (handle != NULL)
        {
          int ver1 = 0, ver2 = 0, ver3 = 0, ver4 = 0;

          int result = VzLPRClient_GetRemoteSoftWareVersion(handle, &ver1, &ver2, &ver3, &ver4);

          if (result == 0 && ver1 > 0)
          {
            char version[128] = { 0 };
            sprintf_s(version, sizeof(version), "%d.%d.%d.%d", ver1, ver2, ver3, ver4);

            m_oMultiIPList.SetItemText(i, 3, version);

            std::string s_version(version);
            UpdateDeviceInfo(n_ip, s_version);
          }

          VzLPRClient_Close(handle);
          handle = NULL;
        }

        m_oMultiIPList.SetItemData(i, (DWORD_PTR)2);
      }
      else
      {
        m_oMultiIPList.SetItemData(i, (DWORD_PTR)3);
      }

      ret = true;
    }
  }

  return ret;
}

bool CDlgSubLocalUpdate::ShowUpdateProcess(CString ip, CString strStatus)
{
  bool ret = false;

  for (int i = 0; i < m_oMultiIPList.GetItemCount(); ++i)
  {
    CString strIP = m_oMultiIPList.GetItemText(i, 1);
    if (strIP == ip)
    {
      m_oMultiIPList.SetItemText(i, 4, strStatus);
      m_oMultiIPList.SetItemData(i, (DWORD_PTR)1);

      ret = true;
    }
  }

  return ret;
}

void CDlgSubLocalUpdate::SetCtrlEnable(BOOL enable)
{
  GetDlgItem(IDC_BTN_SEARCH_DEVICE)->EnableWindow(enable);
  GetDlgItem(IDC_BTN_UPDATE_IP)->EnableWindow(enable);
  GetDlgItem(IDC_BTN_MULTI_UPDATE_DEVICE)->EnableWindow(enable);
  GetDlgItem(IDC_BTN_MULTI_UPDATE)->EnableWindow(enable);
  GetDlgItem(IDC_CMB_VERSION)->EnableWindow(enable);

  GetDlgItem(IDC_BTN_BROW)->EnableWindow(enable);
  GetDlgItem(IDC_BTN_PARAM)->EnableWindow(enable);

  CMenu *pSysMenu = GetSystemMenu(FALSE);
  if (pSysMenu != NULL)
  {
    if (enable) {
      pSysMenu->EnableMenuItem(SC_CLOSE, MF_ENABLED);
    }
    else {
      pSysMenu->EnableMenuItem(SC_CLOSE, MF_DISABLED);
    }
  }
}

LRESULT CDlgSubLocalUpdate::OnUpdateMsg(WPARAM w, LPARAM l)
{
  UpdateStatus *status = (UpdateStatus *)w;
  if (status == NULL)
  {
    return -1;
  }

  BOOL success = (BOOL)status->type;
  int param = (int)l;

  CString strMsg;
  if (success)
  {
    strMsg = "升级设备成功！";
    m_nSuccessCount++;
  }
  else
  {
    switch (param)
    {
    case 1:
      strMsg = "打开设备失败，请检查设备连接是否正常！";
      break;

    case 2:
      strMsg = "升级设备失败，未获取设备版本！";
      break;

    case 3:
      strMsg = "升级设备失败，未获取到对应升级镜像！";
      break;

    case 4:
      strMsg = "升级设备失败！";
      break;

    case 5:
      strMsg = "升级设备失败，升级版本后，重新获取版本号失败！";
      break;

    case 6:
      strMsg = "升级设备失败，升级前后版本号一样！";
      break;

    default:
      break;
    }

    m_nFailedCount++;
  }

  ShowUpdateStauts(status->ip, strMsg);

  delete status;

  if ((m_nFailedCount + m_nSuccessCount) == m_nSelectCount)
  {
    SetCtrlEnable(TRUE);

    m_strMultiStatus = "";
    UpdateData(FALSE);

    char szTotalMsg[128] = { 0 };
    sprintf_s(szTotalMsg, sizeof(szTotalMsg), "升级完成，成功%d台，失败%d台。", m_nSuccessCount, m_nFailedCount);
  }
  else
  {
    int cur_count = m_nFailedCount + m_nSuccessCount;

    char szMultiStatus[128] = { 0 };
    sprintf_s(szMultiStatus, sizeof(szMultiStatus), "共选择%d台，已升级%d台；成功%d台，失败%d台。", m_nSelectCount, cur_count, m_nSuccessCount, m_nFailedCount);

    m_strMultiStatus = szMultiStatus;
    UpdateData(FALSE);
  }


  return 0;
}

LRESULT CDlgSubLocalUpdate::OnProcessMsg(WPARAM w, LPARAM l)
{
  UpdateStatus *update_status = (UpdateStatus *)w;
  if (update_status == NULL)
  {
    return -1;
  }

  int status = update_status->type;
  char *file_name = (char *)l;
  char msg[128] = { 0 };

  CString cur_status;

  switch (status)
  {
  case 5:
    sprintf_s(msg, sizeof(msg), "正在升级'%s'", file_name);
    cur_status = msg;
    delete[] file_name;
    break;

  case 6:
    cur_status = "升级完成，正在重启设备";
    break;

  default:
    break;
  }


  // 更新升级信息到列表框中
  ShowUpdateProcess(update_status->ip, cur_status);

  delete update_status;

  return 0;
}

void CDlgSubLocalUpdate::MutiUpdateDevices()
{
  LocalDeviceInfo device_info;
  while (GetNotUpdateDevice(device_info))
  {
    VzLPRClientHandle handle = VzLPRClient_Open(device_info.ip.c_str(), device_info.port, device_info.username.c_str(), device_info.pwd.c_str());

    UpdateDevice update_obj;
    update_obj.UpdateDeviceProc(handle, device_info.ip, update_file_path_.GetBuffer(0), this->GetSafeHwnd());
  }
}

bool CDlgSubLocalUpdate::GetNotUpdateDevice(LocalDeviceInfo &device_info)
{
  bool ret = false;

  std::lock_guard<std::mutex> lock(m_mtxMutiUpdate);

  int device_count = m_vecUpdateDevice.size();
  for (int i = 0; i < device_count; i++)
  {
    if (!m_vecUpdateDevice[i].is_update)
    {
      device_info = m_vecUpdateDevice[i];
      m_vecUpdateDevice[i].is_update = true;
      ret = true;
      break;
    }
  }

  return ret;
}

void CDlgSubLocalUpdate::OnNMDblclkListMultiIp(NMHDR *pNMHDR, LRESULT *pResult)
{
  LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
  CString strIP = m_oMultiIPList.GetItemText(pNMItemActivate->iItem, 1);
  if (strIP == "") {
    return;
  }

  char cmd_line[128] = { 0 };

  CString strPort = m_oMultiIPList.GetItemText(pNMItemActivate->iItem, 2);
  int port = atoi(strPort.GetBuffer(0));
  if (port == 80) {
    sprintf_s(cmd_line, 128, "http://%s/", strIP.GetBuffer(0));
  }
  else {
    sprintf_s(cmd_line, 128, "http://%s:%d/", strIP.GetBuffer(0), port);
  }

  ShellExecute(NULL, "open", "iexplore.exe", cmd_line, NULL, SW_SHOWNORMAL);

  *pResult = 0;
}


LRESULT CDlgSubLocalUpdate::OnImportMsg(WPARAM w, LPARAM l)
{
  int result = (int)w;
  char *ip = (char*)l;
  if (ip) {
    CString result_text;
    if (result == 0) {
      result_text = "正在导入";
    }
    else if (result == 1) {
      result_text = "导入成功";
      m_nSuccessCount++;
    }
    else {
      if (result == 2) {
        result_text = "导入失败";
      }
      else {
        result_text = "登录设备失败";
      }

      m_nFailedCount++;
    }

    CString device_ip(ip);
    for (int i = 0; i < m_oMultiIPList.GetItemCount(); ++i)
    {
      CString strIP = m_oMultiIPList.GetItemText(i, 1);
      if (strIP == device_ip)
      {
        m_oMultiIPList.SetItemText(i, 5, result_text);
        break;
      }
    }

    delete[] ip;

    if (m_nSuccessCount + m_nFailedCount >= m_nSelectCount) {
      SetCtrlEnable(TRUE);
      m_btn_check.SetWindowText("批量导入");
      MessageBox("导入完成!", "提示", MB_OK);
    }
  }

  return 0;
}

void CDlgSubLocalUpdate::OnClose()
{
  for (int n = 0; n < MAX_THREAD_COUNT; n++) {
    if (m_MutiUpdateThreads[n].joinable()) {
      m_MutiUpdateThreads[n].join();
    }
  }

  import_param_ = false;
  for (int i = 0; i < MAX_IMPORT_COUNT; i++) {
    if (import_thread_[i].joinable()) {
      import_thread_[i].join();
    }
  }

  CDialog::OnClose();
}

void CDlgSubLocalUpdate::OnBnClickedBtnUpdateIp() {
  CUpdateIPDlg dlg;

  for (int i = 0; i < m_oMultiIPList.GetItemCount(); ++i)
  {
    if (!m_oMultiIPList.GetCheck(i))
      continue;

    CString strIP = m_oMultiIPList.GetItemText(i, 1);
    if (strIP == "")
    {
      continue;
    }

    LocalDeviceInfo device_info;

    std::string device_ip(strIP.GetBuffer(0));
    if (GetUpdateDevice(device_ip, device_info)) {
      dlg.update_devices.push_back(device_info);
    }
  }

  if (dlg.update_devices.size() > 0)
  {
    if (IDOK == dlg.DoModal())
    {
      OnBnClickedBtnSearchDevice();
    }
  }
  else
  {
    MessageBox("请选择列表中的设备", "提示", MB_OK);
  }
}

bool CDlgSubLocalUpdate::GetUpdateDevice(std::string ip, LocalDeviceInfo &device_info) {
  bool ret = false;
  std::lock_guard<std::mutex> guard(_search_devce_mutex);
  for (auto item : _search_device)
  {
    if (item.ip == ip) {
      device_info = item;
      ret = true;
      break;
    }
  }

  return ret;
}


void CDlgSubLocalUpdate::OnOK()
{
}


void CDlgSubLocalUpdate::OnBnClickedBtnBrow()
{
  update_file_edit_.SetWindowText("");
  CString file_path;

  CFileDialog FileDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, "bin文件|*.bin||");
  if (FileDlg.DoModal() == IDOK)
  {
    file_path = FileDlg.GetPathName();
  }

  update_file_edit_.SetWindowText(file_path);
}


void CDlgSubLocalUpdate::OnBnClickedBtnParam()
{
  update_file_edit_.SetWindowText("");
  CString file_path;

  CFileDialog FileDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, "cfg文件|*.cfg||");
  if (FileDlg.DoModal() == IDOK)
  {
    file_path = FileDlg.GetPathName();
  }

  param_file_edit_.SetWindowText(file_path);
}


void CDlgSubLocalUpdate::OnBnClickedBtnMultiUpdateDevice()
{
  m_nSelectCount = 0;
  m_nSuccessCount = 0;
  m_nFailedCount = 0;

  int select_count = 0;

  m_vecUpdateDevice.clear();

  LocalDeviceInfo device_info;

  update_file_edit_.GetWindowText(update_file_path_);
  if (update_file_path_ == "") {
    MessageBox("请选择待升级镜像文件", "提示", MB_OK);
    return;
  }

  for (int i = 0; i < m_oMultiIPList.GetItemCount(); ++i)
  {
    if (!m_oMultiIPList.GetCheck(i))
      continue;

    CString strIP = m_oMultiIPList.GetItemText(i, 1);
    if (strIP == "") {
      return;
    }

    CString strPort = m_oMultiIPList.GetItemText(i, 2);
    int port = atoi(strPort.GetBuffer(0));

    device_info.ip = strIP.GetBuffer(0);
    device_info.port = port;
    device_info.username = "admin";
    device_info.pwd = "admin";
    m_vecUpdateDevice.push_back(device_info);

    select_count++;
  }

  if (select_count > 0)
  {
    m_nSelectCount = select_count;
    SetCtrlEnable(FALSE);

    char szMultiStatus[64] = { 0 };
    sprintf_s(szMultiStatus, sizeof(szMultiStatus), "共选择%d台", select_count);
    m_strMultiStatus = szMultiStatus;
    UpdateData(FALSE);

    int thread_count = (select_count > MAX_THREAD_COUNT) ? MAX_THREAD_COUNT : select_count;
    for (int n = 0; n < thread_count; n++)
    {
      if (m_MutiUpdateThreads[n].joinable()) {
        m_MutiUpdateThreads[n].join();
      }

      m_MutiUpdateThreads[n] = std::thread([&]() {
        MutiUpdateDevices();
       });
    }
  }
  else {
    MessageBox("请选择待升级的设备", "提示", MB_OK);
  }
}

void CDlgSubLocalUpdate::OnCbnSelchangeCmbVersion()
{
  m_oMultiIPList.DeleteAllItems();

  {
    std::lock_guard<std::mutex> lock(m_mtxGetVerion);
    for (auto item : m_vecSearchDevice) {
      if (IsDeviceInfoSuitable(&item)) {
        AddDevice(&item);
      }
    }
  }

  ShowDeviceCount();
}

bool  CDlgSubLocalUpdate::IsDeviceInfoSuitable(LocalDeviceInfo *device_info)
{
  bool ret = false;

  int cur_sel = version_combo_.GetCurSel();
  if (cur_sel != 0) {
    CString cur_version;
    version_combo_.GetLBText(cur_sel, cur_version);

    std::string version(cur_version.GetBuffer(0));
    size_t pos = device_info->version.find(version);
    if (pos != std::string::npos) {
      ret = true;
    }
  }
  else {
    ret = true;
  }

  return ret;
}

bool CDlgSubLocalUpdate::FindDeviceItem(std::string device_ip) {
  bool ret = false;
  for (int it = 0; it < m_oMultiIPList.GetItemCount(); ++it)
  {
    CString strCompareIP = m_oMultiIPList.GetItemText(it, 1);
    string cur_ip(strCompareIP.GetBuffer(0));
    if (device_ip == cur_ip)
    {
      ret = true;
      break;
    }
  }
  return ret;
}

void CDlgSubLocalUpdate::ShowDeviceCount() {
  int count = m_oMultiIPList.GetItemCount();
  CString count_msg;
  count_msg.Format("设备数量: %d", count);
  count_lable_.SetWindowText(count_msg);
}