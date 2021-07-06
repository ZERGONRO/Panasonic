/***********************************************
/gen auto by zuitools
***********************************************/
#ifndef __TIMESETTINGACTIVITY_H__
#define __TIMESETTINGACTIVITY_H__


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
#define ID_TIMESETTING_SubItemMinMini    20011
#define ID_TIMESETTING_SubItemMinSmall    20010
#define ID_TIMESETTING_SubItemMinMid    20009
#define ID_TIMESETTING_SubItemMinLarge    20008
#define ID_TIMESETTING_SubItemMinMax    20007
#define ID_TIMESETTING_ListViewMinuete    80005
#define ID_TIMESETTING_SubItemHourMini    20011
#define ID_TIMESETTING_SubItemHourSmall    20010
#define ID_TIMESETTING_SubItemHourMid    20009
#define ID_TIMESETTING_SubItemHourLarge    20008
#define ID_TIMESETTING_SubItemHourMax    20007
#define ID_TIMESETTING_ListViewHour    80004
#define ID_TIMESETTING_SubItemDayMini    20011
#define ID_TIMESETTING_SubItemDaySmall    20010
#define ID_TIMESETTING_SubItemDayMid    20009
#define ID_TIMESETTING_SubItemDayLarge    20008
#define ID_TIMESETTING_SubItemDayMax    20007
#define ID_TIMESETTING_ListViewDay    80006
#define ID_TIMESETTING_SubItemMonthMini    20011
#define ID_TIMESETTING_SubItemMonthSmall    20010
#define ID_TIMESETTING_SubItemMonthMid    20009
#define ID_TIMESETTING_SubItemMonthLarge    20008
#define ID_TIMESETTING_SubItemMonthMax    20007
#define ID_TIMESETTING_ListViewMonth    80003
#define ID_TIMESETTING_SubItemYearMini    20011
#define ID_TIMESETTING_SubItemYearSmall    20010
#define ID_TIMESETTING_SubItemYearMid    20009
#define ID_TIMESETTING_SubItemYearLarge    20008
#define ID_TIMESETTING_SubItemYearMax    20007
#define ID_TIMESETTING_ListViewYear    80002
#define ID_TIMESETTING_SubItemMin    20006
#define ID_TIMESETTING_SubItemHour    20005
#define ID_TIMESETTING_SubItemDay    20004
#define ID_TIMESETTING_SubItemMonth    20003
#define ID_TIMESETTING_SubItemYear    20002
#define ID_TIMESETTING_ListView1    80001
#define ID_TIMESETTING_TextViewDesc    50004
#define ID_TIMESETTING_ButtonBack    20001
#define ID_TIMESETTING_TextViewDatesetting    50003
#define ID_TIMESETTING_TextViewDate1    50002
#define ID_TIMESETTING_TextViewDate    50001
#define ID_TIMESETTING_WindowTimeSetting    110001
#define ID_TIMESETTING_TextView6    50006
/*TAG:Macro宏ID END*/

class TimeSettingActivity : public Activity, 
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
    TimeSettingActivity();
    virtual ~TimeSettingActivity();
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