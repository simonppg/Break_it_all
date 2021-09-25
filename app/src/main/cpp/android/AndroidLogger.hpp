#ifndef _ANDROID_LOGGER_H_
#define _ANDROID_LOGGER_H_

#include <string>
#include "../shared/Logger.hpp"

#include "../shared/strings/StringFormatter.hpp"

using std::string;

class AndroidLogger : public Logger { 
private:
    StringFormatter formatter;

public:
    void sayHello();
    void logi(char aChar);
    void logi(const char* fortmat, ...);
    void logi(string aString);
};

#endif //_ANDROID_LOGGER_H_
