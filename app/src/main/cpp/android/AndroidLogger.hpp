#ifndef APP_SRC_MAIN_CPP_ANDROID_ANDROIDLOGGER_HPP_
#define APP_SRC_MAIN_CPP_ANDROID_ANDROIDLOGGER_HPP_

#include <string>

#include "../shared/platform/Logger.hpp"
#include "../shared/strings/StringFormatter.hpp"

using std::string;

class AndroidLogger : public Logger {
private:
  StringFormatter formatter;

public:
  void sayHello();
  void logi(char aChar);
  void logi(const char *fortmat, ...);
  void logi(string aString);
};

#endif // APP_SRC_MAIN_CPP_ANDROID_ANDROIDLOGGER_HPP_
