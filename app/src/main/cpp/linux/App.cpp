#include "App.hpp"
#include "../common/EventFactory.hpp"
#include "../common/Game.hpp"
#include "../shared/FilesManager.hpp"
#include "../shared/Logger.hpp"
#include "../shared/Platform.hpp"
#include "LinuxPlatform.hpp"
#include "WindowManager.hpp"

#include <cstdlib>
#include <map>

using std::map;

App::App() {
  windowManager = new WindowManager(this);
  platform = new LinuxPlatform();
  filesManager = platform->filesManager();
  logger = platform->logger();
  eventFactory = new EventFactory();
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

    map<int, Key> keyMap = {{GLFW_KEY_W, Key::W_KEY},
                            {GLFW_KEY_A, Key::A_KEY},
                            {GLFW_KEY_S, Key::S_KEY},
                            {GLFW_KEY_D, Key::D_KEY},
                            {GLFW_KEY_L, Key::L_KEY}};

    map<int, PressState> pressStateMap = {
        {GLFW_PRESS, PressState::KEY_PRESSED},
        {GLFW_REPEAT, PressState::KEY_HOLDED},
        {GLFW_RELEASE, PressState::KEY_RELEASED}};

    Key myKey;
    PressState pressState;

    auto keyFound = keyMap.find(key);
    if (keyFound != keyMap.end()) {
      myKey = keyFound->second;
    } else {
      myKey = Key::UNKNOWN;
    }

    auto pressStateFound = pressStateMap.find(action);
    if (pressStateFound != pressStateMap.end()) {
      pressState = pressStateFound->second;
    } else {
      pressState = PressState::UNKNOWN;
    }

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

  game = Game::init(sceneNumber, platform);

  game->surfaceCreated();

  while (!windowManager->shouldClose()) {
    windowManager->pollEvents();

    game->update();
    game->render();

    windowManager->refreshWindow();
  }

  windowManager->destroyWindow();
}
