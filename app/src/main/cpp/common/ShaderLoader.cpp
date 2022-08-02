// Copyright (c) 2022 Simon Puente
#include "ShaderLoader.hpp"
#include <malloc.h>

bool ShaderLoader::isCompilationOk(GLenum shader) {
  GLint compiled = 0;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
  return compiled;
}

int ShaderLoader::getInfoLogLength(GLenum shader) {
  GLint infoLen = 0;
  glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);
  return infoLen;
}

void ShaderLoader::showShaderInfoLog(GLenum shader) {
  int infoLength = getInfoLogLength(shader);
  if (!infoLength) {
    return;
  }

  char *buf = (char *)malloc(sizeof(char) * infoLength);
  if (!buf) {
    return;
  }

  glGetShaderInfoLog(shader, infoLength, NULL, buf);
  // LOGE("%s", buf);
  free(buf);
}

GLuint ShaderLoader::loadShader(GLenum shaderType, const char *shaderSource) {
  // In this function 0 is and error
  int error = 0;

  // glCreateShader return 0 when there is an error
  GLuint shader = glCreateShader(shaderType);
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
