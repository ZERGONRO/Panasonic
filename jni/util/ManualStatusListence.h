/*
 * ManualStatusListence.h
 *
 *  Created on: 2021年8月2日
 *      Author: 80022678
 */

#ifndef JNI_UTIL_MANUALSTATUSLISTENCE_H_
#define JNI_UTIL_MANUALSTATUSLISTENCE_H_

#include "util/ProtocolDataSend.h"
#include "util/MachineStatus.h"

class ManualStatusListence {
public:
	ManualStatusListence();
	virtual ~ManualStatusListence();
	static ManualStatusListence *getInstance();
	void initManualStatusData();

	/* Common Data Func */
	void setTempthreadholdData(int value);
	void setHumdthreadholdData(int value);
	void setCo2threadholdData(int value);
	void setPm25threadholdData(int value);
	void setTvocthreadholdData(float value);
	void setformaldehydethreadholdData(float value);
	int getTempthreadholdData();
	int getHumdthreadholdData();
	int getCo2threadholdData();
	int getPm25threadholdData();
	float getTvocthreadholdData();
	float getformaldehydethreadholdData();
	void setWifiSwitch(int value);
	void setWifiStatus(int value);
	void setVoiceSysSwitch(int value);
	void setMainMachineMode(int value);
	void setRf254Switch(int value);

	/* Manual Device Data Func */
	void setAirPFAutoWind(int value);
	void setAirPFWindDirec(int value);
	void setAirPFHumdValue(int value);
	void setAirPFNanoeX(int value);
	void setAirPFBright(int value);
	void setAirPFFilter(int value);
	void setAirPFChildLock(int value);
	void setAirPFSwitch(int value);
	int getAirPFSwitch();
	void setAirPFModel(const char *value);
	void setAirPFTimeSwitch(int value);
	int getAirPFTimeSwitch();
	void setAirPFTimeInfo(EquipmentTiming *info);

	void setAirAutoWind(int value);
	void setAirWindDirect(int value);
	void setAirMode(int value);
	void setAirTemp(int value);
	void setAirSwitch(int value);
	int getAirSwitch();
	void setAirModel(const char *value);
	void setAirTimeSwitch(int value);
	int getAirTimeSwitch();
	void setAirTimeInfo(EquipmentTiming *info);

	void setHeatChangeAutoWind(int value);
	void setHeatChangeNanoeX(int value);
	void setHeatChangeMode(int value);
	void setHeatChangeModel(const char *value);
	void setHeatChangeSwitch(int value);
	int getHeatChangeSwitch();
	void setHeatChangeTimeSwitch(int value);
	int getHeatChangeTimeSwitch();
	void setHeatChangeTimeInfo(EquipmentTiming *info);

	void setHumdAutoWind(int value);
	void setHumdWindDirect(int value);
	void setHumdsettingHumd(int value);
	void setHumdMode(int value);
	void setHumdModel(const char *value);
	void setHumdSwitch(int value);
	int getHumdSwitch();
	void setHumdTimeSwitch(int value);
	int getHumdTimeSwitch();
	void setHumdTimeInfo(EquipmentTiming *info);

	void setWindAutoWind(int value);
	void setWindNaneoX(int value);
	void setWindModel(const char *value);
	void setWindSwitch(int value);
	int getWindSwitch();
	void setWindTimeSwitch(int value);
	int getWindTimeSwitch();
	void setWindTimeInfo(EquipmentTiming *info);

	void setYuBaHeatDry(int value);
	void setYuBaColdDry(int value);
	void setYuBaChangeAir(int value);
	void setYuBaHeating(int value);
	void setYuBaWindDirct(int value);
	void setYuBaWindType(int value);
	void setYuBaNaneoX(int value);
	void setYuBaBright(int value);
	void setYuBaSwitch(int value);
	int getYuBaSwitch();
	void setYuBaModel(const char *value);
	void setYuBaTimeSwitch(int value);
	int getYuBaTimeSwitch();
	void setYuBaTimeInfo(EquipmentTiming *info);

	//
	SProtocolSendData* getCurrentManualData();
protected:

private:
	SProtocolSendData *sPSData;
	std::vector<EqpTimeData *> sEqpData;
};
#define MANUALSTATUS 	ManualStatusListence::getInstance()

#endif /* JNI_UTIL_MANUALSTATUSLISTENCE_H_ */
