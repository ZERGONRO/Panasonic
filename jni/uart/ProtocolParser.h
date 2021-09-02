/*
 * ProtocolParser.h
 *
 *  Created on: 2021年5月27日
 *      Author: 80022717
 */

#ifndef UART_PROTOCOLPARSER_H_
#define UART_PROTOCOLPARSER_H_


#ifndef BYTE
typedef unsigned char	BYTE;
#endif
#ifndef UINT
typedef unsigned int	UINT;
#endif
#ifndef UINT16
typedef unsigned short  UINT16;
#endif

#include "ProtocolData.h"

typedef struct functionMode_t{
	BYTE AirCondition;	//空调
	BYTE HeatExchanger;	//全热交换器
	BYTE AdjustHumd;	//调湿
	BYTE AirPurifier;	//空气净化器
	BYTE YuBa;			//浴霸
}functionMode;

typedef struct userModeData_t{
//	functionMode functionModeData;
	BYTE resetPermissionFlag;			//瞬停复位许可
	BYTE stopMoment;					//瞬停状态
	BYTE mainBoardStatus;				//电源板暂停/启动状态
	BYTE sensorInit;					//传感器初始化
	BYTE wifiSwitch;					//wifi开关	0开-1关
	BYTE childLockState;				//儿童锁记忆标志
	BYTE pretreatmentState;				//预处理行程
	BYTE workOrder;						//工作命令
	BYTE timingRunningstate;			//时序运转状态
	BYTE machineType;               	//机种区分
	BYTE beepSwitchState;				//蜂鸣器设定
	BYTE simpleModelSettingSwitch;		//简易模式
	BYTE darkModeSettingSwitch;			//深色模式
	BYTE positivePressureSettings;		//正压设置
	UINT16 brightLightSetting;			//背光设置
	BYTE airPurifierSwitch;				//空气净化器开关
	BYTE windDirectAirPurifier;			//净化风向
	UINT16 autoAirVolAirPurifier;		//净化自动风量 		0-1-2-3-4
	BYTE addHumdAirPurifier;			//净化加湿
	BYTE brightAirPurifier;				//净化亮度
	BYTE filterResetAirPurifier;		//净化滤网复位
	BYTE nanoexAirpurifier;				//净化nanoex
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
	UINT16 realTempState;				//当前温度
	UINT16 realHumdState;				//当前湿度
	UINT16 realCo2Content;				//当前CO2含量
	UINT16 realformaldehydeContent;		//当前甲醛含量
	UINT16 realTvocContent;				//当前TVOC含量
	UINT16 realPm25Content;				//当前PM25含量
	BYTE dataResetSetting;				//恢复出厂设置
	BYTE dormantState;					//休眠状态
	BYTE refrigerantReplace;			//制冷剂更换提醒
	BYTE autoShutDown;					//自动关机
	BYTE manualShutDown;				//手动关机
	BYTE dealShutDown;					//关机处理判断
	BYTE regularTime;					//定时时间
	BYTE timeRemaining;					//预约剩余时间
	BYTE HUError;						//H/U异常
	BYTE mainMachineMode;				//主辅机
	BYTE protectedModeState;			//保护模式状态
	BYTE airQuality;					//室内空气综合评价
	BYTE voiceSystemSwitch;				//语音系统
	BYTE emergencyCallState;			//紧急呼救
	BYTE sfVersionMonth;				//主控侧日期 月
	BYTE sfVersionDay;					//主控侧日期 日
	BYTE subModeVersion;				//子模式
	BYTE mainModeVersion;				//主模式

}userModeData;    //用户模式

typedef struct factoryModeData_t{
	functionMode functionModeData;
	BYTE resetPermissionFlag;			//瞬停复位许可
	BYTE stopMoment;					//瞬停状态
	BYTE mainBoardStatus;				//电源板暂停/启动状态
	BYTE sensorInit;					//传感器初始化
	BYTE wifiSwitch;					//wifi开关	0开-1关
	BYTE childLockState;				//儿童锁记忆标志
	BYTE pretreatmentState;				//预处理行程
	BYTE workOrder;						//工作命令
	BYTE timingRunningstate;			//时序运转状态
	BYTE machineType;               	//机种区分
	BYTE beepSwitchState;				//蜂鸣器设定
	BYTE simpleModelSettingSwitch;		//简易模式
	BYTE darkModeSettingSwitch;			//深色模式
	BYTE positivePressureSettings;		//正压设置
	UINT16 brightLightSetting;			//背光设置
	BYTE airPurifierSwitch;				//空气净化器开关
	BYTE windDirectAirPurifier;			//净化风向
	UINT16 autoAirVolAirPurifier;		//净化自动风量 		0-1-2-3-4
	BYTE addHumdAirPurifier;				//净化模式
	BYTE brightAirPurifier;				//净化亮度
	BYTE filterResetAirPurifier;		//净化滤网复位
	BYTE nanoexAirpurifier;				//净化nanoex
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
	UINT16 realTempState;				//当前温度
	UINT16 realHumdState;				//当前湿度
	UINT16 realCo2Content;				//当前CO2含量
	UINT16 realformaldehydeContent;		//当前甲醛含量
	UINT16 realTvocContent;				//当前TVOC含量
	UINT16 realPm25Content;				//当前PM25含量
	BYTE dataResetSetting;				//恢复出厂设置
	BYTE dormantState;					//休眠状态
	BYTE refrigerantReplace;			//制冷剂更换提醒
	BYTE autoShutDown;					//自动关机
	BYTE manualShutDown;				//手动关机
	BYTE dealShutDown;					//关机处理判断
	BYTE regularTime;					//定时时间
	BYTE timeRemaining;					//预约剩余时间
	BYTE HUError;						//H/U异常
	BYTE mainMachineMode;				//主辅机
	BYTE protectedModeState;			//保护模式状态
	BYTE airQuality;					//室内空气综合评价
	BYTE voiceSystemSwitch;				//语音系统
	BYTE emergencyCallState;			//紧急呼救
	BYTE subMode;						//子模式
	BYTE mainMode;						//主模式
	BYTE subModeSetting;  				//子模式设定
	BYTE mainModeSetting;				//主模式设定
	BYTE brakeState;					//制动标志
	BYTE wifiState;						//wifi检测状态
	BYTE voltageGainState;				//电压补正状态
	BYTE writeState;					//写入状态
	BYTE nanoeCheck;					//nanoe检查
	UINT16 PM25ADDF3;
	UINT16 PM25ADDF4;
	BYTE pm25SensorState;				//粉尘传感器状态
	UINT16 CO2ADDF1;
	UINT16 CO2ADDF2;
	UINT16 formaldehydeDF1;
	UINT16 formaldehydeDF2;
	BYTE formaldehydeSensorState;		//甲醛传感器状态
	BYTE formaldehydeSensorAZS;			//甲醛传感器自动调零
	UINT16 TVOCDF9;
	UINT16 TVOCDF10;
	UINT16 tempRegisterLowBits;
	UINT16 tempRegisterHighBits;
	UINT16 humdRegisterLowBits;
	UINT16 humdRegisterHighBits;
	BYTE softReset;
	BYTE outputDataRate;				//传输数据速率
	BYTE heaterCondition;				//加热器状态
	BYTE interruptPolarity;				//中断极性
	BYTE interruptMode;					//中断模式

}factoryModeData;  //工厂模式


typedef struct serverModeData_t{
	functionMode functionModeData;

	BYTE nanoeCheck;
	BYTE abnormalMemoryReadFlag;		//记忆异常
	BYTE abnormalMemoryWriteFlag;
	BYTE errorRecord1;
	BYTE errorRecord2;
	BYTE errorRecord3;
	BYTE errorLastRecord1;
	BYTE programE1;
	BYTE wifiSwitchE1;					//wifi开关	0开-1关
	BYTE childLockStateE1;				//儿童锁记忆标志
	BYTE pretreatmentStateE1;				//预处理行程
	BYTE beepSwitchStateE1;				//蜂鸣器设定
	BYTE simpleModelSettingSwitchE1;		//简易模式
	BYTE darkModeSettingSwitchE1;			//深色模式
	BYTE positivePressureSettingsE1;		//正压设置
	BYTE airPurifierSwitchE1;				//空气净化器开关
	BYTE windDirectAirPurifierE1;			//净化风向
	UINT16 autoAirVolAirPurifierE1;		//净化自动风量 		0-1-2-3-4
	BYTE addHumdAirPurifierE1;				//净化模式
	BYTE brightAirPurifierE1;				//净化亮度
	BYTE filterResetAirPurifierE1;		//净化滤网复位
	BYTE nanoexAirpurifierE1;				//净化nanoex
	BYTE heatExchangerSwitchE1;			//全热交换器开关
	UINT16 autoAirVolHeatExchangerE1;		//全热交换器自动风量
	BYTE modeHeatExchangerE1;				//全热交换器模式
	BYTE nanoexHeatExchangerE1;			//全热交换器nanoex
	BYTE airConditionSwitchE1;			//空调开关
	BYTE windDirectAirConditionE1;		//空调风向
	BYTE autoAirVolAirConditionE1;		//空调自动风量
	BYTE modeAirConditionE1;				//空调模式
	BYTE nanoexAirConditionE1;			//空调nanoex
	UINT16 tempAirConditionSettingE1;		//空调温度设定
	BYTE adjustHumdSwitchE1;				//调试器开关
	UINT16 windDirectAdjustHumdE1; 		//调湿器风向
	BYTE autoAirVolAdjustHumdE1;			//调湿器自动风量
	BYTE modeAdjustHumdE1;				//调湿器模式
	UINT16 humdAdjustHumdSettingE1;		//调湿器湿度设定
	BYTE yuBaSwitchE1;					//浴霸开关
	BYTE windDirectYuBaE1;				//浴霸风向
	BYTE heatingYuBaSettingE1;			//浴霸取暖设定
	BYTE heatDryYuBaSettingE1;			//浴霸热干燥设定
	BYTE coldDryYuBaSettingE1;			//浴霸凉干燥设定
	BYTE lightingYuBaSettingE1;			//浴霸照明设定
	BYTE nanoexYuBaE1;					//浴霸nanoex
	BYTE windTypeYuBaE1;					//浴霸风种
	BYTE airChangeYuBaSettingE1;			//浴霸换气
	UINT16 realTempStateE1;				//当前温度
	UINT16 realHumdStateE1;				//当前湿度
	UINT16 realCo2ContentE1;				//当前CO2含量
	UINT16 realFormaldehydeContentE1;		//当前甲醛含量
	UINT16 realTvocContentE1;				//当前TVOC含量
	UINT16 realPm25ContentE1;				//当前PM25含量


	BYTE errorLastRecord2;
	BYTE programE2;
	BYTE wifiSwitchE2;					//wifi开关	0开-1关
	BYTE childLockStateE2;				//儿童锁记忆标志
	BYTE pretreatmentStateE2;				//预处理行程
	BYTE beepSwitchStateE2;				//蜂鸣器设定
	BYTE simpleModelSettingSwitchE2;		//简易模式
	BYTE darkModeSettingSwitchE2;			//深色模式
	BYTE positivePressureSettingsE2;		//正压设置
	BYTE airPurifierSwitchE2;				//空气净化器开关
	BYTE windDirectAirPurifierE2;			//净化风向
	UINT16 autoAirVolAirPurifierE2;		//净化自动风量 		0-1-2-3-4
	BYTE addHumdAirPurifierE2;				//净化模式
	BYTE brightAirPurifierE2;				//净化亮度
	BYTE filterResetAirPurifierE2;		//净化滤网复位
	BYTE nanoexAirpurifierE2;				//净化nanoex
	BYTE heatExchangerSwitchE2;			//全热交换器开关
	UINT16 autoAirVolHeatExchangerE2;		//全热交换器自动风量
	BYTE modeHeatExchangerE2;				//全热交换器模式
	BYTE nanoexHeatExchangerE2;			//全热交换器nanoex
	BYTE airConditionSwitchE2;			//空调开关
	BYTE windDirectAirConditionE2;		//空调风向
	BYTE autoAirVolAirConditionE2;		//空调自动风量
	BYTE modeAirConditionE2;				//空调模式
	BYTE nanoexAirConditionE2;			//空调nanoex
	UINT16 tempAirConditionSettingE2;		//空调温度设定
	BYTE adjustHumdSwitchE2;				//调试器开关
	UINT16 windDirectAdjustHumdE2; 		//调湿器风向
	BYTE autoAirVolAdjustHumdE2;			//调湿器自动风量
	BYTE modeAdjustHumdE2;				//调湿器模式
	UINT16 humdAdjustHumdSettingE2;		//调湿器湿度设定
	BYTE yuBaSwitchE2;					//浴霸开关
	BYTE windDirectYuBaE2;				//浴霸风向
	BYTE heatingYuBaSettingE2;			//浴霸取暖设定
	BYTE heatDryYuBaSettingE2;			//浴霸热干燥设定
	BYTE coldDryYuBaSettingE2;			//浴霸凉干燥设定
	BYTE lightingYuBaSettingE2;			//浴霸照明设定
	BYTE nanoexYuBaE2;					//浴霸nanoex
	BYTE windTypeYuBaE2;					//浴霸风种
	BYTE airChangeYuBaSettingE2;			//浴霸换气
	UINT16 realTempStateE2;				//当前温度
	UINT16 realHumdStateE2;				//当前湿度
	UINT16 realCo2ContentE2;				//当前CO2含量
	UINT16 realFormaldehydeContentE2;		//当前甲醛含量
	UINT16 realTvocContentE2;				//当前TVOC含量
	UINT16 realPm25ContentE2;				//当前PM25含量

	BYTE errorLastRecord3;
	BYTE programE3;
	BYTE wifiSwitchE3;					//wifi开关	0开-1关
	BYTE childLockStateE3;				//儿童锁记忆标志
	BYTE pretreatmentStateE3;				//预处理行程
	BYTE beepSwitchStateE3;				//蜂鸣器设定
	BYTE simpleModelSettingSwitchE3;		//简易模式
	BYTE darkModeSettingSwitchE3;			//深色模式
	BYTE positivePressureSettingsE3;		//正压设置
	BYTE airPurifierSwitchE3;				//空气净化器开关
	BYTE windDirectAirPurifierE3;			//净化风向
	UINT16 autoAirVolAirPurifierE3;		//净化自动风量 		0-1-2-3-4
	BYTE addHumdAirPurifierE3;				//净化模式
	BYTE brightAirPurifierE3;				//净化亮度
	BYTE filterResetAirPurifierE3;		//净化滤网复位
	BYTE nanoexAirpurifierE3;				//净化nanoex
	BYTE heatExchangerSwitchE3;			//全热交换器开关
	UINT16 autoAirVolHeatExchangerE3;		//全热交换器自动风量
	BYTE modeHeatExchangerE3;				//全热交换器模式
	BYTE nanoexHeatExchangerE3;			//全热交换器nanoex
	BYTE airConditionSwitchE3;			//空调开关
	BYTE windDirectAirConditionE3;		//空调风向
	BYTE autoAirVolAirConditionE3;		//空调自动风量
	BYTE modeAirConditionE3;				//空调模式
	BYTE nanoexAirConditionE3;			//空调nanoex
	UINT16 tempAirConditionSettingE3;		//空调温度设定
	BYTE adjustHumdSwitchE3;				//调试器开关
	UINT16 windDirectAdjustHumdE3; 		//调湿器风向
	BYTE autoAirVolAdjustHumdE3;			//调湿器自动风量
	BYTE modeAdjustHumdE3;				//调湿器模式
	UINT16 humdAdjustHumdSettingE3;		//调湿器湿度设定
	BYTE yuBaSwitchE3;					//浴霸开关
	BYTE windDirectYuBaE3;				//浴霸风向
	BYTE heatingYuBaSettingE3;			//浴霸取暖设定
	BYTE heatDryYuBaSettingE3;			//浴霸热干燥设定
	BYTE coldDryYuBaSettingE3;			//浴霸凉干燥设定
	BYTE lightingYuBaSettingE3;			//浴霸照明设定
	BYTE nanoexYuBaE3;					//浴霸nanoex
	BYTE windTypeYuBaE3;					//浴霸风种
	BYTE airChangeYuBaSettingE3;			//浴霸换气
	UINT16 realTempStateE3;				//当前温度
	UINT16 realHumdStateE3;				//当前湿度
	UINT16 realCo2ContentE3;				//当前CO2含量
	UINT16 realFormaldehydeContentE3;		//当前甲醛含量
	UINT16 realTvocContentE3;				//当前TVOC含量
	UINT16 realPm25ContentE3;				//当前PM25含量

}serverModeData;    //服务模式



/*8*/

typedef union{
	userModeData userData;
	factoryModeData factoryData;
	serverModeData serverData;
}uartReceiveData;

enum {
	MCU_PROTOCOL_TYPE_VERSION,
	MCU_PROTOCOL_TYPE_TEMP,
	MCU_PROTOCOL_TYPE_SWITCH_TEST_MODE,
	MCU_PROTOCOL_TYPE_SWITCH,
	MCU_PROTOCOL_TYPE_POWER_OFF
};

typedef union{
	int mode;
	uartReceiveData receData;
}SensorNodeSetData_t;

/*9*/
typedef union{
	userModeData userData;


}SensorNodeGetData_t;

/*10*/
typedef union{
	userModeData userData;


}SensorGetAllData_t;

/*11*/
typedef union{
	userModeData userData;
	factoryModeData factoryData;
	serverModeData serverData;
}SensorNodeGetRawData_t;

typedef struct {
	int mode;
	uartReceiveData recvData;
} SProtocolData;

typedef struct {
	int type;
	void *data;
}McuProtocolData;

typedef void (*OnMcuProtocolDataUpdateFun)(const McuProtocolData &data);
typedef void (*OnProtocolDataUpdateFun)(const SProtocolData &data);
void registerProtocolDataUpdateListener(OnProtocolDataUpdateFun pListener);
void unregisterProtocolDataUpdateListener(OnProtocolDataUpdateFun pListener);
void registerMcuProtocolDataUpdateListener(OnMcuProtocolDataUpdateFun pListener);

SProtocolData& getProtocolData();

#endif /* UART_PROTOCOLPARSER_H_ */
