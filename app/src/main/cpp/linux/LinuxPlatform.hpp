// Copyright (c) 2021 Simon Puente

#ifndef APP_SRC_MAIN_CPP_LINUX_LINUXPLATFORM_HPP_
#define APP_SRC_MAIN_CPP_LINUX_LINUXPLATFORM_HPP_

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

#endif  // APP_SRC_MAIN_CPP_LINUX_LINUXPLATFORM_HPP_
