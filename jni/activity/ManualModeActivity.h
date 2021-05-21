/***********************************************
/gen auto by zuitools
***********************************************/
#ifndef __MANUALMODEACTIVITY_H__
#define __MANUALMODEACTIVITY_H__


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
#define ID_MANUALMODE_ButtonHumdAdd    20022
#define ID_MANUALMODE_ButtonHumdLess    20020
#define ID_MANUALMODE_ButtonHumdTimeOpen    20019
#define ID_MANUALMODE_ButtonHumdTimePic    20018
#define ID_MANUALMODE_ButtonHumdOpen    20017
#define ID_MANUALMODE_ButtonAirAdd    20008
#define ID_MANUALMODE_ButtonAirLess    20007
#define ID_MANUALMODE_ButtonAirTimeOpen    20006
#define ID_MANUALMODE_ButtonAirTimePic    20004
#define ID_MANUALMODE_ButtonAirOpen    20005
#define ID_MANUALMODE_WindowAir    110004
#define ID_MANUALMODE_ButtonWindTimeOpen    20011
#define ID_MANUALMODE_ButtonWindTimePic    20010
#define ID_MANUALMODE_ButtonWindOpen    20009
#define ID_MANUALMODE_WindowHumdSwitch    110006
#define ID_MANUALMODE_ButtonWindStrong    20016
#define ID_MANUALMODE_ButtonWindWeak    20015
#define ID_MANUALMODE_ButtonWindOrdChangeAir    20014
#define ID_MANUALMODE_ButtonWindHotReplace    20013
#define ID_MANUALMODE_ButtonWindAuto    20012
#define ID_MANUALMODE_WindowWindSwitch    110005
#define ID_MANUALMODE_ButtonHumd    20003
#define ID_MANUALMODE_ButtonWind    20002
#define ID_MANUALMODE_ButtonAir    20001
#define ID_MANUALMODE_WindowModeSelect    110002
#define ID_MANUALMODE_TextView45    50046
#define ID_MANUALMODE_TextView44    50045
#define ID_MANUALMODE_TextView43    50044
#define ID_MANUALMODE_TextView40    50043
#define ID_MANUALMODE_TextView36    50040
#define ID_MANUALMODE_TextView35    50036
#define ID_MANUALMODE_TextView34    50035
#define ID_MANUALMODE_TextView33    50034
#define ID_MANUALMODE_TextView32    50033
#define ID_MANUALMODE_TextView31    50032
#define ID_MANUALMODE_TextView30    50031
#define ID_MANUALMODE_TextView29    50030
#define ID_MANUALMODE_TextView28    50029
#define ID_MANUALMODE_TextView27    50028
#define ID_MANUALMODE_TextView26    50027
#define ID_MANUALMODE_TextView25    50026
#define ID_MANUALMODE_WindowStatus    110007
#define ID_MANUALMODE_ButtonDropDown    20021
#define ID_MANUALMODE_TextViewWifi    50008
#define ID_MANUALMODE_TextView24    50025
#define ID_MANUALMODE_TextView16    50024
#define ID_MANUALMODE_TextView15    50016
#define ID_MANUALMODE_TextView14    50015
#define ID_MANUALMODE_TextView13    50014
#define ID_MANUALMODE_TextView8    50009
#define ID_MANUALMODE_TextView7    50007
#define ID_MANUALMODE_TextView6    50006
#define ID_MANUALMODE_TextView5    50005
#define ID_MANUALMODE_TextView12    50013
#define ID_MANUALMODE_TextView11    50012
#define ID_MANUALMODE_TextView10    50011
#define ID_MANUALMODE_TextView9    50010
#define ID_MANUALMODE_Window1    110001
/*TAG:Macro宏ID END*/

class ManualModeActivity : public Activity, 
                     public ZKSeekBar::ISeekBarChangeListener, 
                     public ZKListView::IItemClickListener,
                     public ZKListView::AbsListAdapter,
                     public ZKSlideWindow::ISlideItemClickListener,
                     public EasyUIContext::ITouchListener,
                     public ZKEditText::ITextChangeListener,
                     public ZKVideoView::IVideoPlayerMessageListener
{
public:
    ManualModeActivity();
    virtual ~ManualModeActivity();

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