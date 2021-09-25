#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <string>

using std::string;

class Logger {
protected:
    const string LOG_TAG = "libNative";

public:
    virtual void sayHello() = 0;
    virtual void logi(char aChar) = 0;
    virtual void logi(const char* fortmat, ...) = 0;
    virtual void logi(string aString) = 0;
};

#endif //_LOGGER_H_
