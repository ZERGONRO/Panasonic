/*
 * MachineStatusDefaultData.h
 *
 *  Created on: 2021年8月2日
 *      Author: 80022678
 */

#ifndef JNI_UTIL_MACHINESTATUSDEFAULTDATA_H_
#define JNI_UTIL_MACHINESTATUSDEFAULTDATA_H_
#include "util/ProtocolDataSend.h"

PurifySendData AirPFDefaultData = {
		Switch : 0,
		ModelSetting : 0,
		TimingSwitch : 0,
		TimeSetting1 : 0,
		TimeSetting2 : 0,
		TimeValueOpenSetting1 : 0,
		TimeValueCloseSetting1 : 0,
		TimeValueOpenSetting2 : 0,
		TimeValueCloseSetting2 : 0,
		TempValue1 : 0,
		TempValue2 : 0,
		AutoWindVolSetting : 0,		//自动风量 		0-1-2-3-4
		WindDirectSetting : 0,		//风向
		AddHumdSetting : 0,			//加湿
		NanoexSetting : 0,
		BrightSetting : 0,			//亮度
		FilterReset : 0,				//滤网复位
		ChildLock : 0,
};

AirConditionSendData AirDefaultData = {
		Swtich : 0,
		TimingSwtich : 0,
		ModelSetting : 0,
		TimeSetting1 : 0,
		TimeSetting2 : 0,
		TimeValueOpenSetting1 : 0,
		TimeValueCloseSetting1 : 0,
		TimeValueOpenSetting2 : 0,
		TimeValueCloseSetting2 : 0,
		TempValue1 : 0,
		TempValue2 : 0,
		AutoAirVolSetting : 0,		//自动风量 		0-1-2-3-4
		WindDirectSetting : 0,		//风向		0上下-1左右
		TempSettingValue : 0,		//温度设定
		NanoeX : 0,
		ModeSelect : 0,				//模式选择		0自动-1制暖-2制冷-3抽湿
};

HeatChangeSendData HeatChangDefaultData = {
		Swtich : 0,
		TimingSwtich : 0,
		ModelSetting : 0,
		TimeSetting1 : 0,
		TimeSetting2 : 0,
		TimeValueOpenSetting1 : 0,
		TimeValueCloseSetting1 : 0,
		TimeValueOpenSetting2 : 0,
		TimeValueCloseSetting2 : 0,
		TempValue1 : 0,
		TempValue2 : 0,
		AutoAirVolSetting : 0,		//自动风量 		0-1-2-3-4
//		WindDirectSetting : 0,		//风向		0上下-1左右
//		TempSettingValue : 0,		//温度设定
		NanoeX : 0,
		ModeSetting : 0,
//		ModeSelect : 0,				//模式选择		0自动-1制暖-2制冷-3抽湿
};

AdjustHumdSendData AdjustHumdDefaultData = {
		Swtich : 0,
		TimingSwtich : 0,
		ModelSetting : 0,
		TimeSetting1 : 0,
		TimeSetting2 : 0,
		TimeValueOpenSetting1 : 0,
		TimeValueCloseSetting1 : 0,
		TimeValueOpenSetting2 : 0,
		TimeValueCloseSetting2 : 0,
		TempValue1 : 0,
		TempValue2 : 0,
		AutoAirVolSetting : 0,	//自动风量 		0-1-2-3-4
		AirDirectSetting : 0,		//风向
		AdjustHumdValue : 0,			//温度设定
		FunctionSelectSetting : 0,		//功能选择		0自动除湿-1连续除湿-2送风
};

WindChangAirSendData WindChangeDefaultData = {
		Swtich : 0,
		TimingSwtich : 0,
		ModelSetting : 0,
		TimeSetting1 : 0,
		TimeSetting2 : 0,
		TimeValueOpenSetting1 : 0,
		TimeValueCloseSetting1 : 0,
		TimeValueOpenSetting2 : 0,
		TimeValueCloseSetting2 : 0,
		TempValue1 : 0,
		TempValue2 : 0,
		NanoeX : 0,
		AutoAirVolSetting : 0,		//自动风量 		0-1-2-3-4
};

YuBaSendData YuBaDefaultData = {
		Swtich : 0,
		TimingSwtich : 0,
		ModelSetting : 0,
		TimeSetting1 : 0,
		TimeSetting2 : 0,
		TimeValueOpenSetting1 : 0,
		TimeValueCloseSetting1 : 0,
		TimeValueOpenSetting2 : 0,
		TimeValueCloseSetting2 : 0,
		TempValue1 : 0,
		TempValue2 : 0,
		HeatDrySetting : 0,			//热干燥	0强-1弱
		ColdDrySetting : 0,			//凉干燥	0强-1弱
		AirDirectSetting : 0,			//风向	0手动-1自动
		WindType : 0,					//风种	0集中-1扩散
		NanoeX : 0,
		HeatingSetting : 0,			//取暖	0强-1弱
		AirChangeSetting : 0,			//换气 	0强-1弱
		BrightnessSetting : 0,			//照明	0冷色-1暖色
};


#endif /* JNI_UTIL_MACHINESTATUSDEFAULTDATA_H_ */
