//
// Created by simonppg on 3/13/19.
//

#ifndef COMMON_CAMERA_H
#define COMMON_CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Point3D.hpp"
#include "Projection.hpp"
#include "Dimension.hpp"
#include "FieldOfView.hpp"

using glm::mat4;
using glm::vec3;

class Camera {
private:
    Projection projection = PERSPECTIVE;
    Dimension *dimension;
    Point3D *position;
    FieldOfView *fov;

    // NOTE: MUST be called after change position, dimension or fov
    void updateProjection();

public:
    mat4 cameraTranslate;

    Camera();
    Camera(Dimension *dimension, Point3D *position);
    Camera(Dimension *dimension, Point3D *position, FieldOfView *fov);

    Point3D* getPosition();
    Dimension* getDimension();
    float aspectRatio();

    void updateDimension(Dimension *dimension);
    void updatePosition(Point3D *position);
    void setProjection(Projection projection);

    float top, bottom, right, left;
};

#endif //COMMON_CAMERA_H
