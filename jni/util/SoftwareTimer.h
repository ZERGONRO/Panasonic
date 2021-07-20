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



typedef void (*timeout_callback_handler)(EqpTimeData EqpData);

typedef struct Software_Timer_t{
	unsigned int timeout;
	EqpTimeData EqpTime_Data;
	timeout_callback_handler callback;
//	struct Software_Timer_t *next;
}Software_Timer;


class SoftwareTimerListener{
	public:
		SoftwareTimerListener();
		virtual ~SoftwareTimerListener();

//		void registerSoftwareTimerListener(timeout_callback_handler sListener);
//		void unregisterSoftwareTimerListener(timeout_callback_handler sListener);

		static SoftwareTimerListener* getInstance();

		bool Is_SoftwareTimer_Empty();
		void Insert_SoftwareTimer(Software_Timer *timer_data);
		void Remove_SoftwareTimer(int DevID);
		void Init_SoftwareTimer(unsigned int timeout, unsigned int repeat, timeout_callback_handler callback);
		void Start_SoftwareTimer();
		void Stop_SoftwareTimer();

	private:
		bool softwaretimer_flag;
		int  time_count;
		std::vector<Software_Timer *> *timer_handler;
	protected:
		virtual bool threadloop();
};

#define SOFTWARETIMER	SoftwareTimerListener::getInstance()




#endif /* JNI_UTIL_SOFTWARETIMER_H_ */
