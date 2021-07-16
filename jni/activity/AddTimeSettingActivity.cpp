/***********************************************
/gen auto by zuitools
***********************************************/
#include "AddTimeSettingActivity.h"

/*TAG:GlobalVariable全局变量*/
static ZKButton* mButtonStage2Ptr;
static ZKButton* mButtonStage1Ptr;
static ZKButton* mButtonConfirePtr;
static ZKButton* mButtonCancelPtr;
static ZKWindow* mWindowSLPtr;
static ZKTextView* mTextView7Ptr;
static ZKTextView* mTextView5Ptr;
static ZKTextView* mTextView3Ptr;
static ZKWindow* mWindowRollPtr;
static ZKTextView* mTextView39Ptr;
static ZKButton* mButton28Ptr;
static ZKTextView* mTextView38Ptr;
static ZKButton* mButton27Ptr;
static ZKTextView* mTextViewHumdity2Ptr;
static ZKButton* mButton26Ptr;
static ZKTextView* mTextView36Ptr;
static ZKButton* mButton25Ptr;
static ZKTextView* mTextViewTimeClose4Ptr;
static ZKTextView* mTextView34Ptr;
static ZKButton* mButton24Ptr;
static ZKButton* mButton1Ptr;
static ZKTextView* mTextViewTimeOpen4Ptr;
static ZKTextView* mTextView32Ptr;
static ZKWindow* mWindowCtlHumTime2Ptr;
static ZKTextView* mTextView31Ptr;
static ZKButton* mButton23Ptr;
static ZKTextView* mTextView30Ptr;
static ZKButton* mButton22Ptr;
static ZKTextView* mTextViewHumdity1Ptr;
static ZKButton* mButton21Ptr;
static ZKTextView* mTextView28Ptr;
static ZKButton* mButton20Ptr;
static ZKTextView* mTextViewTimeClose3Ptr;
static ZKTextView* mTextView25Ptr;
static ZKButton* mButton19Ptr;
static ZKButton* mButton10Ptr;
static ZKTextView* mTextViewTimeOpen3Ptr;
static ZKTextView* mTextView19Ptr;
static ZKWindow* mWindowCtlHumTime1Ptr;
static ZKTextView* mTextViewStrong2Ptr;
static ZKButton* mButton18Ptr;
static ZKTextView* mTextViewWeak2Ptr;
static ZKButton* mButton17Ptr;
static ZKTextView* mTextViewWind2Ptr;
static ZKTextView* mTextViewRepAir2Ptr;
static ZKTextView* mTextViewHotRep2Ptr;
static ZKButton* mButton16Ptr;
static ZKTextView* mTextViewAuto2Ptr;
static ZKButton* mButton15Ptr;
static ZKTextView* mTextViewMode2Ptr;
static ZKButton* mButton14Ptr;
static ZKTextView* mTextView26Ptr;
static ZKButton* mButton13Ptr;
static ZKTextView* mTextViewTimeClose2Ptr;
static ZKTextView* mTextView24Ptr;
static ZKButton* mButton12Ptr;
static ZKButton* mButton11Ptr;
static ZKTextView* mTextViewTimeOpen2Ptr;
static ZKTextView* mTextView21Ptr;
static ZKWindow* mWindowWindTime2Ptr;
static ZKTextView* mTextViewStrongPtr;
static ZKButton* mButton9Ptr;
static ZKTextView* mTextViewWeakPtr;
static ZKButton* mButton8Ptr;
static ZKTextView* mTextViewWindPtr;
static ZKTextView* mTextViewRepAirPtr;
static ZKTextView* mTextViewHotRepPtr;
static ZKButton* mButton7Ptr;
static ZKTextView* mTextViewAutoPtr;
static ZKButton* mButton6Ptr;
static ZKTextView* mTextViewModePtr;
static ZKButton* mButton5Ptr;
static ZKTextView* mTextView22Ptr;
static ZKButton* mButton4Ptr;
static ZKTextView* mTextViewTimeClosePtr;
static ZKTextView* mTextView20Ptr;
static ZKButton* mButton3Ptr;
static ZKButton* mButton2Ptr;
static ZKTextView* mTextViewTimeOpenPtr;
static ZKTextView* mTextView18Ptr;
static ZKWindow* mWindowWindTime1Ptr;
static ZKTextView* mTextView17Ptr;
static ZKButton* mButtonAdd6Ptr;
static ZKTextView* mTextView16Ptr;
static ZKButton* mButtonDel6Ptr;
static ZKTextView* mTextViewTemp2Ptr;
static ZKButton* mButtonAdd5Ptr;
static ZKTextView* mTextView14Ptr;
static ZKButton* mButtonDel5Ptr;
static ZKTextView* mTextViewTimeClose6Ptr;
static ZKTextView* mTextView12Ptr;
static ZKButton* mButtonAdd4Ptr;
static ZKButton* mButtonDel4Ptr;
static ZKTextView* mTextViewTimeOpen6Ptr;
static ZKTextView* mTextView10Ptr;
static ZKWindow* mWindowAirTime2Ptr;
static ZKTextView* mTextView9Ptr;
static ZKButton* mButtonAdd3Ptr;
static ZKTextView* mTextView8Ptr;
static ZKButton* mButtonDel3Ptr;
static ZKTextView* mTextViewTemp1Ptr;
static ZKButton* mButtonAdd2Ptr;
static ZKTextView* mTextView6Ptr;
static ZKButton* mButtonDel2Ptr;
static ZKTextView* mTextViewTimeClose5Ptr;
static ZKTextView* mTextView4Ptr;
static ZKButton* mButtonAdd1Ptr;
static ZKButton* mButtonDel1Ptr;
static ZKTextView* mTextViewTimeOpen5Ptr;
static ZKTextView* mTextView2Ptr;
static ZKWindow* mWindowAirTime1Ptr;
static ZKButton* mButtonSunPtr;
static ZKButton* mButtonSatPtr;
static ZKButton* mButtonFriPtr;
static ZKButton* mButtonThuePtr;
static ZKButton* mButtonWenPtr;
static ZKButton* mButtonTuesPtr;
static ZKButton* mButtonMonPtr;
static ZKButton* mButtonEveryDayPtr;
static ZKWindow* mWindowWeekPtr;
static ZKButton* mButtonAddTimePtr;
static ZKTextView* mTextView1Ptr;
static ZKWindow* mWindowContentPtr;
static ZKWindow* mWindowDispPtr;
static ZKWindow* mWindowMainPtr;
static ZKWindow* mWindowBGPtr;
static AddTimeSettingActivity* mActivityPtr;

/*register activity*/
REGISTER_ACTIVITY(AddTimeSettingActivity);

typedef struct {
	int id; // 定时器ID ， 不能重复
	int time; // 定时器  时间间隔  单位 毫秒
}S_ACTIVITY_TIMEER;

#include "logic/AddTimeSettingLogic.cc"

/***********/
typedef struct {
    int id;
    const char *pApp;
} SAppInfo;

/**
 *点击跳转window
 */
static SAppInfo sAppInfoTab[] = {
//  { ID_MAIN_TEXT, "TextViewActivity" },
};

/***************/
typedef bool (*ButtonCallback)(ZKButton *pButton);
/**
 * button onclick表
 */
typedef struct {
    int id;
    ButtonCallback callback;
}S_ButtonCallback;

/*TAG:ButtonCallbackTab按键映射表*/
static S_ButtonCallback sButtonCallbackTab[] = {
    ID_ADDTIMESETTING_ButtonStage2, onButtonClick_ButtonStage2,
    ID_ADDTIMESETTING_ButtonStage1, onButtonClick_ButtonStage1,
    ID_ADDTIMESETTING_ButtonConfire, onButtonClick_ButtonConfire,
    ID_ADDTIMESETTING_ButtonCancel, onButtonClick_ButtonCancel,
    ID_ADDTIMESETTING_Button28, onButtonClick_Button28,
    ID_ADDTIMESETTING_Button27, onButtonClick_Button27,
    ID_ADDTIMESETTING_Button26, onButtonClick_Button26,
    ID_ADDTIMESETTING_Button25, onButtonClick_Button25,
    ID_ADDTIMESETTING_Button24, onButtonClick_Button24,
    ID_ADDTIMESETTING_Button1, onButtonClick_Button1,
    ID_ADDTIMESETTING_Button23, onButtonClick_Button23,
    ID_ADDTIMESETTING_Button22, onButtonClick_Button22,
    ID_ADDTIMESETTING_Button21, onButtonClick_Button21,
    ID_ADDTIMESETTING_Button20, onButtonClick_Button20,
    ID_ADDTIMESETTING_Button19, onButtonClick_Button19,
    ID_ADDTIMESETTING_Button10, onButtonClick_Button10,
    ID_ADDTIMESETTING_Button18, onButtonClick_Button18,
    ID_ADDTIMESETTING_Button17, onButtonClick_Button17,
    ID_ADDTIMESETTING_Button16, onButtonClick_Button16,
    ID_ADDTIMESETTING_Button15, onButtonClick_Button15,
    ID_ADDTIMESETTING_Button14, onButtonClick_Button14,
    ID_ADDTIMESETTING_Button13, onButtonClick_Button13,
    ID_ADDTIMESETTING_Button12, onButtonClick_Button12,
    ID_ADDTIMESETTING_Button11, onButtonClick_Button11,
    ID_ADDTIMESETTING_Button9, onButtonClick_Button9,
    ID_ADDTIMESETTING_Button8, onButtonClick_Button8,
    ID_ADDTIMESETTING_Button7, onButtonClick_Button7,
    ID_ADDTIMESETTING_Button6, onButtonClick_Button6,
    ID_ADDTIMESETTING_Button5, onButtonClick_Button5,
    ID_ADDTIMESETTING_Button4, onButtonClick_Button4,
    ID_ADDTIMESETTING_Button3, onButtonClick_Button3,
    ID_ADDTIMESETTING_Button2, onButtonClick_Button2,
    ID_ADDTIMESETTING_ButtonAdd6, onButtonClick_ButtonAdd6,
    ID_ADDTIMESETTING_ButtonDel6, onButtonClick_ButtonDel6,
    ID_ADDTIMESETTING_ButtonAdd5, onButtonClick_ButtonAdd5,
    ID_ADDTIMESETTING_ButtonDel5, onButtonClick_ButtonDel5,
    ID_ADDTIMESETTING_ButtonAdd4, onButtonClick_ButtonAdd4,
    ID_ADDTIMESETTING_ButtonDel4, onButtonClick_ButtonDel4,
    ID_ADDTIMESETTING_ButtonAdd3, onButtonClick_ButtonAdd3,
    ID_ADDTIMESETTING_ButtonDel3, onButtonClick_ButtonDel3,
    ID_ADDTIMESETTING_ButtonAdd2, onButtonClick_ButtonAdd2,
    ID_ADDTIMESETTING_ButtonDel2, onButtonClick_ButtonDel2,
    ID_ADDTIMESETTING_ButtonAdd1, onButtonClick_ButtonAdd1,
    ID_ADDTIMESETTING_ButtonDel1, onButtonClick_ButtonDel1,
    ID_ADDTIMESETTING_ButtonSun, onButtonClick_ButtonSun,
    ID_ADDTIMESETTING_ButtonSat, onButtonClick_ButtonSat,
    ID_ADDTIMESETTING_ButtonFri, onButtonClick_ButtonFri,
    ID_ADDTIMESETTING_ButtonThue, onButtonClick_ButtonThue,
    ID_ADDTIMESETTING_ButtonWen, onButtonClick_ButtonWen,
    ID_ADDTIMESETTING_ButtonTues, onButtonClick_ButtonTues,
    ID_ADDTIMESETTING_ButtonMon, onButtonClick_ButtonMon,
    ID_ADDTIMESETTING_ButtonEveryDay, onButtonClick_ButtonEveryDay,
    ID_ADDTIMESETTING_ButtonAddTime, onButtonClick_ButtonAddTime,
};
/***************/


typedef void (*SeekBarCallback)(ZKSeekBar *pSeekBar, int progress);
typedef struct {
    int id;
    SeekBarCallback callback;
}S_ZKSeekBarCallback;
/*TAG:SeekBarCallbackTab*/
static S_ZKSeekBarCallback SZKSeekBarCallbackTab[] = {
};


typedef int (*ListViewGetItemCountCallback)(const ZKListView *pListView);
typedef void (*ListViewobtainListItemDataCallback)(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index);
typedef void (*ListViewonItemClickCallback)(ZKListView *pListView, int index, int id);
typedef struct {
    int id;
    ListViewGetItemCountCallback getListItemCountCallback;
    ListViewobtainListItemDataCallback obtainListItemDataCallback;
    ListViewonItemClickCallback onItemClickCallback;
}S_ListViewFunctionsCallback;
/*TAG:ListViewFunctionsCallback*/
static S_ListViewFunctionsCallback SListViewFunctionsCallbackTab[] = {
};


typedef void (*SlideWindowItemClickCallback)(ZKSlideWindow *pSlideWindow, int index);
typedef struct {
    int id;
    SlideWindowItemClickCallback onSlideItemClickCallback;
}S_SlideWindowItemClickCallback;
/*TAG:SlideWindowFunctionsCallbackTab*/
static S_SlideWindowItemClickCallback SSlideWindowItemClickCallbackTab[] = {
};


typedef void (*EditTextInputCallback)(const std::string &text);
typedef struct {
    int id;
    EditTextInputCallback onEditTextChangedCallback;
}S_EditTextInputCallback;
/*TAG:EditTextInputCallback*/
static S_EditTextInputCallback SEditTextInputCallbackTab[] = {
};

typedef void (*VideoViewCallback)(ZKVideoView *pVideoView, int msg);
typedef struct {
    int id; //VideoView ID
    bool loop; // 是否是轮播类型
    int defaultvolume;//轮播类型时,默认视频音量
    VideoViewCallback onVideoViewCallback;
}S_VideoViewCallback;
/*TAG:VideoViewCallback*/
static S_VideoViewCallback SVideoViewCallbackTab[] = {
};


AddTimeSettingActivity::AddTimeSettingActivity() {
	//todo add init code here
	mVideoLoopIndex = -1;
	mVideoLoopErrorCount = 0;
}

AddTimeSettingActivity::~AddTimeSettingActivity() {
  //todo add init file here
  // 退出应用时需要反注册
    EASYUICONTEXT->unregisterGlobalTouchListener(this);
    onUI_quit();
    unregisterProtocolDataUpdateListener(onProtocolDataUpdate);
}

const char* AddTimeSettingActivity::getAppName() const{
	return "AddTimeSetting.ftu";
}

//TAG:onCreate
void AddTimeSettingActivity::onCreate() {
	Activity::onCreate();
    mButtonStage2Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_ButtonStage2);
    mButtonStage1Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_ButtonStage1);
    mButtonConfirePtr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_ButtonConfire);
    mButtonCancelPtr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_ButtonCancel);
    mWindowSLPtr = (ZKWindow*)findControlByID(ID_ADDTIMESETTING_WindowSL);
    mTextView7Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextView7);
    mTextView5Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextView5);
    mTextView3Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextView3);
    mWindowRollPtr = (ZKWindow*)findControlByID(ID_ADDTIMESETTING_WindowRoll);
    mTextView39Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextView39);
    mButton28Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_Button28);
    mTextView38Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextView38);
    mButton27Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_Button27);
    mTextViewHumdity2Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextViewHumdity2);
    mButton26Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_Button26);
    mTextView36Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextView36);
    mButton25Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_Button25);
    mTextViewTimeClose4Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextViewTimeClose4);
    mTextView34Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextView34);
    mButton24Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_Button24);
    mButton1Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_Button1);
    mTextViewTimeOpen4Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextViewTimeOpen4);
    mTextView32Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextView32);
    mWindowCtlHumTime2Ptr = (ZKWindow*)findControlByID(ID_ADDTIMESETTING_WindowCtlHumTime2);
    mTextView31Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextView31);
    mButton23Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_Button23);
    mTextView30Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextView30);
    mButton22Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_Button22);
    mTextViewHumdity1Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextViewHumdity1);
    mButton21Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_Button21);
    mTextView28Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextView28);
    mButton20Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_Button20);
    mTextViewTimeClose3Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextViewTimeClose3);
    mTextView25Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextView25);
    mButton19Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_Button19);
    mButton10Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_Button10);
    mTextViewTimeOpen3Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextViewTimeOpen3);
    mTextView19Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextView19);
    mWindowCtlHumTime1Ptr = (ZKWindow*)findControlByID(ID_ADDTIMESETTING_WindowCtlHumTime1);
    mTextViewStrong2Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextViewStrong2);
    mButton18Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_Button18);
    mTextViewWeak2Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextViewWeak2);
    mButton17Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_Button17);
    mTextViewWind2Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextViewWind2);
    mTextViewRepAir2Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextViewRepAir2);
    mTextViewHotRep2Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextViewHotRep2);
    mButton16Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_Button16);
    mTextViewAuto2Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextViewAuto2);
    mButton15Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_Button15);
    mTextViewMode2Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextViewMode2);
    mButton14Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_Button14);
    mTextView26Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextView26);
    mButton13Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_Button13);
    mTextViewTimeClose2Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextViewTimeClose2);
    mTextView24Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextView24);
    mButton12Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_Button12);
    mButton11Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_Button11);
    mTextViewTimeOpen2Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextViewTimeOpen2);
    mTextView21Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextView21);
    mWindowWindTime2Ptr = (ZKWindow*)findControlByID(ID_ADDTIMESETTING_WindowWindTime2);
    mTextViewStrongPtr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextViewStrong);
    mButton9Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_Button9);
    mTextViewWeakPtr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextViewWeak);
    mButton8Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_Button8);
    mTextViewWindPtr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextViewWind);
    mTextViewRepAirPtr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextViewRepAir);
    mTextViewHotRepPtr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextViewHotRep);
    mButton7Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_Button7);
    mTextViewAutoPtr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextViewAuto);
    mButton6Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_Button6);
    mTextViewModePtr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextViewMode);
    mButton5Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_Button5);
    mTextView22Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextView22);
    mButton4Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_Button4);
    mTextViewTimeClosePtr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextViewTimeClose);
    mTextView20Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextView20);
    mButton3Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_Button3);
    mButton2Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_Button2);
    mTextViewTimeOpenPtr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextViewTimeOpen);
    mTextView18Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextView18);
    mWindowWindTime1Ptr = (ZKWindow*)findControlByID(ID_ADDTIMESETTING_WindowWindTime1);
    mTextView17Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextView17);
    mButtonAdd6Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_ButtonAdd6);
    mTextView16Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextView16);
    mButtonDel6Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_ButtonDel6);
    mTextViewTemp2Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextViewTemp2);
    mButtonAdd5Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_ButtonAdd5);
    mTextView14Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextView14);
    mButtonDel5Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_ButtonDel5);
    mTextViewTimeClose6Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextViewTimeClose6);
    mTextView12Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextView12);
    mButtonAdd4Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_ButtonAdd4);
    mButtonDel4Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_ButtonDel4);
    mTextViewTimeOpen6Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextViewTimeOpen6);
    mTextView10Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextView10);
    mWindowAirTime2Ptr = (ZKWindow*)findControlByID(ID_ADDTIMESETTING_WindowAirTime2);
    mTextView9Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextView9);
    mButtonAdd3Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_ButtonAdd3);
    mTextView8Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextView8);
    mButtonDel3Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_ButtonDel3);
    mTextViewTemp1Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextViewTemp1);
    mButtonAdd2Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_ButtonAdd2);
    mTextView6Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextView6);
    mButtonDel2Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_ButtonDel2);
    mTextViewTimeClose5Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextViewTimeClose5);
    mTextView4Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextView4);
    mButtonAdd1Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_ButtonAdd1);
    mButtonDel1Ptr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_ButtonDel1);
    mTextViewTimeOpen5Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextViewTimeOpen5);
    mTextView2Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextView2);
    mWindowAirTime1Ptr = (ZKWindow*)findControlByID(ID_ADDTIMESETTING_WindowAirTime1);
    mButtonSunPtr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_ButtonSun);
    mButtonSatPtr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_ButtonSat);
    mButtonFriPtr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_ButtonFri);
    mButtonThuePtr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_ButtonThue);
    mButtonWenPtr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_ButtonWen);
    mButtonTuesPtr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_ButtonTues);
    mButtonMonPtr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_ButtonMon);
    mButtonEveryDayPtr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_ButtonEveryDay);
    mWindowWeekPtr = (ZKWindow*)findControlByID(ID_ADDTIMESETTING_WindowWeek);
    mButtonAddTimePtr = (ZKButton*)findControlByID(ID_ADDTIMESETTING_ButtonAddTime);
    mTextView1Ptr = (ZKTextView*)findControlByID(ID_ADDTIMESETTING_TextView1);
    mWindowContentPtr = (ZKWindow*)findControlByID(ID_ADDTIMESETTING_WindowContent);
    mWindowDispPtr = (ZKWindow*)findControlByID(ID_ADDTIMESETTING_WindowDisp);
    mWindowMainPtr = (ZKWindow*)findControlByID(ID_ADDTIMESETTING_WindowMain);
    mWindowBGPtr = (ZKWindow*)findControlByID(ID_ADDTIMESETTING_WindowBG);
	mActivityPtr = this;
	onUI_init();
    registerProtocolDataUpdateListener(onProtocolDataUpdate); 
    rigesterActivityTimer();
}

void AddTimeSettingActivity::onClick(ZKBase *pBase) {
	//TODO: add widget onClik code 
    int buttonTablen = sizeof(sButtonCallbackTab) / sizeof(S_ButtonCallback);
    for (int i = 0; i < buttonTablen; ++i) {
        if (sButtonCallbackTab[i].id == pBase->getID()) {
            if (sButtonCallbackTab[i].callback((ZKButton*)pBase)) {
            	return;
            }
            break;
        }
    }


    int len = sizeof(sAppInfoTab) / sizeof(sAppInfoTab[0]);
    for (int i = 0; i < len; ++i) {
        if (sAppInfoTab[i].id == pBase->getID()) {
            EASYUICONTEXT->openActivity(sAppInfoTab[i].pApp);
            return;
        }
    }

	Activity::onClick(pBase);
}

void AddTimeSettingActivity::onResume() {
	Activity::onResume();
	EASYUICONTEXT->registerGlobalTouchListener(this);
	startVideoLoopPlayback();
	onUI_show();
}

void AddTimeSettingActivity::onPause() {
	Activity::onPause();
	EASYUICONTEXT->unregisterGlobalTouchListener(this);
	stopVideoLoopPlayback();
	onUI_hide();
}

void AddTimeSettingActivity::onIntent(const Intent *intentPtr) {
	Activity::onIntent(intentPtr);
	onUI_intent(intentPtr);
}

bool AddTimeSettingActivity::onTimer(int id) {
	return onUI_Timer(id);
}

void AddTimeSettingActivity::onProgressChanged(ZKSeekBar *pSeekBar, int progress){

    int seekBarTablen = sizeof(SZKSeekBarCallbackTab) / sizeof(S_ZKSeekBarCallback);
    for (int i = 0; i < seekBarTablen; ++i) {
        if (SZKSeekBarCallbackTab[i].id == pSeekBar->getID()) {
            SZKSeekBarCallbackTab[i].callback(pSeekBar, progress);
            break;
        }
    }
}

int AddTimeSettingActivity::getListItemCount(const ZKListView *pListView) const{
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            return SListViewFunctionsCallbackTab[i].getListItemCountCallback(pListView);
            break;
        }
    }
    return 0;
}

void AddTimeSettingActivity::obtainListItemData(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index){
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            SListViewFunctionsCallbackTab[i].obtainListItemDataCallback(pListView, pListItem, index);
            break;
        }
    }
}

void AddTimeSettingActivity::onItemClick(ZKListView *pListView, int index, int id){
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            SListViewFunctionsCallbackTab[i].onItemClickCallback(pListView, index, id);
            break;
        }
    }
}

void AddTimeSettingActivity::onSlideItemClick(ZKSlideWindow *pSlideWindow, int index) {
    int tablen = sizeof(SSlideWindowItemClickCallbackTab) / sizeof(S_SlideWindowItemClickCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SSlideWindowItemClickCallbackTab[i].id == pSlideWindow->getID()) {
            SSlideWindowItemClickCallbackTab[i].onSlideItemClickCallback(pSlideWindow, index);
            break;
        }
    }
}

bool AddTimeSettingActivity::onTouchEvent(const MotionEvent &ev) {
    return onAddTimeSettingActivityTouchEvent(ev);
}

void AddTimeSettingActivity::onTextChanged(ZKTextView *pTextView, const std::string &text) {
    int tablen = sizeof(SEditTextInputCallbackTab) / sizeof(S_EditTextInputCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SEditTextInputCallbackTab[i].id == pTextView->getID()) {
            SEditTextInputCallbackTab[i].onEditTextChangedCallback(text);
            break;
        }
    }
}

void AddTimeSettingActivity::rigesterActivityTimer() {
    int tablen = sizeof(REGISTER_ACTIVITY_TIMER_TAB) / sizeof(S_ACTIVITY_TIMEER);
    for (int i = 0; i < tablen; ++i) {
        S_ACTIVITY_TIMEER temp = REGISTER_ACTIVITY_TIMER_TAB[i];
        registerTimer(temp.id, temp.time);
    }
}


void AddTimeSettingActivity::onVideoPlayerMessage(ZKVideoView *pVideoView, int msg) {
    int tablen = sizeof(SVideoViewCallbackTab) / sizeof(S_VideoViewCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SVideoViewCallbackTab[i].id == pVideoView->getID()) {
        	if (SVideoViewCallbackTab[i].loop) {
                //循环播放
        		videoLoopPlayback(pVideoView, msg, i);
        	} else if (SVideoViewCallbackTab[i].onVideoViewCallback != NULL){
        	    SVideoViewCallbackTab[i].onVideoViewCallback(pVideoView, msg);
        	}
            break;
        }
    }
}

void AddTimeSettingActivity::videoLoopPlayback(ZKVideoView *pVideoView, int msg, size_t callbackTabIndex) {

	switch (msg) {
	case ZKVideoView::E_MSGTYPE_VIDEO_PLAY_STARTED:
		LOGD("ZKVideoView::E_MSGTYPE_VIDEO_PLAY_STARTED\n");
    if (callbackTabIndex >= (sizeof(SVideoViewCallbackTab)/sizeof(S_VideoViewCallback))) {
      break;
    }
		pVideoView->setVolume(SVideoViewCallbackTab[callbackTabIndex].defaultvolume / 10.0);
		mVideoLoopErrorCount = 0;
		break;
	case ZKVideoView::E_MSGTYPE_VIDEO_PLAY_ERROR:
		/**错误处理 */
		++mVideoLoopErrorCount;
		if (mVideoLoopErrorCount > 100) {
			LOGD("video loop error counts > 100, quit loop playback !");
            break;
		} //不用break, 继续尝试播放下一个
	case ZKVideoView::E_MSGTYPE_VIDEO_PLAY_COMPLETED:
		LOGD("ZKVideoView::E_MSGTYPE_VIDEO_PLAY_COMPLETED\n");
        std::vector<std::string> videolist;
        std::string fileName(getAppName());
        if (fileName.size() < 4) {
             LOGD("getAppName size < 4, ignore!");
             break;
        }
        fileName = fileName.substr(0, fileName.length() - 4) + "_video_list.txt";
        fileName = "/mnt/extsd/" + fileName;
        if (!parseVideoFileList(fileName.c_str(), videolist)) {
            LOGD("parseVideoFileList failed !");
		    break;
        }
		if (pVideoView && !videolist.empty()) {
			mVideoLoopIndex = (mVideoLoopIndex + 1) % videolist.size();
			pVideoView->play(videolist[mVideoLoopIndex].c_str());
		}
		break;
	}
}

void AddTimeSettingActivity::startVideoLoopPlayback() {
    int tablen = sizeof(SVideoViewCallbackTab) / sizeof(S_VideoViewCallback);
    for (int i = 0; i < tablen; ++i) {
    	if (SVideoViewCallbackTab[i].loop) {
    		ZKVideoView* videoView = (ZKVideoView*)findControlByID(SVideoViewCallbackTab[i].id);
    		if (!videoView) {
    			return;
    		}
    		//循环播放
    		videoLoopPlayback(videoView, ZKVideoView::E_MSGTYPE_VIDEO_PLAY_COMPLETED, i);
    		return;
    	}
    }
}

void AddTimeSettingActivity::stopVideoLoopPlayback() {
    int tablen = sizeof(SVideoViewCallbackTab) / sizeof(S_VideoViewCallback);
    for (int i = 0; i < tablen; ++i) {
    	if (SVideoViewCallbackTab[i].loop) {
    		ZKVideoView* videoView = (ZKVideoView*)findControlByID(SVideoViewCallbackTab[i].id);
    		if (!videoView) {
    			return;
    		}
    		if (videoView->isPlaying()) {
    		    videoView->stop();
    		}
    		return;
    	}
    }
}

bool AddTimeSettingActivity::parseVideoFileList(const char *pFileListPath, std::vector<string>& mediaFileList) {
	mediaFileList.clear();
	if (NULL == pFileListPath || 0 == strlen(pFileListPath)) {
        LOGD("video file list is null!");
		return false;
	}

	ifstream is(pFileListPath, ios_base::in);
	if (!is.is_open()) {
		LOGD("cann't open file %s \n", pFileListPath);
		return false;
	}
	char tmp[1024] = {0};
	while (is.getline(tmp, sizeof(tmp))) {
		string str = tmp;
		removeCharFromString(str, '\"');
		removeCharFromString(str, '\r');
		removeCharFromString(str, '\n');
		if (str.size() > 1) {
     		mediaFileList.push_back(str.c_str());
		}
	}
	LOGD("(f:%s, l:%d) parse fileList[%s], get [%d]files\n", __FUNCTION__,
			__LINE__, pFileListPath, mediaFileList.size());
	for (size_t i = 0; i < mediaFileList.size(); i++) {
		LOGD("file[%d]:[%s]\n", i, mediaFileList[i].c_str());
	}
	is.close();

	return true;
}

int AddTimeSettingActivity::removeCharFromString(string& nString, char c) {
    string::size_type   pos;
    while(1) {
        pos = nString.find(c);
        if(pos != string::npos) {
            nString.erase(pos, 1);
        } else {
            break;
        }
    }
    return (int)nString.size();
}

void AddTimeSettingActivity::registerUserTimer(int id, int time) {
	registerTimer(id, time);
}

void AddTimeSettingActivity::unregisterUserTimer(int id) {
	unregisterTimer(id);
}

void AddTimeSettingActivity::resetUserTimer(int id, int time) {
	resetTimer(id, time);
}