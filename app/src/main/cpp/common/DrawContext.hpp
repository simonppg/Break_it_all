// Copyright (c) 2022 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_DRAWCONTEXT_HPP_
#define APP_SRC_MAIN_CPP_COMMON_DRAWCONTEXT_HPP_

#include "MeshType.hpp"
#include <glm/glm.hpp>

using glm::mat4;

class DrawContext {

public:
  unsigned int programID;
  MeshType type;
  unsigned int vbo;
  unsigned int iab;
  const void *vertex;
  int32_t numIndices;
  mat4 matrix_transform;
  int32_t numVertices;
  short *indices;
};

#endif // APP_SRC_MAIN_CPP_COMMON_DRAWCONTEXT_HPP_
