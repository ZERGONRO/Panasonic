/***********************************************
/gen auto by zuitools
***********************************************/
#include "ManualModeActivity.h"

/*TAG:GlobalVariable全局变量*/
static ZKButton* mButtonHumdAddPtr;
static ZKButton* mButtonHumdLessPtr;
static ZKButton* mButtonHumdTimeOpenPtr;
static ZKButton* mButtonHumdTimePicPtr;
static ZKButton* mButtonHumdOpenPtr;
static ZKButton* mButtonAirAddPtr;
static ZKButton* mButtonAirLessPtr;
static ZKButton* mButtonAirTimeOpenPtr;
static ZKButton* mButtonAirTimePicPtr;
static ZKButton* mButtonAirOpenPtr;
static ZKWindow* mWindowAirPtr;
static ZKButton* mButtonWindTimeOpenPtr;
static ZKButton* mButtonWindTimePicPtr;
static ZKButton* mButtonWindOpenPtr;
static ZKWindow* mWindowHumdSwitchPtr;
static ZKButton* mButtonWindStrongPtr;
static ZKButton* mButtonWindWeakPtr;
static ZKButton* mButtonWindOrdChangeAirPtr;
static ZKButton* mButtonWindHotReplacePtr;
static ZKButton* mButtonWindAutoPtr;
static ZKWindow* mWindowWindSwitchPtr;
static ZKButton* mButtonHumdPtr;
static ZKButton* mButtonWindPtr;
static ZKButton* mButtonAirPtr;
static ZKWindow* mWindowModeSelectPtr;
static ZKTextView* mTextView45Ptr;
static ZKTextView* mTextView44Ptr;
static ZKTextView* mTextView43Ptr;
static ZKTextView* mTextView40Ptr;
static ZKTextView* mTextView36Ptr;
static ZKTextView* mTextView35Ptr;
static ZKTextView* mTextView34Ptr;
static ZKTextView* mTextView33Ptr;
static ZKTextView* mTextView32Ptr;
static ZKTextView* mTextView31Ptr;
static ZKTextView* mTextView30Ptr;
static ZKTextView* mTextView29Ptr;
static ZKTextView* mTextView28Ptr;
static ZKTextView* mTextView27Ptr;
static ZKTextView* mTextView26Ptr;
static ZKTextView* mTextView25Ptr;
static ZKWindow* mWindowStatusPtr;
static ZKButton* mButtonDropDownPtr;
static ZKTextView* mTextViewWifiPtr;
static ZKTextView* mTextView24Ptr;
static ZKTextView* mTextView16Ptr;
static ZKTextView* mTextView15Ptr;
static ZKTextView* mTextView14Ptr;
static ZKTextView* mTextView13Ptr;
static ZKTextView* mTextView8Ptr;
static ZKTextView* mTextView7Ptr;
static ZKTextView* mTextView6Ptr;
static ZKTextView* mTextView5Ptr;
static ZKTextView* mTextView12Ptr;
static ZKTextView* mTextView11Ptr;
static ZKTextView* mTextView10Ptr;
static ZKTextView* mTextView9Ptr;
static ZKWindow* mWindow1Ptr;
static ManualModeActivity* mActivityPtr;

/*register activity*/
REGISTER_ACTIVITY(ManualModeActivity);

enum Manual_t {
	Manual_AirMode,
	Manual_Wind,
	Manual_Humd,
};

typedef struct {
	int id; // 定时器ID ， 不能重复
	int time; // 定时器  时间间隔  单位 毫秒
}S_ACTIVITY_TIMEER;

#include "logic/ManualModeLogic.cc"

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
    ID_MANUALMODE_ButtonHumdAdd, onButtonClick_ButtonHumdAdd,
    ID_MANUALMODE_ButtonHumdLess, onButtonClick_ButtonHumdLess,
    ID_MANUALMODE_ButtonHumdTimeOpen, onButtonClick_ButtonHumdTimeOpen,
    ID_MANUALMODE_ButtonHumdTimePic, onButtonClick_ButtonHumdTimePic,
    ID_MANUALMODE_ButtonHumdOpen, onButtonClick_ButtonHumdOpen,
    ID_MANUALMODE_ButtonAirAdd, onButtonClick_ButtonAirAdd,
    ID_MANUALMODE_ButtonAirLess, onButtonClick_ButtonAirLess,
    ID_MANUALMODE_ButtonAirTimeOpen, onButtonClick_ButtonAirTimeOpen,
    ID_MANUALMODE_ButtonAirTimePic, onButtonClick_ButtonAirTimePic,
    ID_MANUALMODE_ButtonAirOpen, onButtonClick_ButtonAirOpen,
    ID_MANUALMODE_ButtonWindTimeOpen, onButtonClick_ButtonWindTimeOpen,
    ID_MANUALMODE_ButtonWindTimePic, onButtonClick_ButtonWindTimePic,
    ID_MANUALMODE_ButtonWindOpen, onButtonClick_ButtonWindOpen,
    ID_MANUALMODE_ButtonWindStrong, onButtonClick_ButtonWindStrong,
    ID_MANUALMODE_ButtonWindWeak, onButtonClick_ButtonWindWeak,
    ID_MANUALMODE_ButtonWindOrdChangeAir, onButtonClick_ButtonWindOrdChangeAir,
    ID_MANUALMODE_ButtonWindHotReplace, onButtonClick_ButtonWindHotReplace,
    ID_MANUALMODE_ButtonWindAuto, onButtonClick_ButtonWindAuto,
    ID_MANUALMODE_ButtonHumd, onButtonClick_ButtonHumd,
    ID_MANUALMODE_ButtonWind, onButtonClick_ButtonWind,
    ID_MANUALMODE_ButtonAir, onButtonClick_ButtonAir,
    ID_MANUALMODE_ButtonDropDown, onButtonClick_ButtonDropDown,
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


ManualModeActivity::ManualModeActivity() {
	//todo add init code here
	mVideoLoopIndex = -1;
	mVideoLoopErrorCount = 0;
}

ManualModeActivity::~ManualModeActivity() {
  //todo add init file here
  // 退出应用时需要反注册
    EASYUICONTEXT->unregisterGlobalTouchListener(this);
    onUI_quit();
    unregisterProtocolDataUpdateListener(onProtocolDataUpdate);
}

const char* ManualModeActivity::getAppName() const{
	return "ManualMode.ftu";
}

//TAG:onCreate
void ManualModeActivity::onCreate() {
	Activity::onCreate();
    mButtonHumdAddPtr = (ZKButton*)findControlByID(ID_MANUALMODE_ButtonHumdAdd);
    mButtonHumdLessPtr = (ZKButton*)findControlByID(ID_MANUALMODE_ButtonHumdLess);
    mButtonHumdTimeOpenPtr = (ZKButton*)findControlByID(ID_MANUALMODE_ButtonHumdTimeOpen);
    mButtonHumdTimePicPtr = (ZKButton*)findControlByID(ID_MANUALMODE_ButtonHumdTimePic);
    mButtonHumdOpenPtr = (ZKButton*)findControlByID(ID_MANUALMODE_ButtonHumdOpen);
    mButtonAirAddPtr = (ZKButton*)findControlByID(ID_MANUALMODE_ButtonAirAdd);
    mButtonAirLessPtr = (ZKButton*)findControlByID(ID_MANUALMODE_ButtonAirLess);
    mButtonAirTimeOpenPtr = (ZKButton*)findControlByID(ID_MANUALMODE_ButtonAirTimeOpen);
    mButtonAirTimePicPtr = (ZKButton*)findControlByID(ID_MANUALMODE_ButtonAirTimePic);
    mButtonAirOpenPtr = (ZKButton*)findControlByID(ID_MANUALMODE_ButtonAirOpen);
    mWindowAirPtr = (ZKWindow*)findControlByID(ID_MANUALMODE_WindowAir);
    mButtonWindTimeOpenPtr = (ZKButton*)findControlByID(ID_MANUALMODE_ButtonWindTimeOpen);
    mButtonWindTimePicPtr = (ZKButton*)findControlByID(ID_MANUALMODE_ButtonWindTimePic);
    mButtonWindOpenPtr = (ZKButton*)findControlByID(ID_MANUALMODE_ButtonWindOpen);
    mWindowHumdSwitchPtr = (ZKWindow*)findControlByID(ID_MANUALMODE_WindowHumdSwitch);
    mButtonWindStrongPtr = (ZKButton*)findControlByID(ID_MANUALMODE_ButtonWindStrong);
    mButtonWindWeakPtr = (ZKButton*)findControlByID(ID_MANUALMODE_ButtonWindWeak);
    mButtonWindOrdChangeAirPtr = (ZKButton*)findControlByID(ID_MANUALMODE_ButtonWindOrdChangeAir);
    mButtonWindHotReplacePtr = (ZKButton*)findControlByID(ID_MANUALMODE_ButtonWindHotReplace);
    mButtonWindAutoPtr = (ZKButton*)findControlByID(ID_MANUALMODE_ButtonWindAuto);
    mWindowWindSwitchPtr = (ZKWindow*)findControlByID(ID_MANUALMODE_WindowWindSwitch);
    mButtonHumdPtr = (ZKButton*)findControlByID(ID_MANUALMODE_ButtonHumd);
    mButtonWindPtr = (ZKButton*)findControlByID(ID_MANUALMODE_ButtonWind);
    mButtonAirPtr = (ZKButton*)findControlByID(ID_MANUALMODE_ButtonAir);
    mWindowModeSelectPtr = (ZKWindow*)findControlByID(ID_MANUALMODE_WindowModeSelect);
    mTextView45Ptr = (ZKTextView*)findControlByID(ID_MANUALMODE_TextView45);
    mTextView44Ptr = (ZKTextView*)findControlByID(ID_MANUALMODE_TextView44);
    mTextView43Ptr = (ZKTextView*)findControlByID(ID_MANUALMODE_TextView43);
    mTextView40Ptr = (ZKTextView*)findControlByID(ID_MANUALMODE_TextView40);
    mTextView36Ptr = (ZKTextView*)findControlByID(ID_MANUALMODE_TextView36);
    mTextView35Ptr = (ZKTextView*)findControlByID(ID_MANUALMODE_TextView35);
    mTextView34Ptr = (ZKTextView*)findControlByID(ID_MANUALMODE_TextView34);
    mTextView33Ptr = (ZKTextView*)findControlByID(ID_MANUALMODE_TextView33);
    mTextView32Ptr = (ZKTextView*)findControlByID(ID_MANUALMODE_TextView32);
    mTextView31Ptr = (ZKTextView*)findControlByID(ID_MANUALMODE_TextView31);
    mTextView30Ptr = (ZKTextView*)findControlByID(ID_MANUALMODE_TextView30);
    mTextView29Ptr = (ZKTextView*)findControlByID(ID_MANUALMODE_TextView29);
    mTextView28Ptr = (ZKTextView*)findControlByID(ID_MANUALMODE_TextView28);
    mTextView27Ptr = (ZKTextView*)findControlByID(ID_MANUALMODE_TextView27);
    mTextView26Ptr = (ZKTextView*)findControlByID(ID_MANUALMODE_TextView26);
    mTextView25Ptr = (ZKTextView*)findControlByID(ID_MANUALMODE_TextView25);
    mWindowStatusPtr = (ZKWindow*)findControlByID(ID_MANUALMODE_WindowStatus);
    mButtonDropDownPtr = (ZKButton*)findControlByID(ID_MANUALMODE_ButtonDropDown);
    mTextViewWifiPtr = (ZKTextView*)findControlByID(ID_MANUALMODE_TextViewWifi);
    mTextView24Ptr = (ZKTextView*)findControlByID(ID_MANUALMODE_TextView24);
    mTextView16Ptr = (ZKTextView*)findControlByID(ID_MANUALMODE_TextView16);
    mTextView15Ptr = (ZKTextView*)findControlByID(ID_MANUALMODE_TextView15);
    mTextView14Ptr = (ZKTextView*)findControlByID(ID_MANUALMODE_TextView14);
    mTextView13Ptr = (ZKTextView*)findControlByID(ID_MANUALMODE_TextView13);
    mTextView8Ptr = (ZKTextView*)findControlByID(ID_MANUALMODE_TextView8);
    mTextView7Ptr = (ZKTextView*)findControlByID(ID_MANUALMODE_TextView7);
    mTextView6Ptr = (ZKTextView*)findControlByID(ID_MANUALMODE_TextView6);
    mTextView5Ptr = (ZKTextView*)findControlByID(ID_MANUALMODE_TextView5);
    mTextView12Ptr = (ZKTextView*)findControlByID(ID_MANUALMODE_TextView12);
    mTextView11Ptr = (ZKTextView*)findControlByID(ID_MANUALMODE_TextView11);
    mTextView10Ptr = (ZKTextView*)findControlByID(ID_MANUALMODE_TextView10);
    mTextView9Ptr = (ZKTextView*)findControlByID(ID_MANUALMODE_TextView9);
    mWindow1Ptr = (ZKWindow*)findControlByID(ID_MANUALMODE_Window1);
	mActivityPtr = this;
	onUI_init();
    registerProtocolDataUpdateListener(onProtocolDataUpdate); 
    rigesterActivityTimer();
}

void ManualModeActivity::onClick(ZKBase *pBase) {
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

void ManualModeActivity::onResume() {
	Activity::onResume();
	EASYUICONTEXT->registerGlobalTouchListener(this);
	startVideoLoopPlayback();
	onUI_show();
}

void ManualModeActivity::onPause() {
	Activity::onPause();
	EASYUICONTEXT->unregisterGlobalTouchListener(this);
	stopVideoLoopPlayback();
	onUI_hide();
}

void ManualModeActivity::onIntent(const Intent *intentPtr) {
	Activity::onIntent(intentPtr);
	onUI_intent(intentPtr);
}

bool ManualModeActivity::onTimer(int id) {
	return onUI_Timer(id);
}

void ManualModeActivity::onProgressChanged(ZKSeekBar *pSeekBar, int progress){

    int seekBarTablen = sizeof(SZKSeekBarCallbackTab) / sizeof(S_ZKSeekBarCallback);
    for (int i = 0; i < seekBarTablen; ++i) {
        if (SZKSeekBarCallbackTab[i].id == pSeekBar->getID()) {
            SZKSeekBarCallbackTab[i].callback(pSeekBar, progress);
            break;
        }
    }
}

int ManualModeActivity::getListItemCount(const ZKListView *pListView) const{
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            return SListViewFunctionsCallbackTab[i].getListItemCountCallback(pListView);
            break;
        }
    }
    return 0;
}

void ManualModeActivity::obtainListItemData(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index){
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            SListViewFunctionsCallbackTab[i].obtainListItemDataCallback(pListView, pListItem, index);
            break;
        }
    }
}

void ManualModeActivity::onItemClick(ZKListView *pListView, int index, int id){
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            SListViewFunctionsCallbackTab[i].onItemClickCallback(pListView, index, id);
            break;
        }
    }
}

void ManualModeActivity::onSlideItemClick(ZKSlideWindow *pSlideWindow, int index) {
    int tablen = sizeof(SSlideWindowItemClickCallbackTab) / sizeof(S_SlideWindowItemClickCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SSlideWindowItemClickCallbackTab[i].id == pSlideWindow->getID()) {
            SSlideWindowItemClickCallbackTab[i].onSlideItemClickCallback(pSlideWindow, index);
            break;
        }
    }
}

bool ManualModeActivity::onTouchEvent(const MotionEvent &ev) {
    return onManualModeActivityTouchEvent(ev);
}

void ManualModeActivity::onTextChanged(ZKTextView *pTextView, const std::string &text) {
    int tablen = sizeof(SEditTextInputCallbackTab) / sizeof(S_EditTextInputCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SEditTextInputCallbackTab[i].id == pTextView->getID()) {
            SEditTextInputCallbackTab[i].onEditTextChangedCallback(text);
            break;
        }
    }
}

void ManualModeActivity::rigesterActivityTimer() {
    int tablen = sizeof(REGISTER_ACTIVITY_TIMER_TAB) / sizeof(S_ACTIVITY_TIMEER);
    for (int i = 0; i < tablen; ++i) {
        S_ACTIVITY_TIMEER temp = REGISTER_ACTIVITY_TIMER_TAB[i];
        registerTimer(temp.id, temp.time);
    }
}


void ManualModeActivity::onVideoPlayerMessage(ZKVideoView *pVideoView, int msg) {
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

void ManualModeActivity::videoLoopPlayback(ZKVideoView *pVideoView, int msg, size_t callbackTabIndex) {

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

void ManualModeActivity::startVideoLoopPlayback() {
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

void ManualModeActivity::stopVideoLoopPlayback() {
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

bool ManualModeActivity::parseVideoFileList(const char *pFileListPath, std::vector<string>& mediaFileList) {
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

int ManualModeActivity::removeCharFromString(string& nString, char c) {
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

void ManualModeActivity::registerUserTimer(int id, int time) {
	registerTimer(id, time);
}

void ManualModeActivity::unregisterUserTimer(int id) {
	unregisterTimer(id);
}

void ManualModeActivity::resetUserTimer(int id, int time) {
	resetTimer(id, time);
}
