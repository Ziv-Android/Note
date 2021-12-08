#pragma once
#include "VzLPRClientSDK.h"

#include <string>
#include <vector>
using namespace std;

typedef struct
{
	char ip[32];
	int type;
}UpdateStatus;

class UpdateDevice
{
public:
	UpdateDevice(void);
	~UpdateDevice(void);

	bool UpdateDeviceProc(VzLPRClientHandle handle, string file_path, string device_ip, HWND hWnd);

public:
	static void PostUpdateMessage( HWND hwnd, int msg, int type, LPARAM l, const char* ip );

private:
	bool GetRemoteSoftWareVersion(VzLPRClientHandle handle, int& main_version, int& sub_version);
	string GetAppPath();
	int IsPathExist(const char *filename);
	bool UpdateRemoteSoftware(VzLPRClientHandle handle, string update_file, const char *ip, int main_version);
	bool RebootDevice(VzLPRClientHandle handle);
	bool GetSoftWareVersionByTimes(VzLPRClientHandle handle, int& main_version, int& sub_version, int times);

private:
	HWND m_hWnd;
};
