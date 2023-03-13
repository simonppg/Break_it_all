#include "App.hpp"

#include <cstdlib>
#include <map>

#include "../common/Game.hpp"
#include "../common/GameLoop.hpp"
#include "../shared/platform/FilesManager.hpp"
#include "../shared/platform/Logger.hpp"
#include "../shared/platform/Platform.hpp"
#include "GLFWKeyMapper.hpp"
#include "LinuxPlatform.hpp"
#include "windowmanager/WindowManager.hpp"

App::App() {
  windowManager = new WindowManager(this);
  platform = new LinuxPlatform();
  logger = platform->logger();
  keyMapper = new GLFWKeyMapper();
}

App::~App() {
  delete game;
  game = nullptr;
  delete keyMapper;
  keyMapper = nullptr;
  delete platform;
  platform = nullptr;
  delete windowManager;
  windowManager = nullptr;
}

void App::cursorCallback(void *appContext, double x, double y) {
  App *app = reinterpret_cast<App *>(appContext);
  auto event = new CursorPositionChanged(x, y);
  app->publish(event);
  delete event;
}

void App::windowSizeCallback(void *appContext, int width, int height) {
  App *app = reinterpret_cast<App *>(appContext);
  auto event = new SurfaceChanged(width, height);
  app->publish(event);
  delete event;
}

void App::keyCallback(void *appContext, int key, int scancode, int action,
                      int mods) {
  App *app = reinterpret_cast<App *>(appContext);
  GLFWKeyMapper *keyMapper = app->keyMapper;

  Key myKey = keyMapper->mapKey(key);
  PressState pressState = keyMapper->mapPressState(action);

  auto event = new KeyPressed(myKey, pressState);
  app->publish(event);
  delete event;
}

void App::publish(Event *event) { game->dispatchEvent(event); }

bool App::isRunning() {
  auto shouldClose = windowManager->shouldClose();
  if (shouldClose) {
    game->close();
  }

  return !shouldClose && game->isPlaying();
}

void App::beforeLoop() {
  const int WINDOW_WIDTH = 450;
  const int WINDOW_HEIGHT = 800;

  try {
    windowManager->createWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
  } catch (const WindowCanNotBeCreated &ex) {
    logger->logi("%s", ex.what());
    exit(EXIT_FAILURE);
  }

  windowManager->setCursorCallback(cursorCallback);
  windowManager->setWindowSizeCallback(windowSizeCallback);
  windowManager->setKeyCallback(keyCallback);

  game->surfaceCreated();
}

void App::beforeIteration() { windowManager->pollEvents(); }

void App::afterIteration() { windowManager->refreshWindow(); }

void App::afterLoop() { windowManager->destroyWindow(); }

void App::update(double dt) { game->update(dt); }

void App::draw() { game->render(); }

void App::start(int sceneNumber) {
  logger->logi("%d", sceneNumber);

  game = new Game(sceneNumber, platform);

  GameLoop(logger, this).loop();
}
