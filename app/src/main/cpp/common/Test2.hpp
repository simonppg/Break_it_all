// Copyright (c) 2021 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_TEST2_HPP_
#define APP_SRC_MAIN_CPP_COMMON_TEST2_HPP_

#include "../shared/FilesManager.hpp"
#include "IScene.hpp"
#include "Renderer.hpp"

class Test2 : public IScene {
private:
  Renderer renderer;
  FilesManager *filesManager;

public:
  explicit Test2(FilesManager *filesManager);

  void surfaceCreated() override;
  void surfaceChanged(Dimension) override;
  void render() override;
  void pause() override;
  void resume() override;
  void update(double) override;
  bool events(Point2D) override;
};

#endif // APP_SRC_MAIN_CPP_COMMON_TEST2_HPP_
