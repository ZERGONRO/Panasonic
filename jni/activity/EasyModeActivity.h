/***********************************************
/gen auto by zuitools
***********************************************/
#ifndef __EASYMODEACTIVITY_H__
#define __EASYMODEACTIVITY_H__


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
#define ID_EASYMODE_Button5    20006
#define ID_EASYMODE_Button4    20004
#define ID_EASYMODE_TextView7    50007
#define ID_EASYMODE_Window1    110005
#define ID_EASYMODE_Button3    20003
#define ID_EASYMODE_Button6    20005
#define ID_EASYMODE_TextView6    50006
#define ID_EASYMODE_WindowWind    110004
#define ID_EASYMODE_Button2    20002
#define ID_EASYMODE_Button1    20001
#define ID_EASYMODE_TextView5    50005
#define ID_EASYMODE_WindowModeSetting    110002
#define ID_EASYMODE_TextView45    50046
#define ID_EASYMODE_TextView44    50045
#define ID_EASYMODE_TextView43    50044
#define ID_EASYMODE_TextView40    50043
#define ID_EASYMODE_TextView8    50040
#define ID_EASYMODE_TextView23    50023
#define ID_EASYMODE_TextView22    50022
#define ID_EASYMODE_TextView21    50021
#define ID_EASYMODE_TextView20    50020
#define ID_EASYMODE_TextView19    50019
#define ID_EASYMODE_TextView18    50018
#define ID_EASYMODE_TextView17    50017
#define ID_EASYMODE_TextView4    50004
#define ID_EASYMODE_TextView3    50003
#define ID_EASYMODE_TextView2    50002
#define ID_EASYMODE_TextView1    50001
#define ID_EASYMODE_WindowStatus    110003
#define ID_EASYMODE_TextViewWifi    50008
#define ID_EASYMODE_ButtonDropDown    20021
#define ID_EASYMODE_WindowBG    110001
/*TAG:Macro宏ID END*/

class EasyModeActivity : public Activity, 
                     public ZKSeekBar::ISeekBarChangeListener, 
                     public ZKListView::IItemClickListener,
                     public ZKListView::AbsListAdapter,
                     public ZKSlideWindow::ISlideItemClickListener,
                     public EasyUIContext::ITouchListener,
                     public ZKEditText::ITextChangeListener,
                     public ZKVideoView::IVideoPlayerMessageListener
{
public:
    EasyModeActivity();
    virtual ~EasyModeActivity();

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