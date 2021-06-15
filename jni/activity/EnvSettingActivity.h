/***********************************************
/gen auto by zuitools
***********************************************/
#ifndef __ENVSETTINGACTIVITY_H__
#define __ENVSETTINGACTIVITY_H__


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
#include "control/ZKRadioGroup.h"
#include "window/ZKSlideWindow.h"

/*TAG:Macro宏ID*/
#define ID_ENVSETTING_TextViewPicShow    50001
#define ID_ENVSETTING_SubItemDevName    20008
#define ID_ENVSETTING_SubItemDevPic    20007
#define ID_ENVSETTING_ListView3    80003
#define ID_ENVSETTING_ButtonInput    20006
#define ID_ENVSETTING_SubItemDelete    20005
#define ID_ENVSETTING_SubItemText    20002
#define ID_ENVSETTING_ListView1    80001
#define ID_ENVSETTING_ButtonDelete1    20004
#define ID_ENVSETTING_ButtonBack2    20003
#define ID_ENVSETTING_TextView15    50015
#define ID_ENVSETTING_TextView14    50014
#define ID_ENVSETTING_Window5    110009
#define ID_ENVSETTING_Window4    110008
#define ID_ENVSETTING_TextView13    50013
#define ID_ENVSETTING_TextView12    50012
#define ID_ENVSETTING_TextView11    50011
#define ID_ENVSETTING_WindowKitchen    110007
#define ID_ENVSETTING_TextView10    50010
#define ID_ENVSETTING_TextView9    50009
#define ID_ENVSETTING_TextView8    50008
#define ID_ENVSETTING_WindowBigMachine    110006
#define ID_ENVSETTING_TextView7    50007
#define ID_ENVSETTING_TextView6    50006
#define ID_ENVSETTING_TextView5    50005
#define ID_ENVSETTING_WindowSmallMachine    110005
#define ID_ENVSETTING_WindowAll    110004
#define ID_ENVSETTING_RadioButtonHomeDev    22005
#define ID_ENVSETTING_RadioButtonKitchen    22004
#define ID_ENVSETTING_RadioButtonBigMachine    22003
#define ID_ENVSETTING_RadioButtonSmallMachine    22002
#define ID_ENVSETTING_RadioButtonAll    22001
#define ID_ENVSETTING_RadioGroup1    94001
#define ID_ENVSETTING_Window3    110003
#define ID_ENVSETTING_TextView2    50002
#define ID_ENVSETTING_ButtonBack1    20001
#define ID_ENVSETTING_Window2    110002
#define ID_ENVSETTING_Window1    110001
#define ID_ENVSETTING_Button10    20029
#define ID_ENVSETTING_SubItemCancel    20027
#define ID_ENVSETTING_SubItemPic    20025
#define ID_ENVSETTING_SubItemTitle    20026
#define ID_ENVSETTING_ListView2    80002
#define ID_ENVSETTING_ButtonBack    20028
#define ID_ENVSETTING_TextView45    50053
#define ID_ENVSETTING_TextView44    50052
#define ID_ENVSETTING_Window15    110029
#define ID_ENVSETTING_Window12    110028
#define ID_ENVSETTING_Button9    20026
#define ID_ENVSETTING_Window14    110027
#define ID_ENVSETTING_WindowEnvBGDisp    110026


typedef struct {
	const char maintext[128];
	const char mainPic[128];
	bool cancelstatus;
}SpaceInfo;

typedef struct {
	const char maintext[128];
	const char mainPic[128];
}IOTDevInfo;

/*TAG:Macro宏ID END*/

class EnvSettingActivity : public Activity, 
                     public ZKSeekBar::ISeekBarChangeListener, 
                     public ZKListView::IItemClickListener,
                     public ZKListView::AbsListAdapter,
                     public ZKSlideWindow::ISlideItemClickListener,
                     public EasyUIContext::ITouchListener,
                     public ZKRadioGroup::ICheckedChangeListener,
                     public ZKEditText::ITextChangeListener,
                     public ZKVideoView::IVideoPlayerMessageListener
{
public:
    EnvSettingActivity();
    virtual ~EnvSettingActivity();

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
    virtual void onItemClick(ZKListView *pListView,  int index, int subItemIndex);

    virtual void onSlideItemClick(ZKSlideWindow *pSlideWindow, int index);

    virtual bool onTouchEvent(const MotionEvent &ev);
    virtual void onCheckedChanged(ZKRadioGroup* pRadioGroup, int checkedID);

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