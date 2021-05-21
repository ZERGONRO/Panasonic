/***********************************************
/gen auto by zuitools
***********************************************/
#ifndef __ADDTIMESETTINGACTIVITY_H__
#define __ADDTIMESETTINGACTIVITY_H__


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
#define ID_ADDTIMESETTING_ButtonConfire    20002
#define ID_ADDTIMESETTING_ButtonCancel    20001
#define ID_ADDTIMESETTING_WindowSL    110003
#define ID_ADDTIMESETTING_TextView7    50063
#define ID_ADDTIMESETTING_TextView5    50062
#define ID_ADDTIMESETTING_TextView3    50061
#define ID_ADDTIMESETTING_WindowRoll    110014
#define ID_ADDTIMESETTING_TextView39    50060
#define ID_ADDTIMESETTING_Button28    20053
#define ID_ADDTIMESETTING_TextView38    50059
#define ID_ADDTIMESETTING_Button27    20052
#define ID_ADDTIMESETTING_TextViewHumdity2    50058
#define ID_ADDTIMESETTING_Button26    20051
#define ID_ADDTIMESETTING_TextView36    50057
#define ID_ADDTIMESETTING_Button25    20050
#define ID_ADDTIMESETTING_TextViewTimeClose4    50056
#define ID_ADDTIMESETTING_TextView34    50055
#define ID_ADDTIMESETTING_Button24    20049
#define ID_ADDTIMESETTING_Button1    20026
#define ID_ADDTIMESETTING_TextViewTimeOpen4    50054
#define ID_ADDTIMESETTING_TextView32    50053
#define ID_ADDTIMESETTING_WindowCtlHumTime2    110013
#define ID_ADDTIMESETTING_TextView31    50052
#define ID_ADDTIMESETTING_Button23    20048
#define ID_ADDTIMESETTING_TextView30    50051
#define ID_ADDTIMESETTING_Button22    20047
#define ID_ADDTIMESETTING_TextViewHumdity1    50050
#define ID_ADDTIMESETTING_Button21    20046
#define ID_ADDTIMESETTING_TextView28    50049
#define ID_ADDTIMESETTING_Button20    20045
#define ID_ADDTIMESETTING_TextViewTimeClose3    50048
#define ID_ADDTIMESETTING_TextView25    50047
#define ID_ADDTIMESETTING_Button19    20044
#define ID_ADDTIMESETTING_Button10    20035
#define ID_ADDTIMESETTING_TextViewTimeOpen3    50046
#define ID_ADDTIMESETTING_TextView19    50045
#define ID_ADDTIMESETTING_WindowCtlHumTime1    110012
#define ID_ADDTIMESETTING_TextViewStrong2    50044
#define ID_ADDTIMESETTING_Button18    20043
#define ID_ADDTIMESETTING_TextViewWeak2    50043
#define ID_ADDTIMESETTING_Button17    20042
#define ID_ADDTIMESETTING_TextViewWind2    50042
#define ID_ADDTIMESETTING_TextViewRepAir2    50041
#define ID_ADDTIMESETTING_TextViewHotRep2    50040
#define ID_ADDTIMESETTING_Button16    20041
#define ID_ADDTIMESETTING_TextViewAuto2    50039
#define ID_ADDTIMESETTING_Button15    20040
#define ID_ADDTIMESETTING_TextViewMode2    50038
#define ID_ADDTIMESETTING_Button14    20039
#define ID_ADDTIMESETTING_TextView26    50037
#define ID_ADDTIMESETTING_Button13    20038
#define ID_ADDTIMESETTING_TextViewTimeClose2    50036
#define ID_ADDTIMESETTING_TextView24    50035
#define ID_ADDTIMESETTING_Button12    20037
#define ID_ADDTIMESETTING_Button11    20036
#define ID_ADDTIMESETTING_TextViewTimeOpen2    50034
#define ID_ADDTIMESETTING_TextView21    50033
#define ID_ADDTIMESETTING_WindowWindTime2    110011
#define ID_ADDTIMESETTING_TextViewStrong    50032
#define ID_ADDTIMESETTING_Button9    20034
#define ID_ADDTIMESETTING_TextViewWeak    50031
#define ID_ADDTIMESETTING_Button8    20033
#define ID_ADDTIMESETTING_TextViewWind    50030
#define ID_ADDTIMESETTING_TextViewRepAir    50029
#define ID_ADDTIMESETTING_TextViewHotRep    50028
#define ID_ADDTIMESETTING_Button7    20032
#define ID_ADDTIMESETTING_TextViewAuto    50027
#define ID_ADDTIMESETTING_Button6    20031
#define ID_ADDTIMESETTING_TextViewMode    50026
#define ID_ADDTIMESETTING_Button5    20030
#define ID_ADDTIMESETTING_TextView22    50025
#define ID_ADDTIMESETTING_Button4    20029
#define ID_ADDTIMESETTING_TextViewTimeClose    50024
#define ID_ADDTIMESETTING_TextView20    50023
#define ID_ADDTIMESETTING_Button3    20028
#define ID_ADDTIMESETTING_Button2    20027
#define ID_ADDTIMESETTING_TextViewTimeOpen    50022
#define ID_ADDTIMESETTING_TextView18    50021
#define ID_ADDTIMESETTING_WindowWindTime1    110010
#define ID_ADDTIMESETTING_TextView17    50017
#define ID_ADDTIMESETTING_ButtonAdd6    20025
#define ID_ADDTIMESETTING_TextView16    50016
#define ID_ADDTIMESETTING_ButtonDel6    20024
#define ID_ADDTIMESETTING_TextViewTemp2    50015
#define ID_ADDTIMESETTING_ButtonAdd5    20023
#define ID_ADDTIMESETTING_TextView14    50014
#define ID_ADDTIMESETTING_ButtonDel5    20022
#define ID_ADDTIMESETTING_TextViewTimeClose6    50013
#define ID_ADDTIMESETTING_TextView12    50012
#define ID_ADDTIMESETTING_ButtonAdd4    20021
#define ID_ADDTIMESETTING_ButtonDel4    20020
#define ID_ADDTIMESETTING_TextViewTimeOpen6    50011
#define ID_ADDTIMESETTING_TextView10    50010
#define ID_ADDTIMESETTING_WindowAirTime2    110008
#define ID_ADDTIMESETTING_TextView9    50009
#define ID_ADDTIMESETTING_ButtonAdd3    20018
#define ID_ADDTIMESETTING_TextView8    50008
#define ID_ADDTIMESETTING_ButtonDel3    20017
#define ID_ADDTIMESETTING_TextViewTemp1    50007
#define ID_ADDTIMESETTING_ButtonAdd2    20016
#define ID_ADDTIMESETTING_TextView6    50006
#define ID_ADDTIMESETTING_ButtonDel2    20015
#define ID_ADDTIMESETTING_TextViewTimeClose5    50005
#define ID_ADDTIMESETTING_TextView4    50004
#define ID_ADDTIMESETTING_ButtonAdd1    20014
#define ID_ADDTIMESETTING_ButtonDel1    20013
#define ID_ADDTIMESETTING_TextViewTimeOpen5    50003
#define ID_ADDTIMESETTING_TextView2    50002
#define ID_ADDTIMESETTING_WindowAirTime1    110007
#define ID_ADDTIMESETTING_ButtonSun    20011
#define ID_ADDTIMESETTING_ButtonSat    20010
#define ID_ADDTIMESETTING_ButtonFri    20009
#define ID_ADDTIMESETTING_ButtonThue    20008
#define ID_ADDTIMESETTING_ButtonWen    20007
#define ID_ADDTIMESETTING_ButtonTues    20006
#define ID_ADDTIMESETTING_ButtonMon    20005
#define ID_ADDTIMESETTING_ButtonEveryDay    20004
#define ID_ADDTIMESETTING_WindowWeek    110006
#define ID_ADDTIMESETTING_ButtonAddTime    20003
#define ID_ADDTIMESETTING_TextView1    50001
#define ID_ADDTIMESETTING_WindowContent    110005
#define ID_ADDTIMESETTING_WindowDisp    110004
#define ID_ADDTIMESETTING_WindowMain    110002
#define ID_ADDTIMESETTING_WindowBG    110001
/*TAG:Macro宏ID END*/

class AddTimeSettingActivity : public Activity, 
                     public ZKSeekBar::ISeekBarChangeListener, 
                     public ZKListView::IItemClickListener,
                     public ZKListView::AbsListAdapter,
                     public ZKSlideWindow::ISlideItemClickListener,
                     public EasyUIContext::ITouchListener,
                     public ZKEditText::ITextChangeListener,
                     public ZKVideoView::IVideoPlayerMessageListener
{
public:
    AddTimeSettingActivity();
    virtual ~AddTimeSettingActivity();

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