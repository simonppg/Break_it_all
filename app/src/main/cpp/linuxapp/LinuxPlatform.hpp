
#ifndef APP_SRC_MAIN_CPP_LINUXAPP_LINUXPLATFORM_HPP_
#define APP_SRC_MAIN_CPP_LINUXAPP_LINUXPLATFORM_HPP_

#include "LinuxFilesManager.hpp"
#include "LinuxLogger.hpp"

#include "../platform/FilesManager.hpp"
#include "../platform/Logger.hpp"
#include "../platform/Platform.hpp"
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

#endif // APP_SRC_MAIN_CPP_LINUXAPP_LINUXPLATFORM_HPP_
