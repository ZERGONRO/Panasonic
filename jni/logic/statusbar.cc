#pragma once
#include "uart/ProtocolSender.h"
#include "util/MyNetWorkingListener.h"
#include "util/MachineStatus.h"
/*
*此文件由GUI工具生成
*文件功能：用于处理用户的逻辑相应代码
*功能说明：
*========================onButtonClick_XXXX
当页面中的按键按下后系统会调用对应的函数，XXX代表GUI工具里面的[标识]名称，
如Button1,当返回值为false的时候系统将不再处理这个按键，返回true的时候系统将会继续处理此按键。比如SYS_BACK.
*========================onSlideWindowItemClick_XXXX(int index) 
当页面中存在滑动窗口并且用户点击了滑动窗口的图标后系统会调用此函数,XXX代表GUI工具里面的[标识]名称，
如slideWindow1;index 代表按下图标的偏移值
*========================onSeekBarChange_XXXX(int progress) 
当页面中存在滑动条并且用户改变了进度后系统会调用此函数,XXX代表GUI工具里面的[标识]名称，
如SeekBar1;progress 代表当前的进度值
*========================ogetListItemCount_XXXX() 
当页面中存在滑动列表的时候，更新的时候系统会调用此接口获取列表的总数目,XXX代表GUI工具里面的[标识]名称，
如List1;返回值为当前列表的总条数
*========================oobtainListItemData_XXXX(ZKListView::ZKListItem *pListItem, int index)
 当页面中存在滑动列表的时候，更新的时候系统会调用此接口获取列表当前条目下的内容信息,XXX代表GUI工具里面的[标识]名称，
如List1;pListItem 是贴图中的单条目对象，index是列表总目的偏移量。具体见函数说明
*========================常用接口===============
*LOGD(...)  打印调试信息的接口
*mTextXXX->setText("****") 在控件TextXXX上显示文字****
*mButton1->setSelected(true); 将控件mButton1设置为选中模式，图片会切换成选中图片，按钮文字会切换为选中后的颜色
*mSeekBar->setProgress(12) 在控件mSeekBar上将进度调整到12
*mListView1->refreshListView() 让mListView1 重新刷新，当列表数据变化后调用
*mDashbroadView1->setTargetAngle(120) 在控件mDashbroadView1上指针显示角度调整到120度

*/

static bool bDropDownButtonPress;
static bool bDropDown;
static bool bMoveThreadRun = false;
static pthread_t g_MoveThread = 0;
bool UpdateTimeFlag = false;
static bool Flag_Statusbus;


static bool bStatusBarInited = false;
extern MyNetWorkingListener *nwlistener;
extern void updateTime();

void initStatusBarMode()
{
	if(!bStatusBarInited)
	{
		bDropDown = false;
		bDropDownButtonPress = false;
		LayoutPosition lp = mstatusbarPtr->mMainWndPtr->getPosition();
//		LayoutPosition lp = mWindowMainStatusBarPtr->getPosition();
		lp.mTop = -630;
//		lp.mTop = -600;
		mstatusbarPtr->mMainWndPtr->setPosition(lp);
//		mWindowMainStatusBarPtr->setPosition(lp);
		bStatusBarInited = true;
	}
	nwlistener = NULL;
	Flag_Statusbus = true;
	mSeekBarLightPtr->setProgress(mSeekBarLightPtr->getProgress());
//	mSeekBarLightPtr->setProgress(50);
	mSeekBarLightPtr->setMax(99);
	mTextViewLightBarPtr->setText(std::to_string(mSeekBarLightPtr->getProgress()));
	mSeekBarSoundPtr->setProgress(mSeekBarSoundPtr->getProgress());
	mSeekBarSoundPtr->setMax(99);
	mTextViewSoundBarPtr->setText(std::to_string(mSeekBarSoundPtr->getProgress()));
//	mstatusbarPtr->mMainWndPtr->setAlpha(255);
}

void disableStatusbus(){
	Flag_Statusbus = false;
}

void enableStatusbus(){
	Flag_Statusbus = true;
}

void showstatusbars()
{
	LayoutPosition lp = mstatusbarPtr->mMainWndPtr->getPosition();
	lp.mTop = 0;
	mstatusbarPtr->mMainWndPtr->setPosition(lp);
	bDropDown = true;
}

void hidestatusbars()
{
	LayoutPosition lp = mstatusbarPtr->mMainWndPtr->getPosition();
	lp.mTop = -600;
	mstatusbarPtr->mMainWndPtr->setPosition(lp);
	bDropDown = false;
}

/**
 * 注册定时器
 * 填充数组用于注册定时器
 * 注意：id不能重复
 */
static S_ACTIVITY_TIMEER REGISTER_ACTIVITY_TIMER_TAB[] = {
	{0,  1000}, //定时器id=0, 时间间隔6秒
	{1,  1000},
};

/**
 * 当界面构造时触发
 */
static void onUI_init(){
    //Tips :添加 UI初始化的显示代码到这里,如:mText1->setText("123");
//	EASYUICONTEXT->hideNaviBar();
//	mTextViewAlphaPtr->setAlpha(5);
//	mWindowAlphaPtr->setAlpha(50);

}

/*
 * 当界面完全退出时触发
 */
static void onUI_quit() {
//	LayoutPosition lp3 = mWindowBackgroundPtr->getPosition();
//	lp3.mTop = -600;
//	mWindowBackgroundPtr->setAlpha(255);
//	mWindowBackgroundPtr->setPosition(lp3);
}

/**
 * 串口数据回调接口
 */
static void onProtocolDataUpdate(const SProtocolData &data) {
    //串口数据回调接口
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
	static int checkWifiCount = 0;
	static int checkWifiCount1 = 0;
	switch (id) {
		case 0:
			break;
		case 1:
		{
			if(nwlistener->IsConnected())
			{
				checkWifiCount++;
				if(checkWifiCount == 3)
				{
					UpdateTimeFlag = true;
//						system("/customer/ntpdate -v -t 5  ntp2.aliyun.com ntp3.aliyun.com pool.ntp.org&");
//							system("/customer/ntpdate -u cn.pool.ntp.org 0.asia.pool.ntp.org ntp1.aliyun.com ntp2.aliyun.com ntp3.aliyun.com&");
						system("/customer/ntpdate -u ntp2.aliyun.com&");
				}
			}
			else
			{
				checkWifiCount = 0;
			}


		}
			break;
		default:
			break;
	}
    return true;
}



static void *statusbarsMovePro(void *param)
{
//	mWindowBackgroundPtr->setAlpha(100);
	int dst = (int) param;
	LayoutPosition lp = mstatusbarPtr->mMainWndPtr->getPosition();
//	LayoutPosition lp = mWindowMainStatusBarPtr->getPosition();
	float speed = 50;
	while(bMoveThreadRun)
	{
		if(dst < 0)				//上拉
		{
			if(lp.mTop > -100)
			{
				lp.mTop += speed;
				if(lp.mTop >= 0)
				{
					lp.mTop = 0;

					bDropDown = true;
					bMoveThreadRun = false;
				}
				mstatusbarPtr->mMainWndPtr->setPosition(lp);
//				mWindowMainStatusBarPtr->setPosition(lp);
			}
			else
			{
				lp.mTop -= speed;
				if(lp.mTop <= -600)
				{
					lp.mTop = -600;
					bDropDown = false;
					bMoveThreadRun = false;
				}
				mstatusbarPtr->mMainWndPtr->setPosition(lp);
//				mWindowMainStatusBarPtr->setPosition(lp);
			}
		}
		else					//下滑
		{
			if(lp.mTop < -500)
			{
				lp.mTop -= speed;
				if(lp.mTop <= -600)
				{
					lp.mTop = -600;
					bDropDown = false;
					bMoveThreadRun = false;
				}
				mstatusbarPtr->mMainWndPtr->setPosition(lp);
//				mWindowMainStatusBarPtr->setPosition(lp);
			}
			else
			{
				lp.mTop += speed;
				if(lp.mTop >= 0)
				{
					lp.mTop = 0;

					bDropDown = true;
					bMoveThreadRun = false;
				}
				mstatusbarPtr->mMainWndPtr->setPosition(lp);
//				mWindowMainStatusBarPtr->setPosition(lp);
			}
		}
		speed *= 0.98;
		usleep(30 * 1000);
	}
	return NULL;
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
static bool onstatusbarActivityTouchEvent(const MotionEvent &ev) {
	LayoutPosition lp = mButtonDropDownPtr->getPosition();
	LayoutPosition lp1 = mstatusbarPtr->mMainWndPtr->getPosition();
//	LayoutPosition lp1 = mWindowMainStatusBarPtr->getPosition();
	static int x, y;
    switch (ev.mActionStatus) {
		case MotionEvent::E_ACTION_DOWN://触摸按下
		{
			if (!Flag_Statusbus){
				break;
			}
			//LOGD("时刻 = %ld 坐标  x = %d, y = %d", ev.mEventTime, ev.mX, ev.mY);
			if((ev.mY > 0) && (ev.mY < 100) && (ev.mX > 412) && (ev.mX < 612) && (!bDropDownButtonPress && !bDropDown))
			{
				x = ev.mX;
				y = ev.mY;
				bDropDownButtonPress = true;
				lp1.mTop = -530;
//				lp1.mTop = -500;
//				lp1.mTop = -330;
				mstatusbarPtr->mMainWndPtr->setPosition(lp1);
//				mWindowMainStatusBarPtr->setPosition(lp1);
			}
			else if((!bDropDownButtonPress && bDropDown) && ((ev.mY > 530) && (ev.mY < 600) && (ev.mX > lp.mLeft) && (ev.mX < lp.mLeft + lp.mWidth)))
			{
				x = ev.mX;
				y = ev.mY;
				bDropDownButtonPress = true;
			}

			if(g_MoveThread)
			{
				pthread_join(g_MoveThread, NULL);
				g_MoveThread = 0;

			}
		}
			break;
		case MotionEvent::E_ACTION_MOVE://触摸滑动
		{
			if(bDropDownButtonPress)
			{

				if(bDropDown)
				{
//					LayoutPosition lp = mWindowStatusBarPtr->getPosition();
					LayoutPosition lp = mstatusbarPtr->mMainWndPtr->getPosition();
//					LayoutPosition lp = mWindowMainStatusBarPtr->getPosition();
					if(abs(lp.mTop - ev.mY) < 5)
						return true;

					lp.mTop = (ev.mY - y) > 0?0 : (ev.mY - y);
					mstatusbarPtr->mMainWndPtr->setPosition(lp);
//					mWindowMainStatusBarPtr->setPosition(lp);

				}
				else
				{
//					LayoutPosition lp = mstatusbarPtr->mMainWndPtr->getPosition();
					LayoutPosition lp = mWindowBGPtr->getPosition();
					if(abs(lp.mTop - ev.mY) < 5)
						return true;

					lp.mTop = -530 + (ev.mY - y);
//					lp.mTop = -330 + (ev.mY - y);
					mstatusbarPtr->mMainWndPtr->setPosition(lp);
//					mWindowMainStatusBarPtr->setPosition(lp);
				}
			}
		}
			break;
		case MotionEvent::E_ACTION_UP:  //触摸抬起
		{
			mstatusbarPtr->resetUserTimer(1, 2000);
			if(bDropDownButtonPress)
			{
				bMoveThreadRun = true;
				pthread_create(&g_MoveThread, NULL, statusbarsMovePro, (void *)(ev.mY - y));
			}
			bDropDownButtonPress = false;
		}
			break;
		default:
			break;
	}
	return false;
}


static bool onButtonClick_ButtonDropDown(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonDropDown !!!\n");
    return false;
}

static void onProgressChanged_SeekBarLight(ZKSeekBar *pSeekBar, int progress) {
    //LOGD(" ProgressChanged SeekBarLight %d !!!\n", progress);
	char cmd[128];
	sprintf(cmd , "echo %d > /sys/class/pwm/pwmchip0/pwm0/duty_cycle" , progress + 1);
	system(cmd);
	MACHINESTATUS->setbacklight(progress+1);
	mTextViewLightBarPtr->setText(std::to_string(progress + 1));
}

static bool onButtonClick_ButtonEasyMode(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonEasyMode !!!\n");
    if(pButton->isSelected())
    {
    	pButton->setSelected(false);
    	EASYUICONTEXT->openActivity("mainActivity", NULL);
    }
    else
    {
    	pButton->setSelected(true);
    	EASYUICONTEXT->openActivity("EasyModeActivity", NULL);
    }
    return false;
}

static bool onButtonClick_ButtonDarkColor(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonDarkColor !!!\n");
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

static bool onButtonClick_ButtonSetting(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonSetting !!!\n");

	EASYUICONTEXT->openActivity("settingActivity", NULL);


    return false;
}
static bool onButtonClick_Button1(ZKButton *pButton) {
    LOGD(" ButtonClick Button1 !!!\n");
    hidestatusbars();
    EASYUICONTEXT->goBack();
    return false;
}

static void onProgressChanged_SeekBarSound(ZKSeekBar *pSeekBar, int progress) {
    //LOGD(" ProgressChanged SeekBarSound %d !!!\n", progress);
	char cmd[128];
//	sprintf(cmd , "echo %d > /sys/class/pwm/pwmchip0/pwm0/duty_cycle" , progress + 1);
//	system(cmd);
	MACHINESTATUS->setvol(progress+1);
	mTextViewSoundBarPtr->setText(std::to_string(progress + 1));
}
