// Copyright (c) 2021 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_SHADERPROG_HPP_
#define APP_SRC_MAIN_CPP_COMMON_SHADERPROG_HPP_

#include "Renderer.hpp"
#include <string>

using std::string;

class ShaderProg final {
private:
  Renderer renderer;
  string vertex_file;
  string fragment_file;

public:
  ShaderProg(const string vertShaderStr, const string fragShaderStr);

  void createProgram();

  unsigned int programID;
};

#endif // APP_SRC_MAIN_CPP_COMMON_SHADERPROG_HPP_
