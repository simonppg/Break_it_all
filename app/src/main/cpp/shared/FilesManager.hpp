// Copyright (c) 2022 Simon Puente
#ifndef FILES_MANAGER_HPP
#define FILES_MANAGER_HPP

class FilesManager {
public:
  virtual ~FilesManager() = default;

  virtual char *loadFile(const char *filePath) = 0;
};

#endif // FILES_MANAGER_HPP
