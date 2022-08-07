// Copyright (c) 2021 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_SANDBOX_HPP_
#define APP_SRC_MAIN_CPP_COMMON_SANDBOX_HPP_

#include "Camera.hpp"
#include "IScene.hpp"
#include "Math.hpp"
#include "Mesh.hpp"
#include "Object.hpp"
#include "ShaderProg.hpp"

#include "../shared/FilesManager.hpp"

class SandBox final : public IScene {
private:
  Math *math = new Math();
  float povInDegrees = 0.0f;

public:
  explicit SandBox(FilesManager *, Camera *);
  ~SandBox();

  void surfaceCreated() override;
  void surfaceChanged(Dimension) override;
  void render() override;
  void pause() override;
  void resume() override;
  void update(double) override;
  bool events(Point2D) override;

  Mesh *mesh;
  Object *objects[40];
  ShaderProg *shaderProg;
  Renderer *renderer;
};

#endif // APP_SRC_MAIN_CPP_COMMON_SANDBOX_HPP_
