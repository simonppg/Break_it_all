#ifndef APP_SRC_MAIN_CPP_GAME_TEST2_HPP_
#define APP_SRC_MAIN_CPP_GAME_TEST2_HPP_

#include "../glwrapper/Gl.hpp"
#include "../platform/FilesManager.hpp"
#include "Renderer.hpp"
#include "Scene.hpp"

class Test2 final : public Scene {
private:
  Gl *gl;
  Renderer renderer = Renderer(new Camera());
  FilesManager *filesManager;

  float vVertices[9] = {0.0f, 0.5f, 0.0f,  -0.5f, -0.5f,
                        0.0f, 0.5f, -0.5f, 0.0f};

public:
  explicit Test2(Platform *);
  ~Test2();

  void surfaceCreated() override;
  void surfaceChanged() override;
  void pause() override;
  void resume() override;
  void update(double) override;
  // bool events(Point2D) override;
};

#endif // APP_SRC_MAIN_CPP_GAME_TEST2_HPP_
