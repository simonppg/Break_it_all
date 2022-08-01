// Copyright (c) 2022 Simon Puente
#include <GLES3/gl3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Object.hpp"
#include "Point3D.hpp"

Object::Object(Camera *pCamera, ShaderProg *pProg, Mesh *pMesh)
    : angle{0}, size{Point3D(2, 1, 1)} {
  this->position = Point3D();
  rotation = vec3(1);
  this->camera = pCamera;
  this->prog = pProg;
  this->mesh = pMesh;
  acceleration = 0;
  velocity = 500.0;
  draw_context = new DrawContext();
}

Point3D Object::getPosition() { return position; }

void Object::draw() {
  mat4 translate;
  mat4 rotate;
  mat4 scale;

  translate =
      glm::translate(camera->cameraTranslate,
                     vec3(position.getX(), position.getY(), position.getZ()));
  rotate = glm::rotate(translate, glm::radians(angle), rotation);
  scale = glm::scale(rotate, glm::vec3(size.getX(), size.getY(), size.getZ()));

  draw_context->programID = prog->programID;
  draw_context->type = mesh->type;
  draw_context->vbo = mesh->vbo;
  draw_context->iab = mesh->iab;
  draw_context->vertex = mesh->vertex;
  draw_context->numVertices = mesh->numVertices;
  draw_context->indices = mesh->indices;
  draw_context->numIndices = mesh->numIndices;
  draw_context->matrix_transform = scale;

  renderer->draw(draw_context);
}

void Object::updatePosition(Point3D position) { this->position = position; }

void Object::updateSize(Point3D size) { this->size = size; }

void Object::set_rotation_angle(float angle) { this->angle = angle; }

void Object::animate_x() { rotation = vec3(1, 0, 0); }

void Object::animate_y() { rotation = vec3(0, 1, 0); }

void Object::animate_z() { rotation = vec3(0, 0, 1); }
