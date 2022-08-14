// Copyright (c) 2022 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_OPENGL_SHADERLOADER_HPP_
#define APP_SRC_MAIN_CPP_COMMON_OPENGL_SHADERLOADER_HPP_

#include "Gl.hpp"
#include <string>

using std::string;

class ShaderLoader {
private:
  Gl *gl;

  void showShaderInfoLog(int32_t shader);

public:
  ShaderLoader();
  ~ShaderLoader();

  uint32_t loadShader(int32_t shaderType, const string shaderSource);
};

#endif // APP_SRC_MAIN_CPP_COMMON_OPENGL_SHADERLOADER_HPP_
