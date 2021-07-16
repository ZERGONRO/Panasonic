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

static bool Flag_Settiming = false;


/**
 * 注册定时器
 * 填充数组用于注册定时器
 * 注意：id不能重复
 */
static S_ACTIVITY_TIMEER REGISTER_ACTIVITY_TIMER_TAB[] = {
	//{0,  6000}, //定时器id=0, 时间间隔6秒
	{1,  1000},
};

void AddTimeSettingFunc();

void ResetTimeTextPos(){
	int StartLeft = 0;
	LayoutPosition lp;
	if (mTextView9Ptr->isVisible()){
		lp = mTextView9Ptr->getPosition();
		lp.mLeft = StartLeft;
		lp.mTop = 10;
//		StartLeft += 66;
		mTextView9Ptr->setPosition(lp);
		return;
	}

	if (mTextView2Ptr->isVisible()){
		lp = mTextView2Ptr->getPosition();
		lp.mLeft = StartLeft;
		lp.mTop = 10;
		StartLeft += 66;
		mTextView2Ptr->setPosition(lp);
	}else{
		lp = mTextView2Ptr->getPosition();
		lp.mTop = -50;
		mTextView2Ptr->setPosition(lp);
	}

	if (mTextView3Ptr->isVisible()){
		lp = mTextView3Ptr->getPosition();
		lp.mLeft = StartLeft;
		lp.mTop = 10;
		StartLeft += 66;
		mTextView3Ptr->setPosition(lp);
	}else{
		lp = mTextView3Ptr->getPosition();
		lp.mTop = -50;
		mTextView3Ptr->setPosition(lp);
	}

	if (mTextView4Ptr->isVisible()){
		lp = mTextView4Ptr->getPosition();
		lp.mLeft = StartLeft;
		lp.mTop = 10;
		StartLeft += 66;
		mTextView4Ptr->setPosition(lp);
	}else{
		lp = mTextView4Ptr->getPosition();
		lp.mTop = -50;
		mTextView4Ptr->setPosition(lp);
	}

	if (mTextView5Ptr->isVisible()){
		lp = mTextView5Ptr->getPosition();
		lp.mLeft = StartLeft;
		lp.mTop = 10;
		StartLeft += 66;
		mTextView5Ptr->setPosition(lp);
	}else{
		lp = mTextView5Ptr->getPosition();
		lp.mTop = -50;
		mTextView5Ptr->setPosition(lp);
	}

	if (mTextView6Ptr->isVisible()){
		lp = mTextView6Ptr->getPosition();
		lp.mLeft = StartLeft;
		lp.mTop = 10;
		StartLeft += 66;
		mTextView6Ptr->setPosition(lp);
	}else{
		lp = mTextView6Ptr->getPosition();
		lp.mTop = -50;
		mTextView6Ptr->setPosition(lp);
	}

	if (mTextView7Ptr->isVisible()){
		lp = mTextView7Ptr->getPosition();
		lp.mLeft = StartLeft;
		lp.mTop = 10;
		StartLeft += 66;
		mTextView7Ptr->setPosition(lp);
	}else{
		lp = mTextView6Ptr->getPosition();
		lp.mTop = -50;
		mTextView7Ptr->setPosition(lp);
	}

	if (mTextView8Ptr->isVisible()){
		lp = mTextView8Ptr->getPosition();
		lp.mLeft = StartLeft;
		lp.mTop = 10;
		StartLeft += 66;
		mTextView8Ptr->setPosition(lp);
	}else{
		lp = mTextView8Ptr->getPosition();
		lp.mTop = -50;
		mTextView8Ptr->setPosition(lp);
	}
}

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
    	std::string DeviceName = intentPtr->getExtra("DeviceName");
    	mTextView1Ptr->setText(DeviceName.c_str());
    	mTextViewAirPtr->setText(DeviceName.c_str());
    }
}

/*
 * 当界面显示时触发
 */
static void onUI_show() {
	ResetTimeTextPos();
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
		case 0:
				break;
		case 1:
		{
			if (Flag_Settiming){
				Flag_Settiming = false;
				AddTimeSettingFunc();
//				mTextView13Ptr->setText(text)
			}
		}
			break;
		default:
			break;
	}
    return true;
}

void WeekPosReset()
{
	LayoutPosition lp;
	int StartLeft = 0;
	if (mTextView2Ptr->isSelected()){
		lp = mTextView2Ptr->getPosition();
		lp.mLeft = StartLeft;
		lp.mTop = 10;
		StartLeft += 66;
		mTextView2Ptr->setPosition(lp);
	}
	if (mTextView3Ptr->isSelected()){
		lp = mTextView3Ptr->getPosition();
		lp.mLeft = StartLeft;
		lp.mTop = 10;
		StartLeft += 66;
		mTextView3Ptr->setPosition(lp);
	}
	if (mTextView4Ptr->isSelected()){
		lp = mTextView4Ptr->getPosition();
		lp.mLeft = StartLeft;
		lp.mTop = 10;
		StartLeft += 66;
		mTextView4Ptr->setPosition(lp);
	}
	if (mTextView5Ptr->isSelected()){
		lp = mTextView5Ptr->getPosition();
		lp.mLeft = StartLeft;
		lp.mTop = 10;
		StartLeft += 66;
		mTextView5Ptr->setPosition(lp);
	}
	if (mTextView6Ptr->isSelected()){
		lp = mTextView6Ptr->getPosition();
		lp.mLeft = StartLeft;
		lp.mTop = 10;
		StartLeft += 66;
		mTextView6Ptr->setPosition(lp);
	}
	if (mTextView7Ptr->isSelected()){
		lp = mTextView7Ptr->getPosition();
		lp.mLeft = StartLeft;
		lp.mTop = 10;
		StartLeft += 66;
		mTextView7Ptr->setPosition(lp);
	}
	if (mTextView8Ptr->isSelected()){
		mTextView8Ptr->setVisible(true);
		lp = mTextView8Ptr->getPosition();
		lp.mLeft = StartLeft;
		lp.mTop = 10;
		StartLeft += 66;
		mTextView8Ptr->setPosition(lp);
	}
	if (StartLeft == 396 || mTextView9Ptr->isSelected()){
		mTextView2Ptr->setVisible(false);
		mTextView3Ptr->setVisible(false);
		mTextView4Ptr->setVisible(false);
		mTextView5Ptr->setVisible(false);
		mTextView6Ptr->setVisible(false);
		mTextView7Ptr->setVisible(false);
		mTextView8Ptr->setVisible(false);

		mTextView9Ptr->setVisible(true);
		lp = mTextView9Ptr->getPosition();
		lp.mLeft = 0;
		lp.mTop = 10;
//		StartLeft = 0;
		mTextView9Ptr->setPosition(lp);
	}


}

void AddTimeSettingFunc()
{

	int Timenum1, Timenum2;
	char Timebuf[64];
	EquipmentTiming *DevTimeSetting = MACHINESTATUS->getEquipmentTimeSetting();
	if (DevTimeSetting->Time1StageFlag){
		Timenum1 = DevTimeSetting->TimeOpenValue1 / 60;
		Timenum2 = DevTimeSetting->TimeOpenValue1 % 60;
		sprintf(Timebuf, "%02d:%02d", Timenum1, Timenum2);
		mTextView13Ptr->setText(Timebuf);

		Timenum1 = DevTimeSetting->TimeCloseValue1 / 60;
		Timenum2 = DevTimeSetting->TimeCloseValue1 % 60;
		sprintf(Timebuf, "%02d:%02d", Timenum1, Timenum2);
		mTextView14Ptr->setText(Timebuf);

		mTextView15Ptr->setText(std::to_string(DevTimeSetting->TempSettingValue1) + "℃");
	}else{
		mTextView13Ptr->setText("未设置");
		mTextView14Ptr->setText("未设置");
		mTextView15Ptr->setText("未设置");
	}

	if (DevTimeSetting->Time2StageFlag){
		Timenum1 = DevTimeSetting->TimeOpenValue2 / 60;
		Timenum2 = DevTimeSetting->TimeOpenValue2 % 60;
		sprintf(Timebuf, "%02d:%02d", Timenum1, Timenum2);
		mTextView23Ptr->setText(Timebuf);

		Timenum1 = DevTimeSetting->TimeCloseValue2 / 60;
		Timenum2 = DevTimeSetting->TimeCloseValue2 % 60;
		sprintf(Timebuf, "%02d:%02d", Timenum1, Timenum2);
		mTextView24Ptr->setText(Timebuf);

		mTextView25Ptr->setText(std::to_string(DevTimeSetting->TempSettingValue2) + "℃");
	}else{
		mTextView23Ptr->setText("未设置");
		mTextView24Ptr->setText("未设置");
		mTextView25Ptr->setText("未设置");
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
static bool onTimingActivityTouchEvent(const MotionEvent &ev) {
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
static bool onButtonClick_Button2(ZKButton *pButton) {
    LOGD(" ButtonClick Button2 !!!\n");
    if (mButton6Ptr->isSelected()){
    	Flag_Settiming = true;
    	EASYUICONTEXT->openActivity("AddTimeSettingActivity", NULL);

    }



    return false;
}

static bool onButtonClick_Button6(ZKButton *pButton) {
    LOGD(" ButtonClick Button6 !!!\n");
    if (pButton->isSelected()){
    	mButton2Ptr->setSelected(false);
    	pButton->setSelected(false);
    }else{
    	mButton2Ptr->setSelected(true);
    	pButton->setSelected(true);
    }
    return false;
}

static bool onButtonClick_Button1(ZKButton *pButton) {
    LOGD(" ButtonClick Button1 !!!\n");
    EASYUICONTEXT->goBack();
    return false;
}

static bool onButtonClick_ButtonDropDown(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonDropDown !!!\n");
    return false;
}
static bool onButtonClick_ButtonBack(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonBack !!!\n");
    EASYUICONTEXT->goBack();
    return false;
}
static bool onButtonClick_ButtonReturn(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonReturn !!!\n");
    return false;
}
