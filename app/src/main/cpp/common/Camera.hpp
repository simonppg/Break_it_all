// Copyright (c) 2022 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_CAMERA_HPP_
#define APP_SRC_MAIN_CPP_COMMON_CAMERA_HPP_

#include "Dimension.hpp"
#include "FieldOfView.hpp"
#include "Point3D.hpp"
#include "Projection.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using glm::mat4;
using glm::vec3;

class Camera {
private:
  Projection projection = Projection::PERSPECTIVE;
  Dimension dimension;
  Point3D position;
  FieldOfView fov;

  // NOTE: MUST be called after change position, dimension or fov
  void updateProjection();

public:
  mat4 cameraTranslate;

  Camera();
  Camera(Dimension dimension, Point3D position);
  Camera(Dimension dimension, Point3D position, FieldOfView fov);

  Point3D getPosition();
  Dimension getDimension();
  float aspectRatio();

  void updateDimension(Dimension dimension);
  void updatePosition(Point3D position);
  void setProjection(Projection projection);

  float top, bottom, right, left;
};

#endif // APP_SRC_MAIN_CPP_COMMON_CAMERA_HPP_
