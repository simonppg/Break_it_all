//
// Created by simonppg on 19/03/18.
//


#ifndef BREAK_IT_ALL_UTILS_H
#define BREAK_IT_ALL_UTILS_H

#include <GLES3/gl3.h>
#include <android/log.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

#define LOG_TAG "libNative"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

GLuint createProgram(const char* vertexSource, const char * fragmentSource);
char* load_file(AAssetManager *assetManager, const char *filePath);

#endif //BREAK_IT_ALL_UTILS_H
