#pragma once
#include "uart/ProtocolSender.h"
#include "util/MyNetWorkingListener.h"
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
#define PASSWORK_DESCRIPTION_STRING "请输入密码"
extern MyNetWorkingListener *nwlistener;
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
    	std::string ssid = intentPtr->getExtra("ssid");
		mTextViewSSIDPtr->setText(ssid.c_str());
    }
}

/*
 * 当界面显示时触发
 */
static void onUI_show() {
	mIconWifiPtr->setVisible(nwlistener->IsConnected());
	if(mPassWordTextViewPtr->getText().c_str() < 8 || mPassWordTextViewPtr->getText().c_str() > 64
			|| mPassWordTextViewPtr->getText().compare(PASSWORK_DESCRIPTION_STRING))
	{
		int w, h;
		LayoutPosition lp = mPassWordTextViewPtr->getPosition();
		mPassWordTextViewPtr->getTextExtent(mPassWordTextViewPtr->getText().c_str(), w, h);
		if (w >= lp.mWidth) {
			mPassWordTextViewPtr->setVisible(false);
			mPassWordTextView2Ptr->setVisible(true);
		} else {
			mPassWordTextViewPtr->setVisible(true);
			mPassWordTextView2Ptr->setVisible(false);
		}
		mButtonConfirmPtr->setInvalid(true);
		mButton22Ptr->setInvalid(true);
	}
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
static bool onWifiInputUIActivityTouchEvent(const MotionEvent &ev) {
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
static bool onButtonClick_ButtonBack(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonBack !!!\n");
    EASYUICONTEXT->goBack();
    return false;
}

static bool onButtonClick_ButtonConfirm(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonConfirm !!!\n");
    if((mPassWordTextViewPtr->getText() != PASSWORK_DESCRIPTION_STRING)
		&& (mPassWordTextViewPtr->getText().length() >= 8 && mPassWordTextViewPtr->getText().length() <= 64)) {
    	nwlistener->startConnectWifi(mTextViewSSIDPtr->getText().c_str(), mPassWordTextViewPtr->getText().c_str());
   }
   else {
	   LOGD("WIFI password wrong format\n");
	//应在界面有相应提示
   }
   EASYUICONTEXT->goBack();
    return false;
}

static bool onButtonClick_ButtonQ(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonQ !!!\n");
	if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_ButtonW(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonW !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());


    return false;
}

static bool onButtonClick_ButtonE(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonE !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());


    return false;
}

static bool onButtonClick_ButtonR(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonR !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());


    return false;
}

static bool onButtonClick_ButtonT(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonT !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());


    return false;
}

static bool onButtonClick_ButtonY(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonY !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());


    return false;
}

static bool onButtonClick_ButtonU(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonU !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());


    return false;
}

static bool onButtonClick_ButtonI(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonI !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());


    return false;
}

static bool onButtonClick_ButtonO(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonO !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());


    return false;
}

static bool onButtonClick_ButtonP(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonP !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());


    return false;
}

static bool onButtonClick_ButtonBackspace(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonBackspace !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING) {
		return false;
	}
	if(mPassWordTextViewPtr->getText().length() <= 1) {
		mPassWordTextViewPtr->setText(PASSWORK_DESCRIPTION_STRING);
	}
	else {
		char *psw = mPassWordTextViewPtr->getText().c_str();
		psw[mPassWordTextViewPtr->getText().length() - 1] = 0;
		mPassWordTextViewPtr->setText(psw);
	}
    return false;
}

static bool onButtonClick_ButtonA(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonA !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());


    return false;
}

static bool onButtonClick_ButtonS(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonS !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());


    return false;
}

static bool onButtonClick_ButtonD(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonD !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());


    return false;
}

static bool onButtonClick_ButtonF(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonF !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());


    return false;
}

static bool onButtonClick_ButtonG(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonG !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());


    return false;
}

static bool onButtonClick_ButtonH(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonH !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());


    return false;
}

static bool onButtonClick_ButtonJ(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonJ !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());


    return false;
}

static bool onButtonClick_ButtonK(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonK !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_ButtonL(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonL !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_Button22(ZKButton *pButton) {
    LOGD(" ButtonClick Button22 !!!\n");
	if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
		mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());
	   return false;
}

static bool onButtonClick_ButtonExclamation(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonExclamation !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
		mPassWordTextViewPtr->setText("!");
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + "!");
	return false;
}

static bool onButtonClick_ButtonUpper(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonUpper !!!\n");
    for(int i = 0 ; i < 26 ; i++) {
		if(mButtonWords[i]->isSelected()) {
			char *psw = mButtonWords[i]->getText().c_str();
			psw[0] += 32;
			mButtonWords[i]->setText(psw[0]);
			mButtonWords[i]->setSelected(false);
		}
		else {
			char *psw = mButtonWords[i]->getText().c_str();
			psw[0] -= 32;
			mButtonWords[i]->setText(psw[0]);
			mButtonWords[i]->setSelected(true);
		}
	}
    return false;
}

static bool onButtonClick_ButtonM(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonM !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
   	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
   	else
   		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_ButtonC(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonC !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
   	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
   	else
   		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_ButtonX(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonX !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
   	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
   	else
   		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_ButtonB(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonB !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
   	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
   	else
   		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_ButtonZ(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonZ !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
   	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
   	else
   		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_ButtonV(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonV !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
   	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
   	else
   		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_ButtonN(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonN !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
   	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
   	else
   		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_ButtonQM(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonQM !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
   		mPassWordTextViewPtr->setText(pButton->getText().c_str());
   	else
   		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());
   return false;
}

static bool onButtonClick_ButtonUpper2(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonUpper2 !!!\n");
    for(int i = 0 ; i < 26 ; i++) {
		if(mButtonWords[i]->isSelected()) {
			char *psw = mButtonWords[i]->getText().c_str();
			psw[0] += 32;
			mButtonWords[i]->setText(psw[0]);
			mButtonWords[i]->setSelected(false);
		}
		else {
			char *psw = mButtonWords[i]->getText().c_str();
			psw[0] -= 32;
			mButtonWords[i]->setText(psw[0]);
			mButtonWords[i]->setSelected(true);
		}
  	}
    return false;
}

static bool onButtonClick_ButtonNum(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonNum !!!\n");
    mWindow2Ptr->hideWnd();
	mWindow14Ptr->showWnd();
    return false;
}

static bool onButtonClick_ButtonSlash(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonSlash !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
		mPassWordTextViewPtr->setText("/");
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + "/");
    return false;
}

static bool onButtonClick_ButtonSpace(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonSpace !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
		mPassWordTextViewPtr->setText(" ");
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + " ");
	return false;
}

static bool onButtonClick_ButtonDCom(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonDCom !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
		mPassWordTextViewPtr->setText(".com");
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + ".com");
	return false;
}

static bool onButtonClick_ButtonNum2(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonNum2 !!!\n");
    mWindow2Ptr->hideWnd();
	mWindow14Ptr->showWnd();
    return false;
}

static bool onButtonClick_ButtonDot(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonDot !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
		mPassWordTextViewPtr->setText(".");
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + ".");
	return false;
}
static bool onButtonClick_Button1(ZKButton *pButton) {
    LOGD(" ButtonClick Button1 !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_Button2(ZKButton *pButton) {
    LOGD(" ButtonClick Button2 !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_Button3(ZKButton *pButton) {
    LOGD(" ButtonClick Button3 !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_Button4(ZKButton *pButton) {
    LOGD(" ButtonClick Button4 !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_Button5(ZKButton *pButton) {
    LOGD(" ButtonClick Button5 !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_Button6(ZKButton *pButton) {
    LOGD(" ButtonClick Button6 !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_Button7(ZKButton *pButton) {
    LOGD(" ButtonClick Button7 !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_Button8(ZKButton *pButton) {
    LOGD(" ButtonClick Button8 !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_Button9(ZKButton *pButton) {
    LOGD(" ButtonClick Button9 !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_Button0(ZKButton *pButton) {
    LOGD(" ButtonClick Button0 !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_Button11(ZKButton *pButton) {
    LOGD(" ButtonClick Button11 !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_Button12(ZKButton *pButton) {
    LOGD(" ButtonClick Button12 !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_Button13(ZKButton *pButton) {
    LOGD(" ButtonClick Button13 !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_Button14(ZKButton *pButton) {
    LOGD(" ButtonClick Button14 !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_Button15(ZKButton *pButton) {
    LOGD(" ButtonClick Button15 !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_Button16(ZKButton *pButton) {
    LOGD(" ButtonClick Button16 !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_Button17(ZKButton *pButton) {
    LOGD(" ButtonClick Button17 !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_Button18(ZKButton *pButton) {
    LOGD(" ButtonClick Button18 !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_Button19(ZKButton *pButton) {
    LOGD(" ButtonClick Button19 !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_Button20(ZKButton *pButton) {
    LOGD(" ButtonClick Button20 !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_Button21(ZKButton *pButton) {
    LOGD(" ButtonClick Button21 !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_Button23(ZKButton *pButton) {
    LOGD(" ButtonClick Button23 !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_Button24(ZKButton *pButton) {
    LOGD(" ButtonClick Button24 !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_Button25(ZKButton *pButton) {
    LOGD(" ButtonClick Button25 !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_Button26(ZKButton *pButton) {
    LOGD(" ButtonClick Button26 !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_Button27(ZKButton *pButton) {
    LOGD(" ButtonClick Button27 !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_Button28(ZKButton *pButton) {
    LOGD(" ButtonClick Button28 !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_Button29(ZKButton *pButton) {
    LOGD(" ButtonClick Button29 !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_Button30(ZKButton *pButton) {
    LOGD(" ButtonClick Button30 !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_Button31(ZKButton *pButton) {
    LOGD(" ButtonClick Button31 !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_Button32(ZKButton *pButton) {
    LOGD(" ButtonClick Button32 !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_Button33(ZKButton *pButton) {
    LOGD(" ButtonClick Button33 !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_Button34(ZKButton *pButton) {
    LOGD(" ButtonClick Button34 !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_Button35(ZKButton *pButton) {
    LOGD(" ButtonClick Button35 !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_Button10(ZKButton *pButton) {
    LOGD(" ButtonClick Button10 !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}

static bool onButtonClick_Button36(ZKButton *pButton) {
    LOGD(" ButtonClick Button36 !!!\n");
    if(mPassWordTextViewPtr->getText() == PASSWORK_DESCRIPTION_STRING)
	   mPassWordTextViewPtr->setText(pButton->getText().c_str());
	else
		mPassWordTextViewPtr->setText(mPassWordTextViewPtr->getText() + pButton->getText().c_str());

    return false;
}
