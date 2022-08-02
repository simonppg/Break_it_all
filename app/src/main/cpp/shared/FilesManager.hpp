// Copyright (c) 2022 Simon Puente
#ifndef APP_SRC_MAIN_CPP_SHARED_FILESMANAGER_HPP_
#define APP_SRC_MAIN_CPP_SHARED_FILESMANAGER_HPP_

class FilesManager {
public:
  virtual ~FilesManager() = default;

  virtual char *loadFile(const char *filePath) = 0;
};

#endif // APP_SRC_MAIN_CPP_SHARED_FILESMANAGER_HPP_
