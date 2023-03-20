#ifndef APP_SRC_MAIN_CPP_COMMON_SANDBOX_HPP_
#define APP_SRC_MAIN_CPP_COMMON_SANDBOX_HPP_

#include <vector>

#include "../eventbus/CursorPositionChanged.hpp"
#include "../glwrapper/Gl.hpp"
#include "Camera.hpp"
#include "Math.hpp"
#include "Mesh.hpp"
#include "Object.hpp"
#include "Scene.hpp"
#include "ShaderProg.hpp"

#include "../platform/FilesManager.hpp"

using std::vector;

class SandBox final : public Scene {
private:
  Gl *gl;
  Mesh *mesh;
  Object *objects[40];
  ShaderProg *shaderProg;
  Renderer *renderer;
  float povInDegrees = 0.0f;
  vector<Object *> objectList;
  // void cursorPositionChangedHandler(Event *e);

public:
  explicit SandBox(Platform *, FilesManager *);
  ~SandBox();

  void surfaceCreated() override;
  void surfaceChanged(Dimension) override;
  void pause() override;
  void resume() override;
  void update(double) override;
  // bool events(Point2D) override;
};

#endif // APP_SRC_MAIN_CPP_COMMON_SANDBOX_HPP_
