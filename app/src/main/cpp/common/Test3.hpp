// Copyright (c) 2021 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_TEST3_HPP_
#define APP_SRC_MAIN_CPP_COMMON_TEST3_HPP_

#include "../shared/FilesManager.hpp"

#include "IScene.hpp"
#include "Math.hpp"
#include "Renderer.hpp"

class Test3 final : public IScene {
private:
  Renderer renderer;
  FilesManager *filesManager;
  Math *math = new Math();
  float *circle;
  int NUMBER_OF_VERTICES = 160;

public:
  explicit Test3(FilesManager *filesManager);

  void surfaceCreated() override;
  void surfaceChanged(Dimension) override;
  void render() override;
  void pause() override;
  void resume() override;
  void update(double) override;
  bool events(Point2D) override;
};

#endif // APP_SRC_MAIN_CPP_COMMON_TEST3_HPP_
