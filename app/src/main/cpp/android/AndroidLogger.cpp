#include "AndroidLogger.hpp"

#include <android/log.h>
#include <cstdarg>
#include <iostream>
#include <sstream>

#include "../shared/strings/StringFormatter.hpp"

using std::string;
using std::stringstream;

void AndroidLogger::sayHello() {
  __android_log_print(ANDROID_LOG_INFO, LOG_TAG.c_str(),
                      "AndroidLogger: Hello");
}

void AndroidLogger::logi(char aChar) {
  __android_log_print(ANDROID_LOG_INFO, LOG_TAG.c_str(), "%c", aChar);
}

void AndroidLogger::logi(const char *format, ...) {
  va_list args;
  va_start(args, format);

  logi(formatter.format(format, args));

  va_end(args);
}

void AndroidLogger::logi(string aString) {
  stringstream sstream;
  sstream << aString;
  __android_log_print(ANDROID_LOG_INFO, LOG_TAG.c_str(), "%s",
                      sstream.str().c_str());
}
