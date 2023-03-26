#include <sstream>

#include "../eventbus/CursorPositionChanged.hpp"
#include "../eventbus/Key.hpp"
#include "../eventbus/KeyPressed.hpp"
#include "../eventbus/ScreenTouched.hpp"
#include "../eventbus/SurfaceChanged.hpp"
#include "../platform/FilesManager.hpp"
#include "../platform/Logger.hpp"
#include "../platform/Platform.hpp"
#include "Dimension.hpp"
#include "Game.hpp"
#include "Point3D.hpp"

// Examples
#include "SandBox.hpp"
#include "Test1.hpp"
#include "Test2.hpp"
#include "Test3.hpp"
#include "Test4.hpp"

Game::Game(int sceneNumber, Platform *platform) {
  // NOTE: Don't call OpenGL functions here
  logger = platform->logger();
  FilesManager *filesManager = platform->filesManager();
  bus = platform->bus();
  isClosing = false;

  if (sceneNumber == 0) {
    pScene = new SandBox(platform, filesManager);
  } else if (sceneNumber == 1) {
    pScene = new Test1(platform);
  } else if (sceneNumber == 2) {
    pScene = new Test2(platform, filesManager);
  } else if (sceneNumber == 3) {
    pScene = new Test3(platform, filesManager);
  } else {
    pScene = new Test4(platform, filesManager);
  }
}

Game::~Game() { close(); }

bool Game::isPlaying() { return !isClosing; }

void Game::close() {
  isClosing = true;
  delete pScene;
  pScene = nullptr;
}

void Game::surfaceCreated() {
  // LOGE("OpenGL version: %s", glGetString(GL_VERSION));
  // LOGE("GLSL version: %s", glGetString(GL_SHADING_LANGUAGE_VERSION));
  pScene->surfaceCreated();
}

void Game::update(double dt) {
  if (isClosing) {
    return;
  }
  pScene->update(dt);
}

void Game::render() {
  if (isClosing) {
    return;
  }
  pScene->render();
}

void Game::pause() { pScene->pause(); }

void Game::resume() { pScene->resume(); }

void Game::dispatchEvent(Event *event) {
  if (isClosing) {
    return;
  }

  bus->publish(event);
}
