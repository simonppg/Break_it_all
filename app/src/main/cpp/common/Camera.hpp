//
// Created by simonppg on 3/13/19.
//

#ifndef BREAK_IT_ALL_CAMERA_H
#define BREAK_IT_ALL_CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Projection.hpp"

using glm::mat4;
using glm::vec3;

#include "Point3D.hpp"

static const int WIDTH = 450;
static const int HEIGHT = 800;
static const float NCP = 0.1f;
static const float FCP = 100.0f;
static const float FOV = 60.0f;
static const float X = 0.0f;
static const float Y = 0.0f;
static const float Z = 40.0f;

class Camera {
    int projection_type = PERSPECTIVE;
    Point3D position;
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
    Camera(int w, int h, Point3D position, float ncp, float fcp, float fov);

    float aspect_ratio();
    void update_width_height(int width, int height);
    void update_xyz(float x, float y, float z);
    void update_position(Point3D position);

    void update_projection();
    void set_projection_type(int projection);

    float top, bottom, right, left;
};

#endif //BREAK_IT_ALL_CAMERA_H
