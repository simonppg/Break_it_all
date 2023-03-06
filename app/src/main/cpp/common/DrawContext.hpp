#ifndef APP_SRC_MAIN_CPP_COMMON_DRAWCONTEXT_HPP_
#define APP_SRC_MAIN_CPP_COMMON_DRAWCONTEXT_HPP_

#include "Mesh.hpp"
#include "ShaderProg.hpp"
#include <glm/glm.hpp>

using glm::mat4;

class DrawContext {
private:
  ShaderProg *program;
  Mesh *mesh;
  mat4 matrixTransform;

public:
  DrawContext(ShaderProg *program, mat4 trasformed, Mesh *mesh);

  ShaderProg *getProgram();
  Mesh *getMesh();
  mat4 getMatrixTransform();
};

#endif // APP_SRC_MAIN_CPP_COMMON_DRAWCONTEXT_HPP_
