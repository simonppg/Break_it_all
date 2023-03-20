#include "ShaderLoader.hpp"

#include <iostream>

#include "Gl.hpp"

void ShaderLoader::showShaderInfoLog(int32_t shader) {
  int32_t infoLength = gl.getInfoLogLength(shader);
  if (infoLength <= 0) {
    return;
  }

  string log = gl.getShaderInfoLog(shader, infoLength);

  // TODO(Simon Puente): use shared/Logger
  std::cout << log;
}

uint32_t ShaderLoader::loadVertexShader(const string shaderSource) {
  // In this function 0 is and error
  int error = 0;
  auto shaderIdOrNull = gl.createVertextShader();
  if (!shaderIdOrNull.has_value()) {
    return error;
  }

  uint32_t shaderId = shaderIdOrNull.value();
  return loadShader(shaderId, shaderSource);
}

uint32_t ShaderLoader::loadFragmentShader(const string shaderSource) {
  // In this function 0 is and error
  int error = 0;
  auto shaderIdOrNull = gl.createFragmentShader();
  if (!shaderIdOrNull.has_value()) {
    return error;
  }

  uint32_t shaderId = shaderIdOrNull.value();
  return loadShader(shaderId, shaderSource);
}

uint32_t ShaderLoader::loadShader(uint32_t shaderId,
                                  const string shaderSourceStr) {
  const int NUM_OF_SOURCES = 1;
  gl.shaderSource(shaderId, NUM_OF_SOURCES, shaderSourceStr);
  gl.compileShader(shaderId);

  if (gl.isShaderCompilationOk(shaderId)) {
    return shaderId;
  }

  showShaderInfoLog(shaderId);
  gl.deleteShader(shaderId);

  // In this function 0 is and error
  int error = 0;
  return error;
}
