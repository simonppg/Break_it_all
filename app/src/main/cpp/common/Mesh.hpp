// Copyright (c) 2022 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_MESH_HPP_
#define APP_SRC_MAIN_CPP_COMMON_MESH_HPP_

#include "MeshType.hpp"
#include <malloc.h>
#include <stdint.h>

#define NUM_ARRAY_ELEMENTS(a) (sizeof(a) / sizeof(*a))
#define INDEX_BUFFER_SIZE(numIndices)                                          \
  ((GLsizeiptr)((numIndices) * (sizeof(GLushort))))
#define VERTEX_BUFFER_SIZE(numIndices)                                         \
  ((GLsizeiptr)((numIndices) * (sizeof(float) * 6)))

class Mesh {
public:
  Mesh(float *pDouble, int i);
  Mesh(float *vertex, int v_size, int16_t *indices, int i_size);
  ~Mesh();

  MeshType type;
  float *vertex = nullptr;
  int16_t *indices = nullptr;
  int numVertices;
  int numIndices;
  uint32_t vbo; // vertex buffer object
  uint32_t iab; // index array buffer
};

#endif // APP_SRC_MAIN_CPP_COMMON_MESH_HPP_
