#pragma once
#include "uart/ProtocolSender.h"
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

static int ManualMode = 0;

/**
 * 注册定时器
 * 填充数组用于注册定时器
 * 注意：id不能重复
 */
static S_ACTIVITY_TIMEER REGISTER_ACTIVITY_TIMER_TAB[] = {
	//{0,  6000}, //定时器id=0, 时间间隔6秒
	//{1,  1000},
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
static bool onManualModeActivityTouchEvent(const MotionEvent &ev) {
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


void DisPlayManualMode(int index)
{
	switch(index)
	{
		case 0:
		{
			mButtonAirPtr->setSelected(true);
			mButtonWindPtr->setSelected(false);
			mButtonHumdPtr->setSelected(false);

			mWindowAirPtr->setVisible(true);
			mWindowWindSwitchPtr->setVisible(false);
			mWindowHumdSwitchPtr->setVisible(false);

			if(mButtonAirOpenPtr->isSelected())
			{
				mButtonAirLessPtr->setSelected(true);
				mButtonAirAddPtr->setSelected(true);
				mTextView7Ptr->setSelected(true);		//mTextView7Ptr->setTextColor(color)
				mTextView8Ptr->setSelected(true);

				if(mTextView7Ptr->getText() <= "17")
				{
					mButtonAirLessPtr->setSelected(false);
					mTextView7Ptr->setText(17);
				}
				else if(mTextView7Ptr->getText() >= "27")
				{
					mButtonAirAddPtr->setSelected(false);
					mTextView7Ptr->setText(27);
				}
			}
			else
			{
				mButtonAirLessPtr->setSelected(false);
				mButtonAirAddPtr->setSelected(false);
				mTextView7Ptr->setSelected(false);		//mTextView7Ptr->setTextColor(color)
				mTextView8Ptr->setSelected(false);
			}
		}
			break;

		case 1:
		{
			mButtonAirPtr->setSelected(false);
			mButtonWindPtr->setSelected(true);
			mButtonHumdPtr->setSelected(false);

			mWindowAirPtr->setVisible(false);
			mWindowWindSwitchPtr->setVisible(true);
			mWindowHumdSwitchPtr->setVisible(false);

			if(mButtonWindOpenPtr->isSelected())
			{
				if(mButtonWindWeakPtr->isSelected())
				{
					mButtonWindWeakPtr->setSelected(true);
					mButtonWindStrongPtr->setSelected(false);
				}
				else
				{
					mButtonWindWeakPtr->setSelected(false);
					mButtonWindStrongPtr->setSelected(true);
				}

				if(mButtonWindAutoPtr->isSelected())
				{
					mButtonWindAutoPtr->setSelected(true);
					mButtonWindHotReplacePtr->setSelected(false);
					mButtonWindOrdChangeAirPtr->setSelected(false);
				}
				else if(mButtonWindHotReplacePtr->isSelected())
				{
					mButtonWindAutoPtr->setSelected(false);
					mButtonWindHotReplacePtr->setSelected(true);
					mButtonWindOrdChangeAirPtr->setSelected(false);
				}
				else
				{
					mButtonWindAutoPtr->setSelected(false);
					mButtonWindHotReplacePtr->setSelected(false);
					mButtonWindOrdChangeAirPtr->setSelected(true);
				}
			}
			else
			{
				mButtonWindWeakPtr->setSelected(false);
				mButtonWindAutoPtr->setSelected(false);
				mButtonWindHotReplacePtr->setSelected(false);
				mButtonWindOrdChangeAirPtr->setSelected(false);
				mButtonWindStrongPtr->setSelected(false);
			}
		}
			break;

		case 2:
		{
			mButtonAirPtr->setSelected(false);
			mButtonWindPtr->setSelected(false);
			mButtonHumdPtr->setSelected(true);

			mWindowAirPtr->setVisible(false);
			mWindowWindSwitchPtr->setVisible(false);
			mWindowHumdSwitchPtr->setVisible(true);

			if(mButtonHumdOpenPtr->isSelected())
			{
				mButtonHumdLessPtr->setSelected(true);
				mButtonHumdAddPtr->setSelected(true);
				mTextView16Ptr->setSelected(true);		//mTextView7Ptr->setTextColor(color)
				mTextView24Ptr->setSelected(true);

				if(mTextView16Ptr->getText() <= "30")
				{
					mButtonHumdLessPtr->setSelected(false);
					mTextView16Ptr->setText(30);
				}
				else if(mTextView16Ptr->getText() >= "70")
				{
					mButtonHumdAddPtr->setSelected(false);
					mTextView16Ptr->setText(70);
				}
			}
			else
			{
				mButtonHumdLessPtr->setSelected(false);
				mButtonHumdAddPtr->setSelected(false);
				mTextView16Ptr->setSelected(false);		//mTextView7Ptr->setTextColor(color)
				mTextView24Ptr->setSelected(false);
			}
		}
			break;
		default:
			break;

	}
}

static bool onButtonClick_ButtonDropDown(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonDropDown !!!\n");
    return false;
}
static bool onButtonClick_ButtonAir(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAir !!!\n");
    if(ManualMode != Manual_AirMode)
    	ManualMode = Manual_AirMode;
    if(pButton->isSelected())
    {
    	return false;
    }
    else
    {
    	pButton->setSelected(true);
    	//调用相关模式的窗口
    	DisPlayManualMode(ManualMode);
    }
    return false;
}

static bool onButtonClick_ButtonWind(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonWind !!!\n");
    if(ManualMode != Manual_Wind)
    	ManualMode = Manual_Wind;
	if(pButton->isSelected())
	{
		return false;
	}
	else
	{
		pButton->setSelected(true);
		//调用相关模式的窗口
		DisPlayManualMode(ManualMode);
	}
    return false;
}

static bool onButtonClick_ButtonHumd(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHumd !!!\n");
    if(ManualMode != Manual_Humd)
    	ManualMode = Manual_Humd;
	if(pButton->isSelected())
	{
	   return false;
	}
	else
	{
	   pButton->setSelected(true);
	   //调用相关模式的窗口
	   DisPlayManualMode(ManualMode);
	}
    return false;
}

static bool onButtonClick_ButtonWindAuto(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonWindAuto !!!\n");
    if(mButtonWindOpenPtr->isSelected())
    {
		if(pButton->isSelected())
		{
			return false;
		}
		else
		{
			pButton->setSelected(true);
			mButtonWindHotReplacePtr->setSelected(false);
			mButtonWindOrdChangeAirPtr->setSelected(false);
		}
    }

    return false;
}

static bool onButtonClick_ButtonWindHotReplace(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonWindHotReplace !!!\n");
    if(mButtonWindOpenPtr->isSelected())
    {
		if(pButton->isSelected())
		{
			return false;
		}
		else
		{
			pButton->setSelected(true);
			mButtonWindAutoPtr->setSelected(false);
			mButtonWindOrdChangeAirPtr->setSelected(false);
		}
    }
    return false;
}

static bool onButtonClick_ButtonWindOrdChangeAir(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonWindOrdChangeAir !!!\n");
    if(mButtonWindOpenPtr->isSelected())
    {
		if(pButton->isSelected())
		{
			return false;
		}
		else
		{
			pButton->setSelected(true);
			mButtonWindAutoPtr->setSelected(false);
			mButtonWindHotReplacePtr->setSelected(false);
		}
    }
    return false;
}

static bool onButtonClick_ButtonWindWeak(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonWindWeak !!!\n");
    if(mButtonWindOpenPtr->isSelected())
	{
		if(pButton->isSelected())
		{
			return false;
		}
		else
		{
			pButton->setSelected(true);
			mButtonWindStrongPtr->setSelected(false);

		}
	}
    return false;
}

static bool onButtonClick_ButtonWindStrong(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonWindStrong !!!\n");
    if(mButtonWindOpenPtr->isSelected())
   	{
   		if(pButton->isSelected())
   		{
   			return false;
   		}
   		else
   		{
   			pButton->setSelected(true);
   			mButtonWindWeakPtr->setSelected(false);

   		}
   	}
    return false;
}
static bool onButtonClick_ButtonWindOpen(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonWindOpen !!!\n");
    if(pButton->isSelected())
	{
    	mButtonWindWeakPtr->setSelected(false);
    	mButtonWindStrongPtr->setSelected(false);
    	mButtonWindAutoPtr->setSelected(false);
    	mButtonWindHotReplacePtr->setSelected(false);
    	mButtonWindOrdChangeAirPtr->setSelected(false);
	}
	else
	{
		pButton->setSelected(true);
		if(mButtonWindWeakPtr->isSelected())
		{
			mButtonWindWeakPtr->setSelected(true);
			mButtonWindStrongPtr->setSelected(false);
		}
		else
		{
			mButtonWindWeakPtr->setSelected(false);
			mButtonWindStrongPtr->setSelected(true);
		}

		if(mButtonWindAutoPtr->isSelected())
		{
			mButtonWindAutoPtr->setSelected(true);
			mButtonWindHotReplacePtr->setSelected(false);
			mButtonWindOrdChangeAirPtr->setSelected(false);
		}
		else if(mButtonWindHotReplacePtr->isSelected())
		{
			mButtonWindAutoPtr->setSelected(false);
			mButtonWindHotReplacePtr->setSelected(true);
			mButtonWindOrdChangeAirPtr->setSelected(false);
		}
		else
		{
			mButtonWindAutoPtr->setSelected(false);
			mButtonWindHotReplacePtr->setSelected(false);
			mButtonWindOrdChangeAirPtr->setSelected(true);
		}

	}
    return false;
}

static bool onButtonClick_ButtonWindTimePic(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonWindTimePic !!!\n");
    EASYUICONTEXT->openActivity("AddTimeSettingActivity", NULL);

    return false;
}

static bool onButtonClick_ButtonWindTimeOpen(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonWindTimeOpen !!!\n");
    EASYUICONTEXT->openActivity("AddTimeSettingActivity", NULL);
    return false;
}

static bool onButtonClick_ButtonAirOpen(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirOpen !!!\n");
    if(pButton->isSelected())
    {
    	mButtonAirLessPtr->setSelected(false);
		mButtonAirAddPtr->setSelected(false);
		mTextView7Ptr->setSelected(false);
		mTextView8Ptr->setSelected(false);
    }
    else
    {
    	pButton->setSelected(true);
    	mButtonAirLessPtr->setSelected(true);
    	mButtonAirAddPtr->setSelected(true);
    	mTextView7Ptr->setSelected(true);
    	mTextView8Ptr->setSelected(true);

    	if(mTextView7Ptr->getText() <= "17")
    	{
    		mButtonAirLessPtr->setSelected(false);
    		mTextView7Ptr->setText(17);
    	}
    	else if(mTextView7Ptr->getText() >= "27")
    	{
    		mButtonAirAddPtr->setSelected(false);
    		mTextView7Ptr->setText(27);
    	}

    }
    return false;
}

static bool onButtonClick_ButtonAirTimePic(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirTimePic !!!\n");
    EASYUICONTEXT->openActivity("AddTimeSettingActivity", NULL);
    return false;
}

static bool onButtonClick_ButtonAirTimeOpen(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirTimeOpen !!!\n");
    EASYUICONTEXT->openActivity("AddTimeSettingActivity", NULL);
    return false;
}

static bool onButtonClick_ButtonAirLess(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirLess !!!\n");
    if(mButtonAirOpenPtr->isSelected())
    {
    	if(mTextView7Ptr->getText() <= "17")
		{
			mButtonAirLessPtr->setSelected(false);
			mTextView7Ptr->setText(17);
			return false;
		}
    	else
    	{
    		//mTextView7Ptr->setText(mTextView7Ptr->getText() - "1");
    	}
    }
    return false;
}

static bool onButtonClick_ButtonAirAdd(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAirAdd !!!\n");
    if(mButtonAirOpenPtr->isSelected())
	{
		if(mTextView7Ptr->getText() >= "27")
		{
			mButtonAirAddPtr->setSelected(false);
			mTextView7Ptr->setText(27);
			return false;
		}
		else
		{
			//mTextView7Ptr->setText(mTextView7Ptr->getText() + "1");
		}
	}
    return false;
}

static bool onButtonClick_ButtonHumdOpen(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHumdOpen !!!\n");
    if(mButtonAirOpenPtr->isSelected())
    {
    	//提示弹框请关闭新风调湿
    }
    else
    {
		if(pButton->isSelected())
		{
			mButtonHumdLessPtr->setSelected(false);
			mButtonHumdAddPtr->setSelected(false);
			mTextView16Ptr->setSelected(false);		//mTextView7Ptr->setTextColor(color)
			mTextView24Ptr->setSelected(false);
		}
		else
		{
			mButtonHumdLessPtr->setSelected(true);
			mButtonHumdAddPtr->setSelected(true);
			mTextView16Ptr->setSelected(true);		//mTextView7Ptr->setTextColor(color)
			mTextView24Ptr->setSelected(true);

			if(mTextView16Ptr->getText() <= "30")
			{
				mButtonHumdLessPtr->setSelected(false);
				mTextView16Ptr->setText(30);
			}
			else if(mTextView16Ptr->getText() >= "70")
			{
				mButtonHumdAddPtr->setSelected(false);
				mTextView16Ptr->setText(70);
			}
		}
    }
    return false;
}

static bool onButtonClick_ButtonHumdTimePic(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHumdTimePic !!!\n");
    EASYUICONTEXT->openActivity("AddTimeSettingActivity", NULL);
    return false;
}

static bool onButtonClick_ButtonHumdTimeOpen(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHumdTimeOpen !!!\n");
    EASYUICONTEXT->openActivity("AddTimeSettingActivity", NULL);
    return false;
}

static bool onButtonClick_ButtonHumdLess(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHumdLess !!!\n");
    if(mButtonHumdOpenPtr->isSelected())
	{
		if(mTextView7Ptr->getText() <= "30")
		{
			mButtonHumdLessPtr->setSelected(false);
			mTextView7Ptr->setText(30);
			return false;
		}
		else
		{
			//mTextView16Ptr->setText(mTextView7Ptr->getText() - "1");
		}
	}
    return false;
}

static bool onButtonClick_ButtonHumdAdd(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHumdAdd !!!\n");
    if(mButtonHumdOpenPtr->isSelected())
   	{
   		if(mTextView7Ptr->getText() >= "70")
   		{
   			mButtonHumdAddPtr->setSelected(false);
   			mTextView7Ptr->setText(70);
   			return false;
   		}
   		else
   		{
   			//mTextView16Ptr->setText(mTextView7Ptr->getText() + "1");
   		}
   	}
    return false;
}
