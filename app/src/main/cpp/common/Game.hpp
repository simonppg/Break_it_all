// Copyright (c) 2022 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_GAME_HPP_
#define APP_SRC_MAIN_CPP_COMMON_GAME_HPP_

#include "../shared/FilesManager.hpp"
#include "../shared/Logger.hpp"
#include "../shared/Platform.hpp"
#include "CursorPositionChanged.hpp"
#include "Event.hpp"
#include "IScene.hpp"
#include "KeyPressed.hpp"
#include "ScreenTouched.hpp"
#include "SurfaceChanged.hpp"

class Game {
private:
  IScene *pScene;
  Platform *platform;
  Logger *logger;
  FilesManager *fileManager;

  void camera_forward();
  void camera_back();
  void camera_left();
  void camera_right();

  void cursorPositionChangedHandler(CursorPositionChanged *event);
  void keyPressedHandler(KeyPressed *event);
  void screenTouchedHandler(ScreenTouched *event);
  void surfaceChangedHandler(SurfaceChanged *event);

public:
  Game(int sceneNumber, Platform *platform);

  // OpenGL context is in this functions
  void surfaceCreated();
  void update();
  void render();
  void pause();
  void resume();
  void camera_reset();
  void dispatchEvent(Event *event);
};

#endif // APP_SRC_MAIN_CPP_COMMON_GAME_HPP_
