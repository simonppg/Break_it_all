// Copyright (c) 2022 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_OPENGL_GL_HPP_
#define APP_SRC_MAIN_CPP_COMMON_OPENGL_GL_HPP_

#include <cstdint>
#include <string>

using std::string;

class Gl {
public:
  Gl();
  ~Gl();

  void useProgram(unsigned int);
  bool isShaderCompilationOk(int32_t shader);
  int32_t getInfoLogLength(int32_t shader);
  string getInfoLog(int32_t shader, int32_t infoLogLength);
};

#endif // APP_SRC_MAIN_CPP_COMMON_OPENGL_GL_HPP_
