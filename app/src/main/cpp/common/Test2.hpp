// Copyright (c) 2021 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_TEST2_HPP_
#define APP_SRC_MAIN_CPP_COMMON_TEST2_HPP_

#include "../shared/FilesManager.hpp"
#include "IScene.hpp"
#include "Renderer.hpp"

class Test2 : public IScene {
private:
  Renderer renderer;

public:
  Test2();
  void surfaceCreated() override;
  void surfaceChanged(int width, int height) override;
  void render() override;
  void pause() override;
  void resume() override;
  void update() override;
  bool events(double xpos, double ypos) override;
};

#endif // APP_SRC_MAIN_CPP_COMMON_TEST2_HPP_
