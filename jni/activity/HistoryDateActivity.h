/***********************************************
/gen auto by zuitools
***********************************************/
#ifndef __HISTORYDATEACTIVITY_H__
#define __HISTORYDATEACTIVITY_H__


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
#define ID_HISTORYDATE_TextViewHumidity    50158
#define ID_HISTORYDATE_TextView103    50157
#define ID_HISTORYDATE_Window23    110039
#define ID_HISTORYDATE_TextViewFreshair    50156
#define ID_HISTORYDATE_TextView101    50155
#define ID_HISTORYDATE_WindowFreshAir    110038
#define ID_HISTORYDATE_TextViewAir    50154
#define ID_HISTORYDATE_TextView90    50153
#define ID_HISTORYDATE_WindowAircondition    110037
#define ID_HISTORYDATE_TextViewmcu    50152
#define ID_HISTORYDATE_TextViewHistory2    50151
#define ID_HISTORYDATE_ButtonHistorty2    20122
#define ID_HISTORYDATE_Window22    110036
#define ID_HISTORYDATE_TextViewManual2    50142
#define ID_HISTORYDATE_ButtonManual2    20121
#define ID_HISTORYDATE_Window21    110035
#define ID_HISTORYDATE_TextViewSmart2    50140
#define ID_HISTORYDATE_ButtonSmart2    20120
#define ID_HISTORYDATE_Window20    110034
#define ID_HISTORYDATE_TextViewHomepage2    50138
#define ID_HISTORYDATE_ButtonHomepage2    20119
#define ID_HISTORYDATE_Window19    110033
#define ID_HISTORYDATE_WindowNavibar5    110032
#define ID_HISTORYDATE_TextViewPicTemp1    50136
#define ID_HISTORYDATE_TextViewPicCO21    50134
#define ID_HISTORYDATE_TextViewPicJQ1    50132
#define ID_HISTORYDATE_TextViewPicPM251    50130
#define ID_HISTORYDATE_TextViewPicHumd1    50119
#define ID_HISTORYDATE_WindowTempHumdWave    110015
#define ID_HISTORYDATE_TextView121    50150
#define ID_HISTORYDATE_TextView120    50149
#define ID_HISTORYDATE_TextView119    50148
#define ID_HISTORYDATE_TextView118    50147
#define ID_HISTORYDATE_TextView117    50146
#define ID_HISTORYDATE_TextView116    50145
#define ID_HISTORYDATE_TextView115    50144
#define ID_HISTORYDATE_TextView114    50143
#define ID_HISTORYDATE_TextView112    50141
#define ID_HISTORYDATE_TextView110    50139
#define ID_HISTORYDATE_TextView108    50137
#define ID_HISTORYDATE_TextView106    50135
#define ID_HISTORYDATE_TextView104    50133
#define ID_HISTORYDATE_TextView102    50131
#define ID_HISTORYDATE_TextView92    50121
#define ID_HISTORYDATE_TextView88    50117
#define ID_HISTORYDATE_TextView86    50115
#define ID_HISTORYDATE_TextView84    50113
#define ID_HISTORYDATE_TextView82    50111
#define ID_HISTORYDATE_TextView80    50109
#define ID_HISTORYDATE_TextView79    50108
#define ID_HISTORYDATE_WindowCO2PM25JQMonth    110018
#define ID_HISTORYDATE_TextView100    50129
#define ID_HISTORYDATE_TextView99    50128
#define ID_HISTORYDATE_TextView98    50127
#define ID_HISTORYDATE_TextView97    50126
#define ID_HISTORYDATE_TextView96    50125
#define ID_HISTORYDATE_TextView95    50124
#define ID_HISTORYDATE_TextView94    50123
#define ID_HISTORYDATE_TextView93    50122
#define ID_HISTORYDATE_TextView91    50120
#define ID_HISTORYDATE_TextView89    50118
#define ID_HISTORYDATE_TextView87    50116
#define ID_HISTORYDATE_TextView85    50114
#define ID_HISTORYDATE_TextView83    50112
#define ID_HISTORYDATE_TextView81    50110
#define ID_HISTORYDATE_TextView78    50107
#define ID_HISTORYDATE_TextView77    50106
#define ID_HISTORYDATE_TextView76    50105
#define ID_HISTORYDATE_TextView75    50104
#define ID_HISTORYDATE_TextView74    50103
#define ID_HISTORYDATE_TextView73    50102
#define ID_HISTORYDATE_TextView72    50098
#define ID_HISTORYDATE_TextView51    50077
#define ID_HISTORYDATE_WindowCO2HumdWaveMonth    110017
#define ID_HISTORYDATE_TextViewPicBad    50022
#define ID_HISTORYDATE_TextViewPicMid    50021
#define ID_HISTORYDATE_TextViewPicMidGood    50020
#define ID_HISTORYDATE_TextViewPicGood    50019
#define ID_HISTORYDATE_TextViewmgm3    50101
#define ID_HISTORYDATE_TextViewugm3    50100
#define ID_HISTORYDATE_TextViewppm    50099
#define ID_HISTORYDATE_TextView71    50097
#define ID_HISTORYDATE_TextView70    50096
#define ID_HISTORYDATE_TextView69    50095
#define ID_HISTORYDATE_TextView68    50094
#define ID_HISTORYDATE_TextView67    50093
#define ID_HISTORYDATE_TextView66    50092
#define ID_HISTORYDATE_TextView65    50091
#define ID_HISTORYDATE_TextView64    50090
#define ID_HISTORYDATE_TextView63    50089
#define ID_HISTORYDATE_TextView62    50088
#define ID_HISTORYDATE_TextView61    50087
#define ID_HISTORYDATE_TextView60    50086
#define ID_HISTORYDATE_TextView59    50085
#define ID_HISTORYDATE_TextView58    50084
#define ID_HISTORYDATE_TextView57    50083
#define ID_HISTORYDATE_TextView56    50082
#define ID_HISTORYDATE_TextView55    50081
#define ID_HISTORYDATE_TextView54    50080
#define ID_HISTORYDATE_TextView53    50079
#define ID_HISTORYDATE_TextView52    50078
#define ID_HISTORYDATE_TextView50    50076
#define ID_HISTORYDATE_TextView49    50075
#define ID_HISTORYDATE_TextView48    50074
#define ID_HISTORYDATE_TextView47    50073
#define ID_HISTORYDATE_TextView46    50072
#define ID_HISTORYDATE_TextView45    50071
#define ID_HISTORYDATE_WindowCO2PM25JQ    110016
#define ID_HISTORYDATE_TextViewHumd    50070
#define ID_HISTORYDATE_TextViewTemp    50069
#define ID_HISTORYDATE_TextView44    50068
#define ID_HISTORYDATE_TextView43    50067
#define ID_HISTORYDATE_TextView42    50066
#define ID_HISTORYDATE_TextView41    50065
#define ID_HISTORYDATE_TextView40    50064
#define ID_HISTORYDATE_TextView21    50063
#define ID_HISTORYDATE_TextView20    50062
#define ID_HISTORYDATE_TextView19    50061
#define ID_HISTORYDATE_TextView18    50060
#define ID_HISTORYDATE_TextView5    50059
#define ID_HISTORYDATE_TextView4    50058
#define ID_HISTORYDATE_TextView3    50057
#define ID_HISTORYDATE_TextView2    50056
#define ID_HISTORYDATE_TextView1    50055
#define ID_HISTORYDATE_TextViewvertical7    50054
#define ID_HISTORYDATE_TextViewvertical6    50053
#define ID_HISTORYDATE_TextViewvertical5    50052
#define ID_HISTORYDATE_TextViewvertical4    50051
#define ID_HISTORYDATE_TextViewvertical3    50050
#define ID_HISTORYDATE_TextViewvertical2    50049
#define ID_HISTORYDATE_TextViewvertical1    50048
#define ID_HISTORYDATE_TextViewparallel5    50047
#define ID_HISTORYDATE_TextViewparallel4    50046
#define ID_HISTORYDATE_TextViewparallel3    50045
#define ID_HISTORYDATE_TextViewparallel2    50044
#define ID_HISTORYDATE_TextViewparallel1    50043
#define ID_HISTORYDATE_TextViewparallel    50042
#define ID_HISTORYDATE_TextViewvertical    50041
#define ID_HISTORYDATE_WindowWave    110010
#define ID_HISTORYDATE_WindowMain    110001
#define ID_HISTORYDATE_TextViewWifi    50008
#define ID_HISTORYDATE_ButtonDropDown    20021
#define ID_HISTORYDATE_TextView39    50040
#define ID_HISTORYDATE_TextView38    50039
#define ID_HISTORYDATE_TextView37    50038
#define ID_HISTORYDATE_TextView36    50037
#define ID_HISTORYDATE_WindowFormalDedhy    110008
#define ID_HISTORYDATE_TextView17    50018
#define ID_HISTORYDATE_TextView16    50017
#define ID_HISTORYDATE_TextView15    50016
#define ID_HISTORYDATE_TextView14    50015
#define ID_HISTORYDATE_Window7    110007
#define ID_HISTORYDATE_TextView13    50014
#define ID_HISTORYDATE_TextView12    50013
#define ID_HISTORYDATE_TextView11    50012
#define ID_HISTORYDATE_TextView10    50011
#define ID_HISTORYDATE_Window6    110006
#define ID_HISTORYDATE_TextView9    50010
#define ID_HISTORYDATE_TextView8    50009
#define ID_HISTORYDATE_TextView7    50007
#define ID_HISTORYDATE_TextView6    50006
#define ID_HISTORYDATE_Window5    110005
#define ID_HISTORYDATE_WindowTempHumd    110004
#define ID_HISTORYDATE_TextView35    50036
#define ID_HISTORYDATE_TextView34    50035
#define ID_HISTORYDATE_ButtonMonth    20015
#define ID_HISTORYDATE_ButtonWeek    20014
#define ID_HISTORYDATE_ButtonDay    20013
#define ID_HISTORYDATE_WindowDate    110014
#define ID_HISTORYDATE_TextView33    50034
#define ID_HISTORYDATE_TextView32    50033
#define ID_HISTORYDATE_TextView31    50032
#define ID_HISTORYDATE_TextView30    50031
#define ID_HISTORYDATE_Window11    110013
#define ID_HISTORYDATE_TextView29    50030
#define ID_HISTORYDATE_TextView28    50029
#define ID_HISTORYDATE_TextView27    50028
#define ID_HISTORYDATE_TextView26    50027
#define ID_HISTORYDATE_Window10    110012
#define ID_HISTORYDATE_TextView25    50026
#define ID_HISTORYDATE_TextView24    50025
#define ID_HISTORYDATE_TextView23    50024
#define ID_HISTORYDATE_TextView22    50023
#define ID_HISTORYDATE_Window9    110011
#define ID_HISTORYDATE_WindowCO2PM25    110009
#define ID_HISTORYDATE_TextViewPicJQ    50005
#define ID_HISTORYDATE_TextViewPicPM25    50004
#define ID_HISTORYDATE_TextViewPicHumd    50003
#define ID_HISTORYDATE_TextViewPicCO2    50002
#define ID_HISTORYDATE_TextViewPicTemp    50001
#define ID_HISTORYDATE_WindowTap    110003
#define ID_HISTORYDATE_Buttonformaldehyde    20006
#define ID_HISTORYDATE_ButtonPM25    20005
#define ID_HISTORYDATE_ButtonCO2    20004
#define ID_HISTORYDATE_ButtonHumd    20003
#define ID_HISTORYDATE_ButtonTemp    20002
#define ID_HISTORYDATE_Window2    110002
/*TAG:Macro宏ID END*/

class HistoryDateActivity : public Activity, 
                     public ZKSeekBar::ISeekBarChangeListener, 
                     public ZKListView::IItemClickListener,
                     public ZKListView::AbsListAdapter,
                     public ZKSlideWindow::ISlideItemClickListener,
                     public EasyUIContext::ITouchListener,
                     public ZKEditText::ITextChangeListener,
                     public ZKVideoView::IVideoPlayerMessageListener
{
public:
    HistoryDateActivity();
    virtual ~HistoryDateActivity();

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