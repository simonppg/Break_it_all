// Copyright (c) 2021 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_SHADERPROG_HPP_
#define APP_SRC_MAIN_CPP_COMMON_SHADERPROG_HPP_

#include "Renderer.hpp"

class ShaderProg {
private:
  Renderer renderer;
  const char *vertex_file;
  const char *fragment_file;

public:
  ShaderProg(const char *vertShaderStr, const char *fragShaderStr);

  void createProgram();

  unsigned int programID;
};

#endif // APP_SRC_MAIN_CPP_COMMON_SHADERPROG_HPP_
