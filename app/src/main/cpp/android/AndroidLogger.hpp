#ifndef ANDROID_LOGGER_HPP
#define ANDROID_LOGGER_HPP

#include "../shared/Logger.hpp"
#include <string>

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

#endif // ANDROID_LOGGER_HPP
