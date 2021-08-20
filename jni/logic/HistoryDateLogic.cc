#pragma once
#include "uart/ProtocolSender.h"
#include "uart/CommDef.h"
//#include "ZKPainter.h"
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

static int HistoryMode = History_TempMode;
extern void enableStatusbus();

void DisPlaySelectModeStatus(int index);

SZKPoint pointX0[] = {
	{-5 , 288},{0 , 263},{90, 96},{180 , 48},{270, 96},{360, 144},{450, 230},{540, 15},{630, 188},{720, 248},{750, 288}
};

SZKPoint pointX1[] = {
	{-5 , 288},{0 , 80},{90, 134},{180 , 42},{270, 253},{360, 144},{450, 86},{540, 106},{630, 13},{720, 248},{750, 288}
};

SZKPoint pointX2[] = {
	{-5 , 288},{0 , 159},{90, 64},{180 , 133},{270, 78},{360, 100},{450, 144},{540, 18},{630, 240},{720, 277},{750, 288}
};

SZKPoint pointX3[] = {
	{-5 , 288},{0 , 277},{90, 12},{180 , 26},{270, 143},{360, 206},{450, 78},{540, 169},{630, 204},{720, 183},{750, 288}
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

void DispLineCharFunc()
{

	//mPainterXPtr[0]->setLineWidth(2);
	//mPainterXPtr[0]->setSourceColor(0x88cffa);
	//mPainterXPtr[0]->drawLines(pointX0, TABLESIZE(pointX0));

	//mPainterXPtr[1]->setLineWidth(2);
	//mPainterXPtr[1]->setSourceColor(0x88cffa);
	//mPainterXPtr[1]->drawLines(pointX1, TABLESIZE(pointX1));

	//mPainterXPtr[2]->setLineWidth(2);
	//mPainterXPtr[2]->setSourceColor(0x88cffa);
	//mPainterXPtr[2]->drawLines(pointX2, TABLESIZE(pointX2));

	//mPainterXPtr[3]->setLineWidth(2);
	//mPainterXPtr[3]->setSourceColor(0x88cffa);
	//mPainterXPtr[3]->drawLines(pointX3, TABLESIZE(pointX3));
}



/**
 * 当界面构造时触发
 */
static void onUI_init(){
    //Tips :添加 UI初始化的显示代码到这里,如:mText1Ptr->setText("123");
//	 SZKPoint points1[] = {
//		    {-5 , 288},
//			{0 , 263},
//			{90, 96},
//			{180 , 48},
//			{270, 96},
//			{360, 144},
//			{450, 230},
//			{540, 15},
//			{630, 188},
//			{720, 248},
//			{750, 288},
////			{50 , 150}
//	    };
//	DispLineCharFunc();
	enableStatusbus();

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

	mButtonHomepage2Ptr->setSelected(false);
	mButtonSmart2Ptr->setSelected(false);
	mButtonManual2Ptr->setSelected(false);
	mButtonHistorty2Ptr->setSelected(true);

	mTextViewHomepage2Ptr->setSelected(false);
	mTextViewSmart2Ptr->setSelected(false);
	mTextViewManual2Ptr->setSelected(false);
	mTextViewHistory2Ptr->setSelected(true);
	mButtonDayPtr->setSelected(true);
	mButtonWeekPtr->setSelected(false);
	mButtonMonthPtr->setSelected(false);

	DisPlaySelectModeStatus(HistoryMode);

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

void DisPlaySelectModeStatus(int index)
{
	int linechar_index;
	switch(index)
	{
		case History_TempMode:
		{
//			HistoryMode = History_TempMode;
			mWindowTempHumdPtr->setVisible(true);
			mWindowCO2PM25Ptr->setVisible(false);
			mWindowFormalDedhyPtr->setVisible(false);

			if(mButtonDayPtr->isSelected() || mButtonWeekPtr->isSelected())
			{
				linechar_index = 0;
				mWindowTempHumdWavePtr->setVisible(true);
				mWindowCO2PM25JQPtr->setVisible(false);
				mWindowTempHumdWaveMonthPtr->setVisible(false);
				mWindowCO2PM25JQMonthPtr->setVisible(false);

				//mPainterXPtr[linechar_index]->setLineWidth(2);
				//mPainterXPtr[linechar_index]->setSourceColor(0x88cffa);
				//mPainterXPtr[linechar_index]->drawLines(pointX0, TABLESIZE(pointX0));
			}
			else
			{
				linechar_index = 2;
				mWindowTempHumdWavePtr->setVisible(false);
				mWindowCO2PM25JQPtr->setVisible(false);
				mWindowTempHumdWaveMonthPtr->setVisible(true);
				mWindowCO2PM25JQMonthPtr->setVisible(false);

				//mPainterXPtr[linechar_index]->setLineWidth(2);
				//mPainterXPtr[linechar_index]->setSourceColor(0x88cffa);
				//mPainterXPtr[linechar_index]->drawLines(pointX2, TABLESIZE(pointX2));
			}



			mTextView6Ptr->setVisible(true);
			mTextView7Ptr->setVisible(true);
			mTextView8Ptr->setVisible(true);
			mTextView9Ptr->setVisible(true);
			mTextView10Ptr->setVisible(true);
			mTextView11Ptr->setVisible(true);
			mTextView12Ptr->setVisible(true);
			mTextView13Ptr->setVisible(true);

			mTextView14Ptr->setVisible(true);
			mTextView15Ptr->setVisible(true);
			mTextView16Ptr->setVisible(true);
			mTextView17Ptr->setVisible(true);

			mTextView9Ptr->setText("℃");
			mTextView13Ptr->setText("℃");
			mTextView17Ptr->setText("℃");
			mTextViewTempPtr->setVisible(true);
			mTextViewHumdPtr->setVisible(false);

			mTextViewPicTemp1Ptr->setVisible(true);
			mTextViewPicCO21Ptr->setVisible(false);
			mTextViewPicHumd1Ptr->setVisible(false);
			mTextViewPicPM251Ptr->setVisible(false);
			mTextViewPicJQ1Ptr->setVisible(false);

			mTextViewPicGoodPtr->setVisible(false);
			mTextViewPicMidGoodPtr->setVisible(false);
			mTextViewPicMidPtr->setVisible(false);
			mTextViewPicBadPtr->setVisible(false);
		}
			break;
		case History_HumdMode:
		{
//			HistoryMode = History_HumdMode;
			mWindowTempHumdPtr->setVisible(true);
			mWindowCO2PM25Ptr->setVisible(false);
			mWindowFormalDedhyPtr->setVisible(false);

			if(mButtonDayPtr->isSelected() || mButtonWeekPtr->isSelected())
			{
				linechar_index = 0;
				mWindowTempHumdWavePtr->setVisible(true);
				mWindowCO2PM25JQPtr->setVisible(false);
				mWindowTempHumdWaveMonthPtr->setVisible(false);
				mWindowCO2PM25JQMonthPtr->setVisible(false);

				//mPainterXPtr[linechar_index]->setLineWidth(2);
				//mPainterXPtr[linechar_index]->setSourceColor(0x88cffa);
				//mPainterXPtr[linechar_index]->drawLines(pointX0, TABLESIZE(pointX0));
			}
			else
			{
				linechar_index = 2;
				mWindowTempHumdWavePtr->setVisible(false);
				mWindowCO2PM25JQPtr->setVisible(false);
				mWindowTempHumdWaveMonthPtr->setVisible(true);
				mWindowCO2PM25JQMonthPtr->setVisible(false);

				//mPainterXPtr[linechar_index]->setLineWidth(2);
				//mPainterXPtr[linechar_index]->setSourceColor(0x88cffa);
				//mPainterXPtr[linechar_index]->drawLines(pointX2, TABLESIZE(pointX2));
			}

			mTextView6Ptr->setVisible(true);
			mTextView7Ptr->setVisible(true);
			mTextView8Ptr->setVisible(true);
			mTextView9Ptr->setVisible(true);
			mTextView10Ptr->setVisible(true);
			mTextView11Ptr->setVisible(true);
			mTextView12Ptr->setVisible(true);
			mTextView13Ptr->setVisible(true);

			mTextView14Ptr->setVisible(false);
			mTextView15Ptr->setVisible(false);
			mTextView16Ptr->setVisible(false);
			mTextView17Ptr->setVisible(false);

			mTextView9Ptr->setText("%");
			mTextView13Ptr->setText("%");
			mTextView17Ptr->setText("%");
			mTextViewTempPtr->setVisible(false);
			mTextViewHumdPtr->setVisible(true);

			mTextViewPicTemp1Ptr->setVisible(false);
			mTextViewPicCO21Ptr->setVisible(false);
			mTextViewPicHumd1Ptr->setVisible(true);
			mTextViewPicPM251Ptr->setVisible(false);
			mTextViewPicJQ1Ptr->setVisible(false);

			mTextViewPicGoodPtr->setVisible(false);
			mTextViewPicMidGoodPtr->setVisible(false);
			mTextViewPicMidPtr->setVisible(false);
			mTextViewPicBadPtr->setVisible(false);
		}
			break;
		case History_CO2Mode:
		{
//			HistoryMode = History_CO2Mode;
			mWindowCO2PM25Ptr->setVisible(true);
			mWindowTempHumdPtr->setVisible(false);
			mWindowFormalDedhyPtr->setVisible(false);
			mTextView22Ptr->setVisible(true);
			mTextView23Ptr->setVisible(true);
			mTextView24Ptr->setVisible(true);
			mTextView25Ptr->setVisible(true);

			//顶部的状态“优良中差”

			if(mButtonDayPtr->isSelected() || mButtonWeekPtr->isSelected())
			{
				linechar_index = 1;
				mWindowTempHumdWavePtr->setVisible(false);
				mWindowCO2PM25JQPtr->setVisible(true);
				mWindowTempHumdWaveMonthPtr->setVisible(false);
				mWindowCO2PM25JQMonthPtr->setVisible(false);

				//mPainterXPtr[linechar_index]->setLineWidth(2);
				//mPainterXPtr[linechar_index]->setSourceColor(0x88cffa);
				//mPainterXPtr[linechar_index]->drawLines(pointX1, TABLESIZE(pointX1));
			}
			else
			{
				linechar_index = 3;
				mWindowTempHumdWavePtr->setVisible(false);
				mWindowCO2PM25JQPtr->setVisible(false);
				mWindowTempHumdWaveMonthPtr->setVisible(false);
				mWindowCO2PM25JQMonthPtr->setVisible(true);

				//mPainterXPtr[linechar_index]->setLineWidth(2);
				//mPainterXPtr[linechar_index]->setSourceColor(0x88cffa);
				//mPainterXPtr[linechar_index]->drawLines(pointX3, TABLESIZE(pointX3));
			}

			mTextView26Ptr->setVisible(false);
			mTextView27Ptr->setVisible(false);
			mTextView28Ptr->setVisible(false);
			mTextView29Ptr->setVisible(false);
			mTextView30Ptr->setVisible(false);
			mTextView31Ptr->setVisible(false);
			mTextView32Ptr->setVisible(false);
			mTextView33Ptr->setVisible(false);

			mTextView25Ptr->setText("ppm");
			mTextViewppmPtr->setVisible(true);
			mTextViewugm3Ptr->setVisible(false);
			mTextViewmgm3Ptr->setVisible(false);

			mTextViewPicTemp1Ptr->setVisible(false);
			mTextViewPicCO21Ptr->setVisible(true);
			mTextViewPicHumd1Ptr->setVisible(false);
			mTextViewPicPM251Ptr->setVisible(false);
			mTextViewPicJQ1Ptr->setVisible(false);

			mTextViewPicGoodPtr->setVisible(true);
			mTextViewPicMidGoodPtr->setVisible(false);
			mTextViewPicMidPtr->setVisible(false);
			mTextViewPicBadPtr->setVisible(false);


		}
			break;
		case History_PM25Mode:
		{
//			HistoryMode = History_PM25Mode;
			mWindowCO2PM25Ptr->setVisible(true);
			mWindowTempHumdPtr->setVisible(false);
			mWindowFormalDedhyPtr->setVisible(false);
			mTextView22Ptr->setVisible(true);
			mTextView23Ptr->setVisible(true);
			mTextView24Ptr->setVisible(true);
			mTextView25Ptr->setVisible(true);

			//顶部的状态“优良中差”

			if(mButtonDayPtr->isSelected() || mButtonWeekPtr->isSelected())
			{
				linechar_index = 1;
				mWindowTempHumdWavePtr->setVisible(false);
				mWindowCO2PM25JQPtr->setVisible(true);
				mWindowTempHumdWaveMonthPtr->setVisible(false);
				mWindowCO2PM25JQMonthPtr->setVisible(false);

				//mPainterXPtr[linechar_index]->setLineWidth(2);
				//mPainterXPtr[linechar_index]->setSourceColor(0x88cffa);
				//mPainterXPtr[linechar_index]->drawLines(pointX1, TABLESIZE(pointX1));
			}
			else
			{
				linechar_index = 3;
				mWindowTempHumdWavePtr->setVisible(false);
				mWindowCO2PM25JQPtr->setVisible(false);
				mWindowTempHumdWaveMonthPtr->setVisible(false);
				mWindowCO2PM25JQMonthPtr->setVisible(true);

				//mPainterXPtr[linechar_index]->setLineWidth(2);
				//mPainterXPtr[linechar_index]->setSourceColor(0x88cffa);
				//mPainterXPtr[linechar_index]->drawLines(pointX3, TABLESIZE(pointX3));
			}

			mTextView26Ptr->setVisible(true);
			mTextView27Ptr->setVisible(true);
			mTextView28Ptr->setVisible(true);
			mTextView29Ptr->setVisible(true);
			mTextView30Ptr->setVisible(true);
			mTextView31Ptr->setVisible(true);
			mTextView32Ptr->setVisible(true);
			mTextView33Ptr->setVisible(true);

//			mTextView25Ptr->setText(std::to_string(atoi(mTextView25Ptr->getText().c_str())));
//			mTextView29Ptr->setText(std::to_string(atoi(mTextView29Ptr->getText().c_str())));
//			mTextView33Ptr->setText(std::to_string(atoi(mTextView33Ptr->getText().c_str())));
//			mTextViewugm3Ptr->setText(std::to_string(atoi(mTextViewugm3Ptr->getText().c_str())));
//			mTextView29Ptr->setText("ug/m³");
//			mTextView33Ptr->setText("ug/m³");
			mTextView25Ptr->setText("ug/m³");
			mTextViewppmPtr->setVisible(false);
			mTextViewugm3Ptr->setVisible(true);
			mTextViewmgm3Ptr->setVisible(false);

			mTextViewPicTemp1Ptr->setVisible(false);
			mTextViewPicCO21Ptr->setVisible(false);
			mTextViewPicHumd1Ptr->setVisible(false);
			mTextViewPicPM251Ptr->setVisible(true);
			mTextViewPicJQ1Ptr->setVisible(false);

			mTextViewPicGoodPtr->setVisible(false);
			mTextViewPicMidGoodPtr->setVisible(true);
			mTextViewPicMidPtr->setVisible(false);
			mTextViewPicBadPtr->setVisible(false);
		}
			break;
		case History_JQMode:
		{
//			HistoryMode = History_JQMode;
			mWindowFormalDedhyPtr->setVisible(true);
			mWindowTempHumdPtr->setVisible(false);
			mWindowCO2PM25Ptr->setVisible(false);
			mTextView36Ptr->setVisible(true);
			mTextView37Ptr->setVisible(true);
			mTextView38Ptr->setVisible(true);
			mTextView39Ptr->setVisible(true);

			mTextViewmgm3Ptr->setVisible(true);

			if(mButtonDayPtr->isSelected() || mButtonWeekPtr->isSelected())
			{
				linechar_index = 1;
				mWindowTempHumdWavePtr->setVisible(false);
				mWindowCO2PM25JQPtr->setVisible(true);
				mWindowTempHumdWaveMonthPtr->setVisible(false);
				mWindowCO2PM25JQMonthPtr->setVisible(false);

				//mPainterXPtr[linechar_index]->setLineWidth(2);
				//mPainterXPtr[linechar_index]->setSourceColor(0x88cffa);
				//mPainterXPtr[linechar_index]->drawLines(pointX1, TABLESIZE(pointX1));
			}
			else
			{
				linechar_index = 3;
				mWindowTempHumdWavePtr->setVisible(false);
				mWindowCO2PM25JQPtr->setVisible(false);
				mWindowTempHumdWaveMonthPtr->setVisible(false);
				mWindowCO2PM25JQMonthPtr->setVisible(true);

				//mPainterXPtr[linechar_index]->setLineWidth(2);
				//mPainterXPtr[linechar_index]->setSourceColor(0x88cffa);
				//mPainterXPtr[linechar_index]->drawLines(pointX3, TABLESIZE(pointX3));
			}
			mTextViewppmPtr->setVisible(false);
			mTextViewugm3Ptr->setVisible(false);
			mTextViewmgm3Ptr->setVisible(true);

			mTextViewPicTemp1Ptr->setVisible(false);
			mTextViewPicCO21Ptr->setVisible(false);
			mTextViewPicHumd1Ptr->setVisible(false);
			mTextViewPicPM251Ptr->setVisible(false);
			mTextViewPicJQ1Ptr->setVisible(true);
//			mTextViewmgm3Ptr->setText(std::to_string(atoi(mTextViewmgm3Ptr->getText().c_str())));
//			mTextView38Ptr->setText(std::to_string(atoi(mTextView38Ptr->getText().c_str())));
			mTextViewPicGoodPtr->setVisible(false);
			mTextViewPicMidGoodPtr->setVisible(false);
			mTextViewPicMidPtr->setVisible(false);
			mTextViewPicBadPtr->setVisible(true);

		}
			break;
//		case 5:
//			break;
		default:
			break;
	}


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
static bool onHistoryDateActivityTouchEvent(const MotionEvent &ev) {
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
static bool onButtonClick_ButtonTemp(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonTemp !!!\n");
    if(HistoryMode != History_TempMode)
    {
    	HistoryMode = History_TempMode;
    }
	pButton->setSelected(true);

    DisPlaySelectModeStatus(HistoryMode);
    return false;
}

static bool onButtonClick_ButtonHumd(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonHumd !!!\n");

    if(HistoryMode != History_HumdMode)
    {
    	HistoryMode = History_HumdMode;
    }
	pButton->setSelected(true);

    DisPlaySelectModeStatus(HistoryMode);


    return false;
}

static bool onButtonClick_ButtonCO2(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonCO2 !!!\n");

    if(HistoryMode != History_CO2Mode)
	{
		HistoryMode = History_CO2Mode;
	}
	pButton->setSelected(true);

	DisPlaySelectModeStatus(HistoryMode);



    return false;
}

static bool onButtonClick_ButtonPM25(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonPM25 !!!\n");

    if(HistoryMode != History_PM25Mode)
	{
		HistoryMode = History_PM25Mode;
	}
	pButton->setSelected(true);

	DisPlaySelectModeStatus(HistoryMode);



    return false;
}

static bool onButtonClick_Buttonformaldehyde(ZKButton *pButton) {
    LOGD(" ButtonClick Buttonformaldehyde !!!\n");

    if(HistoryMode != History_JQMode)
	{
		HistoryMode = History_JQMode;
	}
	pButton->setSelected(true);

	DisPlaySelectModeStatus(HistoryMode);



    return false;
}

static bool onButtonClick_ButtonDay(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonDay !!!\n");
    if(pButton->isSelected())
    {
    	return false;
    }
    else
    {
    	pButton->setSelected(true);
    	mButtonWeekPtr->setSelected(false);
    	mButtonMonthPtr->setSelected(false);


    	if((HistoryMode == History_TempMode) || (HistoryMode == History_HumdMode))
        {
        	mWindowTempHumdWavePtr->setVisible(true);
        	mWindowCO2PM25JQPtr->setVisible(false);
        	mWindowTempHumdWaveMonthPtr->setVisible(false);
			mWindowCO2PM25JQMonthPtr->setVisible(false);
        }
    	else if((HistoryMode == History_CO2Mode) || (HistoryMode == History_PM25Mode) || (HistoryMode == History_JQMode))
        {
        	mWindowTempHumdWavePtr->setVisible(false);
    		mWindowCO2PM25JQPtr->setVisible(true);
    		mWindowTempHumdWaveMonthPtr->setVisible(false);
			mWindowCO2PM25JQMonthPtr->setVisible(false);
        }
    }
    DisPlaySelectModeStatus(HistoryMode);
    return false;
}

static bool onButtonClick_ButtonWeek(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonWeek !!!\n");
    if(pButton->isSelected())
	{
    	return false;
	}
	else
	{
		pButton->setSelected(true);
		mButtonDayPtr->setSelected(false);
		mButtonMonthPtr->setSelected(false);

		if((HistoryMode == History_TempMode) || (HistoryMode == History_HumdMode))
		{
			mWindowTempHumdWavePtr->setVisible(true);
			mWindowCO2PM25JQPtr->setVisible(false);
			mWindowTempHumdWaveMonthPtr->setVisible(false);
			mWindowCO2PM25JQMonthPtr->setVisible(false);
		}
		else if((HistoryMode == History_CO2Mode) || (HistoryMode == History_PM25Mode) || (HistoryMode == History_JQMode))
		{
			mWindowTempHumdWavePtr->setVisible(false);
			mWindowCO2PM25JQPtr->setVisible(true);
			mWindowTempHumdWaveMonthPtr->setVisible(false);
			mWindowCO2PM25JQMonthPtr->setVisible(false);
		}
	}
    DisPlaySelectModeStatus(HistoryMode);
    return false;
}

static bool onButtonClick_ButtonMonth(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonMonth !!!\n");
    if(pButton->isSelected())
   	{
       	return false;
   	}
   	else
   	{
   		pButton->setSelected(true);
   		mButtonDayPtr->setSelected(false);
   		mButtonWeekPtr->setSelected(false);

   		if((HistoryMode == History_TempMode) || (HistoryMode == History_HumdMode))
		{
			mWindowTempHumdWavePtr->setVisible(false);
			mWindowCO2PM25JQPtr->setVisible(false);
			mWindowTempHumdWaveMonthPtr->setVisible(true);
			mWindowCO2PM25JQMonthPtr->setVisible(false);
		}
		else if((HistoryMode == History_CO2Mode) || (HistoryMode == History_PM25Mode) || (HistoryMode == History_JQMode))
		{
			mWindowTempHumdWavePtr->setVisible(false);
			mWindowCO2PM25JQPtr->setVisible(false);
			mWindowTempHumdWaveMonthPtr->setVisible(false);
			mWindowCO2PM25JQMonthPtr->setVisible(true);
		}
   	}
    DisPlaySelectModeStatus(HistoryMode);
    return false;
}

static bool onButtonClick_ButtonDropDown(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonDropDown !!!\n");
    return false;
}

static bool onButtonClick_ButtonBack(ZKButton *pButton) {
    LOGD(" ButtonClick ButtonBack !!!\n");
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
