// Copyright (c) 2022 Simon Puente
#include <iostream>

using std::cout;
using std::endl;

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Camera.hpp"
#include "Dimension.hpp"
#include "FieldOfView.hpp"
#include "Projection.hpp"

using glm::mat4;

Camera::Camera()
    : dimension(Dimension()), position(Point3D()), fov(FieldOfView()) {
  updateProjection();
}

Camera::Camera(Dimension dimension, Point3D position)
    : dimension(dimension), position(position), fov(FieldOfView()) {
  updateProjection();
}

Camera::Camera(Dimension dimension, Point3D position, FieldOfView fov)
    : dimension(dimension), position(position), fov(fov) {
  updateProjection();
}

mat4 Camera::translate(Point3D position) {
  auto point = vec3(position.getX(), position.getY(), position.getZ());
  return glm::translate(cameraTranslate, point);
}

mat4 Camera::rotate(mat4 translate, float angle, Point3D rotation){
  auto point = vec3(rotation.getX(), rotation.getY(), rotation.getZ());
  return glm::rotate(translate, glm::radians(angle), point);
}

mat4 Camera::scale(mat4 rotate, Point3D size) {
  auto point = vec3(size.getX(), size.getY(), size.getZ());
  return glm::scale(rotate, point);
}

Dimension Camera::getDimension() { return dimension; }
Point3D Camera::getPosition() { return position; }
float Camera::aspectRatio() { return dimension.aspectRatio(); }

void Camera::updateDimension(Dimension dimension) {
  cout << "old: " << this->dimension << ",new: " << dimension << endl;
  this->dimension = Dimension(dimension);
  updateProjection();
}

void Camera::updatePosition(Point3D position) {
  this->position = Point3D(position);
  updateProjection();
}

void Camera::setProjection(Projection projection) {
  this->projection = projection;
  updateProjection();
}

// NOTE: MUST be called after change position, dimension or fov
void Camera::updateProjection() {
  mat4 perspective;

  if (projection == Projection::PERSPECTIVE) {
    perspective = glm::perspective(glm::radians(fov.getFov()), aspectRatio(),
                                   fov.getNcp(), fov.getFcp());
  } else {
    if (dimension.getWidth() > dimension.getHeight()) {
      top = dimension.getWidth() / 2;
      bottom = -top;
      right = top * aspectRatio();
      left = -right;
    } else {
      right = dimension.getWidth() / 2;
      left = -right;
      top = right / aspectRatio();
      bottom = -top;
    }
    perspective =
        glm::ortho(left, right, bottom, top, fov.getNcp(), fov.getFcp());
  }

  cameraTranslate = glm::translate(
      perspective, vec3(-position.getX(), -position.getY(), -position.getZ()));
}
