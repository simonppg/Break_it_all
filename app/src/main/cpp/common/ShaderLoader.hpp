// Copyright (c) 2022 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_SHADERLOADER_HPP_
#define APP_SRC_MAIN_CPP_COMMON_SHADERLOADER_HPP_

class ShaderLoader {
private:
  bool isCompilationOk(GLenum shader);
  int getInfoLogLength(GLenum shader);

  void showShaderInfoLog(GLenum shader);

public:
  GLuint loadShader(GLenum shaderType, const char *shaderSource);
};

#endif // APP_SRC_MAIN_CPP_COMMON_SHADERLOADER_HPP_
