/*
 * Create on 2021.05.24
 * Author: Rose_80022678
 *
 * */
#ifndef JNI_UTIL_MYNETWORKINGLISTENER_H_
#define JNI_UTIL_MYNETWORKINGLISTENER_H_

#include <vector>
#include <string>
#include "system/Thread.h"

namespace std{

enum{
	NW_NOTIFY_TYPE_SSIDS_INFO,
	NW_NOTIFY_TYPE_CONNECT_STATUS,
	NW_NOTIFY_TYPE_HW_ERROR,
};

typedef struct _WifiInfo_t{
	char bssid[32];
	int freq;
	int signal;
	char flags[64];
	char ssid[256];
}WifiInfo_t;

class MyNetWorkingListener:public Thread{

public:
	MyNetWorkingListener();
	virtual ~MyNetWorkingListener();
	class MyNetWorkListener {
		public:
			virtual ~MyNetWorkListener() { }
			virtual void MyNetworkNotify(int type , void *data) = 0;
	};
	void setNetWorkListener(MyNetWorkListener *listener);
	void removeNetWorkListener(MyNetWorkListener *listener);

	bool IsConnected();
	std::string& getSSID();
	std::string& getPSD();
	std::string& getSSIDConnecting();
	void ScanNetWork();
	void getNetWorkInfo();
	void setNetWorkInfo();
	void *getSSIDInfo();
	void startupWifi();
	void ShutdownWifi();
	void firstfresh();
	void startConnectWifi(char *ssid, char *psd);
	bool getWifiStatus();
	int getWifiConnectStatus();
	void resetScanCount();

protected:
	virtual bool threadLoop();

private:
	bool bConnecting;
	bool bConnectOtherAp;
	bool bConnected;
	bool bWifiStartup = true;
	bool m_need_bind;
	bool bWifiProcessIsRun;
	std::string ssid;
	std::string psd;
	std::string ssidconnecting;
	std::vector<MyNetWorkListener*> nwListener;
	int scanCount;
	int connectingTimeCount;
	int CheckconnectingTimeCount;
	bool bFirstRefresh;
	void notifyNetWorkListener(int type , void *data);
};
}
#endif




