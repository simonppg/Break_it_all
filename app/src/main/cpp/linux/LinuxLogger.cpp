#include <cstdarg>
#include <sstream>
#include <iostream>

#include "LinuxLogger.hpp"

using std::cout;
using std::endl;

void LinuxLogger::sayHello() {
    cout << endl << "LinuxLogger: Hello" << endl << endl;
}

void LinuxLogger::logi(const char* format, ...) {
    va_list args;

    va_start(args, format);
    while (*format != '\0') {
      if (*format == 'd') {
        int i = va_arg(args, int);
        cout << LOG_TAG << ": " << i << endl;
      } else if (*format == 'c') {
        // note automatic conversion to integral type
        int c = va_arg(args, int);
        cout << LOG_TAG << ": " << static_cast<char>(c) << endl;
      } else if (*format == 'f') {
        double d = va_arg(args, double);
        cout << LOG_TAG << ": " <<  d << endl;
      } else if(*format == 's') {
        const char * str = va_arg(args, const char *);
        cout << LOG_TAG << ": " << str << endl;
      }

      ++format;
    }

    va_end(args);
}

void LinuxLogger::logi(std::string aString) {
    cout << LOG_TAG << ": " << aString << endl;
}
