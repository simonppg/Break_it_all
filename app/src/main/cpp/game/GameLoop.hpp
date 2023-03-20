#ifndef APP_SRC_MAIN_CPP_GAME_GAMELOOP_HPP_
#define APP_SRC_MAIN_CPP_GAME_GAMELOOP_HPP_

#include "../platform/Logger.hpp"
#include "Iterable.hpp"

class GameLoop {
private:
  Logger *logger;
  Iterable *iterable;

public:
  void loop();
  GameLoop(Logger *, Iterable *);
};

#endif // APP_SRC_MAIN_CPP_GAME_GAMELOOP_HPP_
