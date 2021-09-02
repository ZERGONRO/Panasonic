/*
 * ProtocolContinueSend.h
 *
 *  Created on: 2021年7月22日
 *      Author: 80022717
 */

#ifndef JNI_UART_PROTOCOLCONTINUESEND_H_
#define JNI_UART_PROTOCOLCONTINUESEND_H_

#include <vector>
#include "system/Thread.h"
#include "CommDef.h"
#include "uart/ProtocolData.h"
#include "uart/ProtocolSendData.h"

class ProtocolContinueSend : public Thread{
public :
	ProtocolContinueSend();
	void setUartHandler(int);
	void initProtocolSend();
	void startProtocolSend();
	void stopProtocolSend();
	void updateProtocolSendData(const SendProtocolData *sData);
	void updateProtocolSendDataIm(const SendProtocolData *sData);
	void setChildLock(int status);
	void setShutDownManaul();
	void setShutDownAutomatic();
//	void setChildLock(int status);
	void setShutDownDealFlag();
	void setProtocolMode(const SendProtocolData *sData);
	void setStoreSettingFlag();
	void setLoadActionDelayFlag(int flag);
	int getLoadActionDelayFlag();
	void clearFilterReplaceNotice();
	void setFormaldehydeThresHode(int formaldehydeThres);
	void setTvocThresHode(int tvocThres);
	void setCo2ThresHode(int co2Thres);
	void setPm25ThresHode(int pm25Thres);
	void sethumdThresHode(int humdThres);
	void setTempThresHold(int tempThres);
	void setMode(int mainMode , int subMode);
	void setVoiceSystemSwitch(int status);
	void setRegularTime(int time);
	void setMainAuxMode(int mode);
	void setRF254Switch(int status);
protected:
	virtual bool readyToRun();
	virtual bool threadLoop();
private:
	int dataUpdated;
	int mUartID;
	SendProtocolData *data;
	SendProtocolData *dataBackup;
	int backMainStatus;
	int refrigerantReplaceNotice;
	void initProtocolData();
	int dealFlag;
	int dealSetCount;
	int filterReplaceNotice;
};

#define UARTSENDCONTEXT			ProtocolContinueSend::getInstance()
#endif /* JNI_UART_PROTOCOLCONTINUESEND_H_ */
