/*
 * ProtocolSendData.h
 *
 *  Created on: 2021年6月4日
 *      Author: 80022678
 */
#include "ProtocolData.h"

#ifndef JNI_UART_PROTOCOLSENDDATA_H_
#define JNI_UART_PROTOCOLSENDDATA_H_



typedef struct AirConditionSendData_t {
	BYTE Swtich;
	BYTE TimingSwtich;
	UINT16 ModelSetting;
	BYTE TimeSetting1;
	BYTE TimeSetting2;
	UINT16 TimeValueSetting1;
	UINT16 TimeValueSetting2;
	UINT16 AutoAirVolSetting;		//自动风量 		0-1-2-3
	UINT16 WindDirectSetting;		//风向		0上下-1左右
	UINT16 TempSettingValue;		//温度设定
	BYTE NanoeX;
	BYTE ModeSelect;				//模式选择		自动-制暖-制冷-抽湿
}AirConditionSendData;


typedef struct PurifySendData_t {
	BYTE Switch;
	BYTE ModelSelect;
	BYTE TimingSwitch;
	BYTE TimeSetting1;
	BYTE TimeSetting2;
	UINT16 TimeValueSetting1;
	UINT16 TimeValueSetting2;
	BYTE AutoWindVolSetting;		//自动风量 		0-1-2-3
	UINT16 WindDirectSetting;		//风向
	UINT16 AddHumdSetting;			//加湿
	BYTE NanoexSetting;
	UINT16 BrightSetting;			//亮度
	BYTE FilterReset;				//滤网复位		0-1
	BYTE ChildLock;
}PurifySendData;

typedef struct HeatChangeSendData_t {
	BYTE Swtich;
	BYTE TimingSwtich;
	UINT16 ModelSetting;
	BYTE TimeSetting1;
	BYTE TimeSetting2;
	UINT16 TimeValueSetting1;
	UINT16 TimeValueSetting2;
	UINT16 AutoAirVolSetting;		//自动风量 		0-1-2-3
	UINT16 ModeSetting;				//模式选择		自动-热交换-内循环
	BYTE NanoeX;
}HeatChangeSendData;

typedef struct AdjustHumdSendData_t {
	BYTE Swtich;
	BYTE TimingSwtich;
	UINT16 ModelSetting;
	BYTE TimeSetting1;
	BYTE TimeSetting2;
	UINT16 TimeValueSetting1;
	UINT16 TimeValueSetting2;
	UINT16 AutoAirVolSetting;		//自动风量 		0-1-2-3
	UINT16 AirDirectSetting;		//风向
	UINT16 AdjustHumdValue;			//温度设定
	BYTE FunctionSelectSetting;		//功能选择		自动除湿-连续除湿-保湿-送风
}AdjustHumdSendData;


typedef struct WindChangAirSendData_t {
	BYTE Swtich;
	BYTE TimingSwtich;
	UINT16 ModelSetting;
	BYTE TimeSetting1;
	BYTE TimeSetting2;
	UINT16 TimeValueSetting1;
	UINT16 TimeValueSetting2;
	BYTE NanoeX;
	UINT16 AutoAirVolSetting;		//自动风量 		0-1-2-3
}WindChangAirSendData;


typedef struct YuBaSendData_t {
	BYTE Swtich;
	BYTE TimingSwtich;
	UINT16 ModelSetting;
	BYTE TimeSetting1;
	BYTE TimeSetting2;
	UINT16 TimeValueSetting1;
	UINT16 TimeValueSetting2;
	BYTE HeatDrySetting;			//热干燥	0强-1弱
	BYTE ColdDrySetting;			//凉干燥	0强-1弱
	BYTE AirDirectSetting;			//风向	0手动-1自动
	BYTE WindType;					//风种	0集中-1扩散
	BYTE NanoeX;
	BYTE HeatingSetting;			//取暖	0强-1弱
	BYTE AirChangeSetting;			//换气 	0快速换气-1强-2弱
	BYTE BrightnessSetting;			//照明	0冷色-1暖色
}YuBaSendData;

typedef union {
	PurifySendData PurifyData;
	AirConditionSendData AirConditionData;
	HeatChangeSendData HeatChangeData;
	AdjustHumdSendData AdjustHumdData;
	WindChangAirSendData WindChangAirData;
	YuBaSendData YuBaData;
}SProtocolSendData;



#endif /* JNI_UART_PROTOCOLSENDDATA_H_ */
