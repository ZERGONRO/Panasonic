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

typedef enum {
	SoftwareTimer_Stop,
	SoftwareTimer_Start,
	SoftwareTimer_Timeout,
}SoftwareTimer_Mode;

typedef void (*timeout_callback_handler)(int, SoftwareTimer_Mode );

typedef struct Software_Timer_t{
	SoftwareTimer_Mode SWT_Mode;
	EquipmentTiming *EqpTime_Data;
	timeout_callback_handler callback;
}Software_Timer;


class SoftwareTimerListener:public Thread{
	public:
		SoftwareTimerListener();
		virtual ~SoftwareTimerListener();

		static SoftwareTimerListener* getInstance();
		void Init_SoftwareTimer();
		void DeInit_SoftwareTimer();
		void Add_SoftwareTimer(EquipmentTiming *timer);
		void Del_SoftwareTimer(int DevID);
		void Calc_SoftwareTimer();
		std::vector<Software_Timer *> GetSWTData();
//		void StartUp_SoftwareTimer(int DevID);
		void Update_SoftwareTimer();
//		void Stop_SoftwareTimer(int DevID);
		int GetStatus_SoftwareTimer(int DevID);
//		void registerSoftWareTimer();

	private:
		bool softwaretimer_flag;
		int  time_count;
		std::vector<Software_Timer *> timer_handler;
	protected:
		virtual bool threadLoop();
};

#define SOFTWARETIMER	SoftwareTimerListener::getInstance()




#endif /* JNI_UTIL_SOFTWARETIMER_H_ */
