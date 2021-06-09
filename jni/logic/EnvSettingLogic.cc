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

static Mutex lLock;
static std::vector<SpaceInfo *> EnvSettingVector;

static SpaceInfo SpaceInfoList[] = {
		{"卧室", "./ui/图标-天气-大雪-56.png", false},
		{"客厅", "./ui/图标-天气-晴-32.png", false},
		{"次卧", "./ui/图标-天气-大雪-56.png", false},
		{"厨房", "./ui/图标-天气-晴-32.png", false},
		{"浴室", "./ui/图标-天气-大雪-56.png", false},
		{"书房", "./ui/图标-天气-晴-32.png", false},
		{"自定义", "", false}
};

static DeviceInfo DeviceInfoDataList[] = {
		{"全热交换器", false},
		{"空   调", false},
		{"浴   霸", false},
		{"空气净化器", false},
//		{"./ui/智能模式-按钮-+-dis.png", false}
		{"+", false}
};

typedef struct Link {
//	char b[];
	SpaceInfo text;
	struct Link *next;
}Link_t;

/*
Link_t *initLink()
{
	Link_t *p = (Link_t*)malloc(sizeof(Link_t));
	Link_t *temp = p;

	for(int i = 0;i < (sizeof(SpaceInfoList) / sizeof(SpaceInfo));i++)
	{
//		 char *value = SpaceInfoList[i].maintext;
//		 char *value = SpaceInfoList[i];
		 Link_t *link = (Link_t*)malloc(sizeof(Link_t));
		 link->text = SpaceInfoList[i];
		 link->next = NULL;
		 temp->next = link;
		 temp = temp->next;
//		 LOGD("initLink i = %d\n", i);
	}
	return p;
}

Link_t *AddLink(Link_t *p, SpaceInfo text, int pos)
{
	Link_t *temp = p;
	for(int i = 1;i < pos+1;i++)
	{
		if(temp == NULL)
			return p;
		temp = temp->next;
	}
	Link_t *link = (Link_t*)malloc(sizeof(Link_t));
	link->text = text;
	link->next = temp->next;
	temp->next = link;
	return p;
}

Link_t *DeleteLink(Link_t *p, int pos)
{
	Link_t *temp = p;
	for(int i = 1;i < pos+1;i++)
	{
		temp = temp->next;
	}
	Link_t *del = temp->next;
	temp->next = temp->next->next;
	del = NULL;
	free(del);
	return p;
}

void LinkToArrayDeal(Link_t *p, bool type)
{
//	LOGD("LinkToArrayDeal !!!\n");
//	int index = 0;
	Link_t *temp = p;
	if(!type)
	{
		for(int i = 0;i < ((sizeof(SpaceInfoList) / sizeof(SpaceInfo)) - 1);i++)
		{
			SpaceInfoList[i] = temp->text;
			temp = temp->next;
			if(temp == NULL)
				break;
//			LOGD("LinkToArrayDeal i = %d\n", i);
		}
	}
	else
	{

	}
}
*/
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
	EnvSettingVector.clear();
}

/**
 * 当切换到该界面时触发
 */
static void onUI_intent(const Intent *intentPtr) {
    if (intentPtr != NULL) {
        //TODO
    }
//    strncpy(EnvSettingVector, SpaceInfoList, sizeof(SpaceInfoList));
    mButton10Ptr->setSelected(false);
    mButtonDelete1Ptr->setSelected(false);
}

/*
 * 当界面显示时触发
 */
static void onUI_show() {
//EnvSettingVector
//	SpaceInfo *info = (SpaceInfo *)malloc(sizeof(SpaceInfo));
//	memset(info , 0 , sizeof(SpaceInfo));
	EnvSettingVector.push_back(SpaceInfoList);
	mWindow14Ptr->setAlpha(170);
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
static bool onEnvSettingActivityTouchEvent(const MotionEvent &ev) {
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
static bool onButtonClick_Button9(ZKButton *pButton) {
    LOGD(" ButtonClick Button9 !!!\n");
    EASYUICONTEXT->goBack();
    return false;
}

static bool onButtonClick_ButtonBack(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonBack !!!\n");
    EASYUICONTEXT->goBack();
    return false;
}

static int getListItemCount_ListView2(const ZKListView *pListView) {
    //LOGD("getListItemCount_ListView2 !\n");

    return EnvSettingVector.size();
}

static void obtainListItemData_ListView2(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListView2  !!!\n");
	ZKListView::ZKListSubItem* psubText = pListItem->findSubItemByID(ID_ENVSETTING_SubItemTitle);
	ZKListView::ZKListSubItem* psubPic  = pListItem->findSubItemByID(ID_ENVSETTING_SubItemPic);
	ZKListView::ZKListSubItem* psubButton = pListItem->findSubItemByID(ID_ENVSETTING_SubItemCancel);
//	int Len = sizeof(SpaceInfoList) / sizeof(SpaceInfo);
	if(EnvSettingVector.size())
	{
		for(std::vector<SpaceInfo *>::iterator it = EnvSettingVector.begin();it != EnvSettingVector.end();it++)
		{
			SpaceInfo *tmp = (*it);
			psubPic->setBackgroundPic(tmp->mainPic);
			psubText->setText(tmp->maintext);
		}
	}
	if(mButton10Ptr->isSelected())
	{
//		psubButton->setVisible(true);
		if(EnvSettingVector.size() != index)
		{
			psubButton->setVisible(true);
		}
		else
		{
			psubButton->setVisible(false);
		}
	}
	else
	{
		psubButton->setVisible(false);
	}
//	mListView2Ptr->refreshListView();
}

static void onListItemClick_ListView2(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListView2  !!!\n");
	/* 在点击删除图标后，删除对应的环境需要重新对应数组数据 */
//	ZKListView::ZKListSubItem* psubButtonClick = pListItem->findSubItemByID(ID_ENVSETTING_SubItemCancel);
	Mutex::Autolock _l(lLock);
	if(mButton10Ptr->isSelected())
	{
		LOGD("psubButtonClick!!! and index is : %d\n", index);
//		EnvSettingVector->pop_back(SpaceInfoList[index]);
		SpaceInfo *del = EnvSettingVector.at(index);
		delete(del);
		del = NULL;
		mListView2Ptr->refreshListView();
//		LOGD("psubButtonClick end!!!\n");
	}
	else
	{
		mListView2Ptr->setVisible(false);
		mWindow12Ptr->setVisible(false);
		mWindow4Ptr->setVisible(true);
//		mRadioGroup1Ptr->isWndValid()
	}
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
static bool onButtonClick_Button1(ZKButton *pButton) {
    LOGD(" ButtonClick Button1 !!!\n");
    return false;
}

static void onCheckedChanged_RadioGroup1(ZKRadioGroup* pRadioGroup, int checkedID) {
    LOGD(" RadioGroup RadioGroup1 checked %d", checkedID);
    switch(checkedID)
    {
		case ID_ENVSETTING_RadioButtonAll:
		{
			mWindowAllPtr->setVisible(true);
			mWindowSmallMachinePtr->setVisible(false);
			mWindowBigMachinePtr->setVisible(false);
			mWindowKitchenPtr->setVisible(false);
		}
			break;
		case ID_ENVSETTING_RadioButtonSmallMachine:
		{
			mWindowAllPtr->setVisible(false);
			mWindowSmallMachinePtr->setVisible(true);
			mWindowBigMachinePtr->setVisible(false);
			mWindowKitchenPtr->setVisible(false);
		}
			break;
		case ID_ENVSETTING_RadioButtonBigMachine:
		{
			mWindowAllPtr->setVisible(false);
			mWindowSmallMachinePtr->setVisible(false);
			mWindowBigMachinePtr->setVisible(true);
			mWindowKitchenPtr->setVisible(false);
		}
			break;
		case ID_ENVSETTING_RadioButtonKitchen:
		{
			mWindowAllPtr->setVisible(false);
			mWindowSmallMachinePtr->setVisible(false);
			mWindowBigMachinePtr->setVisible(false);
			mWindowKitchenPtr->setVisible(true);
		}
			break;
		case ID_ENVSETTING_RadioButtonHomeDev:
		{

		}
			break;
		default:
			break;
    }
}
//static void onListItemClick_ListView2(ZKListView *pListView, int index, int id) {
//    //LOGD(" onListItemClick_ ListView2  !!!\n");
//}
static bool onButtonClick_ButtonBack1(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonBack1 !!!\n");
    mListView1Ptr->setVisible(true);
	mWindow1Ptr->setVisible(false);
	mWindow4Ptr->setVisible(true);
//    EASYUICONTEXT->goBack();
    return false;
}
static bool onButtonClick_ButtonBack2(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonBack2 !!!\n");
    mListView2Ptr->setVisible(true);
	mWindow12Ptr->setVisible(true);
	mWindow4Ptr->setVisible(false);
    return false;
}

static int getListItemCount_ListView1(const ZKListView *pListView) {
    //LOGD("getListItemCount_ListView1 !\n");
    return sizeof(DeviceInfoDataList) / sizeof(DeviceInfo);
}

static void obtainListItemData_ListView1(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListView1  !!!\n");
	ZKListView::ZKListItem *psubText = pListItem->findSubItemByID(ID_ENVSETTING_SubItemText);
	ZKListView::ZKListItem *psubCancelClick = pListItem->findSubItemByID(ID_ENVSETTING_SubItemDelete);
	int Len = sizeof(DeviceInfoDataList) / sizeof(DeviceInfo);
	psubText->setText(DeviceInfoDataList[index].maintext);
	if(mButtonDelete1Ptr->isSelected())
	{
		if(Len-1 != index)
		{
			psubCancelClick->setVisible(true);
		}
		else
		{
			psubCancelClick->setVisible(false);
		}
	}
	else
	{
		psubCancelClick->setVisible(false);
	}

	mListView1Ptr->refreshListView();
}

static void onListItemClick_ListView1(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListView1  !!!\n");
//	ZKListView::ZKListSubItem* psubButtonClick = pListItem->findSubItemByID(ID_ENVSETTING_SubItemDelete);
	if(mButtonDelete1Ptr->isSelected())
	{
//		if(id == ID_ENVSETTING_SubItemDelete)
//		if(psubButtonClick->isPressed())
//		{
			LOGD("onListItemClick_ ListView1 !!! and index is : %d\n", index);
//		}
	}
	else
	{
		mListView1Ptr->setVisible(false);
		mWindow1Ptr->setVisible(true);
		mWindow4Ptr->setVisible(false);
	}
}

static bool onButtonClick_ButtonDelete1(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonDelete1 !!!\n");
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
