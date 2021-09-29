#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#include "Logger.hpp"
#include "FilesManager.hpp"

class Platform {
public:
    virtual Logger* logger() = 0;
    virtual FilesManager* filesManager() = 0;
};

#endif // PLATFORM_HPP
