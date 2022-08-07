// Copyright (c) 2021 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_TEST4_HPP_
#define APP_SRC_MAIN_CPP_COMMON_TEST4_HPP_

#include <vector>

#include "../shared/FilesManager.hpp"
#include "IScene.hpp"
#include "Math.hpp"
#include "Object.hpp"
#include "Renderer.hpp"
#include "ShaderProg.hpp"

#define ROW 15
#define COL 9

const float CAMERA_WIDTH = 450.0f;
const float CAMERA_HEIGHT = 800.0f;
static float ball_size = CAMERA_WIDTH / 30;
static Point3D ballSize(ball_size, ball_size, 1);

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

  float h = CAMERA_HEIGHT / 2;

  float cube_x_size = (CAMERA_WIDTH / 2) / 3;
  float cube_y_size = cube_x_size / 7;

  int xDirection = 1;
  float x_size = 90.0f * (CAMERA_WIDTH / COL) / 100;
  float povInDegrees = 0.0f;
  float y_size = 80.0f * (h / ROW) / 100;

public:
  explicit Test4(FilesManager *filesManager);
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
