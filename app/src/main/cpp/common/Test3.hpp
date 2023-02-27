// Copyright (c) 2021 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_TEST3_HPP_
#define APP_SRC_MAIN_CPP_COMMON_TEST3_HPP_

#include "../shared/FilesManager.hpp"

#include "IScene.hpp"
#include "Math.hpp"
#include "Renderer.hpp"
#include "opengl/Gl.hpp"

class Test3 final : public IScene {
private:
  Gl *gl;
  Renderer renderer = Renderer(new Camera(Dimension(), Point3D(0, 0, 40)));
  FilesManager *filesManager;
  Math *math = new Math();
  float *circle;
  int NUMBER_OF_VERTICES = 160;

public:
  explicit Test3(FilesManager *);
  ~Test3();

  void surfaceCreated() override;
  void surfaceChanged(Dimension) override;
  void render() override;
  void pause() override;
  void resume() override;
  void update(double) override;
  bool events(Point2D) override;
};

#endif // APP_SRC_MAIN_CPP_COMMON_TEST3_HPP_
