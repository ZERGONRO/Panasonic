/***********************************************
/gen auto by zuitools
***********************************************/
#include "PressModeActivity.h"

/*TAG:GlobalVariable全局变量*/
static ZKTextView* mTextView2Ptr;
static ZKButton* mButtonAddPtr;
static ZKButton* mButtonLessPtr;
static ZKButton* mButtonPressModePtr;
static ZKButton* mButtonStdModePtr;
static ZKButton* mButtonDIYModePtr;
static ZKButton* mButtonBackPtr;
static ZKTextView* mTextView13Ptr;
static ZKTextView* mTextView11Ptr;
static ZKTextView* mTextView10Ptr;
static ZKWindow* mWindowDIYModePtr;
static ZKButton* mButtonPressMidPtr;
static ZKButton* mButtonPressWeakPtr;
static ZKButton* mButtonPressStrongPtr;
static ZKTextView* mTextView4Ptr;
static ZKWindow* mWindowPressParamSettingPtr;
static ZKTextView* mTextView1Ptr;
static ZKWindow* mWindowModeSelectPtr;
static ZKWindow* mWindow1Ptr;
static ZKTextView* mTextView3Ptr;
static ZKTextView* mTextView8Ptr;
static PressModeActivity* mActivityPtr;

/*register activity*/
REGISTER_ACTIVITY(PressModeActivity);

typedef struct {
	int id; // 定时器ID ， 不能重复
	int time; // 定时器  时间间隔  单位 毫秒
}S_ACTIVITY_TIMEER;

#include "logic/PressModeLogic.cc"

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
    ID_PRESSMODE_ButtonAdd, onButtonClick_ButtonAdd,
    ID_PRESSMODE_ButtonLess, onButtonClick_ButtonLess,
    ID_PRESSMODE_ButtonPressMode, onButtonClick_ButtonPressMode,
    ID_PRESSMODE_ButtonStdMode, onButtonClick_ButtonStdMode,
    ID_PRESSMODE_ButtonDIYMode, onButtonClick_ButtonDIYMode,
    ID_PRESSMODE_ButtonBack, onButtonClick_ButtonBack,
    ID_PRESSMODE_ButtonPressMid, onButtonClick_ButtonPressMid,
    ID_PRESSMODE_ButtonPressWeak, onButtonClick_ButtonPressWeak,
    ID_PRESSMODE_ButtonPressStrong, onButtonClick_ButtonPressStrong,
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


PressModeActivity::PressModeActivity() {
	//todo add init code here
	mVideoLoopIndex = -1;
	mVideoLoopErrorCount = 0;
}

PressModeActivity::~PressModeActivity() {
  //todo add init file here
  // 退出应用时需要反注册
    EASYUICONTEXT->unregisterGlobalTouchListener(this);
    onUI_quit();
    unregisterProtocolDataUpdateListener(onProtocolDataUpdate);
}

const char* PressModeActivity::getAppName() const{
	return "PressMode.ftu";
}

//TAG:onCreate
void PressModeActivity::onCreate() {
	Activity::onCreate();
    mTextView2Ptr = (ZKTextView*)findControlByID(ID_PRESSMODE_TextView2);
    mButtonAddPtr = (ZKButton*)findControlByID(ID_PRESSMODE_ButtonAdd);
    mButtonLessPtr = (ZKButton*)findControlByID(ID_PRESSMODE_ButtonLess);
    mButtonPressModePtr = (ZKButton*)findControlByID(ID_PRESSMODE_ButtonPressMode);
    mButtonStdModePtr = (ZKButton*)findControlByID(ID_PRESSMODE_ButtonStdMode);
    mButtonDIYModePtr = (ZKButton*)findControlByID(ID_PRESSMODE_ButtonDIYMode);
    mButtonBackPtr = (ZKButton*)findControlByID(ID_PRESSMODE_ButtonBack);
    mTextView13Ptr = (ZKTextView*)findControlByID(ID_PRESSMODE_TextView13);
    mTextView11Ptr = (ZKTextView*)findControlByID(ID_PRESSMODE_TextView11);
    mTextView10Ptr = (ZKTextView*)findControlByID(ID_PRESSMODE_TextView10);
    mWindowDIYModePtr = (ZKWindow*)findControlByID(ID_PRESSMODE_WindowDIYMode);
    mButtonPressMidPtr = (ZKButton*)findControlByID(ID_PRESSMODE_ButtonPressMid);
    mButtonPressWeakPtr = (ZKButton*)findControlByID(ID_PRESSMODE_ButtonPressWeak);
    mButtonPressStrongPtr = (ZKButton*)findControlByID(ID_PRESSMODE_ButtonPressStrong);
    mTextView4Ptr = (ZKTextView*)findControlByID(ID_PRESSMODE_TextView4);
    mWindowPressParamSettingPtr = (ZKWindow*)findControlByID(ID_PRESSMODE_WindowPressParamSetting);
    mTextView1Ptr = (ZKTextView*)findControlByID(ID_PRESSMODE_TextView1);
    mWindowModeSelectPtr = (ZKWindow*)findControlByID(ID_PRESSMODE_WindowModeSelect);
    mWindow1Ptr = (ZKWindow*)findControlByID(ID_PRESSMODE_Window1);
    mTextView3Ptr = (ZKTextView*)findControlByID(ID_PRESSMODE_TextView3);
    mTextView8Ptr = (ZKTextView*)findControlByID(ID_PRESSMODE_TextView8);
	mActivityPtr = this;
	onUI_init();
    registerProtocolDataUpdateListener(onProtocolDataUpdate); 
    rigesterActivityTimer();
}

void PressModeActivity::onClick(ZKBase *pBase) {
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

void PressModeActivity::onResume() {
	Activity::onResume();
	EASYUICONTEXT->registerGlobalTouchListener(this);
	startVideoLoopPlayback();
	onUI_show();
}

void PressModeActivity::onPause() {
	Activity::onPause();
	EASYUICONTEXT->unregisterGlobalTouchListener(this);
	stopVideoLoopPlayback();
	onUI_hide();
}

void PressModeActivity::onIntent(const Intent *intentPtr) {
	Activity::onIntent(intentPtr);
	onUI_intent(intentPtr);
}

bool PressModeActivity::onTimer(int id) {
	return onUI_Timer(id);
}

void PressModeActivity::onProgressChanged(ZKSeekBar *pSeekBar, int progress){

    int seekBarTablen = sizeof(SZKSeekBarCallbackTab) / sizeof(S_ZKSeekBarCallback);
    for (int i = 0; i < seekBarTablen; ++i) {
        if (SZKSeekBarCallbackTab[i].id == pSeekBar->getID()) {
            SZKSeekBarCallbackTab[i].callback(pSeekBar, progress);
            break;
        }
    }
}

int PressModeActivity::getListItemCount(const ZKListView *pListView) const{
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            return SListViewFunctionsCallbackTab[i].getListItemCountCallback(pListView);
            break;
        }
    }
    return 0;
}

void PressModeActivity::obtainListItemData(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index){
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            SListViewFunctionsCallbackTab[i].obtainListItemDataCallback(pListView, pListItem, index);
            break;
        }
    }
}

void PressModeActivity::onItemClick(ZKListView *pListView, int index, int id){
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            SListViewFunctionsCallbackTab[i].onItemClickCallback(pListView, index, id);
            break;
        }
    }
}

void PressModeActivity::onSlideItemClick(ZKSlideWindow *pSlideWindow, int index) {
    int tablen = sizeof(SSlideWindowItemClickCallbackTab) / sizeof(S_SlideWindowItemClickCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SSlideWindowItemClickCallbackTab[i].id == pSlideWindow->getID()) {
            SSlideWindowItemClickCallbackTab[i].onSlideItemClickCallback(pSlideWindow, index);
            break;
        }
    }
}

bool PressModeActivity::onTouchEvent(const MotionEvent &ev) {
    return onPressModeActivityTouchEvent(ev);
}

void PressModeActivity::onTextChanged(ZKTextView *pTextView, const std::string &text) {
    int tablen = sizeof(SEditTextInputCallbackTab) / sizeof(S_EditTextInputCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SEditTextInputCallbackTab[i].id == pTextView->getID()) {
            SEditTextInputCallbackTab[i].onEditTextChangedCallback(text);
            break;
        }
    }
}

void PressModeActivity::rigesterActivityTimer() {
    int tablen = sizeof(REGISTER_ACTIVITY_TIMER_TAB) / sizeof(S_ACTIVITY_TIMEER);
    for (int i = 0; i < tablen; ++i) {
        S_ACTIVITY_TIMEER temp = REGISTER_ACTIVITY_TIMER_TAB[i];
        registerTimer(temp.id, temp.time);
    }
}


void PressModeActivity::onVideoPlayerMessage(ZKVideoView *pVideoView, int msg) {
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

void PressModeActivity::videoLoopPlayback(ZKVideoView *pVideoView, int msg, size_t callbackTabIndex) {

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

void PressModeActivity::startVideoLoopPlayback() {
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

void PressModeActivity::stopVideoLoopPlayback() {
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

bool PressModeActivity::parseVideoFileList(const char *pFileListPath, std::vector<string>& mediaFileList) {
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

int PressModeActivity::removeCharFromString(string& nString, char c) {
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

void PressModeActivity::registerUserTimer(int id, int time) {
	registerTimer(id, time);
}

void PressModeActivity::unregisterUserTimer(int id) {
	unregisterTimer(id);
}

void PressModeActivity::resetUserTimer(int id, int time) {
	resetTimer(id, time);
}