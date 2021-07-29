/*
 * UserIMESysApp.cpp
 *
 *  Created on: Nov 1, 2017
 *      Author: guoxs
 */

#include "entry/EasyUIContext.h"
#include "app/SysAppFactory.h"
#include "control/ZKButton.h"
#include "control/ZKTextView.h"
#include "window/ZKWindow.h"
#include "utils/Log.h"
#include "manager/ConfigManager.h"
#include "pinyin/pinyinime.h"
#include "pinyin/ConvertUTF.h"
#include "UserIMESysApp.h"

using namespace ime_pinyin;

#define MAX_SEARCH_HANZI		256
#define MAX_PINYIN_LEN			64

static bool toUTF8(UTF8 *dest, size_t destLen, const char16 *src, size_t srcLen) {
	UTF16 *utf16Start = (UTF16 *) src;
	UTF16 *utf16End = (UTF16 *) (src + srcLen);

	return ConvertUTF16toUTF8((const UTF16 **) &utf16Start, utf16End, &dest,
			dest + destLen - 1, strictConversion) == conversionOK;
}

/* register UserIMESysApp */
REGISTER_SYSAPP(APP_TYPE_SYS_IME, UserIMESysApp);

typedef struct {
	int id;
	const char *ch;
	const char *upch;
	const char *numch;
	const char *symb;
} SKeypadInfo;

typedef struct {
	int id;
	char ch;
} SNumKeypadInfo;

// 英文键盘
static const SKeypadInfo sEnglishKeypadInfoTab[] = {
	ID_IME_BUTTON_Q, "q", "Q", "1", "[",
	ID_IME_BUTTON_W, "w", "W", "2", "]",
	ID_IME_BUTTON_E, "e", "E", "3", "{",
	ID_IME_BUTTON_R, "r", "R", "4", "}",
	ID_IME_BUTTON_T, "t", "T", "5", "#",
	ID_IME_BUTTON_Y, "y", "Y", "6", "%",
	ID_IME_BUTTON_U, "u", "U", "7", "^",
	ID_IME_BUTTON_I, "i", "I", "8", "*",
	ID_IME_BUTTON_O, "o", "O", "9", "+",
	ID_IME_BUTTON_P, "p", "P", "0", "=",

	ID_IME_BUTTON_A, "a", "A", "-", "_",
	ID_IME_BUTTON_S, "s", "S", "/", "\\",
	ID_IME_BUTTON_D, "d", "D", ":", "|",
	ID_IME_BUTTON_F, "f", "F", ";", "~",
	ID_IME_BUTTON_G, "g", "G", "(", "<",
	ID_IME_BUTTON_H, "h", "H", ")", ">",
	ID_IME_BUTTON_J, "j", "J", "$", "$",
	ID_IME_BUTTON_K, "k", "K", "&", "&",
	ID_IME_BUTTON_L, "l", "L", "@", "@",

	ID_IME_BUTTON_Z, "z", "Z", ".", ".",
	ID_IME_BUTTON_X, "x", "X", ",", ",",
	ID_IME_BUTTON_C, "c", "C", "?", "?",
	ID_IME_BUTTON_V, "v", "V", "!", "!",
	ID_IME_BUTTON_B, "b", "B", "\'", "\'",
	ID_IME_BUTTON_N, "n", "N", "\"", "\"",
	ID_IME_BUTTON_M, "m", "M", "`", "`",

	ID_IME_BUTTON_COMMA, ",", "!", NULL, NULL,
	ID_IME_BUTTON_DOT, ".", "?", NULL, NULL,

	ID_IME_BUTTON_SPACE, " ", " ", " ", " ",
	ID_IME_BUTTON_ENTER, "\r", "\r", "\r", "\r",
	0, NULL, NULL, NULL, NULL
};

// 中文键盘
static const SKeypadInfo sChineseKeypadInfoTab[] = {
	ID_IME_BUTTON_Q, "q", "Q", "1", "【",
	ID_IME_BUTTON_W, "w", "W", "2", "】",
	ID_IME_BUTTON_E, "e", "E", "3", "{",
	ID_IME_BUTTON_R, "r", "R", "4", "}",
	ID_IME_BUTTON_T, "t", "T", "5", "#",
	ID_IME_BUTTON_Y, "y", "Y", "6", "%",
	ID_IME_BUTTON_U, "u", "U", "7", "-",
	ID_IME_BUTTON_I, "i", "I", "8", "*",
	ID_IME_BUTTON_O, "o", "O", "9", "+",
	ID_IME_BUTTON_P, "p", "P", "0", "=",

	ID_IME_BUTTON_A, "a", "A", "-", "_",
	ID_IME_BUTTON_S, "s", "S", "/", "——",
	ID_IME_BUTTON_D, "d", "D", "：", "\\",
	ID_IME_BUTTON_F, "f", "F", "；", "|",
	ID_IME_BUTTON_G, "g", "G", "（", "～",
	ID_IME_BUTTON_H, "h", "H", "）", "《",
	ID_IME_BUTTON_J, "j", "J", "￥", "》",
	ID_IME_BUTTON_K, "k", "K", "@", "&",
	ID_IME_BUTTON_L, "l", "L", ".", ".",

	ID_IME_BUTTON_Z, "z", "Z", "。", "。",
	ID_IME_BUTTON_X, "x", "X", "，", "，",
	ID_IME_BUTTON_C, "c", "C", "、", "、",
	ID_IME_BUTTON_V, "v", "V", "？", "？",
	ID_IME_BUTTON_B, "b", "B", "！", "！",
	ID_IME_BUTTON_N, "n", "N", "“", "“",
	ID_IME_BUTTON_M, "m", "M", "”", "”",

	ID_IME_BUTTON_COMMA, "，", "！", NULL, NULL,
	ID_IME_BUTTON_DOT, "。", "？", NULL, NULL,

	ID_IME_BUTTON_SPACE, " ", " ", " ", " ",
	ID_IME_BUTTON_ENTER, "\r", "\r", "\r", "\r",
	0, NULL, NULL, NULL, NULL
};

static const SNumKeypadInfo sNumKeypadInfoTab[] = {
	ID_IME_BUTTON_NUMBER_1, '1',
	ID_IME_BUTTON_NUMBER_2, '2',
	ID_IME_BUTTON_NUMBER_3, '3',
	ID_IME_BUTTON_NUMBER_4, '4',
	ID_IME_BUTTON_NUMBER_5, '5',
	ID_IME_BUTTON_NUMBER_6, '6',
	ID_IME_BUTTON_NUMBER_7, '7',
	ID_IME_BUTTON_NUMBER_8, '8',
	ID_IME_BUTTON_NUMBER_9, '9',
	ID_IME_BUTTON_NUMBER_0, '0',
	ID_IME_BUTTON_NUMBER_PLUS, '+',
	ID_IME_BUTTON_NUMBER_MINUS, '-',
	ID_IME_BUTTON_NUMBER_DOT, '.',
	ID_IME_BUTTON_NUMBER_PERCENT, '%',
	ID_IME_BUTTON_NUMBER_MULT, '*',
	ID_IME_BUTTON_NUMBER_DIV, '/',
	ID_IME_BUTTON_NUMBER_SPACE, ' ',
	0, 0
};

UserIMESysApp::UserIMESysApp() :
	mLangType(E_LANG_CHINESE),
	mKeypadType(E_KEYPAD_CHAR),
	mIsIMOpenDecoderOK(false) {

}

UserIMESysApp::~UserIMESysApp() {
	im_close_decoder();
}

const char* UserIMESysApp::getAppName() const {
	return "UserIme.ftu";
}

void UserIMESysApp::onCreate() {
	BaseApp::onCreate();

	mTextViewContentPtr = (ZKTextView *) findControlByID(ID_IME_TEXTVIEW_CONTENT);
	mTextViewLShiftPtr = (ZKTextView *) findControlByID(ID_IME_BUTTON_LSHIFT);
	mTextViewRShiftPtr = (ZKTextView *) findControlByID(ID_IME_BUTTON_RSHIFT);
	mTextViewLSymbolPtr = (ZKTextView *) findControlByID(ID_IME_BUTTON_LSYMBOL);
	mTextViewRSymbolPtr = (ZKTextView *) findControlByID(ID_IME_BUTTON_RSYMBOL);
	mTextViewPinyinPtr = (ZKTextView *) findControlByID(ID_IME_TEXTVIEW_PINYIN);

	mSlideTextHanZiPtr = (ZKSlideText *) findControlByID(ID_IME_SLIDETEXT_HANZI);
	if (mSlideTextHanZiPtr) {
		mSlideTextHanZiPtr->setTextUnitClickListener(this);
	}

	ZKBase *pDel = findControlByID(ID_IME_BUTTON_DEL);
	if (pDel) {
		pDel->setLongClickListener(this);
	}

	pDel = findControlByID(ID_IME_BUTTON_NUMBER_DEL);
	if (pDel) {
		pDel->setLongClickListener(this);
	}
}

void UserIMESysApp::onClick(ZKBase *pBase) {
	BaseApp::onClick(pBase);

	if (!mIsIMOpenDecoderOK && (pBase->getID() == ID_IME_BUTTON_LANG)) {
		return;
	}

	switch (pBase->getID()) {
	case ID_IME_BUTTON_LANG:
	case ID_IME_BUTTON_LSHIFT:
	case ID_IME_BUTTON_RSHIFT:
	case ID_IME_BUTTON_LSYMBOL:
	case ID_IME_BUTTON_RSYMBOL:
		if (!mPinyinStr.empty()) {
			const std::string &text = mSlideTextHanZiPtr->getText(0);
			if (!text.empty()) {
				addStr(mIMETextInfoPtr->text.length(), text);
			}

			clearPinyin();
		}
		break;
	}

	switch (pBase->getID()) {
	case ID_IME_BUTTON_LANG:
		mLangType = (mLangType == E_LANG_CHINESE) ? E_LANG_ENGLISH : E_LANG_CHINESE;
		mKeypadType = E_KEYPAD_CHAR;
		reshowAllKey();
		break;
	case ID_IME_BUTTON_LSHIFT:
	case ID_IME_BUTTON_RSHIFT:
		switch (mKeypadType) {
		case E_KEYPAD_CHAR: mKeypadType = E_KEYPAD_UPERCHAR; break;
		case E_KEYPAD_UPERCHAR: mKeypadType = E_KEYPAD_CHAR; break;
		case E_KEYPAD_NUMCHAR: mKeypadType = E_KEYPAD_SYMBOL; break;
		case E_KEYPAD_SYMBOL: mKeypadType = E_KEYPAD_NUMCHAR; break;
		}
		reshowAllKey();
		break;
	case ID_IME_BUTTON_LSYMBOL:
	case ID_IME_BUTTON_RSYMBOL:
		switch (mKeypadType) {
		case E_KEYPAD_CHAR:
		case E_KEYPAD_UPERCHAR:
			mKeypadType = E_KEYPAD_NUMCHAR;
			break;
		case E_KEYPAD_NUMCHAR:
		case E_KEYPAD_SYMBOL:
			mKeypadType = E_KEYPAD_CHAR;
			break;
		}
		reshowAllKey();
		break;
	case ID_IME_BUTTON_DEL:
	case ID_IME_BUTTON_NUMBER_DEL:
		if (mPinyinStr.empty()) {
			delOneChar(mIMETextInfoPtr->text.length());
		} else {
			if (mPinyinStr.size() == 1) {
				clearPinyin();
			} else {
				mPinyinStr.erase(mPinyinStr.length() - 1);
				mTextViewPinyinPtr->setText(mPinyinStr);

				searchHanZi();
			}
		}
		break;
	case ID_IME_BUTTON_ENTER:
	case ID_IME_BUTTON_NUMBER_ENTER:
		if (mPinyinStr.empty()) {
			doneIMETextUpdate(mIMETextInfoPtr->text);
		} else {
			addStr(mIMETextInfoPtr->text.length(), mPinyinStr);
			clearPinyin();
		}
		break;
	case ID_IME_BUTTON_HIDE:
	case ID_IME_BUTTON_NUMBER_HIDE:
		cancelIMETextUpdate();
		break;
	default:
		if (mIMETextInfoPtr->imeTextType == IMEContext::E_IME_TEXT_TYPE_ALL) {
			const SKeypadInfo *tab = (mLangType == E_LANG_CHINESE) ? sChineseKeypadInfoTab : sEnglishKeypadInfoTab;
			for (int i = 0; tab[i].id != 0; i++) {
				if (tab[i].id == pBase->getID()) {
					const char *str = NULL;

					switch (mKeypadType) {
					case E_KEYPAD_CHAR: str = tab[i].ch; break;
					case E_KEYPAD_UPERCHAR: str = tab[i].upch; break;
					case E_KEYPAD_NUMCHAR: str = tab[i].numch; break;
					case E_KEYPAD_SYMBOL: str = tab[i].symb; break;
					}

					if (!str) {
						break;
					}

					if (mLangType == E_LANG_CHINESE) {
						if (((str[0] >= 'A') && (str[0] <= 'Z')) ||
							((str[0] >= 'a') && (str[0] <= 'z'))) {
							if (mPinyinStr.length() < MAX_PINYIN_LEN) {
								mPinyinStr += str[0];
								mTextViewPinyinPtr->setText(mPinyinStr);
								searchHanZi();
							}
							break;
						} else if (!mPinyinStr.empty()) {
							const std::string &text = mSlideTextHanZiPtr->getText(0);
							if (!text.empty()) {
								addStr(mIMETextInfoPtr->text.length(), text);
							}

							clearPinyin();

							if (tab[i].id == ID_IME_BUTTON_SPACE) {
								break;
							}
						}
					}

					addStr(mIMETextInfoPtr->text.length(), str);

					break;
				}
			}
		} else if (mIMETextInfoPtr->imeTextType == IMEContext::E_IME_TEXT_TYPE_NUMBER) {
			for (int i = 0; sNumKeypadInfoTab[i].id != 0; i++) {
				if (sNumKeypadInfoTab[i].id == pBase->getID()) {
					addStr(mIMETextInfoPtr->text.length(), std::string() + sNumKeypadInfoTab[i].ch);
					break;
				}
			}
		}
		break;
	}
}

void UserIMESysApp::onLongClick(ZKBase *pBase) {
	switch (pBase->getID()) {
	case ID_IME_BUTTON_DEL:
	case ID_IME_BUTTON_NUMBER_DEL:
		// 长按删除按钮，删除所有
		delAll();
		break;
	}
}

void UserIMESysApp::onTextUnitClick(ZKSlideText *pSlideText, const std::string &text) {
	addStr(mIMETextInfoPtr->text.length(), text);

	clearPinyin();
}

void UserIMESysApp::onInitIME(SIMETextInfo *pInfo) {
	updateContentText();

	if (pInfo->imeTextType == IMEContext::E_IME_TEXT_TYPE_NUMBER) {
		ZKWindow *pWnd = (ZKWindow *) findControlByID(ID_IME_WINDOW_ALL);
		if (pWnd) {
			pWnd->hideWnd();
		}

		pWnd = (ZKWindow *) findControlByID(ID_IME_WINDOW_NUMBER);
		if (pWnd) {
			pWnd->showWnd();
		}
	} else {
//		mIsIMOpenDecoderOK = im_open_decoder(CONFIGMANAGER->getDictPinyinPath().c_str(), "/data/user.dic");
		mIsIMOpenDecoderOK = im_open_decoder(CONFIGMANAGER->getDictPinyinPath().c_str(), "/customer_app/res/dict_pinyin.dat");
		LOGD("onInitIME mIsIMOpenDecoderOK: %d\n", mIsIMOpenDecoderOK);

		if (!mIsIMOpenDecoderOK || mIMETextInfoPtr->isPassword) {
			mLangType = E_LANG_ENGLISH;
		}

		reshowAllKey();
	}
}

void UserIMESysApp::reshowAllKey() {
	const SKeypadInfo *tab = (mLangType == E_LANG_CHINESE) ? sChineseKeypadInfoTab : sEnglishKeypadInfoTab;
	for (int i = 0; tab[i].id != 0; ++i) {
		if (tab[i].id == ID_IME_BUTTON_ENTER) {
			continue;
		}

		ZKTextView *pTextView = (ZKTextView *) findControlByID(tab[i].id);
		if (!pTextView) {
			continue;
		}

		if (tab[i].id == ID_IME_BUTTON_SPACE) {
			pTextView->setText((mLangType == E_LANG_CHINESE) ? "" : "Space");
			continue;
		}

		const char *str = NULL;

		switch (mKeypadType) {
		case E_KEYPAD_CHAR: str = tab[i].ch; break;
		case E_KEYPAD_UPERCHAR: str = tab[i].upch; break;
		case E_KEYPAD_NUMCHAR: str = tab[i].numch; break;
		case E_KEYPAD_SYMBOL: str = tab[i].symb; break;
		}

		if (str) {
			pTextView->setText(str);
		}
		pTextView->setVisible(str != NULL);
	}

	mTextViewLShiftPtr->setSelected(mKeypadType == E_KEYPAD_UPERCHAR);
	mTextViewRShiftPtr->setSelected(mKeypadType == E_KEYPAD_UPERCHAR);

	switch (mKeypadType) {
	case E_KEYPAD_CHAR:
	case E_KEYPAD_UPERCHAR:
		mTextViewLShiftPtr->setText("Shift");
		mTextViewRShiftPtr->setText("Shift");
		mTextViewLSymbolPtr->setText(".?123");
		mTextViewRSymbolPtr->setText(".?123");
		break;
	case E_KEYPAD_NUMCHAR:
		mTextViewLShiftPtr->setText("#+=");
		mTextViewRShiftPtr->setText("#+=");
		mTextViewLSymbolPtr->setText("ABC");
		mTextViewRSymbolPtr->setText("ABC");
		break;
	case E_KEYPAD_SYMBOL:
		mTextViewLShiftPtr->setText("123");
		mTextViewRShiftPtr->setText("123");
		mTextViewLSymbolPtr->setText("ABC");
		mTextViewRSymbolPtr->setText("ABC");
		break;
	}
}

void UserIMESysApp::updateContentText() {
	if (!mIMETextInfoPtr->isPassword) {
		mTextViewContentPtr->setText(mIMETextInfoPtr->text);
	} else {
		if (!mIMETextInfoPtr->text.empty()) {
			char *pPwdStr = new char[mIMETextInfoPtr->text.length() + 1];
			pPwdStr[mIMETextInfoPtr->text.length()] = '\0';
			memset(pPwdStr, mIMETextInfoPtr->passwordChar, mIMETextInfoPtr->text.length());
			mTextViewContentPtr->setText(pPwdStr);
			delete[] pPwdStr;
		} else {
			mTextViewContentPtr->setText("");
		}
	}
}

void UserIMESysApp::addStr(int pos, const std::string &str) {
	if (str.empty() || (pos < 0) || (pos > mIMETextInfoPtr->text.length())) {
		return;
	}

	mIMETextInfoPtr->text.insert(pos, str);
	updateContentText();
}

void UserIMESysApp::delOneChar(int pos) {
	if (mIMETextInfoPtr->text.empty() || (pos <= 0) || (pos > mIMETextInfoPtr->text.length())) {
		return;
	}

	int size = 1;
	pos--;
	if (mIMETextInfoPtr->text[pos] & 0x80) {
		while ((pos > 0) && !(mIMETextInfoPtr->text[pos] & 0x40)) {
			size++;
			pos--;
		}
	}
	mIMETextInfoPtr->text.erase(pos, size);

	updateContentText();
}

void UserIMESysApp::delAll() {
	clearPinyin();

	if (!mIMETextInfoPtr->text.empty()) {
		mIMETextInfoPtr->text.clear();
		updateContentText();
	}
}

void UserIMESysApp::clearPinyin() {
	if (!mPinyinStr.empty()) {
		mPinyinStr.clear();
		mTextViewPinyinPtr->setText(mPinyinStr);
	}

	mSlideTextHanZiPtr->clearTextList();
}

void UserIMESysApp::searchHanZi() {
	if (!mIsIMOpenDecoderOK || mPinyinStr.empty()) {
		return;
	}

	std::vector<std::string> hanZiList;

	im_reset_search();
	size_t n = im_search(mPinyinStr.c_str(), mPinyinStr.length());
	if (n > MAX_SEARCH_HANZI) {
		n = MAX_SEARCH_HANZI;
	}

	char16 buffer[64];
	UTF8 utf8Buf[1024] = { 0 };

	for (size_t i = 0; i < n; i++) {
		im_get_candidate(i, buffer, 64);
		toUTF8(utf8Buf, 1024, buffer, 64);
		hanZiList.push_back((const char *) utf8Buf);
	}

	mSlideTextHanZiPtr->setTextList(hanZiList);
}
