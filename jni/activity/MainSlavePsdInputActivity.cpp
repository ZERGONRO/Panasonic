/***********************************************
/gen auto by zuitools
***********************************************/
#include "MainSlavePsdInputActivity.h"

/*TAG:GlobalVariable全局变量*/
static ZKButton* mButtonComfirmPtr;
static ZKTextView* mTextView2Ptr;
static ZKButton* mButtonNumCancelPtr;
static ZKButton* mButtonNum9Ptr;
static ZKButton* mButtonNum6Ptr;
static ZKButton* mButtonNum0Ptr;
static ZKButton* mButtonNum8Ptr;
static ZKButton* mButtonNum5Ptr;
static ZKButton* mButtonNumDelPtr;
static ZKButton* mButtonNum7Ptr;
static ZKButton* mButtonNum4Ptr;
static ZKButton* mButtonNum3Ptr;
static ZKButton* mButtonNum2Ptr;
static ZKButton* mButtonNum1Ptr;
static ZKButton* mButtonModifyKeyPtr;
static ZKButton* mButtonForgetKeyPtr;
static ZKTextView* mTextViewKey6Ptr;
static ZKTextView* mTextViewKey5Ptr;
static ZKTextView* mTextViewKey4Ptr;
static ZKTextView* mTextViewKey3Ptr;
static ZKTextView* mTextViewKey2Ptr;
static ZKTextView* mTextViewKey1Ptr;
static ZKTextView* mTextView1Ptr;
static ZKWindow* mWindow2Ptr;
static ZKButton* mButton1Ptr;
static ZKWindow* mWindow1Ptr;
static ZKWindow* mWindowBGPtr;

static ZKTextView* mTextViewKeyPtr[6];
static MainSlavePsdInputActivity* mActivityPtr;

/*register activity*/
REGISTER_ACTIVITY(MainSlavePsdInputActivity);

typedef struct {
	int id; // 定时器ID ， 不能重复
	int time; // 定时器  时间间隔  单位 毫秒
}S_ACTIVITY_TIMEER;

#include "logic/MainSlavePsdInputLogic.cc"

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
    ID_MAINSLAVEPSDINPUT_ButtonComfirm, onButtonClick_ButtonComfirm,
    ID_MAINSLAVEPSDINPUT_ButtonNumCancel, onButtonClick_ButtonNumCancel,
    ID_MAINSLAVEPSDINPUT_ButtonNum9, onButtonClick_ButtonNum9,
    ID_MAINSLAVEPSDINPUT_ButtonNum6, onButtonClick_ButtonNum6,
    ID_MAINSLAVEPSDINPUT_ButtonNum0, onButtonClick_ButtonNum0,
    ID_MAINSLAVEPSDINPUT_ButtonNum8, onButtonClick_ButtonNum8,
    ID_MAINSLAVEPSDINPUT_ButtonNum5, onButtonClick_ButtonNum5,
    ID_MAINSLAVEPSDINPUT_ButtonNumDel, onButtonClick_ButtonNumDel,
    ID_MAINSLAVEPSDINPUT_ButtonNum7, onButtonClick_ButtonNum7,
    ID_MAINSLAVEPSDINPUT_ButtonNum4, onButtonClick_ButtonNum4,
    ID_MAINSLAVEPSDINPUT_ButtonNum3, onButtonClick_ButtonNum3,
    ID_MAINSLAVEPSDINPUT_ButtonNum2, onButtonClick_ButtonNum2,
    ID_MAINSLAVEPSDINPUT_ButtonNum1, onButtonClick_ButtonNum1,
    ID_MAINSLAVEPSDINPUT_ButtonModifyKey, onButtonClick_ButtonModifyKey,
    ID_MAINSLAVEPSDINPUT_ButtonForgetKey, onButtonClick_ButtonForgetKey,
    ID_MAINSLAVEPSDINPUT_Button1, onButtonClick_Button1,
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


MainSlavePsdInputActivity::MainSlavePsdInputActivity() {
	//todo add init code here
	mVideoLoopIndex = -1;
	mVideoLoopErrorCount = 0;
}

MainSlavePsdInputActivity::~MainSlavePsdInputActivity() {
  //todo add init file here
  // 退出应用时需要反注册
    EASYUICONTEXT->unregisterGlobalTouchListener(this);
    onUI_quit();
    unregisterProtocolDataUpdateListener(onProtocolDataUpdate);
}

const char* MainSlavePsdInputActivity::getAppName() const{
	return "MainSlavePsdInput.ftu";
}

//TAG:onCreate
void MainSlavePsdInputActivity::onCreate() {
	Activity::onCreate();
    mButtonComfirmPtr = (ZKButton*)findControlByID(ID_MAINSLAVEPSDINPUT_ButtonComfirm);
    mTextView2Ptr = (ZKTextView*)findControlByID(ID_MAINSLAVEPSDINPUT_TextView2);
    mButtonNumCancelPtr = (ZKButton*)findControlByID(ID_MAINSLAVEPSDINPUT_ButtonNumCancel);
    mButtonNum9Ptr = (ZKButton*)findControlByID(ID_MAINSLAVEPSDINPUT_ButtonNum9);
    mButtonNum6Ptr = (ZKButton*)findControlByID(ID_MAINSLAVEPSDINPUT_ButtonNum6);
    mButtonNum0Ptr = (ZKButton*)findControlByID(ID_MAINSLAVEPSDINPUT_ButtonNum0);
    mButtonNum8Ptr = (ZKButton*)findControlByID(ID_MAINSLAVEPSDINPUT_ButtonNum8);
    mButtonNum5Ptr = (ZKButton*)findControlByID(ID_MAINSLAVEPSDINPUT_ButtonNum5);
    mButtonNumDelPtr = (ZKButton*)findControlByID(ID_MAINSLAVEPSDINPUT_ButtonNumDel);
    mButtonNum7Ptr = (ZKButton*)findControlByID(ID_MAINSLAVEPSDINPUT_ButtonNum7);
    mButtonNum4Ptr = (ZKButton*)findControlByID(ID_MAINSLAVEPSDINPUT_ButtonNum4);
    mButtonNum3Ptr = (ZKButton*)findControlByID(ID_MAINSLAVEPSDINPUT_ButtonNum3);
    mButtonNum2Ptr = (ZKButton*)findControlByID(ID_MAINSLAVEPSDINPUT_ButtonNum2);
    mButtonNum1Ptr = (ZKButton*)findControlByID(ID_MAINSLAVEPSDINPUT_ButtonNum1);
    mButtonModifyKeyPtr = (ZKButton*)findControlByID(ID_MAINSLAVEPSDINPUT_ButtonModifyKey);
    mButtonForgetKeyPtr = (ZKButton*)findControlByID(ID_MAINSLAVEPSDINPUT_ButtonForgetKey);
    mTextViewKey6Ptr = (ZKTextView*)findControlByID(ID_MAINSLAVEPSDINPUT_TextViewKey6);
    mTextViewKey5Ptr = (ZKTextView*)findControlByID(ID_MAINSLAVEPSDINPUT_TextViewKey5);
    mTextViewKey4Ptr = (ZKTextView*)findControlByID(ID_MAINSLAVEPSDINPUT_TextViewKey4);
    mTextViewKey3Ptr = (ZKTextView*)findControlByID(ID_MAINSLAVEPSDINPUT_TextViewKey3);
    mTextViewKey2Ptr = (ZKTextView*)findControlByID(ID_MAINSLAVEPSDINPUT_TextViewKey2);
    mTextViewKey1Ptr = (ZKTextView*)findControlByID(ID_MAINSLAVEPSDINPUT_TextViewKey1);
    mTextView1Ptr = (ZKTextView*)findControlByID(ID_MAINSLAVEPSDINPUT_TextView1);
    mWindow2Ptr = (ZKWindow*)findControlByID(ID_MAINSLAVEPSDINPUT_Window2);
    mButton1Ptr = (ZKButton*)findControlByID(ID_MAINSLAVEPSDINPUT_Button1);
    mWindow1Ptr = (ZKWindow*)findControlByID(ID_MAINSLAVEPSDINPUT_Window1);
    mWindowBGPtr = (ZKWindow*)findControlByID(ID_MAINSLAVEPSDINPUT_WindowBG);

    mTextViewKeyPtr[0] = mTextViewKey1Ptr;
    mTextViewKeyPtr[1] = mTextViewKey2Ptr;
    mTextViewKeyPtr[2] = mTextViewKey3Ptr;
    mTextViewKeyPtr[3] = mTextViewKey4Ptr;
    mTextViewKeyPtr[4] = mTextViewKey5Ptr;
    mTextViewKeyPtr[5] = mTextViewKey6Ptr;
	mActivityPtr = this;
	onUI_init();
    registerProtocolDataUpdateListener(onProtocolDataUpdate); 
    rigesterActivityTimer();
}

void MainSlavePsdInputActivity::onClick(ZKBase *pBase) {
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

void MainSlavePsdInputActivity::onResume() {
	Activity::onResume();
	EASYUICONTEXT->registerGlobalTouchListener(this);
	startVideoLoopPlayback();
	onUI_show();
}

void MainSlavePsdInputActivity::onPause() {
	Activity::onPause();
	EASYUICONTEXT->unregisterGlobalTouchListener(this);
	stopVideoLoopPlayback();
	onUI_hide();
}

void MainSlavePsdInputActivity::onIntent(const Intent *intentPtr) {
	Activity::onIntent(intentPtr);
	onUI_intent(intentPtr);
}

bool MainSlavePsdInputActivity::onTimer(int id) {
	return onUI_Timer(id);
}

void MainSlavePsdInputActivity::onProgressChanged(ZKSeekBar *pSeekBar, int progress){

    int seekBarTablen = sizeof(SZKSeekBarCallbackTab) / sizeof(S_ZKSeekBarCallback);
    for (int i = 0; i < seekBarTablen; ++i) {
        if (SZKSeekBarCallbackTab[i].id == pSeekBar->getID()) {
            SZKSeekBarCallbackTab[i].callback(pSeekBar, progress);
            break;
        }
    }
}

int MainSlavePsdInputActivity::getListItemCount(const ZKListView *pListView) const{
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            return SListViewFunctionsCallbackTab[i].getListItemCountCallback(pListView);
            break;
        }
    }
    return 0;
}

void MainSlavePsdInputActivity::obtainListItemData(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index){
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            SListViewFunctionsCallbackTab[i].obtainListItemDataCallback(pListView, pListItem, index);
            break;
        }
    }
}

void MainSlavePsdInputActivity::onItemClick(ZKListView *pListView, int index, int id){
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            SListViewFunctionsCallbackTab[i].onItemClickCallback(pListView, index, id);
            break;
        }
    }
}

void MainSlavePsdInputActivity::onSlideItemClick(ZKSlideWindow *pSlideWindow, int index) {
    int tablen = sizeof(SSlideWindowItemClickCallbackTab) / sizeof(S_SlideWindowItemClickCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SSlideWindowItemClickCallbackTab[i].id == pSlideWindow->getID()) {
            SSlideWindowItemClickCallbackTab[i].onSlideItemClickCallback(pSlideWindow, index);
            break;
        }
    }
}

bool MainSlavePsdInputActivity::onTouchEvent(const MotionEvent &ev) {
    return onMainSlavePsdInputActivityTouchEvent(ev);
}

void MainSlavePsdInputActivity::onTextChanged(ZKTextView *pTextView, const std::string &text) {
    int tablen = sizeof(SEditTextInputCallbackTab) / sizeof(S_EditTextInputCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SEditTextInputCallbackTab[i].id == pTextView->getID()) {
            SEditTextInputCallbackTab[i].onEditTextChangedCallback(text);
            break;
        }
    }
}

void MainSlavePsdInputActivity::rigesterActivityTimer() {
    int tablen = sizeof(REGISTER_ACTIVITY_TIMER_TAB) / sizeof(S_ACTIVITY_TIMEER);
    for (int i = 0; i < tablen; ++i) {
        S_ACTIVITY_TIMEER temp = REGISTER_ACTIVITY_TIMER_TAB[i];
        registerTimer(temp.id, temp.time);
    }
}


void MainSlavePsdInputActivity::onVideoPlayerMessage(ZKVideoView *pVideoView, int msg) {
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

void MainSlavePsdInputActivity::videoLoopPlayback(ZKVideoView *pVideoView, int msg, size_t callbackTabIndex) {

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

void MainSlavePsdInputActivity::startVideoLoopPlayback() {
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

void MainSlavePsdInputActivity::stopVideoLoopPlayback() {
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

bool MainSlavePsdInputActivity::parseVideoFileList(const char *pFileListPath, std::vector<string>& mediaFileList) {
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

int MainSlavePsdInputActivity::removeCharFromString(string& nString, char c) {
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

void MainSlavePsdInputActivity::registerUserTimer(int id, int time) {
	registerTimer(id, time);
}

void MainSlavePsdInputActivity::unregisterUserTimer(int id) {
	unregisterTimer(id);
}

void MainSlavePsdInputActivity::resetUserTimer(int id, int time) {
	resetTimer(id, time);
}