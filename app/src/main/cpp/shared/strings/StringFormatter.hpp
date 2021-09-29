#ifndef STRINGS_STRING_FORMATTER_HPP
#define STRINGS_STRING_FORMATTER_HPP

#include <string>

using std::string;

class StringFormatter {
public:
  string format(const char *format, va_list args);
};

#endif // STRINGS_STRING_FORMATTER_HPP
