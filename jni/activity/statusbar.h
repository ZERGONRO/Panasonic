#ifndef _SYSAPP_STATUSBAR_H_
#define _SYSAPP_STATUSBAR_H_

#include "entry/EasyUIContext.h"
#include "app/SysAppFactory.h"

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
#define ID_STATUSBAR_WindowBackground    110005
#define ID_STATUSBAR_TextViewAlpha    50007
#define ID_STATUSBAR_WindowAlpha    110004
#define ID_STATUSBAR_WindowBG    110003
#define ID_STATUSBAR_TextViewSetting    50006
#define ID_STATUSBAR_TextViewDarkColor    50005
#define ID_STATUSBAR_ButtonSetting    20004
#define ID_STATUSBAR_ButtonDarkColor    20003
#define ID_STATUSBAR_TextViewEasyMode    50004
#define ID_STATUSBAR_ButtonEasyMode    20002
#define ID_STATUSBAR_TextViewLightBar    50003
#define ID_STATUSBAR_SeekBarLight    91001
#define ID_STATUSBAR_TextViewLight    50002
#define ID_STATUSBAR_TextViewPicLight    50001
#define ID_STATUSBAR_WindowProcessBar    110002
#define ID_STATUSBAR_ButtonDropDown    20001
#define ID_STATUSBAR_TextView12    50012
#define ID_STATUSBAR_WindowStatusBar    110001
/*TAG:Macro宏ID END*/
class statusbar : public BaseApp,
                  public ZKSeekBar::ISeekBarChangeListener, 
                  public ZKListView::IItemClickListener,
                  public ZKListView::AbsListAdapter,
                  public ZKSlideWindow::ISlideItemClickListener,
                  public EasyUIContext::ITouchListener,
                  public ZKEditText::ITextChangeListener,
                  public ZKVideoView::IVideoPlayerMessageListener
{
public:
	statusbar();
	virtual ~statusbar();
	virtual void onCreate();
	virtual void onClick(ZKBase *pBase);
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


private:
    /*TAG:PRIVATE_VARIABLE*/
    int mVideoLoopIndex;
    int mVideoLoopErrorCount;
};

#endif