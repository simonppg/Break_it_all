#include <cstdarg>
#include <sstream>
#include <string>

#include "StringFormatter.hpp"

using std::string;
using std::stringstream;

string StringFormatter::format(const char *format, va_list args) {
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
      cval = (char)va_arg(args, int);
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

  return sstream.str();
}
