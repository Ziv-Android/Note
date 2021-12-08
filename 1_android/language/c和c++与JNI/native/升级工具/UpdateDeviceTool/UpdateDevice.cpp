#include "stdafx.h"
#include "UpdateDevice.h"
#include <winsock.h>
#include <io.h>
#include <ShlObj.h>
#include <fstream>

bool WriteTxtFile(const char *filepath, LPCSTR strText)
{
	int num = 0;

	FILE *fp = NULL;
	fopen_s(&fp, filepath, "a+");

	if( fp == NULL )
	{
		return false;
	}

	num = fwrite( strText, sizeof(char), strlen(strText), fp );
	fclose( fp );

	return num > 0;
}

// ��ȡ��ǰ����·��
string GetAppPath()
{
	string sAppPath;

	TCHAR tszModule[MAX_PATH + 1] = { 0 };
	::GetModuleFileName(NULL, tszModule, MAX_PATH);

	sAppPath.assign((char*)tszModule);
	int pos = sAppPath.find_last_of('\\');
	sAppPath = sAppPath.substr(0, pos);

	return sAppPath;
}

//************************************************************************************
// UpdateDevice��
UpdateDevice::UpdateDevice(void)
{
}

UpdateDevice::~UpdateDevice(void)
{
}

bool UpdateDevice::UpdateDeviceProc(VzLPRClientHandle handle, string device_ip, string file_path, HWND hWnd)
{	
	m_hWnd = hWnd;

	bool ret = false;

	if (handle != NULL)
	{
		bool enable = false;
		int time = 0;
		int status = 0;

		do
		{
			// ��ȡ�豸�汾��
			int main_version = 0, sub_version = 0;
			bool is_get = GetSoftWareVersionByTimes(handle, main_version, sub_version, 10);

			if (!is_get)
			{
				status = 2;
				break;
			}

			bool is_update = false;

			is_update = UpdateRemoteSoftware(handle, file_path.c_str(), device_ip.c_str(), main_version);
			if (!is_update)
			{
				status = 4;
				break;
			}

			// �ٴλ�ȡ�豸�汾��
			int new_main_version = 0, new_sub_version = 0;
			bool is_get_new = GetSoftWareVersionByTimes(handle, new_main_version, new_sub_version, 20);

			if (!is_get_new)
			{
				status = 5;
				break;
			}

            // ����ǰ��汾һ��
            if (main_version == new_main_version && sub_version == new_sub_version) {
              status = 6;
              break;
            }

			if (is_update) {
				ret = true;
			}

		} while (0);

		if (ret)
		{
			PostUpdateMessage(m_hWnd, WM_UPDATE_MSG, TRUE, (LPARAM)NULL, device_ip.c_str());
		}
		else
		{
		  PostUpdateMessage(m_hWnd, WM_UPDATE_MSG, (WPARAM)FALSE, (LPARAM)status, device_ip.c_str());
          Sleep(500);
          VzLPRClient_RebootDVR(handle);
          Sleep(500);
		}

        VzLPRClient_Close(handle);
        handle = NULL;
	}
	else
	{
		PostUpdateMessage(m_hWnd, WM_UPDATE_MSG, (WPARAM)FALSE, (LPARAM)1, device_ip.c_str());
	}

	return true;
}

// ��ȡ�汾��
bool UpdateDevice::GetRemoteSoftWareVersion(VzLPRClientHandle handle, int& main_version, int& sub_version)
{
	bool ret = false;

	int ver1 = 0, ver2 = 0, ver3 = 0, ver4 = 0;
	int result = VzLPRClient_GetRemoteSoftWareVersion(handle, &ver1, &ver2, &ver3, &ver4);
	if (result == 0)
	{
		main_version = ver1 * 100 + ver2 * 10 + ver3;
		sub_version = ver4;

		ret = true;
	}

	return ret;
}

bool UpdateDevice::GetSoftWareVersionByTimes(VzLPRClientHandle handle, int& main_version, int& sub_version, int times)
{
	bool ret = false;

	for( int i = 0; i < times; i++)
	{
		bool is_get = GetRemoteSoftWareVersion(handle, main_version, sub_version);
		if(is_get)
		{
			break;
		}

		Sleep(5000);
	}

	if (main_version > 0 && sub_version > 0)
	{
		ret = true;
	}

	return ret;
}

// ִ����������
bool UpdateDevice::UpdateRemoteSoftware(VzLPRClientHandle handle, string update_file, const char *ip, int main_version)
{
	bool ret = false;
	bool is_reboot = false;

	int index = update_file.find_last_of("\\");
	string file_name = update_file.substr(index + 1);

	const int path_len = 128;
	char *name = new char[path_len];
	memset(name, 0, path_len);
	strcpy_s(name, path_len, file_name.c_str());

	// �������ȣ���ʼ�����豸
	PostUpdateMessage(m_hWnd, WM_PROCESS_MSG, 5, (LPARAM)name, ip);

	int update_ret = VzLPRClient_Update(handle, const_cast<char*>(update_file.c_str()));

	//����һ���SDK��ȡ�������������⣬��ʱû���ҵ�ԭ���߳�����Ϣ
	if (update_ret != VZ_API_FAILED)
		Sleep(15000);

	if (update_ret != VZ_API_FAILED)
	{
		int count = 0;
		while (true)
		{
			int status = VzLPRClient_GetUpdateState(handle);
			if (status == 1)
			{
				is_reboot = true;
				break;
			}
			else if (status == 2 || status == 3)
			{

			}
			else if (status == -1 || status == 4)
			{
				int last_error = VzLPRClient_GetLastError();
				if (status == 4) {
					is_reboot = true;
				}

				break;
			}

			// ��ȴ�10���ӣ�û�л�ȡ����״̬�����˳�
			if (count > 200)
			{
				break;
			}

			count++;
			Sleep(3000);
		}
	}

	if (is_reboot)
	{
		// �������ȣ������豸�ɹ��������豸
		PostUpdateMessage(m_hWnd, WM_PROCESS_MSG, 6, (LPARAM)NULL, ip);

		ret = RebootDevice(handle);
	}

	return ret;
}

bool UpdateDevice::RebootDevice(VzLPRClientHandle handle)
{
	VzLPRClient_RebootDVR(handle);
	Sleep(20000);

	int nRebootTimes = 0;
	BYTE byteState = 0;
	const int Reboot_MaxTimes = 60 * 5;
	bool bRet = false;

	while (true)
	{
		int nConnectRet = VzLPRClient_IsConnected(handle, &byteState);
		if (byteState == 1)
		{
			Sleep(30000);
			bRet = true;
			break;
		}

		if (nRebootTimes > Reboot_MaxTimes)
		{
			break;
		}

		Sleep(1000);
		++nRebootTimes;
	}
	return bRet;
}

void UpdateDevice::PostUpdateMessage( HWND hwnd, int msg, int type, LPARAM l, const char* ip )
{
	UpdateStatus *status = new UpdateStatus;
	memset(status, 0, sizeof(UpdateStatus));
	strcpy_s(status->ip, sizeof(status->ip), ip);
	status->type = type;

	::PostMessage(hwnd, msg, (WPARAM)status, l);
}

string UpdateDevice::GetAppPath()
{
	string sAppPath;

	TCHAR tszModule[MAX_PATH + 1] = { 0 };
	::GetModuleFileName(NULL, tszModule, MAX_PATH);

	sAppPath.assign((char*)tszModule);
	int pos = sAppPath.find_last_of('\\');
	sAppPath = sAppPath.substr(0, pos);

	return sAppPath;
}

int UpdateDevice::IsPathExist(const char *filename)
{
	return (_access(filename, NULL) == 0);
}
