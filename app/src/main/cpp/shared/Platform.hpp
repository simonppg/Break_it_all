// Copyright (c) 2022 Simon Puente
#ifndef APP_SRC_MAIN_CPP_SHARED_PLATFORM_HPP_
#define APP_SRC_MAIN_CPP_SHARED_PLATFORM_HPP_

#include "FilesManager.hpp"
#include "Logger.hpp"

class Platform {
public:
  virtual Logger *logger() = 0;
  virtual FilesManager *filesManager() = 0;
};

#endif // APP_SRC_MAIN_CPP_SHARED_PLATFORM_HPP_
