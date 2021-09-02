/*
 * ProtocolContinueSend.cpp
 *
 *  Created on: 2021年7月22日
 *      Author: 80022717
 */

#ifndef JNI_UART_PROTOCOLCONTINUESEND_CPP_
#define JNI_UART_PROTOCOLCONTINUESEND_CPP_

#include <string.h>
#include "uart/ProtocolContinueSend.h"
#include "uart/ProtocolSender.h"
#include "utils/Log.h"
#include "ProtocolData.h"
#include <system/Mutex.h>
#include <system/Thread.h>
static Mutex sLock , rLock;

ProtocolContinueSend::ProtocolContinueSend(){
	LOGD("init ProtocolContinueSend\n");
}

/**
 * 设置串口Handler
 * 参数：uartID
 * 			串口Handler
 *
 * 返回值：无
 *
 */
void ProtocolContinueSend::setUartHandler(int uartID) {
	this->mUartID = uartID;
}

/**
 * 初始化线程数据
 * 参数：无
 *
 * 返回值：无
 *
 */
void ProtocolContinueSend::initProtocolSend(){

	backMainStatus = 0;
	dealFlag = 0;
	dealSetCount = 0;
	data = new SendProtocolData;
	memset(data , 0 , sizeof(SendProtocolData));
	data->mode = SENSOR_DATA_MODE_USER;			//默认用户模式,此处需要根据开机进入其他模式设定
	data = new SendProtocolData;
	memset(data , 0 , sizeof(SendProtocolData));
	data->mode = SENSOR_DATA_MODE_USER;	//默认用户模式,此处需要根据开机进入其他模式设定
	initProtocolData();


}

/**
 * 启动线程
 * 参数：无
 *
 * 返回值：无
 *
 */
void ProtocolContinueSend::startProtocolSend() {
	if(isRunning()) {
		return;
	}
	run("CONTINUE SEND");
}

/**
 * 停止线程
 * 参数：无
 *
 * 返回值：无
 *
 */
void ProtocolContinueSend::stopProtocolSend() {
	if(isRunning()) {
		requestExit();
	}
}

/**
 * 更新串口发送数据
 * 参数：sData
 *			新的串口数据
 * 返回值：无
 *
 */
void ProtocolContinueSend::updateProtocolSendData(const SendProtocolData *sData) {

	LOGD("updateProtocolSendData\n");
	sLock.lock();
	memcpy(&dataBackup->data.userData , &sData->data.userData , sizeof(userModeSendData));

	if(refrigerantReplaceNotice) {														//制冷剂更换提醒确认
		dataBackup->data.userData.refrigerantReplace = 1;
	}
	dataUpdated = 1;
	sLock.unlock();
}

/**
 * 初始化数据
 * 参数：无
 *
 * 返回值：无
 *
 */
void ProtocolContinueSend::initProtocolData() {
	if(data->mode == SENSOR_DATA_MODE_USER){
		data->data.userData.airPurifierSwitch = 1;
		data->data.userData.windDirectAirPurifier = 0;
		data->data.userData.autoAirVolAirPurifier = 0;
		data->data.userData.filterResetAirPurifier = 1;
		data->data.userData.nanoexAirPurifier = 1;
		data->data.userData.brightAirPurifier = 0;
		data->data.userData.addHumdAirPurifier = 0;

	}
	else {

	}
}

/**
 *
 *
 *
 */
void ProtocolContinueSend::updateProtocolSendDataIm(const SendProtocolData *sData){
	memcpy(&data->data , &sData->data , sizeof(uartSendData));
	memcpy(&dataBackup->data , &sData->data , sizeof(uartSendData));
}
/*
 *童锁状态
 *
 *参数：status
 *返回值：无
 * */

void ProtocolContinueSend::setChildLock(int status) {
	data->data.userData.childLockState = status;
}

/*
 *设置手动关机
 *
 *参数：无
 *返回值：无
 * */
void ProtocolContinueSend::setShutDownManaul(){
	data->data.userData.manualShutDown = 1;
}
/*
 * 自动关机
 *
 * 参数：无
 * 返回值：无
 *
 * */
void ProtocolContinueSend::setShutDownAutomatic(){
	data->data.userData.autoShutDown = 1;
}

/*
 * 关机处理判断
 *
 * 参数：无
 * 返回值：无
 */
void ProtocolContinueSend::setShutDownDealFlag(){
	data->data.userData.dealShutDown = 1;
	dealFlag = 1;
	dealSetCount = 0;

}

/*
 * 清除滤网更换提醒
 *
 * 参数：无
 * 返回值：无
 *
 */
void ProtocolContinueSend::clearFilterReplaceNotice(){
	filterReplaceNotice = 1;
}

void ProtocolContinueSend::setProtocolMode(const SendProtocolData *sData){
	LOGD("set mode %d\n" , sData->mode);
		sLock.lock();
		data->mode = sData->mode;
		dataBackup->mode = sData->mode;
		memcpy(&dataBackup->data , &sData->data , sizeof(uartSendData));
		dataUpdated = 1;
		sLock.unlock();
}

void ProtocolContinueSend::setStoreSettingFlag(){

}

/*
 * 设置甲醛阈值
 * 参数 ：int formaldehydeThres
 * 返回值：无
 * */
void ProtocolContinueSend::setFormaldehydeThresHode(int formaldehydeThres){
	data->data.userData.formaldehydeThresHoldSetting = formaldehydeThres;
}

/*
 * 设置TVOC阈值
 * 参数 ：int tvocThres
 * 返回值：无
 * */
void ProtocolContinueSend::setTvocThresHode(int tvocThres){
	data->data.userData.tvocThresHoldSetting = tvocThres;
}

/*
 * 设置CO2阈值
 * 参数 ：int co2Thres
 * 返回值：无
 * */
void ProtocolContinueSend::setCo2ThresHode(int co2Thres){
	data->data.userData.co2ThresHoldSetting = co2Thres;
}

/*
 * 设置PM2.5阈值
 * 参数 ：int pm25Thres
 * 返回值：无
 * */
void ProtocolContinueSend::setPm25ThresHode(int pm25Thres){
	data->data.userData.pm25ThresHoldSetting = pm25Thres;
}

/*
 * 设置湿度阈值
 * 参数 ：int humdThres
 * 返回值：无
 * */
void ProtocolContinueSend::sethumdThresHode(int humdThres){
	data->data.userData.humdThresHoldSetting = humdThres;
}

/*
 * 设置温度阈值
 * 参数 ：int tempThres
 * 返回值：无
 * */
void ProtocolContinueSend::setTempThresHold(int tempThres){
	data->data.userData.tempThresHoldSetting = tempThres;
}

/*
 * 设置语音系统
 *
 * 参数：int status
 * 返回值：无
 */
void ProtocolContinueSend::setVoiceSystemSwitch(int status){
	data->data.userData.voiceSystemSwitch = status;
}

/*
 * RF254开关
 *
 * 参数：int status
 * 返回值：无
 */
void ProtocolContinueSend::setRF254Switch(int status){
	data->data.userData.RF254Switch = status;
}

void ProtocolContinueSend::setLoadActionDelayFlag(int flag);
int ProtocolContinueSend::getLoadActionDelayFlag();

/*
 * 设置定时时间
 *
 * 参数：int time
 * 返回值：无
 */
//void ProtocolContinueSend::setRegularTime(int time){
//	data->data.userData.r = time;
//}

/*
 * 设置主辅机
 *
 * 参数：int mode
 * 返回值：无
 */
void ProtocolContinueSend::setMainAuxMode(int mode){
	data->data.userData.mainAuxMode = mode;
}

/*
 * 设置模式
 * 参数：
 * 		主模式: int mainMode
 * 		子模式： int subMode
 * 返回值：无
 * */
void ProtocolContinueSend::setMode(int mainMode , int subMode){
	data->data.userData.mainMode = mainMode;
	data->data.userData.subMode = subMode;
}

bool ProtocolContinueSend::readyToRun(){
	return false;

}
bool ProtocolContinueSend::threadLoop(){
	return false;
}

#endif /* JNI_UART_PROTOCOLCONTINUESEND_CPP_ */
