/*
 * ProtocolParser.cpp
 *
 *  Created on: Sep 7, 2017
 *      Author: guoxs
 */
#include "app/Activity.h"
#include "entry/EasyUIContext.h"
#include <vector>
#include <system/Mutex.h>
#include "CommDef.h"
#include "uart/ProtocolParser.h"
#include "uart/UartContext.h"
#include "utils/Log.h"
#include "uart/ProtocolContinueSend.h"
//#include "util/MyMediaPlayer.h"

static Mutex sLock , mLock;
static std::vector<OnProtocolDataUpdateFun> sProtocolDataUpdateListenerList;
static std::vector<OnMcuProtocolDataUpdateFun> mcuProtocolDataUpdateListenerList;

/**
 * 注册一个串口监听器
 * 参数：pListener
 * 			监听器
 *
 * 返回值：无
 *
 */

void registerProtocolDataUpdateListener(OnProtocolDataUpdateFun pListener) {
	Mutex::Autolock _l(sLock);
//	LOGD("registerProtocolDataUpdateListener\n");
	if (pListener != NULL) {
		sProtocolDataUpdateListenerList.push_back(pListener);
	}
}

void registerMcuProtocolDataUpdateListener(OnMcuProtocolDataUpdateFun pListener) {
	Mutex::Autolock _l(sLock);

	if (pListener != NULL) {
		LOGD("registerMcuProtocolDataUpdateListener\n");
		mcuProtocolDataUpdateListenerList.push_back(pListener);
	}
}

/**
 * 注销一个串口监听器
 * 参数：pListener
 * 			监听器
 *
 * 返回值：无
 *
 */
void unregisterProtocolDataUpdateListener(OnProtocolDataUpdateFun pListener) {
	Mutex::Autolock _l(sLock);
	LOGD("unregisterProtocolDataUpdateListener\n");
	if (pListener != NULL) {
		std::vector<OnProtocolDataUpdateFun>::iterator iter = sProtocolDataUpdateListenerList.begin();
		for (; iter != sProtocolDataUpdateListenerList.end(); iter++) {
			if ((*iter) == pListener) {
				sProtocolDataUpdateListenerList.erase(iter);
				return;
			}
		}
	}
}

void unregisterMcuProtocolDataUpdateListener(OnMcuProtocolDataUpdateFun pListener) {
	Mutex::Autolock _l(sLock);
	LOGD("unregisterMcuProtocolDataUpdateListener\n");
	if (pListener != NULL) {
		std::vector<OnMcuProtocolDataUpdateFun>::iterator iter = mcuProtocolDataUpdateListenerList.begin();
		for (; iter != mcuProtocolDataUpdateListenerList.end(); iter++) {
			if ((*iter) == pListener) {
				mcuProtocolDataUpdateListenerList.erase(iter);
				return;
			}
		}
	}
}

/**
 * 广播一个完整的数据包
 * 参数：data
 * 			被广播的数据
 *
 * 返回值：无
 *
 */

static void notifyProtocolDataUpdate(const SProtocolData &data) {
	Mutex::Autolock _l(sLock);
	std::vector<OnProtocolDataUpdateFun>::const_iterator iter = sProtocolDataUpdateListenerList.begin();
	for (; iter != sProtocolDataUpdateListenerList.end(); iter++) {
		(*iter)(data);
	}
}

static SProtocolData sProtocolData;

SProtocolData& getProtocolData() {
	return sProtocolData;
}

static void notifyMcuProtocolDataUpdate(const McuProtocolData &data) {
	Mutex::Autolock _l(sLock);
//	LOGD("mcu protocol listener %d\n" , mcuProtocolDataUpdateListenerList.size());
	std::vector<OnMcuProtocolDataUpdateFun>::const_iterator iter = mcuProtocolDataUpdateListenerList.begin();
	for (; iter != mcuProtocolDataUpdateListenerList.end(); iter++) {
		(*iter)(data);
	}
}

static SProtocolData sProtocolDatas = {0};
static McuProtocolData mProtocolData;
//SProtocolData& getProtocolData() {
//	return sProtocolData;
//}

/*
 * 获取CRC16检验
 * */
UINT16 getCRC16(const BYTE *pData , int len , UINT16 initValue) {
	unsigned short wCRCin = initValue;
	unsigned short wCPoly = 0x1021;

	while (len--)
	{
		wCRCin ^= *(pData++) << 8;
		for(int i = 0;i < 8;i++)
		{
			if(wCRCin & 0x8000)
				wCRCin = (wCRCin << 1) ^ wCPoly;
			else
				wCRCin = wCRCin << 1;
		}
	}
	return (wCRCin);
}


/**
 * 处理用户模式数据
 * 参数：pData
 * 			待处理数据
 *     len
 *          数据长度
 *
 * 返回值：无
 *
 */
static void procUserData(const BYTE *pData , UINT len) {
	if(pData[11] & 0x80) {
		sProtocolData.recvData.userData.resetPermissionFlag = 1;
	} else {
		sProtocolData.recvData.userData.resetPermissionFlag = 0;
	}


	if((pData[11] & 0x70) == 0x20) {
		sProtocolData.recvData.userData.stopMoment = 1;
	} else if((pData[11] & 0x70) == 0x50) {
		sProtocolData.recvData.userData.stopMoment = 2;
	} else {
		sProtocolData.recvData.userData.stopMoment = 0;
	}

	if(pData[11] & 0x08) {
		sProtocolData.recvData.userData.mainBoardStatus = 1;
	} else {
		sProtocolData.recvData.userData.mainBoardStatus = 0;
	}

	sProtocolData.recvData.userData.sensorInit = (pData[11] & 0x04)? 1:0;
	sProtocolData.recvData.userData.workOrder = pData[11] & 0x03;
	sProtocolData.recvData.userData.timingRunningstate = (pData[12] & 0x70) >> 4;
	sProtocolData.recvData.userData.pretreatmentState = (pData[12] & 0x08)? 1:0;
	sProtocolData.recvData.userData.beepSwitchState = (pData[12] & 0x01)? 1:0;
	sProtocolData.recvData.userData.childLockState = (pData[13] & 0x40)? 1:0;
	sProtocolData.recvData.userData.wifiSwitch = (pData[13] & 0x10)? 1:0;
	sProtocolData.recvData.userData.simpleModelSettingSwitch = (pData[13] & 0x08)? 1:0;
	sProtocolData.recvData.userData.darkModeSettingSwitch = (pData[13] & 0x04)? 1:0;
	sProtocolData.recvData.userData.positivePressureSettings = pData[13] & 0x30;
	sProtocolData.recvData.userData.brightLightSetting = pData[14] & 0xf0;
	sProtocolData.recvData.userData.autoAirVolAirPurifier = pData[15] & 0xc0;
	sProtocolData.recvData.userData.airPurifierSwitch = (pData[15] & 0x04)? 1:0;
	sProtocolData.recvData.userData.filterResetAirPurifier = (pData[15] & 0x02)? 1:0;
	sProtocolData.recvData.userData.nanoexAirpurifier = (pData[15] & 0x01)? 1:0;
	sProtocolData.recvData.userData.brightAirPurifier = pData[16] & 0xf0;
	sProtocolData.recvData.userData.addHumdAirPurifier = pData[16] & 0x0f;
	sProtocolData.recvData.userData.windDirectAirPurifier = pData[17] & 0xf0;
	sProtocolData.recvData.userData.autoAirVolHeatExchanger =(pData[18] & 0x20) >> 4;
	sProtocolData.recvData.userData.modeHeatExchanger = (pData[18] & 0x80) >> 2;
	sProtocolData.recvData.userData.nanoexHeatExchanger = (pData[18] & 0x40) ? 1:0;
	sProtocolData.recvData.userData.heatExchangerSwitch = (pData[18] & 0x20)? 1:0;
	sProtocolData.recvData.userData.airConditionSwitch = (pData[19] & 0x80)? 1:0;
	sProtocolData.recvData.userData.autoAirVolAirCondition = (pData[19] & 0x10) >> 4;
	sProtocolData.recvData.userData.windDirectAirCondition = (pData[19] & 0x04) >> 2;
	sProtocolData.recvData.userData.modeAirCondition = pData[19] & 0x03;
	sProtocolData.recvData.userData.nanoexAirCondition = (pData[20] & 0x80)? 1:0;
	sProtocolData.recvData.userData.tempAirConditionSetting = (pData[20] & 0x01) >> 4;
	sProtocolData.recvData.userData.adjustHumdSwitch = (pData[21] & 0x80)? 1: 0;
	sProtocolData.recvData.userData.autoAirVolAdjustHumd = (pData[21] & 0x10) >> 4;
	sProtocolData.recvData.userData.windDirectAdjustHumd = pData[21] & 0x0f;
	sProtocolData.recvData.userData.modeAdjustHumd = (pData[22] & 0x40 ) >> 2;
	sProtocolData.recvData.userData.humdAdjustHumdSetting = pData[22];
	sProtocolData.recvData.userData.yuBaSwitch = (pData[23] & 0x80)? 1:0;
	sProtocolData.recvData.userData.heatingYuBaSetting = (pData[23] & 0x60);
	sProtocolData.recvData.userData.windDirectYuBa = (pData[23] & 0x10)? 1:0;
	sProtocolData.recvData.userData.heatDryYuBaSetting = (pData[23] & 0x04) >> 2;
	sProtocolData.recvData.userData.lightingYuBaSetting = (pData[23] & 0x01) >> 2;
	sProtocolData.recvData.userData.nanoexYuBa = (pData[24] & 0x80)? 1:0;
	sProtocolData.recvData.userData.windTypeYuBa = (pData[24] & 0x40)? 1:0;
	sProtocolData.recvData.userData.coldDryYuBaSetting = (pData[24] & 0x10) >> 2 ;
	sProtocolData.recvData.userData.airChangeYuBaSetting = (pData[24] & 0x04) >> 2;
	sProtocolData.recvData.userData.realTempState = pData[32];
	sProtocolData.recvData.userData.realHumdState = pData[33];
	sProtocolData.recvData.userData.realCo2Content = pData[34];
	sProtocolData.recvData.userData.realformaldehydeContent = pData[35] & 0xf0;
	sProtocolData.recvData.userData.realTvocContent = pData[35] & 0x0f;
	sProtocolData.recvData.userData.realPm25Content = pData[36] ;
	sProtocolData.recvData.userData.dataResetSetting =(pData[37] & 0x80) ?1:0;
	sProtocolData.recvData.userData.dormantState = (pData[37] & 0x40)? 1:0;
	sProtocolData.recvData.userData.refrigerantReplace = (pData[37] & 0x08) >> 4;
	sProtocolData.recvData.userData.autoShutDown = pData[37] & 0x04;
	sProtocolData.recvData.userData.manualShutDown = pData[37] & 0x02;
	sProtocolData.recvData.userData.dealShutDown = (pData[37] & 0x01)? 1:0;
	sProtocolData.recvData.userData.regularTime = pData[38];
	sProtocolData.recvData.userData.timeRemaining = pData[39];
	sProtocolData.recvData.userData.mainMachineMode = (pData[40] & 0x80)? 1:0;
	sProtocolData.recvData.userData.protectedModeState = (pData[40] & 0x40)? 1:0;
	sProtocolData.recvData.userData.voiceSystemSwitch = (pData[40] & 0x10)? 1:0;
	sProtocolData.recvData.userData.airQuality = (pData[40] & 0x02) >> 4;
	sProtocolData.recvData.userData.emergencyCallState = (pData[40] & 0x01)? 1:0;
	sProtocolData.recvData.userData.HUError = pData[41];
	if(pData[41]) {
			LOGD("error %x\n",pData[41]);
		}
	sProtocolData.recvData.userData.mainModeVersion = pData[44] & 0xf0;
	sProtocolData.recvData.userData.subModeVersion = pData[44] & 0x0f;
	sProtocolData.recvData.userData.sfVersionMonth = pData[45] ;
	sProtocolData.recvData.userData.sfVersionDay = pData[46];



	notifyProtocolDataUpdate(sProtocolData);
}

/**
 * 处理服务模式数据
 * 参数：pData
 * 			待处理数据
 *     len
 *          数据长度
 *
 * 返回值：无
 *
 */
static void procServerData(const BYTE *pData , UINT len) {

	if(pData[11] & 0x80) {
		sProtocolData.recvData.userData.resetPermissionFlag = 1;
	} else {
		sProtocolData.recvData.userData.resetPermissionFlag = 0;
	}


	if((pData[11] & 0x70) == 0x20) {
		sProtocolData.recvData.userData.stopMoment = 1;
	} else if((pData[11] & 0x70) == 0x50) {
		sProtocolData.recvData.userData.stopMoment = 2;
	} else {
		sProtocolData.recvData.userData.stopMoment = 0;
	}

	if(pData[11] & 0x08) {
		sProtocolData.recvData.userData.mainBoardStatus = 1;
	} else {
		sProtocolData.recvData.userData.mainBoardStatus = 0;
	}

	sProtocolData.recvData.userData.sensorInit = (pData[11] & 0x04)? 1:0;
	sProtocolData.recvData.userData.workOrder = pData[11] & 0x03;
	sProtocolData.recvData.userData.timingRunningstate = (pData[12] & 0x70) >> 4;
	sProtocolData.recvData.userData.pretreatmentState = (pData[12] & 0x08)? 1:0;
	sProtocolData.recvData.userData.beepSwitchState = (pData[12] & 0x01)? 1:0;
	sProtocolData.recvData.userData.childLockState = (pData[13] & 0x40)? 1:0;
	sProtocolData.recvData.userData.wifiSwitch = (pData[13] & 0x10)? 1:0;
	sProtocolData.recvData.userData.simpleModelSettingSwitch = (pData[13] & 0x08)? 1:0;
	sProtocolData.recvData.userData.darkModeSettingSwitch = (pData[13] & 0x04)? 1:0;
	sProtocolData.recvData.userData.positivePressureSettings = pData[13] & 0x30;
	sProtocolData.recvData.userData.brightLightSetting = pData[14] & 0xf0;
	sProtocolData.recvData.userData.autoAirVolAirPurifier = pData[15] & 0xc0;
	sProtocolData.recvData.userData.airPurifierSwitch = (pData[15] & 0x04)? 1:0;
	sProtocolData.recvData.userData.filterResetAirPurifier = (pData[15] & 0x02)? 1:0;
	sProtocolData.recvData.userData.nanoexAirpurifier = (pData[15] & 0x01)? 1:0;
	sProtocolData.recvData.userData.brightAirPurifier = pData[16] & 0xf0;
	sProtocolData.recvData.userData.addHumdAirPurifier = pData[16] & 0x0f;
	sProtocolData.recvData.userData.windDirectAirPurifier = pData[17] & 0xf0;
	sProtocolData.recvData.userData.autoAirVolHeatExchanger =(pData[18] & 0x20) >> 4;
	sProtocolData.recvData.userData.modeHeatExchanger = (pData[18] & 0x80) >> 2;
	sProtocolData.recvData.userData.nanoexHeatExchanger = (pData[18] & 0x40) ? 1:0;
	sProtocolData.recvData.userData.heatExchangerSwitch = (pData[18] & 0x20)? 1:0;
	sProtocolData.recvData.userData.airConditionSwitch = (pData[19] & 0x80)? 1:0;
	sProtocolData.recvData.userData.autoAirVolAirCondition = (pData[19] & 0x10) >> 4;
	sProtocolData.recvData.userData.windDirectAirCondition = (pData[19] & 0x04) >> 2;
	sProtocolData.recvData.userData.modeAirCondition = pData[19] & 0x03;
	sProtocolData.recvData.userData.nanoexAirCondition = (pData[20] & 0x80)? 1:0;
	sProtocolData.recvData.userData.tempAirConditionSetting = (pData[20] & 0x01) >> 4;
	sProtocolData.recvData.userData.adjustHumdSwitch = (pData[21] & 0x80)? 1: 0;
	sProtocolData.recvData.userData.autoAirVolAdjustHumd = (pData[21] & 0x10) >> 4;
	sProtocolData.recvData.userData.windDirectAdjustHumd = pData[21] & 0x0f;
	sProtocolData.recvData.userData.modeAdjustHumd = (pData[22] & 0x40 ) >> 2;
	sProtocolData.recvData.userData.humdAdjustHumdSetting = pData[22];
	sProtocolData.recvData.userData.yuBaSwitch = (pData[23] & 0x80)? 1:0;
	sProtocolData.recvData.userData.heatingYuBaSetting = (pData[23] & 0x60);
	sProtocolData.recvData.userData.windDirectYuBa = (pData[23] & 0x10)? 1:0;
	sProtocolData.recvData.userData.heatDryYuBaSetting = (pData[23] & 0x04) >> 2;
	sProtocolData.recvData.userData.lightingYuBaSetting = (pData[23] & 0x01) >> 2;
	sProtocolData.recvData.userData.nanoexYuBa = (pData[24] & 0x80)? 1:0;
	sProtocolData.recvData.userData.windTypeYuBa = (pData[24] & 0x40)? 1:0;
	sProtocolData.recvData.userData.coldDryYuBaSetting = (pData[24] & 0x10) >> 2 ;
	sProtocolData.recvData.userData.airChangeYuBaSetting = (pData[24] & 0x04) >> 2;
	sProtocolData.recvData.userData.realTempState = pData[32];
	sProtocolData.recvData.userData.realHumdState = pData[33];
	sProtocolData.recvData.userData.realCo2Content = pData[34];
	sProtocolData.recvData.userData.realformaldehydeContent = pData[35] & 0xf0;
	sProtocolData.recvData.userData.realTvocContent = pData[35] & 0x0f;
	sProtocolData.recvData.userData.realPm25Content = pData[36] ;
	sProtocolData.recvData.userData.dataResetSetting =(pData[37] & 0x80) ?1:0;
	sProtocolData.recvData.userData.dormantState = (pData[37] & 0x40)? 1:0;
	sProtocolData.recvData.userData.refrigerantReplace = (pData[37] & 0x08) >> 4;
	sProtocolData.recvData.userData.autoShutDown = pData[37] & 0x04;
	sProtocolData.recvData.userData.manualShutDown = pData[37] & 0x02;
	sProtocolData.recvData.userData.dealShutDown = (pData[37] & 0x01)? 1:0;
	sProtocolData.recvData.userData.regularTime = pData[38];
	sProtocolData.recvData.userData.timeRemaining = pData[39];
	sProtocolData.recvData.userData.mainMachineMode = (pData[40] & 0x80)? 1:0;
	sProtocolData.recvData.userData.protectedModeState = (pData[40] & 0x40)? 1:0;
	sProtocolData.recvData.userData.voiceSystemSwitch = (pData[40] & 0x10)? 1:0;
	sProtocolData.recvData.userData.airQuality = (pData[40] & 0x02) >> 4;
	sProtocolData.recvData.userData.emergencyCallState = (pData[40] & 0x01)? 1:0;
	sProtocolData.recvData.userData.HUError = pData[41];

	if(pData[41]) {
			LOGD("error %x\n",pData[41]);
	}

	sProtocolData.recvData.serverData.nanoeCheck = (pData[42] & 0x40) >> 2;
	sProtocolData.recvData.serverData.abnormalMemoryReadFlag = (pData[42] & 0x08)? 1:0;
	sProtocolData.recvData.serverData.abnormalMemoryWriteFlag = (pData[42] & 0x04)? 1:0;
	sProtocolData.recvData.serverData.errorRecord1 = pData[43];
	sProtocolData.recvData.serverData.errorRecord2 = pData[44];
	sProtocolData.recvData.serverData.errorRecord3 = pData[45];

	sProtocolData.recvData.serverData.errorLastRecord1 = pData[46];
	sProtocolData.recvData.serverData.pretreatmentStateE1 = (pData[47] & 0x80)? 1:0;
	sProtocolData.recvData.serverData.beepSwitchStateE1 = (pData[47] & 0x40)? 1:0;
	sProtocolData.recvData.serverData.childLockStateE1 = (pData[47] & 0x20)? 1:0;
	sProtocolData.recvData.serverData.wifiSwitchE1 = (pData[47] & 0x10)? 1:0;
	sProtocolData.recvData.serverData.simpleModelSettingSwitchE1 = (pData[47] & 0x08)? 1:0;
	sProtocolData.recvData.serverData.darkModeSettingSwitchE1 = (pData[47] & 0x04)? 1:0;
	sProtocolData.recvData.serverData.positivePressureSettingsE1 = (pData[47] & 0x03);
	sProtocolData.recvData.serverData.autoAirVolAirPurifierE1 = (pData[48] & 0x10) >> 4;
	sProtocolData.recvData.serverData.airPurifierSwitchE1 = (pData[48] & 0x04)? 1:0;
	sProtocolData.recvData.serverData.filterResetAirPurifierE1 = (pData[48] & 0x02)? 1:0;
	sProtocolData.recvData.serverData.nanoexAirpurifierE1 = (pData[48] & 0x01)? 1:0;
	sProtocolData.recvData.serverData.brightAirPurifierE1 = (pData[49] & 0x10) >> 4;
	sProtocolData.recvData.serverData.addHumdAirPurifierE1 = (pData[49] & 0x01) >> 4;
	sProtocolData.recvData.serverData.windDirectAirPurifierE1 = (pData[50] & 0x10) >>4;
	sProtocolData.recvData.serverData.autoAirVolHeatExchangerE1 = (pData[51] & 0x10) >> 4;
	sProtocolData.recvData.serverData.modeHeatExchangerE1 = (pData[51] & 0x04) >> 2;
	sProtocolData.recvData.serverData.nanoexHeatExchangerE1 = (pData[51] & 0x02)? 1:0;
	sProtocolData.recvData.serverData.heatExchangerSwitchE1 = (pData[51] & 0x01)? 1:0;
	sProtocolData.recvData.serverData.airConditionSwitchE1 = (pData[52]& 0x80)? 1:0;
	sProtocolData.recvData.serverData.autoAirVolAirConditionE1 = (pData[52] & 0x10) >> 4;
	sProtocolData.recvData.serverData.windDirectAirConditionE1 = (pData[52] & 0x04) >> 2;
	sProtocolData.recvData.serverData.modeAirConditionE1 = (pData[52] & 0x01) >> 2;
	sProtocolData.recvData.serverData.nanoexAirConditionE1 = (pData[53] & 0x80)? 1:0;
	sProtocolData.recvData.serverData.tempAirConditionSettingE1 = pData[53];
	sProtocolData.recvData.serverData.adjustHumdSwitchE1 = (pData[54] & 0x80)? 1:0;
	sProtocolData.recvData.serverData.autoAirVolAdjustHumdE1 = (pData[54] & 0x10) >> 4;
	sProtocolData.recvData.serverData.windDirectAdjustHumdE1 = (pData[54] & 0x0f);
	sProtocolData.recvData.serverData.modeAdjustHumdE1 = (pData[55] & 0x40) >> 2;
	sProtocolData.recvData.serverData.humdAdjustHumdSettingE1 = pData[55];
	sProtocolData.recvData.serverData.yuBaSwitchE1 = (pData[56] & 0x80)? 1:0;
	sProtocolData.recvData.serverData.heatingYuBaSettingE1 = (pData[56] & 0x20) >> 2;
	sProtocolData.recvData.serverData.windDirectYuBaE1 = (pData[56] & 0x10)? 1:0;
	sProtocolData.recvData.serverData.heatDryYuBaSettingE1 = (pData[56] & 0x04) >> 2;
	sProtocolData.recvData.serverData.lightingYuBaSettingE1 = (pData[56] & 0x01) >> 2;
	sProtocolData.recvData.serverData.nanoexYuBaE1 = (pData[57] & 0x80)? 1:0;
	sProtocolData.recvData.serverData.windTypeYuBaE1 = (pData[57] & 0x40)? 1:0;
	sProtocolData.recvData.serverData.coldDryYuBaSettingE1 = (pData[57] & 0x10) >> 2;
	sProtocolData.recvData.serverData.airChangeYuBaSettingE1 = (pData[57] & 0x04) >> 2;
	sProtocolData.recvData.serverData.realTempStateE1 = pData[58];
	sProtocolData.recvData.serverData.realHumdStateE1 = pData[59];
	sProtocolData.recvData.serverData.realCo2ContentE1 = pData[60];
	sProtocolData.recvData.serverData.realFormaldehydeContentE1 = pData[61] & 0xf0;
	sProtocolData.recvData.serverData.realTvocContentE1 = pData[61] & 0x0f;
	sProtocolData.recvData.serverData.realPm25ContentE1 = pData[62] ;

	sProtocolData.recvData.serverData.errorLastRecord2 = pData[63];
	sProtocolData.recvData.serverData.pretreatmentStateE2 = (pData[64] & 0x80)? 1:0;
	sProtocolData.recvData.serverData.beepSwitchStateE2 = (pData[64] & 0x40)? 1:0;
	sProtocolData.recvData.serverData.childLockStateE2 = (pData[64] & 0x20)? 1:0;
	sProtocolData.recvData.serverData.wifiSwitchE2 = (pData[64] & 0x10)? 1:0;
	sProtocolData.recvData.serverData.simpleModelSettingSwitchE2 = (pData[64] & 0x08)? 1:0;
	sProtocolData.recvData.serverData.darkModeSettingSwitchE2 = (pData[64] & 0x04)? 1:0;
	sProtocolData.recvData.serverData.positivePressureSettingsE2 = (pData[64] & 0x03);
	sProtocolData.recvData.serverData.autoAirVolAirPurifierE2 = (pData[65] & 0x10) >> 4;
	sProtocolData.recvData.serverData.airPurifierSwitchE2 = (pData[65] & 0x04)? 1:0;
	sProtocolData.recvData.serverData.filterResetAirPurifierE2 = (pData[65] & 0x02)? 1:0;
	sProtocolData.recvData.serverData.nanoexAirpurifierE2 = (pData[65] & 0x01)? 1:0;
	sProtocolData.recvData.serverData.brightAirPurifierE2 = (pData[66] & 0x10) >> 4;
	sProtocolData.recvData.serverData.addHumdAirPurifierE2 = (pData[66] & 0x01) >> 4;
	sProtocolData.recvData.serverData.windDirectAirPurifierE2 = (pData[67] & 0x10) >>4;
	sProtocolData.recvData.serverData.autoAirVolHeatExchangerE2 = (pData[68] & 0x10) >> 4;
	sProtocolData.recvData.serverData.modeHeatExchangerE2 = (pData[68] & 0x04) >> 2;
	sProtocolData.recvData.serverData.nanoexHeatExchangerE2 = (pData[68] & 0x02)? 1:0;
	sProtocolData.recvData.serverData.heatExchangerSwitchE2 = (pData[68] & 0x01)? 1:0;
	sProtocolData.recvData.serverData.airConditionSwitchE2 = (pData[69]& 0x80)? 1:0;
	sProtocolData.recvData.serverData.autoAirVolAirConditionE2 = (pData[69] & 0x10) >> 4;
	sProtocolData.recvData.serverData.windDirectAirConditionE2 = (pData[69] & 0x04) >> 2;
	sProtocolData.recvData.serverData.modeAirConditionE2 = (pData[69] & 0x01) >> 2;
	sProtocolData.recvData.serverData.nanoexAirConditionE2 = (pData[70] & 0x80)? 1:0;
	sProtocolData.recvData.serverData.tempAirConditionSettingE2 = pData[70];
	sProtocolData.recvData.serverData.adjustHumdSwitchE2 = (pData[71] & 0x80)? 1:0;
	sProtocolData.recvData.serverData.autoAirVolAdjustHumdE2 = (pData[71] & 0x10) >> 4;
	sProtocolData.recvData.serverData.windDirectAdjustHumdE2 = (pData[71] & 0x0f);
	sProtocolData.recvData.serverData.modeAdjustHumdE2 = (pData[72] & 0x40) >> 2;
	sProtocolData.recvData.serverData.humdAdjustHumdSettingE2 = pData[72];
	sProtocolData.recvData.serverData.yuBaSwitchE2 = (pData[73] & 0x80)? 1:0;
	sProtocolData.recvData.serverData.heatingYuBaSettingE2 = (pData[73] & 0x20) >> 2;
	sProtocolData.recvData.serverData.windDirectYuBaE2 = (pData[73] & 0x10)? 1:0;
	sProtocolData.recvData.serverData.heatDryYuBaSettingE2 = (pData[73] & 0x04) >> 2;
	sProtocolData.recvData.serverData.lightingYuBaSettingE2 = (pData[73] & 0x01) >> 2;
	sProtocolData.recvData.serverData.nanoexYuBaE2 = (pData[74] & 0x80)? 1:0;
	sProtocolData.recvData.serverData.windTypeYuBaE2 = (pData[74] & 0x40)? 1:0;
	sProtocolData.recvData.serverData.coldDryYuBaSettingE2 = (pData[74] & 0x10) >> 2;
	sProtocolData.recvData.serverData.airChangeYuBaSettingE2 = (pData[74] & 0x04) >> 2;
	sProtocolData.recvData.serverData.realTempStateE2 = pData[75];
	sProtocolData.recvData.serverData.realHumdStateE2 = pData[76];
	sProtocolData.recvData.serverData.realCo2ContentE2 = pData[77];
	sProtocolData.recvData.serverData.realFormaldehydeContentE2 = pData[78] & 0xf0;
	sProtocolData.recvData.serverData.realTvocContentE2 = pData[78] & 0x0f;
	sProtocolData.recvData.serverData.realPm25ContentE2 = pData[79] ;
	sProtocolData.recvData.serverData.errorLastRecord3 = pData[80];


	sProtocolData.recvData.serverData.pretreatmentStateE1 = (pData[81] & 0x80)? 1:0;
	sProtocolData.recvData.serverData.beepSwitchStateE1 = (pData[81] & 0x40)? 1:0;
	sProtocolData.recvData.serverData.childLockStateE1 = (pData[81] & 0x20)? 1:0;
	sProtocolData.recvData.serverData.wifiSwitchE1 = (pData[81] & 0x10)? 1:0;
	sProtocolData.recvData.serverData.simpleModelSettingSwitchE1 = (pData[81] & 0x08)? 1:0;
	sProtocolData.recvData.serverData.darkModeSettingSwitchE1 = (pData[81] & 0x04)? 1:0;
	sProtocolData.recvData.serverData.positivePressureSettingsE1 = (pData[81] & 0x03);
	sProtocolData.recvData.serverData.autoAirVolAirPurifierE1 = (pData[82] & 0x10) >> 4;
	sProtocolData.recvData.serverData.airPurifierSwitchE1 = (pData[82] & 0x04)? 1:0;
	sProtocolData.recvData.serverData.filterResetAirPurifierE1 = (pData[82] & 0x02)? 1:0;
	sProtocolData.recvData.serverData.nanoexAirpurifierE1 = (pData[82] & 0x01)? 1:0;
	sProtocolData.recvData.serverData.brightAirPurifierE1 = (pData[83] & 0x10) >> 4;
	sProtocolData.recvData.serverData.addHumdAirPurifierE1 = (pData[83] & 0x01) >> 4;
	sProtocolData.recvData.serverData.windDirectAirPurifierE1 = (pData[84] & 0x10) >>4;
	sProtocolData.recvData.serverData.autoAirVolHeatExchangerE1 = (pData[85] & 0x10) >> 4;
	sProtocolData.recvData.serverData.modeHeatExchangerE1 = (pData[85] & 0x04) >> 2;
	sProtocolData.recvData.serverData.nanoexHeatExchangerE1 = (pData[85] & 0x02)? 1:0;
	sProtocolData.recvData.serverData.heatExchangerSwitchE1 = (pData[85] & 0x01)? 1:0;
	sProtocolData.recvData.serverData.airConditionSwitchE1 = (pData[86]& 0x80)? 1:0;
	sProtocolData.recvData.serverData.autoAirVolAirConditionE1 = (pData[86] & 0x10) >> 4;
	sProtocolData.recvData.serverData.windDirectAirConditionE1 = (pData[86] & 0x04) >> 2;
	sProtocolData.recvData.serverData.modeAirConditionE1 = (pData[86] & 0x01) >> 2;
	sProtocolData.recvData.serverData.nanoexAirConditionE1 = (pData[87] & 0x80)? 1:0;
	sProtocolData.recvData.serverData.tempAirConditionSettingE1 = pData[87];
	sProtocolData.recvData.serverData.adjustHumdSwitchE1 = (pData[88] & 0x80)? 1:0;
	sProtocolData.recvData.serverData.autoAirVolAdjustHumdE1 = (pData[88] & 0x10) >> 4;
	sProtocolData.recvData.serverData.windDirectAdjustHumdE1 = (pData[88] & 0x0f);
	sProtocolData.recvData.serverData.modeAdjustHumdE1 = (pData[89] & 0x40) >> 2;
	sProtocolData.recvData.serverData.humdAdjustHumdSettingE1 = pData[89];
	sProtocolData.recvData.serverData.yuBaSwitchE1 = (pData[90] & 0x80)? 1:0;
	sProtocolData.recvData.serverData.heatingYuBaSettingE1 = (pData[90] & 0x20) >> 2;
	sProtocolData.recvData.serverData.windDirectYuBaE1 = (pData[90] & 0x10)? 1:0;
	sProtocolData.recvData.serverData.heatDryYuBaSettingE1 = (pData[90] & 0x04) >> 2;
	sProtocolData.recvData.serverData.lightingYuBaSettingE1 = (pData[90] & 0x01) >> 2;
	sProtocolData.recvData.serverData.nanoexYuBaE1 = (pData[91] & 0x80)? 1:0;
	sProtocolData.recvData.serverData.windTypeYuBaE1 = (pData[91] & 0x40)? 1:0;
	sProtocolData.recvData.serverData.coldDryYuBaSettingE1 = (pData[91] & 0x10) >> 2;
	sProtocolData.recvData.serverData.airChangeYuBaSettingE1 = (pData[91] & 0x04) >> 2;
	sProtocolData.recvData.serverData.realTempStateE1 = pData[92];
	sProtocolData.recvData.serverData.realHumdStateE1 = pData[93];
	sProtocolData.recvData.serverData.realCo2ContentE1 = pData[94];
	sProtocolData.recvData.serverData.realFormaldehydeContentE1 = pData[95] & 0xf0;
	sProtocolData.recvData.serverData.realTvocContentE1 = pData[95] & 0x0f;
	sProtocolData.recvData.serverData.realPm25ContentE1 = pData[96] ;

	notifyProtocolDataUpdate(sProtocolData);
}

/**
 * 处理工厂模式数据
 * 参数：pData
 * 			待处理数据
 *     len
 *          数据长度
 *
 * 返回值：无
 *
 */
static void procFactoryMode04Data(const BYTE *pData , UINT len) {
	if(pData[11] & 0x80) {
		sProtocolData.recvData.userData.resetPermissionFlag = 1;
	} else {
		sProtocolData.recvData.userData.resetPermissionFlag = 0;
	}


	if((pData[11] & 0x70) == 0x20) {
		sProtocolData.recvData.userData.stopMoment = 1;
	} else if((pData[11] & 0x70) == 0x50) {
		sProtocolData.recvData.userData.stopMoment = 2;
	} else {
		sProtocolData.recvData.userData.stopMoment = 0;
	}

	if(pData[11] & 0x08) {
		sProtocolData.recvData.userData.mainBoardStatus = 1;
	} else {
		sProtocolData.recvData.userData.mainBoardStatus = 0;
	}

	sProtocolData.recvData.userData.sensorInit = (pData[11] & 0x04)? 1:0;
	sProtocolData.recvData.userData.workOrder = pData[11] & 0x03;
	sProtocolData.recvData.userData.timingRunningstate = (pData[12] & 0x70) >> 4;
	sProtocolData.recvData.userData.pretreatmentState = (pData[12] & 0x08)? 1:0;
	sProtocolData.recvData.userData.beepSwitchState = (pData[12] & 0x01)? 1:0;
	sProtocolData.recvData.userData.childLockState = (pData[13] & 0x40)? 1:0;
	sProtocolData.recvData.userData.wifiSwitch = (pData[13] & 0x10)? 1:0;
	sProtocolData.recvData.userData.simpleModelSettingSwitch = (pData[13] & 0x08)? 1:0;
	sProtocolData.recvData.userData.darkModeSettingSwitch = (pData[13] & 0x04)? 1:0;
	sProtocolData.recvData.userData.positivePressureSettings = pData[13] & 0x30;
	sProtocolData.recvData.userData.brightLightSetting = pData[14] & 0xf0;
	sProtocolData.recvData.userData.autoAirVolAirPurifier = pData[15] & 0xc0;
	sProtocolData.recvData.userData.airPurifierSwitch = (pData[15] & 0x04)? 1:0;
	sProtocolData.recvData.userData.filterResetAirPurifier = (pData[15] & 0x02)? 1:0;
	sProtocolData.recvData.userData.nanoexAirpurifier = (pData[15] & 0x01)? 1:0;
	sProtocolData.recvData.userData.brightAirPurifier = pData[16] & 0xf0;
	sProtocolData.recvData.userData.addHumdAirPurifier = pData[16] & 0x0f;
	sProtocolData.recvData.userData.windDirectAirPurifier = pData[17] & 0xf0;
	sProtocolData.recvData.userData.autoAirVolHeatExchanger =(pData[18] & 0x20) >> 4;
	sProtocolData.recvData.userData.modeHeatExchanger = (pData[18] & 0x80) >> 2;
	sProtocolData.recvData.userData.nanoexHeatExchanger = (pData[18] & 0x40) ? 1:0;
	sProtocolData.recvData.userData.heatExchangerSwitch = (pData[18] & 0x20)? 1:0;
	sProtocolData.recvData.userData.airConditionSwitch = (pData[19] & 0x80)? 1:0;
	sProtocolData.recvData.userData.autoAirVolAirCondition = (pData[19] & 0x10) >> 4;
	sProtocolData.recvData.userData.windDirectAirCondition = (pData[19] & 0x04) >> 2;
	sProtocolData.recvData.userData.modeAirCondition = pData[19] & 0x03;
	sProtocolData.recvData.userData.nanoexAirCondition = (pData[20] & 0x80)? 1:0;
	sProtocolData.recvData.userData.tempAirConditionSetting = (pData[20] & 0x01) >> 4;
	sProtocolData.recvData.userData.adjustHumdSwitch = (pData[21] & 0x80)? 1: 0;
	sProtocolData.recvData.userData.autoAirVolAdjustHumd = (pData[21] & 0x10) >> 4;
	sProtocolData.recvData.userData.windDirectAdjustHumd = pData[21] & 0x0f;
	sProtocolData.recvData.userData.modeAdjustHumd = (pData[22] & 0x40 ) >> 2;
	sProtocolData.recvData.userData.humdAdjustHumdSetting = pData[22];
	sProtocolData.recvData.userData.yuBaSwitch = (pData[23] & 0x80)? 1:0;
	sProtocolData.recvData.userData.heatingYuBaSetting = (pData[23] & 0x60);
	sProtocolData.recvData.userData.windDirectYuBa = (pData[23] & 0x10)? 1:0;
	sProtocolData.recvData.userData.heatDryYuBaSetting = (pData[23] & 0x04) >> 2;
	sProtocolData.recvData.userData.lightingYuBaSetting = (pData[23] & 0x01) >> 2;
	sProtocolData.recvData.userData.nanoexYuBa = (pData[24] & 0x80)? 1:0;
	sProtocolData.recvData.userData.windTypeYuBa = (pData[24] & 0x40)? 1:0;
	sProtocolData.recvData.userData.coldDryYuBaSetting = (pData[24] & 0x10) >> 2 ;
	sProtocolData.recvData.userData.airChangeYuBaSetting = (pData[24] & 0x04) >> 2;
	sProtocolData.recvData.userData.realTempState = pData[32];
	sProtocolData.recvData.userData.realHumdState = pData[33];
	sProtocolData.recvData.userData.realCo2Content = pData[34];
	sProtocolData.recvData.userData.realformaldehydeContent = pData[35] & 0xf0;
	sProtocolData.recvData.userData.realTvocContent = pData[35] & 0x0f;
	sProtocolData.recvData.userData.realPm25Content = pData[36] ;
	sProtocolData.recvData.userData.dataResetSetting =(pData[37] & 0x80) ?1:0;
	sProtocolData.recvData.userData.dormantState = (pData[37] & 0x40)? 1:0;
	sProtocolData.recvData.userData.refrigerantReplace = (pData[37] & 0x08) >> 4;
	sProtocolData.recvData.userData.autoShutDown = pData[37] & 0x04;
	sProtocolData.recvData.userData.manualShutDown = pData[37] & 0x02;
	sProtocolData.recvData.userData.dealShutDown = (pData[37] & 0x01)? 1:0;
	sProtocolData.recvData.userData.regularTime = pData[38];
	sProtocolData.recvData.userData.timeRemaining = pData[39];
	sProtocolData.recvData.userData.mainMachineMode = (pData[40] & 0x80)? 1:0;
	sProtocolData.recvData.userData.protectedModeState = (pData[40] & 0x40)? 1:0;
	sProtocolData.recvData.userData.voiceSystemSwitch = (pData[40] & 0x10)? 1:0;
	sProtocolData.recvData.userData.airQuality = (pData[40] & 0x02) >> 4;
	sProtocolData.recvData.userData.emergencyCallState = (pData[40] & 0x01)? 1:0;
	sProtocolData.recvData.userData.HUError = pData[41];

	if(pData[41]) {
			LOGD("error %x\n",pData[41]);
	}

	sProtocolData.recvData.factoryData.subMode = pData[42] & 0xf0;
	sProtocolData.recvData.factoryData.mainMode = pData[42] & 0x0f;
	sProtocolData.recvData.factoryData.subModeSetting = pData[43] & 0xf0;
	sProtocolData.recvData.factoryData.mainModeSetting = pData[43] & 0x0f;
	sProtocolData.recvData.factoryData.brakeState = pData[44] & 0x80;
	sProtocolData.recvData.factoryData.wifiState = (pData[44] & 0x30)? 1:0;
	sProtocolData.recvData.factoryData.voltageGainState = (pData[44] & 0x02)? 1:0;
	sProtocolData.recvData.factoryData.writeState = (pData[44] & 0x01)? 1:0;
	sProtocolData.recvData.factoryData.nanoeCheck = (pData[45] & 0xc0) >> 2;
	sProtocolData.recvData.factoryData.PM25ADDF3 = pData[46];
	sProtocolData.recvData.factoryData.PM25ADDF4 = pData[47];
	sProtocolData.recvData.factoryData.pm25SensorState = pData[48];
	sProtocolData.recvData.factoryData.CO2ADDF1 = pData[51];
	sProtocolData.recvData.factoryData.CO2ADDF2 = pData[52];
	sProtocolData.recvData.factoryData.formaldehydeDF1 = pData[55];
	sProtocolData.recvData.factoryData.formaldehydeDF2 = pData[56];
	sProtocolData.recvData.factoryData.formaldehydeSensorState = pData[57] & 0xf0;
	sProtocolData.recvData.factoryData.formaldehydeSensorAZS = pData[57] & 0x03;
	sProtocolData.recvData.factoryData.TVOCDF10 = pData[60];
	sProtocolData.recvData.factoryData.TVOCDF9 = pData[61];
	sProtocolData.recvData.factoryData.tempRegisterLowBits = pData[64];
	sProtocolData.recvData.factoryData.tempRegisterHighBits = pData[65];
	sProtocolData.recvData.factoryData.humdRegisterLowBits = pData[66];
	sProtocolData.recvData.factoryData.humdRegisterHighBits = pData[67];
	sProtocolData.recvData.factoryData.softReset = (pData[68] & 0x80)? 1:0;
	sProtocolData.recvData.factoryData.outputDataRate = pData[68] & 0x70;
	sProtocolData.recvData.factoryData.heaterCondition = (pData[68] & 0x08)? 1:0;
	sProtocolData.recvData.factoryData.interruptPolarity = (pData[68] & 0x02)? 1:0;
	sProtocolData.recvData.factoryData.interruptMode = (pData[68] & 0x01)? 1:0;
	notifyProtocolDataUpdate(sProtocolData);


}

/**
 * 获取校验码
 */
UINT16 getCheckSum(const BYTE *pData, int len) {
	int sum = 0;
	for (int i = 0; i < len; ++i) {
		sum += pData[i];
	}
	return (UINT16) (~sum);
}





/**
 * 解析每一帧数据
 */
static void procParse(const BYTE *pData, UINT len) {
	// CmdID
	switch (MAKEWORD(pData[4], pData[5])) {
	case 0xDE00:
		sProtocolData.mode = SENSOR_DATA_MODE_USER;
		procUserData(pData , len);
		break;
	}

	// 通知协议数据更新
	notifyProtocolDataUpdate(sProtocolData);
}

/**
 * 功能：解析协议
 * 参数：pData 协议数据，len 数据长度
 * 返回值：实际解析协议的长度
 */
int parseProtocol(const BYTE *pData, UINT len) {
	UINT remainLen = len;	// 剩余数据长度
	UINT dataLen;	// 数据包长度
	UINT frameLen;	// 帧长度

	/**
	 * 以下部分需要根据协议格式进行相应的修改，解析出每一帧的数据
	 */
	while (remainLen >= DATA_PACKAGE_MIN_LEN) {
		// 找到一帧数据的数据头
		while ((remainLen >= 4) && ((pData[3] != CMD_HEAD1) || (pData[2] != CMD_HEAD2) || (pData[1] != CMD_HEAD3) || (pData[0] != CMD_HEAD4))) {
			pData++;
			remainLen--;
			continue;
		}

		if (remainLen < DATA_PACKAGE_MIN_LEN) {
			break;
		}

		dataLen = pData[4];
		frameLen = dataLen + DATA_PACKAGE_MIN_LEN;
		if (frameLen > remainLen) {
			// 数据内容不全
			break;
		}

		// 打印一帧数据，需要时在CommDef.h文件中打开DEBUG_PRO_DATA宏
#ifdef DEBUG_PRO_DATA
		for (UINT i = 0; i < frameLen; ++i) {
			LOGD("%x ", pData[i]);
		}
		LOGD("\n");
#endif

		// 支持checksum校验，需要时在CommDef.h文件中打开PRO_SUPPORT_CHECK_SUM宏
#ifdef PRO_SUPPORT_CHECK_SUM
		// 检测校验码
		if (getCheckSum(pData, frameLen - 1) == pData[frameLen - 1]) {
			// 解析一帧数据
			procParse(pData, frameLen);
		} else {
			LOGE("CheckSum error!!!!!!\n");
		}
#else
		// 解析一帧数据
		procParse(pData, frameLen);
#endif

		pData += frameLen;
		remainLen -= frameLen;
	}

	return len - remainLen;
}
