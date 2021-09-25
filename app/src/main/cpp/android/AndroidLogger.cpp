#include <cstdarg>
#include <sstream>

#include "AndroidLogger.hpp"
#include <iostream>
#include <android/log.h>

using std::string;
using std::stringstream;

void AndroidLogger::sayHello() {
    __android_log_print(ANDROID_LOG_INFO, LOG_TAG.c_str(), "AndroidLogger: Hello");
}

void AndroidLogger::logi(const char* format, ...) {
    va_list args;

    va_start(args, format);
    while (*format != '\0') {
      if (*format == 'd') {
        int i = va_arg(args, int);
        __android_log_print(ANDROID_LOG_INFO, LOG_TAG.c_str(), "%d", i);
      } else if (*format == 'c') {
        // note automatic conversion to integral type
        int c = va_arg(args, int);
        __android_log_print(ANDROID_LOG_INFO, LOG_TAG.c_str(), "%c", static_cast<char>(c));
      } else if (*format == 'f') {
        double d = va_arg(args, double);
        // std::cout << d << '\n';
        __android_log_print(ANDROID_LOG_INFO, LOG_TAG.c_str(), "%lf", d);
      } else if(*format == 's') {
        const char * str = va_arg(args, const char *);
        __android_log_print(ANDROID_LOG_INFO, LOG_TAG.c_str(), "%s", str);
      }

      ++format;
    }

    va_end(args);
}

void AndroidLogger::logi(string aString) {
    stringstream sstream;
    sstream << aString;
    __android_log_print(ANDROID_LOG_INFO, LOG_TAG.c_str(), "%s", sstream.str().c_str());
}
