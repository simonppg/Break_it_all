#ifndef APP_SRC_MAIN_CPP_GAME_TEST3_HPP_
#define APP_SRC_MAIN_CPP_GAME_TEST3_HPP_

#include "../platform/FilesManager.hpp"

#include "../glwrapper/Gl.hpp"
#include "Math.hpp"
#include "Renderer.hpp"
#include "Scene.hpp"

class Test3 final : public Scene {
private:
  Gl *gl;
  Renderer renderer = Renderer(new Camera(Dimension(), Point3D(0, 0, 40)));
  FilesManager *filesManager;
  Math *math = new Math();
  float *circle;
  int NUMBER_OF_VERTICES = 160;

public:
  explicit Test3(Platform *);
  ~Test3();

  void surfaceCreated() override;
  void surfaceChanged() override;
  void pause() override;
  void resume() override;
  void update(double) override;
  // bool events(Point2D) override;
};

#endif // APP_SRC_MAIN_CPP_GAME_TEST3_HPP_
