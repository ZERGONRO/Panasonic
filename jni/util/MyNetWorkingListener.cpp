/*
 * MyNetWorkingListener.cpp
 *
 *  Created on: 2021年5月24日
 *      Author: 80022678
 */

#include "util/MyNetWorkingListener.h"
#include "util/MachineStatus.h"
#include "string.h"
#include "utils/log.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ifaddrs.h>

namespace std{


static std::vector<WifiInfo_t *> WifiInfo;
static Mutex sLock;

//


bool MyNetWorkingListener::getWifiStatus()
{
	return bWifiStartup;
}

MyNetWorkingListener::MyNetWorkingListener()
{
	LOGD("MyNetWorkingListener init	!!!");
	bConnecting = false;
	bConnectOtherAp = false;
	bConnected = false;
	m_need_bind = false;
	ssid = "";
	psd = "";
	nwListener.clear();
	bWifiStartup = (MACHINESTATUS->getwifistatus() == 1)?true : false;
	scanCount = -1;
	connectingTimeCount = 0;
	CheckconnectingTimeCount = 0;
	bFirstRefresh = false;
	bWifiProcessIsRun = false;
	if(bWifiStartup)
		system("ifconfig wlan0 up");
	else
		system("ifconfig wlan0 down");


}
MyNetWorkingListener::~MyNetWorkingListener()
{

}


void MyNetWorkingListener::setNetWorkListener(MyNetWorkListener *listener)
{
	Mutex::Autolock _l(sLock);

	if(listener != NULL)
	{
		int exitflag = false;
		if(nwListener.size() > 0)
		{
			std::vector<MyNetWorkListener*>::iterator iter = nwListener.begin();
			for(;iter != nwListener.end();iter++)
			{
				if((*iter) == listener)
					exitflag = true;
			}
		}
		if(!exitflag)
			nwListener.push_back(listener);
	}
//	LOGD("MyNetWorkingListener setNetWorkListener 	!!!");
}

void MyNetWorkingListener::removeNetWorkListener(MyNetWorkListener *listener)
{
	Mutex::Autolock _l(sLock);
	if(this->nwListener.size() <= 0)
		return;

	if(listener != NULL)
	{
		std::vector<MyNetWorkListener*>::iterator iter = this->nwListener.begin();
		for(;iter != this->nwListener.end();iter++)
		{
			if((*iter) == listener)
			{
				this->nwListener.erase(iter);
				return;
			}
		}
	}
}

void MyNetWorkingListener::notifyNetWorkListener(int type , void *data) {
	Mutex::Autolock _l(sLock);
	if(this->nwListener.size() <= 0) {
		return;
	}
	std::vector<MyNetWorkListener*>::iterator iter = this->nwListener.begin();
	for (; iter != this->nwListener.end(); iter++) {
		(*iter)->MyNetworkNotify(type, data);
	}
}

bool MyNetWorkingListener::IsConnected()
{
	return bConnected;
}
std::string& MyNetWorkingListener::getSSID()
{
	return ssid;
}
std::string& MyNetWorkingListener::getSSIDConnecting()
{
	return ssidconnecting;
}
std::string& MyNetWorkingListener::getPSD()
{
	return psd;
}


void MyNetWorkingListener::startConnectWifi(char *Ssid, char *psd)
{
	char cmd[256];
	WifiInfo_t *child;
	bool found;
	for(int i = 0;i < WifiInfo.size();i++)
	{
		child = WifiInfo.at(i);
		if(!strcmp(child->ssid, Ssid))
		{
			found = true;
			break;
		}
	}
	if(!found)
		return;

	/*判断之前的SSID和PSW是否符合连接	(open)*/
	char *old_ssid = MACHINESTATUS->getwifissid();
	char *old_psd = MACHINESTATUS->getwifipasswd();
	if((strcmp(old_ssid, Ssid) != 0) || (strcmp(old_psd, psd) != 0))
	{
		MACHINESTATUS->setwifissid(Ssid);
		MACHINESTATUS->setwifipasswd(psd);
	}

	//
	ssid = "";
	ssidconnecting = std::string(Ssid);
	system("/customer/wpa_cli -p/var/run/wpa_supplicant -iwlan0 remove_network 0");
	system("/customer/wpa_cli -p/var/run/wpa_supplicant -iwlan0 add_network");
	sprintf(cmd , "\"%s\"",Ssid);
	if(fork() == 0) {
		if(execl("/customer/wpa_cli", "wpa_cli" , "-p/var/run/wpa_supplicant" , "-iwlan0" , "set_network" , "0" , "ssid" , cmd, NULL) < 0) {
			perror("Err on execv");
		}
	}
	if(strlen(psd) == 64)
	{
		if(fork() == 0) {
			if(execl("/customer/wpa_cli", "wpa_cli" , "-p/var/run/wpa_supplicant" , "-iwlan0" , "set_network" , "0" , "psk" , psd, NULL) < 0) {
				perror("Err on execv1");
			}
		}
	}
	else
	{
		sprintf(cmd , "\"%s\"",psd);
		if(fork() == 0) {
			if(execl("/customer/wpa_cli", "wpa_cli" , "-p/var/run/wpa_supplicant" , "-iwlan0" , "set_network" , "0" , "psk" , cmd, NULL) < 0) {
				perror("Err on execv2");
			}
		}
	}
	if(strstr(child->flags , "WPA2-PSK")) {
		system("/customer/wpa_cli -p/var/run/wpa_supplicant -iwlan0 set_network 0 key_mgmt WPA-PSK");
//		system("/customer/wpa_cli -p/var/run/wpa_supplicant -iwlan0 set_network 0 proto WPA2");
	}
	else if(strstr(child->flags , "WPA-PSK")) {
		system("/customer/wpa_cli -p/var/run/wpa_supplicant -iwlan0 set_network 0 key_mgmt WPA-PSK");
//		system("/customer/wpa_cli -p/var/run/wpa_supplicant -iwlan0 set_network 0 proto WPA");
	}

	if(strstr(child->flags , "CCMP")) {
		system("/customer/wpa_cli -p/var/run/wpa_supplicant -iwlan0 set_network 0 pairwise CCMP");
	}
	else if(strstr(child->flags , "TKIP")) {
		system("/customer/wpa_cli -p/var/run/wpa_supplicant -iwlan0 set_network 0 pairwise TKIP");
	}

	system("/customer/wpa_cli -p/var/run/wpa_supplicant -iwlan0 select_network 0");
	system("/customer/wpa_cli -p/var/run/wpa_supplicant -iwlan0 enable_network 0");
	system("/customer/wpa_cli -p/var/run/wpa_supplicant -iwlan0 save_config");

	bConnecting = true;
	bConnectOtherAp = true;
	bConnected = false;
	connectingTimeCount = 0;
}



void MyNetWorkingListener::ScanNetWork()
{
	system("/customer/wpa_cli -i wlan0 -p/var/run/wpa_supplicant scan");
	scanCount = 1;
//	LOGD("start scan network !!!\n ");
}

void MyNetWorkingListener::firstfresh()
{
	bFirstRefresh = true;
}
void MyNetWorkingListener::getNetWorkInfo()
{

}
void MyNetWorkingListener::setNetWorkInfo()
{

}
void* MyNetWorkingListener::getSSIDInfo()
{
	return (void *)&WifiInfo;
}


void MyNetWorkingListener::resetScanCount()
{
	if(scanCount > 50 || scanCount <= 0)
		ScanNetWork();
}
void MyNetWorkingListener::startupWifi()
{
	if(bWifiStartup)
		return;

	MACHINESTATUS->setwifistatus(1);
	bConnecting = true;
	bWifiStartup = true;
	bConnected = false;
	system("ifconfig wlan0 up");
	ScanNetWork();
}
void MyNetWorkingListener::ShutdownWifi()
{
	if(!bWifiStartup)
		return;

	ssid = "";
	system("ifconfig wlan0 down &");
	WifiInfo.clear();
	notifyNetWorkListener(NW_NOTIFY_TYPE_CONNECT_STATUS, 0);

	MACHINESTATUS->setwifistatus(0);
	bConnecting = false;
	bWifiStartup = false;
	bConnected = false;
	scanCount = -1;
}

int MyNetWorkingListener::getWifiConnectStatus()
{
	if(bConnected)
	{
		return 2;
	}
	else if(bConnecting)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int ScanTabData(const char *s, char *data[], int n)
{
	int i = 0;
	char *start = s;
	while(1)
	{
		if((*s == '\t') || ((*s == '\0')))
		{
			if(i >= n)
				return -1;

			int Length = s - start;
			memcpy(data[i], start, Length);
			if((data[i][Length-1] == '\n') || (data[i][Length-1] == '\t'))
			{
				data[i][Length-1] = '\0';
			}
			else
			{
				data[i][Length] = '\0';
			}
			i++;
			if(*s == '\0')
				return i;
			s++;
			start = s;
		}
		else
		{
			s++;
		}
	}
	return 0;
}

int Hex2Dec(char c)
{
	if ('0' <= c && c <= '9')
	{
		return c - '0';
	}
	else if ('a' <= c && c <= 'f')
	{
		return c - 'a' + 10;
	}
	else if ('A' <= c && c <= 'F')
	{
		return c - 'A' + 10;
	}
	else
	{
		return -1;
	}
}

void URLDecode(char url[])
{
	int len = strlen(url);
	int res_len = 0;
	char res[256];
	if(strlen(url) == 0)
		return;
	for(int i = 0;i < len;i++)
	{
		char c = url[i];
		if(i < len - 3)
		{
			if(url[i] != '\\' || url[i+1] != 'x')
			{
				res[res_len++] = c;
			}
			else
			{
				i++;
				char c1 = url[++i];
				char c0 = url[++i];
				int num = 0;
				num = Hex2Dec(c1) * 16 + Hex2Dec(c0);
				res[res_len++] = num;
			}
		}
		else
		{
			res[res_len++] = c;
		}
	}
	res[res_len] = '\0';
	strcpy(url, res);
	memset(res, 0, 256);
	len = strlen(url);
	res_len = 0;
	for(int j = 0;j < len;j++)
	{
		char c = url[j];
		if(j < len - 1)
		{
			if(url[j] == '\\')
			{
				res[res_len++] = url[j+1];
				j++;
			}
			else
			{
				res[res_len++] = c;
			}
		}
		else
		{
			res[res_len++] = c;
		}
	}
	res[res_len] = '\0';
	strcpy(url, res);
}

/*
 * 判断Wifi是否重复
 * */
bool WifiRepeated(char *ssid)
{
	bool result = false;
	if(WifiInfo.size() == 0 || ssid ==NULL || strlen(ssid) == 0)
	{
		return false;
	}
	for(int i = 0;i < WifiInfo.size();i++)
	{
		WifiInfo_t *child = WifiInfo.at(i);
		if(!strcmp(child->ssid, ssid))
			result = true;
	}
	return  result;
}

bool checkWifiProcessState(const char *procName)
{
	int count = 0;
	char command[200];
	char buf[100];
	FILE* fp = NULL;
	sprintf(command, "ps -ef|grep %s|grep -v grep |wc -l", procName);
	if((fp = popen(command, "r")) == NULL) {
		return false;
	}
	if((fgets(buf, 100, fp)) != NULL) {
		count = atoi(buf);
	}
	pclose(fp);
	fp = NULL;
	if (count == 0) {
		return false;
	}
	return true;
}



bool MyNetWorkingListener::threadLoop()
{
//	LOGD("MyNetWorkingListener  threadLoop !!!\n");
	FILE *fp = NULL;
	char stringLine[4096];
	char *info[5];
	if(!bWifiStartup)
		goto END;


	if(scanCount > 0)
	{
		scanCount++;
		if(scanCount > 50 || (bFirstRefresh && scanCount > 20))
		{
			system("rm /tmp/info.txt");
			system("/customer/wpa_cli -i wlan0 -p/var/run/wpa_supplicant scan_results > /tmp/info.txt");
//			LOGD("scan_results  >  /tmp/info.txt !!!\n");

			fp = fopen("/tmp/info.txt", "r");
			if(fp == NULL)
			{
				LOGD("fopen /tmp/info.txt error \n");
			}
			else
			{
				fgets(stringLine, 1024, fp);
				info[0] = malloc(256);
				info[1] = malloc(256);
				info[2] = malloc(256);
				info[3] = malloc(256);
				info[4] = malloc(256);

				for(int i = 0;i < WifiInfo.size();i++)
				{
					WifiInfo_t *child = WifiInfo.at(i);
					free(child);
					child = NULL;
				}
				WifiInfo.clear();
				while(!feof(fp))				//feof(fp)功能是检测流上的文件结束符，如果文件结束，则返回非0值，否则返回0
				{
					/*char *fgets(char *str, int n, FILE *stream) 从指定的流 stream 读取一行，
					并把它存储在 str 所指向的字符串内。当读取 (n-1) 个字符时，或者读取到换行符时，或者到达文件末尾时，它会停止*/
					fgets(stringLine, 1024, fp);
					int n = ScanTabData(stringLine, (char **)info, strlen(stringLine));
					URLDecode(info[4]);
					if(WifiRepeated(info[4]) || !strlen(info[4]))
					{
						continue;
					}
					WifiInfo_t *child = malloc(sizeof(WifiInfo_t));
					strcpy(child->bssid, info[0]);
					child->freq = atoi(info[1]);
					child->signal = atoi(info[2]);
					strcpy(child->flags, info[3]);
					strcpy(child->ssid, info[4]);
					if(!strcmp(child->ssid, ssid.c_str()))
						WifiInfo.insert(WifiInfo.begin(), child);
					else
						WifiInfo.push_back(child);

				}
				free(info[0]);
				free(info[1]);
				free(info[2]);
				free(info[3]);
				free(info[4]);
				info[0] = NULL;
				info[1] = NULL;
				info[2] = NULL;
				info[3] = NULL;
				info[4] = NULL;
				fclose(fp);
				fp = NULL;
				scanCount = -1;

				notifyNetWorkListener(NW_NOTIFY_TYPE_SSIDS_INFO, &WifiInfo);

			}
			if(bFirstRefresh)
			{
				bFirstRefresh = true;
				scanCount = -1;
			}

		}
	}

	if(CheckconnectingTimeCount > 50 || (bConnecting && (CheckconnectingTimeCount > 10)))
	{
		CheckconnectingTimeCount = 0;
		system("/customer/wpa_cli -iwlan0 -p/var/run/wpa_supplicant status> /tmp/status.txt");
//		LOGD("status  >  /tmp/status.txt !!!\n");
		FILE *fp = fopen("/tmp/status.txt" , "r");
		if(fp != NULL)
		{
			char buf[1024];
			int ret = fread(buf, 1, 1024, fp);
			buf[ret] = 0;
			if(ret > 0)
			{
				if(strstr(buf , "wpa_state=COMPLETED"))
				{
					char apName[256];
					char *tmp;
					int i = 0;
					if(tmp = strstr(buf , "bssid="))
					{
						WifiInfo_t *child = malloc(sizeof(WifiInfo_t));
						//bssid
						tmp += 6;
						while((*tmp != '\r') && (*tmp != '\n') && (*tmp != 0))
						{
							child->bssid[i] = *tmp;
							i++;
							tmp++;
						}
						//freq
						i = 0;
						tmp = strstr(tmp, "freq=");
						tmp += 5;
						char freq[32];
						while((*tmp != '\r') && (*tmp != '\n') && (*tmp != 0)) {
							freq[i] = *tmp;
							i++;
							tmp++;
						}
						freq[i] = 0;
						child->freq = atoi(freq);
						//ssid
						i = 0;
						tmp = strstr(tmp , "ssid=");
						tmp += 5;
						while((*tmp != '\r') && (*tmp != '\n') && (*tmp != 0)) {
							apName[i] = *tmp;
							i++;
							tmp++;
						}
						apName[i] = 0;
						URLDecode(apName);
						this->ssid = apName;
						strcpy(child->ssid, apName);
						//flags
						i = 0;
						tmp = strstr(tmp , "key_mgmt=");
						tmp += 9;
						while((*tmp != '\r') && (*tmp != '\n') && (*tmp != 0)) {
							child->flags[i] = *tmp;
							i++;
							tmp++;
						}
						bool isexist = false;
						for(int i = 0;i < WifiInfo.size();i++)
						{
							WifiInfo_t *child = WifiInfo.at(i);
							if(!strcmp(child->ssid, ssid.c_str()))
							{
								isexist = true;
								break;
							}
						}
						if(!isexist)
						{
							WifiInfo.insert(WifiInfo.begin(), child);
						}
						else
						{
							free(child);
							child = NULL;
						}
					}
					if(bConnecting && !bConnected)
					{
						bConnecting = false;
						bConnected = true;
						bConnectOtherAp = false;
						connectingTimeCount = 0;
						system("udhcpc -i wlan0 -s /etc/init.d/udhcpc.script &");
						LOGD("udhcpc.script !!!\n");
						notifyNetWorkListener(NW_NOTIFY_TYPE_CONNECT_STATUS, (void *)1);

					}
					else if(!bConnecting && !bConnected)
					{
						bConnecting = false;
						bConnected = true;
						bConnectOtherAp = false;
						connectingTimeCount = 0;
						system("udhcpc -i wlan0 -s /etc/init.d/udhcpc.script &");
						LOGD("udhcpc.script111 !!!\n");
//						system("/customer/ntpdate -u ntp1.aliyun.com&");				//1bz
						notifyNetWorkListener(NW_NOTIFY_TYPE_CONNECT_STATUS, (void *)1);

					}
					else
					{
						bConnecting = false;
						bConnected = true;
						bConnectOtherAp = false;
						connectingTimeCount = 0;
					}
				}
				else if(strstr(buf , "wpa_state=INTERFACE_DISABLED"))
				{
					/*判断文件是否存在，并判断文件是否可写
					 * 如果文件具有指定的访问权限，则函数返回0；如果文件不存在或者不能访问指定的权限，则返回-1*/
					if(access("/proc/net/rtl8188eu/wlan0", F_OK) == -1)
					{
						notifyNetWorkListener(NW_NOTIFY_TYPE_HW_ERROR, 0);
						return false;
					}
				}
				else if(bConnected)
				{
					bConnected = false;
					ssid = "";
					notifyNetWorkListener(NW_NOTIFY_TYPE_CONNECT_STATUS, 0);
					system("killall udhcpc");
				}
				else
				{
//					LOGD("wifi not connect other status\n");
					bConnected = false;
				}

				if(bConnectOtherAp)
				{
					if(connectingTimeCount >= 10)
					{
						bConnectOtherAp = false;
						connectingTimeCount = 0;
						ssidconnecting = "";
						notifyNetWorkListener(NW_NOTIFY_TYPE_CONNECT_STATUS, (void*)-1);
					}
					connectingTimeCount++;
				}
			}
		}
		fclose(fp);
	}
	CheckconnectingTimeCount++;
	if(CheckconnectingTimeCount >= 50)
	{
		while (!(bWifiProcessIsRun = checkWifiProcessState("/customer/wpa_supplicant"))) {
			LOGD("wpa_supplicant  >  /wpa_supplicant.conf !!!\n");
			system("/customer/wpa_supplicant -Dnl80211 -iwlan0 -c /appconfigs/wpa_supplicant.conf &");
			Thread::sleep(100);
			break;
		}
	}
END:
	Thread::sleep(100);
	return true;
}


};














