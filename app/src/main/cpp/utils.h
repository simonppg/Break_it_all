//
// Created by simonppg on 19/03/18.
//


#ifndef BREAK_IT_ALL_UTILS_H
#define BREAK_IT_ALL_UTILS_H

#include <GLES3/gl3.h>

#ifdef __ANDROID_NDK__
#include <android/log.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

char* load_file(AAssetManager *assetManager, const char *filePath);

#endif //__ANDROID_NDK__

GLuint createProgram(const char* vertexSource, const char * fragmentSource);

#endif //BREAK_IT_ALL_UTILS_H
