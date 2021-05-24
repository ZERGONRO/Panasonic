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
extern void SetEnvName(std::string focusindex);

//static char *gEnvironmentSelList[10] = {"卧室", "浴室", "客厅", "厨房", "次卧", "厨房", "书房", "阳台", "'储物间", "卫生间"};

static std::vector<std::string > EnvironmentSelVector;

/**
 * 注册定时器
 * 填充数组用于注册定时器
 * 注意：id不能重复
 */
static S_ACTIVITY_TIMEER REGISTER_ACTIVITY_TIMER_TAB[] = {
	//{0,  6000}, //定时器id=0, 时间间隔6秒
	//{1,  1000},
};

void setEnvSelList()
{
	EnvironmentSelVector.push_back("卧室");
	EnvironmentSelVector.push_back("浴室");
	EnvironmentSelVector.push_back("客厅");
	EnvironmentSelVector.push_back("厨房");
	EnvironmentSelVector.push_back("次卧");
	EnvironmentSelVector.push_back("书房");
	EnvironmentSelVector.push_back("阳台");
	EnvironmentSelVector.push_back("储物间");
	EnvironmentSelVector.push_back("卫生间");
}
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
//    for(int i = 0;i < 9;i++)
//    {
//    	EnvironmentSelVector.push_back(std::to_string(gEnvironmentSelList[i]));
//    }
    setEnvSelList();
    mWindowBGPtr->setAlpha(150);
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
	EnvironmentSelVector.clear();
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
static bool onEnvironmentSelectActivityTouchEvent(const MotionEvent &ev) {
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
static bool onButtonClick_Button1(ZKButton *pButton) {
    LOGD(" ButtonClick Button1 !!!\n");
    EASYUICONTEXT->goBack();
    return false;
}

static bool onButtonClick_ButtonCancel(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonCancel !!!\n");
    EASYUICONTEXT->goBack();
    return false;
}

static bool onButtonClick_ButtonConfirm(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonConfirm !!!\n");
    int index = mListView_EnvPtr->getFirstVisibleItemIndex();
    index = index + 2;
    std::string focusindex = EnvironmentSelVector.at(index);
    SetEnvName(focusindex);
    EASYUICONTEXT->goBack();
    return false;
}
typedef enum
{
	E_CENTER_MODE = 0,
	E_DOUBLE_CENTER_MODE,
	E_MOVE_DOWN_MODE,
	E_MOVE_UP_MODE
} MiddleItemDisplayMode_e;


static int getListItemCount_ListView_Env(const ZKListView *pListView) {
    //LOGD("getListItemCount_ListView_Env !\n");
    return 9;
}

static void showListviewItems(MiddleItemDisplayMode_e eDispMode, int selectIdx, ZKListView::ZKListSubItem* pListItem[], int itemIdx, std::string &stringFocus, std::vector<std::string> &vect)
{
	ZKListView::ZKListSubItem *pMaxSizeItem = pListItem[0];
	ZKListView::ZKListSubItem *pMidSizeItem = pListItem[1];
	ZKListView::ZKListSubItem *pLargeSizeItem = pListItem[2];
	ZKListView::ZKListSubItem *pSmallSizeItem = pListItem[3];
	ZKListView::ZKListSubItem *pMinSizeItem = pListItem[4];

	pLargeSizeItem->setVisible(false);
	pSmallSizeItem->setVisible(false);
	pMidSizeItem->setVisible(false);
	pMaxSizeItem->setVisible(false);
	pMinSizeItem->setVisible(false);

	switch (eDispMode)
	{
		case E_CENTER_MODE:
		{
			if (itemIdx != selectIdx)
			{
				//pListItem->setText(g_listItemName[index]);
				pMinSizeItem->setText(vect.at(itemIdx));
				pMinSizeItem->setVisible(true);
			}
			else
			{
				//pListItem->setText("");
				pMaxSizeItem->setText(vect.at(itemIdx));
				pMaxSizeItem->setVisible(true);
				stringFocus = vect.at(itemIdx);
			}
		}
		break;
		case E_DOUBLE_CENTER_MODE:
		{
			int nextIdx = (selectIdx + 1) % vect.size();

			if ((itemIdx != selectIdx) && (itemIdx != nextIdx))
			{
				//pListItem->setText(g_listItemName[index]);
				pMinSizeItem->setText(vect.at(itemIdx));
				pMinSizeItem->setVisible(true);
			}
			else
			{
				//pListItem->setText("");
				pMidSizeItem->setText(vect.at(itemIdx));
				pMidSizeItem->setVisible(true);
			}
		}
		break;
		case E_MOVE_DOWN_MODE:
		{
			int nextIdx = (selectIdx + 1) % vect.size();

			if (itemIdx == selectIdx)
			{
				//pListItem->setText("");
				pSmallSizeItem->setText(vect.at(itemIdx));
				pSmallSizeItem->setVisible(true);
				stringFocus = vect.at(itemIdx);
			}
			else if (itemIdx == nextIdx)
			{
				//pListItem->setText("");
				pLargeSizeItem->setText(vect.at(itemIdx));
				pLargeSizeItem->setVisible(true);
			}
			else
			{
				//pListItem->setText(g_listItemName[index]);
				pMinSizeItem->setText(vect.at(itemIdx));
				pMinSizeItem->setVisible(true);
			}
		}
		break;
		case E_MOVE_UP_MODE:
		{
			int nextIdx = (selectIdx + 1) % vect.size();

			if (itemIdx == selectIdx)
			{
				//pListItem->setText("");
				pLargeSizeItem->setText(vect.at(itemIdx));
				pLargeSizeItem->setVisible(true);
				stringFocus = vect.at(itemIdx);
			}
			else if (itemIdx == nextIdx)
			{
				//pListItem->setText("");
				pSmallSizeItem->setText(vect.at(itemIdx));
				pSmallSizeItem->setVisible(true);
			}
			else
			{
				//pListItem->setText(g_listItemName[index]);
				pMinSizeItem->setText(vect.at(itemIdx));
				pMinSizeItem->setVisible(true);
			}
		}
		break;
	default:
		break;
	}
}

static void setListViewItems(ZKListView *pListView, int index, int &focusIndex, std::string &focusString, ZKListView::ZKListSubItem* pListItem[], std::vector<std::string> &vect)
{
	int firstVisibleIndex = pListView->getFirstVisibleItemIndex();
	int g_itemOffset = pListView->getRows() / 2;
	int itemOffset = pListView->getFirstVisibleItemOffset();
	int itemHeight = pListView->getItemHeight();
	MiddleItemDisplayMode_e midItemMode = E_CENTER_MODE;

	focusIndex = (firstVisibleIndex + g_itemOffset) % vect.size();
	if (itemOffset > (-1 * itemHeight) && itemOffset <= (-7 * itemHeight/8)) {
		focusIndex = (firstVisibleIndex + g_itemOffset + 1) % vect.size();
	} else if (itemOffset >= (-1 * itemHeight/8) && itemOffset <= 0){
		// index:largest others:smallest
	} else if (itemOffset > (-7 * itemHeight/8) && itemOffset <= (-5 * itemHeight/8)) {
		// index:smaller (index+1):larger others:smallest
		midItemMode = E_MOVE_DOWN_MODE;
	} else if (itemOffset > (-3 * itemHeight/8) && itemOffset <= (-1 * itemHeight/8)) {
		// index:larger (index+1):smaller others:smallest
		midItemMode = E_MOVE_UP_MODE;
	}
	else {
		// index:middle (index+1):middle others:smallest
		midItemMode = E_DOUBLE_CENTER_MODE;
	}
	showListviewItems(midItemMode, focusIndex, pListItem, index, focusString, vect);
}

static void obtainListItemData_ListView_Env(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListView_Env  !!!\n");
	ZKListView::ZKListSubItem* listItems[5] = {
				pListItem->findSubItemByID(ID_ENVIRONMENTSELECT_SubItem_Max_Size),
				pListItem->findSubItemByID(ID_ENVIRONMENTSELECT_SubItem_Large_Size),
				pListItem->findSubItemByID(ID_ENVIRONMENTSELECT_SubItem_Mid_Size),
				pListItem->findSubItemByID(ID_ENVIRONMENTSELECT_SubItem_Small_Size),
				pListItem->findSubItemByID(ID_ENVIRONMENTSELECT_SubItem_Mini_Size),
		};
	int focusIdx;
	std::string focusString;
	setListViewItems(pListView, index, focusIdx, focusString, listItems, EnvironmentSelVector);
}

static void onListItemClick_ListView_Env(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListView_Env  !!!\n");
}
