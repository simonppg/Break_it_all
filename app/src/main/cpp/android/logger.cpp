//
// Created by simonppg on 23/06/18.
//

#ifdef __cplusplus
extern "C" {
#endif

#include <android/log.h>

#include "logger.hpp"

#define LOG_TAG "libNative"

void logi(const char* fmt, ...)
{
    __android_log_print(ANDROID_LOG_WARN, LOG_TAG, "%s", fmt);
}

void loge(const char* fmt, ...)
{
    __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "%s", fmt);
}

#ifdef __cplusplus
}
#endif