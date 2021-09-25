#ifndef _LINUX_LOGGER_H_
#define _LINUX_LOGGER_H_

#include "../shared/Logger.hpp"

#include "../shared/strings/StringFormatter.hpp"

using std::string;

class LinuxLogger : public Logger {
private:
  StringFormatter formatter;
  string CONSOLE_GREEN_COLOR = "\x1B[32m";
  string CONSOLE_DEFAULT_COLOR = "\x1B[0m";

public:
  void sayHello();
  void logi(char aChar);
  void logi(const char *fortmat, ...);
  void logi(string aString);
};

#endif //_LINUX_LOGGER_H_
