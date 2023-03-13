#ifndef APP_SRC_MAIN_CPP_COMMON_SHADERPROG_HPP_
#define APP_SRC_MAIN_CPP_COMMON_SHADERPROG_HPP_

#include <iostream>
#include <string>

#include "../shared/platform/FilesManager.hpp"
#include "ShaderLoader.hpp"
#include "opengl/Gl.hpp"

using std::string;

class ShaderProg final {
private:
  static Gl gl;
  ShaderLoader shaderLoader;
  string vertexFile;
  string fragmentFile;
  uint32_t programID;

  uint32_t createProgramm(const string vertexSource,
                          const string fragmentSource);
  void showProgramInfoLog(uint32_t program);

public:
  ShaderProg(FilesManager *, const string vertShaderStr,
             const string fragShaderStr);

  void createProgram();
  void use();
  uint32_t getUniformLocation(string uniformName);

  static void clearProgram();
};

#endif // APP_SRC_MAIN_CPP_COMMON_SHADERPROG_HPP_
