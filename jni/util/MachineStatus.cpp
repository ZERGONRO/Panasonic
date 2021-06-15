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

//namespace std{

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
/*
 * 获取WIFI状态
 * */
int MachineStatusListener::getwifistatus()
{
	return config->wifistatus;
}

/*
 * 获取本机状态
 * */
int MachineStatusListener::getmachinemode()
{
	return mode;
}

/*
 * 获取智能模式下的状态
 * */
int MachineStatusListener::getsmartmode()
{
	return smartprograme_type;
}

/*
 * 获取手动模式下的状态
 * */
int MachineStatusListener::getmanualmode()
{
	return manualprograme_type;
}

/*
 * 设置智能模式状态
 * type为状态值
 * */
void MachineStatusListener::setsmartmode(int type)
{
	smartprograme_type = type;
}

/*
 * 设置手动模式状态
 * type为状态值
 * */
void MachineStatusListener::setmanualmode(int type)
{
	manualprograme_type = type;
}

/*
 * 获取亮度值
 * */

int MachineStatusListener::getbacklight()
{
	return EnvDate->bl;
}

/*
 * 设置亮度值
 * bl为亮度具体值
 * */
void MachineStatusListener::setbacklight(int bl)
{
	EnvDate->bl = bl;
}

/*
 * 获取音量值
 * */
int MachineStatusListener::getvol()
{
	return EnvDate->vol;
}

/*
 * 设置音量值
 * vol为音量值
 * */
void MachineStatusListener::setvol(int vol)
{
	EnvDate->vol = vol;
}

/*
 * 获取温度值
 * */
int MachineStatusListener::gettempdate()
{
	return EnvDate->Temp;
}

/*
 * 获取湿度值
 * */
int MachineStatusListener::gethumddate()
{
	return EnvDate->Hhumd;
}

/*
 * 获取PM2.5值
 * */
float MachineStatusListener::getpm25date()
{
	return EnvDate->Pm25;
}

/*
 * 获取甲醛值
 * */
float MachineStatusListener::getformvdate()
{
	return EnvDate->Fdehyde;
}

/*
 * 获取CO2值
 * */
float MachineStatusListener::getCo2date()
{
	return EnvDate->CO2;
}

/*
 * 获取tvoc值
 * */
float MachineStatusListener::gettvocdate()
{
	return EnvDate->Tvoc;
}

/*
 * 设置温度值
 * data为所设置的值
 * */
void MachineStatusListener::settempdate(int data)
{
	EnvDate->Temp = data;
}

/*
 * 设置湿度值
 * data为所设置的值
 * */
void MachineStatusListener::sethumddate(int data)
{
	EnvDate->Hhumd = data;
}

/*
 * 设置CO2值
 * data为所设置的值
 * */
void MachineStatusListener::setCo2date(float data)
{
	EnvDate->CO2 = data;
}

/*
 * 设置PM2.5值
 * data为所设置的值
 * */
void MachineStatusListener::setpm25date(float data)
{
	EnvDate->Pm25 = data;
}

/*
 * 设置甲醛值
 * data为所设置的值
 * */
void MachineStatusListener::setformvdate(float data)
{
	EnvDate->Fdehyde = data;
}

/*
 * 设置tvoc值
 * data为所设置的值
 * */
void MachineStatusListener::settvocdate(float data)
{
	EnvDate->Tvoc = data;
}

/*
 * 设置wifi的ssid
 * ssid为所设置的值
 * */
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

/*
 * 设置wifi的passwd
 * ssid_passwd为所设置的值
 * */
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

/*
 * 设置wifi的status状态
 * status为所设置的值
 * */
void MachineStatusListener::setwifistatus(int status)
{
	config->wifistatus = status;
}

/*
 * 获取wifi的ssid值
 *
 * */
char* MachineStatusListener::getwifissid()
{
	return config->ssid;
}

/*
 * 获取wifi的passwd值
 *
 * */
char* MachineStatusListener::getwifipasswd()
{
	return config->passwd;
}



/*
 * 获取env的index值
 *
 * */
int MachineStatusListener::getenvironmentindex()
{
	return EnvDate->envindex;
}

/*
 * 设置env的index值
 *
 * */
void MachineStatusListener::setenvironmentindex(int index)
{
	EnvDate->envindex = index;
}

std::vector<SpaceInfo *> MachineStatusListener::getEnvSpaceInfo()
{
	std::vector<SpaceInfo *> Vector;
	Vector.clear();
//	std::vector<SpaceInfo *>::iterator it = EnvSettingVector



	return Vector;
}










