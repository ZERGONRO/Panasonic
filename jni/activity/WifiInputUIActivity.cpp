/***********************************************
/gen auto by zuitools
***********************************************/
#include "WifiInputUIActivity.h"
#include "util/MyNetWorkingListener.h"

/*TAG:GlobalVariable全局变量*/
static ZKButton* mButton36Ptr;
static ZKButton* mButton10Ptr;
static ZKButton* mButton35Ptr;
static ZKButton* mButton34Ptr;
static ZKButton* mButton33Ptr;
static ZKButton* mButton32Ptr;
static ZKButton* mButton31Ptr;
static ZKButton* mButton30Ptr;
static ZKButton* mButton29Ptr;
static ZKButton* mButton28Ptr;
static ZKButton* mButton27Ptr;
static ZKButton* mButton26Ptr;
static ZKButton* mButton25Ptr;
static ZKButton* mButton24Ptr;
static ZKButton* mButton23Ptr;
static ZKButton* mButton21Ptr;
static ZKButton* mButton20Ptr;
static ZKButton* mButton19Ptr;
static ZKButton* mButton18Ptr;
static ZKButton* mButton17Ptr;
static ZKButton* mButton16Ptr;
static ZKButton* mButton15Ptr;
static ZKButton* mButton14Ptr;
static ZKButton* mButton13Ptr;
static ZKButton* mButton12Ptr;
static ZKButton* mButton11Ptr;
static ZKButton* mButton0Ptr;
static ZKButton* mButton9Ptr;
static ZKButton* mButton8Ptr;
static ZKButton* mButton7Ptr;
static ZKButton* mButton6Ptr;
static ZKButton* mButton5Ptr;
static ZKButton* mButton4Ptr;
static ZKButton* mButton3Ptr;
static ZKButton* mButton2Ptr;
static ZKButton* mButton1Ptr;
static ZKWindow* mWindow14Ptr;
static ZKButton* mButtonDotPtr;
static ZKButton* mButtonNum2Ptr;
static ZKButton* mButtonDComPtr;
static ZKButton* mButtonSpacePtr;
static ZKButton* mButtonSlashPtr;
static ZKButton* mButtonNumPtr;
static ZKButton* mButtonUpper2Ptr;
static ZKButton* mButtonQMPtr;
static ZKButton* mButtonNPtr;
static ZKButton* mButtonVPtr;
static ZKButton* mButtonZPtr;
static ZKButton* mButtonBPtr;
static ZKButton* mButtonXPtr;
static ZKButton* mButtonCPtr;
static ZKButton* mButtonMPtr;
static ZKButton* mButtonUpperPtr;
static ZKButton* mButtonExclamationPtr;
static ZKButton* mButton22Ptr;
static ZKButton* mButtonLPtr;
static ZKButton* mButtonKPtr;
static ZKButton* mButtonJPtr;
static ZKButton* mButtonHPtr;
static ZKButton* mButtonGPtr;
static ZKButton* mButtonFPtr;
static ZKButton* mButtonDPtr;
static ZKButton* mButtonSPtr;
static ZKButton* mButtonAPtr;
static ZKButton* mButtonBackspacePtr;
static ZKWindow* mWindow13Ptr;
static ZKButton* mButtonPPtr;
static ZKTextView* mTextView11Ptr;
static ZKWindow* mWindow12Ptr;
static ZKButton* mButtonOPtr;
static ZKTextView* mTextView10Ptr;
static ZKWindow* mWindow11Ptr;
static ZKButton* mButtonIPtr;
static ZKTextView* mTextView9Ptr;
static ZKWindow* mWindow10Ptr;
static ZKButton* mButtonUPtr;
static ZKTextView* mTextView8Ptr;
static ZKWindow* mWindow9Ptr;
static ZKButton* mButtonYPtr;
static ZKTextView* mTextView7Ptr;
static ZKWindow* mWindow8Ptr;
static ZKButton* mButtonTPtr;
static ZKTextView* mTextView6Ptr;
static ZKWindow* mWindow7Ptr;
static ZKButton* mButtonRPtr;
static ZKTextView* mTextView5Ptr;
static ZKWindow* mWindow6Ptr;
static ZKButton* mButtonEPtr;
static ZKTextView* mTextView4Ptr;
static ZKWindow* mWindow5Ptr;
static ZKButton* mButtonWPtr;
static ZKTextView* mTextView3Ptr;
static ZKWindow* mWindow4Ptr;
static ZKButton* mButtonQPtr;
static ZKTextView* mTextView2Ptr;
static ZKWindow* mWindow3Ptr;
static ZKWindow* mWindow2Ptr;
static ZKButton* mButtonConfirmPtr;
static ZKTextView* mPassWordTextView2Ptr;
static ZKTextView* mPassWordTextViewPtr;
static ZKWindow* mWindow1Ptr;
static ZKTextView* mIconWifiPtr;
static ZKButton* mButtonBackPtr;
static ZKTextView* mTextViewSSIDPtr;
static WifiInputUIActivity* mActivityPtr;

static ZKButton* mButtonWords[26];
extern MyNetWorkingListener *nwlistener;

/*register activity*/
REGISTER_ACTIVITY(WifiInputUIActivity);

typedef struct {
	int id; // 定时器ID ， 不能重复
	int time; // 定时器  时间间隔  单位 毫秒
}S_ACTIVITY_TIMEER;

#include "logic/WifiInputUILogic.cc"

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
    ID_WIFIINPUTUI_Button36, onButtonClick_Button36,
    ID_WIFIINPUTUI_Button10, onButtonClick_Button10,
    ID_WIFIINPUTUI_Button35, onButtonClick_Button35,
    ID_WIFIINPUTUI_Button34, onButtonClick_Button34,
    ID_WIFIINPUTUI_Button33, onButtonClick_Button33,
    ID_WIFIINPUTUI_Button32, onButtonClick_Button32,
    ID_WIFIINPUTUI_Button31, onButtonClick_Button31,
    ID_WIFIINPUTUI_Button30, onButtonClick_Button30,
    ID_WIFIINPUTUI_Button29, onButtonClick_Button29,
    ID_WIFIINPUTUI_Button28, onButtonClick_Button28,
    ID_WIFIINPUTUI_Button27, onButtonClick_Button27,
    ID_WIFIINPUTUI_Button26, onButtonClick_Button26,
    ID_WIFIINPUTUI_Button25, onButtonClick_Button25,
    ID_WIFIINPUTUI_Button24, onButtonClick_Button24,
    ID_WIFIINPUTUI_Button23, onButtonClick_Button23,
    ID_WIFIINPUTUI_Button21, onButtonClick_Button21,
    ID_WIFIINPUTUI_Button20, onButtonClick_Button20,
    ID_WIFIINPUTUI_Button19, onButtonClick_Button19,
    ID_WIFIINPUTUI_Button18, onButtonClick_Button18,
    ID_WIFIINPUTUI_Button17, onButtonClick_Button17,
    ID_WIFIINPUTUI_Button16, onButtonClick_Button16,
    ID_WIFIINPUTUI_Button15, onButtonClick_Button15,
    ID_WIFIINPUTUI_Button14, onButtonClick_Button14,
    ID_WIFIINPUTUI_Button13, onButtonClick_Button13,
    ID_WIFIINPUTUI_Button12, onButtonClick_Button12,
    ID_WIFIINPUTUI_Button11, onButtonClick_Button11,
    ID_WIFIINPUTUI_Button0, onButtonClick_Button0,
    ID_WIFIINPUTUI_Button9, onButtonClick_Button9,
    ID_WIFIINPUTUI_Button8, onButtonClick_Button8,
    ID_WIFIINPUTUI_Button7, onButtonClick_Button7,
    ID_WIFIINPUTUI_Button6, onButtonClick_Button6,
    ID_WIFIINPUTUI_Button5, onButtonClick_Button5,
    ID_WIFIINPUTUI_Button4, onButtonClick_Button4,
    ID_WIFIINPUTUI_Button3, onButtonClick_Button3,
    ID_WIFIINPUTUI_Button2, onButtonClick_Button2,
    ID_WIFIINPUTUI_Button1, onButtonClick_Button1,
    ID_WIFIINPUTUI_ButtonDot, onButtonClick_ButtonDot,
    ID_WIFIINPUTUI_ButtonNum2, onButtonClick_ButtonNum2,
    ID_WIFIINPUTUI_ButtonDCom, onButtonClick_ButtonDCom,
    ID_WIFIINPUTUI_ButtonSpace, onButtonClick_ButtonSpace,
    ID_WIFIINPUTUI_ButtonSlash, onButtonClick_ButtonSlash,
    ID_WIFIINPUTUI_ButtonNum, onButtonClick_ButtonNum,
    ID_WIFIINPUTUI_ButtonUpper2, onButtonClick_ButtonUpper2,
    ID_WIFIINPUTUI_ButtonQM, onButtonClick_ButtonQM,
    ID_WIFIINPUTUI_ButtonN, onButtonClick_ButtonN,
    ID_WIFIINPUTUI_ButtonV, onButtonClick_ButtonV,
    ID_WIFIINPUTUI_ButtonZ, onButtonClick_ButtonZ,
    ID_WIFIINPUTUI_ButtonB, onButtonClick_ButtonB,
    ID_WIFIINPUTUI_ButtonX, onButtonClick_ButtonX,
    ID_WIFIINPUTUI_ButtonC, onButtonClick_ButtonC,
    ID_WIFIINPUTUI_ButtonM, onButtonClick_ButtonM,
    ID_WIFIINPUTUI_ButtonUpper, onButtonClick_ButtonUpper,
    ID_WIFIINPUTUI_ButtonExclamation, onButtonClick_ButtonExclamation,
    ID_WIFIINPUTUI_Button22, onButtonClick_Button22,
    ID_WIFIINPUTUI_ButtonL, onButtonClick_ButtonL,
    ID_WIFIINPUTUI_ButtonK, onButtonClick_ButtonK,
    ID_WIFIINPUTUI_ButtonJ, onButtonClick_ButtonJ,
    ID_WIFIINPUTUI_ButtonH, onButtonClick_ButtonH,
    ID_WIFIINPUTUI_ButtonG, onButtonClick_ButtonG,
    ID_WIFIINPUTUI_ButtonF, onButtonClick_ButtonF,
    ID_WIFIINPUTUI_ButtonD, onButtonClick_ButtonD,
    ID_WIFIINPUTUI_ButtonS, onButtonClick_ButtonS,
    ID_WIFIINPUTUI_ButtonA, onButtonClick_ButtonA,
    ID_WIFIINPUTUI_ButtonBackspace, onButtonClick_ButtonBackspace,
    ID_WIFIINPUTUI_ButtonP, onButtonClick_ButtonP,
    ID_WIFIINPUTUI_ButtonO, onButtonClick_ButtonO,
    ID_WIFIINPUTUI_ButtonI, onButtonClick_ButtonI,
    ID_WIFIINPUTUI_ButtonU, onButtonClick_ButtonU,
    ID_WIFIINPUTUI_ButtonY, onButtonClick_ButtonY,
    ID_WIFIINPUTUI_ButtonT, onButtonClick_ButtonT,
    ID_WIFIINPUTUI_ButtonR, onButtonClick_ButtonR,
    ID_WIFIINPUTUI_ButtonE, onButtonClick_ButtonE,
    ID_WIFIINPUTUI_ButtonW, onButtonClick_ButtonW,
    ID_WIFIINPUTUI_ButtonQ, onButtonClick_ButtonQ,
    ID_WIFIINPUTUI_ButtonConfirm, onButtonClick_ButtonConfirm,
    ID_WIFIINPUTUI_ButtonBack, onButtonClick_ButtonBack,
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
		{ID_WIFIINPUTUI_PassWordTextView, onEditTextChanged_PassWordTextView}
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


WifiInputUIActivity::WifiInputUIActivity() {
	//todo add init code here
	mVideoLoopIndex = -1;
	mVideoLoopErrorCount = 0;
}

WifiInputUIActivity::~WifiInputUIActivity() {
  //todo add init file here
  // 退出应用时需要反注册
    EASYUICONTEXT->unregisterGlobalTouchListener(this);
    onUI_quit();
    unregisterProtocolDataUpdateListener(onProtocolDataUpdate);
    nwlistener->removeNetWorkListener(this);
}

const char* WifiInputUIActivity::getAppName() const{
	return "WifiInputUI.ftu";
}

//TAG:onCreate
void WifiInputUIActivity::onCreate() {
	Activity::onCreate();
    mButton36Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button36);
    mButton10Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button10);
    mButton35Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button35);
    mButton34Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button34);
    mButton33Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button33);
    mButton32Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button32);
    mButton31Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button31);
    mButton30Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button30);
    mButton29Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button29);
    mButton28Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button28);
    mButton27Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button27);
    mButton26Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button26);
    mButton25Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button25);
    mButton24Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button24);
    mButton23Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button23);
    mButton21Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button21);
    mButton20Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button20);
    mButton19Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button19);
    mButton18Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button18);
    mButton17Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button17);
    mButton16Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button16);
    mButton15Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button15);
    mButton14Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button14);
    mButton13Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button13);
    mButton12Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button12);
    mButton11Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button11);
    mButton0Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button0);
    mButton9Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button9);
    mButton8Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button8);
    mButton7Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button7);
    mButton6Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button6);
    mButton5Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button5);
    mButton4Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button4);
    mButton3Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button3);
    mButton2Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button2);
    mButton1Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button1);
    mWindow14Ptr = (ZKWindow*)findControlByID(ID_WIFIINPUTUI_Window14);
    mButtonDotPtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonDot);
    mButtonNum2Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonNum2);
    mButtonDComPtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonDCom);
    mButtonSpacePtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonSpace);
    mButtonSlashPtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonSlash);
    mButtonNumPtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonNum);
    mButtonUpper2Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonUpper2);
    mButtonQMPtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonQM);
    mButtonNPtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonN);
    mButtonVPtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonV);
    mButtonZPtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonZ);
    mButtonBPtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonB);
    mButtonXPtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonX);
    mButtonCPtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonC);
    mButtonMPtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonM);
    mButtonUpperPtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonUpper);
    mButtonExclamationPtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonExclamation);
    mButton22Ptr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_Button22);
    mButtonLPtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonL);
    mButtonKPtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonK);
    mButtonJPtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonJ);
    mButtonHPtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonH);
    mButtonGPtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonG);
    mButtonFPtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonF);
    mButtonDPtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonD);
    mButtonSPtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonS);
    mButtonAPtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonA);
    mButtonBackspacePtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonBackspace);
    mWindow13Ptr = (ZKWindow*)findControlByID(ID_WIFIINPUTUI_Window13);
    mButtonPPtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonP);
    mTextView11Ptr = (ZKTextView*)findControlByID(ID_WIFIINPUTUI_TextView11);
    mWindow12Ptr = (ZKWindow*)findControlByID(ID_WIFIINPUTUI_Window12);
    mButtonOPtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonO);
    mTextView10Ptr = (ZKTextView*)findControlByID(ID_WIFIINPUTUI_TextView10);
    mWindow11Ptr = (ZKWindow*)findControlByID(ID_WIFIINPUTUI_Window11);
    mButtonIPtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonI);
    mTextView9Ptr = (ZKTextView*)findControlByID(ID_WIFIINPUTUI_TextView9);
    mWindow10Ptr = (ZKWindow*)findControlByID(ID_WIFIINPUTUI_Window10);
    mButtonUPtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonU);
    mTextView8Ptr = (ZKTextView*)findControlByID(ID_WIFIINPUTUI_TextView8);
    mWindow9Ptr = (ZKWindow*)findControlByID(ID_WIFIINPUTUI_Window9);
    mButtonYPtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonY);
    mTextView7Ptr = (ZKTextView*)findControlByID(ID_WIFIINPUTUI_TextView7);
    mWindow8Ptr = (ZKWindow*)findControlByID(ID_WIFIINPUTUI_Window8);
    mButtonTPtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonT);
    mTextView6Ptr = (ZKTextView*)findControlByID(ID_WIFIINPUTUI_TextView6);
    mWindow7Ptr = (ZKWindow*)findControlByID(ID_WIFIINPUTUI_Window7);
    mButtonRPtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonR);
    mTextView5Ptr = (ZKTextView*)findControlByID(ID_WIFIINPUTUI_TextView5);
    mWindow6Ptr = (ZKWindow*)findControlByID(ID_WIFIINPUTUI_Window6);
    mButtonEPtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonE);
    mTextView4Ptr = (ZKTextView*)findControlByID(ID_WIFIINPUTUI_TextView4);
    mWindow5Ptr = (ZKWindow*)findControlByID(ID_WIFIINPUTUI_Window5);
    mButtonWPtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonW);
    mTextView3Ptr = (ZKTextView*)findControlByID(ID_WIFIINPUTUI_TextView3);
    mWindow4Ptr = (ZKWindow*)findControlByID(ID_WIFIINPUTUI_Window4);
    mButtonQPtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonQ);
    mTextView2Ptr = (ZKTextView*)findControlByID(ID_WIFIINPUTUI_TextView2);
    mWindow3Ptr = (ZKWindow*)findControlByID(ID_WIFIINPUTUI_Window3);
    mWindow2Ptr = (ZKWindow*)findControlByID(ID_WIFIINPUTUI_Window2);
    mButtonConfirmPtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonConfirm);
    mPassWordTextView2Ptr = (ZKTextView*)findControlByID(ID_WIFIINPUTUI_PassWordTextView2);
    mPassWordTextViewPtr = (ZKTextView*)findControlByID(ID_WIFIINPUTUI_PassWordTextView);
    mWindow1Ptr = (ZKWindow*)findControlByID(ID_WIFIINPUTUI_Window1);
    mIconWifiPtr = (ZKTextView*)findControlByID(ID_WIFIINPUTUI_IconWifi);
    mButtonBackPtr = (ZKButton*)findControlByID(ID_WIFIINPUTUI_ButtonBack);
    mTextViewSSIDPtr = (ZKTextView*)findControlByID(ID_WIFIINPUTUI_TextViewSSID);

    mButtonWords[0] = mButtonAPtr;
	mButtonWords[1] = mButtonBPtr;
	mButtonWords[2] = mButtonCPtr;
	mButtonWords[3] = mButtonDPtr;
	mButtonWords[4] = mButtonEPtr;
	mButtonWords[5] = mButtonFPtr;
	mButtonWords[6] = mButtonGPtr;
	mButtonWords[7] = mButtonHPtr;
	mButtonWords[8] = mButtonIPtr;
	mButtonWords[9] = mButtonJPtr;
	mButtonWords[10] = mButtonKPtr;
	mButtonWords[11] = mButtonLPtr;
	mButtonWords[12] = mButtonMPtr;
	mButtonWords[13] = mButtonNPtr;
	mButtonWords[14] = mButtonOPtr;
	mButtonWords[15] = mButtonPPtr;
	mButtonWords[16] = mButtonQPtr;
	mButtonWords[17] = mButtonRPtr;
	mButtonWords[18] = mButtonSPtr;
	mButtonWords[19] = mButtonTPtr;
	mButtonWords[20] = mButtonUPtr;
	mButtonWords[21] = mButtonVPtr;
	mButtonWords[22] = mButtonWPtr;
	mButtonWords[23] = mButtonXPtr;
	mButtonWords[24] = mButtonYPtr;
	mButtonWords[25] = mButtonZPtr;
	mButtonQPtr->setLongClickListener(this);
	mButtonWPtr->setLongClickListener(this);
	mButtonEPtr->setLongClickListener(this);
	mButtonRPtr->setLongClickListener(this);
	mButtonTPtr->setLongClickListener(this);
	mButtonYPtr->setLongClickListener(this);
	mButtonUPtr->setLongClickListener(this);
	mButtonIPtr->setLongClickListener(this);
	mButtonOPtr->setLongClickListener(this);
	mButtonPPtr->setLongClickListener(this);

	mActivityPtr = this;
	onUI_init();
	nwlistener->setNetWorkListener(this);
    registerProtocolDataUpdateListener(onProtocolDataUpdate); 
    rigesterActivityTimer();

}

void WifiInputUIActivity::onClick(ZKBase *pBase) {
	//TODO: add widget onClik code 
    int buttonTablen = sizeof(sButtonCallbackTab) / sizeof(S_ButtonCallback);
    for (int i = 0; i < buttonTablen; ++i) {
    	if(strcmp(EASYUICONTEXT->currentAppName() , "WifiInputUIActivity")) {
			return ;
		}
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

void WifiInputUIActivity::onResume() {
	Activity::onResume();
	EASYUICONTEXT->registerGlobalTouchListener(this);
	startVideoLoopPlayback();
	onUI_show();
}

void WifiInputUIActivity::onPause() {
	Activity::onPause();
	EASYUICONTEXT->unregisterGlobalTouchListener(this);
	stopVideoLoopPlayback();
	onUI_hide();
}

void WifiInputUIActivity::onIntent(const Intent *intentPtr) {
	Activity::onIntent(intentPtr);
	onUI_intent(intentPtr);
}

bool WifiInputUIActivity::onTimer(int id) {
	return onUI_Timer(id);
}

void WifiInputUIActivity::onProgressChanged(ZKSeekBar *pSeekBar, int progress){

    int seekBarTablen = sizeof(SZKSeekBarCallbackTab) / sizeof(S_ZKSeekBarCallback);
    for (int i = 0; i < seekBarTablen; ++i) {
        if (SZKSeekBarCallbackTab[i].id == pSeekBar->getID()) {
            SZKSeekBarCallbackTab[i].callback(pSeekBar, progress);
            break;
        }
    }
}

int WifiInputUIActivity::getListItemCount(const ZKListView *pListView) const{
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            return SListViewFunctionsCallbackTab[i].getListItemCountCallback(pListView);
            break;
        }
    }
    return 0;
}
void WifiInputUIActivity::MyNetworkNotify(int type , void *data){
	if(type == NW_NOTIFY_TYPE_CONNECT_STATUS) {				//连接状态变化
	LOGD("connected %d\n" , (int)data);
	if(1 == (int)data) {								//连接成功
		mIconWifiPtr->setVisible(true);
//			resetStatusIconim();
	}
	else {
		mIconWifiPtr->setVisible(false);
//			resetStatusIconim();
	}
}
}

void WifiInputUIActivity::obtainListItemData(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index){
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            SListViewFunctionsCallbackTab[i].obtainListItemDataCallback(pListView, pListItem, index);
            break;
        }
    }
}

void WifiInputUIActivity::onItemClick(ZKListView *pListView, int index, int id){
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            SListViewFunctionsCallbackTab[i].onItemClickCallback(pListView, index, id);
            break;
        }
    }
}

void WifiInputUIActivity::onSlideItemClick(ZKSlideWindow *pSlideWindow, int index) {
    int tablen = sizeof(SSlideWindowItemClickCallbackTab) / sizeof(S_SlideWindowItemClickCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SSlideWindowItemClickCallbackTab[i].id == pSlideWindow->getID()) {
            SSlideWindowItemClickCallbackTab[i].onSlideItemClickCallback(pSlideWindow, index);
            break;
        }
    }
}

bool WifiInputUIActivity::onTouchEvent(const MotionEvent &ev) {
    return onWifiInputUIActivityTouchEvent(ev);
}

void WifiInputUIActivity::onTextChanged(ZKTextView *pTextView, const std::string &text) {
    int tablen = sizeof(SEditTextInputCallbackTab) / sizeof(S_EditTextInputCallback);
    LOGD("WifiInputUIActivity::onTextChanged  \n");
    for (int i = 0; i < tablen; ++i) {
        if (SEditTextInputCallbackTab[i].id == pTextView->getID()) {
            SEditTextInputCallbackTab[i].onEditTextChangedCallback(text);
            break;
        }
    }
}

void WifiInputUIActivity::rigesterActivityTimer() {
    int tablen = sizeof(REGISTER_ACTIVITY_TIMER_TAB) / sizeof(S_ACTIVITY_TIMEER);
    for (int i = 0; i < tablen; ++i) {
        S_ACTIVITY_TIMEER temp = REGISTER_ACTIVITY_TIMER_TAB[i];
        registerTimer(temp.id, temp.time);
    }
}


void WifiInputUIActivity::onVideoPlayerMessage(ZKVideoView *pVideoView, int msg) {
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

void WifiInputUIActivity::videoLoopPlayback(ZKVideoView *pVideoView, int msg, size_t callbackTabIndex) {

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

void WifiInputUIActivity::startVideoLoopPlayback() {
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

void WifiInputUIActivity::stopVideoLoopPlayback() {
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

bool WifiInputUIActivity::parseVideoFileList(const char *pFileListPath, std::vector<string>& mediaFileList) {
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

int WifiInputUIActivity::removeCharFromString(string& nString, char c) {
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

void WifiInputUIActivity::registerUserTimer(int id, int time) {
	registerTimer(id, time);
}

void WifiInputUIActivity::unregisterUserTimer(int id) {
	unregisterTimer(id);
}

void WifiInputUIActivity::resetUserTimer(int id, int time) {
	resetTimer(id, time);
}

void WifiInputUIActivity::onLongClick(ZKBase *pBase) {
	//TODO: add widget onClik code
	ZKButton *btn = (ZKButton*)pBase;
	LOGD("long click\n");
	if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING) {
		mPassWordTextViewPtr->setText("");
		mWindow1Ptr->setBackgroundPic("./ui/输入框-确认dn.png");
	}
	if(btn == mButtonQPtr) {
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + "1");
		mWindow1Ptr->setBackgroundPic("./ui/输入框-确认dn.png");
	}
	else if(btn == mButtonWPtr) {
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + "2");
		mWindow1Ptr->setBackgroundPic("./ui/输入框-确认dn.png");
	}
	else if(btn == mButtonEPtr) {
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + "3");
		mWindow1Ptr->setBackgroundPic("./ui/输入框-确认dn.png");
	}
	else if(btn == mButtonRPtr) {
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + "4");
		mWindow1Ptr->setBackgroundPic("./ui/输入框-确认dn.png");
	}
	else if(btn == mButtonTPtr) {
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + "5");
		mWindow1Ptr->setBackgroundPic("./ui/输入框-确认dn.png");
	}
	else if(btn == mButtonYPtr) {
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + "6");
		mWindow1Ptr->setBackgroundPic("./ui/输入框-确认dn.png");
	}
	else if(btn == mButtonUPtr) {
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + "7");
		mWindow1Ptr->setBackgroundPic("./ui/输入框-确认dn.png");
	}
	else if(btn == mButtonIPtr) {
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + "8");
		mWindow1Ptr->setBackgroundPic("./ui/输入框-确认dn.png");
	}
	else if(btn == mButtonOPtr) {
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + "9");
		mWindow1Ptr->setBackgroundPic("./ui/输入框-确认dn.png");
	}
	else if(btn == mButtonPPtr) {
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + "0");
		mWindow1Ptr->setBackgroundPic("./ui/输入框-确认dn.png");
	}
}

