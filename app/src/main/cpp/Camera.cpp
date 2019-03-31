//
// Created by simonppg on 3/13/19.
//

#include "Camera.hpp"
#include "utils.hpp"

Camera::Camera() : w{WIDTH}, h{HEIGHT}, x{X}, y{Y}, z{Z}, ncp{NCP}, fcp {FCP}, fov{FOV}
{
    update_perspective();
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
    update_perspective();
}

float Camera::aspect_ratio() { // TODO: change this to a macro
    return (float) w/h;
}

void Camera::update_width_height(int width, int height) {
    this->w = width;
    this->h = height;
    update_perspective();
}

void Camera::update_perspective() {
    perspective = glm::perspective(glm::radians(fov), Camera::aspect_ratio(), ncp, fcp);
    //perspective = glm::ortho(-10.0f,10.0f,-5.0f,5.0f, ncp, fcp);
    cameraTranslate = glm::translate(perspective, vec3(-x, -y, -z));
}

void Camera::update_xyz(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
    update_perspective();
}