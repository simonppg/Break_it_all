#include "AndroidLogger.hpp"
#include <iostream>
#include <android/log.h>

#define LOG_TAG "libNative"

using namespace std;

void AndroidLogger::sayHello() {
    __android_log_print(ANDROID_LOG_INFO, LOG_TAG, "AndroidLogger: Hello");
}
