/***********************************************
/gen auto by zuitools
***********************************************/
#ifndef __MAINACTIVITY_H__
#define __MAINACTIVITY_H__


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
#define ID_MAIN_TextView42    50070
#define ID_MAIN_IconViewWifi    50046
#define ID_MAIN_IconViewAirCold    50045
#define ID_MAIN_IconViewHumdCold    50044
#define ID_MAIN_IconViewHumdDry    50043
#define ID_MAIN_IconViewSecurity    50042
#define ID_MAIN_Window25    110041
#define ID_MAIN_ButtonSelect4    20013
#define ID_MAIN_ButtonSelect5    20012
#define ID_MAIN_ButtonSelect3    20011
#define ID_MAIN_ButtonSelect2    20010
#define ID_MAIN_ButtonSelect1    20009
#define ID_MAIN_TextViewHumidity    50069
#define ID_MAIN_TextView60    50068
#define ID_MAIN_Window23    110039
#define ID_MAIN_TextViewFreshair    50067
#define ID_MAIN_TextView59    50066
#define ID_MAIN_WindowFreshAir    110038
#define ID_MAIN_TextViewAir    50065
#define ID_MAIN_TextView58    50064
#define ID_MAIN_WindowAircondition    110037
#define ID_MAIN_TextViewmcu    50063
#define ID_MAIN_TextViewHistory2    50062
#define ID_MAIN_ButtonHistorty2    20034
#define ID_MAIN_Window22    110036
#define ID_MAIN_TextViewManual2    50061
#define ID_MAIN_ButtonManual2    20033
#define ID_MAIN_Window21    110035
#define ID_MAIN_TextViewSmart2    50060
#define ID_MAIN_ButtonSmart2    20032
#define ID_MAIN_Window20    110034
#define ID_MAIN_TextViewHomepage2    50059
#define ID_MAIN_ButtonHomepage2    20031
#define ID_MAIN_Window19    110033
#define ID_MAIN_WindowNavibar2    110032
#define ID_MAIN_ButtonDropDown    20030
#define ID_MAIN_Button14    20029
#define ID_MAIN_TextView57    50058
#define ID_MAIN_Window18    110031
#define ID_MAIN_Button13    20028
#define ID_MAIN_TextView56    50057
#define ID_MAIN_Window17    110030
#define ID_MAIN_Button12    20027
#define ID_MAIN_TextView55    50056
#define ID_MAIN_Window16    110029
#define ID_MAIN_Button11    20026
#define ID_MAIN_TextView54    50055
#define ID_MAIN_Window15    110028
#define ID_MAIN_Button10    20025
#define ID_MAIN_TextView53    50054
#define ID_MAIN_Window14    110027
#define ID_MAIN_Button9    20024
#define ID_MAIN_TextView52    50053
#define ID_MAIN_Window12    110026
#define ID_MAIN_TextView51    50052
#define ID_MAIN_Button8    20023
#define ID_MAIN_Button2    20022
#define ID_MAIN_Window1    110025
#define ID_MAIN_WindowModeSelect2    110024
#define ID_MAIN_WindowMainStatus    110023
#define ID_MAIN_WindowModeSelect1    110019
#define ID_MAIN_WindowBG    110001
#define ID_MAIN_TextView50    50051
#define ID_MAIN_TextView49    50050
#define ID_MAIN_TextView48    50049
#define ID_MAIN_TextView47    50048
#define ID_MAIN_TextView40    50047
#define ID_MAIN_TextViewWifi    50040
#define ID_MAIN_Button1    20021
#define ID_MAIN_Button7    20020
#define ID_MAIN_Button6    20019
#define ID_MAIN_TextView39    50039
#define ID_MAIN_Window13    110022
#define ID_MAIN_Button5    20018
#define ID_MAIN_TextView38    50038
#define ID_MAIN_Window11    110021
#define ID_MAIN_Button4    20017
#define ID_MAIN_TextView37    50037
#define ID_MAIN_Window10    110020
#define ID_MAIN_Button3    20016
#define ID_MAIN_ButtonOFF    20015
#define ID_MAIN_ButtonON    20014
#define ID_MAIN_TextView35    50035
#define ID_MAIN_TextView34    50034
#define ID_MAIN_TextView33    50033
#define ID_MAIN_TextView32    50032
#define ID_MAIN_WindowCO2    110018
#define ID_MAIN_TextView28    50028
#define ID_MAIN_TextView31    50031
#define ID_MAIN_TextView30    50030
#define ID_MAIN_TextView29    50029
#define ID_MAIN_WindowFormaldehyde    110017
#define ID_MAIN_TextView27    50027
#define ID_MAIN_TextView26    50026
#define ID_MAIN_TextView25    50025
#define ID_MAIN_TextView24    50024
#define ID_MAIN_WindowTemp    110016
#define ID_MAIN_TextView23    50023
#define ID_MAIN_TextView22    50022
#define ID_MAIN_TextView21    50021
#define ID_MAIN_TextView20    50020
#define ID_MAIN_WindowPM25    110015
#define ID_MAIN_TextView36    50036
#define ID_MAIN_TextView19    50019
#define ID_MAIN_TextView18    50018
#define ID_MAIN_TextView17    50017
#define ID_MAIN_WindowHumidity    110014
#define ID_MAIN_Window9    110013
#define ID_MAIN_TextView16    50016
#define ID_MAIN_TextView15    50015
#define ID_MAIN_TextView14    50014
#define ID_MAIN_Window8    110012
#define ID_MAIN_Window7    110011
#define ID_MAIN_TextView13    50013
#define ID_MAIN_TextView12    50012
#define ID_MAIN_TextView11    50011
#define ID_MAIN_TextView10    50010
#define ID_MAIN_TextView9    50009
#define ID_MAIN_TextView8    50008
#define ID_MAIN_TextView7    50007
#define ID_MAIN_Window6    110010
#define ID_MAIN_TextView6    50006
#define ID_MAIN_TextView5    50005
#define ID_MAIN_Window5    110009
#define ID_MAIN_Window4    110008
#define ID_MAIN_Window3    110007
#define ID_MAIN_TextView41    50041
#define ID_MAIN_ButtonHistorty1    20008
#define ID_MAIN_TextView4    50004
#define ID_MAIN_ButtonHistorty    20004
#define ID_MAIN_WindowHistorty    110006
#define ID_MAIN_ButtonManual1    20007
#define ID_MAIN_TextView3    50003
#define ID_MAIN_ButtonManual    20003
#define ID_MAIN_WindowManual    110005
#define ID_MAIN_ButtonSmart1    20006
#define ID_MAIN_TextView2    50002
#define ID_MAIN_ButtonSmart    20002
#define ID_MAIN_WindowSmart    110004
#define ID_MAIN_ButtonHomepage1    20005
#define ID_MAIN_TextView1    50001
#define ID_MAIN_ButtonHomepage    20001
#define ID_MAIN_WindowHomepage    110003
#define ID_MAIN_Window2    110002
/*TAG:Macro宏ID END*/

class mainActivity : public Activity, 
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
    mainActivity();
    virtual ~mainActivity();

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
	virtual void MyNetworkNotify(int type , void *data);
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
