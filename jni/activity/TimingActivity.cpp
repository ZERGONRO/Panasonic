/***********************************************
/gen auto by zuitools
***********************************************/
#include "TimingActivity.h"

/*TAG:GlobalVariable全局变量*/
static ZKTextView* mTextView83Ptr;
static ZKTextView* mTextView82Ptr;
static ZKTextView* mTextView74Ptr;
static ZKButton* mButtonReturnPtr;
static ZKWindow* mWindowSettingTimeErrorPtr;
static ZKTextView* mTextViewPic2Ptr;
static ZKTextView* mTextViewPic1Ptr;
static ZKTextView* mTextViewNoTimingPtr;
static ZKButton* mButtonBackPtr;
static ZKTextView* mTextView80Ptr;
static ZKTextView* mTextView79Ptr;
static ZKTextView* mTextView78Ptr;
static ZKTextView* mTextView77Ptr;
static ZKTextView* mTextView76Ptr;
static ZKTextView* mTextView75Ptr;
static ZKTextView* mTextViewParalPtr;
static ZKTextView* mTextViewVerPtr;
static ZKWindow* mWindowTimeWavePtr;
static ZKWindow* mWindowHumTime2Ptr;
static ZKWindow* mWindowHumTime1Ptr;
static ZKWindow* mWindowWindTime2Ptr;
static ZKWindow* mWindowWindTime1Ptr;
static ZKWindow* mWindowAirHum2Ptr;
static ZKWindow* mWindowAirHum1Ptr;
static ZKWindow* mWindowTimePtr;
static ZKWindow* mWindowTOPPtr;
static ZKWindow* mWindowBGPtr;
static ZKTextView* mTextViewWifiPtr;
static ZKButton* mButtonDropDownPtr;
static ZKTextView* mTextView73Ptr;
static ZKTextView* mTextView72Ptr;
static ZKTextView* mTextView71Ptr;
static ZKTextView* mTextView70Ptr;
static ZKTextView* mTextView69Ptr;
static ZKTextView* mTextView68Ptr;
static ZKTextView* mTextView67Ptr;
static ZKTextView* mTextView66Ptr;
static ZKTextView* mTextView65Ptr;
static ZKTextView* mTextView64Ptr;
static ZKTextView* mTextView63Ptr;
static ZKTextView* mTextView62Ptr;
static ZKTextView* mTextView61Ptr;
static ZKTextView* mTextView60Ptr;
static ZKTextView* mTextView59Ptr;
static ZKTextView* mTextView58Ptr;
static ZKTextView* mTextView57Ptr;
static ZKTextView* mTextView56Ptr;
static ZKTextView* mTextView55Ptr;
static ZKTextView* mTextView54Ptr;
static ZKTextView* mTextView53Ptr;
static ZKTextView* mTextView52Ptr;
static ZKTextView* mTextView51Ptr;
static ZKTextView* mTextView50Ptr;
static ZKTextView* mTextView49Ptr;
static ZKTextView* mTextView48Ptr;
static ZKTextView* mTextView47Ptr;
static ZKTextView* mTextView46Ptr;
static ZKTextView* mTextView45Ptr;
static ZKTextView* mTextView44Ptr;
static ZKTextView* mTextView43Ptr;
static ZKTextView* mTextView42Ptr;
static ZKTextView* mTextView41Ptr;
static ZKTextView* mTextView40Ptr;
static ZKTextView* mTextView39Ptr;
static ZKTextView* mTextView38Ptr;
static ZKTextView* mTextView37Ptr;
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
static ZKTextView* mTextView24Ptr;
static ZKTextView* mTextView23Ptr;
static ZKTextView* mTextView22Ptr;
static ZKTextView* mTextView21Ptr;
static ZKTextView* mTextView20Ptr;
static ZKTextView* mTextView19Ptr;
static ZKTextView* mTextView18Ptr;
static ZKTextView* mTextView17Ptr;
static ZKTextView* mTextView16Ptr;
static ZKTextView* mTextView15Ptr;
static ZKTextView* mTextView14Ptr;
static ZKTextView* mTextView13Ptr;
static ZKTextView* mTextView12Ptr;
static ZKTextView* mTextView11Ptr;
static ZKTextView* mTextView10Ptr;
static ZKTextView* mTextView9Ptr;
static ZKTextView* mTextView8Ptr;
static ZKTextView* mTextView7Ptr;
static ZKTextView* mTextView6Ptr;
static ZKTextView* mTextView5Ptr;
static ZKTextView* mTextView4Ptr;
static ZKTextView* mTextView3Ptr;
static ZKTextView* mTextView2Ptr;
static ZKWindow* mWindow3Ptr;
static ZKButton* mButton6Ptr;
static ZKButton* mButton2Ptr;
static ZKTextView* mTextView1Ptr;
static TimingActivity* mActivityPtr;

/*register activity*/
REGISTER_ACTIVITY(TimingActivity);

typedef struct {
	int id; // 定时器ID ， 不能重复
	int time; // 定时器  时间间隔  单位 毫秒
}S_ACTIVITY_TIMEER;

#include "logic/TimingLogic.cc"

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
    ID_TIMING_ButtonReturn, onButtonClick_ButtonReturn,
    ID_TIMING_ButtonBack, onButtonClick_ButtonBack,
    ID_TIMING_ButtonDropDown, onButtonClick_ButtonDropDown,
    ID_TIMING_Button6, onButtonClick_Button6,
    ID_TIMING_Button2, onButtonClick_Button2,
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


TimingActivity::TimingActivity() {
	//todo add init code here
	mVideoLoopIndex = -1;
	mVideoLoopErrorCount = 0;
}

TimingActivity::~TimingActivity() {
  //todo add init file here
  // 退出应用时需要反注册
    EASYUICONTEXT->unregisterGlobalTouchListener(this);
    onUI_quit();
    unregisterProtocolDataUpdateListener(onProtocolDataUpdate);
}

const char* TimingActivity::getAppName() const{
	return "Timing.ftu";
}

//TAG:onCreate
void TimingActivity::onCreate() {
	Activity::onCreate();
    mTextView83Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView83);
    mTextView82Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView82);
    mTextView74Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView74);
    mButtonReturnPtr = (ZKButton*)findControlByID(ID_TIMING_ButtonReturn);
    mWindowSettingTimeErrorPtr = (ZKWindow*)findControlByID(ID_TIMING_WindowSettingTimeError);
    mTextViewPic2Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextViewPic2);
    mTextViewPic1Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextViewPic1);
    mTextViewNoTimingPtr = (ZKTextView*)findControlByID(ID_TIMING_TextViewNoTiming);
    mButtonBackPtr = (ZKButton*)findControlByID(ID_TIMING_ButtonBack);
    mTextView80Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView80);
    mTextView79Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView79);
    mTextView78Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView78);
    mTextView77Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView77);
    mTextView76Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView76);
    mTextView75Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView75);
    mTextViewParalPtr = (ZKTextView*)findControlByID(ID_TIMING_TextViewParal);
    mTextViewVerPtr = (ZKTextView*)findControlByID(ID_TIMING_TextViewVer);
    mWindowTimeWavePtr = (ZKWindow*)findControlByID(ID_TIMING_WindowTimeWave);
    mWindowHumTime2Ptr = (ZKWindow*)findControlByID(ID_TIMING_WindowHumTime2);
    mWindowHumTime1Ptr = (ZKWindow*)findControlByID(ID_TIMING_WindowHumTime1);
    mWindowWindTime2Ptr = (ZKWindow*)findControlByID(ID_TIMING_WindowWindTime2);
    mWindowWindTime1Ptr = (ZKWindow*)findControlByID(ID_TIMING_WindowWindTime1);
    mWindowAirHum2Ptr = (ZKWindow*)findControlByID(ID_TIMING_WindowAirHum2);
    mWindowAirHum1Ptr = (ZKWindow*)findControlByID(ID_TIMING_WindowAirHum1);
    mWindowTimePtr = (ZKWindow*)findControlByID(ID_TIMING_WindowTime);
    mWindowTOPPtr = (ZKWindow*)findControlByID(ID_TIMING_WindowTOP);
    mWindowBGPtr = (ZKWindow*)findControlByID(ID_TIMING_WindowBG);
    mTextViewWifiPtr = (ZKTextView*)findControlByID(ID_TIMING_TextViewWifi);
    mButtonDropDownPtr = (ZKButton*)findControlByID(ID_TIMING_ButtonDropDown);
    mTextView73Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView73);
    mTextView72Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView72);
    mTextView71Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView71);
    mTextView70Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView70);
    mTextView69Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView69);
    mTextView68Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView68);
    mTextView67Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView67);
    mTextView66Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView66);
    mTextView65Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView65);
    mTextView64Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView64);
    mTextView63Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView63);
    mTextView62Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView62);
    mTextView61Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView61);
    mTextView60Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView60);
    mTextView59Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView59);
    mTextView58Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView58);
    mTextView57Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView57);
    mTextView56Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView56);
    mTextView55Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView55);
    mTextView54Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView54);
    mTextView53Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView53);
    mTextView52Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView52);
    mTextView51Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView51);
    mTextView50Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView50);
    mTextView49Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView49);
    mTextView48Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView48);
    mTextView47Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView47);
    mTextView46Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView46);
    mTextView45Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView45);
    mTextView44Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView44);
    mTextView43Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView43);
    mTextView42Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView42);
    mTextView41Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView41);
    mTextView40Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView40);
    mTextView39Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView39);
    mTextView38Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView38);
    mTextView37Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView37);
    mTextView36Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView36);
    mTextView35Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView35);
    mTextView34Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView34);
    mTextView33Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView33);
    mTextView32Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView32);
    mTextView31Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView31);
    mTextView30Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView30);
    mTextView29Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView29);
    mTextView28Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView28);
    mTextView27Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView27);
    mTextView26Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView26);
    mTextView25Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView25);
    mTextView24Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView24);
    mTextView23Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView23);
    mTextView22Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView22);
    mTextView21Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView21);
    mTextView20Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView20);
    mTextView19Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView19);
    mTextView18Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView18);
    mTextView17Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView17);
    mTextView16Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView16);
    mTextView15Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView15);
    mTextView14Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView14);
    mTextView13Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView13);
    mTextView12Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView12);
    mTextView11Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView11);
    mTextView10Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView10);
    mTextView9Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView9);
    mTextView8Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView8);
    mTextView7Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView7);
    mTextView6Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView6);
    mTextView5Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView5);
    mTextView4Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView4);
    mTextView3Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView3);
    mTextView2Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView2);
    mWindow3Ptr = (ZKWindow*)findControlByID(ID_TIMING_Window3);
    mButton6Ptr = (ZKButton*)findControlByID(ID_TIMING_Button6);
    mButton2Ptr = (ZKButton*)findControlByID(ID_TIMING_Button2);
    mTextView1Ptr = (ZKTextView*)findControlByID(ID_TIMING_TextView1);
	mActivityPtr = this;
	onUI_init();
    registerProtocolDataUpdateListener(onProtocolDataUpdate); 
    rigesterActivityTimer();
}

void TimingActivity::onClick(ZKBase *pBase) {
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

void TimingActivity::onResume() {
	Activity::onResume();
	EASYUICONTEXT->registerGlobalTouchListener(this);
	startVideoLoopPlayback();
	onUI_show();
}

void TimingActivity::onPause() {
	Activity::onPause();
	EASYUICONTEXT->unregisterGlobalTouchListener(this);
	stopVideoLoopPlayback();
	onUI_hide();
}

void TimingActivity::onIntent(const Intent *intentPtr) {
	Activity::onIntent(intentPtr);
	onUI_intent(intentPtr);
}

bool TimingActivity::onTimer(int id) {
	return onUI_Timer(id);
}

void TimingActivity::onProgressChanged(ZKSeekBar *pSeekBar, int progress){

    int seekBarTablen = sizeof(SZKSeekBarCallbackTab) / sizeof(S_ZKSeekBarCallback);
    for (int i = 0; i < seekBarTablen; ++i) {
        if (SZKSeekBarCallbackTab[i].id == pSeekBar->getID()) {
            SZKSeekBarCallbackTab[i].callback(pSeekBar, progress);
            break;
        }
    }
}

int TimingActivity::getListItemCount(const ZKListView *pListView) const{
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            return SListViewFunctionsCallbackTab[i].getListItemCountCallback(pListView);
            break;
        }
    }
    return 0;
}

void TimingActivity::obtainListItemData(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index){
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            SListViewFunctionsCallbackTab[i].obtainListItemDataCallback(pListView, pListItem, index);
            break;
        }
    }
}

void TimingActivity::onItemClick(ZKListView *pListView, int index, int id){
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            SListViewFunctionsCallbackTab[i].onItemClickCallback(pListView, index, id);
            break;
        }
    }
}

void TimingActivity::onSlideItemClick(ZKSlideWindow *pSlideWindow, int index) {
    int tablen = sizeof(SSlideWindowItemClickCallbackTab) / sizeof(S_SlideWindowItemClickCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SSlideWindowItemClickCallbackTab[i].id == pSlideWindow->getID()) {
            SSlideWindowItemClickCallbackTab[i].onSlideItemClickCallback(pSlideWindow, index);
            break;
        }
    }
}

bool TimingActivity::onTouchEvent(const MotionEvent &ev) {
    return onTimingActivityTouchEvent(ev);
}

void TimingActivity::onTextChanged(ZKTextView *pTextView, const std::string &text) {
    int tablen = sizeof(SEditTextInputCallbackTab) / sizeof(S_EditTextInputCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SEditTextInputCallbackTab[i].id == pTextView->getID()) {
            SEditTextInputCallbackTab[i].onEditTextChangedCallback(text);
            break;
        }
    }
}

void TimingActivity::rigesterActivityTimer() {
    int tablen = sizeof(REGISTER_ACTIVITY_TIMER_TAB) / sizeof(S_ACTIVITY_TIMEER);
    for (int i = 0; i < tablen; ++i) {
        S_ACTIVITY_TIMEER temp = REGISTER_ACTIVITY_TIMER_TAB[i];
        registerTimer(temp.id, temp.time);
    }
}


void TimingActivity::onVideoPlayerMessage(ZKVideoView *pVideoView, int msg) {
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

void TimingActivity::videoLoopPlayback(ZKVideoView *pVideoView, int msg, size_t callbackTabIndex) {

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

void TimingActivity::startVideoLoopPlayback() {
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

void TimingActivity::stopVideoLoopPlayback() {
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

bool TimingActivity::parseVideoFileList(const char *pFileListPath, std::vector<string>& mediaFileList) {
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

int TimingActivity::removeCharFromString(string& nString, char c) {
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

void TimingActivity::registerUserTimer(int id, int time) {
	registerTimer(id, time);
}

void TimingActivity::unregisterUserTimer(int id) {
	unregisterTimer(id);
}

void TimingActivity::resetUserTimer(int id, int time) {
	resetTimer(id, time);
}