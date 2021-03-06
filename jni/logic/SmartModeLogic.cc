#pragma once
#include "uart/ProtocolSender.h"
#include "util/MachineStatus.h"
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

static int SmartModeSelect = StandardMode;

/**
 * 注册定时器
 * 填充数组用于注册定时器
 * 注意：id不能重复
 */
static S_ACTIVITY_TIMEER REGISTER_ACTIVITY_TIMER_TAB[] = {
	//{0,  6000}, //定时器id=0, 时间间隔6秒
	//{1,  1000},
};

void DisPlayFocusMode(int index);

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

//	mTextView45Ptr->setText(std::to_string(atoi(mTextView45Ptr->getText().c_str())));
//	mTextView43Ptr->setText(std::to_string(atoi(mTextView43Ptr->getText().c_str())));
//
	mButtonHomepage2Ptr->setSelected(false);
	mButtonSmart2Ptr->setSelected(true);
	mButtonManual2Ptr->setSelected(false);
	mButtonHistorty2Ptr->setSelected(false);

	mTextViewHomepage2Ptr->setSelected(false);
	mTextViewSmart2Ptr->setSelected(true);
	mTextViewManual2Ptr->setSelected(false);
	mTextViewHistory2Ptr->setSelected(false);

	DisPlayFocusMode(MACHINESTATUS->getsmartmode());

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
	switch (id) {

		default:
			break;
	}
    return true;
}

void DisPlayFocusMode(int index)
{
	if(index < 0 || index > 3)
		return ;

	//打开对应模式窗口
	switch(index)
	{
		case StandardMode:
		{
			mButtonStdModePtr->setSelected(true);
			mButtonHokiModePtr->setSelected(false);
			mButtonHawaiModePtr->setSelected(false);
			mButtonVacModePtr->setSelected(false);

			mWindowStandardModePtr->setVisible(true);
			mWindowHokkaidoModePtr->setVisible(false);
			mWindowHawaiiModePtr->setVisible(false);
			mWindowVacationModePtr->setVisible(false);
		}
			break;

		case HokiMode:
		{
			mButtonStdModePtr->setSelected(false);
			mButtonHokiModePtr->setSelected(true);
			mButtonHawaiModePtr->setSelected(false);
			mButtonVacModePtr->setSelected(false);

			mWindowStandardModePtr->setVisible(false);
			mWindowHokkaidoModePtr->setVisible(true);
			mWindowHawaiiModePtr->setVisible(false);
			mWindowVacationModePtr->setVisible(false);
		}
			break;

		case HawaiMode:
		{
			mButtonStdModePtr->setSelected(false);
			mButtonHokiModePtr->setSelected(false);
			mButtonHawaiModePtr->setSelected(true);
			mButtonVacModePtr->setSelected(false);

			mWindowStandardModePtr->setVisible(false);
			mWindowHokkaidoModePtr->setVisible(false);
			mWindowHawaiiModePtr->setVisible(true);
			mWindowVacationModePtr->setVisible(false);
		}
			break;

		case VacMode:
		{
			mButtonStdModePtr->setSelected(false);
			mButtonHokiModePtr->setSelected(false);
			mButtonHawaiModePtr->setSelected(false);
			mButtonVacModePtr->setSelected(true);

			mWindowStandardModePtr->setVisible(false);
			mWindowHokkaidoModePtr->setVisible(false);
			mWindowHawaiiModePtr->setVisible(false);
			mWindowVacationModePtr->setVisible(true);
		}
			break;
		default:
			break;
	}
}

void StdModeCalTempAndHumd()
{
	mButton7Ptr->setSelected(true);
	mButton8Ptr->setSelected(true);
	mButton9Ptr->setSelected(true);
	mButton10Ptr->setSelected(true);

	if(atoi(mTextView10Ptr->getText().c_str()) <= 17)
	{
		mTextView10Ptr->setText("17");
		mButton7Ptr->setSelected(false);
	}
	if(atoi(mTextView10Ptr->getText().c_str()) >= 27)
	{
		mTextView10Ptr->setText("27");
		mButton9Ptr->setSelected(false);
	}


	if(atoi(mTextView12Ptr->getText().c_str()) <= 30)
	{
		mButton8Ptr->setSelected(false);
		mTextView12Ptr->setText("30");
	}
	if(atoi(mTextView12Ptr->getText().c_str()) >= 70)
	{
		mButton10Ptr->setSelected(false);
		mTextView12Ptr->setText("70");
	}


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
static bool onSmartModeActivityTouchEvent(const MotionEvent &ev) {
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
static bool onButtonClick_Button7(ZKButton *pButton) {
    LOGD(" ButtonClick Button7 !!!\n");

    if(mButton6Ptr->isSelected())
    {
    	mTextView10Ptr->setText(atoi(mTextView10Ptr->getText().c_str()) - 1);
//    	if(atoi(mTextView10Ptr->getText().c_str()) <= 17)
//		{
//			mTextView10Ptr->setText("17");
//			pButton->setSelected(false);
//		}
//    	else
//    	{
//    		pButton->setSelected(true);
//    	}
    	StdModeCalTempAndHumd();
    }


    return false;
}

static bool onButtonClick_Button9(ZKButton *pButton) {
    LOGD(" ButtonClick Button9 !!!\n");
    if(mButton6Ptr->isSelected())
	{
		mTextView10Ptr->setText(atoi(mTextView10Ptr->getText().c_str()) + 1);
//		if(atoi(mTextView10Ptr->getText().c_str()) >= 27)
//		{
//			pButton->setSelected(false);
//			mTextView10Ptr->setText("27");
//		}
//		else
//		{
//			pButton->setSelected(true);
//		}
		StdModeCalTempAndHumd();
	}


    return false;
}

static bool onButtonClick_Button8(ZKButton *pButton) {
    LOGD(" ButtonClick Button8 !!!\n");
    if(mButton6Ptr->isSelected())
	{
		mTextView12Ptr->setText(atoi(mTextView12Ptr->getText().c_str()) - 1);
//		if(atoi(mTextView12Ptr->getText().c_str()) <= 30)
//		{
//			pButton->setSelected(false);
//			mTextView12Ptr->setText("30");
//		}
		StdModeCalTempAndHumd();
	}


    return false;
}



static bool onButtonClick_Button10(ZKButton *pButton) {
    LOGD(" ButtonClick Button10 !!!\n");
    if(mButton6Ptr->isSelected())
	{
    	mTextView12Ptr->setText(atoi(mTextView12Ptr->getText().c_str()) + 1);
//		if(atoi(mTextView12Ptr->getText().c_str()) >= 70)
//		{
//			mButton10Ptr->setSelected(false);
//			mTextView12Ptr->setText("70");
//		}
    	StdModeCalTempAndHumd();
	}



    return false;
}

static bool onButtonClick_Button6(ZKButton *pButton) {
    LOGD(" ButtonClick Button6 !!!\n");
    if(pButton->isSelected())
    {
    	mButton6Ptr->setSelected(false);

    	mButton7Ptr->setSelected(false);
    	mButton9Ptr->setSelected(false);
    	mButton8Ptr->setSelected(false);
    	mButton10Ptr->setSelected(false);
    }
    else
    {
    	mButton6Ptr->setSelected(true);

    	mButton7Ptr->setSelected(true);
		mButton9Ptr->setSelected(true);
    	mButton8Ptr->setSelected(true);
		mButton10Ptr->setSelected(true);

    	if(atoi(mTextView10Ptr->getText().c_str()) >= 27)
    	{
    		mButton9Ptr->setSelected(false);
    		mTextView10Ptr->setText("27");
    	}
    	else if(atoi(mTextView10Ptr->getText().c_str()) <= 17)
    	{
    		mButton7Ptr->setSelected(false);
    		mTextView10Ptr->setText("17");
    	}

    	if(atoi(mTextView12Ptr->getText().c_str()) >= 70)
    	{
    		mButton10Ptr->setSelected(false);
    		mTextView12Ptr->setText("70");
    	}
    	else if(atoi(mTextView12Ptr->getText().c_str()) <= 30)
    	{
    		mButton8Ptr->setSelected(false);
    		mTextView12Ptr->setText("30");
    	}

    }


    return false;
}

static bool onButtonClick_Button11(ZKButton *pButton) {
    LOGD(" ButtonClick Button11 !!!\n");
    if(pButton->isSelected())
	{
		mButton11Ptr->setSelected(false);
	}
	else
	{
		mButton11Ptr->setSelected(true);
		//按键动画显示
	}
    return false;
}

static bool onButtonClick_Button12(ZKButton *pButton) {
    LOGD(" ButtonClick Button12 !!!\n");
    if(pButton->isSelected())
	{
		mButton12Ptr->setSelected(false);
	}
	else
	{
		mButton12Ptr->setSelected(true);
		//按键动画显示
	}
    return false;
}

static bool onButtonClick_Button13(ZKButton *pButton) {
    LOGD(" ButtonClick Button13 !!!\n");
    if(pButton->isSelected())
	{
		mButton13Ptr->setSelected(false);
	}
	else
	{
		mButton13Ptr->setSelected(true);
		//按键动画显示
	}
    return false;
}



static bool onButtonClick_ButtonDropDown(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonDropDown !!!\n");
    return false;
}
static bool onButtonClick_ButtonStdMode(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonStdMode !!!\n");
    SmartModeSelect = StandardMode;
    if(pButton->isSelected())
    {
    	return false;
    }
    else
    {
    	if(mButton11Ptr->isSelected() || mButton12Ptr->isSelected() || mButton13Ptr->isSelected())
    	{
    		//弹出是否切换模式弹框
    	}
    	//DisPlayFocusMode(index);
    	DisPlayFocusMode(SmartModeSelect);
    	MACHINESTATUS->setsmartmode(SmartModeSelect);
    }
    return false;
}

static bool onButtonClick_ButtonHokiMode(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHokiMode !!!\n");
	SmartModeSelect = HokiMode;
	if(pButton->isSelected())
	{
		return false;
	}
	else
	{
		if(mButton12Ptr->isSelected() || mButton6Ptr->isSelected() || mButton13Ptr->isSelected())
		{
			//弹出是否切换模式弹框
		}
		//DisPlayFocusMode(index);
		DisPlayFocusMode(SmartModeSelect);
		MACHINESTATUS->setsmartmode(SmartModeSelect);
	}
    return false;
}

static bool onButtonClick_ButtonHawaiMode(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHawaiMode !!!\n");
	SmartModeSelect = HawaiMode;
	if(pButton->isSelected())
	{
		return false;
	}
	else
	{
		if(mButton11Ptr->isSelected() || mButton6Ptr->isSelected() || mButton13Ptr->isSelected())
		{
			//弹出是否切换模式弹框
		}
		//DisPlayFocusMode(index);
		DisPlayFocusMode(SmartModeSelect);
		MACHINESTATUS->setsmartmode(SmartModeSelect);
	}
    return false;
}

static bool onButtonClick_ButtonVacMode(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonVacMode !!!\n");
	SmartModeSelect = VacMode;
	if(pButton->isSelected())
	{
		return false;
	}
	else
	{
		if(mButton11Ptr->isSelected() || mButton10Ptr->isSelected() || mButton6Ptr->isSelected())
		{
			//弹出是否切换模式弹框
		}
		//DisPlayFocusMode(index);
		DisPlayFocusMode(SmartModeSelect);
		MACHINESTATUS->setsmartmode(SmartModeSelect);
	}
    return false;
}
static bool onButtonClick_ButtonHomepage2(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHomepage !!!\n");
    if(pButton->isSelected())
    {
    	return false;
    }
    else
    {
    	pButton->setSelected(true);
    }
//    DisPlayNavibarMode(0);
    EASYUICONTEXT->openActivity("mainActivity", NULL);
    return false;
}


static bool onButtonClick_ButtonSmart2(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonSmart !!!\n");
    if(pButton->isSelected())
	{
    	return false;
	}
	else
	{
		pButton->setSelected(true);
	}
//    DisPlayNavibarMode(1);
    EASYUICONTEXT->openActivity("SmartModeActivity", NULL);
    return false;
}
static bool onButtonClick_ButtonManual2(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonSmart !!!\n");
    if(pButton->isSelected())
	{
    	return false;
	}
	else
	{
		pButton->setSelected(true);
	}
//    DisPlayNavibarMode(2);
    EASYUICONTEXT->openActivity("ManualMode11Activity", NULL);
    return false;
}


static bool onButtonClick_ButtonHistorty2(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHistorty !!!\n");
    if(pButton->isSelected())
	{
    	return false;
	}
	else
	{
		pButton->setSelected(true);
	}
//    DisPlayNavibarMode(3);
    EASYUICONTEXT->openActivity("HistoryDateActivity", NULL);
    return false;
}
