/*
 * SoftwareTimer.cpp
 *
 *  Created on: 2021年7月20日
 *      Author: 80022678
 */

#include "SoftwareTimer.h"
#include "util/MachineStatus.h"
#include <sys/time.h>
#include "util/MyNetWorkingListener.h"
#include "ManualStatusListence.h"
#include "utils/TimeHelper.h"

extern MyNetWorkingListener *nwlistener;



SoftwareTimerListener::SoftwareTimerListener(){
	LOGD("SoftwareTimerListener init\n");
	softwaretimer_flag = false;
	time_count = 0;
	Init_SoftwareTimer();
}

SoftwareTimerListener::~SoftwareTimerListener(){
	DeInit_SoftwareTimer();

}

SoftwareTimerListener* SoftwareTimerListener::getInstance(){
	static SoftwareTimerListener sST;
	return &sST;
}

void SoftwareTimerListener::Init_SoftwareTimer(){

}

void SoftwareTimerListener::DeInit_SoftwareTimer(){

}

void SoftwareTimerListener::Del_SoftwareTimer(int DevID){
	if (timer_handler.empty())
		return;
	std::vector<Software_Timer *>::iterator it = timer_handler.begin();
	for (;it != timer_handler.end();it++){
		if ((*it)->EqpTime_Data->DeviceID == DevID){
			Software_Timer *tmp = (*it);
			timer_handler.erase(it);
			delete (tmp);
			tmp = NULL;
			break;
		}
	}
}

void SoftwareTimerListener::Calc_SoftwareTimer(){

}

void StartUp_SoftwareTimer(int DevID){
	if (DevID < 0 || DevID > 6)
		return;
	/*Start up the device and translate param-data(Maybe ManualMode can do something)*/
	MANUALSTATUS->ControlDeviceTimer(DevID, 1);
}

void SoftwareTimerListener::Update_SoftwareTimer(){
	bool FlagSWTChange = false;
	struct tm *t = TimeHelper::getDateTime();
	int CurrentTime = (t->tm_hour + 8) * 60 + t->tm_min;
	LOGD("CurrentTime is %d and days is %d\n", CurrentTime, t->tm_wday);
	std::vector<Software_Timer *>::iterator it = timer_handler.begin();
	for (;it != timer_handler.end();it++){
		Software_Timer *tmp_timer = (*it);
		bool Flag_WeekTime = false;
		if (tmp_timer->EqpTime_Data->DeviceSwitch){
			for (int i = 0;tmp_timer->EqpTime_Data->weekbuf[i] != 0;i++){
				if (tmp_timer->EqpTime_Data->weekbuf[i] == (t->tm_wday)){
					Flag_WeekTime = true;
					break;
				}
			}
			if (!Flag_WeekTime)
				continue;
			/*stage*/
//			LOGD("STAGE!!!\n");
			if (!tmp_timer->EqpTime_Data->Time1StageFlag && !tmp_timer->EqpTime_Data->Time2StageFlag){
				continue;
			}else if (tmp_timer->EqpTime_Data->Time1StageFlag && (tmp_timer->EqpTime_Data->TimeOpenValue1 < CurrentTime &&
					tmp_timer->EqpTime_Data->TimeCloseValue1 > CurrentTime)){
				if (tmp_timer->SWT_Mode != SoftwareTimer_Start){
					tmp_timer->SWT_Mode = SoftwareTimer_Start;
					FlagSWTChange = true;
				}
			}else if (tmp_timer->EqpTime_Data->Time2StageFlag && (tmp_timer->EqpTime_Data->TimeOpenValue2 < CurrentTime &&
					tmp_timer->EqpTime_Data->TimeCloseValue2 > CurrentTime)){
				if (tmp_timer->SWT_Mode != SoftwareTimer_Start){
					tmp_timer->SWT_Mode = SoftwareTimer_Start;
					FlagSWTChange = true;
				}
			}else if ((tmp_timer->SWT_Mode == SoftwareTimer_Start) && (tmp_timer->EqpTime_Data->TimeCloseValue1 <= CurrentTime
					|| tmp_timer->EqpTime_Data->TimeCloseValue2 <= CurrentTime)){
				tmp_timer->SWT_Mode = SoftwareTimer_Timeout;
				FlagSWTChange = true;
			}else if ((tmp_timer->EqpTime_Data->TimeOpenValue1 == tmp_timer->EqpTime_Data->TimeCloseValue1)
					|| (tmp_timer->EqpTime_Data->TimeOpenValue2 == tmp_timer->EqpTime_Data->TimeCloseValue2)){
				tmp_timer->SWT_Mode = SoftwareTimer_Stop;
				Del_SoftwareTimer(tmp_timer->EqpTime_Data->DeviceID);
			}else{
				if (tmp_timer->SWT_Mode != SoftwareTimer_Stop){
					tmp_timer->SWT_Mode = SoftwareTimer_Stop;
					FlagSWTChange = true;
				}
			}
			if (FlagSWTChange){
				tmp_timer->callback(tmp_timer->EqpTime_Data->DeviceID, tmp_timer->SWT_Mode);
				FlagSWTChange = false;
			}
		}else{
			LOGD("Device:%d Switch closed\n", tmp_timer->EqpTime_Data->DeviceID);
		}
	}
}

std::vector<Software_Timer *> SoftwareTimerListener::GetSWTData(){
	return timer_handler;
}

void Stop_SoftwareTimer(int DevID){
	if (DevID > 6 || DevID < 0)
		return;
	/*stop the device running(manualmode can do something)*/
	MANUALSTATUS->ControlDeviceTimer(DevID, 0);
}

int SoftwareTimerListener::GetStatus_SoftwareTimer(int DevID){
	if (DevID > 6 || DevID < 0)
		return SoftwareTimer_Stop;
	std::vector<Software_Timer *>::iterator it = timer_handler.begin();
	for (;it != timer_handler.end();it++){
		if ((*it)->EqpTime_Data->DeviceID == DevID){
			return (*it)->SWT_Mode;
		}
	}
}


/*Callback Func*/
static void SoftWareTimerCallBackFunc(int DevID, SoftwareTimer_Mode mode){
	if (DevID < 0 || DevID > 6){
		return;
	}
	switch(mode){
		case SoftwareTimer_Stop:
		{
			LOGD("Close the device\n");
			Stop_SoftwareTimer(DevID);
		}
			break;
		case SoftwareTimer_Start:
		{
			LOGD("Start the device\n");
			StartUp_SoftwareTimer(DevID);
		}
			break;
		case SoftwareTimer_Timeout:
		{
			Stop_SoftwareTimer(DevID);
		}
			break;
	}
}

void SoftwareTimerListener::Add_SoftwareTimer(EquipmentTiming *EqpTimer){
	if (!EqpTimer)
		return;
	if (!timer_handler.empty()){
		std::vector<Software_Timer *>::iterator it = timer_handler.begin();
		for (;it != timer_handler.end();it++){
			Software_Timer *tmp = (*it);
			if (EqpTimer->DeviceID == tmp->EqpTime_Data->DeviceID){
				if (memcmp(EqpTimer, tmp->EqpTime_Data, sizeof(EquipmentTiming)) == 0){
					return;
				}else{
					timer_handler.erase(it);
					delete (tmp->EqpTime_Data);
					tmp->EqpTime_Data = NULL;
					delete (tmp);
					tmp = NULL;
					break;
				}
			}
		}
	}
	Software_Timer *tmpSoftwareTimer = new Software_Timer;
	tmpSoftwareTimer->EqpTime_Data = new EquipmentTiming;
	tmpSoftwareTimer->SWT_Mode = SoftwareTimer_Stop;
	tmpSoftwareTimer->callback = &SoftWareTimerCallBackFunc;
	memcpy(tmpSoftwareTimer->EqpTime_Data, EqpTimer, sizeof(EquipmentTiming));
	timer_handler.push_back(tmpSoftwareTimer);
//	LOGD("timer_handler size is %d\n", timer_handler.size());
}


//MACHINESTATUS
bool SoftwareTimerListener::threadLoop(){
//	char timebuf[32];

	if (nwlistener->getWifiConnectStatus() == 2){
		time_count++;
		if (time_count > 120){
			time_count = 0;
			if (!timer_handler.empty()){
				Update_SoftwareTimer();
			}else{
				LOGD("timer_handler is empty\n");
			}
		}
	}else{

	}
	Thread::sleep(100);
	return true;
}






