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

static int ManualType = Manual_AirPF;

/**
 * 注册定时器
 * 填充数组用于注册定时器
 * 注意：id不能重复
 */
static S_ACTIVITY_TIMEER REGISTER_ACTIVITY_TIMER_TAB[] = {
	//{0,  6000}, //定时器id=0, 时间间隔6秒
	//{1,  1000},
};


void ManualMode11SelStatus(int index);
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


	mButtonHomepage2Ptr->setSelected(false);
	mButtonSmart2Ptr->setSelected(false);
	mButtonManual2Ptr->setSelected(true);
	mButtonHistorty2Ptr->setSelected(false);

	mTextViewHomepage2Ptr->setSelected(false);
	mTextViewSmart2Ptr->setSelected(false);
	mTextViewManual2Ptr->setSelected(true);
	mTextViewHistory2Ptr->setSelected(false);

	ManualMode11SelStatus(MACHINESTATUS->getmanualmode());

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

/**
 * 有新的触摸事件时触发
 * 参数：ev
 *         新的触摸事件
 * 返回值：true
 *            表示该触摸事件在此被拦截，系统不再将此触摸事件传递到控件上
 *         false
 *            触摸事件将继续传递到控件上
 */
static bool onManualMode11ActivityTouchEvent(const MotionEvent &ev) {
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
void ManualMode11SelStatus(int index)
{
	switch(index)
	{
		case Manual_AirPF:
		{
			mButtonPurifyPtr->setSelected(true);
			mButtonAirPtr->setSelected(false);
			mButtonHotChangePtr->setSelected(false);
			mButtonModHumdPtr->setSelected(false);
			mButtonChangeWindPtr->setSelected(false);
			mButtonSterilizationPtr->setSelected(false);
			mButtonYuBaPtr->setSelected(false);

			mWindowAirPFPtr->setVisible(true);
			mWindowAirSwitchPtr->setVisible(false);
			mWindowHotChangeSwitchPtr->setVisible(false);
			mWindowHumdSwitchPtr->setVisible(false);
			mWindowWindSwitchPtr->setVisible(false);
			mWindowYubaSwitchPtr->setVisible(false);
			mWindowSterilizationPtr->setVisible(false);
		}
			break;
		case Manual_Air:
		{
			mButtonPurifyPtr->setSelected(false);
			mButtonAirPtr->setSelected(true);
			mButtonHotChangePtr->setSelected(false);
			mButtonModHumdPtr->setSelected(false);
			mButtonChangeWindPtr->setSelected(false);
			mButtonSterilizationPtr->setSelected(false);
			mButtonYuBaPtr->setSelected(false);

			mWindowAirPFPtr->setVisible(false);
			mWindowAirSwitchPtr->setVisible(true);
			mWindowHotChangeSwitchPtr->setVisible(false);
			mWindowHumdSwitchPtr->setVisible(false);
			mWindowWindSwitchPtr->setVisible(false);
			mWindowYubaSwitchPtr->setVisible(false);
			mWindowSterilizationPtr->setVisible(false);
		}
			break;
		case Manual_HotChange:
		{
			mButtonPurifyPtr->setSelected(false);
			mButtonAirPtr->setSelected(false);
			mButtonHotChangePtr->setSelected(true);
			mButtonModHumdPtr->setSelected(false);
			mButtonChangeWindPtr->setSelected(false);
			mButtonSterilizationPtr->setSelected(false);
			mButtonYuBaPtr->setSelected(false);

			mWindowAirPFPtr->setVisible(false);
			mWindowAirSwitchPtr->setVisible(false);
			mWindowHotChangeSwitchPtr->setVisible(true);
			mWindowHumdSwitchPtr->setVisible(false);
			mWindowWindSwitchPtr->setVisible(false);
			mWindowYubaSwitchPtr->setVisible(false);
			mWindowSterilizationPtr->setVisible(false);
		}
			break;
		case Manual_Humd:
		{
			mButtonPurifyPtr->setSelected(false);
			mButtonAirPtr->setSelected(false);
			mButtonHotChangePtr->setSelected(false);
			mButtonModHumdPtr->setSelected(true);
			mButtonChangeWindPtr->setSelected(false);
			mButtonSterilizationPtr->setSelected(false);
			mButtonYuBaPtr->setSelected(false);

			mWindowAirPFPtr->setVisible(false);
			mWindowAirSwitchPtr->setVisible(false);
			mWindowHotChangeSwitchPtr->setVisible(false);
			mWindowHumdSwitchPtr->setVisible(true);
			mWindowWindSwitchPtr->setVisible(false);
			mWindowYubaSwitchPtr->setVisible(false);
			mWindowSterilizationPtr->setVisible(false);
		}
			break;
		case Manual_WindChange:
		{
			mButtonPurifyPtr->setSelected(false);
			mButtonAirPtr->setSelected(false);
			mButtonHotChangePtr->setSelected(false);
			mButtonModHumdPtr->setSelected(false);
			mButtonChangeWindPtr->setSelected(true);
			mButtonSterilizationPtr->setSelected(false);
			mButtonYuBaPtr->setSelected(false);

			mWindowAirPFPtr->setVisible(false);
			mWindowAirSwitchPtr->setVisible(false);
			mWindowHotChangeSwitchPtr->setVisible(false);
			mWindowHumdSwitchPtr->setVisible(false);
			mWindowWindSwitchPtr->setVisible(true);
			mWindowYubaSwitchPtr->setVisible(false);
			mWindowSterilizationPtr->setVisible(false);
		}
			break;
		case Manual_Ster:
		{
			mButtonPurifyPtr->setSelected(false);
			mButtonAirPtr->setSelected(false);
			mButtonHotChangePtr->setSelected(false);
			mButtonModHumdPtr->setSelected(false);
			mButtonChangeWindPtr->setSelected(false);
			mButtonSterilizationPtr->setSelected(true);
			mButtonYuBaPtr->setSelected(false);

			mWindowAirPFPtr->setVisible(false);
			mWindowAirSwitchPtr->setVisible(false);
			mWindowHotChangeSwitchPtr->setVisible(false);
			mWindowHumdSwitchPtr->setVisible(false);
			mWindowWindSwitchPtr->setVisible(false);
			mWindowYubaSwitchPtr->setVisible(false);
			mWindowSterilizationPtr->setVisible(true);
		}
			break;
		case Manual_YuBa:
		{
			mButtonPurifyPtr->setSelected(false);
			mButtonAirPtr->setSelected(false);
			mButtonHotChangePtr->setSelected(false);
			mButtonModHumdPtr->setSelected(false);
			mButtonChangeWindPtr->setSelected(false);
			mButtonSterilizationPtr->setSelected(false);
			mButtonYuBaPtr->setSelected(true);

			mWindowAirPFPtr->setVisible(false);
			mWindowAirSwitchPtr->setVisible(false);
			mWindowHotChangeSwitchPtr->setVisible(false);
			mWindowHumdSwitchPtr->setVisible(false);
			mWindowWindSwitchPtr->setVisible(false);
			mWindowYubaSwitchPtr->setVisible(true);
			mWindowSterilizationPtr->setVisible(false);
		}
			break;
		default:
			break;

	}
}

static bool onButtonClick_ButtonPurify(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonPurify !!!\n");
    ManualType = Manual_AirPF;
    ManualMode11SelStatus(ManualType);
    MACHINESTATUS->setmanualmode(ManualType);
    return false;
}

static bool onButtonClick_ButtonAir(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAir !!!\n");
    ManualType = Manual_Air;
    ManualMode11SelStatus(ManualType);
    MACHINESTATUS->setmanualmode(ManualType);
    return false;
}

static bool onButtonClick_ButtonHotChange(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHotChange !!!\n");
    ManualType = Manual_HotChange;
    ManualMode11SelStatus(ManualType);
    MACHINESTATUS->setmanualmode(ManualType);
    return false;
}

static bool onButtonClick_ButtonModHumd(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonModHumd !!!\n");
    ManualType = Manual_Humd;
    ManualMode11SelStatus(ManualType);
    MACHINESTATUS->setmanualmode(ManualType);
    return false;
}

static bool onButtonClick_ButtonChangeWind(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonChangeWind !!!\n");
    ManualType = Manual_WindChange;
    ManualMode11SelStatus(ManualType);
    MACHINESTATUS->setmanualmode(ManualType);
    return false;
}

static bool onButtonClick_ButtonSterilization(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonSterilization !!!\n");
    ManualType = Manual_Ster;
    ManualMode11SelStatus(ManualType);
    MACHINESTATUS->setmanualmode(ManualType);
    return false;
}

static bool onButtonClick_ButtonYuBa(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonYuBa !!!\n");
    ManualType = Manual_YuBa;
    ManualMode11SelStatus(ManualType);
    MACHINESTATUS->setmanualmode(ManualType);
    return false;
}

static bool onButtonClick_ButtonAirPFOpen(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirPFOpen !!!\n");
    if(pButton->isSelected())
    {
    	pButton->setSelected(false);
    }
    else
    {
    	pButton->setSelected(true);
    }
    return false;
}

static bool onButtonClick_ButtonAirPFSelect(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirPFSelect !!!\n");
    return false;
}

static bool onButtonClick_ButtonAirPFPicTime(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirPFPicTime !!!\n");
    if(mButtonAirPFOpenPtr->isSelected())
    {
    	EASYUICONTEXT->openActivity("AddTimeSettingActivity", NULL);
    }
    return false;
}

static bool onButtonClick_ButtonAirPFPicTimeOpen(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirPFPicTimeOpen !!!\n");
    if(mButtonAirPFOpenPtr->isSelected())
	{
		EASYUICONTEXT->openActivity("AddTimeSettingActivity", NULL);
	}
    return false;
}

static bool onButtonClick_ButtonAirPFAutoWind(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirPFAutoWind !!!\n");
    return false;
}

static bool onButtonClick_ButtonAirPFWindDirect(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirPFWindDirect !!!\n");
    return false;
}

static bool onButtonClick_ButtonAirPFHumdSetting(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirPFHumdSetting !!!\n");
    return false;
}

static bool onButtonClick_ButtonAirPFAutoWindLess(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirPFAutoWindLess !!!\n");
    return false;
}

static bool onButtonClick_ButtonAirPFAutoWindAdd(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirPFAutoWindAdd !!!\n");
    return false;
}

static bool onButtonClick_ButtonAirPFWindDirectLess(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirPFWindDirectLess !!!\n");
    return false;
}

static bool onButtonClick_ButtonAirPFWindDirectAdd(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirPFWindDirectAdd !!!\n");
    return false;
}

static bool onButtonClick_ButtonAirPFHumdSettingLess(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirPFHumdSettingLess !!!\n");
    return false;
}

static bool onButtonClick_ButtonAirPFHumdSettingAdd(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirPFHumdSettingAdd !!!\n");
    return false;
}

static bool onButtonClick_ButtonAirPFNANOEX(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirPFNANOEX !!!\n");
    return false;
}

static bool onButtonClick_ButtonAirPFLight(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirPFLight !!!\n");
    return false;
}

static bool onButtonClick_ButtonAirPFHumd(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirPFHumd !!!\n");
    return false;
}

static bool onButtonClick_ButtonAirPFFilterReset(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirPFFilterReset !!!\n");
    return false;
}

static bool onButtonClick_ButtonAirPFChildLock(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirPFChildLock !!!\n");
    return false;
}

static bool onButtonClick_ButtonAirSwitchOpen(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirSwitchOpen !!!\n");
    if(pButton->isSelected())
	{
		pButton->setSelected(false);
	}
	else
	{
		pButton->setSelected(true);
	}
    return false;
}

static bool onButtonClick_ButtonAirSwitchSelect(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirSwitchSelect !!!\n");
    return false;
}

static bool onButtonClick_ButtonAirSwitchPicTime(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirSwitchPicTime !!!\n");
    if(mButtonAirSwitchOpenPtr->isSelected())
	{
		EASYUICONTEXT->openActivity("AddTimeSettingActivity", NULL);
	}
    return false;
}

static bool onButtonClick_ButtonAirSwitchPicTimeOpen(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirSwitchPicTimeOpen !!!\n");
    if(mButtonAirSwitchOpenPtr->isSelected())
	{
		EASYUICONTEXT->openActivity("AddTimeSettingActivity", NULL);
	}
    return false;
}

static bool onButtonClick_ButtonAirSwitchAutoWind(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirSwitchAutoWind !!!\n");
    return false;
}

static bool onButtonClick_ButtonAirSwitchWindDirect(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirSwitchWindDirect !!!\n");
    return false;
}

static bool onButtonClick_ButtonAirSwitchMode(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirSwitchMode !!!\n");
    return false;
}

static bool onButtonClick_ButtonAirSwitchAutoWindLess(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirSwitchAutoWindLess !!!\n");
    return false;
}

static bool onButtonClick_ButtonAirSwitchAutoWindAdd(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirSwitchAutoWindAdd !!!\n");
    return false;
}

static bool onButtonClick_ButtonAirSwitchWindDirectUpDown(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirSwitchWindDirectUpDown !!!\n");
    return false;
}

static bool onButtonClick_ButtonAirSwitchNANOEX(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirSwitchNANOEX !!!\n");
    return false;
}

static bool onButtonClick_ButtonAirSwitchTempSetting(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirSwitchTempSetting !!!\n");
    return false;
}

static bool onButtonClick_ButtonAirSwitchWindDirectLeftRight(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirSwitchWindDirectLeftRight !!!\n");
    return false;
}

static bool onButtonClick_ButtonAirSwitchModeAuto(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirSwitchModeAuto !!!\n");
    return false;
}

static bool onButtonClick_ButtonAirSwitchModeHot(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirSwitchModeHot !!!\n");
    return false;
}

static bool onButtonClick_ButtonAirSwitchModeCold(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirSwitchModeCold !!!\n");
    return false;
}

static bool onButtonClick_ButtonAirSwitchModeHumd(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirSwitchModeHumd !!!\n");
    return false;
}

static bool onButtonClick_ButtonAirSwitchTempSettingLess(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirSwitchTempSettingLess !!!\n");
    return false;
}

static bool onButtonClick_ButtonAirSwitchTempSettingAdd(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirSwitchTempSettingAdd !!!\n");
    return false;
}

static bool onButtonClick_ButtonHotChangeSwitchOpen(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHotChangeSwitchOpen !!!\n");
    if(pButton->isSelected())
	{
		pButton->setSelected(false);
	}
	else
	{
		pButton->setSelected(true);
	}
    return false;
}

static bool onButtonClick_ButtonHotChangeSwitchSelect(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHotChangeSwitchSelect !!!\n");
    return false;
}

static bool onButtonClick_ButtonHotChangeSwitchPicTime(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHotChangeSwitchPicTime !!!\n");
    if(mButtonHotChangeSwitchOpenPtr->isSelected())
	{
		EASYUICONTEXT->openActivity("AddTimeSettingActivity", NULL);
	}
    return false;
}

static bool onButtonClick_ButtonHotChangeSwitchPicTimeOpen(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHotChangeSwitchPicTimeOpen !!!\n");
    if(mButtonHotChangeSwitchOpenPtr->isSelected())
	{
		EASYUICONTEXT->openActivity("AddTimeSettingActivity", NULL);
	}
    return false;
}

static bool onButtonClick_ButtonHotChangeSwitchAutoWind(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHotChangeSwitchAutoWind !!!\n");
    return false;
}

static bool onButtonClick_ButtonHotChangeSwitchMode(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHotChangeSwitchMode !!!\n");
    return false;
}

static bool onButtonClick_ButtonHotChangeSwitchAutoWindLess(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHotChangeSwitchAutoWindLess !!!\n");
    return false;
}

static bool onButtonClick_ButtonHotChangeSwitchAutoWindAdd(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHotChangeSwitchAutoWindAdd !!!\n");
    return false;
}

static bool onButtonClick_ButtonHotChangeSwitchModeAuto(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHotChangeSwitchModeAuto !!!\n");
    return false;
}

static bool onButtonClick_ButtonHotChangeSwitchNANOEX(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHotChangeSwitchNANOEX !!!\n");
    return false;
}

static bool onButtonClick_ButtonHotChangeSwitchModeHotChange(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHotChangeSwitchModeHotChange !!!\n");
    return false;
}

static bool onButtonClick_ButtonHotChangeSwitchModeCycle(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHotChangeSwitchModeCycle !!!\n");
    return false;
}

static bool onButtonClick_ButtonHumdSwitchOpen(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHumdSwitchOpen !!!\n");
    if(pButton->isSelected())
	{
		pButton->setSelected(false);
	}
	else
	{
		pButton->setSelected(true);
	}
    return false;
}

static bool onButtonClick_ButtonHumdSwitchSelect(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHumdSwitchSelect !!!\n");
    return false;
}

static bool onButtonClick_ButtonHumdSwitchPicTime(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHumdSwitchPicTime !!!\n");
    if(mButtonHumdSwitchOpenPtr->isSelected())
	{
		EASYUICONTEXT->openActivity("AddTimeSettingActivity", NULL);
	}
    return false;
}

static bool onButtonClick_ButtonHumdSwitchPicTimeOpen(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHumdSwitchPicTimeOpen !!!\n");
    if(mButtonHumdSwitchOpenPtr->isSelected())
	{
		EASYUICONTEXT->openActivity("AddTimeSettingActivity", NULL);
	}
    return false;
}

static bool onButtonClick_ButtonHumdSwitchAutoWind(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHumdSwitchAutoWind !!!\n");
    return false;
}

static bool onButtonClick_ButtonHumdSwitchWindDirect(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHumdSwitchWindDirect !!!\n");
    return false;
}

static bool onButtonClick_ButtonHumdSwitchHumdSetting(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHumdSwitchHumdSetting !!!\n");
    return false;
}

static bool onButtonClick_ButtonHumdSwitchAutoWindLess(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHumdSwitchAutoWindLess !!!\n");
    return false;
}

static bool onButtonClick_ButtonHumdSwitchAutoWindAdd(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHumdSwitchAutoWindAdd !!!\n");
    return false;
}

static bool onButtonClick_ButtonHumdSwitchWindDirectLess(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHumdSwitchWindDirectLess !!!\n");
    return false;
}

static bool onButtonClick_ButtonHumdSwitchWindDirectAdd(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHumdSwitchWindDirectAdd !!!\n");
    return false;
}

static bool onButtonClick_ButtonHumdSwitchHumdSettingLess(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHumdSwitchHumdSettingLess !!!\n");
    return false;
}

static bool onButtonClick_ButtonHumdSwitchHumdSettingAdd(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHumdSwitchHumdSettingAdd !!!\n");
    return false;
}

static bool onButtonClick_ButtonHumdSwitchFuncSel(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHumdSwitchFuncSel !!!\n");
    return false;
}

static bool onButtonClick_ButtonHumdSwitchWindClass(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHumdSwitchWindClass !!!\n");
    return false;
}

static bool onButtonClick_ButtonHumdSwitchFuncSelAuto(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHumdSwitchFuncSelAuto !!!\n");
    return false;
}

static bool onButtonClick_ButtonHumdSwitchFuncSelCont(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHumdSwitchFuncSelCont !!!\n");
    return false;
}

static bool onButtonClick_ButtonHumdSwitchFuncSelKeep(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHumdSwitchFuncSelKeep !!!\n");
    return false;
}

static bool onButtonClick_ButtonHumdSwitchFuncSelSend(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHumdSwitchFuncSelSend !!!\n");
    return false;
}

static bool onButtonClick_ButtonHumdSwitchWindClassConcen(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHumdSwitchWindClassConcen !!!\n");
    return false;
}

static bool onButtonClick_ButtonHumdSwitchWindClassDiff(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHumdSwitchWindClassDiff !!!\n");
    return false;
}

static bool onButtonClick_ButtonWindSwitchOpen(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonWindSwitchOpen !!!\n");
    if(pButton->isSelected())
	{
		pButton->setSelected(false);
	}
	else
	{
		pButton->setSelected(true);
	}
    return false;
}

static bool onButtonClick_ButtonWindSwitchSelect(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonWindSwitchSelect !!!\n");
    return false;
}

static bool onButtonClick_ButtonWindSwitchPicTime(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonWindSwitchPicTime !!!\n");
    if(mButtonWindSwitchOpenPtr->isSelected())
	{
		EASYUICONTEXT->openActivity("AddTimeSettingActivity", NULL);
	}
    return false;
}

static bool onButtonClick_ButtonWindSwitchPicTimeOpen(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonWindSwitchPicTimeOpen !!!\n");
    if(mButtonWindSwitchOpenPtr->isSelected())
	{
		EASYUICONTEXT->openActivity("AddTimeSettingActivity", NULL);
	}
    return false;
}

static bool onButtonClick_ButtonWindSwitchAutoWind(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonWindSwitchAutoWind !!!\n");
    return false;
}

static bool onButtonClick_ButtonWindSwitchAutoWindLess(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonWindSwitchAutoWindLess !!!\n");
    return false;
}

static bool onButtonClick_ButtonWindSwitchAutoWindAdd(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonWindSwitchAutoWindAdd !!!\n");
    return false;
}

static bool onButtonClick_ButtonWindSwitchNANOEX(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonWindSwitchNANOEX !!!\n");
    return false;
}

static bool onButtonClick_ButtonSterilizationOpen(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonSterilizationOpen !!!\n");
    if(pButton->isSelected())
	{
		pButton->setSelected(false);
	}
	else
	{
		pButton->setSelected(true);
	}
    return false;
}

static bool onButtonClick_ButtonSterilizationSelect(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonSterilizationSelect !!!\n");
    return false;
}

static bool onButtonClick_ButtonSterilizationPicTime(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonSterilizationPicTime !!!\n");
    if(mButtonSterilizationOpenPtr->isSelected())
   	{
   		EASYUICONTEXT->openActivity("AddTimeSettingActivity", NULL);
   	}
    return false;
}

static bool onButtonClick_ButtonSterilizationPicTimeOpen(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonSterilizationPicTimeOpen !!!\n");
    if(mButtonSterilizationOpenPtr->isSelected())
   	{
   		EASYUICONTEXT->openActivity("AddTimeSettingActivity", NULL);
   	}
    return false;
}

static bool onButtonClick_ButtonYuBaOpen(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonYuBaOpen !!!\n");
    if(pButton->isSelected())
	{
		pButton->setSelected(false);
	}
	else
	{
		pButton->setSelected(true);
	}
    return false;
}

static bool onButtonClick_ButtonYuBaSelect(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonYuBaSelect !!!\n");
    return false;
}

static bool onButtonClick_ButtonYuBaPicTime(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonYuBaPicTime !!!\n");
    if(mButtonYuBaOpenPtr->isSelected())
	{
		EASYUICONTEXT->openActivity("AddTimeSettingActivity", NULL);
	}
    return false;
}

static bool onButtonClick_ButtonYuBaTimeOpen(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonYuBaTimeOpen !!!\n");
    if(mButtonYuBaOpenPtr->isSelected())
	{
		EASYUICONTEXT->openActivity("AddTimeSettingActivity", NULL);
	}
    return false;
}

static bool onButtonClick_ButtonYuBaHeating(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonYuBaHeating !!!\n");
    return false;
}

static bool onButtonClick_ButtonYuBaWindDirect(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonYuBaWindDirect !!!\n");
    return false;
}

static bool onButtonClick_ButtonYuBaHotting(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonYuBaHotting !!!\n");
    return false;
}

static bool onButtonClick_ButtonYuBaNANOEX(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonYuBaNANOEX !!!\n");
    return false;
}

static bool onButtonClick_ButtonYuBaWindClass(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonYuBaWindClass !!!\n");
    return false;
}

static bool onButtonClick_ButtonYuBaColdHot(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonYuBaColdHot !!!\n");
    return false;
}

static bool onButtonClick_ButtonYuBaChangAir(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonYuBaChangAir !!!\n");
    return false;
}

static bool onButtonClick_ButtonYuBaLight(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonYuBaLight !!!\n");
    return false;
}

static bool onButtonClick_ButtonYuBaHeatingStr(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonYuBaHeatingStr !!!\n");
    return false;
}

static bool onButtonClick_ButtonYuBaHeatingWeak(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonYuBaHeatingWeak !!!\n");
    return false;
}

static bool onButtonClick_ButtonYuBaWindDirectManual(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonYuBaWindDirectManual !!!\n");
    return false;
}

static bool onButtonClick_ButtonYuBaWindDirectAuto(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonYuBaWindDirectAuto !!!\n");
    return false;
}

static bool onButtonClick_ButtonYuBaHottingStr(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonYuBaHottingStr !!!\n");
    return false;
}

static bool onButtonClick_ButtonYuBaHottingWeak(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonYuBaHottingWeak !!!\n");
    return false;
}

static bool onButtonClick_ButtonYuBaWindClassConcen(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonYuBaWindClassConcen !!!\n");
    return false;
}

static bool onButtonClick_ButtonYuBaColdHotStr(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonYuBaColdHotStr !!!\n");
    return false;
}

static bool onButtonClick_ButtonYuBaWindClassdiffusion(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonYuBaWindClassdiffusion !!!\n");
    return false;
}

static bool onButtonClick_ButtonYuBaColdHotWeak(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonYuBaColdHotWeak !!!\n");
    return false;
}

static bool onButtonClick_ButtonYuBaLightStr(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonYuBaLightStr !!!\n");
    return false;
}

static bool onButtonClick_ButtonYuBaLightWeak(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonYuBaLightWeak !!!\n");
    return false;
}

static bool onButtonClick_ButtonYuBaLightNight(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonYuBaLightNight !!!\n");
    return false;
}

static bool onButtonClick_ButtonYuBaLightClose(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonYuBaLightClose !!!\n");
    return false;
}

static bool onButtonClick_ButtonYuBaChangAirFast(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonYuBaChangAirFast !!!\n");
    return false;
}

static bool onButtonClick_ButtonYuBaChangAirStr(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonYuBaChangAirStr !!!\n");
    return false;
}

static bool onButtonClick_ButtonYuBaChangAirWeak(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonYuBaChangAirWeak !!!\n");
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

