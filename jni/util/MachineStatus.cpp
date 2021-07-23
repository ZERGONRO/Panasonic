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
	EquipmentTimeSetting = new EquipmentTiming;
//	EqpTime_Data = new std::vector<EqpTimeData *>[10];
	EqpTime_Data.clear();
//	EqpTime_Data = new EqpTimeData;
	config->wifistatus = 1;
	EnvInfo.clear();
	EnvListInfo.clear();
	EnvDate->MasterorSlaver = false;
	EquipmentTimeSetting->DeviceID = AirPURIFY;
	EquipmentTimeSetting->DeviceSwitch = false;
	EquipmentTimeSetting->Time1StageFlag = false;
	EquipmentTimeSetting->Time2StageFlag = false;

	strcpy(MasterSlaverKey, InitialPassword);
	initVersion();
//	initEqpTimeData();
//	MasterSlaverKey[10] = "123456";
//	EnvDate->bl = 51;
//	EnvDate->vol = 51;
}

MachineStatusListener::~MachineStatusListener()
{
	delete config;
	delete EnvDate;
	delete EquipmentTimeSetting;
	delete MachineVer;

	MachineVer = NULL;
	EnvDate = NULL;
	config = NULL;
	EquipmentTimeSetting = NULL;

}




void MachineStatusListener::initVersion()
{
	FILE *fp = fopen(Version_Path, "r+");
	if (!MachineVer){
		MachineVer = new MachineVersion;
	}
	memset(MachineVer, 0, sizeof(MachineVersion));

	if (!fp){
		strcpy(MachineVer->verbuf, GUI_VerSion);
		MachineVer->ver_notice = 0;
	}else{
		int ret = fread(MachineVer, 1, sizeof(MachineVersion), fp);
		if (ret != sizeof(MachineVersion)){
			strcpy(MachineVer->verbuf, GUI_VerSion);
			MachineVer->ver_notice = 0;
		}else{
			//更新为最新版本
			if (getVersionStatus() == 2){
				saveVersion(GUI_VerSion, 0);
			}
		}
		fclose(fp);
	}

}

void MachineStatusListener::saveVersion(char *newversion, int notice)
{
	FILE *fp = fopen(Version_Path, "w");
	if (!fp){

	}else{
		if (strcmp(newversion, MachineVer->verbuf) || notice != MachineVer->ver_notice){
			strcpy(MachineVer->verbuf, newversion);
			if (notice != -1){
				MachineVer->ver_notice = notice;
			}
			if (fwrite(MachineVer, 1, sizeof(MachineVersion), fp) < 0){
				LOGD("write gui_version to path error\n");
			}
			fflush(fp);
			fsync(fileno(fp));
		}
		fclose(fp);
		system("sync");
	}
}

bool MachineStatusListener::getVersionNotice(char *version_desc)
{
	char verbuf[128];
	if (!version_desc){
		return false;
	}
	strcpy(verbuf, version_desc);
	int FirstVersion = 0, SecondVersion = 0, ThirdVersion = 0;
	char *token;
	char *ver = verbuf;
	ver++;
	token = strtok(ver, ".");
	if (!token){
		return false;
	}
	FirstVersion = atoi(token);

	token = strtok(NULL, ".");
	if (!token){
		return false;
	}
	SecondVersion = atoi(token);

	token = strtok(NULL, ".");
	if (!token){
		return false;
	}
	ThirdVersion = atoi(token);

	if (FirstVersion > GUI_First_VerSion){
		return true;
	}else if (FirstVersion == GUI_First_VerSion){
		if (SecondVersion > GUI_Second_VerSion){
			return true;
		}else if (SecondVersion == GUI_Second_VerSion){
			if (ThirdVersion > GUI_Third_VerSion){
				return true;
			}
		}
	}
	return false;

}

int MachineStatusListener::getVersionStatus()
{
	if (!strcmp(GUI_VerSion, MachineVer->verbuf)){
		return 0;			//与当前版本号相同
	}
	if (strlen(MachineVer->verbuf) == 0){
		return 1;			//服务器为新版本;
	}


	int FirstVersion = 0, SecondVersion = 0, ThirdVersion = 0;
	char verbuf[64];
	strcpy(verbuf, GUI_VerSion);
	char *token;
	char *ver = verbuf;
	ver++;
	token = strtok(ver, ".");
	if (!token){
		saveVersion(GUI_VerSion, 0);
		return 0;
	}
	FirstVersion = atoi(token);

	token = strtok(NULL, ".");
	if (!token){
		saveVersion(GUI_VerSion, 0);
		return 0;
	}
	SecondVersion = atoi(token);

	token = strtok(NULL, ".");
	if (!token){
		saveVersion(GUI_VerSion, 0);
		return 0;
	}
	ThirdVersion = atoi(token);

	if (FirstVersion > GUI_First_VerSion){
		return 1;
	}else if (FirstVersion == GUI_First_VerSion){
		if (SecondVersion > GUI_Second_VerSion){
			return 1;
		}else if (SecondVersion == GUI_Second_VerSion){
			if (ThirdVersion > GUI_Third_VerSion){
				return 1;
			}
		}
	}

	if (FirstVersion < GUI_First_VerSion){
		return 2;							//为旧版本，需要更新
	}else if (FirstVersion == GUI_First_VerSion){
		if (SecondVersion < GUI_Second_VerSion){
			return 2;
		}else if (SecondVersion == GUI_Second_VerSion){
			if (ThirdVersion < GUI_Third_VerSion){
				return 2;
			}
		}
	}
	return 0;

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

std::vector<DeviceInfo *> MachineStatusListener::getEnvSpaceInfo()
{
	return EnvInfo;
}

void MachineStatusListener::setEnvSpaceInfo(std::vector<DeviceInfo *> *EnvDevSettingVector)
{
	if(!EnvDevSettingVector)
		return;

	EnvInfo.clear();
//	DeviceInfo *info = (DeviceInfo *)malloc(sizeof(DeviceInfo));
	for(std::vector<DeviceInfo *>::iterator it = EnvDevSettingVector->begin(); it != EnvDevSettingVector->end();it++)
	{
		DeviceInfo *tmp = (*it);
		EnvInfo.push_back(tmp);
	}
}

void MachineStatusListener::setEnvListInfo(std::vector<SpaceInfo *> *EnvSettingVectorList)
{
	if (!EnvSettingVectorList){
		return;
	}
	EnvListInfo.clear();
	std::vector<SpaceInfo *>::iterator it = EnvListInfo.begin();
	for (;it != EnvListInfo.end();it++){
		SpaceInfo *tmp = (*it);
		EnvListInfo.push_back(tmp);
	}
}

std::vector<SpaceInfo *> MachineStatusListener::getEnvListInfo()
{
	return EnvListInfo;
}

void MachineStatusListener::setMachineTime(struct tm *time)
{
	Machinetime.year = time->tm_year;
	Machinetime.month = time->tm_mon;
	Machinetime.days = time->tm_mday;
	Machinetime.hour = time->tm_hour;
	Machinetime.min = time->tm_min;
}
MachineTime MachineStatusListener::getMachineTime()
{
	return Machinetime;
}

void MachineStatusListener::setMasterSlaverKey(char *keyword)
{

	strcpy(MasterSlaverKey, keyword);
	LOGD("The MasterSlaverKey is %s\n", &MasterSlaverKey);

}

char* MachineStatusListener::getMasterSlaverKey()
{
	char *buf = MasterSlaverKey;
	return buf;
}



void MachineStatusListener::setMasterorSlaver(bool MasterorSlaverFlag)
{
	EnvDate->MasterorSlaver = MasterorSlaverFlag;
}

bool MachineStatusListener::getMasterorSlaver()
{
	return EnvDate->MasterorSlaver;
}

void MachineStatusListener::setEquipmentTimeSetting(EquipmentTiming *EquTimeSetting)
{
	if (!EquTimeSetting){
		return;
	}

	EquipmentTimeSetting->DeviceID = EquTimeSetting->DeviceID;
	EquipmentTimeSetting->DeviceSwitch = EquTimeSetting->DeviceSwitch;
	EquipmentTimeSetting->weekbuf.clear();
	for (int i = 0;i < EquTimeSetting->weekbuf.size();i++){
		std::string tmpweek = EquTimeSetting->weekbuf.at(i);
		EquipmentTimeSetting->weekbuf.push_back(tmpweek.c_str());
	}

	if (EquTimeSetting->Time1StageFlag){
		EquipmentTimeSetting->Time1StageFlag = true;
		EquipmentTimeSetting->TimeOpenValue1 = EquTimeSetting->TimeOpenValue1;
		EquipmentTimeSetting->TimeCloseValue1 = EquTimeSetting->TimeCloseValue1;
		EquipmentTimeSetting->TempSettingValue1 = EquTimeSetting->TempSettingValue1;
	}else{
		EquipmentTimeSetting->Time1StageFlag = false;
	}

	if (EquTimeSetting->Time2StageFlag){
		EquipmentTimeSetting->Time2StageFlag = true;
		EquipmentTimeSetting->TimeOpenValue2 = EquTimeSetting->TimeOpenValue2;
		EquipmentTimeSetting->TimeCloseValue2 = EquTimeSetting->TimeCloseValue2;
		EquipmentTimeSetting->TempSettingValue2 = EquTimeSetting->TempSettingValue2;
	}else{
		EquipmentTimeSetting->Time2StageFlag = false;
	}

}

EquipmentTiming* MachineStatusListener::getEquipmentTimeSetting()
{
	return EquipmentTimeSetting;
}

void MachineStatusListener::setEqpTimeData()
{
	int Eqp_Count = 0;
	if (!EquipmentTimeSetting){
		return;
	}
	if (!EqpTime_Data.empty()){
		std::vector<EqpTimeData *>::iterator it = EqpTime_Data.begin();
//		for (int i = 0;i < EqpTime_Data.size();i++){
		for (;it != EqpTime_Data.end();it++){
			EqpTimeData *tmp = (*it);
			EqpTimeData *tmp1 = EqpTime_Data.at(Eqp_Count);
			if (EquipmentTimeSetting->DeviceID == tmp1->DeviceID){
				if (memcmp(tmp1->DeviceData, EquipmentTimeSetting, sizeof(EquipmentTiming)) == 0){
					LOGD("the same EqpTime_Data\n");
					return;
				}else{
					EqpTime_Data.erase(it);
					free(tmp->DeviceData);
					tmp->DeviceData = NULL;
					free(tmp);
					tmp = NULL;

					LOGD("the same DeviceID but not EqpTime_Data\n");
					break;
				}
			}
			Eqp_Count++;
		}
	}
	EqpTimeData *tmpEqpTimer = (EqpTimeData *)malloc(sizeof(EqpTimeData));
	tmpEqpTimer->DeviceData = (EquipmentTiming *)malloc(sizeof(EquipmentTiming));
	tmpEqpTimer->DeviceID = EquipmentTimeSetting->DeviceID;
	memcpy(tmpEqpTimer->DeviceData, EquipmentTimeSetting, sizeof(EquipmentTiming));
	EqpTime_Data.push_back(tmpEqpTimer);
}
std::vector<EqpTimeData *> MachineStatusListener::getEqpTimeData()
{
	return EqpTime_Data;
}

bool MachineStatusListener::getDeviceSwitch(bool SwitchStatus)
{
	return EquipmentTimeSetting->DeviceSwitch = SwitchStatus;
}

void MachineStatusListener::setDeviceID(int DevID)
{
//	EqpTime_Data.DeviceID = DevID;
}



