// Copyright (c) 2022 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_TEST1_HPP_
#define APP_SRC_MAIN_CPP_COMMON_TEST1_HPP_

#include "IScene.hpp"

class Test1 : public IScene {
public:
  Test1();
  void surfaceCreated() override;
  void surfaceChanged(Dimension) override;
  void render() override;
  void pause() override;
  void resume() override;
  void update() override;
  bool events(Point2D) override;
};

#endif // APP_SRC_MAIN_CPP_COMMON_TEST1_HPP_
