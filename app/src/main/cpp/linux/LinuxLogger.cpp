// Copyright (c) 2021 Simon Puente
#include <cstdarg>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>

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
  time_t now;
  time(&now);
  char *ctime_no_newline;
  time_t tm = time(NULL);

  ctime_no_newline = strtok(ctime(&tm), "\n");

  cout << CONSOLE_GREEN_COLOR;
  cout << ctime_no_newline << CONSOLE_DEFAULT_COLOR;
  cout << " " << LOG_TAG << ": " << aString;
  cout << CONSOLE_DEFAULT_COLOR << endl;
}
