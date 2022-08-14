// Copyright (c) 2022 Simon Puente
#include "Gl.hpp"
#include <GLES3/gl3.h>
#include <vector>

using std::vector;

Gl::Gl() {}

Gl::~Gl() {}

void Gl::useProgram(unsigned int programID) { glUseProgram(programID); }

bool Gl::isShaderCompilationOk(int32_t shader) {
  GLint compilationStatus = GL_FALSE;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &compilationStatus);
  return compilationStatus == GL_TRUE;
}

int32_t Gl::getInfoLogLength(int32_t shader) {
  int32_t infoLogLength = 0;
  glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);
  return infoLogLength;
}

string Gl::getInfoLog(int32_t shader, int32_t infoLogLength) {
  vector<char> buffer(infoLogLength);
  glGetShaderInfoLog(shader, infoLogLength, NULL, buffer.data());
  string infoLog(begin(buffer), end(buffer));
  return infoLog;
}
