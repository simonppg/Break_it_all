#ifndef PLATFORM_H
#define PLATFORM_H

#include "Logger.hpp"
#include "FilesManager.hpp"

class Platform {
public:
    virtual Logger* logger() = 0;
    virtual FilesManager* filesManager() = 0;
};

#endif // PLATFORM_H
