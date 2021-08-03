/*
 * ProtocolDataSend.h
 *
 *  Created on: 2021年6月7日
 *      Author: 80022678
 */

#ifndef JNI_UTIL_PROTOCOLDATASEND_H_
#define JNI_UTIL_PROTOCOLDATASEND_H_

#include "uart/ProtocolData.h"

typedef struct CommonSendDate_t{
	UINT16 TempThresHoldSetting;		//温度阈值设定
	UINT16 HumdThresHoldSetting;		//温度阈值设定
	UINT16 Pm25ThresHoldSetting;		//温度阈值设定
	UINT16 Co2ThresHoldSetting;			//温度阈值设定
	UINT16 TvocThresHoldSetting;		//温度阈值设定
	UINT16 FormaldehydeThresHoldSetting;		//甲醛阈值设定
	BYTE WifiSwitch;					//wifi开关	0关-1开
	BYTE WIFIStatus;					//wifi状态    0关闭-1已连接-2连接异常
	BYTE ERVPreventCondensation;		//erv防止结霜标志
	BYTE ERVPreventFreezing;			//erv防止冻结标志
	BYTE AirCondiOutdoorDefrost;		//空调外机除霜标志
	BYTE PreventMode;					//保护模式标志
	BYTE AdjustHumdPreCondensation;		//调湿防结霜标志
	BYTE AdjustHumdDry;					//调湿干燥标志
	BYTE NanoeXSwitch;					//nanoex开关
	BYTE ImmediateCommunicationSwitch;	//即时通讯
	BYTE EmergencyCallSwitch;			//紧急呼叫
	BYTE RF254Switch;					//RF254开关
	BYTE MainMachineMode;				//主辅机模式 	0辅机-1主机
	UINT16 EnvSetting;					//环境设置  		客厅-厨房-浴室-次卧-书房-卫生间-储物间
	BYTE VoiceSystemSwitch;				//语音系统开关
	BYTE WifiVersionUpdate;				//wifi版本更新
	BYTE GUIVersionUpdate;				//gui版本更新
	BYTE ResetFactorySetting;			//恢复出厂设置
	BYTE MainBoardStatus;				//电源板暂停/启动状态
	BYTE WorkOrder;						//工作命令
	BYTE Dealing;						//本体处理中
	BYTE OTAStatus;						//OTA状态
	BYTE HumanPerceptionStatus;			//人体感知状态
	BYTE ChildrenLockStatus;			//儿童锁记忆标志
	BYTE APPOrder;						//APP控制指令
	BYTE HUError;						//H/U异常
	BYTE WindSettingSwitch;				//新风开关
	BYTE AdjustHumdSettingSwitch;		//调湿开关
	BYTE HeatChangeSettingSwitch;		//热交换开关
	BYTE AirCondHumdAdjustSettingSwitch;	//空调湿度调节开关
	BYTE PurifySettingSwitch;			//净化开关
	BYTE DeHumdSettingSwitch;		//除湿开关
	BYTE AirPurifySettingSwitch;		//空气净化器开关
	BYTE AirConditionSettingSwitch;		//空调开关
	BYTE AutoAdjustHumd40to60SettingSwitch;		//自动调湿40%-60%开关
	BYTE AdjustAircondiHumd26degreeSettingSwitch;		//空调湿度调节26℃开关
	BYTE AirOnekeyAdjustSettingSwitch;		//空气一键调节开关
}CommonSendDate;

typedef struct AirConditionSendData_t {
	BYTE Swtich;
	BYTE TimingSwtich;
	char ModelSetting[64];
	BYTE TimeSetting1;
	BYTE TimeSetting2;
	UINT16 TimeValueOpenSetting1;
	UINT16 TimeValueCloseSetting1;
	UINT16 TimeValueOpenSetting2;
	UINT16 TimeValueCloseSetting2;
	BYTE TempValue1;
	BYTE TempValue2;
	UINT16 AutoAirVolSetting;		//自动风量 		0-1-2-3-4
	UINT16 WindDirectSetting;		//风向		0上下-1左右
	UINT16 TempSettingValue;		//温度设定
	BYTE NanoeX;
	BYTE ModeSelect;				//模式选择		0自动-1制暖-2制冷-3抽湿
}AirConditionSendData;


typedef struct PurifySendData_t {
	BYTE Switch;
	char ModelSetting[64];
	BYTE TimingSwitch;
	BYTE TimeSetting1;
	BYTE TimeSetting2;
	UINT16 TimeValueOpenSetting1;
	UINT16 TimeValueCloseSetting1;
	UINT16 TimeValueOpenSetting2;
	UINT16 TimeValueCloseSetting2;
	BYTE TempValue1;
	BYTE TempValue2;
	BYTE AutoWindVolSetting;		//自动风量 		0-1-2-3-4
	UINT16 WindDirectSetting;		//风向
	UINT16 AddHumdSetting;			//加湿
	BYTE NanoexSetting;
	UINT16 BrightSetting;			//亮度
	BYTE FilterReset;				//滤网复位
	BYTE ChildLock;
}PurifySendData;

typedef struct HeatChangeSendData_t {
	BYTE Swtich;
	BYTE TimingSwtich;
	char ModelSetting[64];
	BYTE TimeSetting1;
	BYTE TimeSetting2;
	UINT16 TimeValueOpenSetting1;
	UINT16 TimeValueCloseSetting1;
	UINT16 TimeValueOpenSetting2;
	UINT16 TimeValueCloseSetting2;
	BYTE TempValue1;
	BYTE TempValue2;
	UINT16 AutoAirVolSetting;		//自动风量 		0-1-2-3-4
	UINT16 ModeSetting;				//模式选择		0自动-1热交换-2内循环
	BYTE NanoeX;
}HeatChangeSendData;

typedef struct AdjustHumdSendData_t {
	BYTE Swtich;
	BYTE TimingSwtich;
	char ModelSetting[64];
	BYTE TimeSetting1;
	BYTE TimeSetting2;
	UINT16 TimeValueOpenSetting1;
	UINT16 TimeValueCloseSetting1;
	UINT16 TimeValueOpenSetting2;
	UINT16 TimeValueCloseSetting2;
	BYTE TempValue1;
	BYTE TempValue2;
	UINT16 AutoAirVolSetting;		//自动风量 		0-1-2-3-4
	UINT16 AirDirectSetting;		//风向
	UINT16 AdjustHumdValue;			//温度设定
	BYTE FunctionSelectSetting;		//功能选择		0自动除湿-1连续除湿-2送风
}AdjustHumdSendData;


typedef struct WindChangAirSendData_t {
	BYTE Swtich;
	BYTE TimingSwtich;
	char ModelSetting[64];
	BYTE TimeSetting1;
	BYTE TimeSetting2;
	UINT16 TimeValueOpenSetting1;
	UINT16 TimeValueCloseSetting1;
	UINT16 TimeValueOpenSetting2;
	UINT16 TimeValueCloseSetting2;
	BYTE TempValue1;
	BYTE TempValue2;
	BYTE NanoeX;
	UINT16 AutoAirVolSetting;		//自动风量 		0-1-2-3-4
}WindChangAirSendData;


typedef struct YuBaSendData_t {
	BYTE Swtich;
	BYTE TimingSwtich;
	char ModelSetting[64];
	BYTE TimeSetting1;
	BYTE TimeSetting2;
	UINT16 TimeValueOpenSetting1;
	UINT16 TimeValueCloseSetting1;
	UINT16 TimeValueOpenSetting2;
	UINT16 TimeValueCloseSetting2;
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
}YuBaSendData;

typedef union {
	CommonSendDate CommonDate;
	PurifySendData PurifyData;
	AirConditionSendData AirConditionData;
	HeatChangeSendData HeatChangeData;
	AdjustHumdSendData AdjustHumdData;
	WindChangAirSendData WindChangAirData;
	YuBaSendData YuBaData;
}SProtocolSendData;


#endif

