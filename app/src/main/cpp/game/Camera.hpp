#ifndef APP_SRC_MAIN_CPP_GAME_CAMERA_HPP_
#define APP_SRC_MAIN_CPP_GAME_CAMERA_HPP_

#include "Dimension.hpp"
#include "FieldOfView.hpp"
#include "Math.hpp"
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
  Math math;

  mat4 cameraTranslate;
  // NOTE: MUST be called after change position, dimension or fov
  void updateProjection();

public:
  Camera();
  Camera(Dimension dimension, Point3D position);
  Camera(Dimension dimension, Point3D position, FieldOfView fov);

  mat4 translate(Point3D);
  mat4 rotate(mat4, float, Point3D);
  mat4 scale(mat4, Point3D);
  mat4 trasform(Point3D, float, Point3D, Point3D);

  Point3D getPosition();

  void resize(Dimension dimension);
  void travel(Point3D position);
  void changeProjection(Projection projection);
};

#endif // APP_SRC_MAIN_CPP_GAME_CAMERA_HPP_
