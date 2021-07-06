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

static MachineTime date;

static std::vector<std::string > VectorYear;
static std::vector<std::string > VectorMonth;
static std::vector<std::string > VectorDays;
static std::vector<std::string > VectorHour;
static std::vector<std::string > VectorMin;

static  std::string ListYear[] = {"2019", "2020", "2021", "2022", "2023", "2024", "2025", "2026", "2027"};
static const std::string ListMonth[] = {"1月", "2月", "3月", "4月", "5月", "6月", "7月", "8月", "9月", "10月", "11月", "12月"};
static const std::string ListDays[] = {"1日", "2日", "3日", "4日", "5日", "6日", "7日", "8日", "9日", "10日",
									  "11日", "12日", "13日", "14日", "15日", "16日", "17日", "18日", "19日", "20日",
									  "21日", "22日", "23日", "24日", "25日", "26日", "27日", "28日", "29日", "30日", "31日"};
static  std::string ListHour[] =  {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
								   "10", "11", "12", "13", "14", "15", "16", "17", "18", "19",
								    "20", "21", "22", "23"};
static  std::string ListMin[] =   {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
									 "10", "11", "12", "13", "14", "15", "16", "17", "18", "19",
									 "20", "21", "22", "23", "24", "25", "26", "27", "28", "29",
									 "30", "31", "32", "33", "34", "35", "36", "37", "38", "39",
									 "40", "41", "42", "43", "44", "45", "46", "47", "48", "49",
									 "50", "51", "52", "53", "54", "55", "56", "57", "58", "59"};


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
    }

}

/*
 * 当界面显示时触发
 */
static void onUI_show() {
	char timebuf[100];
	if (!nwlistener->getWifiStatus()){
		mTextViewDescPtr->setVisible(true);
		mListViewYearPtr->setVisible(false);
		mListViewMonthPtr->setVisible(false);
		mListViewDayPtr->setVisible(false);
		mListViewHourPtr->setVisible(false);
		mListViewMinuetePtr->setVisible(false);
//		mListView1Ptr->setVisible(false);
	}else{
		mTextViewDescPtr->setVisible(false);
//		mListView1Ptr->setVisible(true);
//		mListView1Ptr->refreshListView();
		mListViewYearPtr->setVisible(true);
		mListViewMonthPtr->setVisible(true);
		mListViewDayPtr->setVisible(true);
		mListViewHourPtr->setVisible(true);
		mListViewMinuetePtr->setVisible(true);

		for (int i = 0;i < sizeof(ListYear) / sizeof(std::string);i++){
			VectorYear.push_back(ListYear[i]);
		}

		for (int i = 0;i < sizeof(ListMonth) / sizeof(std::string);i++){
			VectorMonth.push_back(ListMonth[i]);
		}

		for (int i = 0;i < sizeof(ListDays) / sizeof(std::string);i++){
			VectorDays.push_back(ListDays[i]);
		}

		for (int i = 0;i < sizeof(ListHour) / sizeof(std::string);i++){
			VectorHour.push_back(ListHour[i]);
		}

		for (int i = 0;i < sizeof(ListMin) / sizeof(std::string);i++){
			VectorMin.push_back(ListMin[i]);
		}

		date = MACHINESTATUS->getMachineTime();
		sprintf(timebuf, "%d年%02d月%02d日    %02d:%02d", date.year+1900, date.month, date.days, date.hour, date.min);
		mTextViewDate1Ptr->setText(timebuf);

		mListViewYearPtr->setSelection(date.year - 121);
		mListViewYearPtr->refreshListView();

		mListViewMonthPtr->setSelection(date.month-3);
		mListViewMonthPtr->refreshListView();

		mListViewDayPtr->setSelection(date.days-3);
		mListViewDayPtr->refreshListView();

		mListViewHourPtr->setSelection(date.hour-2);
		mListViewHourPtr->refreshListView();

		mListViewMinuetePtr->setSelection(date.min-2);
		mListViewMinuetePtr->refreshListView();

		mListViewYearPtr->setDecRatio(0.7);
		mListViewMonthPtr->setDecRatio(0.7);
		mListViewDayPtr->setDecRatio(0.7);
		mListViewHourPtr->setDecRatio(0.7);
		mListViewMinuetePtr->setDecRatio(0.7);

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
static bool onTimeSettingActivityTouchEvent(const MotionEvent &ev) {
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
    return false;
}
static bool onButtonClick_ButtonBack(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonBack !!!\n");
    EASYUICONTEXT->goBack();
    return false;
}
static int getListItemCount_ListView1(const ZKListView *pListView) {
    //LOGD("getListItemCount_ListView1 !\n");
    return 5;
}

/*
static void obtainListItemData_ListView1(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListView1  !!!\n");
	ZKListView::ZKListSubItem* psubYear = pListItem->findSubItemByID(ID_TIMESETTING_SubItemYear);
	ZKListView::ZKListSubItem* psubMonth = pListItem->findSubItemByID(ID_TIMESETTING_SubItemMonth);
	ZKListView::ZKListSubItem* psubDay = pListItem->findSubItemByID(ID_TIMESETTING_SubItemDay);
	ZKListView::ZKListSubItem* psubHour = pListItem->findSubItemByID(ID_TIMESETTING_SubItemHour);
	ZKListView::ZKListSubItem* psubMin = pListItem->findSubItemByID(ID_TIMESETTING_SubItemMin);
	psubYear->setText((int)VectorYear.at(index));
	psubMonth->setText(VectorMonth.at(index));
	psubDay->setText(VectorDays.at(index));
	psubHour->setText((int)VectorHour.at(index));
	psubMin->setText((int)VectorMin.at(index));


}
*/


typedef enum
{
	E_CENTER_MODE = 0,
	E_DOUBLE_CENTER_MODE,
	E_MOVE_DOWN_MODE,
	E_MOVE_UP_MODE
} MiddleItemDisplayMode_e;

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

	MACHINESTATUS->setenvironmentindex(itemIdx);
//	LOGD("itemIdx is : %d\n", itemIdx);
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


static int getListItemCount_ListViewYear(const ZKListView *pListView) {
    //LOGD("getListItemCount_ListViewYear !\n");
    return 9;
}

static void obtainListItemData_ListViewYear(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListViewYear  !!!\n");
	ZKListView::ZKListSubItem* listItems[5] = {
					pListItem->findSubItemByID(ID_TIMESETTING_SubItemYearMax),
					pListItem->findSubItemByID(ID_TIMESETTING_SubItemYearLarge),
					pListItem->findSubItemByID(ID_TIMESETTING_SubItemYearMid),
					pListItem->findSubItemByID(ID_TIMESETTING_SubItemYearSmall),
					pListItem->findSubItemByID(ID_TIMESETTING_SubItemYearMini),
			};
	int focusIdx;
	std::string focusString;
	setListViewItems(pListView, index, focusIdx, focusString, listItems, VectorYear);
}

static void onListItemClick_ListViewYear(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListViewYear  !!!\n");
}

static int getListItemCount_ListViewMonth(const ZKListView *pListView) {
    //LOGD("getListItemCount_ListViewMonth !\n");
    return 12;
}

static void obtainListItemData_ListViewMonth(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListViewMonth  !!!\n");
	ZKListView::ZKListSubItem* listItems[5] = {
					pListItem->findSubItemByID(ID_TIMESETTING_SubItemMonthMax),
					pListItem->findSubItemByID(ID_TIMESETTING_SubItemMonthLarge),
					pListItem->findSubItemByID(ID_TIMESETTING_SubItemMonthMid),
					pListItem->findSubItemByID(ID_TIMESETTING_SubItemMonthSmall),
					pListItem->findSubItemByID(ID_TIMESETTING_SubItemMonthMini),
			};
	int focusIdx;
	std::string focusString;
	setListViewItems(pListView, index, focusIdx, focusString, listItems, VectorMonth);
}

static void onListItemClick_ListViewMonth(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListViewMonth  !!!\n");
}

static int getListItemCount_ListViewDay(const ZKListView *pListView) {
    //LOGD("getListItemCount_ListViewDay !\n");
    return 31;
}

static void obtainListItemData_ListViewDay(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListViewDay  !!!\n");
	ZKListView::ZKListSubItem* listItems[5] = {
					pListItem->findSubItemByID(ID_TIMESETTING_SubItemDayMax),
					pListItem->findSubItemByID(ID_TIMESETTING_SubItemDayLarge),
					pListItem->findSubItemByID(ID_TIMESETTING_SubItemDayMid),
					pListItem->findSubItemByID(ID_TIMESETTING_SubItemDaySmall),
					pListItem->findSubItemByID(ID_TIMESETTING_SubItemDayMini),
			};
	int focusIdx;
	std::string focusString;
	setListViewItems(pListView, index, focusIdx, focusString, listItems, VectorDays);
}

static void onListItemClick_ListViewDay(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListViewDay  !!!\n");
}

static int getListItemCount_ListViewHour(const ZKListView *pListView) {
    //LOGD("getListItemCount_ListViewHour !\n");
    return 24;
}

static void obtainListItemData_ListViewHour(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListViewHour  !!!\n");
	ZKListView::ZKListSubItem* listItems[5] = {
					pListItem->findSubItemByID(ID_TIMESETTING_SubItemHourMax),
					pListItem->findSubItemByID(ID_TIMESETTING_SubItemHourLarge),
					pListItem->findSubItemByID(ID_TIMESETTING_SubItemHourMid),
					pListItem->findSubItemByID(ID_TIMESETTING_SubItemHourSmall),
					pListItem->findSubItemByID(ID_TIMESETTING_SubItemHourMini),
			};
	int focusIdx;
	std::string focusString;
	setListViewItems(pListView, index, focusIdx, focusString, listItems, VectorHour);
}

static void onListItemClick_ListViewHour(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListViewHour  !!!\n");
}

static int getListItemCount_ListViewMinuete(const ZKListView *pListView) {
    //LOGD("getListItemCount_ListViewMinuete !\n");
    return 60;
}

static void obtainListItemData_ListViewMinuete(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
    //LOGD(" obtainListItemData_ ListViewMinuete  !!!\n");
	ZKListView::ZKListSubItem* listItems[5] = {
					pListItem->findSubItemByID(ID_TIMESETTING_SubItemMinMax),
					pListItem->findSubItemByID(ID_TIMESETTING_SubItemMinLarge),
					pListItem->findSubItemByID(ID_TIMESETTING_SubItemMinMid),
					pListItem->findSubItemByID(ID_TIMESETTING_SubItemMinSmall),
					pListItem->findSubItemByID(ID_TIMESETTING_SubItemMinMini),
			};
	int focusIdx;
	std::string focusString;
	setListViewItems(pListView, index, focusIdx, focusString, listItems, VectorMin);
}

static void onListItemClick_ListViewMinuete(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListViewMinuete  !!!\n");
}
static void onListItemClick_ListView1(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListView1  !!!\n");
}
