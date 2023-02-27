// Copyright (c) 2022 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_OBJECT_HPP_
#define APP_SRC_MAIN_CPP_COMMON_OBJECT_HPP_

#include "Camera.hpp"
#include "DrawContext.hpp"
#include "Mesh.hpp"
#include "Point3D.hpp"
#include "Renderer.hpp"
#include "ShaderProg.hpp"

using glm::mat4;

class Object {
protected:
  ShaderProg *program;
  Renderer *renderer;
  Mesh *mesh;

  float angle;
  Point3D position;
  Point3D rotation;
  Point3D size;

public:
  Object(ShaderProg *pProg, Mesh *pMesh);
  ~Object();

  Point3D getPosition();

  void draw(Camera *);
  void updatePosition(Point3D position);
  void updateSize(Point3D size);
  void set_rotation_angle(float angle);
  void animate_x();
  void animate_y();
  void animate_z();

  float velocity;
  float acceleration = 0;
};

#endif // APP_SRC_MAIN_CPP_COMMON_OBJECT_HPP_
