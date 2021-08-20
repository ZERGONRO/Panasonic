/*
 * SoftwareTimer.cpp
 *
 *  Created on: 2021年7月20日
 *      Author: 80022678
 */

#include "SoftwareTimer.h"
#include "util/MachineStatus.h"
#include <sys/time.h>



SoftwareTimerListener::SoftwareTimerListener(){
	softwaretimer_flag = false;
	time_count = 0;
//	timer_handler = new Software_Timer;
	timer_handler.clear();
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

void SoftwareTimerListener::Add_SoftwareTimer(Software_Timer *timer){
	if (!timer)
		return;
	if (!timer_handler.empty()){
		std::vector<Software_Timer *>::iterator it = timer_handler.begin();
		for (;it != timer_handler.end();it++){
			Software_Timer *tmp = (*it);
			if (timer->DevID == tmp->DevID){
				if (memcmp(timer->EqpTime_Data, tmp->EqpTime_Data, sizeof(EquipmentTiming)) == 0){
					return;
				}else{
					timer_handler.erase(it);
					delete (tmp);
					tmp = NULL;
					break;
				}
			}
		}
	}
	timer_handler.push_back(timer);
}

void SoftwareTimerListener::Del_SoftwareTimer(int DevID){
	if (timer_handler.empty())
		return;
	std::vector<Software_Timer *>::iterator it = timer_handler.begin();
	for (;it != timer_handler.end();it++){
		if ((*it)->DevID == DevID){
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

//MACHINESTATUS
bool SoftwareTimerListener::threadloop(){
	struct timeval tVal;
	time_t curtime;
	int CurrentTime;
	static MachineTime date;
	char timebuf[32];
	if (!softwaretimer_flag || timer_handler.empty()){
		time_count = 0;
		return false;
	}
	curtime = time(NULL);
	gettimeofday(&tVal, NULL);
	date = MACHINESTATUS->getMachineTime();
	CurrentTime = date.hour * 60 + date.min;
	LOGD("date hour is %d, date min is %d, CurrentTime is %d, tVal.tv_sec is %d\n", date.hour, date.min, CurrentTime, tVal.tv_sec);
	LOGD("curtime is %ld\n", curtime);
	sprintf(timebuf, "%02d%02d", date.hour, date.min);
	time_count++;
	if (time_count > 60){
		time_count = 0;
		std::vector<Software_Timer *>::iterator it = timer_handler.begin();
		for (;it != timer_handler.end();it++){
			Software_Timer *tmp_timer = (*it);
			if (tmp_timer->DevID < 0 || tmp_timer->DevID > 6){
				continue;
			}else{
				if (tmp_timer->EqpTime_Data->Time1StageFlag){
					if (tmp_timer->start_time1 < CurrentTime && tmp_timer->close_time1 > CurrentTime){
						tmp_timer->SWT_Mode = SoftwareTimer_Start;
						/*回调*/
					}else if (tmp_timer->start_time1 > CurrentTime || tmp_timer->close_time1 < CurrentTime){
						tmp_timer->SWT_Mode = SoftwareTimer_Timeout;
					}

					if (tmp_timer->EqpTime_Data->Time2StageFlag){

					}
				}
			}
		}
	}
}






