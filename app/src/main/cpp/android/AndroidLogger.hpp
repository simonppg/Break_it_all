#ifndef _ANDROID_LOGGER_H_
#define _ANDROID_LOGGER_H_

#include <string>
#include "../shared/Logger.hpp"

class AndroidLogger : public Logger { 
public:
    void sayHello();
    void logi(const char* fortmat, ...);
    void logi(std::string aString);
};

#endif //_ANDROID_LOGGER_H_
