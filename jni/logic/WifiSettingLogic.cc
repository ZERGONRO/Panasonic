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

extern MyNetWorkingListener *nwlistener;
/**
 * 注册定时器
 * 填充数组用于注册定时器
 * 注意：id不能重复
 */
static S_ACTIVITY_TIMEER REGISTER_ACTIVITY_TIMER_TAB[] = {
	{0,  1000}, //定时器id=0, 时间间隔6秒
	//{1,  1000},
};

/**
 * 当界面构造时触发
 */
static void onUI_init(){
    //Tips :添加 UI初始化的显示代码到这里,如:mText1Ptr->setText("123");
	mTextViewConnectFailMsgPtr->setTextRowSpace(6);
	mTextViewConnectFailMsgPtr->setText("连接失败，\n请检查当前网络环境是否正常，\n账号/密码是否输入正确。");
}

/**
 * 当切换到该界面时触发
 */
static void onUI_intent(const Intent *intentPtr) {
    if (intentPtr != NULL) {
        //TODO
    }
//    LOGD("nwlistener->getWifiStatus() is : %d \n", nwlistener->getWifiStatus());
	if(nwlistener->getWifiStatus()) {
		mButtonWifiSwitchPtr->setSelected(false);
		nwlistener->ScanNetWork();
		nwlistener->firstfresh();
		wifiInfo = nwlistener->getSSIDInfo();
		mListViewWifiInfoPtr->setVisible(true);
		mListViewWifiInfoPtr->setSelection(0);
		mListViewWifiInfoPtr->refreshListView();
	}
	else {
		mButtonWifiSwitchPtr->setSelected(true);
		mListViewWifiInfoPtr->setVisible(false);
	}
}

/*
 * 当界面显示时触发
 */
static void onUI_show() {

	mWindowConnectFailPtr->setVisible(false);
	mIconWifiPtr->setVisible(MACHINESTATUS->getwifistatus());
	if(nwlistener->getWifiStatus()) {
		wifiInfo = nwlistener->getSSIDInfo();
		mListViewWifiInfoPtr->setVisible(true);
		mListViewWifiInfoPtr->setSelection(0);
		mListViewWifiInfoPtr->refreshListView();
	}
	mListViewWifiInfoPtr->setDecRatio(0.7);
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
	{
		if(nwlistener->getWifiStatus())
			nwlistener->resetScanCount();
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
static bool onWifiSettingActivityTouchEvent(const MotionEvent &ev) {
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

static bool onButtonClick_ButtonWifiSwitch(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonWifiSwitch !!!\n");
    if(pButton->isSelected())
    {
    	pButton->setSelected(false);
    	wifiInfo = nwlistener->getSSIDInfo();
    	mListViewWifiInfoPtr->setVisible(true);
    	nwlistener->startupWifi();
    	nwlistener->firstfresh();
    }
    else
    {
    	pButton->setSelected(true);
    	mListViewWifiInfoPtr->setVisible(false);
    	nwlistener->ShutdownWifi();
    }
    return false;
}

static int getListItemCount_ListViewWifiInfo(const ZKListView *pListView) {
    //LOGD("getListItemCount_ListViewWifiInfo !\n");
	if(!wifiInfo)
		return 0;
	if(wifiInfo->size())
		return wifiInfo->size();
	else
		return 0;
//    return 3;
}

static void obtainListItemData_ListViewWifiInfo(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListViewWifiInfo  !!!\n");
	ZKListView::ZKListSubItem *pWifiInfoItem = pListItem->findSubItemByID(ID_WIFISETTING_SSID);
	WifiInfo_t *child = wifiInfo->at(index);
	pWifiInfoItem->setText(child->ssid);

	pWifiInfoItem = pListItem->findSubItemByID(ID_WIFISETTING_IconConnectedStatus);
	int wifistatus = nwlistener->getWifiConnectStatus();
	if(wifistatus == 1)
	{
		if(nwlistener->getSSIDConnecting().length() > 0)
		{
			if(!strcmp(child->ssid, nwlistener->getSSIDConnecting().c_str()))
			{
				pWifiInfoItem->setText("连接中");
			}
			else
			{
				pWifiInfoItem->setText("");
			}
		}
		else
		{
		pWifiInfoItem->setText("");
		}
	}
	else if(wifistatus == 2)
	{
		if(nwlistener->getSSID().length() > 0)
		{
			if(!strcmp(child->ssid, nwlistener->getSSID().c_str()))
			{
				pWifiInfoItem->setText("已连接");
			}
			else
			{
				pWifiInfoItem->setText("");
			}
		}
		pWifiInfoItem->setText("");
	}
	else
	{
		pWifiInfoItem->setText("");
	}


}

static void onListItemClick_ListViewWifiInfo(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListViewWifiInfo  !!!\n");
	int wifistatus = nwlistener->getWifiConnectStatus();
	if(wifistatus == 2)
	{
		if(nwlistener->getSSID().length() > 0)
		{
			if(!strcmp(wifiInfo->at(index)->ssid, nwlistener->getSSID().c_str()))
			{
				return;
			}
		}
	}
	Intent* intent = new Intent();
	intent->putExtra("ssid", wifiInfo->at(index)->ssid);
	EASYUICONTEXT->openActivity("WifiInputUIActivity", intent);
}
static bool onButtonClick_ButtonKnow(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonKnow !!!\n");
    mWindowConnectFailPtr->setVisible(false);
    return false;
}
static bool onButtonClick_Button2(ZKButton *pButton) {
    LOGD(" ButtonClick Button2 !!!\n");
    EASYUICONTEXT->goBack();
    return false;
}
