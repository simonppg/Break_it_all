// Copyright (c) 2021 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_TEST3_HPP_
#define APP_SRC_MAIN_CPP_COMMON_TEST3_HPP_

#include "IScene.hpp"
#include "Math.hpp"
#include "Renderer.hpp"

class Test3 : public IScene {
private:
  Renderer renderer;
  Math *math = new Math();

public:
  Test3();
  void surfaceCreated() override;
  void surfaceChanged(int width, int height) override;
  void render() override;
  void pause() override;
  void resume() override;
  void update() override;
  bool events(double xpos, double ypos) override;
};

#endif // APP_SRC_MAIN_CPP_COMMON_TEST3_HPP_
