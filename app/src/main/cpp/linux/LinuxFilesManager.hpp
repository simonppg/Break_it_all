// Copyright (c) 2021 Simon Puente
#ifndef APP_SRC_MAIN_CPP_LINUX_LINUXFILESMANAGER_HPP_
#define APP_SRC_MAIN_CPP_LINUX_LINUXFILESMANAGER_HPP_
#include "../shared/FilesManager.hpp"

class LinuxFilesManager : public FilesManager {
 private:
  const char *projectPath;

 public:
  explicit LinuxFilesManager(const char *projectPath);

  char* loadFile(const char *filePath);
};

#endif  // APP_SRC_MAIN_CPP_LINUX_LINUXFILESMANAGER_HPP_
