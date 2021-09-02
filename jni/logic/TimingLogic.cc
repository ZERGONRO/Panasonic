#pragma once
#include "uart/ProtocolSender.h"
#include "util/MachineStatus.h"
#include "util/ManualStatusListence.h"
#include "util/SoftwareTimer.h"
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

int DeviceID;
static char Weekname[16];
static bool Flag_Switch = false;
static bool Flag_Settiming = false;
static Mutex sLock;
//static EquipmentTiming *DevTime_Setting;
static EquipmentTiming *EqpTSet_t = NULL;
static EqpTimeData *tmpEqpTmer_Data = NULL;
//static EqpTimeData *EqpTime_Date = MACHINESTATUS->getEqpTimeData();
SoftwareTimerListener *SWTListence = NULL;
extern bool Flag_EquipmentTimeSetting;
extern void disableStatusbus();

//static char week[8][4] = {"每天", "周一", "周二", "周三", "周四", "周五", "周六", "周日"};
/**
 * 注册定时器
 * 填充数组用于注册定时器
 * 注意：id不能重复
 */
static S_ACTIVITY_TIMEER REGISTER_ACTIVITY_TIMER_TAB[] = {
	//{0,  6000}, //定时器id=0, 时间间隔6秒
	{1,  300},
};

void UpdateTimeSettingFunc();

char *Week_String2char(int index){
	if (index == 8){
		strcpy(Weekname, "每天");
	}else if (index == 1){
		strcpy(Weekname, "周一");
	}else if (index == 2){
		strcpy(Weekname, "周二");
	}else if (index == 3){
		strcpy(Weekname, "周三");
	}else if (index == 4){
		strcpy(Weekname, "周四");
	}else if (index == 5){
		strcpy(Weekname, "周五");
	}else if (index == 6){
		strcpy(Weekname, "周六");
	}else if (index == 7){
		strcpy(Weekname, "周日");
	}
	return Weekname;
}

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
	disableStatusbus();

//	LOGD("init1\n");
}

void DispEqpTimeData(int DevID){
	Mutex::Autolock _l(sLock);
	int StartLeft = 0;
	int num1, num2, num3, num4;
	char Timebuf[64];
	LayoutPosition lp, lp1;
	bool Flag_EqpTimer = false;
//	LOGD("init2\n");
	EquipmentTiming *EqpTSet = new EquipmentTiming;
//	EquipmentTiming *EqpTSet = (EquipmentTiming *)malloc(sizeof(EquipmentTiming));//EqpTSet_t;
	//EqpTSet = NULL;
	LOGD("MACHINESTATUS getEqpTimeData size is %d\n", MACHINESTATUS->getEqpTimeData().size());
//		std::vector<EqpTimeData *>::iterator tmpEqpTimer = MACHINESTATUS->getEqpTimeData().begin();
//		for (;tmpEqpTimer != MACHINESTATUS->getEqpTimeData().end();tmpEqpTimer++){
		for(int i = 0;i < (int)MACHINESTATUS->getEqpTimeData().size();i++){
			EqpTimeData *tmp = MACHINESTATUS->getEqpTimeData().at(i);
			if (tmp->DeviceID == DevID){
				Flag_EqpTimer = true;
				LOGD("copy the recorded data to show\n");
//				EqpTSet = (*tmpEqpTimer)->DeviceData;
				memcpy(EqpTSet, tmp->DeviceData, sizeof(EquipmentTiming));
				break;
			}
		}

		if (!Flag_EqpTimer){
			LOGD("Flag_EqpTimer is false\n");
//			free(EqpTSet);
			delete(EqpTSet);
			EqpTSet = NULL;
			return;
		}


		//显示对应设备定时的相关数据
		if (EqpTSet->DeviceSwitch){
			mButton6Ptr->setSelected(true);
			mButton2Ptr->setSelected(true);
			mWindowTimeWavePtr->setBackgroundColor(0);
		}else{
			mButton6Ptr->setSelected(false);
			mButton2Ptr->setSelected(false);
			mWindowTimeWavePtr->setBackgroundColor(0x22252525);
		}

		for (int i = 0;EqpTSet->weekbuf[i] != 0;i++){
			int text = EqpTSet->weekbuf[i];
	//		mTextViewPtr[index]->setVisible(true);
			lp = mTextViewPtr[i]->getPosition();
			lp.mLeft = StartLeft;
			lp.mTop = 10;
			mTextViewPtr[i]->setPosition(lp);
			mTextViewPtr[i]->setText(std::string(Week_String2char(text)).c_str());
			StartLeft += 66;
		}
		if (EqpTSet->Time1StageFlag){
			num1 = EqpTSet->TimeOpenValue1 / 60;
			num2 = EqpTSet->TimeOpenValue1 % 60;
			sprintf(Timebuf, "%02d:%02d", num1, num2);
			mTextView13Ptr->setText(Timebuf);

			num3 = EqpTSet->TimeCloseValue1 / 60;
			num4 = EqpTSet->TimeCloseValue1 % 60;
			sprintf(Timebuf, "%02d:%02d", num3, num4);
			mTextView14Ptr->setText(Timebuf);
			mTextView15Ptr->setText(std::to_string(EqpTSet->TempSettingValue1) + "℃");
			mWindowAirHum1Ptr->setBackgroundColor(0);

			mTextViewStage1ColorFillPtr->setText(mTextView15Ptr->getText().c_str());
			int RemainTime = EqpTSet->TimeCloseValue1 - EqpTSet->TimeOpenValue1;
			lp1 = mTextViewStage1ColorFillPtr->getPosition();
			lp1.mLeft = 427 + (num1 * 33) + (num2 * 16 / 30);
			lp1.mWidth = (RemainTime / 60) * 33 + ((RemainTime % 60) / 30) * 16;
			lp1.mTop = 46;
			mTextViewStage1ColorFillPtr->setPosition(lp1);
			mTextViewStage1ColorFillPtr->setBackgroundColor(0xFFFF8000);
		}else{
			mTextViewStage1ColorFillPtr->setBackgroundColor(0);
			mWindowAirHum1Ptr->setBackgroundColor(0xFFD6D6D6);
		}

		if (EqpTSet->Time2StageFlag){
			num1 = EqpTSet->TimeOpenValue2 / 60;
			num2 = EqpTSet->TimeOpenValue2 % 60;
			sprintf(Timebuf, "%02d:%02d", num1, num2);
			mTextView23Ptr->setText(Timebuf);

			num3 = EqpTSet->TimeCloseValue2 / 60;
			num4 = EqpTSet->TimeCloseValue2 % 60;
			sprintf(Timebuf, "%02d:%02d", num3, num4);
			mTextView24Ptr->setText(Timebuf);
			mTextView25Ptr->setText(std::to_string(EqpTSet->TempSettingValue2) + "℃");
			mWindowAirHum2Ptr->setBackgroundColor(0);

			mTextViewStage2ColorFillPtr->setText(mTextView25Ptr->getText().c_str());
			int RemainTime = EqpTSet->TimeCloseValue2 - EqpTSet->TimeOpenValue2;
			lp1 = mTextViewStage2ColorFillPtr->getPosition();
			lp1.mLeft = 427 + (num1 * 33) + (num2 * 16 / 30);
			lp1.mWidth = (RemainTime / 60) * 33 + ((RemainTime % 60) / 30) * 16;
			lp1.mTop = 46;
			mTextViewStage2ColorFillPtr->setPosition(lp1);
			mTextViewStage2ColorFillPtr->setBackgroundColor(0xFFFF8000);
		}else{
			mTextViewStage2ColorFillPtr->setBackgroundColor(0);
			mWindowAirHum2Ptr->setBackgroundColor(0xFFD6D6D6);
		}
//	}
		delete(EqpTSet);
		EqpTSet = NULL;

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

    	//根据设备的ID号进入各自的定时设置界面
    	if (!strcmp(DeviceName.c_str(), "空气净化器")){
    		DeviceID = AirPURIFY;
    	}else if (!strcmp(DeviceName.c_str(), "空调")){
    		DeviceID = AIRCONDITION;
    	}else if (!strcmp(DeviceName.c_str(), "全热交换器")){
    		DeviceID = HOTEXCHANGE;
    	}else if (!strcmp(DeviceName.c_str(), "除湿器")){
    		DeviceID = DEHUMIDIFY;
    	}else if (!strcmp(DeviceName.c_str(), "新风机")){
    		DeviceID = WINDEXCHANGE;
    	}else if (!strcmp(DeviceName.c_str(), "净味器")){
    		DeviceID = STERILIZATION;
    	}else if (!strcmp(DeviceName.c_str(), "浴霸")){
    		DeviceID = YUBA;
    	}

    	DispEqpTimeData(DeviceID);
    }
}

/*
 * 当界面显示时触发
 */
static void onUI_show() {

//	if (WindowTimeWave)



//	ResetTimeTextPos();
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
//	LOGD("Timing exit\n");
//	tmpEqpTmer_Data = NULL;
//	free(tmpEqpTmer_Data);

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
			if (Flag_EquipmentTimeSetting){
				Flag_EquipmentTimeSetting = false;
				UpdateTimeSettingFunc();
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

void setManualDevTimeInfo(int DevID, EquipmentTiming *EqpTimeInfo){

		if (DevID < 0 || DevID > 6){
			return;
		}
		switch(DevID){
			case AirPURIFY:
			{
				MANUALSTATUS->setAirPFTimeInfo(EqpTimeInfo);
			}
			break;
			case AIRCONDITION:
			{
				MANUALSTATUS->setAirTimeInfo(EqpTimeInfo);
			}
			break;
			case HOTEXCHANGE:
			{
				MANUALSTATUS->setHeatChangeTimeInfo(EqpTimeInfo);
			}
			break;
			case DEHUMIDIFY:
			{
				MANUALSTATUS->setHumdTimeInfo(EqpTimeInfo);
			}
			break;
			case WINDEXCHANGE:
			{
				MANUALSTATUS->setWindTimeInfo(EqpTimeInfo);
			}
			break;
			case STERILIZATION:
			{
	//			MANUALSTATUS->setAirPFTimeSwitch(status);
			}
			break;
			case YUBA:
			{
				MANUALSTATUS->setYuBaTimeInfo(EqpTimeInfo);
			}
			break;
		}
		/*
		SWTtmp->DevID = DevID;
		if (EqpTimeInfo->Time1StageFlag){
			if (EqpTimeInfo->TimeCloseValue1 > EqpTimeInfo->TimeOpenValue1){
				SWTtmp->start_time1 = EqpTimeInfo->TimeOpenValue1;
				SWTtmp->delay_time1 = EqpTimeInfo->TimeCloseValue1 - EqpTimeInfo->TimeOpenValue1;
				SWTtmp->SWT_Mode = SoftwareTimer_Start;
				SWTtmp->timecount = 0;
			}
		}else{
			SWTtmp->start_time1 = 0;
			SWTtmp->delay_time1 = 0;
			SWTtmp->SWT_Mode = SoftwareTimer_Stop;
		}
		if (SWTtmp->SWT_Mode == SoftwareTimer_Start){
			if (EqpTimeInfo->Time2StageFlag){
				if (EqpTimeInfo->TimeCloseValue2 > EqpTimeInfo->TimeOpenValue2){
					SWTtmp->start_time2 = EqpTimeInfo->TimeOpenValue2;
					SWTtmp->delay_time2 = EqpTimeInfo->TimeCloseValue2 - EqpTimeInfo->TimeOpenValue2;
				}
			}else{
				SWTtmp->start_time2 = 0;
				SWTtmp->delay_time2 = 0;
			}
		}
		 */

//		SOFTWARETIMER->Add_SoftwareTimer(SWTtmp);

}

/* 从Addtime返回后更新Timing界面 */
void UpdateTimeSettingFunc()
{

	int Timenum1, Timenum2, Timenum3, Timenum4;
	char Timebuf[64];
	LayoutPosition lp, lp1, lpx;
	int StartLeft = 0;
	int ColorFillPos;

	EquipmentTiming *DevTimeSetting = MACHINESTATUS->getEquipmentTimeSetting();
	MACHINESTATUS->setEqpTimeData();
	setManualDevTimeInfo(DevTimeSetting->DeviceID, DevTimeSetting);

	if (!SOFTWARETIMER->isRunning()){
		SOFTWARETIMER->run("SWTlistence");
	}
	SOFTWARETIMER->Add_SoftwareTimer(DevTimeSetting);

	for (int i = 0;i < 8;i++){
		mTextViewPtr[i]->setText("");
	}
	for (int index = 0;DevTimeSetting->weekbuf[index] != 0;index++){
		int text = DevTimeSetting->weekbuf[index];
//		mTextViewPtr[index]->setVisible(true);
		lp = mTextViewPtr[index]->getPosition();
		lp.mLeft = StartLeft;
		lp.mTop = 10;
		mTextViewPtr[index]->setPosition(lp);
		mTextViewPtr[index]->setText(std::string(Week_String2char(text)).c_str());
		StartLeft += 66;
	}

	if (DevTimeSetting->Time1StageFlag){
		Timenum1 = DevTimeSetting->TimeOpenValue1 / 60;			//hour
		Timenum2 = DevTimeSetting->TimeOpenValue1 % 60;			//min
		sprintf(Timebuf, "%02d:%02d", Timenum1, Timenum2);
		mTextView13Ptr->setText(Timebuf);

		Timenum3 = DevTimeSetting->TimeCloseValue1 / 60;
		Timenum4 = DevTimeSetting->TimeCloseValue1 % 60;
		sprintf(Timebuf, "%02d:%02d", Timenum3, Timenum4);
		mTextView14Ptr->setText(Timebuf);
		mTextView15Ptr->setText(std::to_string(DevTimeSetting->TempSettingValue1) + "℃");
		mWindowAirHum1Ptr->setBackgroundColor(0);


//		mTextViewStage1ColorFillPtr->setText(mTextView15Ptr->getText().c_str());
		int RemainTime = DevTimeSetting->TimeCloseValue1 - DevTimeSetting->TimeOpenValue1;
		lp1 = mTextViewStage1ColorFillPtr->getPosition();
		lpx = mTextViewStage11ColorFillPtr->getPosition();
		if (Timenum1 > 12){
			ColorFillPos = 27;
			Timenum1 = Timenum1 - 12;
		}else{
			ColorFillPos = 427;
		}
		lp1.mLeft = ColorFillPos + (Timenum1 * 33) + (Timenum2 * 16 / 30);			//初始位置
		if (Timenum3 > 12){
			mTextViewStage11ColorFillPtr->setVisible(true);
			if ((DevTimeSetting->TimeOpenValue1 / 60) > 12){
				lp1.mWidth = ((24 - (DevTimeSetting->TimeOpenValue1 / 60)) * 33) - (Timenum2 * 16 / 30) + 12 * 33 + 4;
			}else{
				lp1.mWidth = ((12 - Timenum1) * 33) - (Timenum2 * 16 / 30) + 8;
			}
			lp1.mTop = 46;
			lpx.mLeft = 27;
			lpx.mTop = 46;
			lpx.mWidth = (Timenum3 - 12) * 33 + (Timenum4 * 16 / 30);

			mTextViewStage1ColorFillPtr->setPosition(lp1);
			mTextViewStage1ColorFillPtr->setBackgroundColor(0x55FF8000);
			mTextViewStage11ColorFillPtr->setPosition(lpx);
			mTextViewStage11ColorFillPtr->setBackgroundColor(0x55FF8000);
		}else{
			mTextViewStage11ColorFillPtr->setVisible(false);
			if ((DevTimeSetting->TimeOpenValue1 / 60) > 12){
				lp1.mWidth = ((24 - (DevTimeSetting->TimeOpenValue1 / 60)) * 33) - (Timenum2 * 16 / 30) + (Timenum3 * 33) + (Timenum4 * 16 / 30);
			}else{
				lp1.mWidth = ((RemainTime / 60) * 33) + ((RemainTime % 60) * 16 / 30);
			}
			lp1.mTop = 46;
			mTextViewStage1ColorFillPtr->setPosition(lp1);
			mTextViewStage1ColorFillPtr->setBackgroundColor(0x55FF8000);
		}
//		LOGD("Timenum1 is %d, Timenum2 is %d, Timenum3 is %d, Timenum4 is %d\n", Timenum1, Timenum2, Timenum3, Timenum4);
//		LOGD("lp1.mLeft is %d, lp1.mWidth is %d\n", lp1.mLeft, lp1.mWidth);
	}else{
//		mTextView13Ptr->setText("未设置");
//		mTextView14Ptr->setText("未设置");
//		mTextView15Ptr->setText("未设置");
		mTextViewStage1ColorFillPtr->setText("");
		mTextViewStage1ColorFillPtr->setBackgroundColor(0);
		mWindowAirHum1Ptr->setBackgroundColor(0xFFD6D6D6);
	}

	if (DevTimeSetting->Time2StageFlag){
		Timenum1 = DevTimeSetting->TimeOpenValue2 / 60;
		Timenum2 = DevTimeSetting->TimeOpenValue2 % 60;
		sprintf(Timebuf, "%02d:%02d", Timenum1, Timenum2);
		mTextView23Ptr->setText(Timebuf);

		Timenum3 = DevTimeSetting->TimeCloseValue2 / 60;
		Timenum4 = DevTimeSetting->TimeCloseValue2 % 60;
		sprintf(Timebuf, "%02d:%02d", Timenum3, Timenum4);
		mTextView24Ptr->setText(Timebuf);
		mTextView25Ptr->setText(std::to_string(DevTimeSetting->TempSettingValue2) + "℃");
		mWindowAirHum2Ptr->setBackgroundColor(0);

//		mTextViewStage2ColorFillPtr->setText(mTextView25Ptr->getText().c_str());
		int RemainTime1 = DevTimeSetting->TimeCloseValue2 - DevTimeSetting->TimeOpenValue2;
		lp1 = mTextViewStage2ColorFillPtr->getPosition();
		lpx = mTextViewStage22ColorFillPtr->getPosition();
		if (Timenum1 > 12){
			ColorFillPos = 27;
			Timenum1 = Timenum1 - 12;
		}else{
			ColorFillPos = 427;
		}
		lp1.mLeft = ColorFillPos + (Timenum1 * 33) + (Timenum2 * 16 / 30);			//初始位置
		if (Timenum3 > 12){
			mTextViewStage22ColorFillPtr->setVisible(true);
			if ((DevTimeSetting->TimeOpenValue2 / 60) > 12){
				lp1.mWidth = ((24 - (DevTimeSetting->TimeOpenValue2 / 60)) * 33) - (Timenum2 * 16 / 30) + 12 * 33 + 4;
			}else{
				lp1.mWidth = ((12 - Timenum1) * 33) - (Timenum2 * 16 / 30) + 8;
			}
			lp1.mTop = 46;
			lpx.mLeft = 27;
			lpx.mTop = 46;
			lpx.mWidth = (Timenum3 - 12) * 33 + (Timenum4 * 16 / 30);

			mTextViewStage2ColorFillPtr->setPosition(lp1);
			mTextViewStage2ColorFillPtr->setBackgroundColor(0x550080FF);
			mTextViewStage22ColorFillPtr->setPosition(lpx);
			mTextViewStage22ColorFillPtr->setBackgroundColor(0x550080FF);
		}else{
			mTextViewStage22ColorFillPtr->setVisible(false);
			if ((DevTimeSetting->TimeOpenValue2 / 60) > 12){
				lp1.mWidth = ((24 - (DevTimeSetting->TimeOpenValue2 / 60)) * 33) - (Timenum2 * 16 / 30) + (Timenum3 * 33) + (Timenum4 * 16 / 30);
			}else{
				lp1.mWidth = ((RemainTime1 / 60) * 33) + ((RemainTime1 % 60) * 16 / 30);
			}
			lp1.mTop = 46;
			mTextViewStage2ColorFillPtr->setPosition(lp1);
			mTextViewStage2ColorFillPtr->setBackgroundColor(0x550080FF);
		}
	}else{
//		mTextView23Ptr->setText("未设置");
//		mTextView24Ptr->setText("未设置");
//		mTextView25Ptr->setText("未设置");
		mTextViewStage2ColorFillPtr->setText("");
		mTextViewStage2ColorFillPtr->setBackgroundColor(0);
		mWindowAirHum2Ptr->setBackgroundColor(0xFFD6D6D6);
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

void setManualDevTimeSwitch(int DevID, int status){
	if (DevID < 0 || DevID > 6){
		return;
	}
	switch(DevID){
		case AirPURIFY:
		{
			MANUALSTATUS->setAirPFTimeSwitch(status);
		}
		break;
		case AIRCONDITION:
		{
			MANUALSTATUS->setAirTimeSwitch(status);
		}
		break;
		case HOTEXCHANGE:
		{
			MANUALSTATUS->setHeatChangeTimeSwitch(status);
		}
		break;
		case DEHUMIDIFY:
		{
			MANUALSTATUS->setHumdTimeSwitch(status);
		}
		break;
		case WINDEXCHANGE:
		{
			MANUALSTATUS->setWindTimeSwitch(status);
		}
		break;
		case STERILIZATION:
		{
//			MANUALSTATUS->setAirPFTimeSwitch(status);
		}
		break;
		case YUBA:
		{
			MANUALSTATUS->setYuBaTimeSwitch(status);
		}
		break;
	}
}

static bool onButtonClick_Button6(ZKButton *pButton) {
    LOGD(" ButtonClick Button6 !!!\n");
    if (pButton->isSelected()){
    	Flag_Switch = false;
    	mButton2Ptr->setSelected(false);
    	pButton->setSelected(false);
    	mWindowTimeWavePtr->setBackgroundColor(0x22252525);
    }else{
    	Flag_Switch = true;
    	mButton2Ptr->setSelected(true);
    	pButton->setSelected(true);
    	mWindowTimeWavePtr->setBackgroundColor(0);
    }
//    setManualDevTimeSwitch(DeviceID, pButton->isSelected());
    if (!SOFTWARETIMER->GetSWTData().empty()){
//		std::vector<Software_Timer *>::iterator it = SOFTWARETIMER->GetSWTData().begin();
//		for (;it != SOFTWARETIMER->GetSWTData().end();it++){
    	for (int i = 0;i < (int)SOFTWARETIMER->GetSWTData().size();i++){
			Software_Timer *tmp = SOFTWARETIMER->GetSWTData().at(i);
			if (tmp->EqpTime_Data->DeviceID == DeviceID){
				tmp->EqpTime_Data->DeviceSwitch = (pButton->isSelected()?true : false);
//				LOGD("tmp->EqpTime_Data->DeviceSwitch is %d\n", tmp->EqpTime_Data->DeviceSwitch);
				break;
			}
		}
    }
    MACHINESTATUS->setDeviceSWTSwitch(DeviceID, (pButton->isSelected()?true : false));
    MACHINESTATUS->getDeviceSwitch(Flag_Switch);
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
