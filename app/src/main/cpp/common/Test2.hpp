#ifndef APP_SRC_MAIN_CPP_COMMON_TEST2_HPP_
#define APP_SRC_MAIN_CPP_COMMON_TEST2_HPP_

#include "../shared/platform/FilesManager.hpp"
#include "Renderer.hpp"
#include "Scene.hpp"
#include "opengl/Gl.hpp"

class Test2 final : public Scene {
private:
  Gl *gl;
  Renderer renderer = Renderer(new Camera());
  FilesManager *filesManager;

  float vVertices[9] = {0.0f, 0.5f, 0.0f,  -0.5f, -0.5f,
                        0.0f, 0.5f, -0.5f, 0.0f};

public:
  explicit Test2(Platform *, FilesManager *);
  ~Test2();

  void surfaceCreated() override;
  void surfaceChanged(Dimension) override;
  void pause() override;
  void resume() override;
  void update(double) override;
  // bool events(Point2D) override;
};

#endif // APP_SRC_MAIN_CPP_COMMON_TEST2_HPP_
