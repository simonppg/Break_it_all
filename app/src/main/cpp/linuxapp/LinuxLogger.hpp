#ifndef APP_SRC_MAIN_CPP_LINUXAPP_LINUXLOGGER_HPP_
#define APP_SRC_MAIN_CPP_LINUXAPP_LINUXLOGGER_HPP_

#include <string>

#include "../platform/Logger.hpp"

#include "../stringformatter/StringFormatter.hpp"

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

#endif // APP_SRC_MAIN_CPP_LINUXAPP_LINUXLOGGER_HPP_
