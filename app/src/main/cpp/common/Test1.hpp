#ifndef APP_SRC_MAIN_CPP_COMMON_TEST1_HPP_
#define APP_SRC_MAIN_CPP_COMMON_TEST1_HPP_

#include "Scene.hpp"
#include "opengl/Gl.hpp"

class Test1 final : public Scene {
private:
  Gl *gl;

public:
  Test1(Platform *);
  ~Test1();

  void surfaceCreated() override;
  void surfaceChanged(Dimension) override;
  void pause() override;
  void resume() override;
  void update(double) override;
  // bool events(Point2D) override;
};

#endif // APP_SRC_MAIN_CPP_COMMON_TEST1_HPP_
