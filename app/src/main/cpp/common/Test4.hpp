// Copyright (c) 2021 - 2022 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_TEST4_HPP_
#define APP_SRC_MAIN_CPP_COMMON_TEST4_HPP_

#include <vector>

#include "../shared/FilesManager.hpp"
#include "IScene.hpp"
#include "Math.hpp"
#include "Object.hpp"
#include "Renderer.hpp"
#include "ShaderProg.hpp"

static const int ROW = 15;
static const int COL = 9;

class Test4 final : public IScene {
private:
  vector<float> vPos;
  Math *math = new Math();
  Mesh *meshes[2];
  ShaderProg *shaderProgs[2];
  Object *objects[ROW * COL];
  Object *ball;
  Object *paddle;
  Renderer *renderer;

  const float CAMERA_WIDTH = 450.0f;
  const float CAMERA_HEIGHT = 800.0f;
  Dimension cameraSize = Dimension(CAMERA_WIDTH, CAMERA_HEIGHT);
  int xDirection = 1;
  float povInDegrees = 0.0f;

public:
  explicit Test4(FilesManager *, Camera *);

  void surfaceCreated() override;
  void surfaceChanged(Dimension) override;
  void render() override;
  void pause() override;
  void resume() override;
  void update(double) override;
  bool events(Point2D) override;

  Object *ball2;
};

#endif // APP_SRC_MAIN_CPP_COMMON_TEST4_HPP_
