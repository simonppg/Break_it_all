// Copyright (c) 2022 Simon Puente
#include "ShaderLoader.hpp"
#include <GLES3/gl3.h>
#include <malloc.h>

bool ShaderLoader::isCompilationOk(int32_t shader) {
  int32_t compiled = 0;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
  return compiled;
}

int ShaderLoader::getInfoLogLength(int32_t shader) {
  int32_t infoLen = 0;
  glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);
  return infoLen;
}

void ShaderLoader::showShaderInfoLog(int32_t shader) {
  int infoLength = getInfoLogLength(shader);
  if (!infoLength) {
    return;
  }

  char *buf = reinterpret_cast<char *>(malloc(sizeof(char) * infoLength));
  if (!buf) {
    return;
  }

  glGetShaderInfoLog(shader, infoLength, NULL, buf);
  free(buf);
}

uint32_t ShaderLoader::loadShader(int32_t shaderType,
                                  const string shaderSourceStr) {
  const char *shaderSource = shaderSourceStr.c_str();
  // In this function 0 is and error
  int error = 0;

  // glCreateShader return 0 when there is an error
  uint32_t shader = glCreateShader(shaderType);
  if (!shader) {
    return error;
  }

  glShaderSource(shader, 1, &shaderSource, NULL);
  glCompileShader(shader);

  if (isCompilationOk(shader)) {
    return shader;
  }

  showShaderInfoLog(shader);
  glDeleteShader(shader);

  return error;
}
