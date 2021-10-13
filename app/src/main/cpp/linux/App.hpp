#ifndef APP_HPP
#define APP_HPP

#include "../common/EventFactory.hpp"
#include "../common/Game.hpp"
#include "../shared/FilesManager.hpp"
#include "../shared/Logger.hpp"
#include "../shared/Platform.hpp"
#include "GLFWKeyMapper.hpp"
#include "WindowManager.hpp"

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

public:
  App();

  void start(int sceneNumber);
};

#endif // APP_HPP
