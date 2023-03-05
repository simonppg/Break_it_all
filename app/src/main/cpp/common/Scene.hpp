// Copyright (c) 2022 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_SCENE_HPP_
#define APP_SRC_MAIN_CPP_COMMON_SCENE_HPP_

#include "Dimension.hpp"
#include "DrawableObject.hpp"
#include "Gl.hpp"
#include "Object.hpp"
#include "Object3D.hpp"
#include "Point2D.hpp"

#include <vector>

class Scene {
private:
  Gl gl;
  vector<DrawableObject *> drawableObjects;

protected:
  unsigned int programID;

public:
  virtual ~Scene() {}

  virtual void surfaceCreated() = 0;
  void render();
  virtual void surfaceChanged(Dimension) = 0;
  virtual void pause() = 0;
  virtual void resume() = 0;
  virtual void update(double) = 0;
  virtual bool events(Point2D) = 0;
  void enterScene(DrawableObject *);
};

#endif // APP_SRC_MAIN_CPP_COMMON_SCENE_HPP_
