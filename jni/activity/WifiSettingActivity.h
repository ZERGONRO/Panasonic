/***********************************************
/gen auto by zuitools
***********************************************/
#ifndef __WIFISETTINGACTIVITY_H__
#define __WIFISETTINGACTIVITY_H__


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
#include "util/MyNetWorkingListener.h"

/*TAG:Macro宏ID*/
#define ID_WIFISETTING_ButtonKnow    20004
#define ID_WIFISETTING_TextViewConnectFailMsg    50007
#define ID_WIFISETTING_Window5    110005
#define ID_WIFISETTING_WindowConnectFail    110003
#define ID_WIFISETTING_IconWifi    50008
#define ID_WIFISETTING_IconConnectedStatus    20003
#define ID_WIFISETTING_SSID2    20005
#define ID_WIFISETTING_SSID    20002
#define ID_WIFISETTING_ListViewWifiInfo    80001
#define ID_WIFISETTING_ButtonWifiSwitch    20001
#define ID_WIFISETTING_TextView2    50002
#define ID_WIFISETTING_Window1    110002
#define ID_WIFISETTING_ButtonBack    20011
#define ID_WIFISETTING_TextView3    50003
/*TAG:Macro宏ID END*/

class WifiSettingActivity : public Activity, 
                     public ZKSeekBar::ISeekBarChangeListener, 
                     public ZKListView::IItemClickListener,
                     public ZKListView::AbsListAdapter,
                     public ZKSlideWindow::ISlideItemClickListener,
                     public EasyUIContext::ITouchListener,
                     public ZKEditText::ITextChangeListener,
					 public MyNetWorkingListener::MyNetWorkListener,
                     public ZKVideoView::IVideoPlayerMessageListener
{
public:
    WifiSettingActivity();
    virtual ~WifiSettingActivity();
    virtual void MyNetworkNotify(int type , void *data);
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
