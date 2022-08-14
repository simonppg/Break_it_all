// Copyright (c) 2022 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_RENDERER_HPP_
#define APP_SRC_MAIN_CPP_COMMON_RENDERER_HPP_

#include <cstdint>
#include <string>

#include "DrawContext.hpp"
#include "Mesh.hpp"
#include "ShaderLoader.hpp"
#include "opengl/Gl.hpp"

using std::string;

class Renderer {
private:
  ShaderLoader *shaderLoader;
  Gl *gl;

  void showProgramInfoLog(uint32_t program);

public:
  Renderer();
  ~Renderer();

  void load_model(Mesh *pMesh);
  void draw(DrawContext *pDrawContex);
  static unsigned int loadShader(unsigned int shaderType,
                                 const string shaderSource);
  unsigned int createProgram(const string vertexSource,
                             const string fragmentSource);
};

#endif // APP_SRC_MAIN_CPP_COMMON_RENDERER_HPP_
