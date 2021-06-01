/*
 * MachineStatus.cpp
 *
 *  Created on: 2021年5月31日
 *      Author: 80022678
 */

#include "util/MachineStatus.h"
#include "stdio.h"
#include "utils/log.h"
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include "util/MyNetWorkingListener.h"

//extern MyNetWorkingListener *nwlistener;

namespace std{

MachineStatusListener::MachineStatusListener()
{
	mode = 0;
	smartprograme_type = 0;
	manualprograme_type = 0;
	config = new PanasonicServe_t;
	EnvDate = new EnvironmentDate_t;
	config->wifistatus = 1;
//	EnvDate->bl = 51;
//	EnvDate->vol = 51;
}

MachineStatusListener::~MachineStatusListener()
{
	delete config;
	delete EnvDate;
	EnvDate = NULL;
	config = NULL;
}

MachineStatusListener* MachineStatusListener::getInstance()
{
	static MachineStatusListener sMS;
	return &sMS;
}

int MachineStatusListener::getwifistatus()
{
	return config->wifistatus;
}

int MachineStatusListener::getmachinemode()
{
	return mode;
}

int MachineStatusListener::getsmartmode()
{
	return smartprograme_type;
}

int MachineStatusListener::getmanualmode()
{
	return manualprograme_type;
}

void MachineStatusListener::setsmartmode(int type)
{
	smartprograme_type = type;
}

void MachineStatusListener::setmanualmode(int type)
{
	manualprograme_type = type;
}

int MachineStatusListener::getbacklight()
{
	return EnvDate->bl;
}

void MachineStatusListener::setbacklight(int bl)
{
	EnvDate->bl = bl;
}

int MachineStatusListener::getvol()
{
	return EnvDate->vol;
}

void MachineStatusListener::setvol(int vol)
{
	EnvDate->vol = vol;
}

int MachineStatusListener::gettempdate()
{
	return EnvDate->Temp;
}

int MachineStatusListener::gethumddate()
{
	return EnvDate->Hhumd;
}

float MachineStatusListener::getpm25date()
{
	return EnvDate->Pm25;
}

float MachineStatusListener::getformvdate()
{
	return EnvDate->Fdehyde;
}

float MachineStatusListener::getCo2date()
{
	return EnvDate->CO2;
}

float MachineStatusListener::gettvocdate()
{
	return EnvDate->Tvoc;
}

void MachineStatusListener::settempdate(int data)
{
	EnvDate->Temp = data;
}

void MachineStatusListener::sethumddate(int data)
{
	EnvDate->Hhumd = data;
}

void MachineStatusListener::setCo2date(float data)
{
	EnvDate->CO2 = data;
}

void MachineStatusListener::setpm25date(float data)
{
	EnvDate->Pm25 = data;
}

void MachineStatusListener::setformvdate(float data)
{
	EnvDate->Fdehyde = data;
}

void MachineStatusListener::settvocdate(float data)
{
	EnvDate->Tvoc = data;
}


void MachineStatusListener::setwifissid(std::string ssid)
{
//	config->ssid = ssid;
	if(!ssid.size())
	{
		memset(config->ssid, 0, 128);
	}
	else
	{
		strcpy(config->ssid, ssid.c_str());
	}

}

void MachineStatusListener::setwifipasswd(std::string ssid_passwd)
{
//	config->passwd = ssid_passwd;
	if(!ssid_passwd.size())
	{
		memset(config->passwd, 0, 128);
	}
	else
	{
		strcpy(config->passwd, ssid_passwd.c_str());
	}
}

void MachineStatusListener::setwifistatus(int status)
{
	config->wifistatus = status;
}

char* MachineStatusListener::getwifissid()
{
	return config->ssid;
}

char* MachineStatusListener::getwifipasswd()
{
	return config->passwd;
}


};














