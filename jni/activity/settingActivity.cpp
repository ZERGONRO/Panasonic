/***********************************************
/gen auto by zuitools
***********************************************/
#include "settingActivity.h"

/*TAG:GlobalVariable全局变量*/
static ZKButton* mButton2Ptr;
static ZKButton* mButtonMasterSlaverSet1Ptr;
static ZKButton* mButtonVoiceSysSet1Ptr;
static ZKButton* mButtonBackPtr;
static ZKTextView* mTextView22Ptr;
static ZKTextView* mTextView21Ptr;
static ZKTextView* mTextView4Ptr;
static ZKTextView* mTextView3Ptr;
static ZKButton* mButtonConfirmPtr;
static ZKButton* mButtonCancelPtr;
static ZKTextView* mTextView2Ptr;
static ZKTextView* mTextView1Ptr;
static ZKWindow* mWindowReset2Ptr;
static ZKButton* mButtonCtlSet1Ptr;
static ZKTextView* mTextView43Ptr;
static ZKTextView* mTextView42Ptr;
static ZKWindow* mWindowCtlSet1Ptr;
static ZKButton* mButtonReset1Ptr;
static ZKTextView* mTextView41Ptr;
static ZKTextView* mTextView40Ptr;
static ZKWindow* mWindowReset1Ptr;
static ZKButton* mButtonWifiSetting1Ptr;
static ZKTextView* mTextView39Ptr;
static ZKTextView* mTextView38Ptr;
static ZKWindow* mWindowWifiSetting1Ptr;
static ZKButton* mButtonFWUpdate1Ptr;
static ZKTextView* mTextView37Ptr;
static ZKTextView* mTextView36Ptr;
static ZKWindow* mWindowFWUpdate1Ptr;
static ZKTextView* mTextView35Ptr;
static ZKTextView* mTextView34Ptr;
static ZKWindow* mWindowDeviceSet1Ptr;
static ZKButton* mButtonFilterSet1Ptr;
static ZKTextView* mTextView33Ptr;
static ZKTextView* mTextView32Ptr;
static ZKWindow* mWindowFilterSet1Ptr;
static ZKButton* mButtonBodySensor1Ptr;
static ZKTextView* mTextView31Ptr;
static ZKTextView* mTextView30Ptr;
static ZKWindow* mWindowBodySensor1Ptr;
static ZKButton* mButtonTimesetting1Ptr;
static ZKTextView* mTextView29Ptr;
static ZKTextView* mTextView28Ptr;
static ZKWindow* mWindowTimeSetting1Ptr;
static ZKTextView* mTextView27Ptr;
static ZKTextView* mTextView26Ptr;
static ZKWindow* mWindowPressSet1Ptr;
static ZKButton* mButtonSensorCtl1Ptr;
static ZKTextView* mTextView25Ptr;
static ZKTextView* mTextView24Ptr;
static ZKWindow* mWindowSensorCtl1Ptr;
static ZKWindow* mWindow1Ptr;
static settingActivity* mActivityPtr;

/*register activity*/
REGISTER_ACTIVITY(settingActivity);

typedef struct {
	int id; // 定时器ID ， 不能重复
	int time; // 定时器  时间间隔  单位 毫秒
}S_ACTIVITY_TIMEER;

#include "logic/settingLogic.cc"

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
    ID_SETTING_Button2, onButtonClick_Button2,
    ID_SETTING_ButtonMasterSlaverSet1, onButtonClick_ButtonMasterSlaverSet1,
    ID_SETTING_ButtonVoiceSysSet1, onButtonClick_ButtonVoiceSysSet1,
    ID_SETTING_ButtonBack, onButtonClick_ButtonBack,
    ID_SETTING_ButtonConfirm, onButtonClick_ButtonConfirm,
    ID_SETTING_ButtonCancel, onButtonClick_ButtonCancel,
    ID_SETTING_ButtonCtlSet1, onButtonClick_ButtonCtlSet1,
    ID_SETTING_ButtonReset1, onButtonClick_ButtonReset1,
    ID_SETTING_ButtonWifiSetting1, onButtonClick_ButtonWifiSetting1,
    ID_SETTING_ButtonFWUpdate1, onButtonClick_ButtonFWUpdate1,
    ID_SETTING_ButtonFilterSet1, onButtonClick_ButtonFilterSet1,
    ID_SETTING_ButtonBodySensor1, onButtonClick_ButtonBodySensor1,
    ID_SETTING_ButtonTimesetting1, onButtonClick_ButtonTimesetting1,
    ID_SETTING_ButtonSensorCtl1, onButtonClick_ButtonSensorCtl1,
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


settingActivity::settingActivity() {
	//todo add init code here
	mVideoLoopIndex = -1;
	mVideoLoopErrorCount = 0;
}

settingActivity::~settingActivity() {
  //todo add init file here
  // 退出应用时需要反注册
    EASYUICONTEXT->unregisterGlobalTouchListener(this);
    onUI_quit();
    unregisterProtocolDataUpdateListener(onProtocolDataUpdate);
}

const char* settingActivity::getAppName() const{
	return "setting.ftu";
}

//TAG:onCreate
void settingActivity::onCreate() {
	Activity::onCreate();
    mButton2Ptr = (ZKButton*)findControlByID(ID_SETTING_Button2);
    mButtonMasterSlaverSet1Ptr = (ZKButton*)findControlByID(ID_SETTING_ButtonMasterSlaverSet1);
    mButtonVoiceSysSet1Ptr = (ZKButton*)findControlByID(ID_SETTING_ButtonVoiceSysSet1);
    mButtonBackPtr = (ZKButton*)findControlByID(ID_SETTING_ButtonBack);
    mTextView22Ptr = (ZKTextView*)findControlByID(ID_SETTING_TextView22);
    mTextView21Ptr = (ZKTextView*)findControlByID(ID_SETTING_TextView21);
    mTextView4Ptr = (ZKTextView*)findControlByID(ID_SETTING_TextView4);
    mTextView3Ptr = (ZKTextView*)findControlByID(ID_SETTING_TextView3);
    mButtonConfirmPtr = (ZKButton*)findControlByID(ID_SETTING_ButtonConfirm);
    mButtonCancelPtr = (ZKButton*)findControlByID(ID_SETTING_ButtonCancel);
    mTextView2Ptr = (ZKTextView*)findControlByID(ID_SETTING_TextView2);
    mTextView1Ptr = (ZKTextView*)findControlByID(ID_SETTING_TextView1);
    mWindowReset2Ptr = (ZKWindow*)findControlByID(ID_SETTING_WindowReset2);
    mButtonCtlSet1Ptr = (ZKButton*)findControlByID(ID_SETTING_ButtonCtlSet1);
    mTextView43Ptr = (ZKTextView*)findControlByID(ID_SETTING_TextView43);
    mTextView42Ptr = (ZKTextView*)findControlByID(ID_SETTING_TextView42);
    mWindowCtlSet1Ptr = (ZKWindow*)findControlByID(ID_SETTING_WindowCtlSet1);
    mButtonReset1Ptr = (ZKButton*)findControlByID(ID_SETTING_ButtonReset1);
    mTextView41Ptr = (ZKTextView*)findControlByID(ID_SETTING_TextView41);
    mTextView40Ptr = (ZKTextView*)findControlByID(ID_SETTING_TextView40);
    mWindowReset1Ptr = (ZKWindow*)findControlByID(ID_SETTING_WindowReset1);
    mButtonWifiSetting1Ptr = (ZKButton*)findControlByID(ID_SETTING_ButtonWifiSetting1);
    mTextView39Ptr = (ZKTextView*)findControlByID(ID_SETTING_TextView39);
    mTextView38Ptr = (ZKTextView*)findControlByID(ID_SETTING_TextView38);
    mWindowWifiSetting1Ptr = (ZKWindow*)findControlByID(ID_SETTING_WindowWifiSetting1);
    mButtonFWUpdate1Ptr = (ZKButton*)findControlByID(ID_SETTING_ButtonFWUpdate1);
    mTextView37Ptr = (ZKTextView*)findControlByID(ID_SETTING_TextView37);
    mTextView36Ptr = (ZKTextView*)findControlByID(ID_SETTING_TextView36);
    mWindowFWUpdate1Ptr = (ZKWindow*)findControlByID(ID_SETTING_WindowFWUpdate1);
    mTextView35Ptr = (ZKTextView*)findControlByID(ID_SETTING_TextView35);
    mTextView34Ptr = (ZKTextView*)findControlByID(ID_SETTING_TextView34);
    mWindowDeviceSet1Ptr = (ZKWindow*)findControlByID(ID_SETTING_WindowDeviceSet1);
    mButtonFilterSet1Ptr = (ZKButton*)findControlByID(ID_SETTING_ButtonFilterSet1);
    mTextView33Ptr = (ZKTextView*)findControlByID(ID_SETTING_TextView33);
    mTextView32Ptr = (ZKTextView*)findControlByID(ID_SETTING_TextView32);
    mWindowFilterSet1Ptr = (ZKWindow*)findControlByID(ID_SETTING_WindowFilterSet1);
    mButtonBodySensor1Ptr = (ZKButton*)findControlByID(ID_SETTING_ButtonBodySensor1);
    mTextView31Ptr = (ZKTextView*)findControlByID(ID_SETTING_TextView31);
    mTextView30Ptr = (ZKTextView*)findControlByID(ID_SETTING_TextView30);
    mWindowBodySensor1Ptr = (ZKWindow*)findControlByID(ID_SETTING_WindowBodySensor1);
    mButtonTimesetting1Ptr = (ZKButton*)findControlByID(ID_SETTING_ButtonTimesetting1);
    mTextView29Ptr = (ZKTextView*)findControlByID(ID_SETTING_TextView29);
    mTextView28Ptr = (ZKTextView*)findControlByID(ID_SETTING_TextView28);
    mWindowTimeSetting1Ptr = (ZKWindow*)findControlByID(ID_SETTING_WindowTimeSetting1);
    mTextView27Ptr = (ZKTextView*)findControlByID(ID_SETTING_TextView27);
    mTextView26Ptr = (ZKTextView*)findControlByID(ID_SETTING_TextView26);
    mWindowPressSet1Ptr = (ZKWindow*)findControlByID(ID_SETTING_WindowPressSet1);
    mButtonSensorCtl1Ptr = (ZKButton*)findControlByID(ID_SETTING_ButtonSensorCtl1);
    mTextView25Ptr = (ZKTextView*)findControlByID(ID_SETTING_TextView25);
    mTextView24Ptr = (ZKTextView*)findControlByID(ID_SETTING_TextView24);
    mWindowSensorCtl1Ptr = (ZKWindow*)findControlByID(ID_SETTING_WindowSensorCtl1);
    mWindow1Ptr = (ZKWindow*)findControlByID(ID_SETTING_Window1);
	mActivityPtr = this;
	onUI_init();
    registerProtocolDataUpdateListener(onProtocolDataUpdate); 
    rigesterActivityTimer();
}

void settingActivity::onClick(ZKBase *pBase) {
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

void settingActivity::onResume() {
	Activity::onResume();
	EASYUICONTEXT->registerGlobalTouchListener(this);
	startVideoLoopPlayback();
	onUI_show();
}

void settingActivity::onPause() {
	Activity::onPause();
	EASYUICONTEXT->unregisterGlobalTouchListener(this);
	stopVideoLoopPlayback();
	onUI_hide();
}

void settingActivity::onIntent(const Intent *intentPtr) {
	Activity::onIntent(intentPtr);
	onUI_intent(intentPtr);
}

bool settingActivity::onTimer(int id) {
	return onUI_Timer(id);
}

void settingActivity::onProgressChanged(ZKSeekBar *pSeekBar, int progress){

    int seekBarTablen = sizeof(SZKSeekBarCallbackTab) / sizeof(S_ZKSeekBarCallback);
    for (int i = 0; i < seekBarTablen; ++i) {
        if (SZKSeekBarCallbackTab[i].id == pSeekBar->getID()) {
            SZKSeekBarCallbackTab[i].callback(pSeekBar, progress);
            break;
        }
    }
}

int settingActivity::getListItemCount(const ZKListView *pListView) const{
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            return SListViewFunctionsCallbackTab[i].getListItemCountCallback(pListView);
            break;
        }
    }
    return 0;
}

void settingActivity::obtainListItemData(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index){
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            SListViewFunctionsCallbackTab[i].obtainListItemDataCallback(pListView, pListItem, index);
            break;
        }
    }
}

void settingActivity::onItemClick(ZKListView *pListView, int index, int id){
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            SListViewFunctionsCallbackTab[i].onItemClickCallback(pListView, index, id);
            break;
        }
    }
}

void settingActivity::onSlideItemClick(ZKSlideWindow *pSlideWindow, int index) {
    int tablen = sizeof(SSlideWindowItemClickCallbackTab) / sizeof(S_SlideWindowItemClickCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SSlideWindowItemClickCallbackTab[i].id == pSlideWindow->getID()) {
            SSlideWindowItemClickCallbackTab[i].onSlideItemClickCallback(pSlideWindow, index);
            break;
        }
    }
}

bool settingActivity::onTouchEvent(const MotionEvent &ev) {
    return onsettingActivityTouchEvent(ev);
}

void settingActivity::onTextChanged(ZKTextView *pTextView, const std::string &text) {
    int tablen = sizeof(SEditTextInputCallbackTab) / sizeof(S_EditTextInputCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SEditTextInputCallbackTab[i].id == pTextView->getID()) {
            SEditTextInputCallbackTab[i].onEditTextChangedCallback(text);
            break;
        }
    }
}

void settingActivity::rigesterActivityTimer() {
    int tablen = sizeof(REGISTER_ACTIVITY_TIMER_TAB) / sizeof(S_ACTIVITY_TIMEER);
    for (int i = 0; i < tablen; ++i) {
        S_ACTIVITY_TIMEER temp = REGISTER_ACTIVITY_TIMER_TAB[i];
        registerTimer(temp.id, temp.time);
    }
}


void settingActivity::onVideoPlayerMessage(ZKVideoView *pVideoView, int msg) {
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

void settingActivity::videoLoopPlayback(ZKVideoView *pVideoView, int msg, size_t callbackTabIndex) {

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

void settingActivity::startVideoLoopPlayback() {
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

void settingActivity::stopVideoLoopPlayback() {
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

bool settingActivity::parseVideoFileList(const char *pFileListPath, std::vector<string>& mediaFileList) {
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

int settingActivity::removeCharFromString(string& nString, char c) {
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

void settingActivity::registerUserTimer(int id, int time) {
	registerTimer(id, time);
}

void settingActivity::unregisterUserTimer(int id) {
	unregisterTimer(id);
}

void settingActivity::resetUserTimer(int id, int time) {
	resetTimer(id, time);
}