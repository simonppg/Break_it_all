// Copyright (c) 2021 Simon Puente
#include "App.hpp"

#include <cstdlib>
#include <ctime>
#include <chrono>
#include <map>

#include "../common/EventFactory.hpp"
#include "../common/Game.hpp"
#include "../shared/FilesManager.hpp"
#include "../shared/Logger.hpp"
#include "../shared/Platform.hpp"
#include "GLFWKeyMapper.hpp"
#include "LinuxPlatform.hpp"
#include "windowmanager/WindowManager.hpp"

using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::duration;
using std::chrono::system_clock;
using std::chrono::high_resolution_clock;
using std::milli;

App::App() {
  windowManager = new WindowManager(this);
  platform = new LinuxPlatform();
  filesManager = platform->filesManager();
  logger = platform->logger();
  eventFactory = new EventFactory();
  keyMapper = new GLFWKeyMapper();
}

void App::cursorCallback(void *appContext, double x, double y) {
  App *app = reinterpret_cast<App *>(appContext);
  app->publish(new CursorPositionChanged(x, y));
}

void App::windowSizeCallback(void *appContext, int width, int height) {
  App *app = reinterpret_cast<App *>(appContext);
  app->publish(new SurfaceChanged(width, height));
}

void App::keyCallback(void *appContext, int key, int scancode, int action,
                      int mods) {
  App *app = reinterpret_cast<App *>(appContext);
  EventFactory *eventFactory = app->eventFactory;
  GLFWKeyMapper *keyMapper = app->keyMapper;

  Key myKey = keyMapper->mapKey(key);
  PressState pressState = keyMapper->mapPressState(action);

  auto event = eventFactory->keyPressed(myKey, pressState);
  app->publish(event);
}

void App::publish(Event *event) { game->dispatchEvent(event); }

void App::start(int sceneNumber) {
  const int WINDOW_WIDTH = 450;
  const int WINDOW_HEIGHT = 800;

  logger->logi("%d", sceneNumber);

  try {
    windowManager->createWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
  } catch (const WindowCanNotBeCreated &ex) {
    logger->logi("%s", ex.what());
    exit(EXIT_FAILURE);
  }

  windowManager->setCursorCallback(cursorCallback);
  windowManager->setWindowSizeCallback(windowSizeCallback);
  windowManager->setKeyCallback(keyCallback);

  game = new Game(sceneNumber, platform);

  float MAX_FRAMES_PER_SECOND = 60; // FPS
  float MAX_UPDATES_PER_SECOND = 60; // UPS

  double fOPTIMAL_TIME = 1'000'000'000 / MAX_FRAMES_PER_SECOND;
  double uOPTIMAL_TIME = 1'000'000'000 / MAX_UPDATES_PER_SECOND;

  double uDeltaTime = 0, fDeltaTime = 0;
  int frames = 0, updates = 0;
  auto startTime = high_resolution_clock::now();
  auto timer = high_resolution_clock::now();

  game->surfaceCreated();

  while (!windowManager->shouldClose()) {
    auto currentTime = high_resolution_clock::now();
    auto deltaTime = (currentTime - startTime).count();
    uDeltaTime += deltaTime;
    fDeltaTime += deltaTime;

    windowManager->pollEvents();

    if(uDeltaTime >= uOPTIMAL_TIME) {
      game->update();
      updates++;
      uDeltaTime -= uOPTIMAL_TIME;
    }

    if(fDeltaTime >= fOPTIMAL_TIME) {
      game->render();
      frames++;
      fDeltaTime -= fOPTIMAL_TIME;
    }

    auto timer2 = high_resolution_clock::now();
    double elapsed_time_ms = duration<double, milli>(timer2 - timer).count();

    if (elapsed_time_ms >= 1'000) {
      logger->logi("UPS: %d, FPS: %d", updates, frames);

      updates = 0;
      frames = 0;
      elapsed_time_ms = 0;
      timer =timer2;
    }

    windowManager->refreshWindow();
  }

  windowManager->destroyWindow();
}
