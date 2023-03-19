
#ifndef APP_SRC_MAIN_CPP_LINUX_LINUXPLATFORM_HPP_
#define APP_SRC_MAIN_CPP_LINUX_LINUXPLATFORM_HPP_

#include "LinuxFilesManager.hpp"
#include "LinuxLogger.hpp"

#include "../shared/platform/FilesManager.hpp"
#include "../shared/platform/Logger.hpp"
#include "../shared/platform/Platform.hpp"
#include "Platform.hpp"

class LinuxPlatform final : public Platform {
private:
  LinuxLogger *aLogger;
  LinuxFilesManager *aFilesManager;

public:
  LinuxPlatform();
  ~LinuxPlatform();

  Logger *logger();
  FilesManager *filesManager();
};

#endif // APP_SRC_MAIN_CPP_LINUX_LINUXPLATFORM_HPP_
