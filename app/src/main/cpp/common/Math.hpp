// Copyright (c) 2022 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_MATH_HPP_
#define APP_SRC_MAIN_CPP_COMMON_MATH_HPP_

#include <vector>

#include "Dimension.hpp"

using std::vector;

class Math {
public:
  vector<float> generateGrid(Dimension dimension, float row, float col);
  float *get_circle(float radius, int number_of_vertices);
  float *get_cube();
  int16_t *get_cube_index();
};

#endif // APP_SRC_MAIN_CPP_COMMON_MATH_HPP_
