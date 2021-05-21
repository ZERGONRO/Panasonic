/***********************************************
/gen auto by zuitools
***********************************************/
#include "SmartModeActivity.h"

/*TAG:GlobalVariable全局变量*/
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
static ZKWindow* mWindowNavibar3Ptr;
static ZKButton* mButtonVacModePtr;
static ZKButton* mButtonHawaiModePtr;
static ZKButton* mButtonHokiModePtr;
static ZKButton* mButtonStdModePtr;
static ZKWindow* mWindowSelectModePtr;
static ZKWindow* mWindowVacationModePtr;
static ZKWindow* mWindowHawaiiModePtr;
static ZKWindow* mWindowHokkaidoModePtr;
static ZKWindow* mWindowStandardModePtr;
static ZKTextView* mTextView45Ptr;
static ZKTextView* mTextView44Ptr;
static ZKTextView* mTextView43Ptr;
static ZKTextView* mTextView40Ptr;
static ZKTextView* mTextView8Ptr;
static ZKWindow* mWindowStatusPtr;
static ZKTextView* mTextViewWifiPtr;
static ZKButton* mButtonDropDownPtr;
static ZKTextView* mTextView42Ptr;
static ZKTextView* mTextView41Ptr;
static ZKTextView* mTextView39Ptr;
static ZKTextView* mTextView38Ptr;
static ZKButton* mButton13Ptr;
static ZKTextView* mTextView37Ptr;
static ZKTextView* mTextView36Ptr;
static ZKTextView* mTextView35Ptr;
static ZKTextView* mTextView34Ptr;
static ZKTextView* mTextView33Ptr;
static ZKTextView* mTextView32Ptr;
static ZKTextView* mTextView31Ptr;
static ZKTextView* mTextView30Ptr;
static ZKButton* mButton12Ptr;
static ZKTextView* mTextView29Ptr;
static ZKTextView* mTextView28Ptr;
static ZKTextView* mTextView27Ptr;
static ZKTextView* mTextView26Ptr;
static ZKTextView* mTextView25Ptr;
static ZKTextView* mTextView24Ptr;
static ZKTextView* mTextView16Ptr;
static ZKTextView* mTextView15Ptr;
static ZKButton* mButton11Ptr;
static ZKTextView* mTextView14Ptr;
static ZKTextView* mTextView13Ptr;
static ZKTextView* mTextView12Ptr;
static ZKTextView* mTextView11Ptr;
static ZKTextView* mTextView10Ptr;
static ZKButton* mButton10Ptr;
static ZKButton* mButton8Ptr;
static ZKButton* mButton9Ptr;
static ZKButton* mButton7Ptr;
static ZKTextView* mTextView9Ptr;
static ZKTextView* mTextView7Ptr;
static ZKTextView* mTextView6Ptr;
static ZKButton* mButton6Ptr;
static ZKTextView* mTextView5Ptr;
static ZKTextView* mTextView23Ptr;
static ZKTextView* mTextView22Ptr;
static ZKTextView* mTextView21Ptr;
static ZKTextView* mTextView20Ptr;
static ZKTextView* mTextView19Ptr;
static ZKTextView* mTextView18Ptr;
static ZKTextView* mTextView17Ptr;
static ZKTextView* mTextView4Ptr;
static ZKTextView* mTextView3Ptr;
static ZKTextView* mTextView2Ptr;
static ZKTextView* mTextView1Ptr;
static ZKWindow* mWindow2Ptr;
static SmartModeActivity* mActivityPtr;

/*register activity*/
REGISTER_ACTIVITY(SmartModeActivity);

enum SmartMode_t{
	StandardMode,
	HokiMode,
	HawaiMode,
	VacMode,
};


typedef struct {
	int id; // 定时器ID ， 不能重复
	int time; // 定时器  时间间隔  单位 毫秒
}S_ACTIVITY_TIMEER;

#include "logic/SmartModeLogic.cc"

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
    ID_SMARTMODE_ButtonHistorty2, onButtonClick_ButtonHistorty2,
    ID_SMARTMODE_ButtonManual2, onButtonClick_ButtonManual2,
    ID_SMARTMODE_ButtonSmart2, onButtonClick_ButtonSmart2,
    ID_SMARTMODE_ButtonHomepage2, onButtonClick_ButtonHomepage2,
    ID_SMARTMODE_ButtonVacMode, onButtonClick_ButtonVacMode,
    ID_SMARTMODE_ButtonHawaiMode, onButtonClick_ButtonHawaiMode,
    ID_SMARTMODE_ButtonHokiMode, onButtonClick_ButtonHokiMode,
    ID_SMARTMODE_ButtonStdMode, onButtonClick_ButtonStdMode,
    ID_SMARTMODE_ButtonDropDown, onButtonClick_ButtonDropDown,
    ID_SMARTMODE_Button13, onButtonClick_Button13,
    ID_SMARTMODE_Button12, onButtonClick_Button12,
    ID_SMARTMODE_Button11, onButtonClick_Button11,
    ID_SMARTMODE_Button10, onButtonClick_Button10,
    ID_SMARTMODE_Button8, onButtonClick_Button8,
    ID_SMARTMODE_Button9, onButtonClick_Button9,
    ID_SMARTMODE_Button7, onButtonClick_Button7,
    ID_SMARTMODE_Button6, onButtonClick_Button6,
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


SmartModeActivity::SmartModeActivity() {
	//todo add init code here
	mVideoLoopIndex = -1;
	mVideoLoopErrorCount = 0;
}

SmartModeActivity::~SmartModeActivity() {
  //todo add init file here
  // 退出应用时需要反注册
    EASYUICONTEXT->unregisterGlobalTouchListener(this);
    onUI_quit();
    unregisterProtocolDataUpdateListener(onProtocolDataUpdate);
}

const char* SmartModeActivity::getAppName() const{
	return "SmartMode.ftu";
}

//TAG:onCreate
void SmartModeActivity::onCreate() {
	Activity::onCreate();
    mTextViewHumidityPtr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextViewHumidity);
    mTextView60Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView60);
    mWindow23Ptr = (ZKWindow*)findControlByID(ID_SMARTMODE_Window23);
    mTextViewFreshairPtr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextViewFreshair);
    mTextView59Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView59);
    mWindowFreshAirPtr = (ZKWindow*)findControlByID(ID_SMARTMODE_WindowFreshAir);
    mTextViewAirPtr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextViewAir);
    mTextView58Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView58);
    mWindowAirconditionPtr = (ZKWindow*)findControlByID(ID_SMARTMODE_WindowAircondition);
    mTextViewmcuPtr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextViewmcu);
    mTextViewHistory2Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextViewHistory2);
    mButtonHistorty2Ptr = (ZKButton*)findControlByID(ID_SMARTMODE_ButtonHistorty2);
    mWindow22Ptr = (ZKWindow*)findControlByID(ID_SMARTMODE_Window22);
    mTextViewManual2Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextViewManual2);
    mButtonManual2Ptr = (ZKButton*)findControlByID(ID_SMARTMODE_ButtonManual2);
    mWindow21Ptr = (ZKWindow*)findControlByID(ID_SMARTMODE_Window21);
    mTextViewSmart2Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextViewSmart2);
    mButtonSmart2Ptr = (ZKButton*)findControlByID(ID_SMARTMODE_ButtonSmart2);
    mWindow20Ptr = (ZKWindow*)findControlByID(ID_SMARTMODE_Window20);
    mTextViewHomepage2Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextViewHomepage2);
    mButtonHomepage2Ptr = (ZKButton*)findControlByID(ID_SMARTMODE_ButtonHomepage2);
    mWindow19Ptr = (ZKWindow*)findControlByID(ID_SMARTMODE_Window19);
    mWindowNavibar3Ptr = (ZKWindow*)findControlByID(ID_SMARTMODE_WindowNavibar3);
    mButtonVacModePtr = (ZKButton*)findControlByID(ID_SMARTMODE_ButtonVacMode);
    mButtonHawaiModePtr = (ZKButton*)findControlByID(ID_SMARTMODE_ButtonHawaiMode);
    mButtonHokiModePtr = (ZKButton*)findControlByID(ID_SMARTMODE_ButtonHokiMode);
    mButtonStdModePtr = (ZKButton*)findControlByID(ID_SMARTMODE_ButtonStdMode);
    mWindowSelectModePtr = (ZKWindow*)findControlByID(ID_SMARTMODE_WindowSelectMode);
    mWindowVacationModePtr = (ZKWindow*)findControlByID(ID_SMARTMODE_WindowVacationMode);
    mWindowHawaiiModePtr = (ZKWindow*)findControlByID(ID_SMARTMODE_WindowHawaiiMode);
    mWindowHokkaidoModePtr = (ZKWindow*)findControlByID(ID_SMARTMODE_WindowHokkaidoMode);
    mWindowStandardModePtr = (ZKWindow*)findControlByID(ID_SMARTMODE_WindowStandardMode);
    mTextView45Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView45);
    mTextView44Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView44);
    mTextView43Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView43);
    mTextView40Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView40);
    mTextView8Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView8);
    mWindowStatusPtr = (ZKWindow*)findControlByID(ID_SMARTMODE_WindowStatus);
    mTextViewWifiPtr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextViewWifi);
    mButtonDropDownPtr = (ZKButton*)findControlByID(ID_SMARTMODE_ButtonDropDown);
    mTextView42Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView42);
    mTextView41Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView41);
    mTextView39Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView39);
    mTextView38Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView38);
    mButton13Ptr = (ZKButton*)findControlByID(ID_SMARTMODE_Button13);
    mTextView37Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView37);
    mTextView36Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView36);
    mTextView35Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView35);
    mTextView34Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView34);
    mTextView33Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView33);
    mTextView32Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView32);
    mTextView31Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView31);
    mTextView30Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView30);
    mButton12Ptr = (ZKButton*)findControlByID(ID_SMARTMODE_Button12);
    mTextView29Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView29);
    mTextView28Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView28);
    mTextView27Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView27);
    mTextView26Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView26);
    mTextView25Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView25);
    mTextView24Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView24);
    mTextView16Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView16);
    mTextView15Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView15);
    mButton11Ptr = (ZKButton*)findControlByID(ID_SMARTMODE_Button11);
    mTextView14Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView14);
    mTextView13Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView13);
    mTextView12Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView12);
    mTextView11Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView11);
    mTextView10Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView10);
    mButton10Ptr = (ZKButton*)findControlByID(ID_SMARTMODE_Button10);
    mButton8Ptr = (ZKButton*)findControlByID(ID_SMARTMODE_Button8);
    mButton9Ptr = (ZKButton*)findControlByID(ID_SMARTMODE_Button9);
    mButton7Ptr = (ZKButton*)findControlByID(ID_SMARTMODE_Button7);
    mTextView9Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView9);
    mTextView7Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView7);
    mTextView6Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView6);
    mButton6Ptr = (ZKButton*)findControlByID(ID_SMARTMODE_Button6);
    mTextView5Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView5);
    mTextView23Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView23);
    mTextView22Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView22);
    mTextView21Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView21);
    mTextView20Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView20);
    mTextView19Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView19);
    mTextView18Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView18);
    mTextView17Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView17);
    mTextView4Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView4);
    mTextView3Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView3);
    mTextView2Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView2);
    mTextView1Ptr = (ZKTextView*)findControlByID(ID_SMARTMODE_TextView1);
    mWindow2Ptr = (ZKWindow*)findControlByID(ID_SMARTMODE_Window2);
	mActivityPtr = this;
	onUI_init();
    registerProtocolDataUpdateListener(onProtocolDataUpdate); 
    rigesterActivityTimer();
}

void SmartModeActivity::onClick(ZKBase *pBase) {
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

void SmartModeActivity::onResume() {
	Activity::onResume();
	EASYUICONTEXT->registerGlobalTouchListener(this);
	startVideoLoopPlayback();
	onUI_show();
}

void SmartModeActivity::onPause() {
	Activity::onPause();
	EASYUICONTEXT->unregisterGlobalTouchListener(this);
	stopVideoLoopPlayback();
	onUI_hide();
}

void SmartModeActivity::onIntent(const Intent *intentPtr) {
	Activity::onIntent(intentPtr);
	onUI_intent(intentPtr);
}

bool SmartModeActivity::onTimer(int id) {
	return onUI_Timer(id);
}

void SmartModeActivity::onProgressChanged(ZKSeekBar *pSeekBar, int progress){

    int seekBarTablen = sizeof(SZKSeekBarCallbackTab) / sizeof(S_ZKSeekBarCallback);
    for (int i = 0; i < seekBarTablen; ++i) {
        if (SZKSeekBarCallbackTab[i].id == pSeekBar->getID()) {
            SZKSeekBarCallbackTab[i].callback(pSeekBar, progress);
            break;
        }
    }
}

int SmartModeActivity::getListItemCount(const ZKListView *pListView) const{
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            return SListViewFunctionsCallbackTab[i].getListItemCountCallback(pListView);
            break;
        }
    }
    return 0;
}

void SmartModeActivity::obtainListItemData(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index){
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            SListViewFunctionsCallbackTab[i].obtainListItemDataCallback(pListView, pListItem, index);
            break;
        }
    }
}

void SmartModeActivity::onItemClick(ZKListView *pListView, int index, int id){
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            SListViewFunctionsCallbackTab[i].onItemClickCallback(pListView, index, id);
            break;
        }
    }
}

void SmartModeActivity::onSlideItemClick(ZKSlideWindow *pSlideWindow, int index) {
    int tablen = sizeof(SSlideWindowItemClickCallbackTab) / sizeof(S_SlideWindowItemClickCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SSlideWindowItemClickCallbackTab[i].id == pSlideWindow->getID()) {
            SSlideWindowItemClickCallbackTab[i].onSlideItemClickCallback(pSlideWindow, index);
            break;
        }
    }
}

bool SmartModeActivity::onTouchEvent(const MotionEvent &ev) {
    return onSmartModeActivityTouchEvent(ev);
}

void SmartModeActivity::onTextChanged(ZKTextView *pTextView, const std::string &text) {
    int tablen = sizeof(SEditTextInputCallbackTab) / sizeof(S_EditTextInputCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SEditTextInputCallbackTab[i].id == pTextView->getID()) {
            SEditTextInputCallbackTab[i].onEditTextChangedCallback(text);
            break;
        }
    }
}

void SmartModeActivity::rigesterActivityTimer() {
    int tablen = sizeof(REGISTER_ACTIVITY_TIMER_TAB) / sizeof(S_ACTIVITY_TIMEER);
    for (int i = 0; i < tablen; ++i) {
        S_ACTIVITY_TIMEER temp = REGISTER_ACTIVITY_TIMER_TAB[i];
        registerTimer(temp.id, temp.time);
    }
}


void SmartModeActivity::onVideoPlayerMessage(ZKVideoView *pVideoView, int msg) {
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

void SmartModeActivity::videoLoopPlayback(ZKVideoView *pVideoView, int msg, size_t callbackTabIndex) {

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

void SmartModeActivity::startVideoLoopPlayback() {
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

void SmartModeActivity::stopVideoLoopPlayback() {
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

bool SmartModeActivity::parseVideoFileList(const char *pFileListPath, std::vector<string>& mediaFileList) {
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

int SmartModeActivity::removeCharFromString(string& nString, char c) {
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

void SmartModeActivity::registerUserTimer(int id, int time) {
	registerTimer(id, time);
}

void SmartModeActivity::unregisterUserTimer(int id) {
	unregisterTimer(id);
}

void SmartModeActivity::resetUserTimer(int id, int time) {
	resetTimer(id, time);
}