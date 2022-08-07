// Copyright (c) 2021 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_GAMELOOP_HPP_
#define APP_SRC_MAIN_CPP_COMMON_GAMELOOP_HPP_

#include "../shared/Logger.hpp"
#include "Iterable.hpp"

class GameLoop {
private:
  Logger *logger;
  Iterable *iterable;

public:
  void loop();
  GameLoop(Logger *, Iterable *);
};

#endif // APP_SRC_MAIN_CPP_COMMON_GAMELOOP_HPP_
