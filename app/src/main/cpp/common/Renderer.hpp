#ifndef APP_SRC_MAIN_CPP_COMMON_RENDERER_HPP_
#define APP_SRC_MAIN_CPP_COMMON_RENDERER_HPP_

#include <cstdint>
#include <string>

#include "Camera.hpp"
#include "DrawContext.hpp"
#include "Mesh.hpp"
#include "ShaderLoader.hpp"
#include "opengl/Gl.hpp"

using glm::mat4;
using std::string;

class Renderer {
private:
  ShaderLoader shaderLoader;
  Gl gl;
  Camera *camera;

  void showProgramInfoLog(uint32_t program);
  void typeOneMesh(const Mesh *, const mat4, const int32_t);
  void typeTwoMesh(const Mesh *, const mat4, const int32_t);

public:
  explicit Renderer(Camera *);
  ~Renderer();

  mat4 trasform(Point3D, float, Point3D, Point3D);
  void load_model(Mesh *pMesh);
  void draw(DrawContext *pDrawContex);
  static unsigned int loadShader(unsigned int shaderType,
                                 const string shaderSource);
  uint32_t createProgram(const string vertexSource,
                         const string fragmentSource);
};

#endif // APP_SRC_MAIN_CPP_COMMON_RENDERER_HPP_
