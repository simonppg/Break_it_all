#ifndef _ANDROID_LOGGER_H_
#define _ANDROID_LOGGER_H_

#include <string>
#include "../shared/Logger.hpp"

using std::string;

class AndroidLogger : public Logger { 
public:
    void sayHello();
    void logi(char aChar);
    void logi(const char* fortmat, ...);
    void logi(string aString);
};

#endif //_ANDROID_LOGGER_H_
