// Copyright (c) 2022 Simon Puente
#include "ShaderLoader.hpp"

#include <iostream>

#include "Gl.hpp"

ShaderLoader::ShaderLoader() { gl = new Gl(); }

ShaderLoader::~ShaderLoader() {
  delete gl;
  gl = nullptr;
}

void ShaderLoader::showShaderInfoLog(int32_t shader) {
  int32_t infoLength = gl->getInfoLogLength(shader);
  if (infoLength <= 0) {
    return;
  }

  string log = gl->getInfoLog(shader, infoLength);

  // TODO(Simon Puente): use shared/Logger
  std::cout << log;
}

uint32_t ShaderLoader::loadShader(int32_t shaderType,
                                  const string shaderSourceStr) {
  const int NUM_OF_SOURCES = 1;
  const char *shaderSource = shaderSourceStr.c_str();
  // In this function 0 is and error
  int error = 0;

  // glCreateShader return 0 when there is an error
  uint32_t shader = glCreateShader(shaderType);
  if (!shader) {
    return error;
  }

  glShaderSource(shader, NUM_OF_SOURCES, &shaderSource, NULL);
  glCompileShader(shader);

  if (gl->isShaderCompilationOk(shader)) {
    return shader;
  }

  showShaderInfoLog(shader);
  glDeleteShader(shader);

  return error;
}
