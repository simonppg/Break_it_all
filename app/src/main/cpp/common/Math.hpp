// Copyright (c) 2022 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_MATH_HPP_
#define APP_SRC_MAIN_CPP_COMMON_MATH_HPP_

#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Dimension.hpp"
#include "FieldOfView.hpp"
#include "Point3D.hpp"

using glm::mat4;
using std::vector;

class Math {
public:
  vector<float> generateGrid(Dimension dimension, float row, float col);
  float *generateCircle(float radius, int number_of_vertices);
  float *generateCube();
  int16_t *generateCubeIndexs();
  mat4 perspectiveView(FieldOfView fov, Dimension dimension);
  mat4 orthographicView(FieldOfView fov, Dimension dimension);
};

#endif // APP_SRC_MAIN_CPP_COMMON_MATH_HPP_
