/*
 * ProtocolDataRecv.h
 *
 *  Created on: 2021年6月7日
 *      Author: 80022678
 */
#ifndef JNI_UTIL_PROTOCOLDATARECV_H_
#define JNI_UTIL_PROTOCOLDATARECV_H_

#include "uart/ProtocolData.h"


typedef struct CommonRecvDate_t{
	int IndoorTempData;				//室内温度
	int IndoorHumdData;				//室内湿度
	int IndoorPm25Data;				//室内PM2.5
	float IndoorTvocData;				//室内tvoc
	int IndoorCo2Data;				//室内co2
	float IndoorFormaldehydeData;		//室内甲醛
	int OutdoorTempData;				//室外温度
	int OutdoorHumdData;				//室外湿度
	int OutdoorPM25Data;				//室外pm2.5
	int TempThresHoldSetting;		//温度阈值设定
	int HumdThresHoldSetting;		//湿度阈值设定
	int Pm25ThresHoldSetting;		//pm25阈值设定
	int CO2ThresHoldSetting;			//co2阈值设定
	float TvocThresHoldSetting;		//tvoc阈值设定
	float FormaldehydeThresHoldSetting;		//甲醛阈值设定
	BYTE WifiSwitch;					//wifi开关	0关-1开
//	BYTE WIFIStatus;					//wifi状态    0关闭-1已连接-2连接异常
	BYTE NanoeXSwitch;					//nanoex开关		0-1
	BYTE ImmediateCommunicationSwitch;	//即时通讯
	BYTE EmergencyCallSwitch;			//紧急呼叫
	BYTE RF254Switch;					//RF254开关
	BYTE MainMachineMode;				//主辅机模式 	0辅机-1主机
	BYTE VoiceSystemSwitch;				//语音系统开关
	BYTE ResetFactorySetting;			//恢复出厂设置
	BYTE MainBoardStatus;				//电源板暂停/启动状态
	BYTE WorkOrder;						//工作命令
	BYTE Dealing;						//本体处理中
	BYTE OTAStatus;						//OTA状态
	BYTE HumanPerceptionStatus;			//人体感知状态
	BYTE ChildrenLockStatus;			//儿童锁记忆标志
	BYTE APPOrder;						//APP控制指令
	BYTE HUError;						//H/U异常
	BYTE AirOnekeyAdjustSettingSwitch;		//空气一键调节开关
	BYTE MusicSwitch;					//音乐开关暂停键 		0关闭-1打开
	BYTE MusicModeSelc;					//音乐模式选择		0循环-1顺序-2随机
	BYTE MusicVolSwitch;				//音乐声音开关	0静音-1开音

}CommonRecvDate;

typedef struct PurifyRecvData_t{
	BYTE Switch;
	char ModelSetting[64];
	BYTE TimingSwitch;
	BYTE TimeSetting1;
	BYTE TimeSetting2;
	int TimeValueOpenSetting1;
	int TimeValueCloseSetting1;
	int TimeValueOpenSetting2;
	int TimeValueCloseSetting2;
	BYTE TempValue1;
	BYTE TempValue2;
	BYTE AutoWindVolSetting;		//自动风量 		0-1-2-3-4
	int WindDirectSetting;		//风向
	int AddHumdSetting;			//加湿
	BYTE NanoexSetting;
	BYTE BrightSetting;			//亮度
	BYTE FilterReset;				//滤网复位
	BYTE ChildLock;
}PurifyRecvData;


typedef struct AirConditionRecvData_t{
	BYTE Swtich;
	BYTE TimingSwtich;
	char ModelSetting[64];
	BYTE TimeSetting1;
	BYTE TimeSetting2;
	int TimeValueOpenSetting1;
	int TimeValueCloseSetting1;
	int TimeValueOpenSetting2;
	int TimeValueCloseSetting2;
	BYTE TempValue1;
	BYTE TempValue2;
	int AutoAirVolSetting;		//自动风量 		0-1-2-3-4
	int WindDirectSetting;		//风向		0上下-1左右
	int TempSettingValue;		//温度设定
	BYTE NanoeX;
	BYTE ModeSelect;				//模式选择		0自动-1制暖-2制冷-3抽湿
}AirConditionRecvData;


typedef struct HeatChangeRecvData_t {
	BYTE Swtich;
	BYTE TimingSwtich;
	char ModelSetting[64];
	BYTE TimeSetting1;
	BYTE TimeSetting2;
	int TimeValueOpenSetting1;
	int TimeValueCloseSetting1;
	int TimeValueOpenSetting2;
	int TimeValueCloseSetting2;
	BYTE TempValue1;
	BYTE TempValue2;
	BYTE AutoAirVolSetting;		//自动风量 		0-1-2-3-4
	BYTE ModeSetting;				//模式选择		0自动-1热交换-2内循环
	BYTE NanoeX;
}HeatChangeRecvData;


typedef struct AdjustHumdRecvData_t {
	BYTE Swtich;
	BYTE TimingSwtich;
	char ModelSetting[64];
	BYTE TimeSetting1;
	BYTE TimeSetting2;
	int TimeValueOpenSetting1;
	int TimeValueCloseSetting1;
	int TimeValueOpenSetting2;
	int TimeValueCloseSetting2;
	BYTE TempValue1;
	BYTE TempValue2;
	BYTE AutoAirVolSetting;		//自动风量 		0-1-2-3-4
	int AirDirectSetting;		//风向
	int AdjustHumdValue;			//温度设定
	BYTE FunctionSelectSetting;		//功能选择		0自动除湿-1连续除湿-2送风
}AdjustHumdRecvData;


typedef struct WindChangAirRecvData_t {
	BYTE Swtich;
	BYTE TimingSwtich;
	char ModelSetting[64];
	BYTE TimeSetting1;
	BYTE TimeSetting2;
	int TimeValueOpenSetting1;
	int TimeValueCloseSetting1;
	int TimeValueOpenSetting2;
	int TimeValueCloseSetting2;
	int TempValue1;
	int TempValue2;
	BYTE NanoeX;
	BYTE AutoAirVolSetting;		//自动风量 		0-1-2-3-4
}WindChangAirRecvData;


typedef struct YuBaRecvData_t {
	BYTE Swtich;
	BYTE TimingSwtich;
	char ModelSetting[64];
	BYTE TimeSetting1;
	BYTE TimeSetting2;
	int TimeValueOpenSetting1;
	int TimeValueCloseSetting1;
	int TimeValueOpenSetting2;
	int TimeValueCloseSetting2;
	BYTE TempValue1;
	BYTE TempValue2;
	BYTE HeatDrySetting;			//热干燥	0强-1弱
	BYTE ColdDrySetting;			//凉干燥	0强-1弱
	BYTE AirDirectSetting;			//风向	0手动-1自动
	BYTE WindType;					//风种	0集中-1扩散
	BYTE NanoeX;
	BYTE HeatingSetting;			//取暖	0强-1弱
	BYTE AirChangeSetting;			//换气 	0强-1弱
	BYTE BrightnessSetting;			//照明	0冷色-1暖色
}YuBaRecvData;



typedef struct {
	CommonRecvDate CommonDate;
	PurifyRecvData PurifyData;
	AirConditionRecvData AirConditionData;
	HeatChangeRecvData HeatChangeData;
	AdjustHumdRecvData AdjustHumdData;
	WindChangAirRecvData WindChangAirData;
	YuBaRecvData YuBaData;
}SProtocolRecvDate;



#endif
