/*
 * SoftwareTimer.cpp
 *
 *  Created on: 2021年7月20日
 *      Author: 80022678
 */

#include "SoftwareTimer.h"


SoftwareTimerListener::SoftwareTimerListener(){
	softwaretimer_flag = false;
	time_count = -1;
	timer_handler->clear();
}

SoftwareTimerListener::~SoftwareTimerListener(){

}

SoftwareTimerListener* SoftwareTimerListener::getInstance(){
	static SoftwareTimerListener sST;
	return &sST;
}



bool SoftwareTimerListener::Is_SoftwareTimer_Empty(){
	if (timer_handler->empty()){
		return true;
	}else{
		return false;
	}
}

void SoftwareTimerListener::Insert_SoftwareTimer(Software_Timer *timer_data){
	if (!timer_data){
		return;
	}
	std::vector<Software_Timer *>::iterator it = timer_handler->begin();
	for (; it != timer_handler->end();it++){
		if ((*it)->EqpTime_Data.DeviceID == timer_data->EqpTime_Data.DeviceID){
			return;
		}
	}
	timer_handler->push_back(timer_data);

}

void SoftwareTimerListener::Remove_SoftwareTimer(int DevID){
	if (DevID < 0 || DevID > 7 || Is_SoftwareTimer_Empty()){
		return;
	}

	std::vector<Software_Timer *>::iterator it = timer_handler->begin();
	for (; it != timer_handler->end();it++){
		if ((*it)->EqpTime_Data.DeviceID == DevID){
			timer_handler->erase(it);
			break;
		}
	}
}

void SoftwareTimerListener::Init_SoftwareTimer(unsigned int timeout, unsigned int repeat, timeout_callback_handler callback){


}

void SoftwareTimerListener::Start_SoftwareTimer(){
	if (Is_SoftwareTimer_Empty()){
		return;
	}else{
		softwaretimer_flag = true;
		time_count = 1;
	}

}

void SoftwareTimerListener::Stop_SoftwareTimer(){
	softwaretimer_flag = false;
	time_count = -1;
}

bool SoftwareTimerListener::threadloop(){

	if (!softwaretimer_flag){
		return false;
	}else{
		time_count++;
		if (!Is_SoftwareTimer_Empty()){
			if (time_count > 60){
				time_count = 0;
				std::vector<Software_Timer *>::iterator it = timer_handler->begin();
				for (; it != timer_handler->end();it++){
					Software_Timer *tmp = (*it);
					if (tmp->timeout > 0){
						tmp->timeout--;
					}else{
						timer_handler->erase(it);
						tmp->callback(tmp->EqpTime_Data);
					}

				}
			}
		}else{
			LOGD("timer_handler is cleared\n");
		}

	}
	return false;
}








