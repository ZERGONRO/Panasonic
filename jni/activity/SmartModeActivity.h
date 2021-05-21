/***********************************************
/gen auto by zuitools
***********************************************/
#ifndef __SMARTMODEACTIVITY_H__
#define __SMARTMODEACTIVITY_H__


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
#define ID_SMARTMODE_TextViewHumidity    50069
#define ID_SMARTMODE_TextView60    50068
#define ID_SMARTMODE_Window23    110039
#define ID_SMARTMODE_TextViewFreshair    50067
#define ID_SMARTMODE_TextView59    50066
#define ID_SMARTMODE_WindowFreshAir    110038
#define ID_SMARTMODE_TextViewAir    50065
#define ID_SMARTMODE_TextView58    50064
#define ID_SMARTMODE_WindowAircondition    110037
#define ID_SMARTMODE_TextViewmcu    50063
#define ID_SMARTMODE_TextViewHistory2    50062
#define ID_SMARTMODE_ButtonHistorty2    20034
#define ID_SMARTMODE_Window22    110036
#define ID_SMARTMODE_TextViewManual2    50061
#define ID_SMARTMODE_ButtonManual2    20033
#define ID_SMARTMODE_Window21    110035
#define ID_SMARTMODE_TextViewSmart2    50060
#define ID_SMARTMODE_ButtonSmart2    20032
#define ID_SMARTMODE_Window20    110034
#define ID_SMARTMODE_TextViewHomepage2    50059
#define ID_SMARTMODE_ButtonHomepage2    20031
#define ID_SMARTMODE_Window19    110033
#define ID_SMARTMODE_WindowNavibar3    110032
#define ID_SMARTMODE_ButtonVacMode    20004
#define ID_SMARTMODE_ButtonHawaiMode    20003
#define ID_SMARTMODE_ButtonHokiMode    20002
#define ID_SMARTMODE_ButtonStdMode    20001
#define ID_SMARTMODE_WindowSelectMode    110004
#define ID_SMARTMODE_WindowVacationMode    110007
#define ID_SMARTMODE_WindowHawaiiMode    110006
#define ID_SMARTMODE_WindowHokkaidoMode    110005
#define ID_SMARTMODE_WindowStandardMode    110001
#define ID_SMARTMODE_TextView45    50046
#define ID_SMARTMODE_TextView44    50045
#define ID_SMARTMODE_TextView43    50044
#define ID_SMARTMODE_TextView40    50043
#define ID_SMARTMODE_TextView8    50040
#define ID_SMARTMODE_WindowStatus    110003
#define ID_SMARTMODE_TextViewWifi    50008
#define ID_SMARTMODE_ButtonDropDown    20021
#define ID_SMARTMODE_TextView42    50042
#define ID_SMARTMODE_TextView41    50041
#define ID_SMARTMODE_TextView39    50039
#define ID_SMARTMODE_TextView38    50038
#define ID_SMARTMODE_Button13    20012
#define ID_SMARTMODE_TextView37    50037
#define ID_SMARTMODE_TextView36    50036
#define ID_SMARTMODE_TextView35    50035
#define ID_SMARTMODE_TextView34    50034
#define ID_SMARTMODE_TextView33    50033
#define ID_SMARTMODE_TextView32    50032
#define ID_SMARTMODE_TextView31    50031
#define ID_SMARTMODE_TextView30    50030
#define ID_SMARTMODE_Button12    20011
#define ID_SMARTMODE_TextView29    50029
#define ID_SMARTMODE_TextView28    50028
#define ID_SMARTMODE_TextView27    50027
#define ID_SMARTMODE_TextView26    50026
#define ID_SMARTMODE_TextView25    50025
#define ID_SMARTMODE_TextView24    50024
#define ID_SMARTMODE_TextView16    50016
#define ID_SMARTMODE_TextView15    50015
#define ID_SMARTMODE_Button11    20010
#define ID_SMARTMODE_TextView14    50014
#define ID_SMARTMODE_TextView13    50013
#define ID_SMARTMODE_TextView12    50012
#define ID_SMARTMODE_TextView11    50011
#define ID_SMARTMODE_TextView10    50010
#define ID_SMARTMODE_Button10    20009
#define ID_SMARTMODE_Button8    20007
#define ID_SMARTMODE_Button9    20008
#define ID_SMARTMODE_Button7    20006
#define ID_SMARTMODE_TextView9    50009
#define ID_SMARTMODE_TextView7    50007
#define ID_SMARTMODE_TextView6    50006
#define ID_SMARTMODE_Button6    20005
#define ID_SMARTMODE_TextView5    50005
#define ID_SMARTMODE_TextView23    50023
#define ID_SMARTMODE_TextView22    50022
#define ID_SMARTMODE_TextView21    50021
#define ID_SMARTMODE_TextView20    50020
#define ID_SMARTMODE_TextView19    50019
#define ID_SMARTMODE_TextView18    50018
#define ID_SMARTMODE_TextView17    50017
#define ID_SMARTMODE_TextView4    50004
#define ID_SMARTMODE_TextView3    50003
#define ID_SMARTMODE_TextView2    50002
#define ID_SMARTMODE_TextView1    50001
#define ID_SMARTMODE_Window2    110002
/*TAG:Macro宏ID END*/

class SmartModeActivity : public Activity, 
                     public ZKSeekBar::ISeekBarChangeListener, 
                     public ZKListView::IItemClickListener,
                     public ZKListView::AbsListAdapter,
                     public ZKSlideWindow::ISlideItemClickListener,
                     public EasyUIContext::ITouchListener,
                     public ZKEditText::ITextChangeListener,
                     public ZKVideoView::IVideoPlayerMessageListener
{
public:
    SmartModeActivity();
    virtual ~SmartModeActivity();

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