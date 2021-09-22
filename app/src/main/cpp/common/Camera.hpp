//
// Created by simonppg on 3/13/19.
//

#ifndef BREAK_IT_ALL_CAMERA_H
#define BREAK_IT_ALL_CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Projection.hpp"
#include "CanvasSize.hpp"

using glm::mat4;
using glm::vec3;

#include "Point3D.hpp"

static const int WIDTH = 450;
static const int HEIGHT = 800;

class Camera {
    Projection projection = PERSPECTIVE;
    CanvasSize *size;
    Point3D *position;

public:
    float ncp; // near clipping plane
    float fcp; // far clipping plane
    float fov; // field of view
    mat4 cameraTranslate;

    Camera();
    Camera(CanvasSize *size, Point3D *position);
    Camera(CanvasSize *size, Point3D *position, float ncp, float fcp, float fov);

    Point3D* getPosition();
    CanvasSize* getSize();
    float aspect_ratio();

    void updateSize(CanvasSize *size);
    void updatePosition(Point3D *position);
    void update_projection();
    void setProjection(Projection projection);

    float top, bottom, right, left;
};

#endif //BREAK_IT_ALL_CAMERA_H
