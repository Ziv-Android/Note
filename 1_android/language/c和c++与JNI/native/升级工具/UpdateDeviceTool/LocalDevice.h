#pragma once
#include <string>

class LocalDeviceInfo
{
public:
	LocalDeviceInfo(){ 
		get_version = false;
		is_update   = false;
        SL = 0;
        SH = 0;
	};

	LocalDeviceInfo(const LocalDeviceInfo& device)
	{
		this->ip = device.ip;
		this->port = device.port;
		this->version = device.version;
		this->get_version = device.get_version;
		this->username = device.username;
		this->pwd = device.pwd;
		this->is_update = device.is_update;
		this->sn = device.sn;
        this->SL = device.SL;
        this->SH = device.SH;
	};

public:
	std::string ip;
	int port;
	std::string username;
	std::string pwd;
	std::string version;
	std::string sn;
	bool get_version;
    unsigned int SL;
    unsigned int SH;
	bool is_update;
};