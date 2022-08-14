// Copyright (c) 2022 Simon Puente
#include "Gl.hpp"
#include <GLES3/gl3.h>
#include <vector>

using std::vector;

Gl::Gl() {}

Gl::~Gl() {}

void Gl::useProgram(uint32_t program) { glUseProgram(program); }

bool Gl::isProgramLinkOk(uint32_t program) {
  GLint linkStatus = GL_FALSE;
  glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);
  return linkStatus == GL_TRUE;
}

int32_t Gl::getProgramInfoLength(uint32_t program) {
  int32_t infoLogLength = 0;
  glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);
  return infoLogLength;
}

string Gl::getProgramInfoLog(uint32_t program, int32_t infoLogLength){
  vector<char> buffer(infoLogLength);
  glGetProgramInfoLog(program, infoLogLength, NULL, buffer.data());
  string infoLog(begin(buffer), end(buffer));
  return infoLog;
}

bool Gl::isShaderCompilationOk(uint32_t shader) {
  GLint compilationStatus = GL_FALSE;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &compilationStatus);
  return compilationStatus == GL_TRUE;
}

int32_t Gl::getInfoLogLength(uint32_t shader) {
  int32_t infoLogLength = 0;
  glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);
  return infoLogLength;
}

string Gl::getShaderInfoLog(uint32_t shader, int32_t infoLogLength) {
  vector<char> buffer(infoLogLength);
  glGetShaderInfoLog(shader, infoLogLength, NULL, buffer.data());
  string infoLog(begin(buffer), end(buffer));
  return infoLog;
}
