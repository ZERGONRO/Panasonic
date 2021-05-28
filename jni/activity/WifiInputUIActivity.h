/***********************************************
/gen auto by zuitools
***********************************************/
#ifndef __WIFIINPUTUIACTIVITY_H__
#define __WIFIINPUTUIACTIVITY_H__


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
#define ID_WIFIINPUTUI_Button36    20076
#define ID_WIFIINPUTUI_Button10    20075
#define ID_WIFIINPUTUI_Button35    20074
#define ID_WIFIINPUTUI_Button34    20073
#define ID_WIFIINPUTUI_Button33    20072
#define ID_WIFIINPUTUI_Button32    20071
#define ID_WIFIINPUTUI_Button31    20070
#define ID_WIFIINPUTUI_Button30    20069
#define ID_WIFIINPUTUI_Button29    20068
#define ID_WIFIINPUTUI_Button28    20067
#define ID_WIFIINPUTUI_Button27    20066
#define ID_WIFIINPUTUI_Button26    20065
#define ID_WIFIINPUTUI_Button25    20064
#define ID_WIFIINPUTUI_Button24    20063
#define ID_WIFIINPUTUI_Button23    20062
#define ID_WIFIINPUTUI_Button21    20061
#define ID_WIFIINPUTUI_Button20    20060
#define ID_WIFIINPUTUI_Button19    20059
#define ID_WIFIINPUTUI_Button18    20058
#define ID_WIFIINPUTUI_Button17    20057
#define ID_WIFIINPUTUI_Button16    20056
#define ID_WIFIINPUTUI_Button15    20055
#define ID_WIFIINPUTUI_Button14    20054
#define ID_WIFIINPUTUI_Button13    20053
#define ID_WIFIINPUTUI_Button12    20052
#define ID_WIFIINPUTUI_Button11    20051
#define ID_WIFIINPUTUI_Button0    20050
#define ID_WIFIINPUTUI_Button9    20049
#define ID_WIFIINPUTUI_Button8    20048
#define ID_WIFIINPUTUI_Button7    20047
#define ID_WIFIINPUTUI_Button6    20046
#define ID_WIFIINPUTUI_Button5    20045
#define ID_WIFIINPUTUI_Button4    20044
#define ID_WIFIINPUTUI_Button3    20043
#define ID_WIFIINPUTUI_Button2    20042
#define ID_WIFIINPUTUI_Button1    20041
#define ID_WIFIINPUTUI_Window14    110015
#define ID_WIFIINPUTUI_ButtonDot    20040
#define ID_WIFIINPUTUI_ButtonNum2    20039
#define ID_WIFIINPUTUI_ButtonDCom    20038
#define ID_WIFIINPUTUI_ButtonSpace    20037
#define ID_WIFIINPUTUI_ButtonSlash    20036
#define ID_WIFIINPUTUI_ButtonNum    20035
#define ID_WIFIINPUTUI_ButtonUpper2    20034
#define ID_WIFIINPUTUI_ButtonQM    20033
#define ID_WIFIINPUTUI_ButtonN    20032
#define ID_WIFIINPUTUI_ButtonV    20031
#define ID_WIFIINPUTUI_ButtonZ    20030
#define ID_WIFIINPUTUI_ButtonB    20029
#define ID_WIFIINPUTUI_ButtonX    20028
#define ID_WIFIINPUTUI_ButtonC    20027
#define ID_WIFIINPUTUI_ButtonM    20026
#define ID_WIFIINPUTUI_ButtonUpper    20025
#define ID_WIFIINPUTUI_ButtonExclamation    20024
#define ID_WIFIINPUTUI_Button22    20023
#define ID_WIFIINPUTUI_ButtonL    20022
#define ID_WIFIINPUTUI_ButtonK    20021
#define ID_WIFIINPUTUI_ButtonJ    20020
#define ID_WIFIINPUTUI_ButtonH    20019
#define ID_WIFIINPUTUI_ButtonG    20018
#define ID_WIFIINPUTUI_ButtonF    20017
#define ID_WIFIINPUTUI_ButtonD    20016
#define ID_WIFIINPUTUI_ButtonS    20015
#define ID_WIFIINPUTUI_ButtonA    20014
#define ID_WIFIINPUTUI_ButtonBackspace    20013
#define ID_WIFIINPUTUI_Window13    110013
#define ID_WIFIINPUTUI_ButtonP    20012
#define ID_WIFIINPUTUI_TextView11    50013
#define ID_WIFIINPUTUI_Window12    110012
#define ID_WIFIINPUTUI_ButtonO    20010
#define ID_WIFIINPUTUI_TextView10    50012
#define ID_WIFIINPUTUI_Window11    110011
#define ID_WIFIINPUTUI_ButtonI    20009
#define ID_WIFIINPUTUI_TextView9    50011
#define ID_WIFIINPUTUI_Window10    110010
#define ID_WIFIINPUTUI_ButtonU    20008
#define ID_WIFIINPUTUI_TextView8    50010
#define ID_WIFIINPUTUI_Window9    110009
#define ID_WIFIINPUTUI_ButtonY    20007
#define ID_WIFIINPUTUI_TextView7    50009
#define ID_WIFIINPUTUI_Window8    110008
#define ID_WIFIINPUTUI_ButtonT    20006
#define ID_WIFIINPUTUI_TextView6    50007
#define ID_WIFIINPUTUI_Window7    110007
#define ID_WIFIINPUTUI_ButtonR    20005
#define ID_WIFIINPUTUI_TextView5    50006
#define ID_WIFIINPUTUI_Window6    110006
#define ID_WIFIINPUTUI_ButtonE    20004
#define ID_WIFIINPUTUI_TextView4    50005
#define ID_WIFIINPUTUI_Window5    110005
#define ID_WIFIINPUTUI_ButtonW    20003
#define ID_WIFIINPUTUI_TextView3    50004
#define ID_WIFIINPUTUI_Window4    110004
#define ID_WIFIINPUTUI_ButtonQ    20002
#define ID_WIFIINPUTUI_TextView2    50003
#define ID_WIFIINPUTUI_Window3    110003
#define ID_WIFIINPUTUI_Window2    110002
#define ID_WIFIINPUTUI_ButtonConfirm    20001
#define ID_WIFIINPUTUI_PassWordTextView2    50017
#define ID_WIFIINPUTUI_PassWordTextView    50002
#define ID_WIFIINPUTUI_Window1    110001
#define ID_WIFIINPUTUI_IconWifi    50008
#define ID_WIFIINPUTUI_ButtonBack    20011
#define ID_WIFIINPUTUI_TextViewSSID    50001
/*TAG:Macro宏ID END*/

class WifiInputUIActivity : public Activity, 
                     public ZKSeekBar::ISeekBarChangeListener, 
                     public ZKListView::IItemClickListener,
                     public ZKListView::AbsListAdapter,
                     public ZKSlideWindow::ISlideItemClickListener,
                     public EasyUIContext::ITouchListener,
                     public ZKEditText::ITextChangeListener,
					 public MyNetWorkingListener::MyNetWorkListener,
					 public ZKBase::ILongClickListener,
                     public ZKVideoView::IVideoPlayerMessageListener
{
public:
    WifiInputUIActivity();
    virtual ~WifiInputUIActivity();
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
    virtual void onLongClick(ZKBase *pBase);
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
