//
// Created by simonppg on 3/13/19.
//

#ifndef BREAK_IT_ALL_CAMERA_H
#define BREAK_IT_ALL_CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using glm::mat4;
using glm::vec3;

class Camera {

public:

    int w, h;
    float x, y, z;
    float ncp; // near clipping plane
    float fcp; // far clipping plane
    float fov; // field of view
    mat4 perspective;
    mat4 cameraTranslate;

    Camera();
    Camera(int w, int h, float x, float y, float z, float ncp, float fcp, float fov);

    float aspect_ratio();
    void update_width_height(int width, int height);
    void update_xyz(float x, float y, float z);

    void update_perspective();
};

#endif //BREAK_IT_ALL_CAMERA_H