/***********************************************
/gen auto by zuitools
***********************************************/
#include "mainActivity.h"
#include "util/MyNetWorkingListener.h"

/*TAG:GlobalVariable全局变量*/
static ZKTextView* mTextView62Ptr;
static ZKTextView* mTextView61Ptr;
static ZKTextView* mTextView57Ptr;
static ZKSeekBar* mSeekBarSoundPtr;
static ZKWindow* mWindowSoundSeebakPtr;
static ZKTextView* mIconViewFrostPtr;
static ZKTextView* mIconViewFilterPtr;
static ZKTextView* mIconViewTimingPtr;
static ZKButton* mButtonMusicAudioPtr;
static ZKButton* mButtonMusicNextPtr;
static ZKButton* mButtonMusicPlayPtr;
static ZKButton* mButtonMusicPrePtr;
static ZKTextView* mTextView56Ptr;
static ZKTextView* mTextView55Ptr;
static ZKTextView* mTextView54Ptr;
static ZKWindow* mWindowEmergencyCallPtr;
static ZKTextView* mTextView53Ptr;
static ZKTextView* mTextView52Ptr;
static ZKWindow* mWindowImmediaCommunicatePtr;
static ZKWindow* mWindowListViewPtr;
static ZKTextView* mTextView51Ptr;
static ZKTextView* mTextView46Ptr;
static ZKTextView* mTextView45Ptr;
static ZKTextView* mTextView44Ptr;
static ZKWindow* mWindowTVOCPtr;
static ZKButton* mButtonMusicModePtr;
static ZKButton* mButtonMusicPicPtr;
static ZKWindow* mWindowMusicPtr;
static ZKWindow* mWindowTimeWeatherPtr;
static ZKWindow* mWindowIntervalPtr;
static ZKButton* mButtonOneKeyAdjustPtr;
static ZKButton* mButtonEmergencyCallPtr;
static ZKButton* mButtonImmediaCommunicatePtr;
static ZKListView* mListView1Ptr;
static ZKButton* mButtonNetworkConnectPtr;
static ZKTextView* mTextView43Ptr;
static ZKWindow* mWindow24Ptr;
static ZKTextView* mTextView42Ptr;
static ZKTextView* mIconViewWifiPtr;
static ZKTextView* mIconViewAirColdPtr;
static ZKTextView* mIconViewHumdColdPtr;
static ZKTextView* mIconViewHumdDryPtr;
static ZKTextView* mIconViewSecurityPtr;
static ZKWindow* mWindow25Ptr;
static ZKButton* mButtonSelect4Ptr;
static ZKButton* mButtonSelect5Ptr;
static ZKButton* mButtonSelect3Ptr;
static ZKButton* mButtonSelect2Ptr;
static ZKButton* mButtonSelect1Ptr;
static ZKTextView* mTextViewHumidityPtr;
static ZKTextView* mTextView60Ptr;
static ZKWindow* mWindow23Ptr;
static ZKTextView* mTextViewFreshairPtr;
static ZKTextView* mTextView59Ptr;
static ZKWindow* mWindowFreshAirPtr;
static ZKTextView* mTextViewAirPtr;
static ZKTextView* mTextView58Ptr;
static ZKWindow* mWindowAirconditionPtr;
static ZKTextView* mTextViewmcuPtr;
static ZKTextView* mTextViewHistory2Ptr;
static ZKButton* mButtonHistorty2Ptr;
static ZKWindow* mWindow22Ptr;
static ZKTextView* mTextViewManual2Ptr;
static ZKButton* mButtonManual2Ptr;
static ZKWindow* mWindow21Ptr;
static ZKTextView* mTextViewSmart2Ptr;
static ZKButton* mButtonSmart2Ptr;
static ZKWindow* mWindow20Ptr;
static ZKTextView* mTextViewHomepage2Ptr;
static ZKButton* mButtonHomepage2Ptr;
static ZKWindow* mWindow19Ptr;
static ZKWindow* mWindowNavibar2Ptr;
static ZKButton* mButtonDropDownPtr;
static ZKButton* mButton8Ptr;
static ZKButton* mButton2Ptr;
static ZKWindow* mWindowModeSelect2Ptr;
static ZKWindow* mWindowMainStatusPtr;
static ZKWindow* mWindowModeSelect1Ptr;
static ZKWindow* mWindowBGPtr;
static ZKTextView* mTextView50Ptr;
static ZKTextView* mTextView49Ptr;
static ZKTextView* mTextView48Ptr;
static ZKTextView* mTextView47Ptr;
static ZKTextView* mTextView40Ptr;
static ZKTextView* mTextViewWifiPtr;
static ZKButton* mButton1Ptr;
static ZKButton* mButton7Ptr;
static ZKButton* mButton6Ptr;
static ZKTextView* mTextView39Ptr;
static ZKWindow* mWindow13Ptr;
static ZKButton* mButton5Ptr;
static ZKTextView* mTextView38Ptr;
static ZKWindow* mWindow11Ptr;
static ZKButton* mButton4Ptr;
static ZKTextView* mTextView37Ptr;
static ZKWindow* mWindow10Ptr;
static ZKButton* mButton3Ptr;
static ZKButton* mButtonOFFPtr;
static ZKButton* mButtonONPtr;
static ZKTextView* mTextView35Ptr;
static ZKTextView* mTextView34Ptr;
static ZKTextView* mTextView33Ptr;
static ZKTextView* mTextView32Ptr;
static ZKWindow* mWindowCO2Ptr;
static ZKTextView* mTextView28Ptr;
static ZKTextView* mTextView31Ptr;
static ZKTextView* mTextView30Ptr;
static ZKTextView* mTextView29Ptr;
static ZKWindow* mWindowFormaldehydePtr;
static ZKTextView* mTextView27Ptr;
static ZKTextView* mTextView26Ptr;
static ZKTextView* mTextView25Ptr;
static ZKTextView* mTextView24Ptr;
static ZKWindow* mWindowTempPtr;
static ZKTextView* mTextView23Ptr;
static ZKTextView* mTextView22Ptr;
static ZKTextView* mTextView21Ptr;
static ZKTextView* mTextView20Ptr;
static ZKWindow* mWindowPM25Ptr;
static ZKTextView* mTextView36Ptr;
static ZKTextView* mTextView19Ptr;
static ZKTextView* mTextView18Ptr;
static ZKTextView* mTextView17Ptr;
static ZKWindow* mWindowHumidityPtr;
static ZKWindow* mWindow9Ptr;
static ZKTextView* mTextView16Ptr;
static ZKTextView* mTextView15Ptr;
static ZKTextView* mTextView14Ptr;
static ZKWindow* mWindow8Ptr;
static ZKWindow* mWindow7Ptr;
static ZKTextView* mTextView13Ptr;
static ZKTextView* mTextView12Ptr;
static ZKTextView* mTextView11Ptr;
static ZKTextView* mTextView10Ptr;
static ZKTextView* mTextView9Ptr;
static ZKTextView* mTextView8Ptr;
static ZKTextView* mTextView7Ptr;
static ZKWindow* mWindow6Ptr;
static ZKTextView* mTextView6Ptr;
static ZKTextView* mTextView5Ptr;
static ZKWindow* mWindow5Ptr;
static ZKTextView* mTextView41Ptr;
static ZKButton* mButtonHistorty1Ptr;
static ZKTextView* mTextView4Ptr;
static ZKButton* mButtonHistortyPtr;
static ZKWindow* mWindowHistortyPtr;
static ZKButton* mButtonManual1Ptr;
static ZKTextView* mTextView3Ptr;
static ZKButton* mButtonManualPtr;
static ZKWindow* mWindowManualPtr;
static ZKButton* mButtonSmart1Ptr;
static ZKTextView* mTextView2Ptr;
static ZKButton* mButtonSmartPtr;
static ZKWindow* mWindowSmartPtr;
static ZKButton* mButtonHomepage1Ptr;
static ZKTextView* mTextView1Ptr;
static ZKButton* mButtonHomepagePtr;
static ZKWindow* mWindowHomepagePtr;
static ZKWindow* mWindow2Ptr;
static mainActivity* mActivityPtr;

static ZKWindow* mWindowSelectModePtr[5];
static ZKButton* mButtonModeSelect[5];
static ZKTextView* mTextModeSelectPic[5];
static ZKTextView* mTextModeSelectTitle[5];
static ZKTextView* mTextModeSelectRecvData[5];
static ZKTextView* mTextModeSelectString[5];

MyNetWorkingListener *nwlistener = NULL;


//static ZKWindow* mWindowsSelectMode[5] = {mWindowHumidityPtr, mWindowPM25Ptr, mWindowTempPtr, mWindowCO2Ptr, mWindowFormaldehydePtr};
//static ZKButton* mButtonModeSelect[5] = {mButtonSelect1Ptr, mButtonSelect2Ptr, mButtonSelect3Ptr, mButtonSelect4Ptr, mButtonSelect5Ptr};
typedef struct {
	const char* maintext;
	const char* mainpic;
	bool buttonstatus;
}EnvInfo;




/*register activity*/
REGISTER_ACTIVITY(mainActivity);
typedef struct {
	int id; // 定时器ID ， 不能重复
	int time; // 定时器  时间间隔  单位 毫秒
}S_ACTIVITY_TIMEER;

#include "logic/mainLogic.cc"

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
    ID_MAIN_ButtonMusicAudio, onButtonClick_ButtonMusicAudio,
    ID_MAIN_ButtonMusicNext, onButtonClick_ButtonMusicNext,
    ID_MAIN_ButtonMusicPlay, onButtonClick_ButtonMusicPlay,
    ID_MAIN_ButtonMusicPre, onButtonClick_ButtonMusicPre,
    ID_MAIN_ButtonMusicMode, onButtonClick_ButtonMusicMode,
    ID_MAIN_ButtonMusicPic, onButtonClick_ButtonMusicPic,
    ID_MAIN_ButtonOneKeyAdjust, onButtonClick_ButtonOneKeyAdjust,
    ID_MAIN_ButtonEmergencyCall, onButtonClick_ButtonEmergencyCall,
    ID_MAIN_ButtonImmediaCommunicate, onButtonClick_ButtonImmediaCommunicate,
    ID_MAIN_ButtonNetworkConnect, onButtonClick_ButtonNetworkConnect,
    ID_MAIN_ButtonSelect4, onButtonClick_ButtonSelect4,
    ID_MAIN_ButtonSelect5, onButtonClick_ButtonSelect5,
    ID_MAIN_ButtonSelect3, onButtonClick_ButtonSelect3,
    ID_MAIN_ButtonSelect2, onButtonClick_ButtonSelect2,
    ID_MAIN_ButtonSelect1, onButtonClick_ButtonSelect1,
    ID_MAIN_ButtonHistorty2, onButtonClick_ButtonHistorty2,
    ID_MAIN_ButtonManual2, onButtonClick_ButtonManual2,
    ID_MAIN_ButtonSmart2, onButtonClick_ButtonSmart2,
    ID_MAIN_ButtonHomepage2, onButtonClick_ButtonHomepage2,
    ID_MAIN_ButtonDropDown, onButtonClick_ButtonDropDown,
    ID_MAIN_Button8, onButtonClick_Button8,
    ID_MAIN_Button2, onButtonClick_Button2,
    ID_MAIN_Button1, onButtonClick_Button1,
    ID_MAIN_Button7, onButtonClick_Button7,
    ID_MAIN_Button6, onButtonClick_Button6,
    ID_MAIN_Button5, onButtonClick_Button5,
    ID_MAIN_Button4, onButtonClick_Button4,
    ID_MAIN_Button3, onButtonClick_Button3,
    ID_MAIN_ButtonOFF, onButtonClick_ButtonOFF,
    ID_MAIN_ButtonON, onButtonClick_ButtonON,
    ID_MAIN_ButtonHistorty1, onButtonClick_ButtonHistorty1,
    ID_MAIN_ButtonHistorty, onButtonClick_ButtonHistorty,
    ID_MAIN_ButtonManual1, onButtonClick_ButtonManual1,
    ID_MAIN_ButtonManual, onButtonClick_ButtonManual,
    ID_MAIN_ButtonSmart1, onButtonClick_ButtonSmart1,
    ID_MAIN_ButtonSmart, onButtonClick_ButtonSmart,
    ID_MAIN_ButtonHomepage1, onButtonClick_ButtonHomepage1,
    ID_MAIN_ButtonHomepage, onButtonClick_ButtonHomepage,
};
/***************/


typedef void (*SeekBarCallback)(ZKSeekBar *pSeekBar, int progress);
typedef struct {
    int id;
    SeekBarCallback callback;
}S_ZKSeekBarCallback;
/*TAG:SeekBarCallbackTab*/
static S_ZKSeekBarCallback SZKSeekBarCallbackTab[] = {
    ID_MAIN_SeekBarSound, onProgressChanged_SeekBarSound,
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
    ID_MAIN_ListView1, getListItemCount_ListView1, obtainListItemData_ListView1, onListItemClick_ListView1,
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


mainActivity::mainActivity() {
	//todo add init code here
	mVideoLoopIndex = -1;
	mVideoLoopErrorCount = 0;
}

mainActivity::~mainActivity() {
  //todo add init file here
  // 退出应用时需要反注册
    EASYUICONTEXT->unregisterGlobalTouchListener(this);
//    nwlistener->removeNetWorkListener(this);
//	if(nwlistener)
//	{
//		nwlistener->requestExitAndWait();
//		delete nwlistener;
//		nwlistener = NULL;
//	}
    onUI_quit();
    unregisterProtocolDataUpdateListener(onProtocolDataUpdate);
}

const char* mainActivity::getAppName() const{
	return "main.ftu";
}

//TAG:onCreate
void mainActivity::onCreate() {
	Activity::onCreate();
    mTextView62Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView62);
    mTextView61Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView61);
    mTextView57Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView57);
    mSeekBarSoundPtr = (ZKSeekBar*)findControlByID(ID_MAIN_SeekBarSound);if(mSeekBarSoundPtr!= NULL){mSeekBarSoundPtr->setSeekBarChangeListener(this);}
    mWindowSoundSeebakPtr = (ZKWindow*)findControlByID(ID_MAIN_WindowSoundSeebak);
    mIconViewFrostPtr = (ZKTextView*)findControlByID(ID_MAIN_IconViewFrost);
    mIconViewFilterPtr = (ZKTextView*)findControlByID(ID_MAIN_IconViewFilter);
    mIconViewTimingPtr = (ZKTextView*)findControlByID(ID_MAIN_IconViewTiming);
    mButtonMusicAudioPtr = (ZKButton*)findControlByID(ID_MAIN_ButtonMusicAudio);
    mButtonMusicNextPtr = (ZKButton*)findControlByID(ID_MAIN_ButtonMusicNext);
    mButtonMusicPlayPtr = (ZKButton*)findControlByID(ID_MAIN_ButtonMusicPlay);
    mButtonMusicPrePtr = (ZKButton*)findControlByID(ID_MAIN_ButtonMusicPre);
    mTextView56Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView56);
    mTextView55Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView55);
    mTextView54Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView54);
    mWindowEmergencyCallPtr = (ZKWindow*)findControlByID(ID_MAIN_WindowEmergencyCall);
    mTextView53Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView53);
    mTextView52Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView52);
    mWindowImmediaCommunicatePtr = (ZKWindow*)findControlByID(ID_MAIN_WindowImmediaCommunicate);
    mWindowListViewPtr = (ZKWindow*)findControlByID(ID_MAIN_WindowListView);
    mTextView51Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView51);
    mTextView46Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView46);
    mTextView45Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView45);
    mTextView44Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView44);
    mWindowTVOCPtr = (ZKWindow*)findControlByID(ID_MAIN_WindowTVOC);
    mButtonMusicModePtr = (ZKButton*)findControlByID(ID_MAIN_ButtonMusicMode);
    mButtonMusicPicPtr = (ZKButton*)findControlByID(ID_MAIN_ButtonMusicPic);
    mWindowMusicPtr = (ZKWindow*)findControlByID(ID_MAIN_WindowMusic);
    mWindowTimeWeatherPtr = (ZKWindow*)findControlByID(ID_MAIN_WindowTimeWeather);
    mWindowIntervalPtr = (ZKWindow*)findControlByID(ID_MAIN_WindowInterval);
    mButtonOneKeyAdjustPtr = (ZKButton*)findControlByID(ID_MAIN_ButtonOneKeyAdjust);
    mButtonEmergencyCallPtr = (ZKButton*)findControlByID(ID_MAIN_ButtonEmergencyCall);
    mButtonImmediaCommunicatePtr = (ZKButton*)findControlByID(ID_MAIN_ButtonImmediaCommunicate);
    mListView1Ptr = (ZKListView*)findControlByID(ID_MAIN_ListView1);if(mListView1Ptr!= NULL){mListView1Ptr->setListAdapter(this);mListView1Ptr->setItemClickListener(this);}
    mButtonNetworkConnectPtr = (ZKButton*)findControlByID(ID_MAIN_ButtonNetworkConnect);
    mTextView43Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView43);
    mWindow24Ptr = (ZKWindow*)findControlByID(ID_MAIN_Window24);
    mTextView42Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView42);
    mIconViewWifiPtr = (ZKTextView*)findControlByID(ID_MAIN_IconViewWifi);
    mIconViewAirColdPtr = (ZKTextView*)findControlByID(ID_MAIN_IconViewAirCold);
    mIconViewHumdColdPtr = (ZKTextView*)findControlByID(ID_MAIN_IconViewHumdCold);
    mIconViewHumdDryPtr = (ZKTextView*)findControlByID(ID_MAIN_IconViewHumdDry);
    mIconViewSecurityPtr = (ZKTextView*)findControlByID(ID_MAIN_IconViewSecurity);
    mWindow25Ptr = (ZKWindow*)findControlByID(ID_MAIN_Window25);
    mButtonSelect4Ptr = (ZKButton*)findControlByID(ID_MAIN_ButtonSelect4);
    mButtonSelect5Ptr = (ZKButton*)findControlByID(ID_MAIN_ButtonSelect5);
    mButtonSelect3Ptr = (ZKButton*)findControlByID(ID_MAIN_ButtonSelect3);
    mButtonSelect2Ptr = (ZKButton*)findControlByID(ID_MAIN_ButtonSelect2);
    mButtonSelect1Ptr = (ZKButton*)findControlByID(ID_MAIN_ButtonSelect1);
    mTextViewHumidityPtr = (ZKTextView*)findControlByID(ID_MAIN_TextViewHumidity);
    mTextView60Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView60);
    mWindow23Ptr = (ZKWindow*)findControlByID(ID_MAIN_Window23);
    mTextViewFreshairPtr = (ZKTextView*)findControlByID(ID_MAIN_TextViewFreshair);
    mTextView59Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView59);
    mWindowFreshAirPtr = (ZKWindow*)findControlByID(ID_MAIN_WindowFreshAir);
    mTextViewAirPtr = (ZKTextView*)findControlByID(ID_MAIN_TextViewAir);
    mTextView58Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView58);
    mWindowAirconditionPtr = (ZKWindow*)findControlByID(ID_MAIN_WindowAircondition);
    mTextViewmcuPtr = (ZKTextView*)findControlByID(ID_MAIN_TextViewmcu);
    mTextViewHistory2Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextViewHistory2);
    mButtonHistorty2Ptr = (ZKButton*)findControlByID(ID_MAIN_ButtonHistorty2);
    mWindow22Ptr = (ZKWindow*)findControlByID(ID_MAIN_Window22);
    mTextViewManual2Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextViewManual2);
    mButtonManual2Ptr = (ZKButton*)findControlByID(ID_MAIN_ButtonManual2);
    mWindow21Ptr = (ZKWindow*)findControlByID(ID_MAIN_Window21);
    mTextViewSmart2Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextViewSmart2);
    mButtonSmart2Ptr = (ZKButton*)findControlByID(ID_MAIN_ButtonSmart2);
    mWindow20Ptr = (ZKWindow*)findControlByID(ID_MAIN_Window20);
    mTextViewHomepage2Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextViewHomepage2);
    mButtonHomepage2Ptr = (ZKButton*)findControlByID(ID_MAIN_ButtonHomepage2);
    mWindow19Ptr = (ZKWindow*)findControlByID(ID_MAIN_Window19);
    mWindowNavibar2Ptr = (ZKWindow*)findControlByID(ID_MAIN_WindowNavibar2);
    mButtonDropDownPtr = (ZKButton*)findControlByID(ID_MAIN_ButtonDropDown);
    mButton8Ptr = (ZKButton*)findControlByID(ID_MAIN_Button8);
    mButton2Ptr = (ZKButton*)findControlByID(ID_MAIN_Button2);
    mWindowModeSelect2Ptr = (ZKWindow*)findControlByID(ID_MAIN_WindowModeSelect2);
    mWindowMainStatusPtr = (ZKWindow*)findControlByID(ID_MAIN_WindowMainStatus);
    mWindowModeSelect1Ptr = (ZKWindow*)findControlByID(ID_MAIN_WindowModeSelect1);
    mWindowBGPtr = (ZKWindow*)findControlByID(ID_MAIN_WindowBG);
    mTextView50Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView50);
    mTextView49Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView49);
    mTextView48Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView48);
    mTextView47Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView47);
    mTextView40Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView40);
    mTextViewWifiPtr = (ZKTextView*)findControlByID(ID_MAIN_TextViewWifi);
    mButton1Ptr = (ZKButton*)findControlByID(ID_MAIN_Button1);
    mButton7Ptr = (ZKButton*)findControlByID(ID_MAIN_Button7);
    mButton6Ptr = (ZKButton*)findControlByID(ID_MAIN_Button6);
    mTextView39Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView39);
    mWindow13Ptr = (ZKWindow*)findControlByID(ID_MAIN_Window13);
    mButton5Ptr = (ZKButton*)findControlByID(ID_MAIN_Button5);
    mTextView38Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView38);
    mWindow11Ptr = (ZKWindow*)findControlByID(ID_MAIN_Window11);
    mButton4Ptr = (ZKButton*)findControlByID(ID_MAIN_Button4);
    mTextView37Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView37);
    mWindow10Ptr = (ZKWindow*)findControlByID(ID_MAIN_Window10);
    mButton3Ptr = (ZKButton*)findControlByID(ID_MAIN_Button3);
    mButtonOFFPtr = (ZKButton*)findControlByID(ID_MAIN_ButtonOFF);
    mButtonONPtr = (ZKButton*)findControlByID(ID_MAIN_ButtonON);
    mTextView35Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView35);
    mTextView34Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView34);
    mTextView33Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView33);
    mTextView32Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView32);
    mWindowCO2Ptr = (ZKWindow*)findControlByID(ID_MAIN_WindowCO2);
    mTextView28Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView28);
    mTextView31Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView31);
    mTextView30Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView30);
    mTextView29Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView29);
    mWindowFormaldehydePtr = (ZKWindow*)findControlByID(ID_MAIN_WindowFormaldehyde);
    mTextView27Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView27);
    mTextView26Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView26);
    mTextView25Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView25);
    mTextView24Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView24);
    mWindowTempPtr = (ZKWindow*)findControlByID(ID_MAIN_WindowTemp);
    mTextView23Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView23);
    mTextView22Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView22);
    mTextView21Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView21);
    mTextView20Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView20);
    mWindowPM25Ptr = (ZKWindow*)findControlByID(ID_MAIN_WindowPM25);
    mTextView36Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView36);
    mTextView19Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView19);
    mTextView18Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView18);
    mTextView17Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView17);
    mWindowHumidityPtr = (ZKWindow*)findControlByID(ID_MAIN_WindowHumidity);
    mWindow9Ptr = (ZKWindow*)findControlByID(ID_MAIN_Window9);
    mTextView16Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView16);
    mTextView15Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView15);
    mTextView14Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView14);
    mWindow8Ptr = (ZKWindow*)findControlByID(ID_MAIN_Window8);
    mWindow7Ptr = (ZKWindow*)findControlByID(ID_MAIN_Window7);
    mTextView13Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView13);
    mTextView12Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView12);
    mTextView11Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView11);
    mTextView10Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView10);
    mTextView9Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView9);
    mTextView8Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView8);
    mTextView7Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView7);
    mWindow6Ptr = (ZKWindow*)findControlByID(ID_MAIN_Window6);
    mTextView6Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView6);
    mTextView5Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView5);
    mWindow5Ptr = (ZKWindow*)findControlByID(ID_MAIN_Window5);
    mTextView41Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView41);
    mButtonHistorty1Ptr = (ZKButton*)findControlByID(ID_MAIN_ButtonHistorty1);
    mTextView4Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView4);
    mButtonHistortyPtr = (ZKButton*)findControlByID(ID_MAIN_ButtonHistorty);
    mWindowHistortyPtr = (ZKWindow*)findControlByID(ID_MAIN_WindowHistorty);
    mButtonManual1Ptr = (ZKButton*)findControlByID(ID_MAIN_ButtonManual1);
    mTextView3Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView3);
    mButtonManualPtr = (ZKButton*)findControlByID(ID_MAIN_ButtonManual);
    mWindowManualPtr = (ZKWindow*)findControlByID(ID_MAIN_WindowManual);
    mButtonSmart1Ptr = (ZKButton*)findControlByID(ID_MAIN_ButtonSmart1);
    mTextView2Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView2);
    mButtonSmartPtr = (ZKButton*)findControlByID(ID_MAIN_ButtonSmart);
    mWindowSmartPtr = (ZKWindow*)findControlByID(ID_MAIN_WindowSmart);
    mButtonHomepage1Ptr = (ZKButton*)findControlByID(ID_MAIN_ButtonHomepage1);
    mTextView1Ptr = (ZKTextView*)findControlByID(ID_MAIN_TextView1);
    mButtonHomepagePtr = (ZKButton*)findControlByID(ID_MAIN_ButtonHomepage);
    mWindowHomepagePtr = (ZKWindow*)findControlByID(ID_MAIN_WindowHomepage);
    mWindow2Ptr = (ZKWindow*)findControlByID(ID_MAIN_Window2);

    mWindowSelectModePtr[0] = mWindowHumidityPtr;
    mWindowSelectModePtr[1] = mWindowPM25Ptr;
    mWindowSelectModePtr[2] = mWindowTempPtr;
    mWindowSelectModePtr[3] = mWindowCO2Ptr;
    mWindowSelectModePtr[4] = mWindowFormaldehydePtr;

    mButtonModeSelect[0] = mButtonSelect1Ptr;
    mButtonModeSelect[1] = mButtonSelect2Ptr;
    mButtonModeSelect[2] = mButtonSelect3Ptr;
    mButtonModeSelect[3] = mButtonSelect4Ptr;
    mButtonModeSelect[4] = mButtonSelect5Ptr;

    mTextModeSelectPic[0] = mTextView17Ptr;
    mTextModeSelectPic[1] = mTextView20Ptr;
    mTextModeSelectPic[2] = mTextView24Ptr;
    mTextModeSelectPic[3] = mTextView35Ptr;
    mTextModeSelectPic[4] = mTextView28Ptr;

    mTextModeSelectTitle[0] = mTextView18Ptr;
    mTextModeSelectTitle[1] = mTextView21Ptr;
    mTextModeSelectTitle[2] = mTextView25Ptr;
    mTextModeSelectTitle[3] = mTextView32Ptr;
    mTextModeSelectTitle[4] = mTextView29Ptr;

    mTextModeSelectRecvData[0] = mTextView19Ptr;
    mTextModeSelectRecvData[1] = mTextView22Ptr;
    mTextModeSelectRecvData[2] = mTextView26Ptr;
    mTextModeSelectRecvData[3] = mTextView33Ptr;
    mTextModeSelectRecvData[4] = mTextView30Ptr;

    mTextModeSelectString[0] = mTextView36Ptr;
    mTextModeSelectString[1] = mTextView23Ptr;
    mTextModeSelectString[2] = mTextView27Ptr;
    mTextModeSelectString[3] = mTextView34Ptr;
    mTextModeSelectString[4] = mTextView31Ptr;

    		//static ZKWindow* mWindowsSelectMode[5] = {mWindowHumidityPtr, mWindowPM25Ptr, mWindowTempPtr, mWindowCO2Ptr, mWindowFormaldehydePtr};
    //static ZKButton* mButtonModeSelect[5] = {mButtonSelect1Ptr, mButtonSelect2Ptr, mButtonSelect3Ptr, mButtonSelect4Ptr, mButtonSelect5Ptr};

	mActivityPtr = this;
	onUI_init();
    registerProtocolDataUpdateListener(onProtocolDataUpdate); 
    rigesterActivityTimer();
}

void mainActivity::onClick(ZKBase *pBase) {
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

void mainActivity::onResume() {
	Activity::onResume();
	EASYUICONTEXT->registerGlobalTouchListener(this);

	if(nwlistener->IsConnected())
	{
		mIconViewWifiPtr->setVisible(true);
	}
	else
	{
		mIconViewWifiPtr->setVisible(false);
	}

	startVideoLoopPlayback();
	onUI_show();
}

void mainActivity::onPause() {
	Activity::onPause();
	EASYUICONTEXT->unregisterGlobalTouchListener(this);
	stopVideoLoopPlayback();
	onUI_hide();
}

void mainActivity::onIntent(const Intent *intentPtr) {
	Activity::onIntent(intentPtr);
	onUI_intent(intentPtr);
	nwlistener->setNetWorkListener(this);
}

bool mainActivity::onTimer(int id) {
	return onUI_Timer(id);
}

void mainActivity::onProgressChanged(ZKSeekBar *pSeekBar, int progress){

    int seekBarTablen = sizeof(SZKSeekBarCallbackTab) / sizeof(S_ZKSeekBarCallback);
    for (int i = 0; i < seekBarTablen; ++i) {
        if (SZKSeekBarCallbackTab[i].id == pSeekBar->getID()) {
            SZKSeekBarCallbackTab[i].callback(pSeekBar, progress);
            break;
        }
    }
}

int mainActivity::getListItemCount(const ZKListView *pListView) const{
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            return SListViewFunctionsCallbackTab[i].getListItemCountCallback(pListView);
            break;
        }
    }
    return 0;
}

void mainActivity::obtainListItemData(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index){
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            SListViewFunctionsCallbackTab[i].obtainListItemDataCallback(pListView, pListItem, index);
            break;
        }
    }
}

void mainActivity::onItemClick(ZKListView *pListView, int index, int id){
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            SListViewFunctionsCallbackTab[i].onItemClickCallback(pListView, index, id);
            break;
        }
    }
}

void mainActivity::onSlideItemClick(ZKSlideWindow *pSlideWindow, int index) {
    int tablen = sizeof(SSlideWindowItemClickCallbackTab) / sizeof(S_SlideWindowItemClickCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SSlideWindowItemClickCallbackTab[i].id == pSlideWindow->getID()) {
            SSlideWindowItemClickCallbackTab[i].onSlideItemClickCallback(pSlideWindow, index);
            break;
        }
    }
}

bool mainActivity::onTouchEvent(const MotionEvent &ev) {
    return onmainActivityTouchEvent(ev);
}

void mainActivity::onTextChanged(ZKTextView *pTextView, const std::string &text) {
    int tablen = sizeof(SEditTextInputCallbackTab) / sizeof(S_EditTextInputCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SEditTextInputCallbackTab[i].id == pTextView->getID()) {
            SEditTextInputCallbackTab[i].onEditTextChangedCallback(text);
            break;
        }
    }
}

void mainActivity::rigesterActivityTimer() {
    int tablen = sizeof(REGISTER_ACTIVITY_TIMER_TAB) / sizeof(S_ACTIVITY_TIMEER);
    for (int i = 0; i < tablen; ++i) {
        S_ACTIVITY_TIMEER temp = REGISTER_ACTIVITY_TIMER_TAB[i];
        registerTimer(temp.id, temp.time);
    }
}


void mainActivity::onVideoPlayerMessage(ZKVideoView *pVideoView, int msg) {
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

void mainActivity::videoLoopPlayback(ZKVideoView *pVideoView, int msg, size_t callbackTabIndex) {

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

void mainActivity::startVideoLoopPlayback() {
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

void mainActivity::stopVideoLoopPlayback() {
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

bool mainActivity::parseVideoFileList(const char *pFileListPath, std::vector<string>& mediaFileList) {
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

int mainActivity::removeCharFromString(string& nString, char c) {
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

void mainActivity::registerUserTimer(int id, int time) {
	registerTimer(id, time);
}

void mainActivity::unregisterUserTimer(int id) {
	unregisterTimer(id);
}
void mainActivity::MyNetworkNotify(int type, void* data) {
	if(type == NW_NOTIFY_TYPE_CONNECT_STATUS) {				//连接状态变化
		LOGD("connected %d\n" , (int)data);
		if(1 == (int)data) {								//连接成功
			//ltz modify begin
			mIconViewWifiPtr->setVisible(true);
//			mTextView62Ptr->setText("已联网");
		}
		else {

			if(!nwlistener->getWifiStatus()) {
				mIconViewWifiPtr->setVisible(false);
//				mTextView62Ptr->setText("未连网");
			}

		}
	}

}

void mainActivity::resetUserTimer(int id, int time) {
	resetTimer(id, time);
}
