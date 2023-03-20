#ifndef APP_SRC_MAIN_CPP_PLATFORM_LOGGER_HPP_
#define APP_SRC_MAIN_CPP_PLATFORM_LOGGER_HPP_

#include <string>

using std::string;

class Logger {
protected:
  const string LOG_TAG = "libNative";

public:
  virtual ~Logger() = default;

  virtual void sayHello() = 0;
  virtual void logi(char aChar) = 0;
  virtual void logi(const char *fortmat, ...) = 0;
  virtual void logi(string aString) = 0;
};

#endif // APP_SRC_MAIN_CPP_PLATFORM_LOGGER_HPP_
