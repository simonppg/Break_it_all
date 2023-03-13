#include <sstream>

#include "../shared/platform/FilesManager.hpp"
#include "../shared/platform/Logger.hpp"
#include "../shared/platform/Platform.hpp"
#include "Dimension.hpp"
#include "Game.hpp"
#include "Key.hpp"
#include "Point3D.hpp"
#include "../shared/events/CursorPositionChanged.hpp"
#include "../shared/events/KeyPressed.hpp"
#include "../shared/events/ScreenTouched.hpp"
#include "../shared/events/SurfaceChanged.hpp"

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
  // delete camera;
  // camera = nullptr;
}

void Game::camera_forward() {
  // Point3D cameraPosition = camera->getPosition();
  // camera->travel(cameraPosition.decrementZ(1));
}

void Game::camera_back() {
  // Point3D cameraPosition = camera->getPosition();
  // camera->travel(cameraPosition.incrementZ(1));
}

void Game::camera_left() {
  // Point3D cameraPosition = camera->getPosition();
  // camera->travel(cameraPosition.decrementX(1));
}

void Game::camera_right() {
  // Point3D cameraPosition = camera->getPosition();
  // camera->travel(cameraPosition.incrementX(1));
}

void Game::cursorPositionChangedHandler(CursorPositionChanged *event) {
  // pScene->events(Point2D(event->getXPosition(), event->getYPosition()));
}

void Game::screenTouchedHandler(ScreenTouched *event) {
  pScene->events(Point2D(event->getXPosition(), event->getYPosition()));
}

void Game::keyPressedHandler(KeyPressed *event) {
  Key key = event->key();
  PressState pressState = event->pressState();

  if (pressState == PressState::KEY_PRESSED ||
      pressState == PressState::KEY_HOLDED) {
    if (key == Key::W_KEY) {
      camera_forward();
    } else if (key == Key::S_KEY) {
      camera_back();
    } else if (key == Key::D_KEY) {
      camera_right();
    } else if (key == Key::A_KEY) {
      camera_left();
    } else if (key == Key::L_KEY) {
      camera_reset();
    } else if (key == Key::ESCAPE_KEY) {
      // TODO(simon): Should we save state before exit?
      close();
      // exit(0);
    }
  }
}

void Game::camera_reset() {
  // camera->travel(Point3D());
}

void Game::surfaceCreated() {
  // LOGE("OpenGL version: %s", glGetString(GL_VERSION));
  // LOGE("GLSL version: %s", glGetString(GL_SHADING_LANGUAGE_VERSION));
  pScene->surfaceCreated();
}

void Game::surfaceChangedHandler(SurfaceChanged *event) {
  Dimension dimension = Dimension(event->width(), event->height());
  std::stringstream sstream;
  sstream << dimension;
  logger->logi(sstream.str());

  pScene->surfaceChanged(dimension);
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
  EventType eventType = event->type();

  if (eventType == EventType::SURFACE_CHANGED) {
    logger->logi("SURFACE_CHANGED");

    auto realEvent = reinterpret_cast<SurfaceChanged *>(event);
    surfaceChangedHandler(realEvent);
    // return;
  }

  if (eventType == EventType::CURSOR_POSITION_CHANGED) {
    logger->logi("CURSOR_POSITION_CHANGED");

    auto realEvent = reinterpret_cast<CursorPositionChanged *>(event);
    cursorPositionChangedHandler(realEvent);
    // return;
  }

  if (eventType == EventType::KEY_PRESSED) {
    logger->logi("KEY_PRESSED");

    keyPressedHandler(reinterpret_cast<KeyPressed *>(event));
    // return;
  }

  if (eventType == EventType::SCREEN_TOUCHED) {
    logger->logi("SCREEN_TOUCHED");

    screenTouchedHandler(reinterpret_cast<ScreenTouched *>(event));
    // return;
  }

  logger->logi("Event type: %d, was not handled", event->type());

  bus->publish(event);
}
