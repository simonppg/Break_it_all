// Copyright (c) 2022 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_RENDERER_HPP_
#define APP_SRC_MAIN_CPP_COMMON_RENDERER_HPP_

#include "DrawContext.hpp"
#include "Mesh.hpp"
#include "ShaderLoader.hpp"

class Renderer {
private:
  ShaderLoader shaderLoader;

public:
  void load_model(Mesh *pMesh);
  void draw(DrawContext *pDrawContex);
  static unsigned int loadShader(unsigned int shaderType,
                                 const char *shaderSource);
  unsigned int createProgram(const char *vertexSource,
                             const char *fragmentSource);
};

#endif // APP_SRC_MAIN_CPP_COMMON_RENDERER_HPP_
