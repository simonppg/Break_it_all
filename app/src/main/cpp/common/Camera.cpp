//
// Created by simonppg on 3/13/19.
//

#include "Camera.hpp"
#include "Projection.hpp"

Camera::Camera() : w{WIDTH}, h{HEIGHT}, x{X}, y{Y}, z{Z}, ncp{NCP}, fcp {FCP}, fov{FOV}
{
    update_projection();
}

Camera::Camera(int w, int h, float x, float y, float z, float ncp, float rcp, float fov)
: w{WIDTH}, h{HEIGHT}, x{X}, y{Y}, z{Z}, ncp{NCP}, fcp {FCP}, fov{FOV}
{
    this->w = w;
    this->h = h;
    this->x = x;
    this->y = y;
    this->z = z;
    this->ncp = ncp;
    this->fcp = rcp;
    this->fov = fov;
    update_projection();
}

Camera::Camera(int w, int h, Point3D position, float ncp, float rcp, float fov)
: w{WIDTH}, h{HEIGHT}, ncp{NCP}, fcp {FCP}, fov{FOV}
{
    this->w = w;
    this->h = h;
    this->x = X;
    this->y = Y;
    this->z = Z;
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

    cameraTranslate = glm::translate(perspective, vec3(-x, -y, -z));
}

void Camera::update_xyz(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
    update_projection();
}

void Camera::update_position(Point3D position) {
    this->position = position;
}

void Camera::setProjection(Projection projection) {
    this->projection = projection;
    update_projection();
}
