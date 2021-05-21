/*
 * BitmapHelper.h
 *
 *  Created on: Jun 11, 2017
 *      Author: guoxs
 */

#ifndef _UTILS_BITMAP_HELPER_H_
#define _UTILS_BITMAP_HELPER_H_

struct _bitmap_t;

class BitmapHelper {
public:
	static bool loadBitmapFromFile(struct _bitmap_t *&pBmp, const char *pPath);
	static void unloadBitmap(struct _bitmap_t *&pBmp);
};

#endif /* _UTILS_BITMAP_HELPER_H_ */
