#ifndef APP_SRC_MAIN_CPP_GAME_TEST4_HPP_
#define APP_SRC_MAIN_CPP_GAME_TEST4_HPP_

#include <vector>

#include "../eventbus/CursorPositionChanged.hpp"
#include "../glwrapper/Gl.hpp"
#include "../platform/FilesManager.hpp"
#include "Ball.hpp"
#include "Math.hpp"
#include "MeshFactory.hpp"
#include "Object.hpp"
#include "Object3D.hpp"
#include "Renderer.hpp"
#include "Scene.hpp"
#include "ShaderProg.hpp"

static const int ROW = 15;
static const int COL = 9;

class Test4 final : public Scene {
private:
  Gl gl;
  MeshFactory meshFactory;
  Math math;
  Mesh *meshes[2];
  ShaderProg *shaderProgs[2];
  Object *objects[ROW * COL];
  Ball *redBall;
  Ball *greenBall;
  Object *ball;
  Object *ball2;
  Object *paddle;
  Renderer *renderer;
  int NUMBER_OF_VERTICES = 15;
  float radius = 1.0;

  int xDirection = 1;
  float povInDegrees = 0.0f;
  float top, bottom, right, left;

  void movePaddle(CursorPositionChanged);

public:
  explicit Test4(Platform *);
  ~Test4();

  void surfaceCreated() override;
  void surfaceChanged() override;
  void pause() override;
  void resume() override;
  void update(double) override;
};

#endif // APP_SRC_MAIN_CPP_GAME_TEST4_HPP_
