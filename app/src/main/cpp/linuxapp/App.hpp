#ifndef APP_SRC_MAIN_CPP_LINUXAPP_APP_HPP_
#define APP_SRC_MAIN_CPP_LINUXAPP_APP_HPP_

#include "../eventbus/Event.hpp"
#include "../game/Game.hpp"
#include "../game/Iterable.hpp"
#include "../platform/Logger.hpp"
#include "../platform/Platform.hpp"
#include "GLFWKeyMapper.hpp"
#include "Platform.hpp"
#include "windowmanager/WindowManager.hpp"

class App final : public Iterable {
private:
  Game *game;
  WindowManager *windowManager;
  Platform *platform;
  Logger *logger;
  GLFWKeyMapper *keyMapper;

  static void cursorCallback(void *appContext, double x, double y);
  static void windowSizeCallback(void *appContext, int width, int height);
  static void keyCallback(void *appContext, int key, int scancode, int action,
                          int mods);
  void publish(Event *e);

public:
  App();
  ~App();

  void start(int sceneNumber);

  // Iterable
  void beforeLoop() override;
  void beforeIteration() override;
  void afterIteration() override;
  void afterLoop() override;
  void update(double) override;
  void draw() override;
  bool isRunning() override;
};

#endif // APP_SRC_MAIN_CPP_LINUXAPP_APP_HPP_
