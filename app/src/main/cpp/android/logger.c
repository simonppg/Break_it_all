//
// Created by simonppg on 23/06/18.
//

#include <android/log.h>

#include "logger.h"

#define LOG_TAG "libNative"

void logi(const char* fmt, ...)
{
    __android_log_print(ANDROID_LOG_WARN, LOG_TAG, "%s", fmt);
}

void loge(const char* fmt, ...)
{
    __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "%s", fmt);
}
