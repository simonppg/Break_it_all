// Copyright (c) 2022 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_OPENGL_GL_HPP_
#define APP_SRC_MAIN_CPP_COMMON_OPENGL_GL_HPP_

#include <cstdint>
#include <string>
#include <optional>

using std::string;
using std::optional;

class Gl {
public:
  Gl();
  ~Gl();

  void useProgram(uint32_t program);
  bool isProgramLinkOk(uint32_t program);
  int32_t getProgramInfoLength(uint32_t program);
  string getProgramInfoLog(uint32_t program, int32_t infoLogLength);

  optional<uint32_t> createShader(int32_t shaderType);
  bool isShaderCompilationOk(uint32_t shader);
  int32_t getInfoLogLength(uint32_t shader);
  string getShaderInfoLog(uint32_t shader, int32_t infoLogLength);
};

#endif // APP_SRC_MAIN_CPP_COMMON_OPENGL_GL_HPP_
