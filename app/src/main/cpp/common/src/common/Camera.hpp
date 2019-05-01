//
// Created by simonppg on 3/13/19.
//

#ifndef BREAK_IT_ALL_CAMERA_H
#define BREAK_IT_ALL_CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using glm::mat4;
using glm::vec3;

#define PERSPECTIVE 0
#define ORTHO 1
class Camera {
    int projection_type = PERSPECTIVE;
public:
    float w, h;
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

    void update_projection();
    void set_projection_type(int projection);

    float top, bottom, right, left;
};

#endif //BREAK_IT_ALL_CAMERA_H