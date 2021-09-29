#ifndef LINUX_PLATFORM_HPP
#define LINUX_PLATFORM_HPP

#include "LinuxLogger.hpp"
#include "LinuxFilesManager.hpp"

#include "../shared/Platform.hpp"
#include "../shared/Logger.hpp"
#include "../shared/FilesManager.hpp"

class LinuxPlatform : public Platform {
private:
    LinuxLogger *aLogger;
    LinuxFilesManager *aFilesManager;

public:
    LinuxPlatform();
    ~LinuxPlatform();

    Logger* logger();
    FilesManager* filesManager();
};

#endif // LINUX_PLATFORM_HPP
