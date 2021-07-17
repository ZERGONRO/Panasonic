/***********************************************
/gen auto by zuitools
***********************************************/
#ifndef __TIMINGACTIVITY_H__
#define __TIMINGACTIVITY_H__


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
#define ID_TIMING_TextViewStage2ColorFill    50092
#define ID_TIMING_TextViewStage1ColorFill    50091
#define ID_TIMING_Button1    20004
#define ID_TIMING_TextViewPics2    50010
#define ID_TIMING_TextViewPics1    50009
#define ID_TIMING_TextView9    50090
#define ID_TIMING_TextView8    50089
#define ID_TIMING_TextViewHumidity    50099
#define ID_TIMING_TextView85    50098
#define ID_TIMING_Window23    110039
#define ID_TIMING_TextViewFreshair    50097
#define ID_TIMING_TextView84    50096
#define ID_TIMING_WindowFreshAir    110038
#define ID_TIMING_TextViewAir    50095
#define ID_TIMING_TextView81    50094
#define ID_TIMING_WindowAircondition    110037
#define ID_TIMING_WindowNavibar2    110032
#define ID_TIMING_TextView83    50086
#define ID_TIMING_TextView82    50085
#define ID_TIMING_TextView74    50084
#define ID_TIMING_ButtonReturn    20003
#define ID_TIMING_WindowSettingTimeError    110012
#define ID_TIMING_TextViewPic2    50088
#define ID_TIMING_TextViewPic1    50087
#define ID_TIMING_TextViewNoTiming    50083
#define ID_TIMING_ButtonBack    20001
#define ID_TIMING_TextView80    50082
#define ID_TIMING_TextView79    50081
#define ID_TIMING_TextView78    50080
#define ID_TIMING_TextView77    50079
#define ID_TIMING_TextView76    50078
#define ID_TIMING_TextView75    50077
#define ID_TIMING_TextViewParal    50076
#define ID_TIMING_TextViewVer    50075
#define ID_TIMING_WindowTimeWave    110011
#define ID_TIMING_WindowHumTime2    110010
#define ID_TIMING_WindowHumTime1    110009
#define ID_TIMING_WindowWindTime2    110008
#define ID_TIMING_WindowWindTime1    110007
#define ID_TIMING_WindowAirHum2    110006
#define ID_TIMING_WindowAirHum1    110005
#define ID_TIMING_WindowTime    110004
#define ID_TIMING_WindowTOP    110002
#define ID_TIMING_WindowBG    110001
#define ID_TIMING_TextViewWifi    50008
#define ID_TIMING_ButtonDropDown    20021
#define ID_TIMING_TextView73    50074
#define ID_TIMING_TextView72    50073
#define ID_TIMING_TextView71    50072
#define ID_TIMING_TextView70    50071
#define ID_TIMING_TextView69    50070
#define ID_TIMING_TextView68    50069
#define ID_TIMING_TextView67    50068
#define ID_TIMING_TextView66    50067
#define ID_TIMING_TextView65    50066
#define ID_TIMING_TextView64    50065
#define ID_TIMING_TextView63    50064
#define ID_TIMING_TextView62    50063
#define ID_TIMING_TextView61    50062
#define ID_TIMING_TextView60    50061
#define ID_TIMING_TextView59    50060
#define ID_TIMING_TextView58    50059
#define ID_TIMING_TextView57    50058
#define ID_TIMING_TextView56    50057
#define ID_TIMING_TextView55    50056
#define ID_TIMING_TextView54    50055
#define ID_TIMING_TextView53    50054
#define ID_TIMING_TextView52    50053
#define ID_TIMING_TextView51    50052
#define ID_TIMING_TextView50    50051
#define ID_TIMING_TextView49    50050
#define ID_TIMING_TextView48    50049
#define ID_TIMING_TextView47    50048
#define ID_TIMING_TextView46    50047
#define ID_TIMING_TextView45    50046
#define ID_TIMING_TextView44    50045
#define ID_TIMING_TextView43    50044
#define ID_TIMING_TextView42    50043
#define ID_TIMING_TextView41    50042
#define ID_TIMING_TextView40    50041
#define ID_TIMING_TextView39    50040
#define ID_TIMING_TextView38    50039
#define ID_TIMING_TextView37    50038
#define ID_TIMING_TextView36    50037
#define ID_TIMING_TextView35    50036
#define ID_TIMING_TextView34    50035
#define ID_TIMING_TextView33    50034
#define ID_TIMING_TextView32    50033
#define ID_TIMING_TextView31    50032
#define ID_TIMING_TextView30    50031
#define ID_TIMING_TextView29    50030
#define ID_TIMING_TextView28    50029
#define ID_TIMING_TextView27    50028
#define ID_TIMING_TextView26    50027
#define ID_TIMING_TextView25    50026
#define ID_TIMING_TextView24    50025
#define ID_TIMING_TextView23    50024
#define ID_TIMING_TextView22    50023
#define ID_TIMING_TextView21    50022
#define ID_TIMING_TextView20    50021
#define ID_TIMING_TextView19    50020
#define ID_TIMING_TextView18    50019
#define ID_TIMING_TextView17    50018
#define ID_TIMING_TextView16    50017
#define ID_TIMING_TextView15    50016
#define ID_TIMING_TextView14    50015
#define ID_TIMING_TextView13    50014
#define ID_TIMING_TextView12    50013
#define ID_TIMING_TextView11    50012
#define ID_TIMING_TextView10    50011
#define ID_TIMING_TextView7    50007
#define ID_TIMING_TextView6    50006
#define ID_TIMING_TextView5    50005
#define ID_TIMING_TextView4    50004
#define ID_TIMING_TextView3    50003
#define ID_TIMING_TextView2    50002
#define ID_TIMING_Window3    110003
#define ID_TIMING_Button6    20005
#define ID_TIMING_Button2    20002
#define ID_TIMING_TextView1    50001
/*TAG:Macro宏ID END*/

class TimingActivity : public Activity, 
                     public ZKSeekBar::ISeekBarChangeListener, 
                     public ZKListView::IItemClickListener,
                     public ZKListView::AbsListAdapter,
                     public ZKSlideWindow::ISlideItemClickListener,
                     public EasyUIContext::ITouchListener,
                     public ZKEditText::ITextChangeListener,
                     public ZKVideoView::IVideoPlayerMessageListener
{
public:
    TimingActivity();
    virtual ~TimingActivity();

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