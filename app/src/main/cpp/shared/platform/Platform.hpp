#ifndef APP_SRC_MAIN_CPP_SHARED_PLATFORM_HPP_
#define APP_SRC_MAIN_CPP_SHARED_PLATFORM_HPP_

#include "../events/EventBus.hpp"
#include "FilesManager.hpp"
#include "Logger.hpp"

class Platform {
private:
  EventBus aBus;

public:
  virtual ~Platform() {}

  virtual Logger *logger() = 0;
  virtual FilesManager *filesManager() = 0;
  EventBus *bus();
};

#endif // APP_SRC_MAIN_CPP_SHARED_PLATFORM_HPP_
