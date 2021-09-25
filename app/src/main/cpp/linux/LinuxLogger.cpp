#include <cstdarg>
#include <iostream>
#include <sstream>

#include "LinuxLogger.hpp"

using std::cout;
using std::endl;
using std::string;

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
  int ival;
  double dval;

  cout << LOG_TAG << ": ";

  for (p = format; *p; p++) {

    if (*p != '%') {
      putchar(*p);
      continue;
    }

    switch (*++p) {
    case 'd':
      ival = va_arg(args, int);
      cout << ival;
      break;
    case 'f':
      dval = va_arg(args, double);
      cout << dval;
      break;
    case 's':
      for (sval = va_arg(args, char *); *sval; sval++) {
        putchar(*sval);
      }
      break;
    default:
      putchar(*p);
      break;
    }

    ++format;
  }

  cout << endl;

  va_end(args);
}

void LinuxLogger::logi(string aString) {
  cout << LOG_TAG << ": " << aString << endl;
}
