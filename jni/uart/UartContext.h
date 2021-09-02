/*
 * UartContext.h
 *
 *  Created on: Sep 5, 2017
 *      Author: guoxs
 */

#ifndef _UART_UARTCONTEXT_H_
#define _UART_UARTCONTEXT_H_

#include <vector>
#include "system/Thread.h"
#include "CommDef.h"

class UartContext : public Thread {
public:
	virtual ~UartContext();

	bool openUart(const char *pFileName, UINT baudRate);
	void closeUart();

	bool isOpen() { return mIsOpen; }

	bool send(const BYTE *pData, UINT len);
	bool send1(const BYTE *pData , UINT len);
	static UartContext* getInstance();

protected:
	virtual bool readyToRun();
	virtual bool threadLoop();

private:
	UartContext();

private:
	bool mIsOpen;
	bool mIsOpen1;
	int mUartID;
	int mMcuUartID;
	// 用于拼接缓存数据，可能存在上一包数据解析未完全，残留有数据
	BYTE *mDataBufPtr;
	int mDataBufLen;
};

#define UARTCONTEXT		UartContext::getInstance()

#endif /* _UART_UARTCONTEXT_H_ */
