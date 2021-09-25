#ifndef _LINUX_LOGGER_H_
#define _LINUX_LOGGER_H_

#include "../shared/Logger.hpp"

using std::string;

class LinuxLogger : public Logger { 
public:
    void sayHello();
    void logi(const char* fortmat, ...);
    void logi(string aString);
};

#endif //_LINUX_LOGGER_H_
