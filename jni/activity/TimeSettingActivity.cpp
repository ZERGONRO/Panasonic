/***********************************************
/gen auto by zuitools
***********************************************/
#include "TimeSettingActivity.h"
#include "util/MachineStatus.h"
#include "util/MyNetWorkingListener.h"


/*TAG:GlobalVariable全局变量*/
static ZKButton* mButton2Ptr;
static ZKListView* mListViewMinuetePtr;
static ZKListView* mListViewHourPtr;
static ZKListView* mListViewDayPtr;
static ZKListView* mListViewMonthPtr;
static ZKListView* mListViewYearPtr;
static ZKListView* mListView1Ptr;
static ZKTextView* mTextViewDescPtr;
static ZKButton* mButtonBackPtr;
static ZKTextView* mTextViewDatesettingPtr;
static ZKTextView* mTextViewDate1Ptr;
static ZKTextView* mTextViewDatePtr;
static ZKWindow* mWindowTimeSettingPtr;
static ZKTextView* mTextView6Ptr;
static TimeSettingActivity* mActivityPtr;


extern MyNetWorkingListener *nwlistener;
/*register activity*/
//REGISTER_ACTIVITY(TimeSettingActivity);
REGISTER_ACTIVITY(TimeSettingActivity);

typedef struct {
	int id; // 定时器ID ， 不能重复
	int time; // 定时器  时间间隔  单位 毫秒
}S_ACTIVITY_TIMEER;

#include "logic/TimeSettingLogic.cc"

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
    ID_TIMESETTING_Button2, onButtonClick_Button2,
    ID_TIMESETTING_ButtonBack, onButtonClick_ButtonBack,
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
    ID_TIMESETTING_ListViewMinuete, getListItemCount_ListViewMinuete, obtainListItemData_ListViewMinuete, onListItemClick_ListViewMinuete,
    ID_TIMESETTING_ListViewHour, getListItemCount_ListViewHour, obtainListItemData_ListViewHour, onListItemClick_ListViewHour,
    ID_TIMESETTING_ListViewDay, getListItemCount_ListViewDay, obtainListItemData_ListViewDay, onListItemClick_ListViewDay,
    ID_TIMESETTING_ListViewMonth, getListItemCount_ListViewMonth, obtainListItemData_ListViewMonth, onListItemClick_ListViewMonth,
    ID_TIMESETTING_ListViewYear, getListItemCount_ListViewYear, obtainListItemData_ListViewYear, onListItemClick_ListViewYear,
//    ID_TIMESETTING_ListView1, getListItemCount_ListView1, obtainListItemData_ListView1, onListItemClick_ListView1,
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


TimeSettingActivity::TimeSettingActivity() {
	//todo add init code here
	mVideoLoopIndex = -1;
	mVideoLoopErrorCount = 0;
}

TimeSettingActivity::~TimeSettingActivity() {
  //todo add init file here
  // 退出应用时需要反注册
    EASYUICONTEXT->unregisterGlobalTouchListener(this);
    onUI_quit();
//    nwlistener->removeNetWorkListener(this);
    unregisterProtocolDataUpdateListener(onProtocolDataUpdate);
    nwlistener->removeNetWorkListener(this);
}

const char* TimeSettingActivity::getAppName() const{
	return "TimeSetting.ftu";
}

//TAG:onCreate
void TimeSettingActivity::onCreate() {
	Activity::onCreate();
    mButton2Ptr = (ZKButton*)findControlByID(ID_TIMESETTING_Button2);
    mListViewMinuetePtr = (ZKListView*)findControlByID(ID_TIMESETTING_ListViewMinuete);if(mListViewMinuetePtr!= NULL){mListViewMinuetePtr->setListAdapter(this);mListViewMinuetePtr->setItemClickListener(this);}
    mListViewHourPtr = (ZKListView*)findControlByID(ID_TIMESETTING_ListViewHour);if(mListViewHourPtr!= NULL){mListViewHourPtr->setListAdapter(this);mListViewHourPtr->setItemClickListener(this);}
    mListViewDayPtr = (ZKListView*)findControlByID(ID_TIMESETTING_ListViewDay);if(mListViewDayPtr!= NULL){mListViewDayPtr->setListAdapter(this);mListViewDayPtr->setItemClickListener(this);}
    mListViewMonthPtr = (ZKListView*)findControlByID(ID_TIMESETTING_ListViewMonth);if(mListViewMonthPtr!= NULL){mListViewMonthPtr->setListAdapter(this);mListViewMonthPtr->setItemClickListener(this);}
    mListViewYearPtr = (ZKListView*)findControlByID(ID_TIMESETTING_ListViewYear);if(mListViewYearPtr!= NULL){mListViewYearPtr->setListAdapter(this);mListViewYearPtr->setItemClickListener(this);}
    mListView1Ptr = (ZKListView*)findControlByID(ID_TIMESETTING_ListView1);if(mListView1Ptr!= NULL){mListView1Ptr->setListAdapter(this);mListView1Ptr->setItemClickListener(this);}
    mTextViewDescPtr = (ZKTextView*)findControlByID(ID_TIMESETTING_TextViewDesc);
    mButtonBackPtr = (ZKButton*)findControlByID(ID_TIMESETTING_ButtonBack);
    mTextViewDatesettingPtr = (ZKTextView*)findControlByID(ID_TIMESETTING_TextViewDatesetting);
    mTextViewDate1Ptr = (ZKTextView*)findControlByID(ID_TIMESETTING_TextViewDate1);
    mTextViewDatePtr = (ZKTextView*)findControlByID(ID_TIMESETTING_TextViewDate);
    mWindowTimeSettingPtr = (ZKWindow*)findControlByID(ID_TIMESETTING_WindowTimeSetting);
    mTextView6Ptr = (ZKTextView*)findControlByID(ID_TIMESETTING_TextView6);
	mActivityPtr = this;
	onUI_init();
	nwlistener->setNetWorkListener(this);
    registerProtocolDataUpdateListener(onProtocolDataUpdate); 
    rigesterActivityTimer();
//    nwlistener->setNetWorkListener(this);
}

void TimeSettingActivity::onClick(ZKBase *pBase) {
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

void TimeSettingActivity::onResume() {
	Activity::onResume();
	EASYUICONTEXT->registerGlobalTouchListener(this);
	startVideoLoopPlayback();
	onUI_show();
}

void TimeSettingActivity::onPause() {
	Activity::onPause();
	EASYUICONTEXT->unregisterGlobalTouchListener(this);
	stopVideoLoopPlayback();
	onUI_hide();
}

void TimeSettingActivity::onIntent(const Intent *intentPtr) {
	Activity::onIntent(intentPtr);
	onUI_intent(intentPtr);
}

bool TimeSettingActivity::onTimer(int id) {
	return onUI_Timer(id);
}

void TimeSettingActivity::onProgressChanged(ZKSeekBar *pSeekBar, int progress){

    int seekBarTablen = sizeof(SZKSeekBarCallbackTab) / sizeof(S_ZKSeekBarCallback);
    for (int i = 0; i < seekBarTablen; ++i) {
        if (SZKSeekBarCallbackTab[i].id == pSeekBar->getID()) {
            SZKSeekBarCallbackTab[i].callback(pSeekBar, progress);
            break;
        }
    }
}

int TimeSettingActivity::getListItemCount(const ZKListView *pListView) const{
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            return SListViewFunctionsCallbackTab[i].getListItemCountCallback(pListView);
            break;
        }
    }
    return 0;
}

void TimeSettingActivity::obtainListItemData(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index){
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            SListViewFunctionsCallbackTab[i].obtainListItemDataCallback(pListView, pListItem, index);
            break;
        }
    }
}

void TimeSettingActivity::onItemClick(ZKListView *pListView, int index, int id){
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            SListViewFunctionsCallbackTab[i].onItemClickCallback(pListView, index, id);
            break;
        }
    }
}

void TimeSettingActivity::onSlideItemClick(ZKSlideWindow *pSlideWindow, int index) {
    int tablen = sizeof(SSlideWindowItemClickCallbackTab) / sizeof(S_SlideWindowItemClickCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SSlideWindowItemClickCallbackTab[i].id == pSlideWindow->getID()) {
            SSlideWindowItemClickCallbackTab[i].onSlideItemClickCallback(pSlideWindow, index);
            break;
        }
    }
}

bool TimeSettingActivity::onTouchEvent(const MotionEvent &ev) {
    return onTimeSettingActivityTouchEvent(ev);
}

void TimeSettingActivity::onTextChanged(ZKTextView *pTextView, const std::string &text) {
    int tablen = sizeof(SEditTextInputCallbackTab) / sizeof(S_EditTextInputCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SEditTextInputCallbackTab[i].id == pTextView->getID()) {
            SEditTextInputCallbackTab[i].onEditTextChangedCallback(text);
            break;
        }
    }
}

void TimeSettingActivity::rigesterActivityTimer() {
    int tablen = sizeof(REGISTER_ACTIVITY_TIMER_TAB) / sizeof(S_ACTIVITY_TIMEER);
    for (int i = 0; i < tablen; ++i) {
        S_ACTIVITY_TIMEER temp = REGISTER_ACTIVITY_TIMER_TAB[i];
        registerTimer(temp.id, temp.time);
    }
}


void TimeSettingActivity::onVideoPlayerMessage(ZKVideoView *pVideoView, int msg) {
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

void TimeSettingActivity::videoLoopPlayback(ZKVideoView *pVideoView, int msg, size_t callbackTabIndex) {

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

void TimeSettingActivity::startVideoLoopPlayback() {
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

void TimeSettingActivity::stopVideoLoopPlayback() {
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

bool TimeSettingActivity::parseVideoFileList(const char *pFileListPath, std::vector<string>& mediaFileList) {
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

int TimeSettingActivity::removeCharFromString(string& nString, char c) {
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

void TimeSettingActivity::MyNetworkNotify(int type , void *data){

}

void TimeSettingActivity::registerUserTimer(int id, int time) {
	registerTimer(id, time);
}

void TimeSettingActivity::unregisterUserTimer(int id) {
	unregisterTimer(id);
}

void TimeSettingActivity::resetUserTimer(int id, int time) {
	resetTimer(id, time);
}