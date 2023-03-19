#ifndef APP_SRC_MAIN_CPP_COMMON_GAME_HPP_
#define APP_SRC_MAIN_CPP_COMMON_GAME_HPP_

#include "../shared/eventbus/CursorPositionChanged.hpp"
#include "../shared/eventbus/Event.hpp"
#include "../shared/eventbus/EventBus.hpp"
#include "../shared/eventbus/KeyPressed.hpp"
#include "../shared/eventbus/ScreenTouched.hpp"
#include "../shared/eventbus/SurfaceChanged.hpp"
#include "../shared/platform/Logger.hpp"
#include "../shared/platform/Platform.hpp"
#include "Scene.hpp"

class Game final {
private:
  Scene *pScene;
  Logger *logger;
  EventBus *bus;

  bool isClosing;

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
  ~Game();

  bool isPlaying();
  void close();
  // OpenGL context is in this functions
  void surfaceCreated();
  void update(double);
  void render();
  void pause();
  void resume();
  void camera_reset();
  void dispatchEvent(Event *event);
};

#endif // APP_SRC_MAIN_CPP_COMMON_GAME_HPP_
