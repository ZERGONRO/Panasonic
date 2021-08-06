/*
 * ManualStatusListence->cpp
 *
 *  Created on: 2021年8月2日
 *      Author: 80022678
 */

#include "ManualStatusListence.h"
#include <string.h>

ManualStatusListence::ManualStatusListence() {
	// TODO 自动生成的构造函数存根


//	initManualStatusData();
}

ManualStatusListence::~ManualStatusListence() {
	// TODO 自动生成的析构函数存根

//	delete sPSData;
//	sPSData = NULL;

}

ManualStatusListence *ManualStatusListence::getInstance(){
	static ManualStatusListence sPS;
	return &sPS;
}

void ManualStatusListence::initManualStatusData(){
	LOGD("init ManualStatus\n");
	sPSData = new SProtocolSendData;
	memset(sPSData, 0, sizeof(SProtocolSendData));

	/*  Common Data init */
	sPSData->CommonDate.TempThresHoldSetting = 20;
	sPSData->CommonDate.HumdThresHoldSetting = 40;
	sPSData->CommonDate.Pm25ThresHoldSetting = 20;
	sPSData->CommonDate.Co2ThresHoldSetting  = 200;
	sPSData->CommonDate.FormaldehydeThresHoldSetting = 0.05;
	sPSData->CommonDate.TvocThresHoldSetting = 0.05;
	sPSData->CommonDate.WifiSwitch = 0;
	sPSData->CommonDate.WIFIStatus = 0;
	sPSData->CommonDate.WifiVersionUpdate = 0;
	sPSData->CommonDate.ERVPreventCondensation = 0;
	sPSData->CommonDate.ERVPreventFreezing = 0;
	sPSData->CommonDate.EmergencyCallSwitch = 0;
	sPSData->CommonDate.AdjustHumdDry = 0;
	sPSData->CommonDate.AdjustHumdPreCondensation = 0;
	sPSData->CommonDate.PreventMode = 0;
	sPSData->CommonDate.AirCondiOutdoorDefrost = 0;
	sPSData->CommonDate.NanoeXSwitch = 0;
	sPSData->CommonDate.ImmediateCommunicationSwitch = 0;
	sPSData->CommonDate.EmergencyCallSwitch = 0;
	sPSData->CommonDate.WorkOrder = 0;
	sPSData->CommonDate.VoiceSystemSwitch = 0;
	sPSData->CommonDate.MainMachineMode = 0;
	sPSData->CommonDate.GUIVersionUpdate = 0;
	sPSData->CommonDate.ResetFactorySetting = 0;
	sPSData->CommonDate.RF254Switch = 0;
	sPSData->CommonDate.Dealing = 0;
	sPSData->CommonDate.OTAStatus = 0;
	sPSData->CommonDate.ChildrenLockStatus = 0;
	sPSData->CommonDate.HUError = 0;
	sPSData->CommonDate.MusicSwitch = 0;
	sPSData->CommonDate.MusicVolSwitch = 0;
	sPSData->CommonDate.MusicModeSelc = 0;
	sPSData->CommonDate.AirOnekeyAdjustSettingSwitch = 0;
	sPSData->CommonDate.APPOrder = 0;


	/* Manual Device Data init */
	sPSData->PurifyData.Switch = 0;
//	sPSData->PurifyData.ModelSetting = "";
	sPSData->PurifyData.TimingSwitch = 0;
	sPSData->PurifyData.TimeSetting1 = 0;
	sPSData->PurifyData.TimeSetting2 = 0;
	sPSData->PurifyData.TimeValueOpenSetting1 = 0;
	sPSData->PurifyData.TimeValueCloseSetting1 = 0;
	sPSData->PurifyData.TimeValueOpenSetting2 = 0;
	sPSData->PurifyData.TimeValueCloseSetting2 = 0;
	sPSData->PurifyData.TempValue1 = 0;
	sPSData->PurifyData.TempValue2 = 0;
	sPSData->PurifyData.AutoWindVolSetting = 0;
	sPSData->PurifyData.WindDirectSetting = 30;
	sPSData->PurifyData.AddHumdSetting = 40;
	sPSData->PurifyData.NanoexSetting = 0;
	sPSData->PurifyData.BrightSetting = 0;
	sPSData->PurifyData.FilterReset = 0;
	sPSData->PurifyData.ChildLock = 0;

	sPSData->AirConditionData.Swtich = 0;
//	sPSData->AirConditionData.ModelSetting = "";
	sPSData->AirConditionData.TimingSwtich = 0;
	sPSData->AirConditionData.TimeSetting1 = 0;
	sPSData->AirConditionData.TimeSetting2 = 0;
	sPSData->AirConditionData.TimeValueOpenSetting1 = 0;
	sPSData->AirConditionData.TimeValueCloseSetting1 = 0;
	sPSData->AirConditionData.TimeValueOpenSetting2 = 0;
	sPSData->AirConditionData.TimeValueCloseSetting2 = 0;
	sPSData->AirConditionData.TempValue1 = 0;
	sPSData->AirConditionData.TempValue2 = 0;
	sPSData->AirConditionData.AutoAirVolSetting = 0;		//自动风量 		0-1-2-3-4
	sPSData->AirConditionData.WindDirectSetting = 0;		//风向		0上下-1左右
	sPSData->AirConditionData.TempSettingValue = 20;		//温度设定
	sPSData->AirConditionData.NanoeX = 0;
	sPSData->AirConditionData.ModeSelect = 0;

	sPSData->HeatChangeData.Swtich = 0;
//	sPSData->HeatChangeData.ModelSetting = "";
	sPSData->HeatChangeData.TimingSwtich = 0;
	sPSData->HeatChangeData.TimeSetting1 = 0;
	sPSData->HeatChangeData.TimeSetting2 = 0;
	sPSData->HeatChangeData.TimeValueOpenSetting1 = 0;
	sPSData->HeatChangeData.TimeValueCloseSetting1 = 0;
	sPSData->HeatChangeData.TimeValueOpenSetting2 = 0;
	sPSData->HeatChangeData.TimeValueCloseSetting2 = 0;
	sPSData->HeatChangeData.TempValue1 = 0;
	sPSData->HeatChangeData.TempValue2 = 0;
	sPSData->HeatChangeData.NanoeX = 0;
	sPSData->HeatChangeData.ModeSetting = 0;
	sPSData->HeatChangeData.AutoAirVolSetting = 0;

	sPSData->AdjustHumdData.Swtich = 0;
//	sPSData->AdjustHumdData.ModelSetting = "";
	sPSData->AdjustHumdData.TimingSwtich = 0;
	sPSData->AdjustHumdData.TimeSetting1 = 0;
	sPSData->AdjustHumdData.TimeSetting2 = 0;
	sPSData->AdjustHumdData.TimeValueOpenSetting1 = 0;
	sPSData->AdjustHumdData.TimeValueCloseSetting1 = 0;
	sPSData->AdjustHumdData.TimeValueOpenSetting2 = 0;
	sPSData->AdjustHumdData.TimeValueCloseSetting2 = 0;
	sPSData->AdjustHumdData.TempValue1 = 0;
	sPSData->AdjustHumdData.TempValue2 = 0;
	sPSData->AdjustHumdData.AutoAirVolSetting = 0;	//自动风量 		0-1-2-3-4
	sPSData->AdjustHumdData.AirDirectSetting = 30;		//风向
	sPSData->AdjustHumdData.AdjustHumdValue = 20;			//温度设定
	sPSData->AdjustHumdData.FunctionSelectSetting = 0;

	sPSData->WindChangAirData.Swtich = 0;
//	sPSData->WindChangAirData.ModelSetting = "";
	sPSData->WindChangAirData.TimingSwtich = 0;
	sPSData->WindChangAirData.TimeSetting1 = 0;
	sPSData->WindChangAirData.TimeSetting2 = 0;
	sPSData->WindChangAirData.TimeValueOpenSetting1 = 0;
	sPSData->WindChangAirData.TimeValueCloseSetting1 = 0;
	sPSData->WindChangAirData.TimeValueOpenSetting2 = 0;
	sPSData->WindChangAirData.TimeValueCloseSetting2 = 0;
	sPSData->WindChangAirData.TempValue1 = 0;
	sPSData->WindChangAirData.TempValue2 = 0;
	sPSData->WindChangAirData.NanoeX = 0;
	sPSData->WindChangAirData.AutoAirVolSetting = 0;		//自动风量 		0-1-2-3-4

	sPSData->YuBaData.Swtich = 0;
//	sPSData->YuBaData.ModelSetting = "";
	sPSData->YuBaData.TimingSwtich = 0;
	sPSData->YuBaData.TimeSetting1 = 0;
	sPSData->YuBaData.TimeSetting2 = 0;
	sPSData->YuBaData.TimeValueOpenSetting1 = 0;
	sPSData->YuBaData.TimeValueCloseSetting1 = 0;
	sPSData->YuBaData.TimeValueOpenSetting2 = 0;
	sPSData->YuBaData.TimeValueCloseSetting2 = 0;
	sPSData->YuBaData.TempValue1 = 0;
	sPSData->YuBaData.TempValue2 = 0;
	sPSData->YuBaData.HeatDrySetting = 0;			//热干燥	0强-1弱
	sPSData->YuBaData.ColdDrySetting = 0;			//凉干燥	0强-1弱
	sPSData->YuBaData.AirDirectSetting = 0;			//风向	0手动-1自动
	sPSData->YuBaData.WindType = 0;					//风种	0集中-1扩散
	sPSData->YuBaData.NanoeX = 0;
	sPSData->YuBaData.HeatingSetting = 0;			//取暖	0强-1弱
	sPSData->YuBaData.AirChangeSetting = 0;			//换气 	0强-1弱
	sPSData->YuBaData.BrightnessSetting = 0;			//照明	0冷色-1暖色
}


void ManualStatusListence::setAirPFAutoWind(int value){
	sPSData->PurifyData.AutoWindVolSetting = value;
}

void ManualStatusListence::setAirPFWindDirec(int value){
	sPSData->PurifyData.WindDirectSetting = value;
}

void ManualStatusListence::setAirPFHumdValue(int value){
	sPSData->PurifyData.AddHumdSetting = value;
}

void ManualStatusListence::setAirPFNanoeX(int value){
	sPSData->PurifyData.NanoexSetting = value;
}

void ManualStatusListence::setAirPFBright(int value){
	sPSData->PurifyData.BrightSetting = value;
}

void ManualStatusListence::setAirPFFilter(int value){
	sPSData->PurifyData.FilterReset = value;
}

void ManualStatusListence::setAirPFChildLock(int value){
	sPSData->PurifyData.ChildLock = value;
}

void ManualStatusListence::setAirPFSwitch(int value){
	sPSData->PurifyData.Switch = value;
}

int ManualStatusListence::getAirPFSwitch(){
	return sPSData->PurifyData.Switch;
}

void ManualStatusListence::setAirPFModel(const char *value){
	strcpy(sPSData->PurifyData.ModelSetting, value);
}

void ManualStatusListence::setAirPFTimeSwitch(int value){
	sPSData->PurifyData.TimingSwitch = value;
}

int ManualStatusListence::getAirPFTimeSwitch(){
	return sPSData->PurifyData.TimingSwitch;
}

void ManualStatusListence::setAirPFTimeInfo(EquipmentTiming *info){
	if (info->DeviceID != AirPURIFY || !info){
		return;
	}
	if (!info->DeviceSwitch){
		sPSData->PurifyData.TimingSwitch = 0;
		return;
	}
	sPSData->PurifyData.TimingSwitch = 1;
	if (info->Time1StageFlag){
		sPSData->PurifyData.TimeSetting1 = 1;
		sPSData->PurifyData.TimeValueOpenSetting1 = info->TimeOpenValue1;
		sPSData->PurifyData.TimeValueCloseSetting1 = info->TimeCloseValue1;
		sPSData->PurifyData.TempValue1 = info->TempSettingValue1;
	}
	if (info->Time2StageFlag){
		sPSData->PurifyData.TimeSetting2 = 1;
		sPSData->PurifyData.TimeValueOpenSetting2 = info->TimeOpenValue2;
		sPSData->PurifyData.TimeValueCloseSetting2 = info->TimeCloseValue2;
		sPSData->PurifyData.TempValue2 = info->TempSettingValue2;
	}


}


void ManualStatusListence::setAirAutoWind(int value){
	sPSData->AirConditionData.AutoAirVolSetting = value;
}

void ManualStatusListence::setAirWindDirect(int value){
	sPSData->AirConditionData.WindDirectSetting = value;
}

void ManualStatusListence::setAirMode(int value){
	sPSData->AirConditionData.ModeSelect = value;
}

void ManualStatusListence::setAirTemp(int value){
	sPSData->AirConditionData.TempSettingValue = value;
}

void ManualStatusListence::setAirSwitch(int value){
	sPSData->AirConditionData.Swtich = value;
}

int ManualStatusListence::getAirSwitch(){
	return sPSData->AirConditionData.Swtich;
}

void ManualStatusListence::setAirModel(const char *value){
//	sPSData->AirConditionData.ModelSetting = value;
	strcpy(sPSData->AirConditionData.ModelSetting, value);
}

void ManualStatusListence::setAirTimeSwitch(int value){
	sPSData->AirConditionData.TimingSwtich = value;
}

int ManualStatusListence::getAirTimeSwitch(){
	return sPSData->AirConditionData.TimingSwtich;
}

void ManualStatusListence::setAirTimeInfo(EquipmentTiming *info){
	if (info->DeviceID != AIRCONDITION || !info){
		return;
	}
	if (!info->DeviceSwitch){
		sPSData->AirConditionData.TimingSwtich = 0;
		return;
	}
	sPSData->AirConditionData.TimingSwtich = 1;
	if (info->Time1StageFlag){
		sPSData->AirConditionData.TimeSetting1 = 1;
		sPSData->AirConditionData.TimeValueOpenSetting1 = info->TimeOpenValue1;
		sPSData->AirConditionData.TimeValueCloseSetting1 = info->TimeCloseValue1;
		sPSData->AirConditionData.TempValue1 = info->TempSettingValue1;
	}
	if (info->Time2StageFlag){
		sPSData->AirConditionData.TimeSetting2 = 1;
		sPSData->AirConditionData.TimeValueOpenSetting2 = info->TimeOpenValue2;
		sPSData->AirConditionData.TimeValueCloseSetting2 = info->TimeCloseValue2;
		sPSData->AirConditionData.TempValue2 = info->TempSettingValue2;
	}
}

void ManualStatusListence::setHeatChangeAutoWind(int value){
	sPSData->HeatChangeData.AutoAirVolSetting = value;
}

void ManualStatusListence::setHeatChangeNanoeX(int value){
	sPSData->HeatChangeData.NanoeX = value;
}

void ManualStatusListence::setHeatChangeMode(int value){
	sPSData->HeatChangeData.ModeSetting = value;
}

void ManualStatusListence::setHeatChangeModel(const char *value){
//	sPSData->HeatChangeData.ModelSetting = value;
	strcpy(sPSData->HeatChangeData.ModelSetting, value);
}

void ManualStatusListence::setHeatChangeSwitch(int value){
	sPSData->HeatChangeData.Swtich = value;
}

int ManualStatusListence::getHeatChangeSwitch(){
	return sPSData->HeatChangeData.Swtich;
}

void ManualStatusListence::setHeatChangeTimeSwitch(int value){
	sPSData->HeatChangeData.TimingSwtich = value;
}

int ManualStatusListence::getHeatChangeTimeSwitch(){
	return sPSData->HeatChangeData.TimingSwtich;
}

void ManualStatusListence::setHeatChangeTimeInfo(EquipmentTiming *info){
	if (info->DeviceID != HOTEXCHANGE || !info){
		return;
	}
	if (!info->DeviceSwitch){
		sPSData->HeatChangeData.TimingSwtich = 0;
		return;
	}
	sPSData->HeatChangeData.TimingSwtich = 1;
	if (info->Time1StageFlag){
		sPSData->HeatChangeData.TimeSetting1 = 1;
		sPSData->HeatChangeData.TimeValueOpenSetting1 = info->TimeOpenValue1;
		sPSData->HeatChangeData.TimeValueCloseSetting1 = info->TimeCloseValue1;
		sPSData->HeatChangeData.TempValue1 = info->TempSettingValue1;
	}
	if (info->Time2StageFlag){
		sPSData->HeatChangeData.TimeSetting2 = 1;
		sPSData->HeatChangeData.TimeValueOpenSetting2 = info->TimeOpenValue2;
		sPSData->HeatChangeData.TimeValueCloseSetting2 = info->TimeCloseValue2;
		sPSData->HeatChangeData.TempValue2 = info->TempSettingValue2;
	}
}

void ManualStatusListence::setHumdAutoWind(int value){
	sPSData->AdjustHumdData.AutoAirVolSetting = value;
}

void ManualStatusListence::setHumdWindDirect(int value){
	sPSData->AdjustHumdData.AirDirectSetting = value;
}

void ManualStatusListence::setHumdsettingHumd(int value){
	sPSData->AdjustHumdData.AdjustHumdValue = value;
}

void ManualStatusListence::setHumdMode(int value){
	sPSData->AdjustHumdData.FunctionSelectSetting = value;
}

void ManualStatusListence::setHumdModel(const char *value){
//	sPSData->AdjustHumdData.ModelSetting = value;
	strcpy(sPSData->AdjustHumdData.ModelSetting, value);
}

void ManualStatusListence::setHumdSwitch(int value){
	sPSData->AdjustHumdData.Swtich = value;
}

int ManualStatusListence::getHumdSwitch(){
	return sPSData->AdjustHumdData.Swtich;
}

void ManualStatusListence::setHumdTimeSwitch(int value){
	sPSData->AdjustHumdData.TimingSwtich = value;
}
int ManualStatusListence::getHumdTimeSwitch(){
	return sPSData->AdjustHumdData.TimingSwtich;
}

void ManualStatusListence::setHumdTimeInfo(EquipmentTiming *info){
	if (info->DeviceID != DEHUMIDIFY || !info){
		return;
	}
	if (!info->DeviceSwitch){
		sPSData->AdjustHumdData.TimingSwtich = 0;
		return;
	}
	sPSData->AdjustHumdData.TimingSwtich = 1;
	if (info->Time1StageFlag){
		sPSData->AdjustHumdData.TimeSetting1 = 1;
		sPSData->AdjustHumdData.TimeValueOpenSetting1 = info->TimeOpenValue1;
		sPSData->AdjustHumdData.TimeValueCloseSetting1 = info->TimeCloseValue1;
		sPSData->AdjustHumdData.TempValue1 = info->TempSettingValue1;
	}
	if (info->Time2StageFlag){
		sPSData->AdjustHumdData.TimeSetting2 = 1;
		sPSData->AdjustHumdData.TimeValueOpenSetting2 = info->TimeOpenValue2;
		sPSData->AdjustHumdData.TimeValueCloseSetting2 = info->TimeCloseValue2;
		sPSData->AdjustHumdData.TempValue2 = info->TempSettingValue2;
	}
}

void ManualStatusListence::setWindAutoWind(int value){
	sPSData->WindChangAirData.AutoAirVolSetting = value;
}

void ManualStatusListence::setWindNaneoX(int value){
	sPSData->WindChangAirData.NanoeX = value;
}

void ManualStatusListence::setWindModel(const char *value){
//	sPSData->WindChangAirData.ModelSetting = value;
	strcpy(sPSData->WindChangAirData.ModelSetting, value);
}

void ManualStatusListence::setWindSwitch(int value){
	sPSData->WindChangAirData.Swtich = value;
}

int ManualStatusListence::getWindSwitch(){
	return sPSData->WindChangAirData.Swtich;
}

void ManualStatusListence::setWindTimeSwitch(int value){
	sPSData->WindChangAirData.TimingSwtich = value;
}

int ManualStatusListence::getWindTimeSwitch(){
	return sPSData->WindChangAirData.TimingSwtich;
}

void ManualStatusListence::setWindTimeInfo(EquipmentTiming *info){
	if (info->DeviceID != WINDEXCHANGE || !info){
		return;
	}
	if (!info->DeviceSwitch){
		sPSData->WindChangAirData.TimingSwtich = 0;
		return;
	}
	sPSData->WindChangAirData.TimingSwtich = 1;
	if (info->Time1StageFlag){
		sPSData->WindChangAirData.TimeSetting1 = 1;
		sPSData->WindChangAirData.TimeValueOpenSetting1 = info->TimeOpenValue1;
		sPSData->WindChangAirData.TimeValueCloseSetting1 = info->TimeCloseValue1;
		sPSData->WindChangAirData.TempValue1 = info->TempSettingValue1;
	}
	if (info->Time2StageFlag){
		sPSData->WindChangAirData.TimeSetting2 = 1;
		sPSData->WindChangAirData.TimeValueOpenSetting2 = info->TimeOpenValue2;
		sPSData->WindChangAirData.TimeValueCloseSetting2 = info->TimeCloseValue2;
		sPSData->WindChangAirData.TempValue2 = info->TempSettingValue2;
	}
}

void ManualStatusListence::setYuBaHeatDry(int value){
	sPSData->YuBaData.HeatDrySetting = value;
}

void ManualStatusListence::setYuBaColdDry(int value){
	sPSData->YuBaData.ColdDrySetting = value;
}

void ManualStatusListence::setYuBaChangeAir(int value){
	sPSData->YuBaData.AirChangeSetting = value;
}

void ManualStatusListence::setYuBaHeating(int value){
	sPSData->YuBaData.HeatingSetting = value;
}

void ManualStatusListence::setYuBaWindDirct(int value){
	sPSData->YuBaData.AirDirectSetting = value;
}

void ManualStatusListence::setYuBaWindType(int value){
	sPSData->YuBaData.WindType = value;
}

void ManualStatusListence::setYuBaNaneoX(int value){
	sPSData->YuBaData.NanoeX = value;
}

void ManualStatusListence::setYuBaBright(int value){
	sPSData->YuBaData.BrightnessSetting = value;
}

void ManualStatusListence::setYuBaSwitch(int value){
	sPSData->YuBaData.Swtich = value;
}

int ManualStatusListence::getYuBaSwitch(){
	return sPSData->YuBaData.Swtich;
}

void ManualStatusListence::setYuBaModel(const char *value){
//	sPSData->YuBaData.ModelSetting = value;
	strcpy(sPSData->YuBaData.ModelSetting, value);
}

void ManualStatusListence::setYuBaTimeSwitch(int value){
	sPSData->YuBaData.TimingSwtich = value;
}

int ManualStatusListence::getYuBaTimeSwitch(){
	return sPSData->YuBaData.TimingSwtich;
}

void ManualStatusListence::setYuBaTimeInfo(EquipmentTiming *info){
	if (info->DeviceID != YUBA || !info){
		return;
	}
	if (!info->DeviceSwitch){
		sPSData->YuBaData.TimingSwtich = 0;
		return;
	}
	sPSData->YuBaData.TimingSwtich = 1;
	if (info->Time1StageFlag){
		sPSData->YuBaData.TimeSetting1 = 1;
		sPSData->YuBaData.TimeValueOpenSetting1 = info->TimeOpenValue1;
		sPSData->YuBaData.TimeValueCloseSetting1 = info->TimeCloseValue1;
		sPSData->YuBaData.TempValue1 = info->TempSettingValue1;
	}
	if (info->Time2StageFlag){
		sPSData->YuBaData.TimeSetting2 = 1;
		sPSData->YuBaData.TimeValueOpenSetting2 = info->TimeOpenValue2;
		sPSData->YuBaData.TimeValueCloseSetting2 = info->TimeCloseValue2;
		sPSData->YuBaData.TempValue2 = info->TempSettingValue2;
	}
}

SProtocolSendData* ManualStatusListence::getCurrentManualData(){
	return sPSData;
}

void ManualStatusListence::setTempthreadholdData(int value){
	sPSData->CommonDate.TempThresHoldSetting = value;
}

void ManualStatusListence::setHumdthreadholdData(int value){
	sPSData->CommonDate.HumdThresHoldSetting = value;
}

void ManualStatusListence::setCo2threadholdData(int value){
	sPSData->CommonDate.Co2ThresHoldSetting = value;
}

void ManualStatusListence::setPm25threadholdData(int value){
	sPSData->CommonDate.Pm25ThresHoldSetting = value;
}

void ManualStatusListence::setTvocthreadholdData(float value){
	sPSData->CommonDate.TvocThresHoldSetting = value;
}

void ManualStatusListence::setformaldehydethreadholdData(float value){
	sPSData->CommonDate.FormaldehydeThresHoldSetting = value;
}

int ManualStatusListence::getTempthreadholdData(){
	return sPSData->CommonDate.TempThresHoldSetting;
}

int ManualStatusListence::getHumdthreadholdData(){
	return sPSData->CommonDate.HumdThresHoldSetting;
}

int ManualStatusListence::getCo2threadholdData(){
	return sPSData->CommonDate.Co2ThresHoldSetting;
}

int ManualStatusListence::getPm25threadholdData(){
	return sPSData->CommonDate.Pm25ThresHoldSetting;
}

float ManualStatusListence::getTvocthreadholdData(){
	return sPSData->CommonDate.TvocThresHoldSetting;
}

float ManualStatusListence::getformaldehydethreadholdData(){
	return sPSData->CommonDate.FormaldehydeThresHoldSetting;
}

void ManualStatusListence::setWifiSwitch(int value){
	sPSData->CommonDate.WifiSwitch = value;
}

void ManualStatusListence::setWifiStatus(int value){
	sPSData->CommonDate.WIFIStatus = value;
}

void ManualStatusListence::setVoiceSysSwitch(int value){
	sPSData->CommonDate.VoiceSystemSwitch = value;
}

void ManualStatusListence::setMainMachineMode(int value){
	sPSData->CommonDate.MainMachineMode = value;
}

void ManualStatusListence::setRf254Switch(int value){
	sPSData->CommonDate.RF254Switch = value;
}















