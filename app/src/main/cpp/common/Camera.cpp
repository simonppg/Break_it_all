//
// Created by simonppg on 3/13/19.
//

#include "Camera.hpp"
#include "Projection.hpp"
#include "CanvasSize.hpp"

Camera::Camera() : size{new CanvasSize()}, ncp{NCP}, fcp {FCP}, fov{FOV} {
    update_projection();
}

Camera::Camera(CanvasSize *size, Point3D *position, float ncp, float rcp, float fov)
: size{size}, ncp{NCP}, fcp {FCP}, fov{FOV}
{
    this->size = size;
    this->position = position;
    this->ncp = ncp;
    this->fcp = rcp;
    this->fov = fov;
    update_projection();
}

CanvasSize* Camera::getSize() { return size; }
Point3D * Camera::getPosition() { return position; }
float Camera::aspect_ratio() { return size->aspectRatio(); }

void Camera::update_projection() {
    if(projection == PERSPECTIVE)
        perspective = glm::perspective(glm::radians(fov), Camera::aspect_ratio(), ncp, fcp);
    else {
        if (size->getWidth() > size->getHeight()) {
            top = size->getWidth()/2;
            bottom = -top;
            right = top * aspect_ratio();
            left = -right;
        }
        else {
            right = size->getWidth()/2;
            left = -right;
            top = right / aspect_ratio();
            bottom = -top;
        }
        perspective = glm::ortho(left, right, bottom, top, ncp, fcp);
    }

    cameraTranslate = glm::translate(perspective, vec3(-position->getX(), -position->getY(), -position->getZ()));
}

void Camera::updateSize(CanvasSize *size) {
  if (this->size != nullptr) { delete this->size; }

  this->size = size;
  update_projection();
}

void Camera::updatePosition(Point3D *position) {
    if(this->position != nullptr) { delete this->position; }

    this->position = position;
    update_projection();
}

void Camera::setProjection(Projection projection) {
    this->projection = projection;
    update_projection();
}
