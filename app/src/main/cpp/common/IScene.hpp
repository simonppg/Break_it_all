// Copyright (c) 2022 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_ISCENE_HPP_
#define APP_SRC_MAIN_CPP_COMMON_ISCENE_HPP_

#include <GLES3/gl3.h>

#include "Camera.hpp"
#include "Point2D.hpp"

class IScene {
protected:
  unsigned int programID;

public:
  virtual ~IScene(){};

  virtual void surfaceCreated() = 0;
  virtual void render() = 0;
  virtual void surfaceChanged(Dimension) = 0;
  virtual void pause() = 0;
  virtual void resume() = 0;
  virtual void update(double) = 0;
  virtual bool events(Point2D) = 0;

  Camera *camera = nullptr;
};

#endif // APP_SRC_MAIN_CPP_COMMON_ISCENE_HPP_
