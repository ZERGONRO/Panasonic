#ifndef _UTILS_LOG_H_
#define _UTILS_LOG_H_

#include <stdio.h>
#include <stdlib.h>

#ifdef USE_ANDROID_LOG
#include <android/log.h>

#define LOG_TAG "zkgui"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#else
//#define LOGE(fmt,...)	fprintf(stderr, fmt, ##__VA_ARGS__)
//#define LOGD(fmt,...) 	fprintf(stderr, fmt, ##__VA_ARGS__)

#define LOGD_ENABLE 1

#include <string.h>

#define filename(x) strrchr(x, '/') ? strrchr(x, '/') + 1 : x

/************************************************************************
 ** 函数名:     get_sys_runtime
 ** 函数描述:   返回系统运行时间
 ** 参数:       [in]  1 - 秒,2 - 毫秒
 ** 返回:       秒/毫秒
 ************************************************************************/
inline long get_sys_runtime(int type)
{
    struct timespec times = { 0, 0 };
    long time;

    clock_gettime(CLOCK_MONOTONIC, &times);

    if (1 == type) {
        time = times.tv_sec;
    } else {
        time = times.tv_sec * 1000 + times.tv_nsec / 1000000;
    }

    return time;
}

#define LOGE(fmt, ...) \
    fprintf(stderr, "\033[0;31m[%5ld.%03ld] LOG_ERR>>> %s(%d) %s(): " fmt "\033[0m\n", get_sys_runtime(2) / 1000, get_sys_runtime(2) % 1000, filename(__FILE__), __LINE__, __func__, ##__VA_ARGS__)
#define LOGW(fmt, ...) \
    fprintf(stderr, "\033[0;33m[%5ld.%03ld] LOG_WARNING>>> %s(%d) %s(): " fmt "\033[0m\n", get_sys_runtime(2) / 1000, get_sys_runtime(2) % 1000, filename(__FILE__), __LINE__, __func__, ##__VA_ARGS__)
#define LOGI(fmt, ...) \
    fprintf(stderr, "\033[0;36m[%5ld.%03ld] LOG_INFO>>> %s(%d) %s(): " fmt "\033[0m\n", get_sys_runtime(2) / 1000, get_sys_runtime(2) % 1000, filename(__FILE__), __LINE__, __func__, ##__VA_ARGS__)

#if LOGD_ENABLE
#define LOGD(fmt, ...) \
    fprintf(stderr, "\033[0;32m[%5ld.%03ld] LOG_DEBUG>>> %s(%d) %s(): " fmt "\033[0m\n", get_sys_runtime(2) / 1000, get_sys_runtime(2) % 1000, filename(__FILE__), __LINE__, __func__, ##__VA_ARGS__)
#else
#define LOGD(fmt, ...)
#endif

#endif

#if 0

#define ZKSWE_DEBUG_EASYGUI
#ifdef ZKSWE_DEBUG_EASYGUI
#include <sys/time.h>
#define TIME_ELAPSED(codeToTime)                                                                                                      \
    do {                                                                                                                              \
        struct timeval beginTime, endTime;                                                                                            \
        gettimeofday(&beginTime, NULL);                                                                                               \
        {                                                                                                                             \
            codeToTime;                                                                                                               \
        }                                                                                                                             \
        gettimeofday(&endTime, NULL);                                                                                                 \
        long secTime = endTime.tv_sec - beginTime.tv_sec;                                                                             \
        long usecTime = endTime.tv_usec - beginTime.tv_usec;                                                                          \
        if (secTime) {                                                                                                                \
            long secTime1 = (secTime * 1000000 + endTime.tv_usec - beginTime.tv_usec) / 1000000;                                      \
            usecTime = (secTime * 1000000 + endTime.tv_usec - beginTime.tv_usec) % 1000000;                                           \
            fprintf(stderr, "[%s(%d)]Elapsed Time: SecTime = %lds, UsecTime = %ldus!\n", __FUNCTION__, __LINE__, secTime1, usecTime); \
        } else                                                                                                                        \
            fprintf(stderr, "[%s(%d)]Elapsed Time: SecTime = %lds, UsecTime = %ldus!\n", __FUNCTION__, __LINE__, secTime, usecTime);  \
    } while (0)
#else
#define TIME_ELAPSED(codeToTime) \
    do {                         \
        {                        \
            codeToTime;          \
        }                        \
    } while (0)
#endif

#endif

#endif /* _UTILS_LOG_H_ */
