/***********************************************
/gen auto by zuitools
***********************************************/
#ifndef __STANDBYACTIVITY_H__
#define __STANDBYACTIVITY_H__


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
#define ID_STANDBY_TextView25    50026
#define ID_STANDBY_iconWifi    50025
#define ID_STANDBY_TextView24    50024
#define ID_STANDBY_TextView23    50023
#define ID_STANDBY_WindowDate    110012
#define ID_STANDBY_TextView22    50022
#define ID_STANDBY_TextView21    50021
#define ID_STANDBY_Window11    110011
#define ID_STANDBY_TextView20    50020
#define ID_STANDBY_TextView19    50019
#define ID_STANDBY_Window10    110010
#define ID_STANDBY_TextView18    50018
#define ID_STANDBY_TextView17    50017
#define ID_STANDBY_TextView16    50016
#define ID_STANDBY_Window9    110009
#define ID_STANDBY_TextView15    50015
#define ID_STANDBY_TextView14    50014
#define ID_STANDBY_Window8    110008
#define ID_STANDBY_TextView13    50013
#define ID_STANDBY_TextView12    50012
#define ID_STANDBY_Window7    110007
#define ID_STANDBY_TextView11    50011
#define ID_STANDBY_TextView10    50010
#define ID_STANDBY_Windowinside    110006
#define ID_STANDBY_TextView9    50009
#define ID_STANDBY_TextView8    50008
#define ID_STANDBY_TextView7    50007
#define ID_STANDBY_Window5    110005
#define ID_STANDBY_TextView6    50006
#define ID_STANDBY_TextView5    50005
#define ID_STANDBY_Window4    110004
#define ID_STANDBY_TextView4    50004
#define ID_STANDBY_TextView3    50003
#define ID_STANDBY_Window3    110003
#define ID_STANDBY_TextView2    50002
#define ID_STANDBY_TextView1    50001
#define ID_STANDBY_Windowoutdoor    110002
#define ID_STANDBY_Window1    110001
/*TAG:Macro宏ID END*/

class StandByActivity : public Activity, 
                     public ZKSeekBar::ISeekBarChangeListener, 
                     public ZKListView::IItemClickListener,
                     public ZKListView::AbsListAdapter,
                     public ZKSlideWindow::ISlideItemClickListener,
                     public EasyUIContext::ITouchListener,
                     public ZKEditText::ITextChangeListener,
                     public ZKVideoView::IVideoPlayerMessageListener
{
public:
    StandByActivity();
    virtual ~StandByActivity();

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