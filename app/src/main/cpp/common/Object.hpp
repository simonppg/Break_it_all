// Copyright (c) 2022 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_OBJECT_HPP_
#define APP_SRC_MAIN_CPP_COMMON_OBJECT_HPP_

#include "Camera.hpp"
#include "DrawContext.hpp"
#include "Mesh.hpp"
#include "Point3D.hpp"
#include "Renderer.hpp"
#include "ShaderProg.hpp"

class Object {
protected:
  ShaderProg *prog;
  Renderer *renderer;
  DrawContext *draw_context;
  Camera *camera;
  vec3 rotation;
  float angle;
  Mesh *mesh;
  Point3D position;
  Point3D size;

public:
  Object(Camera *pCamera, ShaderProg *pProg, Mesh *pMesh);

  Point3D getPosition();

  void draw();
  void updatePosition(Point3D position);
  void updateSize(Point3D size);
  void set_rotation_angle(float angle);
  void animate_x();
  void animate_y();
  void animate_z();

  float velocity;
  float acceleration = 0;
  float x_direction = 1;
};

#endif // APP_SRC_MAIN_CPP_COMMON_OBJECT_HPP_
