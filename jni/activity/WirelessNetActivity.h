/***********************************************
/gen auto by zuitools
***********************************************/
#ifndef __WIRELESSNETACTIVITY_H__
#define __WIRELESSNETACTIVITY_H__


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
#define ID_WIRELESSNET_Button4    20004
#define ID_WIRELESSNET_Button3    20003
#define ID_WIRELESSNET_TextView5    50005
#define ID_WIRELESSNET_Window2    110002
#define ID_WIRELESSNET_Button6    20005
#define ID_WIRELESSNET_Button2    20002
#define ID_WIRELESSNET_Button1    20001
#define ID_WIRELESSNET_TextView4    50004
#define ID_WIRELESSNET_TextView2    50002
#define ID_WIRELESSNET_TextView1    50001
#define ID_WIRELESSNET_Window1    110001
#define ID_WIRELESSNET_TextView8    50008
#define ID_WIRELESSNET_TextView3    50003
#define ID_WIRELESSNET_ButtonBack    20011
/*TAG:Macro宏ID END*/

class WirelessNetActivity : public Activity, 
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
    WirelessNetActivity();
    virtual ~WirelessNetActivity();
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
