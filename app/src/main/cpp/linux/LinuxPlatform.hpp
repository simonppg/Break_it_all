#ifndef LINUX_PLATFORM_HPP
#define LINUX_PLATFORM_HPP

#include "LinuxFilesManager.hpp"
#include "LinuxLogger.hpp"

#include "../shared/FilesManager.hpp"
#include "../shared/Logger.hpp"
#include "../shared/Platform.hpp"

class LinuxPlatform : public Platform {
private:
  LinuxLogger *aLogger;
  LinuxFilesManager *aFilesManager;

public:
  LinuxPlatform();
  ~LinuxPlatform();

  Logger *logger();
  FilesManager *filesManager();
};

#endif // LINUX_PLATFORM_HPP
