// Copyright (c) 2021 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_SHADERPROG_HPP_
#define APP_SRC_MAIN_CPP_COMMON_SHADERPROG_HPP_

#include <iostream>
#include <string>

#include "ShaderLoader.hpp"
#include "opengl/Gl.hpp"

using std::string;

class ShaderProg final {
private:
  Gl *gl;
  ShaderLoader *shaderLoader;
  string vertexFile;
  string fragmentFile;
  uint32_t createProgramm(const string vertexSource,
                          const string fragmentSource);
  void showProgramInfoLog(uint32_t program);

public:
  ShaderProg(const string vertShaderStr, const string fragShaderStr);
  ~ShaderProg();

  void createProgram();
  void use();
  uint32_t getUniformLocation(string uniformName);

  // TODO(Simon Puente): make programID private
  uint32_t programID;
};

#endif // APP_SRC_MAIN_CPP_COMMON_SHADERPROG_HPP_
