/*
 * MachineStatus.h
 *
 *  Created on: 2021年5月31日
 *      Author: 80022678
 */

#ifndef JNI_UTIL_MACHINESTATUS_H_
#define JNI_UTIL_MACHINESTATUS_H_

#include <vector>
#include <string>
#include "system/Thread.h"
#include "activity/EnvSettingActivity.h"



#define		InitialPassword		"123456"
#define 	GUI_VerSion			"V1.00.00"
#define 	GUI_First_VerSion	1
#define 	GUI_Second_VerSion	0
#define 	GUI_Third_VerSion	0
#define 	Version_Path		"/appconfigs/version.cfg"


//namespace std{

typedef struct _PanasonicServe_t{
	int wifistatus;
	char ssid[128];
	char passwd[128];
}PanasonicServe_t;

typedef struct MachineVersion_t{
	char verbuf[128];
	int ver_notice;
}MachineVersion;

typedef enum {
	AirPURIFY,
	AIRCONDITION,
	HOTEXCHANGE,
	DEHUMIDIFY,
	WINDEXCHANGE,
	STERILIZATION,
	YUBA
}IOTDeviceID;

typedef struct EquipmentTiming_t {
	int DeviceID;
//	char WeekBuf[128];
	bool DeviceSwitch;
	std::vector<std::string > weekbuf;
	bool Time1StageFlag;
	int TimeOpenValue1;
	int TimeCloseValue1;
	int TempSettingValue1;
	bool Time2StageFlag;
	int TimeOpenValue2;
	int TimeCloseValue2;
	int TempSettingValue2;
	int HumdSettingValue1;
	int HumdSettingValue2;
}EquipmentTiming;

typedef struct EqpTimeData_t {
	int DeviceID;
	EquipmentTiming *DeviceData;
}EqpTimeData;

typedef struct MachineTime_t {
	int year;
	int month;
	int days;
	int hour;
	int min;
}MachineTime;

typedef struct _EnvironmentDate_t{
	int Temp;
	int Hhumd;
	float Pm25;
	float Tvoc;
	float Fdehyde;
	float CO2;
	int bl;
	int vol;
	int envindex;
	bool MasterorSlaver;
//	std::vector<DeviceInfo *> envmode;
}EnvironmentDate_t;
enum {
	STANDARD_MODE,
	HOKKAIDO_MODE,
	HAWAII_MODE,
	VACATION_MODE,
};



class MachineStatusListener{

public:
	MachineStatusListener();
	virtual ~MachineStatusListener();

	static MachineStatusListener* getInstance();

	int getbacklight();
	void setbacklight(int bl);
	int getvol();
	void setvol(int vol);
	int getmachinemode();
	int getsmartmode();
	void setsmartmode(int type);
	int getmanualmode();
	void setmanualmode(int type);
	void setMachineTime(struct tm *time);
	MachineTime getMachineTime();
	void setMasterSlaverKey(char *keyword);
	char *getMasterSlaverKey();
	void setMasterorSlaver(bool MasterorSlaverFlag);
	bool getMasterorSlaver();
	void initVersion();
	void saveVersion(char *newversion, int notice);
	bool getVersionNotice(char *version_desc);
	int getVersionStatus();
	void setEquipmentTimeSetting(EquipmentTiming *EquTimeSetting);
	EquipmentTiming* getEquipmentTimeSetting();
	void setEqpTimeData();
	std::vector<EqpTimeData *> getEqpTimeData();
	void initEqpTimeData();
	bool getDeviceSwitch(bool SwitchStatus);
	void setDeviceID(int DevID);
	//获取和设置环境数据
	int gettempdate();
	void settempdate(int data);
	int gethumddate();
	void sethumddate(int data);
	float getCo2date();
	void setCo2date(float data);
	float getpm25date();
	void setpm25date(float data);
	float getformvdate();
	void setformvdate(float data);
	float gettvocdate();
	void settvocdate(float data);
	//
	int getenvmode();
	void setenvmode();
	int getenvironmentindex();
	void setenvironmentindex(int index);

	//获取和设置wifi相关
	void setwifissid(std::string ssid);
	void setwifipasswd(std::string ssid_passwd);
	int getwifistatus();
	void setwifistatus(int status);
	char *getwifissid();
	char *getwifipasswd();


	std::vector<DeviceInfo *> getEnvSpaceInfo();
	void setEnvSpaceInfo(std::vector<DeviceInfo *> *EnvDevSettingVector);
	void setEnvListInfo(std::vector<SpaceInfo *> *EnvSettingVectorList);
	std::vector<SpaceInfo *> getEnvListInfo();
protected:

private:
	int mode;
	int smartprograme_type;
	int manualprograme_type;
	MachineTime Machinetime;
	char MasterSlaverKey[10];
	MachineVersion *MachineVer;
	EquipmentTiming* EquipmentTimeSetting;
//	EqpTimeData* EqpTime_Data;
	PanasonicServe_t* config;
	EnvironmentDate_t* EnvDate;
	std::vector<DeviceInfo *> EnvInfo;
	std::vector<SpaceInfo *>  EnvListInfo;
	std::vector<EqpTimeData *> EqpTime_Data;

};

//};

#define MACHINESTATUS	MachineStatusListener::getInstance()

#endif /* JNI_UTIL_MACHINESTATUS_H_ */
