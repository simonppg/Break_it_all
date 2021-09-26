#include "LinuxPlatform.hpp"

#include "LinuxLogger.hpp"
#include "LinuxFilesManager.hpp"

#include "../shared/Platform.hpp"
#include "../shared/Logger.hpp"
#include "../shared/FilesManager.hpp"

LinuxPlatform::LinuxPlatform () {
    aLogger = new LinuxLogger();
    aFilesManager = new LinuxFilesManager();
}

LinuxPlatform::~LinuxPlatform () {
    delete aLogger;
    delete aFilesManager;
}

Logger* LinuxPlatform::logger() { return aLogger; }
FilesManager* LinuxPlatform::filesManager() { return aFilesManager; }

