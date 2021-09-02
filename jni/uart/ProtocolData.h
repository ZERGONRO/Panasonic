/*
 * ProtocolData.h
 *
 *  Created on: Sep 7, 2017
 *      Author: guoxs
 */

#ifndef _UART_PROTOCOL_DATA_H_
#define _UART_PROTOCOL_DATA_H_

#include <string>
#include "CommDef.h"

/******************** CmdID ***********************/
#define CMDID_POWER							0x0
/**************************************************/

/******************** 错误码 ***********************/
#define ERROR_CODE_CMDID			1
/**************************************************/

typedef enum {

	SENSOR_DATA_MODE_USER, //用户模式
	SENSOR_DATA_MODE_FACTORY,  //工厂模式
	SENSON_DATA_MODE_BUSINESS,  //营业模式
	SENSON_DATA_MODE_SERVICE,   //服务模式


}SensorDataMode_t;


#endif /* _UART_PROTOCOL_DATA_H_ */
