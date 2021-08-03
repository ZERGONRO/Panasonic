/*
 * ProtocolRepotData.h
 *
 *  Created on: 2021年8月2日
 *      Author: 80022678
 */

#ifndef JNI_UTIL_PROTOCOLREPOTDATA_H_
#define JNI_UTIL_PROTOCOLREPOTDATA_H_
#include "util/ProtocolDataSend.h"

class ProtocolReportDataListence {
	public:
		ProtocolReportDataListence();
		virtual ~ProtocolReportDataListence();
		static  ProtocolReportDataListence* getInstance();
		void getcurrentManualDeviceParam();

	protected:
		bool threadloop();
	private:
		SProtocolSendData sData;

};

#define PROTOCOLREPORTDATA   ProtocolReportDataListence::getInstance();



#endif /* JNI_UTIL_PROTOCOLREPOTDATA_H_ */
