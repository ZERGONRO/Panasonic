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

//namespace std{

typedef struct _PanasonicServe_t{
	int wifistatus;
	char ssid[128];
	char passwd[128];
}PanasonicServe_t;


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
}EnvironmentDate_t;
enum {
	STANDARD_MODE,
	HOKKAIDO_MODE,
	HAWAII_MODE,
	VACATION_MODE,
};

enum {
	MANAUAL_PURIFY,
	MANAUAL_AIRCONDITION,
	MANAUAL_HOTCHANGE,
	MANAUAL_SETHUMD,
	MANAUAL_EXCHANGEWIND,
	MANAUAL_STERILIZATION,
	MANAUAL_YUBA,
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

	int getenvmode();
	void setenvmode();
	int getenvironmentindex();
	void setenvironmentindex(int index);

	void setwifissid(std::string ssid);
	void setwifipasswd(std::string ssid_passwd);
	int getwifistatus();
	void setwifistatus(int status);
	char *getwifissid();
	char *getwifipasswd();


	std::vector<SpaceInfo *> getEnvSpaceInfo();
protected:

private:
	int mode;
	int smartprograme_type;
	int manualprograme_type;
	PanasonicServe_t* config;
	EnvironmentDate_t* EnvDate;

};

//};

#define MACHINESTATUS	MachineStatusListener::getInstance()

#endif /* JNI_UTIL_MACHINESTATUS_H_ */
