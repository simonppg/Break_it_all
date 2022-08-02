#ifndef APP_SRC_MAIN_CPP_SHARED_STRINGS_STRINGFORMATTER_HPP_
#define APP_SRC_MAIN_CPP_SHARED_STRINGS_STRINGFORMATTER_HPP_

#include <string>

using std::string;

class StringFormatter {
public:
  string format(const char *format, va_list args);
};

#endif // APP_SRC_MAIN_CPP_SHARED_STRINGS_STRINGFORMATTER_HPP_
