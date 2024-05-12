#ifndef APP_SRC_MAIN_CPP_GAME_BALL_HPP_
#define APP_SRC_MAIN_CPP_GAME_BALL_HPP_

#include "DrawableObject.hpp"
#include "Mesh.hpp"
#include "MeshFactory.hpp"
#include "Object3D.hpp"
#include "ProgramFactory.hpp"
#include "Renderer.hpp"
#include "ShaderProg.hpp"

class Ball final : public Object3D, virtual public DrawableObject {
private:
  ShaderProg *program;
  Renderer *renderer;
  Mesh *mesh;

  float angle;
  Point3D position;
  Point3D rotation;
  Point3D size;

public:
  explicit Ball(MeshFactory *, Renderer *, ProgramFactory *);
  ~Ball();
  void draw() override;
};

#endif // APP_SRC_MAIN_CPP_GAME_BALL_HPP_
