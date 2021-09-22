//
// Created by simonppg on 3/13/19.
//

#ifndef BREAK_IT_ALL_CAMERA_H
#define BREAK_IT_ALL_CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Point3D.hpp"
#include "Projection.hpp"
#include "Dimension.hpp"

using glm::mat4;
using glm::vec3;

class Camera {
    Projection projection = PERSPECTIVE;
    Dimension *dimension;
    Point3D *position;

public:
    float ncp; // near clipping plane
    float fcp; // far clipping plane
    float fov; // field of view
    mat4 cameraTranslate;

    Camera();
    Camera(Dimension *dimension, Point3D *position);
    Camera(Dimension *dimension, Point3D *position, float ncp, float fcp, float fov);

    Point3D* getPosition();
    Dimension* getDimension();
    float aspect_ratio();

    void updateDimension(Dimension *dimension);
    void updatePosition(Point3D *position);
    void update_projection();
    void setProjection(Projection projection);

    float top, bottom, right, left;
};

#endif //BREAK_IT_ALL_CAMERA_H
