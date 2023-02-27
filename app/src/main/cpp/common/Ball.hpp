// Copyright (c) 2022 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_BALL_HPP_
#define APP_SRC_MAIN_CPP_COMMON_BALL_HPP_

#include "Object3D.hpp"
#include "Mesh.hpp"
#include "MeshFactory.hpp"

class Ball final : public Object3D {
private:
  Mesh *mesh;
public:
  explicit Ball(MeshFactory *);
  ~Ball();
  void draw() override;
};

#endif // APP_SRC_MAIN_CPP_COMMON_BALL_HPP_
