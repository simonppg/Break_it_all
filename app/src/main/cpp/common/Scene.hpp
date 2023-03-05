// Copyright (c) 2022 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_SCENE_HPP_
#define APP_SRC_MAIN_CPP_COMMON_SCENE_HPP_

#include "Dimension.hpp"
#include "Point2D.hpp"

class Scene {
protected:
  unsigned int programID;

public:
  virtual ~Scene() {}

  virtual void surfaceCreated() = 0;
  virtual void render() = 0;
  virtual void surfaceChanged(Dimension) = 0;
  virtual void pause() = 0;
  virtual void resume() = 0;
  virtual void update(double) = 0;
  virtual bool events(Point2D) = 0;
};

#endif // APP_SRC_MAIN_CPP_COMMON_SCENE_HPP_
