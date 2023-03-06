#include "ShaderLoader.hpp"

#include <iostream>

#include "Gl.hpp"

#include "GLES3/gl3.h"

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

  string log = gl->getShaderInfoLog(shader, infoLength);

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
  auto shaderOrNull = gl->createShader(shaderType);
  if (!shaderOrNull.has_value()) {
    return error;
  }

  uint32_t shader = shaderOrNull.value();

  glShaderSource(shader, NUM_OF_SOURCES, &shaderSource, NULL);
  glCompileShader(shader);

  if (gl->isShaderCompilationOk(shader)) {
    return shader;
  }

  showShaderInfoLog(shader);
  glDeleteShader(shader);

  return error;
}
