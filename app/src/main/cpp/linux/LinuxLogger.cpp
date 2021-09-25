#include <cstdarg>
#include <iostream>
#include <sstream>

#include "LinuxLogger.hpp"
#include "../shared/strings/StringFormatter.hpp"

using std::cout;
using std::endl;
using std::string;
using std::stringstream;

void LinuxLogger::sayHello() {
  cout << endl << "LinuxLogger: Hello" << endl << endl;
}

void LinuxLogger::logi(char aChar) {
  cout << LOG_TAG << ": " << aChar << endl;
}

void LinuxLogger::logi(const char *format, ...) {
  va_list args;
  va_start(args, format);

  logi(formatter.format(format, args));

  va_end(args);
}

void LinuxLogger::logi(string aString) {
  cout << LOG_TAG << ": " << aString << endl;
}
