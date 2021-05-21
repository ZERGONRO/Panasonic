/***********************************************
/gen auto by zuitools
***********************************************/
#include "FilterSettingActivity.h"

/*TAG:GlobalVariable全局变量*/
static ZKTextView* mTextView10Ptr;
static ZKTextView* mTextView7Ptr;
static ZKTextView* mTextView5Ptr;
static ZKButton* mButtonChangePtr;
static ZKButton* mButtonContinuePtr;
static ZKWindow* mWindow3Ptr;
static ZKButton* mButtonChangeCyclePtr;
static ZKButton* mButton6monthPtr;
static ZKButton* mButton5monthPtr;
static ZKButton* mButton4monthPtr;
static ZKButton* mButton3monthPtr;
static ZKWindow* mWindow2Ptr;
static ZKTextView* mTextView16Ptr;
static ZKTextView* mTextView15Ptr;
static ZKTextView* mTextView14Ptr;
static ZKTextView* mTextView13Ptr;
static ZKTextView* mTextView11Ptr;
static ZKTextView* mTextView9Ptr;
static ZKTextView* mTextView6Ptr;
static ZKTextView* mTextView4Ptr;
static ZKTextView* mTextView1Ptr;
static ZKWindow* mWindow1Ptr;
static ZKButton* mButtonBackPtr;
static ZKButton* mButtonCFilterPtr;
static ZKButton* mButtonStrengthFilterPtr;
static ZKButton* mButtonWindFilterPtr;
static ZKButton* mButtonStdFilterPtr;
static ZKTextView* mTextView12Ptr;
static ZKTextView* mTextView2Ptr;
static ZKTextView* mTextView3Ptr;
static ZKTextView* mTextView8Ptr;
static FilterSettingActivity* mActivityPtr;

/*register activity*/
REGISTER_ACTIVITY(FilterSettingActivity);

typedef struct {
	int id; // 定时器ID ， 不能重复
	int time; // 定时器  时间间隔  单位 毫秒
}S_ACTIVITY_TIMEER;

#include "logic/FilterSettingLogic.cc"

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
    ID_FILTERSETTING_ButtonChange, onButtonClick_ButtonChange,
    ID_FILTERSETTING_ButtonContinue, onButtonClick_ButtonContinue,
    ID_FILTERSETTING_ButtonChangeCycle, onButtonClick_ButtonChangeCycle,
    ID_FILTERSETTING_Button6month, onButtonClick_Button6month,
    ID_FILTERSETTING_Button5month, onButtonClick_Button5month,
    ID_FILTERSETTING_Button4month, onButtonClick_Button4month,
    ID_FILTERSETTING_Button3month, onButtonClick_Button3month,
    ID_FILTERSETTING_ButtonBack, onButtonClick_ButtonBack,
    ID_FILTERSETTING_ButtonCFilter, onButtonClick_ButtonCFilter,
    ID_FILTERSETTING_ButtonStrengthFilter, onButtonClick_ButtonStrengthFilter,
    ID_FILTERSETTING_ButtonWindFilter, onButtonClick_ButtonWindFilter,
    ID_FILTERSETTING_ButtonStdFilter, onButtonClick_ButtonStdFilter,
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


FilterSettingActivity::FilterSettingActivity() {
	//todo add init code here
	mVideoLoopIndex = -1;
	mVideoLoopErrorCount = 0;
}

FilterSettingActivity::~FilterSettingActivity() {
  //todo add init file here
  // 退出应用时需要反注册
    EASYUICONTEXT->unregisterGlobalTouchListener(this);
    onUI_quit();
    unregisterProtocolDataUpdateListener(onProtocolDataUpdate);
}

const char* FilterSettingActivity::getAppName() const{
	return "FilterSetting.ftu";
}

//TAG:onCreate
void FilterSettingActivity::onCreate() {
	Activity::onCreate();
    mTextView10Ptr = (ZKTextView*)findControlByID(ID_FILTERSETTING_TextView10);
    mTextView7Ptr = (ZKTextView*)findControlByID(ID_FILTERSETTING_TextView7);
    mTextView5Ptr = (ZKTextView*)findControlByID(ID_FILTERSETTING_TextView5);
    mButtonChangePtr = (ZKButton*)findControlByID(ID_FILTERSETTING_ButtonChange);
    mButtonContinuePtr = (ZKButton*)findControlByID(ID_FILTERSETTING_ButtonContinue);
    mWindow3Ptr = (ZKWindow*)findControlByID(ID_FILTERSETTING_Window3);
    mButtonChangeCyclePtr = (ZKButton*)findControlByID(ID_FILTERSETTING_ButtonChangeCycle);
    mButton6monthPtr = (ZKButton*)findControlByID(ID_FILTERSETTING_Button6month);
    mButton5monthPtr = (ZKButton*)findControlByID(ID_FILTERSETTING_Button5month);
    mButton4monthPtr = (ZKButton*)findControlByID(ID_FILTERSETTING_Button4month);
    mButton3monthPtr = (ZKButton*)findControlByID(ID_FILTERSETTING_Button3month);
    mWindow2Ptr = (ZKWindow*)findControlByID(ID_FILTERSETTING_Window2);
    mTextView16Ptr = (ZKTextView*)findControlByID(ID_FILTERSETTING_TextView16);
    mTextView15Ptr = (ZKTextView*)findControlByID(ID_FILTERSETTING_TextView15);
    mTextView14Ptr = (ZKTextView*)findControlByID(ID_FILTERSETTING_TextView14);
    mTextView13Ptr = (ZKTextView*)findControlByID(ID_FILTERSETTING_TextView13);
    mTextView11Ptr = (ZKTextView*)findControlByID(ID_FILTERSETTING_TextView11);
    mTextView9Ptr = (ZKTextView*)findControlByID(ID_FILTERSETTING_TextView9);
    mTextView6Ptr = (ZKTextView*)findControlByID(ID_FILTERSETTING_TextView6);
    mTextView4Ptr = (ZKTextView*)findControlByID(ID_FILTERSETTING_TextView4);
    mTextView1Ptr = (ZKTextView*)findControlByID(ID_FILTERSETTING_TextView1);
    mWindow1Ptr = (ZKWindow*)findControlByID(ID_FILTERSETTING_Window1);
    mButtonBackPtr = (ZKButton*)findControlByID(ID_FILTERSETTING_ButtonBack);
    mButtonCFilterPtr = (ZKButton*)findControlByID(ID_FILTERSETTING_ButtonCFilter);
    mButtonStrengthFilterPtr = (ZKButton*)findControlByID(ID_FILTERSETTING_ButtonStrengthFilter);
    mButtonWindFilterPtr = (ZKButton*)findControlByID(ID_FILTERSETTING_ButtonWindFilter);
    mButtonStdFilterPtr = (ZKButton*)findControlByID(ID_FILTERSETTING_ButtonStdFilter);
    mTextView12Ptr = (ZKTextView*)findControlByID(ID_FILTERSETTING_TextView12);
    mTextView2Ptr = (ZKTextView*)findControlByID(ID_FILTERSETTING_TextView2);
    mTextView3Ptr = (ZKTextView*)findControlByID(ID_FILTERSETTING_TextView3);
    mTextView8Ptr = (ZKTextView*)findControlByID(ID_FILTERSETTING_TextView8);
	mActivityPtr = this;
	onUI_init();
    registerProtocolDataUpdateListener(onProtocolDataUpdate); 
    rigesterActivityTimer();
}

void FilterSettingActivity::onClick(ZKBase *pBase) {
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

void FilterSettingActivity::onResume() {
	Activity::onResume();
	EASYUICONTEXT->registerGlobalTouchListener(this);
	startVideoLoopPlayback();
	onUI_show();
}

void FilterSettingActivity::onPause() {
	Activity::onPause();
	EASYUICONTEXT->unregisterGlobalTouchListener(this);
	stopVideoLoopPlayback();
	onUI_hide();
}

void FilterSettingActivity::onIntent(const Intent *intentPtr) {
	Activity::onIntent(intentPtr);
	onUI_intent(intentPtr);
}

bool FilterSettingActivity::onTimer(int id) {
	return onUI_Timer(id);
}

void FilterSettingActivity::onProgressChanged(ZKSeekBar *pSeekBar, int progress){

    int seekBarTablen = sizeof(SZKSeekBarCallbackTab) / sizeof(S_ZKSeekBarCallback);
    for (int i = 0; i < seekBarTablen; ++i) {
        if (SZKSeekBarCallbackTab[i].id == pSeekBar->getID()) {
            SZKSeekBarCallbackTab[i].callback(pSeekBar, progress);
            break;
        }
    }
}

int FilterSettingActivity::getListItemCount(const ZKListView *pListView) const{
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            return SListViewFunctionsCallbackTab[i].getListItemCountCallback(pListView);
            break;
        }
    }
    return 0;
}

void FilterSettingActivity::obtainListItemData(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index){
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            SListViewFunctionsCallbackTab[i].obtainListItemDataCallback(pListView, pListItem, index);
            break;
        }
    }
}

void FilterSettingActivity::onItemClick(ZKListView *pListView, int index, int id){
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            SListViewFunctionsCallbackTab[i].onItemClickCallback(pListView, index, id);
            break;
        }
    }
}

void FilterSettingActivity::onSlideItemClick(ZKSlideWindow *pSlideWindow, int index) {
    int tablen = sizeof(SSlideWindowItemClickCallbackTab) / sizeof(S_SlideWindowItemClickCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SSlideWindowItemClickCallbackTab[i].id == pSlideWindow->getID()) {
            SSlideWindowItemClickCallbackTab[i].onSlideItemClickCallback(pSlideWindow, index);
            break;
        }
    }
}

bool FilterSettingActivity::onTouchEvent(const MotionEvent &ev) {
    return onFilterSettingActivityTouchEvent(ev);
}

void FilterSettingActivity::onTextChanged(ZKTextView *pTextView, const std::string &text) {
    int tablen = sizeof(SEditTextInputCallbackTab) / sizeof(S_EditTextInputCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SEditTextInputCallbackTab[i].id == pTextView->getID()) {
            SEditTextInputCallbackTab[i].onEditTextChangedCallback(text);
            break;
        }
    }
}

void FilterSettingActivity::rigesterActivityTimer() {
    int tablen = sizeof(REGISTER_ACTIVITY_TIMER_TAB) / sizeof(S_ACTIVITY_TIMEER);
    for (int i = 0; i < tablen; ++i) {
        S_ACTIVITY_TIMEER temp = REGISTER_ACTIVITY_TIMER_TAB[i];
        registerTimer(temp.id, temp.time);
    }
}


void FilterSettingActivity::onVideoPlayerMessage(ZKVideoView *pVideoView, int msg) {
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

void FilterSettingActivity::videoLoopPlayback(ZKVideoView *pVideoView, int msg, size_t callbackTabIndex) {

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

void FilterSettingActivity::startVideoLoopPlayback() {
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

void FilterSettingActivity::stopVideoLoopPlayback() {
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

bool FilterSettingActivity::parseVideoFileList(const char *pFileListPath, std::vector<string>& mediaFileList) {
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

int FilterSettingActivity::removeCharFromString(string& nString, char c) {
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

void FilterSettingActivity::registerUserTimer(int id, int time) {
	registerTimer(id, time);
}

void FilterSettingActivity::unregisterUserTimer(int id) {
	unregisterTimer(id);
}

void FilterSettingActivity::resetUserTimer(int id, int time) {
	resetTimer(id, time);
}