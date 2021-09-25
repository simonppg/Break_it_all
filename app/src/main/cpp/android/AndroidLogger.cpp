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

void AndroidLogger::logi(char aChar) {
  __android_log_print(ANDROID_LOG_INFO, LOG_TAG.c_str(), "%c", aChar);
}

void AndroidLogger::logi(const char *format, ...) {
  va_list args;

  va_start(args, format);

  const char *p;
  char *sval;
  int ival;
  double dval;
  string buffer;

  for (p = format; *p; p++) {

    if (*p != '%') {
      buffer.push_back(*p);
      continue;
    }

    switch (*++p) {
    case 'd':
      logi(buffer);
      buffer.clear();

      ival = va_arg(args, int);
      __android_log_print(ANDROID_LOG_INFO, LOG_TAG.c_str(), "%d", ival);
      break;
    case 'f':
      logi(buffer);
      buffer.clear();

      dval = va_arg(args, double);
      __android_log_print(ANDROID_LOG_INFO, LOG_TAG.c_str(), "%f", dval);
      break;
    case 's':
      for (sval = va_arg(args, char *); *sval; sval++) {
        buffer.push_back(*sval);
      }
      break;
    default:
      buffer.push_back(*p);
      break;
    }

    ++format;
  }

  logi(buffer);

  va_end(args);
}

void AndroidLogger::logi(string aString) {
    stringstream sstream;
    sstream << aString;
    __android_log_print(ANDROID_LOG_INFO, LOG_TAG.c_str(), "%s", sstream.str().c_str());
}
