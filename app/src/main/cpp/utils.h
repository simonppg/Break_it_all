//
// Created by simonppg on 19/03/18.
//

#include <GLES2/gl2.h>

#ifndef BREAK_IT_ALL_UTILS_H
#define BREAK_IT_ALL_UTILS_H

#define LOG_TAG "libNative"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

GLuint createProgram(const char* vertexSource, const char * fragmentSource);

#endif //BREAK_IT_ALL_UTILS_H
