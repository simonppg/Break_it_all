// Copyright (c) 2021 Simon Puente
#ifndef APP_SRC_MAIN_CPP_LINUX_LINUXFILESMANAGER_HPP_
#define APP_SRC_MAIN_CPP_LINUX_LINUXFILESMANAGER_HPP_
#include "../shared/FilesManager.hpp"

class LinuxFilesManager final : public FilesManager {
private:
  const string projectPath;

public:
  explicit LinuxFilesManager(const string projectPath);

  const string loadFile(const string filePath);
};

#endif // APP_SRC_MAIN_CPP_LINUX_LINUXFILESMANAGER_HPP_
