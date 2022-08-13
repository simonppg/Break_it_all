// Copyright (c) 2022 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_DRAWCONTEXT_HPP_
#define APP_SRC_MAIN_CPP_COMMON_DRAWCONTEXT_HPP_

#include "Mesh.hpp"
#include <glm/glm.hpp>

using glm::mat4;

class DrawContext {
public:
  unsigned int programID;
  Mesh *mesh;
  mat4 matrix_transform;
};

#endif // APP_SRC_MAIN_CPP_COMMON_DRAWCONTEXT_HPP_
