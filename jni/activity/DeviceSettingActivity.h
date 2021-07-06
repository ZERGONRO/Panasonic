/***********************************************
/gen auto by zuitools
***********************************************/
#ifndef __DEVICESETTINGACTIVITY_H__
#define __DEVICESETTINGACTIVITY_H__


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
#define ID_DEVICESETTING_ButtonBack    20011
#define ID_DEVICESETTING_TextViewIcon4    50018
#define ID_DEVICESETTING_TextViewIcon3    50017
#define ID_DEVICESETTING_TextViewIcon2    50016
#define ID_DEVICESETTING_TextViewIcon1    50015
#define ID_DEVICESETTING_TextViewDeviceInfo    50014
#define ID_DEVICESETTING_TextViewNameSetting    50013
#define ID_DEVICESETTING_TextViewDeviceAddr    50011
#define ID_DEVICESETTING_TextViewDeviceName    50010
#define ID_DEVICESETTING_TextViewDeviceNum    50009
#define ID_DEVICESETTING_Window2    110002
#define ID_DEVICESETTING_TextView7    50007
#define ID_DEVICESETTING_TextView6    50006
#define ID_DEVICESETTING_TextView5    50005
#define ID_DEVICESETTING_TextView4    50004
#define ID_DEVICESETTING_TextView2    50002
#define ID_DEVICESETTING_Window1    110001
#define ID_DEVICESETTING_TextView3    50003
#define ID_DEVICESETTING_TextView8    50008
/*TAG:Macro宏ID END*/

class DeviceSettingActivity : public Activity, 
                     public ZKSeekBar::ISeekBarChangeListener, 
                     public ZKListView::IItemClickListener,
                     public ZKListView::AbsListAdapter,
                     public ZKSlideWindow::ISlideItemClickListener,
                     public EasyUIContext::ITouchListener,
                     public ZKEditText::ITextChangeListener,
                     public ZKVideoView::IVideoPlayerMessageListener
{
public:
    DeviceSettingActivity();
    virtual ~DeviceSettingActivity();

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