/***********************************************
/gen auto by zuitools
***********************************************/
#include "EnvSettingActivity.h"
#include "app/SysAppFactory.h"
/*TAG:GlobalVariable全局变量*/
static ZKEditText* mEditText2Ptr;
static ZKEditText* mEditText1Ptr;
static ZKTextView* mTextViewPic1Ptr;
static ZKTextView* mTextViewPicShowPtr;
static ZKListView* mListView3Ptr;
static ZKButton* mButtonInputPtr;
static ZKButton* mButtonDelete1Ptr;
static ZKListView* mListView1Ptr;
static ZKButton* mButtonBack2Ptr;
static ZKTextView* mTextView15Ptr;
static ZKTextView* mTextView14Ptr;
static ZKWindow* mWindow5Ptr;
static ZKWindow* mWindow4Ptr;
static ZKButton* mButtonBack1Ptr;
static ZKTextView* mTextView13Ptr;
static ZKTextView* mTextView12Ptr;
static ZKTextView* mTextView11Ptr;
static ZKWindow* mWindowKitchenPtr;
static ZKTextView* mTextView10Ptr;
static ZKTextView* mTextView9Ptr;
static ZKTextView* mTextView8Ptr;
static ZKWindow* mWindowBigMachinePtr;
static ZKTextView* mTextView7Ptr;
static ZKTextView* mTextView6Ptr;
static ZKTextView* mTextView5Ptr;
static ZKWindow* mWindowSmallMachinePtr;
static ZKWindow* mWindowAllPtr;
static ZKRadioGroup* mRadioGroup1Ptr;
static ZKWindow* mWindow3Ptr;
static ZKTextView* mTextView2Ptr;
static ZKWindow* mWindow2Ptr;
static ZKWindow* mWindow1Ptr;
static ZKButton* mButton10Ptr;
static ZKListView* mListView2Ptr;
static ZKButton* mButtonBackPtr;
static ZKTextView* mTextView45Ptr;
static ZKTextView* mTextView44Ptr;
static ZKWindow* mWindow15Ptr;
static ZKWindow* mWindow12Ptr;
static ZKButton* mButton9Ptr;
static ZKWindow* mWindow14Ptr;
static ZKWindow* mWindowEnvBGDispPtr;
static EnvSettingActivity* mActivityPtr;



char texttmp[16];

enum {
	AllMachine,
	LifeSmallMachine,
	BigMachine,
	KitcheenMachine,
	HomeMachine
}DeviceList_t;



/*register activity*/
REGISTER_ACTIVITY(EnvSettingActivity);

typedef struct {
	int id; // 定时器ID ， 不能重复
	int time; // 定时器  时间间隔  单位 毫秒
}S_ACTIVITY_TIMEER;

#include "logic/EnvSettingLogic.cc"

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
    ID_ENVSETTING_ButtonInput, onButtonClick_ButtonInput,
    ID_ENVSETTING_ButtonDelete1, onButtonClick_ButtonDelete1,
    ID_ENVSETTING_ButtonBack2, onButtonClick_ButtonBack2,
    ID_ENVSETTING_ButtonBack1, onButtonClick_ButtonBack1,
    ID_ENVSETTING_Button10, onButtonClick_Button10,
    ID_ENVSETTING_ButtonBack, onButtonClick_ButtonBack,
    ID_ENVSETTING_Button9, onButtonClick_Button9,
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
typedef void (*ListViewonItemClickCallback)(ZKListView *pListView,  int index, int id);
typedef struct {
    int id;
    ListViewGetItemCountCallback getListItemCountCallback;
    ListViewobtainListItemDataCallback obtainListItemDataCallback;
    ListViewonItemClickCallback onItemClickCallback;
}S_ListViewFunctionsCallback;
/*TAG:ListViewFunctionsCallback*/
static S_ListViewFunctionsCallback SListViewFunctionsCallbackTab[] = {
    ID_ENVSETTING_ListView3, getListItemCount_ListView3, obtainListItemData_ListView3, onListItemClick_ListView3,
    ID_ENVSETTING_ListView1, getListItemCount_ListView1, obtainListItemData_ListView1, onListItemClick_ListView1,
    ID_ENVSETTING_ListView2, getListItemCount_ListView2, obtainListItemData_ListView2, onListItemClick_ListView2,
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
    ID_ENVSETTING_EditText2, onEditTextChanged_EditText2,
    ID_ENVSETTING_EditText1, onEditTextChanged_EditText1,
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


typedef void (*RadioGroupCallback)(ZKRadioGroup*, int);
typedef struct {
  int id;
  RadioGroupCallback onCheckedChanged;
}S_RadioGroupCallback;
/*TAG:RadioGroupCallbackTab*/
static S_RadioGroupCallback SRadioGroupCallbackTab[] = {
    ID_ENVSETTING_RadioGroup1, onCheckedChanged_RadioGroup1,
};

EnvSettingActivity::EnvSettingActivity() {
	//todo add init code here
	mVideoLoopIndex = -1;
	mVideoLoopErrorCount = 0;
}

EnvSettingActivity::~EnvSettingActivity() {
  //todo add init file here
  // 退出应用时需要反注册
    EASYUICONTEXT->unregisterGlobalTouchListener(this);
    onUI_quit();
    unregisterProtocolDataUpdateListener(onProtocolDataUpdate);
}

EnvSettingActivity* EnvSettingActivity::getInstance(){
	static EnvSettingActivity sES;
	return &sES;
}

const char* EnvSettingActivity::getAppName() const{
	return "EnvSetting.ftu";
}

//TAG:onCreate
void EnvSettingActivity::onCreate() {
	Activity::onCreate();
    mEditText2Ptr = (ZKEditText*)findControlByID(ID_ENVSETTING_EditText2);if(mEditText2Ptr!= NULL){mEditText2Ptr->setTextChangeListener(this);}
    mEditText1Ptr = (ZKEditText*)findControlByID(ID_ENVSETTING_EditText1);if(mEditText1Ptr!= NULL){mEditText1Ptr->setTextChangeListener(this);}
    mTextViewPic1Ptr = (ZKTextView*)findControlByID(ID_ENVSETTING_TextViewPic1);
    mTextViewPicShowPtr = (ZKTextView*)findControlByID(ID_ENVSETTING_TextViewPicShow);
    mListView3Ptr = (ZKListView*)findControlByID(ID_ENVSETTING_ListView3);if(mListView3Ptr!= NULL){mListView3Ptr->setListAdapter(this);mListView3Ptr->setItemClickListener(this);}
    mButtonInputPtr = (ZKButton*)findControlByID(ID_ENVSETTING_ButtonInput);
    mButtonDelete1Ptr = (ZKButton*)findControlByID(ID_ENVSETTING_ButtonDelete1);
    mListView1Ptr = (ZKListView*)findControlByID(ID_ENVSETTING_ListView1);if(mListView1Ptr!= NULL){mListView1Ptr->setListAdapter(this);mListView1Ptr->setItemClickListener(this);}
    mButtonBack2Ptr = (ZKButton*)findControlByID(ID_ENVSETTING_ButtonBack2);
    mTextView15Ptr = (ZKTextView*)findControlByID(ID_ENVSETTING_TextView15);
    mTextView14Ptr = (ZKTextView*)findControlByID(ID_ENVSETTING_TextView14);
    mWindow5Ptr = (ZKWindow*)findControlByID(ID_ENVSETTING_Window5);
    mWindow4Ptr = (ZKWindow*)findControlByID(ID_ENVSETTING_Window4);
    mButtonBack1Ptr = (ZKButton*)findControlByID(ID_ENVSETTING_ButtonBack1);
    mTextView13Ptr = (ZKTextView*)findControlByID(ID_ENVSETTING_TextView13);
    mTextView12Ptr = (ZKTextView*)findControlByID(ID_ENVSETTING_TextView12);
    mTextView11Ptr = (ZKTextView*)findControlByID(ID_ENVSETTING_TextView11);
    mWindowKitchenPtr = (ZKWindow*)findControlByID(ID_ENVSETTING_WindowKitchen);
    mTextView10Ptr = (ZKTextView*)findControlByID(ID_ENVSETTING_TextView10);
    mTextView9Ptr = (ZKTextView*)findControlByID(ID_ENVSETTING_TextView9);
    mTextView8Ptr = (ZKTextView*)findControlByID(ID_ENVSETTING_TextView8);
    mWindowBigMachinePtr = (ZKWindow*)findControlByID(ID_ENVSETTING_WindowBigMachine);
    mTextView7Ptr = (ZKTextView*)findControlByID(ID_ENVSETTING_TextView7);
    mTextView6Ptr = (ZKTextView*)findControlByID(ID_ENVSETTING_TextView6);
    mTextView5Ptr = (ZKTextView*)findControlByID(ID_ENVSETTING_TextView5);
    mWindowSmallMachinePtr = (ZKWindow*)findControlByID(ID_ENVSETTING_WindowSmallMachine);
    mWindowAllPtr = (ZKWindow*)findControlByID(ID_ENVSETTING_WindowAll);
    mRadioGroup1Ptr = (ZKRadioGroup*)findControlByID(ID_ENVSETTING_RadioGroup1);if(mRadioGroup1Ptr!= NULL){mRadioGroup1Ptr->setCheckedChangeListener(this);}
    mWindow3Ptr = (ZKWindow*)findControlByID(ID_ENVSETTING_Window3);
    mTextView2Ptr = (ZKTextView*)findControlByID(ID_ENVSETTING_TextView2);
    mWindow2Ptr = (ZKWindow*)findControlByID(ID_ENVSETTING_Window2);
    mWindow1Ptr = (ZKWindow*)findControlByID(ID_ENVSETTING_Window1);
    mButton10Ptr = (ZKButton*)findControlByID(ID_ENVSETTING_Button10);
    mListView2Ptr = (ZKListView*)findControlByID(ID_ENVSETTING_ListView2);if(mListView2Ptr!= NULL){mListView2Ptr->setListAdapter(this);mListView2Ptr->setItemClickListener(this);}
    mButtonBackPtr = (ZKButton*)findControlByID(ID_ENVSETTING_ButtonBack);
    mTextView45Ptr = (ZKTextView*)findControlByID(ID_ENVSETTING_TextView45);
    mTextView44Ptr = (ZKTextView*)findControlByID(ID_ENVSETTING_TextView44);
    mWindow15Ptr = (ZKWindow*)findControlByID(ID_ENVSETTING_Window15);
    mWindow12Ptr = (ZKWindow*)findControlByID(ID_ENVSETTING_Window12);
    mButton9Ptr = (ZKButton*)findControlByID(ID_ENVSETTING_Button9);
    mWindow14Ptr = (ZKWindow*)findControlByID(ID_ENVSETTING_Window14);
    mWindowEnvBGDispPtr = (ZKWindow*)findControlByID(ID_ENVSETTING_WindowEnvBGDisp);
	mActivityPtr = this;
	onUI_init();
    registerProtocolDataUpdateListener(onProtocolDataUpdate); 
    rigesterActivityTimer();
}

void EnvSettingActivity::onClick(ZKBase *pBase) {
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

void EnvSettingActivity::onResume() {
	Activity::onResume();
	EASYUICONTEXT->registerGlobalTouchListener(this);
	startVideoLoopPlayback();
	onUI_show();
}

void EnvSettingActivity::onPause() {
	Activity::onPause();
	EASYUICONTEXT->unregisterGlobalTouchListener(this);
	stopVideoLoopPlayback();
	onUI_hide();
}

void EnvSettingActivity::onIntent(const Intent *intentPtr) {
	Activity::onIntent(intentPtr);
	onUI_intent(intentPtr);
}

bool EnvSettingActivity::onTimer(int id) {
	return onUI_Timer(id);
}

void EnvSettingActivity::onProgressChanged(ZKSeekBar *pSeekBar, int progress){

    int seekBarTablen = sizeof(SZKSeekBarCallbackTab) / sizeof(S_ZKSeekBarCallback);
    for (int i = 0; i < seekBarTablen; ++i) {
        if (SZKSeekBarCallbackTab[i].id == pSeekBar->getID()) {
            SZKSeekBarCallbackTab[i].callback(pSeekBar, progress);
            break;
        }
    }
}

int EnvSettingActivity::getListItemCount(const ZKListView *pListView) const{
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            return SListViewFunctionsCallbackTab[i].getListItemCountCallback(pListView);
            break;
        }
    }
    return 0;
}

void EnvSettingActivity::obtainListItemData(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index){
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            SListViewFunctionsCallbackTab[i].obtainListItemDataCallback(pListView, pListItem, index);
            break;
        }
    }
}

void EnvSettingActivity::onItemClick(ZKListView *pListView,  int index, int id){
    int tablen = sizeof(SListViewFunctionsCallbackTab) / sizeof(S_ListViewFunctionsCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SListViewFunctionsCallbackTab[i].id == pListView->getID()) {
            SListViewFunctionsCallbackTab[i].onItemClickCallback(pListView, index, id);
            break;
        }
    }
}

void EnvSettingActivity::onSlideItemClick(ZKSlideWindow *pSlideWindow, int index) {
    int tablen = sizeof(SSlideWindowItemClickCallbackTab) / sizeof(S_SlideWindowItemClickCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SSlideWindowItemClickCallbackTab[i].id == pSlideWindow->getID()) {
            SSlideWindowItemClickCallbackTab[i].onSlideItemClickCallback(pSlideWindow, index);
            break;
        }
    }
}

bool EnvSettingActivity::onTouchEvent(const MotionEvent &ev) {
    return onEnvSettingActivityTouchEvent(ev);
}

void EnvSettingActivity::onTextChanged(ZKTextView *pTextView, const std::string &text) {
    int tablen = sizeof(SEditTextInputCallbackTab) / sizeof(S_EditTextInputCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SEditTextInputCallbackTab[i].id == pTextView->getID()) {
//        	mEditText1Ptr->setText("");
//        	strcpy(texttmp, text.c_str());
            SEditTextInputCallbackTab[i].onEditTextChangedCallback(text);
            break;
        }
    }
}

void EnvSettingActivity::rigesterActivityTimer() {
    int tablen = sizeof(REGISTER_ACTIVITY_TIMER_TAB) / sizeof(S_ACTIVITY_TIMEER);
    for (int i = 0; i < tablen; ++i) {
        S_ACTIVITY_TIMEER temp = REGISTER_ACTIVITY_TIMER_TAB[i];
        registerTimer(temp.id, temp.time);
    }
}


void EnvSettingActivity::onVideoPlayerMessage(ZKVideoView *pVideoView, int msg) {
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

void EnvSettingActivity::videoLoopPlayback(ZKVideoView *pVideoView, int msg, size_t callbackTabIndex) {

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

void EnvSettingActivity::startVideoLoopPlayback() {
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

void EnvSettingActivity::stopVideoLoopPlayback() {
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

bool EnvSettingActivity::parseVideoFileList(const char *pFileListPath, std::vector<string>& mediaFileList) {
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

int EnvSettingActivity::removeCharFromString(string& nString, char c) {
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

void EnvSettingActivity::registerUserTimer(int id, int time) {
	registerTimer(id, time);
}

void EnvSettingActivity::unregisterUserTimer(int id) {
	unregisterTimer(id);
}

void EnvSettingActivity::resetUserTimer(int id, int time) {
	resetTimer(id, time);
}
void EnvSettingActivity::onCheckedChanged(ZKRadioGroup* pRadioGroup, int checkedID) {
    int tablen = sizeof(SRadioGroupCallbackTab) / sizeof(S_RadioGroupCallback);
    for (int i = 0; i < tablen; ++i) {
        if (SRadioGroupCallbackTab[i].id == pRadioGroup->getID()) {
        	SRadioGroupCallbackTab[i].onCheckedChanged(pRadioGroup, checkedID);
            break;
        }
    }
}
