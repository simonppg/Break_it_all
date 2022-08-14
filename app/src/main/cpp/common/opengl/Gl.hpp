// Copyright (c) 2022 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_OPENGL_GL_HPP_
#define APP_SRC_MAIN_CPP_COMMON_OPENGL_GL_HPP_

#include <cstdint>
#include <optional>
#include <string>

using std::optional;
using std::string;

class Gl {
public:
  Gl();
  ~Gl();

  optional<uint32_t> createProgram();
  void useProgram(uint32_t program);
  bool isProgramLinkOk(uint32_t program);
  int32_t getProgramInfoLength(uint32_t program);
  string getProgramInfoLog(uint32_t program, int32_t infoLogLength);

  optional<uint32_t> createShader(int32_t shaderType);
  bool isShaderCompilationOk(uint32_t shader);
  int32_t getInfoLogLength(uint32_t shader);
  string getShaderInfoLog(uint32_t shader, int32_t infoLogLength);

  void genBuffer(uint32_t *buffer);
  void bindBuffer(int32_t bufferBindingTarget, uint32_t buffer);
};

#endif // APP_SRC_MAIN_CPP_COMMON_OPENGL_GL_HPP_
