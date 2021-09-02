/*
 * ProtocolSender.cpp
 *
 *  Created on: Sep 8, 2017
 *      Author: guoxs
 */

#include "ProtocolParser.h"
#include "app/Activity.h"
#include <vector>
#include "entry/EasyUIContext.h"
#include <system/Mutex.h>
#include "CommDef.h"
#include "uart/ProtocolParser.h"
#include "uart/UartContext.h"
#include "ProtocolSendData.h"
#include "utils/Log.h"
#include <stdio.h>
#include <string.h>


static Mutex sLock , mLock;
static std::vector<OnProtocolDataUpdateFun> sProtocolDataUpdateListenerList;
static std::vector<OnMcuProtocolDataUpdateFun> mcuProtocolDataUpdateListenerList;

extern BYTE getCheckSum(const BYTE *pData, int len);

static void dealUserModeData(const userModeSendData *srcData , BYTE *outData , int isUserMode) {

	outData[0] |= srcData->autoAirVolAirPurifier <<4;
	if(srcData->airPurifierSwitch){
		outData[0] |= 1<<2;
	}
	if(srcData->filterResetAirPurifier){
		outData[0] |= 1<<1;
	}
	if(srcData->nanoexAirPurifier){
		outData[0] |= 1<<0;
	}
	outData[1] |= srcData->brightAirPurifier <<4;
	outData[1] |= srcData->addHumdAirPurifier <<0;
	outData[2] |= srcData->windDirectAirPurifier <<4;
	outData[3] |= srcData->autoAirVolHeatExchanger <<5;
	outData[3] |= srcData->modeHeatExchanger <<3;
	if(srcData->nanoexHeatExchanger){
		outData[3] |= 1<<2;
	}
	if(srcData->heatExchangerSwitch){
		outData[3] |= 1<<1;
	}

	if(srcData->airConditionSwitch){
		outData[4] |= 1<<7;
	}
	if(srcData->autoAirVolAirCondition){
		outData[4] |= 1<<4;
	}
	outData[4] |= srcData->windDirectAirCondition <<2;
	outData[4] |= srcData->modeAirCondition << 0;
	if(srcData->nanoexAirCondition){
		outData[5] |= 1<<7;
	}
	outData[5] = srcData->tempAirConditionSetting;
	if(srcData->adjustHumdSwitch){
		outData[6] |= 1<<7;
	}
	outData[6] = srcData->autoAirVolAdjustHumd << 4;
	outData[6] = srcData->windDirectAdjustHumd << 0;
	outData[7] = srcData->modeAdjustHumd << 6;
	outData[7] = srcData->humdAdjustHumdSetting;
	if(srcData->yuBaSwitch){
		outData[8] |= 1<<7;
	}
	outData[8] |= srcData->heatingYuBaSetting << 5;
	if(srcData->windDirectYuBa){
		outData[8] |= 1<<4;
	}
	outData[8] |= srcData->heatDryYuBaSetting << 2;
	outData[8] |= srcData->lightingYuBaSetting << 0;
	if(srcData->nanoexYuBa){
		outData[9] |= 1<<7;
	}
	if(srcData->windTypeYuBa){
		outData[9] |= 1<<6;
	}
	outData[9] |= srcData->coldDryYuBaSetting << 4;
	outData[9] |= srcData->airChangeYuBaSetting <<2;
	if(srcData->beepSwitchState){
		outData[10] |= 1<<7;
	}
	if(srcData->childLockState){
		outData[10] |= 1<<6;
	}
	if(srcData->wifiSwitch){
		outData[10] |= 1<<4;
	}
	if(srcData->simpleModelSettingSwitch){
		outData[10] |= 1<<3;
	}
	if(srcData->darkModeSettingSwitch){
		outData[10] |= 1<<2;
	}
	outData[10] |= srcData->positivePressureSettings << 0;
	outData[11] |= srcData->brightLightSetting << 4;
	outData[12] |= srcData->realTempState;
	outData[13] |= srcData->realHumdState;
	outData[14] |= srcData->realCo2Content;
	outData[15] |= srcData->realformaldehydeContent <<4;
	outData[15] |= srcData->realTvocContent << 0;
	outData[16] |= srcData->realPm25Content;
	if(srcData->dataResetSetting){
		outData[17] |= 1<<7;
	}
	if(srcData->dormantState){
		outData[17] |= 1<<6;
	}
	outData[17] |= srcData->airQuality << 4;
	outData[17] |= srcData->autoShutDown << 2;
	outData[17] |= srcData->manualShutDown <<1;
	outData[17] |= srcData->dealShutDown << 0;
	outData[18] |= srcData->displayPlace << 4;
	if(srcData->voiceSystemSwitch){
		outData[18] |= 1<<3;
	}
	if(srcData->RF254Switch){
		outData[18] |= 1<<2;
	}
	outData[18] |= srcData->protectedModeState << 0;
	if(srcData->modeUsefulSettingState){
		outData[19] |= 1<<7;
	}
	outData[19] |= srcData->wifiCheckState <<5;
	if(srcData->wifiOTAState){
		outData[19] |= 1<<3;
	}
	if(srcData->IMState){
		outData[19] |= 1<<2;
	}
	if(srcData->emergencyCallState){
		outData[19] |= 1<<1;
	}
	if(srcData->quickSwitchState){
		outData[19] |= 1<<0;
	}
	outData[20] |= srcData->HUError;

}


static int firstStartCount = 0;
void setProtocolSenderFirstStartCount(int count) {
	firstStartCount = count;
}

/**
 * 需要根据协议格式进行拼接，以下只是个模板
 */
bool sendProtocol(const UINT16 cmdID, const BYTE *pData, BYTE len) {
	if (len + DATA_PACKAGE_MIN_LEN > 256) {
		LOGE("sendProtocol data is too len !!!\n");
		return false;
	}

	BYTE dataBuf[256];

	dataBuf[0] = CMD_HEAD1;
	dataBuf[1] = CMD_HEAD2;			// 同步帧头

	dataBuf[2] = HIBYTE(cmdID);
	dataBuf[3] = LOBYTE(cmdID);		// 命令字节

	dataBuf[4] = len;

	UINT frameLen = 5;

	// 数据
	for (int i = 0; i < len; ++i) {
		dataBuf[frameLen] = pData[i];
		frameLen++;
	}

#ifdef PRO_SUPPORT_CHECK_SUM
	// 校验码
	dataBuf[frameLen] = getCheckSum(dataBuf, frameLen);
	frameLen++;
#endif

	return UARTCONTEXT->send(dataBuf, frameLen);
}
