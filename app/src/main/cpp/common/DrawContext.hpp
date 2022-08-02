// Copyright (c) 2022 Simon Puente
#ifndef COMMON_DRAW_CONTEXT_HPP
#define COMMON_DRAW_CONTEXT_HPP

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

#endif // COMMON_DRAW_CONTEXT_HPP
