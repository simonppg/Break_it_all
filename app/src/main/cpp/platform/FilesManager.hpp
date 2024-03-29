#ifndef APP_SRC_MAIN_CPP_PLATFORM_FILESMANAGER_HPP_
#define APP_SRC_MAIN_CPP_PLATFORM_FILESMANAGER_HPP_

#include <string>

using std::string;

class FilesManager {
public:
  virtual ~FilesManager() = default;

  virtual const string loadFile(const string filePath) = 0;
};

#endif // APP_SRC_MAIN_CPP_PLATFORM_FILESMANAGER_HPP_
