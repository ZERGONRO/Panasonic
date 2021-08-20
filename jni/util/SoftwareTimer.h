/*
 * SoftwareTimer.h
 *
 *  Created on: 2021年7月20日
 *      Author: 80022678
 */

#ifndef JNI_UTIL_SOFTWARETIMER_H_
#define JNI_UTIL_SOFTWARETIMER_H_

#include <vector>
#include <string>
#include "system/Thread.h"
#include "util/MachineStatus.h"



typedef void (*timeout_callback_handler)(void *);

typedef enum {
	SoftwareTimer_Start,
	SoftwareTimer_Stop,
	SoftwareTimer_Timeout,
	SoftwareTimer_Reload,
	SoftwareTimer_Resume
}SoftwareTimer_Mode;

typedef struct Software_Timer_t{
	int DevID;
	int start_time1;
	int close_time1;
	int start_time2;
	int close_time2;
	SoftwareTimer_Mode SWT_Mode;
	EquipmentTiming *EqpTime_Data;
	timeout_callback_handler callback;
}Software_Timer;


class SoftwareTimerListener{
	public:
		SoftwareTimerListener();
		virtual ~SoftwareTimerListener();

		static SoftwareTimerListener* getInstance();
		void Init_SoftwareTimer();
		void DeInit_SoftwareTimer();
		void Add_SoftwareTimer(Software_Timer *timer);
		void Del_SoftwareTimer(int DevID);
		void Calc_SoftwareTimer();

	private:
		bool softwaretimer_flag;
		int  time_count;
		std::vector<Software_Timer *> timer_handler;
	protected:
		virtual bool threadloop();
};

#define SOFTWARETIMER	SoftwareTimerListener::getInstance()




#endif /* JNI_UTIL_SOFTWARETIMER_H_ */
