// Copyright (c) 2021 Simon Puente
#ifndef APP_SRC_MAIN_CPP_LINUX_APP_HPP_
#define APP_SRC_MAIN_CPP_LINUX_APP_HPP_

#include "../common/Event.hpp"
#include "../common/EventFactory.hpp"
#include "../common/Game.hpp"
#include "../shared/FilesManager.hpp"
#include "../shared/Logger.hpp"
#include "../shared/Platform.hpp"
#include "GLFWKeyMapper.hpp"
#include "windowmanager/WindowManager.hpp"

class App {
private:
  Game *game;
  WindowManager *windowManager;
  Platform *platform;
  FilesManager *filesManager;
  Logger *logger;
  EventFactory *eventFactory;
  GLFWKeyMapper *keyMapper;

  static void cursorCallback(void *appContext, double x, double y);
  static void windowSizeCallback(void *appContext, int width, int height);
  static void keyCallback(void *appContext, int key, int scancode, int action,
                          int mods);
  void publish(Event *e);

public:
  App();

  void start(int sceneNumber);
};

#endif // APP_SRC_MAIN_CPP_LINUX_APP_HPP_
