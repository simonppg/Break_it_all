//
// Created by simonppg on 3/13/19.
//

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Camera.hpp"
#include "Projection.hpp"
#include "Dimension.hpp"
#include "FieldOfView.hpp"

using glm::mat4;

Camera::Camera()
    : dimension(new Dimension()), position(new Point3D()), fov(new FieldOfView()) {
  updateProjection();
}

Camera::Camera(Dimension *dimension, Point3D *position)
    : dimension(dimension), position(new Point3D()), fov(new FieldOfView()) {
  updateProjection();
}

Camera::Camera(Dimension *dimension, Point3D *position, FieldOfView *fov)
    : dimension(dimension), position(new Point3D()), fov(fov) {
  updateProjection();
}

Dimension* Camera::getDimension() { return dimension; }
Point3D * Camera::getPosition() { return position; }
float Camera::aspect_ratio() { return dimension->aspectRatio(); }

void Camera::updateDimension(Dimension *dimension) {
  if (this->dimension != nullptr) { delete this->dimension; }

  this->dimension = dimension;
  updateProjection();
}

void Camera::updatePosition(Point3D *position) {
    if(this->position != nullptr) { delete this->position; }

    this->position = position;
    updateProjection();
}

void Camera::setProjection(Projection projection) {
    this->projection = projection;
    updateProjection();
}

// NOTE: MUST be called after change position, dimension or fov
void Camera::updateProjection() {
    mat4 perspective;

    if(projection == PERSPECTIVE)
        perspective = glm::perspective(glm::radians(fov->getFov()), Camera::aspect_ratio(), fov->getNcp(), fov->getFcp());
    else {
        if (dimension->getWidth() > dimension->getHeight()) {
            top = dimension->getWidth()/2;
            bottom = -top;
            right = top * aspect_ratio();
            left = -right;
        }
        else {
            right = dimension->getWidth()/2;
            left = -right;
            top = right / aspect_ratio();
            bottom = -top;
        }
        perspective = glm::ortho(left, right, bottom, top, fov->getNcp(),fov->getFcp());
    }

    cameraTranslate = glm::translate(perspective, vec3(-position->getX(), -position->getY(), -position->getZ()));
}

