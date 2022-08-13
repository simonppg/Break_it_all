// Copyright (c) 2022 Simon Puente
#include <GLES3/gl3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Object.hpp"
#include "Point3D.hpp"

Object::Object(ShaderProg *pProg, Mesh *pMesh)
    : angle{0}, size{Point3D(2, 1, 1)} {
  this->prog = pProg;
  this->mesh = pMesh;
  position = Point3D();
  rotation = Point3D(1, 1, 1);
  acceleration = 0;
  velocity = 500.0;
  drawContext = new DrawContext();
}

Object::~Object() {
  delete drawContext;
  drawContext = nullptr;
}

Point3D Object::getPosition() { return position; }

void Object::draw(Camera *camera) {
  mat4 trasformed = camera->trasform(position, angle, rotation, size);

  drawContext->programID = prog->programID;
  drawContext->matrix_transform = trasformed;
  drawContext->mesh = mesh;

  renderer->draw(drawContext);
}

void Object::updatePosition(Point3D position) { this->position = position; }

void Object::updateSize(Point3D size) { this->size = size; }

void Object::set_rotation_angle(float angle) { this->angle = angle; }

void Object::animate_x() { rotation = Point3D(1, 0, 0); }

void Object::animate_y() { rotation = Point3D(0, 1, 0); }

void Object::animate_z() { rotation = Point3D(0, 0, 1); }
