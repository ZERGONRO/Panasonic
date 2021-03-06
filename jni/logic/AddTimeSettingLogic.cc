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


static float scale = 0.0;
static int TimeSet1 = 0, TimeSet2 = 0;
static EquipmentTiming DeviceTimes;
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
	LayoutPosition lpWindowMain = mWindowMainPtr->getPosition();
	LayoutPosition lpWindowDisp = mWindowDispPtr->getPosition();
	LayoutPosition lpWindowContent = mWindowContentPtr->getPosition();
	LayoutPosition lpWindowRoll = mWindowRollPtr->getPosition();

	scale = (float)(lpWindowDisp.mHeight / lpWindowContent.mHeight);
	lpWindowRoll.mHeight = lpWindowRoll.mHeight * scale;

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
static bool onAddTimeSettingActivityTouchEvent(const MotionEvent &ev) {
	LayoutPosition lpWindowMain = mWindowMainPtr->getPosition();
	LayoutPosition lpWindowDisp = mWindowDispPtr->getPosition();
	static int PosY = 0;
    switch (ev.mActionStatus) {
		case MotionEvent::E_ACTION_DOWN://触摸按下
		{
			//LOGD("时刻 = %ld 坐标  x = %d, y = %d", ev.mEventTime, ev.mX, ev.mY);
//			if((ev.mY > (lpWindowMain.mTop + lpWindowDisp.mTop)) && (ev.mY < (lpWindowMain.mTop + lpWindowDisp.mTop + lpWindowMain.mHeight)) && (ev.mX > (lpWindowMain.mLeft + lpWindowDisp.mLeft)) && (ev.mX < (lpWindowMain.mLeft + lpWindowDisp.mLeft + lpWindowMain.mWidth)))
//			{
//			if((ev.mY > (lpWindowMain.mTop)) && (ev.mY < (lpWindowMain.mTop + lpWindowMain.mHeight)) && (ev.mX > (lpWindowMain.mLeft)) && (ev.mX < (lpWindowMain.mLeft + lpWindowDisp.mLeft)))
			if((ev.mY > (lpWindowMain.mTop + lpWindowDisp.mTop)) && (ev.mY < (lpWindowMain.mTop + lpWindowDisp.mTop + lpWindowMain.mHeight)) && (ev.mX > (lpWindowMain.mLeft + lpWindowDisp.mLeft)) && (ev.mX < (lpWindowMain.mLeft + lpWindowDisp.mLeft + lpWindowMain.mWidth)))
			{
				PosY = ev.mY;
			}


		}
			break;
		case MotionEvent::E_ACTION_MOVE://触摸滑动
		{
//			if((ev.mY > (lpWindowMain.mTop)) && (ev.mY < (lpWindowMain.mTop + lpWindowMain.mHeight)) && (ev.mX > (lpWindowMain.mLeft)) && (ev.mX < (lpWindowMain.mLeft + lpWindowMain.mWidth)))
//			{
			if((ev.mY > (lpWindowMain.mTop + lpWindowDisp.mTop)) && (ev.mY < (lpWindowMain.mTop + lpWindowDisp.mTop + lpWindowMain.mHeight)) && (ev.mX > (lpWindowMain.mLeft + lpWindowDisp.mLeft)) && (ev.mX < (lpWindowMain.mLeft + lpWindowDisp.mLeft + lpWindowMain.mWidth)))
			{
				int dst = ev.mY - PosY;
				LayoutPosition lpWindowContent = mWindowContentPtr->getPosition();
				LayoutPosition lpWindowRoll = mWindowRollPtr->getPosition();
				if(lpWindowContent.mHeight > lpWindowRoll.mHeight)
				{
					lpWindowContent.mTop += dst;
					lpWindowRoll.mTop -= (dst * scale);
					if(abs(dst) > 5)
					{
						if(dst >= 0)
						{
							if(lpWindowContent.mTop >= 0)
							{
								lpWindowContent.mTop = 0;
								lpWindowRoll.mTop = 0;
							}
						}
						else
						{
							if((lpWindowDisp.mHeight - lpWindowContent.mHeight) > lpWindowContent.mTop)
							{
								lpWindowContent.mTop = lpWindowDisp.mHeight - lpWindowContent.mHeight;
								lpWindowRoll.mTop = lpWindowDisp.mHeight - lpWindowRoll.mHeight;

								if(lpWindowRoll.mHeight == 12)
								{
									lpWindowRoll.mTop += (12 * scale * dst);
								}
							}
						}
						mWindowContentPtr->setPosition(lpWindowContent);
						mWindowRollPtr->setPosition(lpWindowRoll);
					}
				}

			}
			PosY = ev.mY;
		}
			break;
		case MotionEvent::E_ACTION_UP:  //触摸抬起
		{
			PosY = 0;
		}
			break;
		default:
			break;
	}
	return false;
}
static bool onButtonClick_ButtonAddTime(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAddTime !!!\n");
    return false;
}

static bool onButtonClick_ButtonEveryDay(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonEveryDay !!!\n");
    if (pButton->isSelected()){
    	pButton->setSelected(false);
    	mButtonMonPtr->setSelected(false);
    	mButtonTuesPtr->setSelected(false);
    	mButtonWenPtr->setSelected(false);
    	mButtonThuePtr->setSelected(false);
    	mButtonFriPtr->setSelected(false);
    	mButtonSatPtr->setSelected(false);
    	mButtonSunPtr->setSelected(false);
    }else{
    	pButton->setSelected(true);
		mButtonMonPtr->setSelected(true);
		mButtonTuesPtr->setSelected(true);
		mButtonWenPtr->setSelected(true);
		mButtonThuePtr->setSelected(true);
		mButtonFriPtr->setSelected(true);
		mButtonSatPtr->setSelected(true);
		mButtonSunPtr->setSelected(true);
    }
    return false;
}

static bool onButtonClick_ButtonMon(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonMon !!!\n");
    if (pButton->isSelected()){
    	pButton->setSelected(false);
    }else{
    	pButton->setSelected(true);
    }
    return false;
}

static bool onButtonClick_ButtonTues(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonTues !!!\n");
    if (pButton->isSelected()){
    	pButton->setSelected(false);
    }else{
	    pButton->setSelected(true);
    }
    return false;
}

static bool onButtonClick_ButtonWen(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonWen !!!\n");
    if (pButton->isSelected()){
       	pButton->setSelected(false);
   }else{
   	    pButton->setSelected(true);
   }
    return false;
}

static bool onButtonClick_ButtonThue(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonThue !!!\n");
    if (pButton->isSelected()){
       	pButton->setSelected(false);
	}else{
		pButton->setSelected(true);
	}
    return false;
}

static bool onButtonClick_ButtonFri(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonFri !!!\n");
    if (pButton->isSelected()){
       	pButton->setSelected(false);
   }else{
   	    pButton->setSelected(true);
   }
    return false;
}

static bool onButtonClick_ButtonSat(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonSat !!!\n");
    if (pButton->isSelected()){
       	pButton->setSelected(false);
   }else{
   	    pButton->setSelected(true);
   }
    return false;
}

static bool onButtonClick_ButtonSun(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonSun !!!\n");
    if (pButton->isSelected()){
       	pButton->setSelected(false);
   }else{
   	    pButton->setSelected(true);
   }
    return false;
}

static bool onButtonClick_ButtonDel1(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonDel1 !!!\n");
    int num1, num2;
	char timebuf[10];
	TimeSet1 -= 30;
	if (TimeSet1 == -30){
		TimeSet1 = 1410;
	}
	num1 = TimeSet1 / 60;
	num2 = TimeSet1 % 60;

	sprintf(timebuf, "%02d:%02d", num1, num2);
	mTextView4Ptr->setText(timebuf);
    return false;
}

static bool onButtonClick_ButtonAdd1(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAdd1 !!!\n");
    LOGD(" %d\n",atoi(mTextView4Ptr->getText().c_str()));
    int num1, num2;
    char timebuf[10];
    TimeSet1 += 30;
    if (TimeSet1 == 1440)
       	TimeSet1 = 0;
    num1 = TimeSet1 / 60;
    num2 = TimeSet1 % 60;

    sprintf(timebuf, "%02d:%02d", num1, num2);
    mTextView4Ptr->setText(timebuf);
    return false;
}

static bool onButtonClick_ButtonDel2(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonDel2 !!!\n");
    int num1, num2;
   	char timebuf[10];
   	TimeSet2 -= 30;
   	if (TimeSet2 == -30){
   		TimeSet2 = 1410;
	}
   	num1 = TimeSet2 / 60;
   	num2 = TimeSet2 % 60;
   	sprintf(timebuf, "%02d:%02d", num1, num2);
   	mTextView6Ptr->setText(timebuf);
    return false;
}

static bool onButtonClick_ButtonAdd2(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAdd2 !!!\n");
    LOGD(" %d\n",atoi(mTextView6Ptr->getText().c_str()));
    int num1, num2;
	char timebuf[10];
	TimeSet2 += 30;
	if (TimeSet2 == 1440){
		TimeSet2 = 0;
	}
	num1 = TimeSet2 / 60;
	num2 = TimeSet2 % 60;
	sprintf(timebuf, "%02d:%02d", num1, num2);
	mTextView6Ptr->setText(timebuf);
    return false;
}

static bool onButtonClick_ButtonDel3(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonDel3 !!!\n");
    mTextView8Ptr->setText(atoi(mTextView8Ptr->getText().c_str()) - 1);
    if (atoi(mTextView8Ptr->getText().c_str()) < 15){
    	mTextView8Ptr->setText("15");
    }
    return false;
}

static bool onButtonClick_ButtonAdd3(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAdd3 !!!\n");
    mTextView8Ptr->setText(atoi(mTextView8Ptr->getText().c_str()) + 1);
    if (atoi(mTextView8Ptr->getText().c_str()) > 27){
		mTextView8Ptr->setText("27");
    }
    return false;
}

static bool onButtonClick_ButtonDel4(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonDel4 !!!\n");
    return false;
}

static bool onButtonClick_ButtonAdd4(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAdd4 !!!\n");
    return false;
}

static bool onButtonClick_ButtonDel5(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonDel5 !!!\n");
    return false;
}

static bool onButtonClick_ButtonAdd5(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAdd5 !!!\n");
    return false;
}

static bool onButtonClick_ButtonDel6(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonDel6 !!!\n");
    return false;
}

static bool onButtonClick_ButtonAdd6(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonAdd6 !!!\n");
    return false;
}

static bool onButtonClick_Button2(ZKButton *pButton) {
    LOGD(" ButtonClick Button2 !!!\n");
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

static bool onButtonClick_Button8(ZKButton *pButton) {
    LOGD(" ButtonClick Button8 !!!\n");
    return false;
}

static bool onButtonClick_Button9(ZKButton *pButton) {
    LOGD(" ButtonClick Button9 !!!\n");
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
    return false;
}

static bool onButtonClick_Button10(ZKButton *pButton) {
    LOGD(" ButtonClick Button10 !!!\n");
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
    return false;
}

static bool onButtonClick_Button23(ZKButton *pButton) {
    LOGD(" ButtonClick Button23 !!!\n");
    return false;
}

static bool onButtonClick_Button1(ZKButton *pButton) {
    LOGD(" ButtonClick Button1 !!!\n");
    return false;
}

static bool onButtonClick_Button24(ZKButton *pButton) {
    LOGD(" ButtonClick Button24 !!!\n");
    return false;
}

static bool onButtonClick_Button25(ZKButton *pButton) {
    LOGD(" ButtonClick Button25 !!!\n");
    return false;
}

static bool onButtonClick_Button26(ZKButton *pButton) {
    LOGD(" ButtonClick Button26 !!!\n");
    return false;
}

static bool onButtonClick_Button27(ZKButton *pButton) {
    LOGD(" ButtonClick Button27 !!!\n");
    return false;
}

static bool onButtonClick_Button28(ZKButton *pButton) {
    LOGD(" ButtonClick Button28 !!!\n");
    return false;
}

static bool onButtonClick_ButtonCancel(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonCancel !!!\n");
    EASYUICONTEXT->goBack();
    return false;
}

static bool onButtonClick_ButtonConfire(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonConfire !!!\n");
    if ((TimeSet1 > TimeSet2)){// && (TimeSet1 != 0 && TimeSet2 != 0)){
    	LOGD("Set Time Error\n");
    	return false;
    }
//    DeviceTimes.Time1 = TimeSet1;
//    DeviceTimes.Time2 = TimeSet2;
//    DeviceTimes.Temp1 = atoi(mTextView8Ptr->getText().c_str());
//    MACHINESTATUS->setEquipmentTimingFunc(DeviceTimes);
    EASYUICONTEXT->goBack();
    return false;
}
