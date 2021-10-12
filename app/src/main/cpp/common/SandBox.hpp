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

class SandBox : public IScene {
private:
  Math *math = new Math();

public:
  explicit SandBox(FilesManager *filesManager);

  void surfaceCreated() override;
  void surfaceChanged(int width, int height) override;
  void render() override;
  void pause() override;
  void resume() override;
  void update() override;
  bool events(double xpos, double ypos) override;

  Mesh *meshes[1];
  Object *objects[40];
  ShaderProg *shaderProgs[1];
  Renderer *renderer;
};

#endif // APP_SRC_MAIN_CPP_COMMON_SANDBOX_HPP_
