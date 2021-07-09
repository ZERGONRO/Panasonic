/***********************************************
/gen auto by zuitools
***********************************************/
#ifndef __MANUALMODE11ACTIVITY_H__
#define __MANUALMODE11ACTIVITY_H__


#include "app/Activity.h"
#include "entry/EasyUIContext.h"

#include "uart/ProtocolData.h"
#include "uart/ProtocolParser.h"

#include "utils/Log.h"
#include "control/ZKDigitalClock.h"
#include "control/ZKButton.h"
#include "control/ZKCircleBar.h"
#include "control/ZKDiagram.h"
#include "control/ZKListView.h"
#include "control/ZKPointer.h"
#include "control/ZKQRCode.h"
#include "control/ZKTextView.h"
#include "control/ZKSeekBar.h"
#include "control/ZKEditText.h"
#include "control/ZKVideoView.h"
#include "window/ZKSlideWindow.h"

/*TAG:Macro宏ID*/
#define ID_MANUALMODE11_SubItemYuBa    20089
#define ID_MANUALMODE11_ListViewYuBa    80007
#define ID_MANUALMODE11_TextView93    50102
#define ID_MANUALMODE11_SubItemSterl    20089
#define ID_MANUALMODE11_ListViewSterl    80006
#define ID_MANUALMODE11_TextView92    50101
#define ID_MANUALMODE11_SubItemWind    20089
#define ID_MANUALMODE11_ListViewWind    80005
#define ID_MANUALMODE11_TextView91    50100
#define ID_MANUALMODE11_SubItemHumd    20089
#define ID_MANUALMODE11_ListViewHumd    80004
#define ID_MANUALMODE11_TextView90    50099
#define ID_MANUALMODE11_SubItemHot    20089
#define ID_MANUALMODE11_ListViewHot    80003
#define ID_MANUALMODE11_TextView39    50039
#define ID_MANUALMODE11_SubItemAir    20089
#define ID_MANUALMODE11_ListViewAir    80002
#define ID_MANUALMODE11_TextView38    50038
#define ID_MANUALMODE11_TextView37    50037
#define ID_MANUALMODE11_SubItemAirPF    20089
#define ID_MANUALMODE11_ListViewAirPF    80001
#define ID_MANUALMODE11_ButtonTiming    20088
#define ID_MANUALMODE11_ButtonPicTime    20087
#define ID_MANUALMODE11_ButtonYubaSwitch    20083
#define ID_MANUALMODE11_ButtonSteriTimeSwitch    20081
#define ID_MANUALMODE11_ButtonSteriTimeSwitchPic    20080
#define ID_MANUALMODE11_ButtonSterilizationSwitch    20078
#define ID_MANUALMODE11_ButtonWindTimeSwitch    20060
#define ID_MANUALMODE11_ButtonWindTimeSwitchPic    20059
#define ID_MANUALMODE11_ButtonWindSwitch    20056
#define ID_MANUALMODE11_ButtonHumdTimeSwitch    20130
#define ID_MANUALMODE11_ButtonHumdTimeSwitchPic    20129
#define ID_MANUALMODE11_ButtonHumdSwitch    20127
#define ID_MANUALMODE11_ButtonHotCTimeSwitch    20029
#define ID_MANUALMODE11_ButtonHotCTimeSwitchPic    20028
#define ID_MANUALMODE11_ButtonHotCSwitch    20026
#define ID_MANUALMODE11_ButtonAirTimeSwitch    20126
#define ID_MANUALMODE11_ButtonAirTimeSwitchPic    20125
#define ID_MANUALMODE11_ButtonAirSwitch    20023
#define ID_MANUALMODE11_ButtonAirPFTimeSwitch    20011
#define ID_MANUALMODE11_ButtonAirPFTimeSwitchPic    20010
#define ID_MANUALMODE11_ButtonAirPFSwitch    20008
#define ID_MANUALMODE11_TextView63    50072
#define ID_MANUALMODE11_TextView62    50071
#define ID_MANUALMODE11_TextView61    50070
#define ID_MANUALMODE11_TextView57    50058
#define ID_MANUALMODE11_TextView56    50057
#define ID_MANUALMODE11_TextView55    50056
#define ID_MANUALMODE11_TextView54    50055
#define ID_MANUALMODE11_TextView53    50054
#define ID_MANUALMODE11_TextView52    50053
#define ID_MANUALMODE11_TextView51    50052
#define ID_MANUALMODE11_TextView50    50051
#define ID_MANUALMODE11_TextView49    50050
#define ID_MANUALMODE11_TextView48    50049
#define ID_MANUALMODE11_TextView47    50048
#define ID_MANUALMODE11_TextView46    50047
#define ID_MANUALMODE11_TextView45    50046
#define ID_MANUALMODE11_TextView44    50045
#define ID_MANUALMODE11_TextView43    50044
#define ID_MANUALMODE11_TextView42    50043
#define ID_MANUALMODE11_TextView41    50042
#define ID_MANUALMODE11_TextView40    50041
#define ID_MANUALMODE11_WindowIndoorEnv    110019
#define ID_MANUALMODE11_TextView89    50098
#define ID_MANUALMODE11_TextView88    50097
#define ID_MANUALMODE11_Button22    20084
#define ID_MANUALMODE11_Window9    110016
#define ID_MANUALMODE11_TextView87    50096
#define ID_MANUALMODE11_TextView86    50095
#define ID_MANUALMODE11_Button18    20079
#define ID_MANUALMODE11_Window8    110014
#define ID_MANUALMODE11_TextView85    50094
#define ID_MANUALMODE11_TextView84    50093
#define ID_MANUALMODE11_Button14    20058
#define ID_MANUALMODE11_Window6    110012
#define ID_MANUALMODE11_TextView83    50092
#define ID_MANUALMODE11_TextView82    50091
#define ID_MANUALMODE11_Button10    20128
#define ID_MANUALMODE11_TextView81    50090
#define ID_MANUALMODE11_TextView80    50089
#define ID_MANUALMODE11_TextView79    50088
#define ID_MANUALMODE11_Window4    110021
#define ID_MANUALMODE11_TextView78    50087
#define ID_MANUALMODE11_TextView77    50086
#define ID_MANUALMODE11_Button6    20027
#define ID_MANUALMODE11_Window3    110008
#define ID_MANUALMODE11_TextView76    50085
#define ID_MANUALMODE11_TextView75    50084
#define ID_MANUALMODE11_Button2    20124
#define ID_MANUALMODE11_TextView74    50083
#define ID_MANUALMODE11_TextView73    50082
#define ID_MANUALMODE11_TextView72    50081
#define ID_MANUALMODE11_Window2    110020
#define ID_MANUALMODE11_TextView71    50080
#define ID_MANUALMODE11_TextView70    50079
#define ID_MANUALMODE11_TextView69    50078
#define ID_MANUALMODE11_TextView68    50077
#define ID_MANUALMODE11_TextView67    50076
#define ID_MANUALMODE11_TextView66    50075
#define ID_MANUALMODE11_TextView65    50074
#define ID_MANUALMODE11_TextView64    50073
#define ID_MANUALMODE11_TextViewWifi    50040
#define ID_MANUALMODE11_ButtonDropDown    20123
#define ID_MANUALMODE11_TextViewHumidity    50069
#define ID_MANUALMODE11_TextView60    50068
#define ID_MANUALMODE11_Window23    110039
#define ID_MANUALMODE11_TextViewFreshair    50067
#define ID_MANUALMODE11_TextView59    50066
#define ID_MANUALMODE11_WindowFreshAir    110038
#define ID_MANUALMODE11_TextViewAir    50065
#define ID_MANUALMODE11_TextView58    50064
#define ID_MANUALMODE11_WindowAircondition    110037
#define ID_MANUALMODE11_TextViewmcu    50063
#define ID_MANUALMODE11_TextViewHistory2    50062
#define ID_MANUALMODE11_ButtonHistorty2    20122
#define ID_MANUALMODE11_Window22    110036
#define ID_MANUALMODE11_TextViewManual2    50061
#define ID_MANUALMODE11_ButtonManual2    20121
#define ID_MANUALMODE11_Window21    110035
#define ID_MANUALMODE11_TextViewSmart2    50060
#define ID_MANUALMODE11_ButtonSmart2    20120
#define ID_MANUALMODE11_Window20    110034
#define ID_MANUALMODE11_TextViewHomepage2    50059
#define ID_MANUALMODE11_ButtonHomepage2    20119
#define ID_MANUALMODE11_Window19    110033
#define ID_MANUALMODE11_WindowNavibar4    110032
#define ID_MANUALMODE11_ButtonYuBaChangAirWeak    20118
#define ID_MANUALMODE11_ButtonYuBaChangAirStr    20117
#define ID_MANUALMODE11_ButtonYuBaChangAirFast    20116
#define ID_MANUALMODE11_ButtonYuBaLightClose    20115
#define ID_MANUALMODE11_ButtonYuBaLightNight    20114
#define ID_MANUALMODE11_ButtonYuBaLightWeak    20113
#define ID_MANUALMODE11_ButtonYuBaLightStr    20112
#define ID_MANUALMODE11_ButtonYuBaColdHotWeak    20111
#define ID_MANUALMODE11_ButtonYuBaWindClassdiffusion    20110
#define ID_MANUALMODE11_ButtonYuBaColdHotStr    20109
#define ID_MANUALMODE11_ButtonYuBaWindClassConcen    20107
#define ID_MANUALMODE11_ButtonYuBaHottingWeak    20108
#define ID_MANUALMODE11_ButtonYuBaHottingStr    20102
#define ID_MANUALMODE11_ButtonYuBaWindDirectAuto    20101
#define ID_MANUALMODE11_ButtonYuBaWindDirectManual    20100
#define ID_MANUALMODE11_ButtonYuBaHeatingWeak    20099
#define ID_MANUALMODE11_ButtonYuBaHeatingStr    20098
#define ID_MANUALMODE11_ButtonYuBaLight    20097
#define ID_MANUALMODE11_ButtonYuBaChangAir    20106
#define ID_MANUALMODE11_ButtonYuBaColdHot    20105
#define ID_MANUALMODE11_ButtonYuBaWindClass    20104
#define ID_MANUALMODE11_ButtonYuBaNANOEX    20103
#define ID_MANUALMODE11_ButtonYuBaHotting    20096
#define ID_MANUALMODE11_ButtonYuBaWindDirect    20095
#define ID_MANUALMODE11_ButtonYuBaHeating    20094
#define ID_MANUALMODE11_WindowYubaSwitch    110017
#define ID_MANUALMODE11_TextView36    50036
#define ID_MANUALMODE11_TextView35    50035
#define ID_MANUALMODE11_TextView34    50034
#define ID_MANUALMODE11_WindowSterilization    110015
#define ID_MANUALMODE11_ButtonWindSwitchNANOEX    20091
#define ID_MANUALMODE11_ButtonWindSwitchAutoWindAdd    20086
#define ID_MANUALMODE11_ButtonWindSwitchAutoWindLess    20085
#define ID_MANUALMODE11_ButtonWindSwitchAutoWind    20082
#define ID_MANUALMODE11_TextView33    50033
#define ID_MANUALMODE11_TextView32    50032
#define ID_MANUALMODE11_TextView31    50031
#define ID_MANUALMODE11_WindowWindSwitch    110013
#define ID_MANUALMODE11_ButtonHumdSwitchWindClassDiff    20077
#define ID_MANUALMODE11_ButtonHumdSwitchWindClassConcen    20076
#define ID_MANUALMODE11_ButtonHumdSwitchFuncSelSend    20075
#define ID_MANUALMODE11_ButtonHumdSwitchFuncSelKeep    20074
#define ID_MANUALMODE11_ButtonHumdSwitchFuncSelCont    20073
#define ID_MANUALMODE11_ButtonHumdSwitchFuncSelAuto    20072
#define ID_MANUALMODE11_ButtonHumdSwitchWindClass    20071
#define ID_MANUALMODE11_ButtonHumdSwitchFuncSel    20070
#define ID_MANUALMODE11_TextView30    50030
#define ID_MANUALMODE11_TextView29    50029
#define ID_MANUALMODE11_ButtonHumdSwitchHumdSettingAdd    20069
#define ID_MANUALMODE11_ButtonHumdSwitchHumdSettingLess    20068
#define ID_MANUALMODE11_ButtonHumdSwitchWindDirectAdd    20067
#define ID_MANUALMODE11_ButtonHumdSwitchWindDirectLess    20066
#define ID_MANUALMODE11_ButtonHumdSwitchAutoWindAdd    20065
#define ID_MANUALMODE11_ButtonHumdSwitchAutoWindLess    20064
#define ID_MANUALMODE11_ButtonHumdSwitchHumdSetting    20063
#define ID_MANUALMODE11_ButtonHumdSwitchWindDirect    20062
#define ID_MANUALMODE11_ButtonHumdSwitchAutoWind    20061
#define ID_MANUALMODE11_TextView28    50028
#define ID_MANUALMODE11_TextView27    50027
#define ID_MANUALMODE11_TextView26    50026
#define ID_MANUALMODE11_WindowHumdSwitch    110011
#define ID_MANUALMODE11_ButtonHotChangeSwitchModeCycle    20051
#define ID_MANUALMODE11_ButtonHotChangeSwitchModeHotChange    20057
#define ID_MANUALMODE11_ButtonHotChangeSwitchNANOEX    20055
#define ID_MANUALMODE11_ButtonHotChangeSwitchModeAuto    20054
#define ID_MANUALMODE11_ButtonHotChangeSwitchAutoWindAdd    20053
#define ID_MANUALMODE11_ButtonHotChangeSwitchAutoWindLess    20052
#define ID_MANUALMODE11_ButtonHotChangeSwitchMode    20050
#define ID_MANUALMODE11_ButtonHotChangeSwitchAutoWind    20049
#define ID_MANUALMODE11_ButtonHotChangeSwitchPicTimeOpen    20048
#define ID_MANUALMODE11_ButtonHotChangeSwitchPicTime    20047
#define ID_MANUALMODE11_ButtonHotChangeSwitchSelect    20046
#define ID_MANUALMODE11_TextView25    50025
#define ID_MANUALMODE11_TextView24    50024
#define ID_MANUALMODE11_ButtonHotChangeSwitchOpen    20045
#define ID_MANUALMODE11_TextView23    50023
#define ID_MANUALMODE11_Window7    110010
#define ID_MANUALMODE11_WindowHotChangeSwitch    110009
#define ID_MANUALMODE11_TextView22    50022
#define ID_MANUALMODE11_ButtonAirSwitchTempSettingAdd    20044
#define ID_MANUALMODE11_ButtonAirSwitchTempSettingLess    20041
#define ID_MANUALMODE11_ButtonAirSwitchModeHumd    20040
#define ID_MANUALMODE11_ButtonAirSwitchModeCold    20039
#define ID_MANUALMODE11_ButtonAirSwitchModeHot    20038
#define ID_MANUALMODE11_ButtonAirSwitchModeAuto    20037
#define ID_MANUALMODE11_ButtonAirSwitchWindDirectLeftRight    20036
#define ID_MANUALMODE11_ButtonAirSwitchTempSetting    20043
#define ID_MANUALMODE11_ButtonAirSwitchNANOEX    20042
#define ID_MANUALMODE11_ButtonAirSwitchWindDirectUpDown    20035
#define ID_MANUALMODE11_ButtonAirSwitchAutoWindAdd    20034
#define ID_MANUALMODE11_ButtonAirSwitchAutoWindLess    20033
#define ID_MANUALMODE11_ButtonAirSwitchMode    20032
#define ID_MANUALMODE11_ButtonAirSwitchWindDirect    20031
#define ID_MANUALMODE11_ButtonAirSwitchAutoWind    20030
#define ID_MANUALMODE11_TextView21    50021
#define ID_MANUALMODE11_TextView20    50020
#define ID_MANUALMODE11_TextView19    50019
#define ID_MANUALMODE11_WindowAirSwitch    110007
#define ID_MANUALMODE11_ButtonAirPFChildLock    20025
#define ID_MANUALMODE11_ButtonAirPFFilterReset    20024
#define ID_MANUALMODE11_ButtonAirPFLight    20022
#define ID_MANUALMODE11_ButtonAirPFNANOEX    20021
#define ID_MANUALMODE11_TextView18    50018
#define ID_MANUALMODE11_TextView17    50017
#define ID_MANUALMODE11_ButtonAirPFHumdSettingAdd    20020
#define ID_MANUALMODE11_ButtonAirPFHumdSettingLess    20019
#define ID_MANUALMODE11_ButtonAirPFWindDirectAdd    20018
#define ID_MANUALMODE11_ButtonAirPFWindDirectLess    20017
#define ID_MANUALMODE11_ButtonAirPFAutoWindAdd    20016
#define ID_MANUALMODE11_ButtonAirPFAutoWindLess    20015
#define ID_MANUALMODE11_ButtonAirPFHumdSetting    20014
#define ID_MANUALMODE11_ButtonAirPFWindDirect    20013
#define ID_MANUALMODE11_ButtonAirPFAutoWind    20012
#define ID_MANUALMODE11_ButtonAirPFSelect    20009
#define ID_MANUALMODE11_TextView16    50016
#define ID_MANUALMODE11_TextView15    50015
#define ID_MANUALMODE11_TextView14    50014
#define ID_MANUALMODE11_Window5    110006
#define ID_MANUALMODE11_WindowAirPF    110005
#define ID_MANUALMODE11_ButtonYuBa    20007
#define ID_MANUALMODE11_ButtonSterilization    20006
#define ID_MANUALMODE11_ButtonChangeWind    20005
#define ID_MANUALMODE11_ButtonModHumd    20004
#define ID_MANUALMODE11_ButtonHotChange    20003
#define ID_MANUALMODE11_ButtonAir    20002
#define ID_MANUALMODE11_ButtonPurify    20001
#define ID_MANUALMODE11_WindowModeSelect    110004
#define ID_MANUALMODE11_TextView13    50013
#define ID_MANUALMODE11_TextView12    50012
#define ID_MANUALMODE11_TextView11    50011
#define ID_MANUALMODE11_TextView10    50010
#define ID_MANUALMODE11_TextView9    50009
#define ID_MANUALMODE11_TextView8    50008
#define ID_MANUALMODE11_TextView7    50007
#define ID_MANUALMODE11_TextView6    50006
#define ID_MANUALMODE11_TextView5    50005
#define ID_MANUALMODE11_TextView4    50004
#define ID_MANUALMODE11_TextView3    50003
#define ID_MANUALMODE11_TextView2    50002
#define ID_MANUALMODE11_TextView1    50001
#define ID_MANUALMODE11_WindowInsideStatus    110003
#define ID_MANUALMODE11_Window1    110002
#define ID_MANUALMODE11_WindowBG    110001
/*TAG:Macro宏ID END*/

class ManualMode11Activity : public Activity, 
                     public ZKSeekBar::ISeekBarChangeListener, 
                     public ZKListView::IItemClickListener,
                     public ZKListView::AbsListAdapter,
                     public ZKSlideWindow::ISlideItemClickListener,
                     public EasyUIContext::ITouchListener,
                     public ZKEditText::ITextChangeListener,
                     public ZKVideoView::IVideoPlayerMessageListener
{
public:
    ManualMode11Activity();
    virtual ~ManualMode11Activity();

    /**
     * 注册定时器
     */
	void registerUserTimer(int id, int time);
	/**
	 * 取消定时器
	 */
	void unregisterUserTimer(int id);
	/**
	 * 重置定时器
	 */
	void resetUserTimer(int id, int time);

protected:
    /*TAG:PROTECTED_FUNCTION*/
    virtual const char* getAppName() const;
    virtual void onCreate();
    virtual void onClick(ZKBase *pBase);
    virtual void onResume();
    virtual void onPause();
    virtual void onIntent(const Intent *intentPtr);
    virtual bool onTimer(int id);

    virtual void onProgressChanged(ZKSeekBar *pSeekBar, int progress);

    virtual int getListItemCount(const ZKListView *pListView) const;
    virtual void obtainListItemData(ZKListView *pListView, ZKListView::ZKListItem *pListItem, int index);
    virtual void onItemClick(ZKListView *pListView, int index, int subItemIndex);

    virtual void onSlideItemClick(ZKSlideWindow *pSlideWindow, int index);

    virtual bool onTouchEvent(const MotionEvent &ev);

    virtual void onTextChanged(ZKTextView *pTextView, const string &text);

    void rigesterActivityTimer();

    virtual void onVideoPlayerMessage(ZKVideoView *pVideoView, int msg);
    void videoLoopPlayback(ZKVideoView *pVideoView, int msg, size_t callbackTabIndex);
    void startVideoLoopPlayback();
    void stopVideoLoopPlayback();
    bool parseVideoFileList(const char *pFileListPath, std::vector<string>& mediaFileList);
    int removeCharFromString(string& nString, char c);


private:
    /*TAG:PRIVATE_VARIABLE*/
    int mVideoLoopIndex;
    int mVideoLoopErrorCount;

};

#endif