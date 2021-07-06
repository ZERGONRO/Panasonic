/***********************************************
/gen auto by zuitools
***********************************************/
#ifndef __SETTINGACTIVITY_H__
#define __SETTINGACTIVITY_H__


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
#define ID_SETTING_ButtonMasterSlaverSet1    20006
#define ID_SETTING_ButtonVoiceSysSet1    20002
#define ID_SETTING_ButtonBack    20011
#define ID_SETTING_TextView22    50022
#define ID_SETTING_TextView21    50021
#define ID_SETTING_TextView23    50023
#define ID_SETTING_TextView4    50004
#define ID_SETTING_TextView3    50003
#define ID_SETTING_ButtonConfirm    20013
#define ID_SETTING_ButtonCancel    20012
#define ID_SETTING_TextView2    50002
#define ID_SETTING_TextView1    50001
#define ID_SETTING_WindowReset2    110001
#define ID_SETTING_ButtonCtlSet1    20010
#define ID_SETTING_TextView43    50043
#define ID_SETTING_TextView42    50042
#define ID_SETTING_WindowCtlSet1    110021
#define ID_SETTING_ButtonReset1    20009
#define ID_SETTING_TextView41    50041
#define ID_SETTING_TextView40    50040
#define ID_SETTING_WindowReset1    110020
#define ID_SETTING_ButtonWifiSetting1    20008
#define ID_SETTING_TextView39    50039
#define ID_SETTING_TextView38    50038
#define ID_SETTING_WindowWifiSetting1    110019
#define ID_SETTING_ButtonFWUpdate1    20007
#define ID_SETTING_TextView37    50037
#define ID_SETTING_TextView36    50036
#define ID_SETTING_WindowFWUpdate1    110018
#define ID_SETTING_TextView35    50035
#define ID_SETTING_TextView34    50034
#define ID_SETTING_WindowDeviceSet1    110017
#define ID_SETTING_ButtonFilterSet1    20005
#define ID_SETTING_TextView33    50033
#define ID_SETTING_TextView32    50032
#define ID_SETTING_WindowFilterSet1    110016
#define ID_SETTING_ButtonBodySensor1    20004
#define ID_SETTING_TextView31    50031
#define ID_SETTING_TextView30    50030
#define ID_SETTING_WindowBodySensor1    110015
#define ID_SETTING_ButtonTimesetting1    20003
#define ID_SETTING_TextView29    50029
#define ID_SETTING_TextView28    50028
#define ID_SETTING_WindowTimeSetting1    110014
#define ID_SETTING_TextView27    50027
#define ID_SETTING_TextView26    50026
#define ID_SETTING_WindowPressSet1    110013
#define ID_SETTING_ButtonSensorCtl1    20001
#define ID_SETTING_TextView25    50025
#define ID_SETTING_TextView24    50024
#define ID_SETTING_WindowSensorCtl1    110012
#define ID_SETTING_Window1    110011
/*TAG:Macro宏ID END*/

class settingActivity : public Activity, 
                     public ZKSeekBar::ISeekBarChangeListener, 
                     public ZKListView::IItemClickListener,
                     public ZKListView::AbsListAdapter,
                     public ZKSlideWindow::ISlideItemClickListener,
                     public EasyUIContext::ITouchListener,
                     public ZKEditText::ITextChangeListener,
                     public ZKVideoView::IVideoPlayerMessageListener
{
public:
    settingActivity();
    virtual ~settingActivity();

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