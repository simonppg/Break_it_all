// Copyright (c) 2021 Simon Puente
#ifndef LINUX_LOGGER_HPP
#define LINUX_LOGGER_HPP

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

#endif // LINUX_LOGGER_HPP
