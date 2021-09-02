/*
 * ProtocolSendData.h
 *
 *  Created on: 2021年7月20日
 *      Author: 80022717
 */

#ifndef JNI_UART_PROTOCOLSENDDATA_H_
#define JNI_UART_PROTOCOLSENDDATA_H_

#include "ProtocolData.h"

typedef struct userModeSendData_t{
	BYTE mainAuxMode;					//主辅机
	BYTE mainMode;						//主模式
	BYTE subMode;						//子模式
	BYTE airPurifierSwitch;				//空气净化器开关
	BYTE windDirectAirPurifier;			//净化风向
	UINT16 autoAirVolAirPurifier;		//净化自动风量 		0-1-2-3-4
	BYTE brightAirPurifier;				//净化亮度
	BYTE filterResetAirPurifier;		//净化滤网复位
	BYTE nanoexAirPurifier;				//净化nanoex
	BYTE addHumdAirPurifier;			//净化加湿
	BYTE heatExchangerSwitch;			//全热交换器开关
	UINT16 autoAirVolHeatExchanger;		//全热交换器自动风量
	BYTE modeHeatExchanger;				//全热交换器模式
	BYTE nanoexHeatExchanger;			//全热交换器nanoex
	BYTE airConditionSwitch;			//空调开关
	BYTE windDirectAirCondition;		//空调风向
	BYTE autoAirVolAirCondition;		//空调自动风量
	BYTE modeAirCondition;				//空调模式
	BYTE nanoexAirCondition;			//空调nanoex
	UINT16 tempAirConditionSetting;		//空调温度设定
	BYTE adjustHumdSwitch;				//调试器开关
	UINT16 windDirectAdjustHumd; 		//调湿器风向
	BYTE autoAirVolAdjustHumd;			//调湿器自动风量
	BYTE modeAdjustHumd;				//调湿器模式
	UINT16 humdAdjustHumdSetting;		//调湿器湿度设定
	BYTE yuBaSwitch;					//浴霸开关
	BYTE windDirectYuBa;				//浴霸风向
	BYTE heatingYuBaSetting;			//浴霸取暖设定
	BYTE heatDryYuBaSetting;			//浴霸热干燥设定
	BYTE coldDryYuBaSetting;			//浴霸凉干燥设定
	BYTE lightingYuBaSetting;			//浴霸照明设定
	BYTE nanoexYuBa;					//浴霸nanoex
	BYTE windTypeYuBa;					//浴霸风种
	BYTE airChangeYuBaSetting;			//浴霸换气
	BYTE beepSwitchState;				//蜂鸣器设定
	BYTE childLockState;				//儿童锁记忆标志
	BYTE wifiSwitch;					//wifi开关	0开-1关
	BYTE simpleModelSettingSwitch;		//简易模式
	BYTE darkModeSettingSwitch;			//深色模式
	BYTE positivePressureSettings;		//正压设置
	UINT16 brightLightSetting;			//背光设置
	UINT16 realTempState;				//当前温度
	UINT16 realHumdState;				//当前湿度
	UINT16 realCo2Content;				//当前CO2含量
	UINT16 realformaldehydeContent;		//当前甲醛含量
	UINT16 realTvocContent;				//当前TVOC含量
	UINT16 realPm25Content;				//当前PM25含量
	BYTE formaldehydeThresHoldSetting;	//甲醛阈值
	BYTE tvocThresHoldSetting;			//TVOC阈值
	BYTE co2ThresHoldSetting;			//CO2阈值
	BYTE pm25ThresHoldSetting;			//PM2.5阈值
	BYTE humdThresHoldSetting;			//湿度阈值
	BYTE tempThresHoldSetting;			//温度阈值
	BYTE dataResetSetting;				//恢复出厂设置
	BYTE dormantState;					//休眠状态
	BYTE airQuality;					//室内空气综合评价
	BYTE autoShutDown;					//自动关机
	BYTE manualShutDown;				//手动关机
	BYTE dealShutDown;					//关机处理判断
	BYTE displayPlace;					//显示场所
	BYTE voiceSystemSwitch;				//语音系统
	BYTE RF254Switch;					//RF254开关
	BYTE protectedModeState;			//保护模式状态
	BYTE modeUsefulSettingState;		//模式设定有效标志
	BYTE wifiCheckState;				//wifi检测标志
	BYTE wifiOTAState;					//wifi OTA状态设定
	BYTE IMState;						//即时通讯状态
	BYTE emergencyCallState;			//紧急呼救
	BYTE quickSwitchState;				//设备快捷开关标志
	BYTE refrigerantReplace;			//制冷剂更换提醒
	BYTE HUError;						//H/U异常


}userModeSendData;

typedef struct {
	userModeSendData userData;

}uartSendData;

typedef struct {
	int mode;
	uartSendData data;
}SendProtocolData;

#endif /* JNI_UART_PROTOCOLSENDDATA_H_ */
