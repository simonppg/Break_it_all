#ifndef _LINUX_LOGGER_H_
#define _LINUX_LOGGER_H_

#include "../shared/Logger.hpp"

class LinuxLogger : public Logger { 
public:
    void sayHello();
    void logi(const char* fortmat, ...);
    void logi(std::string aString);
};

#endif //_LINUX_LOGGER_H_
