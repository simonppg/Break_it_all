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
  char cval;
  int ival;
  double dval;
  stringstream sstream;

  for (p = format; *p; p++) {

    if (*p != '%') {
      sstream << *p;
      continue;
    }

    switch (*++p) {
    case 'c':
      cval = (char) va_arg(args, int);
      sstream << cval;
      break;
    case 'd':
      ival = va_arg(args, int);
      sstream << ival;
      break;
    case 'f':
      dval = va_arg(args, double);
      sstream << dval;
      break;
    case 's':
      for (sval = va_arg(args, char *); *sval; sval++) {
      sstream << *sval;
      }
      break;
    default:
      sstream << *p;
      break;
    }

    ++format;
  }

  logi(sstream.str());

  va_end(args);
}

void AndroidLogger::logi(string aString) {
    stringstream sstream;
    sstream << aString;
    __android_log_print(ANDROID_LOG_INFO, LOG_TAG.c_str(), "%s", sstream.str().c_str());
}
