#include <iostream>

using std::cout;
using std::endl;

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Camera.hpp"
#include "Dimension.hpp"
#include "FieldOfView.hpp"
#include "Projection.hpp"

using glm::mat4;

Camera::Camera()
    : dimension(Dimension()), position(Point3D()), fov(FieldOfView()) {
  updateProjection();
}

Camera::Camera(Dimension dimension, Point3D position)
    : dimension(dimension), position(position), fov(FieldOfView()) {
  updateProjection();
}

Camera::Camera(Dimension dimension, Point3D position, FieldOfView fov)
    : dimension(dimension), position(position), fov(fov) {
  updateProjection();
}

mat4 Camera::translate(Point3D position) {
  auto point = vec3(position.getX(), position.getY(), position.getZ());
  return glm::translate(cameraTranslate, point);
}

mat4 Camera::rotate(mat4 translate, float angle, Point3D rotation) {
  auto point = vec3(rotation.getX(), rotation.getY(), rotation.getZ());
  return glm::rotate(translate, glm::radians(angle), point);
}

mat4 Camera::scale(mat4 rotate, Point3D size) {
  auto point = vec3(size.getX(), size.getY(), size.getZ());
  return glm::scale(rotate, point);
}

mat4 Camera::trasform(Point3D position, float angle, Point3D rotation,
                      Point3D size) {
  mat4 translated = translate(position);
  mat4 rotated = rotate(translated, angle, rotation);
  mat4 scaled = scale(rotated, size);
  return scaled;
}

Point3D Camera::getPosition() { return position; }

void Camera::resize(Dimension dimension) {
  cout << "old: " << this->dimension << ",new: " << dimension << endl;
  this->dimension = Dimension(dimension);
  updateProjection();
}

void Camera::travel(Point3D position) {
  this->position = Point3D(position);
  updateProjection();
}

void Camera::changeProjection(Projection projection) {
  this->projection = projection;
  updateProjection();
}

// NOTE: MUST be called after change position, dimension or fov
void Camera::updateProjection() {
  mat4 aPerspective;

  if (projection == Projection::PERSPECTIVE) {
    aPerspective = math.perspectiveView(fov, dimension);
  } else {
    aPerspective = math.orthographicView(fov, dimension);
  }

  cameraTranslate = glm::translate(
      aPerspective, vec3(-position.getX(), -position.getY(), -position.getZ()));
}
