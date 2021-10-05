#ifndef COMMON_SHADERPROG_HPP
#define COMMON_SHADERPROG_HPP

#include "Renderer.hpp"

class ShaderProg {
private:
  Renderer renderer;
  const char *vertex_file;
  const char *fragment_file;

public:
  ShaderProg(const char *vertShaderStr, const char *fragShaderStr);

  void createProgram();

  unsigned int programID;
};

#endif // COMMON_SHADERPROG_HPP
