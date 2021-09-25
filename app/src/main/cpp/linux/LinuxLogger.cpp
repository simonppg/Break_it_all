#include <cstdarg>
#include <iostream>
#include <sstream>

#include "LinuxLogger.hpp"

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

  const char *p;
  char *sval;
  char cval;
  int ival;
  double dval;
  stringstream sstream;

  for (p = format; *p; p++) {

    if (*p != '%') {
      sstream << *p;
      continue;
    }

    switch (*++p) {
    case 'c':
      cval = (char) va_arg(args, int);
      sstream << cval;
      break;
    case 'd':
      ival = va_arg(args, int);
      sstream << ival;
      break;
    case 'f':
      dval = va_arg(args, double);
      sstream << dval;
      break;
    case 's':
      for (sval = va_arg(args, char *); *sval; sval++) {
      sstream << *sval;
      }
      break;
    default:
      sstream << *p;
      break;
    }

    ++format;
  }

  logi(sstream.str());

  va_end(args);
}

void LinuxLogger::logi(string aString) {
  cout << LOG_TAG << ": " << aString << endl;
}
