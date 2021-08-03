/*
 * ProtocolRepotData.cpp
 *
 *  Created on: 2021年8月2日
 *      Author: 80022678
 */
#include "ProtocolRepotData.h"

ProtocolReportDataListence::ProtocolReportDataListence(){

}

ProtocolReportDataListence::~ProtocolReportDataListence(){

}


ProtocolReportDataListence* ProtocolReportDataListence::getInstance(){
	static ProtocolReportDataListence sPrd;
	return &sPrd;
}


