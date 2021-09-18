//
// Created by simonppg on 3/13/19.
//

#include "Camera.hpp"
#include "Projection.hpp"

Camera::Camera() : w{WIDTH}, h{HEIGHT}, ncp{NCP}, fcp {FCP}, fov{FOV} {
    update_projection();
}

Camera::Camera(int w, int h, Point3D *position, float ncp, float rcp, float fov)
: w{WIDTH}, h{HEIGHT}, ncp{NCP}, fcp {FCP}, fov{FOV}
{
    this->w = w;
    this->h = h;
    this->position = position;
    this->ncp = ncp;
    this->fcp = rcp;
    this->fov = fov;
    update_projection();
}

float Camera::aspect_ratio() { // TODO: change this to a macro
    return w/h;
}

void Camera::update_width_height(int width, int height) {
    w = width;
    h = height;
    update_projection();
}

void Camera::update_projection() {
    if(projection == PERSPECTIVE)
        perspective = glm::perspective(glm::radians(fov), Camera::aspect_ratio(), ncp, fcp);
    else {
        if (w > h) {
            top = w/2;
            bottom = -top;
            right = top * aspect_ratio();
            left = -right;
        }
        else {
            right = w/2;
            left = -right;
            top = right / aspect_ratio();
            bottom = -top;
        }
        perspective = glm::ortho(left, right, bottom, top, ncp, fcp);
    }

    cameraTranslate = glm::translate(perspective, vec3(-position->getX(), -position->getY(), -position->getZ()));
}

void Camera::updatePosition(Point3D *position) {
    if(this->position != nullptr) { delete this->position; }

    this->position = position;
    update_projection();
}

Point3D * Camera::getPosition() {
    return position;
}

void Camera::setProjection(Projection projection) {
    this->projection = projection;
    update_projection();
}
