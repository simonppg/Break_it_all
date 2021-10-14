// Copyright (c) 2021 Simon Puente
#include <cstdarg>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <cstdarg>

#include "../shared/strings/StringFormatter.hpp"
#include "LinuxLogger.hpp"

using std::cout;
using std::endl;
using std::string;
using std::stringstream;

void LinuxLogger::sayHello() {
  cout << endl << "LinuxLogger: Hello" << endl << endl;
}

void LinuxLogger::logi(char aChar) { cout << LOG_TAG << ": " << aChar << endl; }
void LinuxLogger::logi(const char *format, ...) {
  va_list args;
  va_start(args, format);

  logi(formatter.format(format, args));

  va_end(args);
}

void LinuxLogger::logi(string aString) {
  auto nows = std::chrono::system_clock::now();
  auto in_time_t = std::chrono::system_clock::to_time_t(nows);

  std::stringstream ss;
  ss << std::put_time(std::localtime(&in_time_t), "%a %b %d %X %Y");

  cout << CONSOLE_GREEN_COLOR;
  cout << ss.str() << CONSOLE_DEFAULT_COLOR;
  cout << " " << LOG_TAG << ": " << aString;
  cout << CONSOLE_DEFAULT_COLOR << endl;
  cout << CONSOLE_DEFAULT_COLOR << endl;
}
