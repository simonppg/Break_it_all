// Copyright (c) 2022 Simon Puente
#include <cmath>

#include "Math.hpp"
#include "Dimension.hpp"

vector<float> Math::generateGrid(Dimension dimension, float row, float col) {
  float width = dimension.getWidth();
  float height = dimension.getHeight();

  float x_section = width / col;
  float y_section = height / row;
  float x_offset = -width / 2 + x_section / 2;
  float y_offset = height - y_section / 2;

  vector<float> grid;

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      grid.push_back(x_offset);
      grid.push_back(y_offset);
      x_offset = x_offset + x_section;
    }
    x_offset = -width / 2 + x_section / 2;
    y_offset = y_offset - y_section;
  }

  return grid;
}

float *Math::get_circle(float radius, int number_of_vertices) {
  float *v;

  v = reinterpret_cast<float *>(malloc(sizeof(float) * 3 * number_of_vertices));
  int j = 0;

  for (double i = 0; i < 2 * M_PI; i += 2 * M_PI / number_of_vertices) {
    v[j++] = cos(i) * radius; // X coordinate
    v[j++] = sin(i) * radius; // Y coordinate
    v[j++] = 0.0;             // Z coordinate
  }

  return v;
}

int16_t *Math::get_cube_index() {
  int16_t *indices;
#define size 36
  indices = reinterpret_cast<int16_t *>(malloc(sizeof(int16_t) * size));

  int16_t p[] = {// right face 0,1,4,5
               0, 1, 4, 1, 4, 5,

               // left face 2,3,6,7
               2, 3, 6, 3, 6, 7,

               // down face 0,1,2,3
               0, 1, 2, 0, 2, 3,

               // up face 4,5,6,7
               4, 5, 6, 4, 6, 7,

               // front face 1,2,5,6
               1, 2, 5, 2, 5, 6,

               // back face 0,3,4,7
               0, 3, 4, 3, 4, 7};

  for (int i = 0; i < size; ++i) {
    indices[i] = p[i];
  }

  return indices;
#undef size
}

float *Math::get_cube() {
  float *vertex;
#define size 48
  vertex = reinterpret_cast<float *>(malloc(sizeof(float) * size));

  float p[size] = {1.0,  -1.0, -1.0, // right down back
                   1.0,  0.0,  0.0,

                   1.0,  -1.0, 1.0, // right down front
                   1.0,  1.0,  0.0,

                   -1.0, -1.0, 1.0, // left down front
                   0.0,  1.0,  0.0,

                   -1.0, -1.0, -1.0, // left down back
                   0.0,  0.0,  0.0,

                   1.0,  1.0,  -1.0, // right up back
                   1.0,  0.0,  1.0,

                   1.0,  1.0,  1.0, // right up front
                   1.0,  1.0,  1.0,

                   -1.0, 1.0,  1.0, // left up front
                   0.0,  1.0,  1.0,

                   -1.0, 1.0,  -1.0, // left up back
                   0.0,  0.0,  1.0};

  for (int i = 0; i < size; ++i) {
    vertex[i] = p[i];
  }

  return vertex;
#undef size
}
