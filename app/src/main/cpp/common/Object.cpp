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
  rotation = vec3(1);
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
  mat4 translate;
  mat4 rotate;
  mat4 scale;

  translate = camera->translate(position);
  rotate = glm::rotate(translate, glm::radians(angle), rotation);
  scale = glm::scale(rotate, glm::vec3(size.getX(), size.getY(), size.getZ()));

  drawContext->programID = prog->programID;
  drawContext->type = mesh->type;
  drawContext->vbo = mesh->vbo;
  drawContext->iab = mesh->iab;
  drawContext->vertex = mesh->vertex;
  drawContext->numVertices = mesh->numVertices;
  drawContext->indices = mesh->indices;
  drawContext->numIndices = mesh->numIndices;
  drawContext->matrix_transform = scale;

  renderer->draw(drawContext);
}

void Object::updatePosition(Point3D position) { this->position = position; }

void Object::updateSize(Point3D size) { this->size = size; }

void Object::set_rotation_angle(float angle) { this->angle = angle; }

void Object::animate_x() { rotation = vec3(1, 0, 0); }

void Object::animate_y() { rotation = vec3(0, 1, 0); }

void Object::animate_z() { rotation = vec3(0, 0, 1); }
