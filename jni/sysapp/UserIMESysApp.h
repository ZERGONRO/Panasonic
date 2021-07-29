/*
 * UserIMESysApp.h
 *
 *  Created on: Nov 1, 2017
 *      Author: guoxs
 */

#ifndef _SYSAPP_USERIMESYSAPP_H_
#define _SYSAPP_USERIMESYSAPP_H_

#define ID_IME_BUTTON_RSHIFT    20031
#define ID_IME_BUTTON_LSHIFT    20030
#define ID_IME_BUTTON_RSYMBOL    20055
#define ID_IME_BUTTON_LSYMBOL    20032
#define ID_IME_WINDOW_ALL    100000
#define ID_IME_BUTTON_NUMBER_SPACE    20120
#define ID_IME_BUTTON_NUMBER_DIV    20119
#define ID_IME_BUTTON_NUMBER_MULT    20118
#define ID_IME_BUTTON_NUMBER_PERCENT    20117
#define ID_IME_BUTTON_NUMBER_DOT    20116
#define ID_IME_BUTTON_NUMBER_MINUS    20115
#define ID_IME_BUTTON_NUMBER_PLUS    20113
#define ID_IME_BUTTON_NUMBER_HIDE    20091
#define ID_IME_BUTTON_NUMBER_ENTER    20087
#define ID_IME_BUTTON_NUMBER_DEL    20086
#define ID_IME_BUTTON_NUMBER_0    20114
#define ID_IME_BUTTON_NUMBER_9    20111
#define ID_IME_BUTTON_NUMBER_8    20110
#define ID_IME_BUTTON_NUMBER_7    20109
#define ID_IME_BUTTON_NUMBER_6    20108
#define ID_IME_BUTTON_NUMBER_5    20107
#define ID_IME_BUTTON_NUMBER_4    20106
#define ID_IME_BUTTON_NUMBER_3    20105
#define ID_IME_BUTTON_NUMBER_2    20104
#define ID_IME_BUTTON_NUMBER_1    20102
#define ID_IME_WINDOW_NUMBER    100001
#define ID_IME_TEXTVIEW_CONTENT    50000
#define ID_IME_TEXTVIEW_PINYIN    50003
#define ID_IME_BUTTON_LANG    20035
#define ID_IME_BUTTON_HIDE    20034
#define ID_IME_BUTTON_SPACE    20033
#define ID_IME_BUTTON_ENTER    20029
#define ID_IME_BUTTON_DEL    20028
#define ID_IME_BUTTON_DOT    20027
#define ID_IME_BUTTON_COMMA    20026
#define ID_IME_BUTTON_Z    20025
#define ID_IME_BUTTON_Y    20024
#define ID_IME_BUTTON_X    20023
#define ID_IME_BUTTON_W    20022
#define ID_IME_BUTTON_V    20021
#define ID_IME_BUTTON_U    20020
#define ID_IME_BUTTON_T    20019
#define ID_IME_BUTTON_S    20018
#define ID_IME_BUTTON_R    20017
#define ID_IME_BUTTON_Q    20016
#define ID_IME_BUTTON_P    20015
#define ID_IME_BUTTON_N    20014
#define ID_IME_BUTTON_M    20013
#define ID_IME_BUTTON_L    20012
#define ID_IME_BUTTON_O    20011
#define ID_IME_BUTTON_K    20010
#define ID_IME_BUTTON_J    20009
#define ID_IME_BUTTON_I    20008
#define ID_IME_BUTTON_H    20007
#define ID_IME_BUTTON_G    20006
#define ID_IME_BUTTON_F    20005
#define ID_IME_BUTTON_E    20004
#define ID_IME_BUTTON_D    20003
#define ID_IME_BUTTON_C    20002
#define ID_IME_BUTTON_B    20001
#define ID_IME_BUTTON_A    20000
#define ID_IME_SLIDETEXT_HANZI    51000

#include "app/IMEBaseApp.h"
#include "control/ZKSlideText.h"

class ZKTextView;

class UserIMESysApp :
		public IMEBaseApp,
		public ZKBase::ILongClickListener,
		public ZKSlideText::ITextUnitClickListener {
public:
	UserIMESysApp();
	virtual ~UserIMESysApp();

protected:
	virtual const char* getAppName() const;
	virtual void onCreate();
	virtual void onClick(ZKBase *pBase);
	virtual void onLongClick(ZKBase *pBase);
	virtual void onTextUnitClick(ZKSlideText *pSlideText, const std::string &text);
	virtual void onInitIME(SIMETextInfo *pInfo);

private:
	void reshowAllKey();
	void updateContentText();
	void addStr(int pos, const std::string &str);
	void delOneChar(int pos);
	void delAll();

	void clearPinyin();
	void searchHanZi();

private:
	enum {
		E_LANG_ENGLISH,
		E_LANG_CHINESE
	} mLangType;

	enum {
		E_KEYPAD_CHAR,
		E_KEYPAD_UPERCHAR,
		E_KEYPAD_NUMCHAR,
		E_KEYPAD_SYMBOL
	} mKeypadType;

	ZKTextView *mTextViewContentPtr;
	ZKTextView *mTextViewLShiftPtr;
	ZKTextView *mTextViewRShiftPtr;
	ZKTextView *mTextViewLSymbolPtr;
	ZKTextView *mTextViewRSymbolPtr;
	ZKTextView *mTextViewPinyinPtr;

	ZKSlideText *mSlideTextHanZiPtr;

	bool mIsIMOpenDecoderOK;

	std::string mPinyinStr;
};

#endif
