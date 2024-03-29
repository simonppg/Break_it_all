#ifndef APP_SRC_MAIN_CPP_LINUXAPP_LINUXFILESMANAGER_HPP_
#define APP_SRC_MAIN_CPP_LINUXAPP_LINUXFILESMANAGER_HPP_

#include <string>

#include "../platform/FilesManager.hpp"

class LinuxFilesManager final : public FilesManager {
private:
  const string projectPath;

public:
  explicit LinuxFilesManager(const string projectPath);

  const string loadFile(const string filePath);
};

#endif // APP_SRC_MAIN_CPP_LINUXAPP_LINUXFILESMANAGER_HPP_
