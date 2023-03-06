#ifndef APP_SRC_MAIN_CPP_COMMON_OPENGL_SHADERLOADER_HPP_
#define APP_SRC_MAIN_CPP_COMMON_OPENGL_SHADERLOADER_HPP_

#include <string>

#include "Gl.hpp"

using std::string;

class ShaderLoader {
private:
  Gl gl;

  void showShaderInfoLog(int32_t shader);
  uint32_t loadShader(int32_t shaderType, const string shaderSource);

public:
  uint32_t loadVertexShader(const string shaderSource);
  uint32_t loadFragmentShader(const string shaderSource);
};

#endif // APP_SRC_MAIN_CPP_COMMON_OPENGL_SHADERLOADER_HPP_
