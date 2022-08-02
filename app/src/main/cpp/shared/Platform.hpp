// Copyright (c) 2022 Simon Puente
#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#include "FilesManager.hpp"
#include "Logger.hpp"

class Platform {
public:
  virtual Logger *logger() = 0;
  virtual FilesManager *filesManager() = 0;
};

#endif // PLATFORM_HPP
