// Copyright (c) 2022 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_OPENGL_SHADERLOADER_HPP_
#define APP_SRC_MAIN_CPP_COMMON_OPENGL_SHADERLOADER_HPP_

#include <string>

using std::string;

class ShaderLoader {
private:
  bool isCompilationOk(int32_t shader);
  int getInfoLogLength(int32_t shader);
  void showShaderInfoLog(int32_t shader);

public:
  uint32_t loadShader(int32_t shaderType, const string shaderSource);
};

#endif // APP_SRC_MAIN_CPP_COMMON_OPENGL_SHADERLOADER_HPP_
