// Copyright (c) 2021 Simon Puente
#ifndef APP_SRC_MAIN_CPP_LINUX_LINUXLOGGER_HPP_
#define APP_SRC_MAIN_CPP_LINUX_LINUXLOGGER_HPP_

#include <string>

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

#endif // APP_SRC_MAIN_CPP_LINUX_LINUXLOGGER_HPP_
