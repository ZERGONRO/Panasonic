#pragma once
#include "uart/ProtocolSender.h"
#include "util/MachineStatus.h"
#include "util/ProtocolDataRecv.h"
#include "util/ProtocolDataSend.h"
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

static std::vector<std::string > AirPFListViewVector, AirListViewVector, HumdListViewVector, WindListViewVector, HotListViewVector, YuBaListViewVector,SterlListViewVector;
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

void VectorInit()
{
	AirPFListViewVector.push_back("F-PMX03XL");
	AirPFListViewVector.push_back("F-PMX12XLL");
	AirPFListViewVector.push_back("F-PMX23XXXL");
	AirPFListViewVector.push_back("F-PMX06XXLL");
	AirPFListViewVector.push_back("F-PMX15SXLM");

	AirListViewVector.push_back("A-NEX3233");
	AirListViewVector.push_back("A-NEX5499");
	AirListViewVector.push_back("A-NEX8011");

	HumdListViewVector.push_back("H-PLC5X3C");
	HumdListViewVector.push_back("H-PLC5X60");
	HumdListViewVector.push_back("H-PLC5X83");
	HumdListViewVector.push_back("H-PLC5X61");

	WindListViewVector.push_back("W-MDU873X");
	WindListViewVector.push_back("W-MDU622X");
	WindListViewVector.push_back("W-MDU105X");

	HotListViewVector.push_back("HT-YL5023");
	HotListViewVector.push_back("HT-YL4170");
	HotListViewVector.push_back("HT-YL9096");

	YuBaListViewVector.push_back("YB-LW6000");
	YuBaListViewVector.push_back("YB-LW8550");
	YuBaListViewVector.push_back("YB-LW9800");
	YuBaListViewVector.push_back("YB-LW1200");

	SterlListViewVector.push_back("S-VV3070");
	SterlListViewVector.push_back("S-VV1660");
	SterlListViewVector.push_back("S-VV2080");
}

void ManualMode11SelStatus(int index);
/**
 * 当界面构造时触发
 */
static void onUI_init(){
    //Tips :添加 UI初始化的显示代码到这里,如:mText1Ptr->setText("123");
	VectorInit();

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

static void ManualModeRecvDataUpdate(const SProtocolRecvDate &Data)
{
	SProtocolRecvDate data = Data;
	if(data.PurifyData.Switch)							//净化
	{
		mTextView17Ptr->setText(data.PurifyData.WindDirectSetting + '°');
		mTextView18Ptr->setText(data.PurifyData.AddHumdSetting + '%');
		mButtonAirPFNANOEXPtr->setSelected(data.PurifyData.NanoexSetting);
		mButtonAirPFLightPtr->setSelected(data.PurifyData.BrightSetting);
		mButtonAirPFFilterResetPtr->setSelected(data.PurifyData.FilterReset);
		mButtonAirPFChildLockPtr->setSelected(data.PurifyData.ChildLock);
	}


	if(data.AirConditionData.Swtich)					//空调
	{
		if(data.AirConditionData.WindDirectSetting)
		{
			mButtonAirSwitchWindDirectUpDownPtr->setSelected(false);
			mButtonAirSwitchWindDirectLeftRightPtr->setSelected(true);
		}
		else
		{
			mButtonAirSwitchWindDirectUpDownPtr->setSelected(true);
			mButtonAirSwitchWindDirectLeftRightPtr->setSelected(false);
		}

		if(data.AirConditionData.ModeSelect == 1)
		{
			mButtonAirSwitchModeAutoPtr->setSelected(false);
			mButtonAirSwitchModeHotPtr->setSelected(true);
			mButtonAirSwitchModeColdPtr->setSelected(false);
			mButtonAirSwitchModeHumdPtr->setSelected(false);
		}
		else if(data.AirConditionData.ModeSelect == 2)
		{
			mButtonAirSwitchModeAutoPtr->setSelected(false);
			mButtonAirSwitchModeHotPtr->setSelected(false);
			mButtonAirSwitchModeColdPtr->setSelected(true);
			mButtonAirSwitchModeHumdPtr->setSelected(false);
		}
		else if(data.AirConditionData.ModeSelect == 3)
		{
			mButtonAirSwitchModeAutoPtr->setSelected(false);
			mButtonAirSwitchModeHotPtr->setSelected(false);
			mButtonAirSwitchModeColdPtr->setSelected(false);
			mButtonAirSwitchModeHumdPtr->setSelected(true);
		}
		else
		{
			mButtonAirSwitchModeAutoPtr->setSelected(true);
			mButtonAirSwitchModeHotPtr->setSelected(false);
			mButtonAirSwitchModeColdPtr->setSelected(false);
			mButtonAirSwitchModeHumdPtr->setSelected(false);
		}

		mTextView22Ptr->setText(data.AirConditionData.TempSettingValue + '℃');
		mButtonAirSwitchNANOEXPtr->setSelected(data.AirConditionData.NanoeX);
	}

	if(data.HeatChangeData.Swtich)							//热交换
	{
		if(data.HeatChangeData.ModeSetting == 1)
		{
			mButtonHotChangeSwitchModeAutoPtr->setSelected(false);
			mButtonHotChangeSwitchModeHotChangePtr->setSelected(true);
			mButtonHotChangeSwitchModeCyclePtr->setSelected(false);
		}
		else if(data.HeatChangeData.ModeSetting == 2)
		{
			mButtonHotChangeSwitchModeAutoPtr->setSelected(false);
			mButtonHotChangeSwitchModeHotChangePtr->setSelected(false);
			mButtonHotChangeSwitchModeCyclePtr->setSelected(true);
		}
		else
		{
			mButtonHotChangeSwitchModeAutoPtr->setSelected(true);
			mButtonHotChangeSwitchModeHotChangePtr->setSelected(false);
			mButtonHotChangeSwitchModeCyclePtr->setSelected(false);
		}

		mButtonHotChangeSwitchNANOEXPtr->setSelected(data.HeatChangeData.NanoeX);

	}


	if(data.AdjustHumdData.Swtich)							//调湿
	{
		mTextView29Ptr->setText(data.AdjustHumdData.AirDirectSetting + '°');
		mTextView30Ptr->setText(data.AdjustHumdData.AdjustHumdValue + '%');
		if(data.AdjustHumdData.FunctionSelectSetting == 1)
		{
			mButtonHumdSwitchFuncSelAutoPtr->setSelected(false);
			mButtonHumdSwitchFuncSelContPtr->setSelected(true);
			mButtonHumdSwitchFuncSelKeepPtr->setSelected(false);
			mButtonHumdSwitchFuncSelSendPtr->setSelected(false);
		}
		else if(data.AdjustHumdData.FunctionSelectSetting == 2)
		{
			mButtonHumdSwitchFuncSelAutoPtr->setSelected(false);
			mButtonHumdSwitchFuncSelContPtr->setSelected(false);
			mButtonHumdSwitchFuncSelKeepPtr->setSelected(true);
			mButtonHumdSwitchFuncSelSendPtr->setSelected(false);
		}
		else if(data.AdjustHumdData.FunctionSelectSetting == 3)
		{
			mButtonHumdSwitchFuncSelAutoPtr->setSelected(false);
			mButtonHumdSwitchFuncSelContPtr->setSelected(false);
			mButtonHumdSwitchFuncSelKeepPtr->setSelected(false);
			mButtonHumdSwitchFuncSelSendPtr->setSelected(true);
		}
		else
		{
			mButtonHumdSwitchFuncSelAutoPtr->setSelected(true);
			mButtonHumdSwitchFuncSelContPtr->setSelected(false);
			mButtonHumdSwitchFuncSelKeepPtr->setSelected(false);
			mButtonHumdSwitchFuncSelSendPtr->setSelected(false);
		}

//		if(data.AdjustHumdData.)

	}

	if(data.WindChangAirData.Swtich)							//新风
	{
		mButtonWindSwitchNANOEXPtr->setSelected(data.WindChangAirData.NanoeX);
	}

	if(data.YuBaData.Swtich)									//浴霸
	{
		mButtonYuBaNANOEXPtr->setSelected(data.YuBaData.NanoeX);

		if(data.YuBaData.HeatingSetting)
		{
			mButtonYuBaHeatingStrPtr->setSelected(false);
			mButtonYuBaHeatingWeakPtr->setSelected(true);
		}
		else
		{
			mButtonYuBaHeatingStrPtr->setSelected(true);
			mButtonYuBaHeatingWeakPtr->setSelected(false);
		}

		if(data.YuBaData.AirDirectSetting)
		{
			mButtonYuBaWindDirectManualPtr->setSelected(false);
			mButtonYuBaWindDirectAutoPtr->setSelected(true);
		}
		else
		{
			mButtonYuBaWindDirectManualPtr->setSelected(true);
			mButtonYuBaWindDirectAutoPtr->setSelected(false);
		}

		if(data.YuBaData.HeatDrySetting)
		{
			mButtonYuBaHottingStrPtr->setSelected(false);
			mButtonYuBaHottingWeakPtr->setSelected(true);
		}
		else
		{
			mButtonYuBaHottingStrPtr->setSelected(true);
			mButtonYuBaHottingWeakPtr->setSelected(false);
		}

		if(data.YuBaData.ColdDrySetting)
		{
			mButtonYuBaColdHotStrPtr->setSelected(false);
			mButtonYuBaColdHotWeakPtr->setSelected(true);
		}
		else
		{
			mButtonYuBaColdHotStrPtr->setSelected(true);
			mButtonYuBaColdHotWeakPtr->setSelected(false);
		}

		if(data.YuBaData.WindType)
		{
			mButtonYuBaWindClassConcenPtr->setSelected(false);
			mButtonYuBaWindClassdiffusionPtr->setSelected(true);
		}
		else
		{
			mButtonYuBaWindClassConcenPtr->setSelected(true);
			mButtonYuBaWindClassdiffusionPtr->setSelected(false);
		}

		if(data.YuBaData.AirChangeSetting == 1)
		{
			mButtonYuBaChangAirFastPtr->setSelected(false);
			mButtonYuBaChangAirStrPtr->setSelected(true);
			mButtonYuBaChangAirWeakPtr->setSelected(false);
		}
		else if(data.YuBaData.AirChangeSetting == 2)
		{
			mButtonYuBaChangAirFastPtr->setSelected(false);
			mButtonYuBaChangAirStrPtr->setSelected(false);
			mButtonYuBaChangAirWeakPtr->setSelected(true);
		}
		else
		{
			mButtonYuBaChangAirFastPtr->setSelected(true);
			mButtonYuBaChangAirStrPtr->setSelected(false);
			mButtonYuBaChangAirWeakPtr->setSelected(false);
		}

		if(data.YuBaData.BrightnessSetting)
		{

		}
		else
		{

		}

	}

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


static bool onButtonClick_ButtonAirPFSelect(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirPFSelect !!!\n");
    if (pButton->isSelected()){
    	pButton->setSelected(false);
    	mListViewAirPFPtr->setVisible(false);
    }else{
    	pButton->setSelected(true);
    	mListViewAirPFPtr->setVisible(true);
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


static bool onButtonClick_ButtonAirSwitchSelect(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirSwitchSelect !!!\n");
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


static bool onButtonClick_ButtonHotChangeSwitchSelect(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHotChangeSwitchSelect !!!\n");
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


static bool onButtonClick_ButtonHumdSwitchSelect(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHumdSwitchSelect !!!\n");
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

static bool onButtonClick_ButtonWindSwitchSelect(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonWindSwitchSelect !!!\n");
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


static bool onButtonClick_ButtonSterilizationSelect(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonSterilizationSelect !!!\n");
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

static bool onButtonClick_ButtonDropDown(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonDropDown !!!\n");
    return false;
}
static bool onButtonClick_Button1(ZKButton *pButton) {
    LOGD(" ButtonClick Button1 !!!\n");
    return false;
}

static bool onButtonClick_Button2(ZKButton *pButton) {
    LOGD(" ButtonClick Button2 !!!\n");
    if (pButton->isSelected()){
		pButton->setSelected(false);
		mListViewAirPtr->setVisible(false);
	}else{
		pButton->setSelected(true);
		mListViewAirPtr->setVisible(true);
	}
    return false;
}

static bool onButtonClick_Button3(ZKButton *pButton) {
    LOGD(" ButtonClick Button3 !!!\n");
    return false;
}

static bool onButtonClick_Button4(ZKButton *pButton) {
    LOGD(" ButtonClick Button4 !!!\n");
    return false;
}

static bool onButtonClick_Button5(ZKButton *pButton) {
    LOGD(" ButtonClick Button5 !!!\n");
    return false;
}

static bool onButtonClick_Button6(ZKButton *pButton) {
    LOGD(" ButtonClick Button6 !!!\n");
    if (pButton->isSelected()){
   		pButton->setSelected(false);
   		mListViewHotPtr->setVisible(false);
   	}else{
   		pButton->setSelected(true);
   		mListViewHotPtr->setVisible(true);
   	}
    return false;
}

static bool onButtonClick_Button7(ZKButton *pButton) {
    LOGD(" ButtonClick Button7 !!!\n");
    return false;
}

static bool onButtonClick_Button8(ZKButton *pButton) {
    LOGD(" ButtonClick Button8 !!!\n");
    return false;
}

static bool onButtonClick_Button9(ZKButton *pButton) {
    LOGD(" ButtonClick Button9 !!!\n");
    return false;
}

static bool onButtonClick_Button10(ZKButton *pButton) {
    LOGD(" ButtonClick Button10 !!!\n");
    if (pButton->isSelected()){
		pButton->setSelected(false);
		mListViewHumdPtr->setVisible(false);
	}else{
		pButton->setSelected(true);
		mListViewHumdPtr->setVisible(true);
	}
    return false;
}

static bool onButtonClick_Button11(ZKButton *pButton) {
    LOGD(" ButtonClick Button11 !!!\n");
    return false;
}

static bool onButtonClick_Button12(ZKButton *pButton) {
    LOGD(" ButtonClick Button12 !!!\n");
    return false;
}

static bool onButtonClick_Button13(ZKButton *pButton) {
    LOGD(" ButtonClick Button13 !!!\n");
    return false;
}

static bool onButtonClick_Button14(ZKButton *pButton) {
    LOGD(" ButtonClick Button14 !!!\n");
    if (pButton->isSelected()){
		pButton->setSelected(false);
		mListViewWindPtr->setVisible(false);
	}else{
		pButton->setSelected(true);
		mListViewWindPtr->setVisible(true);
	}
    return false;
}

static bool onButtonClick_Button15(ZKButton *pButton) {
    LOGD(" ButtonClick Button15 !!!\n");
    return false;
}

static bool onButtonClick_Button16(ZKButton *pButton) {
    LOGD(" ButtonClick Button16 !!!\n");
    return false;
}

static bool onButtonClick_Button17(ZKButton *pButton) {
    LOGD(" ButtonClick Button17 !!!\n");
    return false;
}

static bool onButtonClick_Button18(ZKButton *pButton) {
    LOGD(" ButtonClick Button18 !!!\n");
    if (pButton->isSelected()){
  		pButton->setSelected(false);
  		mListViewSterlPtr->setVisible(false);
  	}else{
  		pButton->setSelected(true);
  		mListViewSterlPtr->setVisible(true);
  	}
    return false;
}

static bool onButtonClick_Button19(ZKButton *pButton) {
    LOGD(" ButtonClick Button19 !!!\n");
    return false;
}

static bool onButtonClick_Button20(ZKButton *pButton) {
    LOGD(" ButtonClick Button20 !!!\n");
    return false;
}

static bool onButtonClick_Button21(ZKButton *pButton) {
    LOGD(" ButtonClick Button21 !!!\n");
    return false;
}

static bool onButtonClick_Button22(ZKButton *pButton) {
    LOGD(" ButtonClick Button22 !!!\n");
    if (pButton->isSelected()){
		pButton->setSelected(false);
		mListViewYuBaPtr->setVisible(false);
	}else{
		pButton->setSelected(true);
		mListViewYuBaPtr->setVisible(true);
	}
    return false;
}

static bool onButtonClick_Button23(ZKButton *pButton) {
    LOGD(" ButtonClick Button23 !!!\n");
    return false;
}

static bool onButtonClick_Button24(ZKButton *pButton) {
    LOGD(" ButtonClick Button24 !!!\n");
    return false;
}
static bool onButtonClick_ButtonAirPFSwitch(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirPFSwitch !!!\n");
    return false;
}

static bool onButtonClick_ButtonAirPFTimeSwitchPic(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirPFTimeSwitchPic !!!\n");
    Intent* intent = new Intent();
	intent->putExtra("DeviceName", mButtonPurifyPtr->getText());
    EASYUICONTEXT->openActivity("TimingActivity", intent);
    return false;
}

static bool onButtonClick_ButtonAirPFTimeSwitch(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirPFTimeSwitch !!!\n");
    return false;
}

static bool onButtonClick_ButtonAirSwitch(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirSwitch !!!\n");
    return false;
}

static bool onButtonClick_ButtonAirTimeSwitchPic(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirTimeSwitchPic !!!\n");
    Intent* intent = new Intent();
   	intent->putExtra("DeviceName", mButtonAirPtr->getText());
   	EASYUICONTEXT->openActivity("TimingActivity", intent);
    return false;
}

static bool onButtonClick_ButtonAirTimeSwitch(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirTimeSwitch !!!\n");
    return false;
}

static bool onButtonClick_ButtonHotChangeSwitchOpen(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHotChangeSwitchOpen !!!\n");
    return false;
}

static bool onButtonClick_ButtonHotChangeSwitchPicTime(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHotChangeSwitchPicTime !!!\n");
    return false;
}

static bool onButtonClick_ButtonHotChangeSwitchPicTimeOpen(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHotChangeSwitchPicTimeOpen !!!\n");
    return false;
}

static bool onButtonClick_ButtonHotCSwitch(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHotCSwitch !!!\n");
    return false;
}

static bool onButtonClick_ButtonHotCTimeSwitchPic(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHotCTimeSwitchPic !!!\n");
    Intent* intent = new Intent();
	intent->putExtra("DeviceName", mButtonHotChangePtr->getText());
	EASYUICONTEXT->openActivity("TimingActivity", intent);
    return false;
}

static bool onButtonClick_ButtonHotCTimeSwitch(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHotCTimeSwitch !!!\n");
    return false;
}

static bool onButtonClick_ButtonHumdSwitch(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHumdSwitch !!!\n");
    return false;
}

static bool onButtonClick_ButtonHumdTimeSwitchPic(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHumdTimeSwitchPic !!!\n");
    Intent* intent = new Intent();
  	intent->putExtra("DeviceName", mButtonModHumdPtr->getText());
  	EASYUICONTEXT->openActivity("TimingActivity", intent);
    return false;
}

static bool onButtonClick_ButtonHumdTimeSwitch(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHumdTimeSwitch !!!\n");
    return false;
}

static bool onButtonClick_ButtonWindSwitch(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonWindSwitch !!!\n");
    return false;
}

static bool onButtonClick_ButtonWindTimeSwitchPic(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonWindTimeSwitchPic !!!\n");
    Intent* intent = new Intent();
	intent->putExtra("DeviceName", mButtonChangeWindPtr->getText());
	EASYUICONTEXT->openActivity("TimingActivity", intent);
    return false;
}

static bool onButtonClick_ButtonWindTimeSwitch(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonWindTimeSwitch !!!\n");
    return false;
}

static bool onButtonClick_ButtonSterilizationSwitch(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonSterilizationSwitch !!!\n");
    return false;
}

static bool onButtonClick_ButtonSteriTimeSwitchPic(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonSteriTimeSwitchPic !!!\n");
    Intent* intent = new Intent();
   	intent->putExtra("DeviceName", mButtonSterilizationPtr->getText());
   	EASYUICONTEXT->openActivity("TimingActivity", intent);
    return false;
}

static bool onButtonClick_ButtonSteriTimeSwitch(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonSteriTimeSwitch !!!\n");
    return false;
}

static bool onButtonClick_ButtonYubaSwitch(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonYubaSwitch !!!\n");
    return false;
}

static bool onButtonClick_ButtonPicTime(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonPicTime !!!\n");
    Intent* intent = new Intent();
	intent->putExtra("DeviceName", mButtonYuBaPtr->getText());
	EASYUICONTEXT->openActivity("TimingActivity", intent);
    return false;
}

static bool onButtonClick_ButtonTiming(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonTiming !!!\n");
    return false;
}
static int getListItemCount_ListViewAirPF(const ZKListView *pListView) {
    //LOGD("getListItemCount_ListViewAirPF !\n");
    return AirPFListViewVector.size();
}

static void obtainListItemData_ListViewAirPF(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListViewAirPF  !!!\n");
	ZKListView::ZKListSubItem* psubButtonAirPFText = pListItem->findSubItemByID(ID_MANUALMODE11_SubItemAirPF);
	std::string tmp = AirPFListViewVector.at(index);
	psubButtonAirPFText->setText(tmp);
}

static void onListItemClick_ListViewAirPF(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListViewAirPF  !!!\n");
	std::string tmp = AirPFListViewVector.at(index);
	mTextView37Ptr->setText(tmp);
	mListViewAirPFPtr->setVisible(false);
}
static int getListItemCount_ListViewAir(const ZKListView *pListView) {
    //LOGD("getListItemCount_ListViewAir !\n");
    return AirListViewVector.size();
}

static void obtainListItemData_ListViewAir(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListViewAir  !!!\n");
	ZKListView::ZKListSubItem* psubButtonAirText = pListItem->findSubItemByID(ID_MANUALMODE11_SubItemAir);
	std::string tmp = AirListViewVector.at(index);
	psubButtonAirText->setText(tmp);
}

static void onListItemClick_ListViewAir(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListViewAir  !!!\n");
	std::string tmp = AirListViewVector.at(index);
	mTextView38Ptr->setText(tmp);
	mListViewAirPtr->setVisible(false);
}

static int getListItemCount_ListViewHot(const ZKListView *pListView) {
    //LOGD("getListItemCount_ListViewHot !\n");
    return HotListViewVector.size();
}

static void obtainListItemData_ListViewHot(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListViewHot  !!!\n");
	ZKListView::ZKListSubItem* psubButtonHotText = pListItem->findSubItemByID(ID_MANUALMODE11_SubItemHot);
	std::string tmp = HotListViewVector.at(index);
	psubButtonHotText->setText(tmp);
}

static void onListItemClick_ListViewHot(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListViewHot  !!!\n");
	std::string tmp = HotListViewVector.at(index);
	mTextView39Ptr->setText(tmp);
	mListViewHotPtr->setVisible(false);
}

static int getListItemCount_ListViewHumd(const ZKListView *pListView) {
    //LOGD("getListItemCount_ListViewHumd !\n");
    return HumdListViewVector.size();
}

static void obtainListItemData_ListViewHumd(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListViewHumd  !!!\n");
	ZKListView::ZKListSubItem* psubButtonHumdText = pListItem->findSubItemByID(ID_MANUALMODE11_SubItemHumd);
	std::string tmp = HumdListViewVector.at(index);
	psubButtonHumdText->setText(tmp);
}

static void onListItemClick_ListViewHumd(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListViewHumd  !!!\n");
	std::string tmp = HumdListViewVector.at(index);
	mTextView90Ptr->setText(tmp);
	mListViewHumdPtr->setVisible(false);
}

static int getListItemCount_ListViewWind(const ZKListView *pListView) {
    //LOGD("getListItemCount_ListViewWind !\n");
    return WindListViewVector.size();
}

static void obtainListItemData_ListViewWind(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListViewWind  !!!\n");
	ZKListView::ZKListSubItem* psubButtonWindText = pListItem->findSubItemByID(ID_MANUALMODE11_SubItemWind);
	std::string tmp = WindListViewVector.at(index);
	psubButtonWindText->setText(tmp);
}

static void onListItemClick_ListViewWind(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListViewWind  !!!\n");
	std::string tmp = WindListViewVector.at(index);
	mTextView91Ptr->setText(tmp);
	mListViewWindPtr->setVisible(false);
}

static int getListItemCount_ListViewSterl(const ZKListView *pListView) {
    //LOGD("getListItemCount_ListViewSterl !\n");
    return SterlListViewVector.size();
}

static void obtainListItemData_ListViewSterl(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListViewSterl  !!!\n");
	ZKListView::ZKListSubItem* psubButtonSterlText = pListItem->findSubItemByID(ID_MANUALMODE11_SubItemSterl);
	std::string tmp = SterlListViewVector.at(index);
	psubButtonSterlText->setText(tmp);
}

static void onListItemClick_ListViewSterl(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListViewSterl  !!!\n");
	std::string tmp = SterlListViewVector.at(index);
	mTextView92Ptr->setText(tmp);
	mListViewSterlPtr->setVisible(false);
}

static int getListItemCount_ListViewYuBa(const ZKListView *pListView) {
    //LOGD("getListItemCount_ListViewYuBa !\n");
    return YuBaListViewVector.size();
}

static void obtainListItemData_ListViewYuBa(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListViewYuBa  !!!\n");
	ZKListView::ZKListSubItem* psubButtonYuBaText = pListItem->findSubItemByID(ID_MANUALMODE11_SubItemYuBa);
	std::string tmp = YuBaListViewVector.at(index);
	psubButtonYuBaText->setText(tmp);
}

static void onListItemClick_ListViewYuBa(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListViewYuBa  !!!\n");
	std::string tmp = YuBaListViewVector.at(index);
	mTextView93Ptr->setText(tmp);
	mListViewYuBaPtr->setVisible(false);
}
