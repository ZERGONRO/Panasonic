#pragma once
#include "uart/ProtocolSender.h"
#include "util/MachineStatus.h"
#include <pthread.h>
#include "app/SysAppFactory.h"
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

//char *stringText = "";
static std::string stringText;
bool Flag_EnvRefresh = false;
static char *text_name;
static char *pic_name;
static int EnvDevSetting_index;
static int DevListType;
static Mutex lLock;
static std::vector<DeviceInfo *> *EnvSettingVector[20];
static std::vector<SpaceInfo *> *EnvSettingVectorList;			//用指针直接操作，无需中间介质（EnvSettingVector）代替操作
static std::vector<DeviceInfo *> *DevSettingVectorList;
static std::vector<IOTDevInfo *> *IOTDevSettingVectorList;
static std::vector<DeviceInfo *> BedroomDevSettingVector, LivingroomDevSettingVector, StudyDevSettingVector, KitcheenDevSettingVector, SecRoomDevSettingVector, BathRoomDevSettingVector;
static std::vector<IOTDevInfo *> AllDevListVector, LifeSmallDevListVector, BigDevListVector, KitcheenDevListVector, HomeDevListVector;

static bool pushback_flag = true;

extern bool Flag_IME_Text;
extern void disableStatusbus();

void onEditTextChanged_EditText1(const std::string &text);

//extern struct S_EditTextInputCallback;

static SpaceInfo SpaceInfoList[] = {
		{"卧室", "./ui/首页-图标-主卧室1.png", false},
		{"客厅", "./ui/首页-图标-客厅.png", false},
		{"次卧", "./ui/首页-图标-次卧室1.png", false},
		{"厨房", "./ui/首页-图标-厨房.png", false},
		{"浴室", "./ui/首页-图标-浴室1.png", false},
		{"餐厅", "./ui/首页-图标-餐厅1.png", false},
		{"儿童房", "./ui/首页-图标-儿童房.png", false},
		{"阳台", "./ui/首页-图标-阳台1.png", false}
//		{"自定义", "", false}
};

static IOTDevInfo IOTDevInfoList[] = {
		{"空气净化器", "./ui/空气净化器.png"},
		{"空  调", "./ui/空调.png"},
		{"全热交换器", "./ui/全热交换器.png"},
		{"除湿器", "./ui/除湿器.png"},
		{"浴  霸", "./ui/浴霸.png"},
		{"油烟机", "./ui/浴霸.png"},
		{"冰箱", "./ui/空气净化器.png"},
		{"洗衣机", "./ui/全热交换器.png"}
};

static DeviceInfo DeviceInfoDataList[] = {
		{"全热交换器", false},
		{"空   调", false},
		{"浴   霸", false},
		{"空气净化器", false},
//		{"./ui/智能模式-按钮-+-dis.png", false}
		{"+", false}
};

static IOTDevInfo LifeSmallDevInfoList[] = {
		{"全热交换器", "./ui/全热交换器.png"},
		{"除湿器", "./ui/除湿器.png"}
};

static IOTDevInfo BigDevInfoList[] = {
		{"空气净化器", "./ui/空气净化器.png"},
		{"空  调", "./ui/空调.png"}
};

static IOTDevInfo KitcheenDevInfoList[] = {
		{"油烟机", "./ui/浴霸.png"},
		{"冰箱", "./ui/空气净化器.png"}
};

static IOTDevInfo HomecheenDevInfoList[] = {
		{"洗衣机", "./ui/全热交换器.png"},
		{"浴  霸", "./ui/浴霸.png"}
};


/**
 * 注册定时器
 * 填充数组用于注册定时器
 * 注意：id不能重复
 */
static S_ACTIVITY_TIMEER REGISTER_ACTIVITY_TIMER_TAB[] = {
	//{0,  6000}, //定时器id=0, 时间间隔6秒
	//{1,  1000},
};

void InitDevVector()
{
	if(!LifeSmallDevListVector.size())
	{
//		LifeSmallDevListVector = new std::vector<IOTDevInfo *>[5];
		LifeSmallDevListVector.clear();
		for(int i = 0;i < (sizeof(LifeSmallDevInfoList) / sizeof(IOTDevInfo));i++)
		{
			IOTDevInfo *LifeSmalldev = (IOTDevInfo*)malloc(sizeof(IOTDevInfo));
			memcpy(LifeSmalldev, &LifeSmallDevInfoList[i], sizeof(IOTDevInfo));
			LifeSmallDevListVector.push_back(LifeSmalldev);
		}
	}

	if(!BigDevListVector.size())
	{
//		BigDevListVector = new std::vector<IOTDevInfo *>[5];
		BigDevListVector.clear();
		for(int i = 0;i < (sizeof(BigDevInfoList) / sizeof(IOTDevInfo));i++)
		{
			IOTDevInfo *Bigdev = (IOTDevInfo*)malloc(sizeof(IOTDevInfo));
			memcpy(Bigdev, &BigDevInfoList[i], sizeof(IOTDevInfo));
			BigDevListVector.push_back(Bigdev);
		}
	}

	if(!KitcheenDevListVector.size())
	{
//		KitcheenDevListVector = new std::vector<IOTDevInfo *>[5];
		KitcheenDevListVector.clear();
		for(int i = 0;i < (sizeof(KitcheenDevInfoList) / sizeof(IOTDevInfo));i++)
		{
			IOTDevInfo *Kitdev = (IOTDevInfo*)malloc(sizeof(IOTDevInfo));
			memcpy(Kitdev, &KitcheenDevInfoList[i], sizeof(IOTDevInfo));
			KitcheenDevListVector.push_back(Kitdev);
		}
	}

	if(!HomeDevListVector.size())
	{
//		HomeDevListVector = new std::vector<IOTDevInfo *>[5];
		HomeDevListVector.clear();
		for(int i = 0;i < (sizeof(HomecheenDevInfoList) / sizeof(IOTDevInfo));i++)
		{
			IOTDevInfo *Homedev = (IOTDevInfo*)malloc(sizeof(IOTDevInfo));
			memcpy(Homedev, &HomecheenDevInfoList[i], sizeof(IOTDevInfo));
			HomeDevListVector.push_back(Homedev);
		}
	}

	if(!AllDevListVector.size())
	{
//		AllDevListVector = new std::vector<IOTDevInfo *>[15];
		AllDevListVector.clear();
		for(int i = 0;i < (int)LifeSmallDevListVector.size();i++)
		{
			IOTDevInfo *tmp = LifeSmallDevListVector.at(i);
			AllDevListVector.push_back(tmp);
		}
		for(int i = 0;i < (int)BigDevListVector.size();i++)
		{
			IOTDevInfo *tmp1 = BigDevListVector.at(i);
			AllDevListVector.push_back(tmp1);
		}
		for(int i = 0;i < (int)KitcheenDevListVector.size();i++)
		{
			IOTDevInfo *tmp2 = KitcheenDevListVector.at(i);
			AllDevListVector.push_back(tmp2);
		}
		for(int i = 0;i < (int)HomeDevListVector.size();i++)
		{
			IOTDevInfo *tmp3 = HomeDevListVector.at(i);
			AllDevListVector.push_back(tmp3);
		}
	}
}

/**
 * 当界面构造时触发
 */
static void onUI_init(){
    //Tips :添加 UI初始化的显示代码到这里,如:mText1Ptr->setText("123");
//	EnvSettingVector.clear();
	disableStatusbus();
	if(!EnvSettingVectorList)
	{
		LOGD("EnvSettingVectorList is NULL\n");
		EnvSettingVectorList = new std::vector<SpaceInfo *>[20];
		EnvSettingVectorList->clear();

		//数据初始化
		for(int i = 0;i < (sizeof(SpaceInfoList) / sizeof(SpaceInfo));i++)
		{
			SpaceInfo *EnvInfo = (SpaceInfo*)malloc(sizeof(SpaceInfo));
			memcpy(EnvInfo, &SpaceInfoList[i], sizeof(SpaceInfo));
			EnvSettingVectorList->push_back(EnvInfo);
		}
//		EnvSettingVectorList = EnvSettingVector[i];
	}



	for(int j = 0;j < (int)EnvSettingVectorList->size();j++)
	{
		if(!EnvSettingVector[j])
		{
			EnvSettingVector[j] = new std::vector<DeviceInfo *>[20];
			EnvSettingVector[j]->clear();
			DeviceInfo *tmp1 = (DeviceInfo*)malloc(sizeof(DeviceInfo));
			tmp1->maintext = "+";
			EnvSettingVector[j]->push_back(tmp1);
		}

	}



	InitDevVector();
	if(!IOTDevSettingVectorList)
	{
		LOGD("IOTDevSettingVectorList is NULL\n");
		IOTDevSettingVectorList = new std::vector<IOTDevInfo *>[20];
		IOTDevSettingVectorList->clear();
		IOTDevSettingVectorList = &AllDevListVector;

	}

}

/**
 * 当切换到该界面时触发
 */
static void onUI_intent(const Intent *intentPtr) {
    if (intentPtr != NULL) {
        //TODO
    }

    mButton10Ptr->setSelected(false);
    mButtonDelete1Ptr->setSelected(false);
}

/*
 * 当界面显示时触发
 */
static void onUI_show() {
/*

*/
//	for(int i = 0;i < (sizeof(DeviceInfoDataList) / sizeof(DeviceInfo));i++)
//	{
//		DeviceInfo *DevInfo = (DeviceInfo*)malloc(sizeof(DeviceInfo));
//		memcpy(DevInfo, &DeviceInfoDataList[i], sizeof(DeviceInfo));
//		BedroomDevSettingVector.push_back(DevInfo);
//	}
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
    IOTDevSettingVectorList = &AllDevListVector;
    Flag_EnvRefresh = true;
    EASYUICONTEXT->goBack();
    return false;
}

static bool onButtonClick_ButtonBack(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonBack !!!\n");
    if(mButton10Ptr->isSelected())
    {
    	mButton10Ptr->setSelected(false);
    }
    Flag_EnvRefresh = true;
    IOTDevSettingVectorList = &AllDevListVector;
    EASYUICONTEXT->goBack();
    return false;
}

void setEditTextPos(int size){
	LayoutPosition lp = mEditText2Ptr->getPosition();
	mEditText2Ptr->setText("自定义");
	mEditText2Ptr->setTextColor(0xFF000000);
	mEditText2Ptr->setBackgroundColor(0xFFFFFFFF);
	/*
	if (size <= 12){
		if (size == 0){
			lp.mLeft = 50 + 0;
			lp.mTop = 188 + 22 + 5;
		}else if (size == 1){
			lp.mLeft = 50 + 200;
			lp.mTop = 188 + 22 + 5;
		}else if (size == 2){
			lp.mLeft = 50 + 400;
			lp.mTop = 188 + 22 + 5;
		}else if (size == 3){
			lp.mLeft = 50 + 600;
			lp.mTop = 188 + 22 + 5;
		}else if (size == 4){
			lp.mLeft = 50 + 0;
			lp.mTop = 188 + 92 + 5;
		}else if (size == 5){
			lp.mLeft = 50 + 200;
			lp.mTop = 188 + 92 + 5;
		}else if (size == 6){
			lp.mLeft = 50 + 400;
			lp.mTop = 188 + 92 + 5;
		}else if (size == 7){
			lp.mLeft = 50 + 600;
			lp.mTop = 188 + 92 + 5;
		}else if (size == 8){
			lp.mLeft = 50 + 0;
			lp.mTop = 188 + 162;
		}else if (size == 9){
			lp.mLeft = 50 + 200;
			lp.mTop = 188 + 162;
		}else if (size == 10){
			lp.mLeft = 50 + 400;
			lp.mTop = 188 + 162;
		}else if (size == 11){
			lp.mLeft = 50 + 600;
			lp.mTop = 188 + 162;
		}
	}else{
		lp.mLeft = 50 + 600;
		lp.mTop = 188 + 222 + 10;
	}
	 */
	lp.mLeft = 650;
	lp.mTop = 420;
	mEditText2Ptr->setPosition(lp);
}

static int getListItemCount_ListView2(const ZKListView *pListView) {
    //LOGD("getListItemCount_ListView2 !\n");
	MACHINESTATUS->setEnvListInfo(EnvSettingVectorList);
    return EnvSettingVectorList->size();
}

static void obtainListItemData_ListView2(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListView2  !!!\n");
	LayoutPosition lp;
	ZKListView::ZKListSubItem* psubText = pListItem->findSubItemByID(ID_ENVSETTING_SubItemTitle);
	ZKListView::ZKListSubItem* psubPic  = pListItem->findSubItemByID(ID_ENVSETTING_SubItemPic);
	ZKListView::ZKListSubItem* psubButton = pListItem->findSubItemByID(ID_ENVSETTING_SubItemCancel);
	SpaceInfo *tmp = EnvSettingVectorList->at(index);
	psubPic->setBackgroundPic(tmp->mainPic);
	psubText->setText(tmp->maintext);
	setEditTextPos((int)EnvSettingVectorList->size());
//	setEditTextPos(index);
	if(mButton10Ptr->isSelected())
	{
		psubButton->setVisible(true);
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
	Mutex::Autolock _l(lLock);
	if(mButton10Ptr->isSelected())
	{
		for(std::vector<SpaceInfo *>::iterator it = EnvSettingVectorList->begin();;it++)
		{
			if((*it) == EnvSettingVectorList->at(index))
			{
				SpaceInfo *tmp = (*it);
				EnvSettingVectorList->erase(it);
				free(tmp);
				tmp = NULL;
				break;
			}
			if (it == EnvSettingVectorList->end()){
				break;
			}
		}
	}
	else
	{
		SpaceInfo *tmp1 = EnvSettingVectorList->at(index);
		text_name = tmp1->maintext;
		pic_name = tmp1->mainPic;
		EnvDevSetting_index = index;
		DevSettingVectorList = EnvSettingVector[index];
		mListView2Ptr->setVisible(false);
		mWindow12Ptr->setVisible(false);
		mWindow4Ptr->setVisible(true);
	}
	mListView2Ptr->refreshListView();
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
    mListView2Ptr->refreshListView();
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
			DevListType = AllMachine;
			IOTDevSettingVectorList = &AllDevListVector;
		}
			break;
		case ID_ENVSETTING_RadioButtonSmallMachine:
		{
			DevListType = LifeSmallMachine;
			IOTDevSettingVectorList = &LifeSmallDevListVector;
		}
			break;
		case ID_ENVSETTING_RadioButtonBigMachine:
		{
			DevListType = BigMachine;
			IOTDevSettingVectorList = &BigDevListVector;
		}
			break;
		case ID_ENVSETTING_RadioButtonKitchen:
		{
			DevListType = KitcheenMachine;
			IOTDevSettingVectorList = &KitcheenDevListVector;
		}
			break;
		case ID_ENVSETTING_RadioButtonHomeDev:
		{
			DevListType = HomeMachine;
			IOTDevSettingVectorList = &HomeDevListVector;
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
//    if(mButtonDelete1Ptr->isSelected())
//		mButtonDelete1Ptr->setSelected(false);
    mListView1Ptr->setVisible(true);
	mWindow1Ptr->setVisible(false);
	mWindow4Ptr->setVisible(true);
//    EASYUICONTEXT->goBack();
    return false;
}
static bool onButtonClick_ButtonBack2(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonBack2 !!!\n");
    if(mButtonDelete1Ptr->isSelected())
    	mButtonDelete1Ptr->setSelected(false);
    mListView2Ptr->setVisible(true);
	mWindow12Ptr->setVisible(true);
	mWindow4Ptr->setVisible(false);
    return false;
}

static int getListItemCount_ListView1(const ZKListView *pListView) {
    //LOGD("getListItemCount_ListView1 !\n");
	MACHINESTATUS->setEnvSpaceInfo(DevSettingVectorList);
    return DevSettingVectorList->size();
}

static void obtainListItemData_ListView1(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListView1  !!!\n");
	mTextView15Ptr->setText(text_name);
	mTextViewPicShowPtr->setBackgroundPic(pic_name);
	ZKListView::ZKListItem *psubText = pListItem->findSubItemByID(ID_ENVSETTING_SubItemText);
	ZKListView::ZKListItem *psubCancelClick = pListItem->findSubItemByID(ID_ENVSETTING_SubItemDelete);
//	int Len = sizeof(DeviceInfoDataList) / sizeof(DeviceInfo);
	DeviceInfo *tmp = DevSettingVectorList->at(index);
//	MACHINESTATUS->setEnvSpaceInfo(tmp);
	psubText->setText(tmp->maintext);
	if(mButtonDelete1Ptr->isSelected())
	{
		if((int)DevSettingVectorList->size()-1 != index)
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

//	mListView1Ptr->refreshListView();
}

static void onListItemClick_ListView1(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListView1  !!!\n");
//	ZKListView::ZKListSubItem* psubButtonClick = pListItem->findSubItemByID(ID_ENVSETTING_SubItemDelete);
	if(mButtonDelete1Ptr->isSelected())
	{
		LOGD("onListItemClick_ ListView1 !!! and index is : %d\n", index);
		for(std::vector<DeviceInfo *>::iterator it = DevSettingVectorList->begin(); it != DevSettingVectorList->end();it++)
		{
			if(DevSettingVectorList->size() - 1 == index)
			{
				LOGD(" DIY button, Click_ListView1 can't press down  !!!\n");
				break;
			}
			if((*it) == DevSettingVectorList->at(index))
			{
				DeviceInfo *tmp = (*it);
				it = DevSettingVectorList->erase(it);
//				EnvSettingVector[EnvDevSetting_index]->erase(it);
				free(tmp);
				tmp = NULL;
			}
		}
	}
	else
	{
		if(DevSettingVectorList->size() - 1 == index)
		{
			mListView1Ptr->setVisible(false);
			mWindow1Ptr->setVisible(true);
			mWindow4Ptr->setVisible(false);
//			onCheckedChanged_RadioGroup1(mRadioGroup1Ptr, ID_ENVSETTING_RadioButtonAll);
		}
	}
	mListView1Ptr->refreshListView();
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
    mListView1Ptr->refreshListView();
    return false;
}
static bool onButtonClick_ButtonInput(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonInput !!!\n");
    return false;
}
static int getListItemCount_ListView3(const ZKListView *pListView) {
    //LOGD("getListItemCount_ListView3 !\n");
    return IOTDevSettingVectorList->size();
}

static void obtainListItemData_ListView3(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListView3  !!!\n");
	ZKListView::ZKListItem *psubText = pListItem->findSubItemByID(ID_ENVSETTING_SubItemDevName);
	ZKListView::ZKListItem *psubPic = pListItem->findSubItemByID(ID_ENVSETTING_SubItemDevPic);
	IOTDevInfo *tmp = IOTDevSettingVectorList->at(index);
	psubText->setText(tmp->maintext);
	psubPic->setBackgroundPic(tmp->mainPic);
	mListView3Ptr->refreshListView();
}

static void onListItemClick_ListView3(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListView3  !!!\n");
	for(std::vector<IOTDevInfo *>::iterator it = IOTDevSettingVectorList->begin(); it != IOTDevSettingVectorList->end();it++)
	{
		/*将对应的设备增加到相应的环境当中*/
		if(IOTDevSettingVectorList->at(index) == (*it))
		{
			for(std::vector<DeviceInfo *>::iterator it1 = DevSettingVectorList->begin(); it1 != DevSettingVectorList->end();it1++)
			{
				if((*it)->maintext == (*it1)->maintext)
				{
					LOGD(" The IOTDevSettingVectorList is exist  !!!\n");
					return;
				}
			}
			LOGD(" Add IOTDevSettingVectorList : %d  !!!\n", index);
			DeviceInfo *tmp = (DeviceInfo*)malloc(sizeof(DeviceInfo));
//			DeviceInfo *tmp = (DeviceInfo *)(*it);
			tmp->maintext = (*it)->maintext;
			tmp->cancelstatus = false;
			DevSettingVectorList->insert(DevSettingVectorList->end()-1, tmp);
//			EnvSettingVector[EnvDevSetting_index]->insert(EnvSettingVector[EnvDevSetting_index]->end()-1, tmp);
		}

	}
	mListView3Ptr->refreshListView();
}
static void onEditTextChanged_EditText1(const std::string &text) {
    LOGD(" onEditTextChanged_ EditText1 %s !!!\n", text.c_str());
//    mEditText1Ptr->setText("自定义");
//    *stringText = text.c_str();
}
static void onEditTextChanged_EditText2(const std::string &text) {
    LOGD(" onEditTextChanged_ EditText2 %s !!!\n", text.c_str());
    if (Flag_IME_Text){
    	LOGD("Text Entern\n");
    	Flag_IME_Text = false;
    	SpaceInfo *tmpEditText = (SpaceInfo *)malloc(sizeof(SpaceInfo));
		strcpy(tmpEditText->maintext, text.c_str());
		strcpy(tmpEditText->mainPic, NULL);
		tmpEditText->cancelstatus = false;
		EnvSettingVectorList->push_back(tmpEditText);
    }

//    mEditText2Ptr->setText("");
}
