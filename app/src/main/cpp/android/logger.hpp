//
// Created by simonppg on 23/06/18.
//

#ifdef __cplusplus
extern "C" {
#endif
#include <android/log.h>
#define LOG_TAG "libNative"

#ifndef BREAK_IT_ALL_LOGGER_H
#define BREAK_IT_ALL_LOGGER_H

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__);
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__);

#endif //BREAK_IT_ALL_LOGGER_H

#ifdef __cplusplus
}
#endif