#ifndef APP_SRC_MAIN_CPP_GAME_BALL_HPP_
#define APP_SRC_MAIN_CPP_GAME_BALL_HPP_

#include "DrawableObject.hpp"
#include "Mesh.hpp"
#include "MeshFactory.hpp"
#include "Object3D.hpp"

class Ball final : public Object3D, virtual public DrawableObject {
private:
  Mesh *mesh;

public:
  explicit Ball(MeshFactory *);
  ~Ball();
  void draw() override;
};

#endif // APP_SRC_MAIN_CPP_GAME_BALL_HPP_
