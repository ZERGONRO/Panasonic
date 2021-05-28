#pragma once
#include "uart/ProtocolSender.h"
#include "entry/EasyUIContext.h"
#include "utils/TimeHelper.h"
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
static int powerButtonStatus;
static int buttonStatus;
static int timeOutCount;
static int getFlag;
static int step;
static int mode;
static bool NtpDateFlag = false;
static bool ButtonModeSelectStatus = false;
static pthread_t g_MovePicPosThread = 0;
static std::vector<WifiInfo_t *> *WifiInfo;



static Mutex pLock;

extern void initStatusBarMode();
extern void showstatusbars();
extern void hidestatusbars();

//extern MyNetWorkingListener *nwlistener;

/**
 * 注册定时器
 * 填充数组用于注册定时器
 * 注意：id不能重复
 */
static S_ACTIVITY_TIMEER REGISTER_ACTIVITY_TIMER_TAB[] = {
//	{0,  6000}, //定时器id=0, 时间间隔6秒
//	{1,  1000},
//	{2,  500},
};

void SetEnvName(std::string focusindex)
{
	mButton2Ptr->setText(focusindex);
	mButton8Ptr->setText(focusindex);
}
//struct tm *t = TimeHelper::getDateTime();

static void updateTime()
{
	char timeStr[20];
	static bool bflash = false;
	struct tm *t = TimeHelper::getDateTime();

//	sprintf(timeStr, "%02d:%02d:%02d", t->tm_hour,t->tm_min,t->tm_sec);
//	mTextView42Ptr->setText(timeStr);
	sprintf(timeStr, "%02d:%02d", t->tm_hour,t->tm_min);
	mTextView42Ptr->setText(timeStr);

//	sprintf(timeStr, "%d年%02d月%02d日", 1900 + t->tm_year, t->tm_mon + 1, t->tm_mday);
//	mTextView5Ptr->setText(timeStr);
	sprintf(timeStr, "%02d/%02d", t->tm_mon + 1, t->tm_mday);
	mTextView5Ptr->setText(timeStr);

	static const char *day[] = { "日", "一", "二", "三", "四", "五", "六" };
	sprintf(timeStr, "星期%s", day[t->tm_wday]);
	mTextView6Ptr->setText(timeStr);
}

static int GPIO_get_value()
{
    FILE* file = NULL;
    char buf[16] = {0};

    file = fopen("/sys/class/gpio/gpio9/value", "rb");

    if(file == NULL)
    {
        // fail to open watchdog device
        printf("GPIO_get_value: fail to open!\n");
        return -1;
    }

//    fseek(file, 0, SEEK_END); //文件指针转到文件末尾
//    int len = ftell(file);
//    rewind(file);

    fread(buf, 1, 1, file);
    buf[1] = 0;
//    LOGD("GPIO_get_value:gpio_value is %s\n", buf);

    fclose(file);

    return atoi(buf);
}

void ResetStatusIconPos()
{
	LayoutPosition lp;
	int StartLeft = 176;
	if(mIconViewWifiPtr->isVisible())
	{
		lp = mIconViewWifiPtr->getPosition();
		lp.mLeft = StartLeft;
		lp.mTop = 5;
		StartLeft -= 42;
		mIconViewWifiPtr->setPosition(lp);
	}
	else
	{
		lp = mIconViewWifiPtr->getPosition();
		lp.mTop = -10;
		mIconViewWifiPtr->setPosition(lp);
	}
	if(mIconViewAirColdPtr->isVisible())
	{
		lp = mIconViewAirColdPtr->getPosition();
		lp.mLeft = StartLeft;
		lp.mTop = 5;
		StartLeft -= 42;
		mIconViewAirColdPtr->setPosition(lp);
	}
	else
	{
		lp = mIconViewAirColdPtr->getPosition();
		lp.mTop = -10;
		mIconViewAirColdPtr->setPosition(lp);
	}
	if(mIconViewHumdColdPtr->isVisible())
	{
		lp = mIconViewHumdColdPtr->getPosition();
		lp.mLeft = StartLeft;
		lp.mTop = 5;
		StartLeft -= 42;
		mIconViewHumdColdPtr->setPosition(lp);
	}
	else
	{
		lp = mIconViewHumdColdPtr->getPosition();
		lp.mTop = -10;
		mIconViewHumdColdPtr->setPosition(lp);
	}
	if(mIconViewHumdDryPtr->isVisible())
	{
		lp = mIconViewHumdDryPtr->getPosition();
		lp.mLeft = StartLeft;
		lp.mTop = 5;
		StartLeft -= 42;
		mIconViewHumdDryPtr->setPosition(lp);
	}
	else
	{
		lp = mIconViewHumdDryPtr->getPosition();
		lp.mTop = -10;
		mIconViewHumdDryPtr->setPosition(lp);
	}
	if(mIconViewSecurityPtr->isVisible())
	{
		lp = mIconViewSecurityPtr->getPosition();
		lp.mLeft = StartLeft;
		lp.mTop = 5;
		StartLeft -= 42;
		mIconViewSecurityPtr->setPosition(lp);
	}
	else
	{
		lp = mIconViewSecurityPtr->getPosition();
		lp.mTop = -10;
		mIconViewSecurityPtr->setPosition(lp);
	}
}


/**
 * 当界面构造时触发
 */
static void onUI_init(){
    //Tips :添加 UI初始化的显示代码到这里,如:mText1Ptr->setText("123");

	buttonStatus = 0;
	powerButtonStatus = 0;
	timeOutCount = 0;
	getFlag = 0;
	step = 0;
	mode = 0;
	initStatusBarMode();
//	initStatusBar();
//	disableStatusBar();
//	setStatusBarBarrelNotice(false);
	system("echo 9 > /sys/class/gpio/export");
	system("echo in > /sys/class/gpio/gpio9/direction");
	system("echo 1 > /sys/class/pwm/pwmchip0/export");
	system("echo 2000 > /sys/class/pwm/pwmchip0/pwm1/period");
	system("echo 100 > /sys/class/pwm/pwmchip0/pwm1/duty_cycle");
	system("echo 1 > /sys/class/pwm/pwmchip0/pwm1/enable");
	system("echo 0 > /sys/class/pwm/pwmchip0/export");
	system("echo 2000 > /sys/class/pwm/pwmchip0/pwm0/period");
	buttonStatus = GPIO_get_value();
	if(!buttonStatus) {
		getFlag = 1;
		system("echo 20 > /sys/class/pwm/pwmchip0/pwm0/duty_cycle");
		system("echo 1 > /sys/class/pwm/pwmchip0/pwm0/enable");
		mActivityPtr->registerUserTimer(0, 1000);
	}
	else {

		system("echo 100 > /sys/class/pwm/pwmchip0/pwm0/duty_cycle");
		system("echo 1 > /sys/class/pwm/pwmchip0/pwm0/enable");
		system("echo 1 > /tmp/userMode");
		//EASYUICONTEXT->openActivity("mainActivity", NULL);
//		setStatusBarBarrelNotice(true);
	}
}

/**
 * 当切换到该界面时触发
 */
static void onUI_intent(const Intent *intentPtr) {
    if (intentPtr != NULL) {
        //TODO

    }

//    nwlistener->ScanNetWork();
//    mActivityPtr->registerUserTimer(2, 5000);
    if(nwlistener == NULL)
    {
    	nwlistener = new MyNetWorkingListener();
    	nwlistener->run("nwListener");
//    	LOGD("new MyNetWorkingListener() and run !!!\n");
    }

    if(nwlistener->IsConnected())
	{
		LOGD("Load the time \n");
		system("/customer/ntpdate -v -t 5 ntp1.aliyun.com ntp2.aliyun.com ntp3.aliyun.com pool.ntp.org&");
		NtpDateFlag = true;
	}
    else
    {
    	NtpDateFlag = false;
    }


//    system("/customer/ntpdate -v -t 5 ntp1.aliyun.com ntp2.aliyun.com ntp3.aliyun.com pool.ntp.org&");
}

/*
 * 当界面显示时触发
 */
static void onUI_show() {


	hidestatusbars();
//	mTextView31Ptr->setText(std::to_string(atoi(mTextView31Ptr->getText().c_str())));
//	mTextView48Ptr->setText(std::to_string(atoi(mTextView48Ptr->getText().c_str())));

	mIconViewWifiPtr->setVisible(nwlistener->IsConnected());
//	LOGD("mIconViewWifiPtr->setVisible(nwlistener->IsConnected()); !!!\n");
//	mIconViewWifiPtr->setVisible(true);
	mIconViewSecurityPtr->setVisible(true);
	mIconViewHumdDryPtr->setVisible(false);
	mIconViewHumdColdPtr->setVisible(true);
	mIconViewAirColdPtr->setVisible(true);

	ResetStatusIconPos();

	mButtonHomepage2Ptr->setSelected(true);
	mButtonSmart2Ptr->setSelected(false);
	mButtonManual2Ptr->setSelected(false);
	mButtonHistorty2Ptr->setSelected(false);

	mTextViewHomepage2Ptr->setSelected(true);
	mTextViewSmart2Ptr->setSelected(false);
	mTextViewManual2Ptr->setSelected(false);
	mTextViewHistory2Ptr->setSelected(false);
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

	}
		break;
	case 2:
	{

		if(nwlistener->IsConnected())
		{
			LOGD("nwlistener  onUI_Timer !!!\n");

			std::string ssid = nwlistener->getSSID();
			WifiInfo = nwlistener->getSSIDInfo();
			for(int i = 0;i < WifiInfo->size();i++)
			{
				int wifisignal = 0;
				WifiInfo_t *child = WifiInfo->at(i);
				if(ssid == std::string(child->ssid))
				{
					if(child->signal >= -55)
						wifisignal = 100;
					else if(child->signal <= -95)
						wifisignal = 0;
					else
						wifisignal = ((child->signal + 95)*5)/2;
				}
			}
		}

		if(nwlistener->getWifiStatus())
			nwlistener->resetScanCount();


		if(NtpDateFlag)
		{
			updateTime();
		}
//		updateTime();


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
static bool onmainActivityTouchEvent(const MotionEvent &ev) {
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
static bool onButtonClick_ButtonHomepage(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHomepage !!!\n");
    return false;
}

static bool onButtonClick_ButtonHomepage1(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHomepage1 !!!\n");
    return false;
}

static bool onButtonClick_ButtonSmart(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonSmart !!!\n");
    return false;
}

static bool onButtonClick_ButtonSmart1(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonSmart1 !!!\n");
    return false;
}

static bool onButtonClick_ButtonManual(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonManual !!!\n");
    return false;
}

static bool onButtonClick_ButtonManual1(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonManual1 !!!\n");
    return false;
}

static bool onButtonClick_ButtonHistorty(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHistorty !!!\n");
    return false;
}

static bool onButtonClick_ButtonHistorty1(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHistorty1 !!!\n");
    return false;
}



static bool onButtonClick_ButtonON(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonON !!!\n");
    return false;
}

static bool onButtonClick_ButtonOFF(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonOFF !!!\n");
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
    return false;
}

static bool onButtonClick_Button7(ZKButton *pButton) {
    LOGD(" ButtonClick Button7 !!!\n");
    return false;
}
static bool onButtonClick_Button1(ZKButton *pButton) {
    LOGD(" ButtonClick Button1 !!!\n");
    return false;
}
static bool onButtonClick_Button2(ZKButton *pButton) {
    LOGD(" ButtonClick Button2 !!!\n");
    EASYUICONTEXT->openActivity("EnvironmentSelectActivity", NULL);
    return false;
}

static bool onButtonClick_Button8(ZKButton *pButton) {
    LOGD(" ButtonClick Button8 !!!\n");
    EASYUICONTEXT->openActivity("EnvironmentSelectActivity", NULL);
    return false;
}

static bool onButtonClick_Button9(ZKButton *pButton) {
    LOGD(" ButtonClick Button9 !!!\n");
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

static bool onButtonClick_Button10(ZKButton *pButton) {
    LOGD(" ButtonClick Button10 !!!\n");
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

static bool onButtonClick_Button11(ZKButton *pButton) {
    LOGD(" ButtonClick Button11 !!!\n");
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

static bool onButtonClick_Button12(ZKButton *pButton) {
    LOGD(" ButtonClick Button12 !!!\n");
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

static bool onButtonClick_Button13(ZKButton *pButton) {
    LOGD(" ButtonClick Button13 !!!\n");
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

static bool onButtonClick_Button14(ZKButton *pButton) {
    LOGD(" ButtonClick Button14 !!!\n");
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
static bool onButtonClick_ButtonDropDown(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonDropDown !!!\n");
//    EASYUICONTEXT->showStatusBar();
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

/****************
 * type:
 * 		false：卡片逆时针滑动
 * 		true：卡片顺时针滑动
 *
 * count:卡片到主显示的滑动距离
 *
 */

static void *MovePicPos(void *param)
{
	LOGD("MovePicPos thread Begin \n");
	float speedTop = 50;
	float speedLeft = 80;
	bool PosStatus = false;
	bool type = (bool)param;
//	pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
	while(ButtonModeSelectStatus)
	{
		int count = 0;
		for(int i = 0;i < 5;i++)					//卡片移动
		{
			if(count > 4)
				break;

			if(i > 4)
				i = 0;
			LayoutPosition lp = mWindowSelectModePtr[i]->getPosition();
//			LOGD("MovePicPos  type: %d , i = %d, lp.mLeft = %d, lp.mTop = %d \n", type, i, lp.mLeft, lp.mTop);
			if(type)
			{
				if(lp.mLeft > 0 && lp.mLeft <= 242 && lp.mTop > 0 && lp.mTop <= 151)
				{
//					LOGD("5 to 1 \n");
					lp.mLeft -= speedLeft;
					lp.mTop -= speedTop;
					if(lp.mTop <= 0 || lp.mLeft <= 0)
						PosStatus = true;
				}
				else if(lp.mLeft <= 450 && lp.mLeft > 242 && lp.mTop == 151 )
				{
//					LOGD("4 to 5 \n");
					lp.mLeft -= speedLeft;
					lp.mTop = 151;
					if(lp.mLeft <= 242)
						PosStatus = true;
				}
				else if(lp.mLeft == 450 && lp.mTop >= 0 && lp.mTop < 151 )
				{
//					LOGD("3 to 4 \n");
					lp.mLeft = 450;
					lp.mTop += speedTop;
					if(lp.mTop >= 151)
						PosStatus = true;
//					LOGD("lp.mTop = %d \n", lp.mTop);
				}
				else if(lp.mLeft < 450 && lp.mLeft >= 242 && lp.mTop == 0 )
				{
//					LOGD("2 to 3 \n");
					lp.mLeft += speedLeft;
					lp.mTop = 0;
					if(lp.mLeft >= 450)
						PosStatus = true;
				}
				else if(lp.mLeft < 242 && lp.mLeft >= 0 && lp.mTop == 0 )
				{
//					LOGD("1 to 2 \n");
					lp.mLeft += speedLeft;
					lp.mTop = 0;
					if(lp.mLeft >= 242)
						PosStatus = true;
//					LOGD("lp.mLeft = %d \n", lp.mLeft);
				}
//				LOGD("lp.mLeft = %d, lp.mTop = %d , i = %d \n", lp.mLeft, lp.mTop, i);
				mWindowSelectModePtr[i]->setPosition(lp);
			}
			else
			{
//				if(lp.mLeft >= 0 && lp.mLeft < 242 && lp.mTop >= 0 && lp.mTop < 151)
				if(lp.mLeft <= 242 && lp.mLeft > 0 && lp.mTop == 0)
				{
//					LOGD("2 to 1 \n");
					lp.mLeft -= speedLeft;
					lp.mTop = 0;
					if(lp.mLeft <= 0)
						PosStatus = true;

				}
				else if(lp.mLeft < 450 && lp.mLeft >= 242 && lp.mTop == 151 )
				{
//					LOGD("5 to 4 \n");
					lp.mLeft += speedLeft;
					lp.mTop = 151;
					if(lp.mLeft >= 450)
						PosStatus = true;
				}
				else if(lp.mLeft == 450 && lp.mTop > 0)
				{
//					LOGD("4 to 3 \n");
					lp.mLeft = 450;
					lp.mTop -= speedTop;
					if(lp.mTop <= 0)
						PosStatus = true;
				}
				else if(lp.mLeft <= 450 && lp.mLeft > 242 && lp.mTop == 0 )
				{
//					LOGD("3 to 2 \n");
					lp.mLeft -= speedLeft;
					lp.mTop = 0;
					if(lp.mLeft <= 242)
						PosStatus = true;
				}
//				else if(lp.mLeft <= 242 && lp.mLeft > 0 && lp.mTop == 0 )
				else if(lp.mLeft >= 0 && lp.mLeft < 242 && lp.mTop >= 0 && lp.mTop < 151)
				{
//					LOGD("1 to 5 \n");
					lp.mLeft += speedLeft;
					lp.mTop += speedTop;
					if(lp.mTop >= 151 || lp.mLeft >= 242)
						PosStatus = true;
				}
				LOGD("lp.mLeft = %d, lp.mTop = %d , i = %d \n", lp.mLeft, lp.mTop, i);
				mWindowSelectModePtr[i]->setPosition(lp);
			}


			if(PosStatus)						//确定卡片位置
			{
				LOGD("PosStatus  !!!!!\n");
				PosStatus = false;
				ButtonModeSelectStatus = false;
				for(int j = 0;j <= 4;j++)
				{
					LayoutPosition lp1 = mWindowSelectModePtr[j]->getPosition();
//					LOGD("lp1.mLeft = %d,  lp1.mTop = %d, j = %d\n",lp1.mLeft, lp1.mTop, j);
//					LOGD("j = %d \n", j);
					if(type)
					{
						if(lp1.mLeft < 242 && lp1.mTop != 0 && lp1.mTop < 151)
						{
//							LOGD("5 to 1 \n");
							lp1.mLeft = 0;
							lp1.mTop = 0;

						}
						else if(lp1.mLeft < 450 && lp1.mTop == 151 )
						{
//							LOGD("4 to 5 \n");
							lp1.mLeft = 242;
							lp1.mTop = 151;
						}
						else if(lp1.mLeft == 450 &&  lp1.mTop > 0 )
						{
//							LOGD("3 to 4 \n");
							lp1.mLeft = 450;
							lp1.mTop = 151;
						}
						else if(lp1.mLeft > 242 && lp1.mTop == 0 )
						{
//							LOGD("2 to 3 \n");
							lp1.mLeft = 450;
							lp1.mTop = 0;
						}
						else if(lp1.mLeft < 242 && lp1.mLeft >= 0 && lp1.mTop == 0 )
						{
//							LOGD("1 to 2 \n");
							lp1.mLeft = 242;
							lp1.mTop = 0;
						}
					}
					else
					{
						if(lp1.mLeft > 0 && lp1.mLeft <= 242 && lp1.mTop > 0)
						{
//							LOGD("1 to 5 \n");
							lp1.mLeft = 242;
							lp1.mTop = 151;
						}
						else if(lp1.mLeft > 242 && lp1.mTop == 151 )
						{
//							LOGD("5 to 4 \n");
							lp1.mLeft = 450;
							lp1.mTop = 151;
						}
						else if(lp1.mLeft == 450 && lp1.mTop != 0 && lp1.mTop < 151)
						{
//							LOGD("4 to 3 \n");
							lp1.mLeft = 450;
							lp1.mTop = 0;
						}
						else if(lp1.mLeft < 450 && lp1.mLeft >= 230 && lp1.mTop == 0 )
						{
//							LOGD("3 to 2 \n");
							lp1.mLeft = 242;
							lp1.mTop = 0;
						}
						else if(lp1.mLeft >= 0 && lp1.mTop == 0 )
						{
//							LOGD("2 to 1 \n");
							lp1.mLeft = 0;
							lp1.mTop = 0;
						}
					}
					mWindowSelectModePtr[j]->setPosition(lp1);
				}
				LOGD("ButtonModeSelectStatus break !!!!! \n");
//				usleep(30 * 1000);
				break;
			}
			count++;


			speedTop *= 0.98;
			speedLeft *= 0.98;
			usleep(10 * 1000);
		}


	}
	return NULL;
}


void ModePicSelectFunc(bool type, int count, int focus)
{
	LOGD("ModePicSelectFunc!!! \n");
	//顺时针
//		Mutex::Autolock _l(pLock);
		while(count--)
		{
			if(g_MovePicPosThread)
			{
//				pthread_cancel(g_MovePicPosThread);
				pthread_join(g_MovePicPosThread, NULL);
				g_MovePicPosThread = 0;
				LOGD("g_MovePicPosThread pthread_join  !!! \n");

			}
			ButtonModeSelectStatus = true;
//			int j = 0;
			LOGD("ModePicSelectFunc type : %d !!! \n", type);
			for(int k = 0;k <= 4;k++)						//改变卡片大小
			{
				LayoutPosition lp = mWindowSelectModePtr[k]->getPosition();
//				LayoutPosition lp1 = mButtonModeSelect[j]->getPosition();
				if(type)
				{
//						if(lp.mLeft >= 242 && lp.mLeft < 450 && lp.mTop > 0)
						if(lp.mLeft == 242 && lp.mTop == 151)
						{
							lp.mHeight = 260;
							lp.mWidth = 213;
							mWindowSelectModePtr[k]->setPosition(lp);
//							LOGD("5  to  1 !!! \n");
							LayoutPosition lp1 = mTextModeSelectPic[k]->getPosition();
							lp1.mLeft = 30;
							lp1.mTop = 20;
							mTextModeSelectPic[k]->setPosition(lp1);
							LayoutPosition lp4 = mTextModeSelectTitle[k]->getPosition();
							lp4.mWidth = 120;
							lp4.mHeight = 60;
							lp4.mLeft = 64;
							lp4.mTop = 15;
							mTextModeSelectTitle[k]->setPosition(lp4);
							mTextModeSelectTitle[k]->setTextSize(30);
							LayoutPosition lp5 = mTextModeSelectRecvData[k]->getPosition();
	//						lp5.mLeft = 30;
	//						lp5.mTop = 81;
							lp5.mLeft = lp1.mLeft;
							lp5.mTop = lp1.mTop + lp1.mHeight + 30;
							lp5.mHeight = 70;
							lp5.mWidth = 120;
							mTextModeSelectRecvData[k]->setTextSize(38);
							mTextModeSelectRecvData[k]->setAlpha(255);
							mTextModeSelectRecvData[k]->setPosition(lp5);
							LayoutPosition lp3 = mTextModeSelectString[k]->getPosition();
							lp3.mTop = lp5.mTop + lp5.mHeight + 5;
							lp3.mLeft = lp5.mLeft;
							mTextModeSelectString[k]->setPosition(lp3);

							if(mWindowSelectModePtr[k] == mWindowHumidityPtr)
							{
								LayoutPosition lp4 = mTextModeSelectTitle[k]->getPosition();
								lp4.mTop = 8;
								mTextModeSelectTitle[k]->setPosition(lp4);
							}

						}
						else
						{
							LayoutPosition lp1 = mTextModeSelectPic[k]->getPosition();
							lp1.mLeft = 21;
							lp1.mTop = 12;
							mTextModeSelectPic[k]->setPosition(lp1);
							LayoutPosition lp4 = mTextModeSelectTitle[k]->getPosition();
							lp4.mWidth = 80;
							lp4.mHeight = 40;
							lp4.mLeft = 60;
							lp4.mTop = 10;
							mTextModeSelectTitle[k]->setPosition(lp4);
							mTextModeSelectTitle[k]->setTextSize(20);
							LayoutPosition lp2 = mTextModeSelectRecvData[k]->getPosition();
							lp2.mLeft = 29;
							lp2.mTop = 48;
							lp2.mHeight = 45;
							lp2.mWidth = 40;
							mTextModeSelectRecvData[k]->setPosition(lp2);
							mTextModeSelectRecvData[k]->setTextSize(36);
							mTextModeSelectRecvData[k]->setAlpha(255);
							LayoutPosition lp3 = mTextModeSelectString[k]->getPosition();
							lp3.mTop = 65;
							lp3.mLeft = lp2.mLeft + lp2.mWidth + 5;
							mTextModeSelectString[k]->setPosition(lp3);

							lp.mHeight = 109;
							lp.mWidth = 180;


							if(mWindowSelectModePtr[k] == mWindowHumidityPtr)
							{
								LayoutPosition lp4 = mTextModeSelectTitle[k]->getPosition();
								lp4.mWidth = 80;
								lp4.mHeight = 40;
								lp4.mLeft = 60;
								lp4.mTop = 3;
								mTextModeSelectTitle[k]->setPosition(lp4);
								mTextModeSelectTitle[k]->setTextSize(20);
								LayoutPosition lp2 = mTextModeSelectRecvData[k]->getPosition();
								lp2.mLeft = 29;
								lp2.mTop = 38;
								lp2.mHeight = 50;
								lp2.mWidth = 40;
								mTextModeSelectRecvData[k]->setPosition(lp2);
								mTextModeSelectRecvData[k]->setTextSize(36);
								LayoutPosition lp3 = mTextModeSelectString[k]->getPosition();
								lp3.mTop = 65;
								lp3.mLeft = lp2.mLeft + lp2.mWidth + 5;
								mTextModeSelectString[k]->setPosition(lp3);
							}

							if(mWindowSelectModePtr[k] == mWindowFormaldehydePtr)
							{
								LayoutPosition lp2 = mTextModeSelectRecvData[k]->getPosition();
								lp2.mLeft = 29;
								lp2.mTop = 48;
								lp2.mHeight = 45;
								lp2.mWidth = 100;
								mTextModeSelectRecvData[k]->setPosition(lp2);
								mTextModeSelectRecvData[k]->setTextSize(36);
								LayoutPosition lp3 = mTextModeSelectString[k]->getPosition();
								lp3.mTop = 65;
								lp3.mLeft = 100;
								mTextModeSelectString[k]->setPosition(lp3);
							}

							if(mWindowSelectModePtr[k] == mWindowPM25Ptr)
							{
								LayoutPosition lp2 = mTextModeSelectRecvData[k]->getPosition();
								lp2.mLeft = 29;
								lp2.mTop = 48;
								lp2.mHeight = 45;
								lp2.mWidth = 40;
								mTextModeSelectRecvData[k]->setPosition(lp2);
								mTextModeSelectRecvData[k]->setTextSize(36);
								LayoutPosition lp3 = mTextModeSelectString[k]->getPosition();

									lp3.mLeft = lp2.mLeft + 20;

								mTextModeSelectString[k]->setPosition(lp3);
							}

						}
						mWindowSelectModePtr[k]->setPosition(lp);

				}
				else
				{
//						if(lp.mLeft >= 242 && lp.mLeft < 450 && lp.mTop <= 0)
						if(lp.mLeft == 242 && lp.mTop == 0)
						{
							lp.mHeight = 260;
							lp.mWidth = 213;
							mWindowSelectModePtr[k]->setPosition(lp);
							LayoutPosition lp1 = mTextModeSelectPic[k]->getPosition();
							lp1.mLeft = 30;
							lp1.mTop = 20;
							mTextModeSelectPic[k]->setPosition(lp1);
							LayoutPosition lp4 = mTextModeSelectTitle[k]->getPosition();
							lp4.mWidth = 120;
							lp4.mHeight = 60;
							lp4.mLeft = 64;
							lp4.mTop = 15;
							mTextModeSelectTitle[k]->setPosition(lp4);
							mTextModeSelectTitle[k]->setTextSize(30);
							LayoutPosition lp5 = mTextModeSelectRecvData[k]->getPosition();
							lp5.mLeft = lp1.mLeft;
							lp5.mTop = lp1.mTop + lp1.mHeight + 30;
							lp5.mHeight = 70;
							lp5.mWidth = 120;
							mTextModeSelectRecvData[k]->setPosition(lp5);
							mTextModeSelectRecvData[k]->setTextSize(38);
							mTextModeSelectRecvData[k]->setAlpha(255);
	//						mTextModeSelectRecvData[k]->setVisible(true);
							LayoutPosition lp3 = mTextModeSelectString[k]->getPosition();
							lp3.mTop = lp5.mTop + lp5.mHeight + 5;
							lp3.mLeft = lp5.mLeft;
							mTextModeSelectString[k]->setPosition(lp3);

							if(mWindowSelectModePtr[k] == mWindowHumidityPtr)
							{
								LayoutPosition lp4 = mTextModeSelectTitle[k]->getPosition();
								lp4.mTop = 8;
								mTextModeSelectTitle[k]->setPosition(lp4);
							}

							lp.mHeight = 260;
							lp.mWidth = 213;

						}
						else
						{
							LayoutPosition lp1 = mTextModeSelectPic[k]->getPosition();
							lp1.mLeft = 21;
							lp1.mTop = 12;
							mTextModeSelectPic[k]->setPosition(lp1);
							LayoutPosition lp4 = mTextModeSelectTitle[k]->getPosition();
							lp4.mWidth = 80;
							lp4.mHeight = 40;
							lp4.mLeft = 60;
							lp4.mTop = 10;
							mTextModeSelectTitle[k]->setPosition(lp4);
							mTextModeSelectTitle[k]->setTextSize(20);
							LayoutPosition lp2 = mTextModeSelectRecvData[k]->getPosition();
							lp2.mLeft = 29;
							lp2.mTop = 48;
							lp2.mHeight = 45;
							lp2.mWidth = 40;
							mTextModeSelectRecvData[k]->setPosition(lp2);
							mTextModeSelectRecvData[k]->setTextSize(36);
							mTextModeSelectRecvData[k]->setAlpha(255);
							LayoutPosition lp3 = mTextModeSelectString[k]->getPosition();
							lp3.mTop = 65;
							lp3.mLeft = lp2.mLeft + lp2.mWidth + 5;
							mTextModeSelectString[k]->setPosition(lp3);
	//						lp.mLeft = 0;
	//						lp.mTop = 0;
							lp.mHeight = 109;
							lp.mWidth = 180;

							if(mWindowSelectModePtr[k] == mWindowHumidityPtr)
							{
								LayoutPosition lp4 = mTextModeSelectTitle[k]->getPosition();
								lp4.mWidth = 80;
								lp4.mHeight = 40;
								lp4.mLeft = 60;
								lp4.mTop = 3;
								mTextModeSelectTitle[k]->setPosition(lp4);
								mTextModeSelectTitle[k]->setTextSize(20);
								LayoutPosition lp2 = mTextModeSelectRecvData[k]->getPosition();
								lp2.mLeft = 29;
								lp2.mTop = 38;
								lp2.mHeight = 50;
								lp2.mWidth = 40;
								mTextModeSelectRecvData[k]->setPosition(lp2);
								mTextModeSelectRecvData[k]->setTextSize(36);
								LayoutPosition lp3 = mTextModeSelectString[k]->getPosition();
								lp3.mTop = 65;
								lp3.mLeft = lp2.mLeft + lp2.mWidth + 5;
								mTextModeSelectString[k]->setPosition(lp3);
							}

							if(mWindowSelectModePtr[k] == mWindowFormaldehydePtr)
							{
								LayoutPosition lp2 = mTextModeSelectRecvData[k]->getPosition();
								lp2.mLeft = 29;
								lp2.mTop = 48;
								lp2.mHeight = 45;
								lp2.mWidth = 100;
								mTextModeSelectRecvData[k]->setPosition(lp2);
								mTextModeSelectRecvData[k]->setTextSize(36);
								LayoutPosition lp3 = mTextModeSelectString[k]->getPosition();
								lp3.mTop = 65;
								lp3.mLeft = 100;
								mTextModeSelectString[k]->setPosition(lp3);
							}
							if(mWindowSelectModePtr[k] == mWindowPM25Ptr)
							{
								LayoutPosition lp2 = mTextModeSelectRecvData[k]->getPosition();
								lp2.mLeft = 29;
								lp2.mTop = 48;
								lp2.mHeight = 45;
								lp2.mWidth = 40;
								mTextModeSelectRecvData[k]->setPosition(lp2);
								mTextModeSelectRecvData[k]->setTextSize(36);
								LayoutPosition lp3 = mTextModeSelectString[k]->getPosition();

									lp3.mLeft = lp2.mLeft + 20;

								mTextModeSelectString[k]->setPosition(lp3);
							}

						}
						mWindowSelectModePtr[k]->setPosition(lp);

					}

//				LOGD("k = %d !!! \n", k);
				}
			mActivityPtr->resetUserTimer(1, 2000);
			if(pthread_create(&g_MovePicPosThread, NULL, MovePicPos, (void *)(type)) != 0)
				LOGD("pthread_create error !!! \n");
		}

}

static bool onButtonClick_ButtonSelect1(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonSelect1 !!!\n");
    return false;
}

static bool onButtonClick_ButtonSelect2(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonSelect2 !!!\n");
    int i;
    for(i = 0;i < 5;i++)
    {
    	LayoutPosition lp = mWindowSelectModePtr[i]->getPosition();
		LayoutPosition lp1 = mButtonSelect2Ptr->getPosition();
		if(lp1 == lp)
		{
			LOGD("break!!! \n");
			break;
		}

    }
    LOGD("i : %d", i);
    ButtonModeSelectStatus = true;
//    g_MovePicPosThread = 1;
    ModePicSelectFunc(false, 1, i);
    return false;
}

static bool onButtonClick_ButtonSelect3(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonSelect3 !!!\n");
    int i;
	for(i = 0;i < 5;i++)
	{
		LayoutPosition lp = mWindowSelectModePtr[i]->getPosition();
		LayoutPosition lp1 = mButtonSelect3Ptr->getPosition();
		if(lp1 == lp)
		{
			LOGD("break!!! \n");
			break;
		}

	}
	LOGD("i : %d", i);
	ButtonModeSelectStatus = true;
//	g_MovePicPosThread = 1;
	ModePicSelectFunc(false, 2, i);
//    ModePicSelectFunc(false, 2);
    return false;
}

static bool onButtonClick_ButtonSelect5(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonSelect5 !!!\n");
    int i;
	for(i = 0;i < 5;i++)
	{
		LayoutPosition lp = mWindowSelectModePtr[i]->getPosition();
		LayoutPosition lp1 = mButtonSelect5Ptr->getPosition();
		if(lp1 == lp)
		{
			LOGD("break!!! \n");
			break;
		}

	}
	LOGD("i : %d", i);
	ButtonModeSelectStatus = true;
//	g_MovePicPosThread = 1;
	ModePicSelectFunc(true, 1, i);
//    ModePicSelectFunc(true, 2);
    return false;
}

static bool onButtonClick_ButtonSelect4(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonSelect4 !!!\n");
    int i;
	for(i = 0;i < 5;i++)
	{
		LayoutPosition lp = mWindowSelectModePtr[i]->getPosition();
		LayoutPosition lp1 = mButtonSelect4Ptr->getPosition();
		if(lp1 == lp)
		{
			LOGD("break!!! \n");
			break;
		}

	}
	LOGD("i : %d", i);
	ButtonModeSelectStatus = true;
//	g_MovePicPosThread = 1;
	ModePicSelectFunc(true, 2, i);
//    ModePicSelectFunc(true, 1);
    return false;
}
