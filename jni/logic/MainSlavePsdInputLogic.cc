#pragma once
#include "uart/ProtocolSender.h"
#include "util/MachineStatus.h"
#include "util/ManualStatusListence.h"
/*
*此文件由GUI工具生成
*文件功能：用于处理用户的逻辑相应代码
*功能说明：
*========================onButtonClick_XXXX
当页面中的按键按下后系统会调用对应的函数，XXX代表GUI工具里面的[ID值]名称，
如Button1,当返回值为false的时候系统将不再处理这个按键，返回true的时候系统将会继续处理此按键。比如SYS_BACK.
*========================onSlideWindowItemClick_XXXX(int index) 
当页面中存在滑动窗口并且用户点击了滑动窗口的图标后系统会调用此函数,XXX代表GUI工具里面的[ID值]名称，
如slideWindow1;index 代表按下图标的偏移值
*========================onSeekBarChange_XXXX(int progress) 
当页面中存在滑动条并且用户改变了进度后系统会调用此函数,XXX代表GUI工具里面的[ID值]名称，
如SeekBar1;progress 代表当前的进度值
*========================ogetListItemCount_XXXX() 
当页面中存在滑动列表的时候，更新的时候系统会调用此接口获取列表的总数目,XXX代表GUI工具里面的[ID值]名称，
如List1;返回值为当前列表的总条数
*========================oobtainListItemData_XXXX(ZKListView::ZKListItem *pListItem, int index)
 当页面中存在滑动列表的时候，更新的时候系统会调用此接口获取列表当前条目下的内容信息,XXX代表GUI工具里面的[ID值]名称，
如List1;pListItem 是贴图中的单条目对象，index是列表总目的偏移量。具体见函数说明
*========================常用接口===============
*LOGD(...)  打印调试信息的接口
*mTextXXXPtr->setText("****") 在控件TextXXX上显示文字****
*mButton1Ptr->setSelected(true); 将控件mButton1设置为选中模式，图片会切换成选中图片，按钮文字会切换为选中后的颜色
*mSeekBarPtr->setProgress(12) 在控件mSeekBar上将进度调整到12
*mListView1Ptr->refreshListView() 让mListView1 重新刷新，当列表数据变化后调用
*mDashbroadView1Ptr->setTargetAngle(120) 在控件mDashbroadView1上指针显示角度调整到120度
*
* 在Eclipse编辑器中  使用 “alt + /”  快捷键可以打开智能提示
*/

static int TextKeyCount = 0;
static bool TextKeyFlag = false;
static std::vector<std::string > KeyVector;
static char keybuf[6];
static bool IsModifyKey = false;
bool Password_Validation = false;
//static std::vector<char *> KeyVector;

extern int MasterPressed;
/**
 * 注册定时器
 * 填充数组用于注册定时器
 * 注意：id不能重复
 */
static S_ACTIVITY_TIMEER REGISTER_ACTIVITY_TIMER_TAB[] = {
	//{0,  6000}, //定时器id=0, 时间间隔6秒
	{1,  500},
};

/**
 * 当界面构造时触发
 */
static void onUI_init(){
    //Tips :添加 UI初始化的显示代码到这里,如:mText1Ptr->setText("123");

}

/**
 * 当切换到该界面时触发
 */
static void onUI_intent(const Intent *intentPtr) {
    if (intentPtr != NULL) {
        //TODO
    }
}

/*
 * 当界面显示时触发
 */
static void onUI_show() {
	mWindow1Ptr->setAlpha(179);
}

/*
 * 当界面隐藏时触发
 */
static void onUI_hide() {

}

/*
 * 当界面完全退出时触发
 */
static void onUI_quit() {
	TextKeyCount = 0;
	TextKeyFlag = false;
}

/**
 * 串口数据回调接口
 */
static void onProtocolDataUpdate(const SProtocolData &data) {

}

/**
 * 定时器触发函数
 * 不建议在此函数中写耗时操作，否则将影响UI刷新
 * 参数： id
 *         当前所触发定时器的id，与注册时的id相同
 * 返回值: true
 *             继续运行当前定时器
 *         false
 *             停止运行当前定时器
 */
static bool onUI_Timer(int id){
//	char keys[10];
	char *keys;
	bool keyflag = false;
	switch (id) {
	case 1:
	{
		if (TextKeyFlag){
			TextKeyFlag = false;
			if (!IsModifyKey){
//				char *tmpkeys = MACHINESTATUS->getMasterSlaverKey();
//				strcpy(keys, tmpkeys);
				keys = MACHINESTATUS->getMasterSlaverKey();
				LOGD("The key is : %s and key buf is %s\n", keys, &keybuf);
	//			LOGD("key buf is %c\n", keybuf);
				for (int i = 0;i < 6;i++){
					if (keybuf[i] != keys[i]){
						LOGD("Key error\n");
						keyflag = false;
						break;
					}
					keyflag = true;
				}
				if (!keyflag){
					//key error
//					Password_Validation = false;
					TextKeyCount = 0;
					for (int i = 0;i < 6;i++){
						mTextViewKeyPtr[i]->setText("");
					}
				}else{
					//key correct
//					Password_Validation = true;
					if (MasterPressed == 1){
						MACHINESTATUS->setMasterorSlaver(false);
						MANUALSTATUS->setMainMachineMode(0);
					}else if (MasterPressed == 0){
						MACHINESTATUS->setMasterorSlaver(true);
						MANUALSTATUS->setMainMachineMode(1);
					}
					EASYUICONTEXT->goBack();
				}
			}else{

			}
		}
	}
	break;
		default:
			break;
	}
    return true;
}

/**
 * 有新的触摸事件时触发
 * 参数：ev
 *         新的触摸事件
 * 返回值：true
 *            表示该触摸事件在此被拦截，系统不再将此触摸事件传递到控件上
 *         false
 *            触摸事件将继续传递到控件上
 */
static bool onMainSlavePsdInputActivityTouchEvent(const MotionEvent &ev) {
    switch (ev.mActionStatus) {
		case MotionEvent::E_ACTION_DOWN://触摸按下
			//LOGD("时刻 = %ld 坐标  x = %d, y = %d", ev.mEventTime, ev.mX, ev.mY);
			break;
		case MotionEvent::E_ACTION_MOVE://触摸滑动
			break;
		case MotionEvent::E_ACTION_UP:  //触摸抬起
			break;
		default:
			break;
	}
	return false;
}
static bool onButtonClick_Button1(ZKButton *pButton) {
    LOGD(" ButtonClick Button1 !!!\n");
    EASYUICONTEXT->goBack();
    return false;
}


static bool onButtonClick_ButtonForgetKey(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonForgetKey !!!\n");
    return false;
}

static bool onButtonClick_ButtonModifyKey(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonModifyKey !!!\n");
    IsModifyKey = true;
    TextKeyCount = 0;
    mTextView2Ptr->setVisible(true);
    mTextView1Ptr->setVisible(false);
    mButtonNumDelPtr->setVisible(false);
    mButtonComfirmPtr->setVisible(true);
    return false;
}

static bool onButtonClick_ButtonNum1(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonNum1 !!!\n");
    if (TextKeyCount >= 6)
    	return false;
    keybuf[TextKeyCount] = '1';
    mTextViewKeyPtr[TextKeyCount++]->setText("●");
    KeyVector.push_back(pButton->getText().c_str());
    if (TextKeyCount == 6){
//    	TextKeyCount = 0;
    	TextKeyFlag = true;
	}
    return false;
}

static bool onButtonClick_ButtonNum2(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonNum2 !!!\n");
    if (TextKeyCount >= 6)
       	return false;
    keybuf[TextKeyCount] = '2';
    mTextViewKeyPtr[TextKeyCount++]->setText("●");
    KeyVector.push_back(pButton->getText().c_str());
    if (TextKeyCount == 6){
		TextKeyFlag = true;
//		TextKeyCount = 0;
  	}
    return false;
}

static bool onButtonClick_ButtonNum3(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonNum3 !!!\n");
    if (TextKeyCount >= 6)
       	return false;
    keybuf[TextKeyCount] = '3';
    mTextViewKeyPtr[TextKeyCount++]->setText("●");
    KeyVector.push_back(pButton->getText().c_str());
    if (TextKeyCount == 6){
      	TextKeyFlag = true;
//      	TextKeyCount = 0;
  	}
    return false;
}

static bool onButtonClick_ButtonNum4(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonNum4 !!!\n");
    if (TextKeyCount >= 6)
       	return false;
    keybuf[TextKeyCount] = '4';
    mTextViewKeyPtr[TextKeyCount++]->setText("●");
    KeyVector.push_back(pButton->getText().c_str());
    if (TextKeyCount == 6){
      	TextKeyFlag = true;
//      	TextKeyCount = 0;
  	}
    return false;
}

static bool onButtonClick_ButtonNum7(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonNum7 !!!\n");
    if (TextKeyCount >= 6)
       	return false;
    keybuf[TextKeyCount] = '7';
    mTextViewKeyPtr[TextKeyCount++]->setText("●");
    KeyVector.push_back(pButton->getText().c_str());
    if (TextKeyCount == 6){
      	TextKeyFlag = true;
//      	TextKeyCount = 0;
  	}
    return false;
}

static bool onButtonClick_ButtonNumDel(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonNumDel !!!\n");
    mTextViewKeyPtr[TextKeyCount]->setText("");

    keybuf[TextKeyCount] = '\0';
	TextKeyCount--;
	if (TextKeyCount < 0){
		TextKeyCount = 0;
	}


    return false;
}

static bool onButtonClick_ButtonNum5(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonNum5 !!!\n");
    if (TextKeyCount >= 6)
       	return false;
    keybuf[TextKeyCount] = '5';
    mTextViewKeyPtr[TextKeyCount++]->setText("●");
    KeyVector.push_back(pButton->getText().c_str());
    if (TextKeyCount == 6){
      	TextKeyFlag = true;
//      	TextKeyCount = 0;
  	}
    return false;
}

static bool onButtonClick_ButtonNum8(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonNum8 !!!\n");
    if (TextKeyCount >= 6)
       	return false;
    keybuf[TextKeyCount] = '8';
    mTextViewKeyPtr[TextKeyCount++]->setText("●");
    KeyVector.push_back(pButton->getText().c_str());
    if (TextKeyCount == 6){
      	TextKeyFlag = true;
//      	TextKeyCount = 0;
  	}
    return false;
}

static bool onButtonClick_ButtonNum0(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonNum0 !!!\n");
    if (TextKeyCount >= 6)
       	return false;
    keybuf[TextKeyCount] = '0';
    mTextViewKeyPtr[TextKeyCount++]->setText("●");
    KeyVector.push_back(0);
    if (TextKeyCount == 6){
      	TextKeyFlag = true;
//      	TextKeyCount = 0;
  	}
    return false;
}

static bool onButtonClick_ButtonNum6(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonNum6 !!!\n");
    if (TextKeyCount >= 6)
       	return false;
    keybuf[TextKeyCount] = '6';
    mTextViewKeyPtr[TextKeyCount++]->setText("●");
    KeyVector.push_back(pButton->getText().c_str());
    if (TextKeyCount == 6){
      	TextKeyFlag = true;
//      	TextKeyCount = 0;
  	}
    return false;
}

static bool onButtonClick_ButtonNum9(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonNum9 !!!\n");
    if (TextKeyCount >= 6)
       	return false;
    keybuf[TextKeyCount] = '9';
    mTextViewKeyPtr[TextKeyCount++]->setText("●");
    KeyVector.push_back(pButton->getText().c_str());
    if (TextKeyCount == 6){
      	TextKeyFlag = true;

  	}
    return false;
}

static bool onButtonClick_ButtonNumCancel(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonNumCancel !!!\n");
    if (!IsModifyKey){
    	EASYUICONTEXT->goBack();
    }else{
    	for (int i = 0;i < 6;i++){
			mTextViewKeyPtr[i]->setText("");
		}
    	TextKeyCount = 0;
    	IsModifyKey = false;
		mTextView2Ptr->setVisible(false);
		mTextView1Ptr->setVisible(true);
		mButtonNumDelPtr->setVisible(true);
		mButtonComfirmPtr->setVisible(false);
    }

    return false;
}
static bool onButtonClick_ButtonComfirm(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonComfirm !!!\n");
//    char *keys;
//    LOGD("The keybuf size is %d\n", sizeof(keybuf));
    if (IsModifyKey && TextKeyCount == 6){

    	TextKeyCount = 0;
    	IsModifyKey = false;
		MACHINESTATUS->setMasterSlaverKey(keybuf);
		EASYUICONTEXT->goBack();
    }

    return false;
}
