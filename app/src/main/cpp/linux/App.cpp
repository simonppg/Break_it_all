#include "App.hpp"
#include "../common/EventFactory.hpp"
#include "../common/Game.hpp"
#include "../shared/FilesManager.hpp"
#include "../shared/Logger.hpp"
#include "../shared/Platform.hpp"
#include "LinuxPlatform.hpp"
#include "WindowManager.hpp"
#include "GLFWKeyMapper.hpp"

#include <cstdlib>
#include <map>

using std::map;

App::App() {
  windowManager = new WindowManager(this);
  platform = new LinuxPlatform();
  filesManager = platform->filesManager();
  logger = platform->logger();
  eventFactory = new EventFactory();
  keyMapper = new GLFWKeyMapper();
}

void App::cursorCallback(void *appContext, double x, double y) {
  App *app = (App *)appContext;
  EventFactory *eventFactory = app->eventFactory;
  Game *game = app->game;

  auto event = eventFactory->cursorPositionChanged(x, y);
  game->dispatchEvent(event);
}

void App::windowSizeCallback(void *appContext, int width, int height) {
  App *app = (App *)appContext;
  Game *game = app->game;

  game->surfaceChanged(width, height);
}

void App::keyCallback(void *appContext, int key, int scancode, int action, int mods) {
  App *app = (App *)appContext;
  EventFactory *eventFactory = app->eventFactory;
  Game *game = app->game;
  GLFWKeyMapper *keyMapper = app->keyMapper;

  Key myKey = keyMapper->mapKey(key);
  PressState pressState = keyMapper->mapPressState(action);

  auto event = eventFactory->keyPressed(myKey, pressState);
  game->dispatchEvent(event);
}

void App::start(int sceneNumber) {
  const int WINDOW_WIDTH = 450;
  const int WINDOW_HEIGHT = 800;

  logger->logi("%d", sceneNumber);

  if (windowManager->createWindow(WINDOW_WIDTH, WINDOW_HEIGHT) != 0) {
    logger->logi("Window can not be created");
    exit(EXIT_FAILURE);
  }

  windowManager->setCursorCallback(cursorCallback);
  windowManager->setWindowSizeCallback(windowSizeCallback);
  windowManager->setKeyCallback(keyCallback);

  game = new Game(sceneNumber, platform);

  game->surfaceCreated();

  while (!windowManager->shouldClose()) {
    windowManager->pollEvents();

    game->update();
    game->render();

    windowManager->refreshWindow();
  }

  windowManager->destroyWindow();
}
