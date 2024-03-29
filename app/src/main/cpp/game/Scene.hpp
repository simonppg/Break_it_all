#ifndef APP_SRC_MAIN_CPP_GAME_SCENE_HPP_
#define APP_SRC_MAIN_CPP_GAME_SCENE_HPP_

#include <vector>

#include "../eventbus/EventBus.hpp"
#include "../glwrapper/Gl.hpp"
#include "../platform/Platform.hpp"
#include "Dimension.hpp"
#include "DrawableObject.hpp"
#include "Object.hpp"
#include "Object3D.hpp"
#include "Point2D.hpp"

class Scene {
private:
  Gl gl;
  vector<DrawableObject *> drawableObjects;
  Platform *platform;
  Dimension viewport;

protected:
  EventBus *bus;
  Logger *logger;
  unsigned int programID;

  float viewportWidth();
  float viewportHeight();
  Dimension viewportDimension();

public:
  explicit Scene(Platform *);
  virtual ~Scene() {}

  virtual void surfaceCreated() = 0;
  void render();
  virtual void surfaceChanged() = 0;
  virtual void pause() = 0;
  virtual void resume() = 0;
  virtual void update(double) = 0;
  // virtual bool events(Point2D) = 0;
  void enterScene(DrawableObject *);
};

#endif // APP_SRC_MAIN_CPP_GAME_SCENE_HPP_
