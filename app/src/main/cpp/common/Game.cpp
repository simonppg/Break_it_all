// Copyright (c) 2021 Simon Puente
#include <sstream>

#include "../shared/FilesManager.hpp"
#include "../shared/Logger.hpp"
#include "../shared/Platform.hpp"
#include "CursorPositionChanged.hpp"
#include "Dimension.hpp"
#include "Game.hpp"
#include "Key.hpp"
#include "KeyPressed.hpp"
#include "Point3D.hpp"
#include "ScreenTouched.hpp"
#include "SurfaceChanged.hpp"

// Examples
#include "SandBox.hpp"
#include "Test1.hpp"
#include "Test2.hpp"
#include "Test3.hpp"
#include "Test4.hpp"

Game::Game(int sceneNumber, Platform *platform) {
  // NOTE: Don't call OpenGL functions here
  this->platform = platform;
  this->logger = platform->logger();
  this->fileManager = platform->filesManager();

  if (sceneNumber == 0)
    this->pScene = new SandBox(this->fileManager);
  else if (sceneNumber == 1)
    this->pScene = new Test1();
  else if (sceneNumber == 2)
    this->pScene = new Test2(this->fileManager);
  else if (sceneNumber == 3)
    this->pScene = new Test3(this->fileManager);
  else
    this->pScene = new Test4(this->fileManager);
}

Game::~Game() {
  delete pScene;
  pScene = nullptr;
}

void Game::camera_forward() {
  Point3D cameraPosition = pScene->camera->getPosition();
  pScene->camera->updatePosition(cameraPosition.decrementZ(1));
}

void Game::camera_back() {
  Point3D cameraPosition = pScene->camera->getPosition();
  pScene->camera->updatePosition(cameraPosition.incrementZ(1));
}

void Game::camera_left() {
  Point3D cameraPosition = pScene->camera->getPosition();
  pScene->camera->updatePosition(cameraPosition.decrementX(1));
}

void Game::camera_right() {
  Point3D cameraPosition = pScene->camera->getPosition();
  pScene->camera->updatePosition(cameraPosition.incrementX(1));
}

void Game::cursorPositionChangedHandler(CursorPositionChanged *event) {
  pScene->events(Point2D(event->getXPosition(), event->getYPosition()));
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
      exit(0);
    }
  }
}

void Game::camera_reset() { pScene->camera->updatePosition(Point3D()); }

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

void Game::update(double dt) { pScene->update(dt); }

void Game::render() { pScene->render(); }

void Game::pause() { pScene->pause(); }

void Game::resume() { pScene->resume(); }

void Game::dispatchEvent(Event *event) {
  EventType eventType = event->type();

  if (eventType == EventType::SURFACE_CHANGED) {
    logger->logi("SURFACE_CHANGED");

    auto realEvent = reinterpret_cast<SurfaceChanged *>(event);
    surfaceChangedHandler(realEvent);
    return;
  }

  if (eventType == EventType::CURSOR_POSITION_CHANGED) {
    logger->logi("CURSOR_POSITION_CHANGED");

    auto realEvent = reinterpret_cast<CursorPositionChanged *>(event);
    cursorPositionChangedHandler(realEvent);
    return;
  }

  if (eventType == EventType::KEY_PRESSED) {
    logger->logi("KEY_PRESSED");

    keyPressedHandler(reinterpret_cast<KeyPressed *>(event));
    return;
  }

  if (eventType == EventType::SCREEN_TOUCHED) {
    logger->logi("SCREEN_TOUCHED");

    screenTouchedHandler(reinterpret_cast<ScreenTouched *>(event));
    return;
  }

  logger->logi("Event type: %d, was not handled", event->type());
}
