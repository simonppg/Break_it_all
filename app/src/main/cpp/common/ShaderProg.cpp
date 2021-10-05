#include "ShaderProg.hpp"
#include "Renderer.hpp"

ShaderProg::ShaderProg(const char *vertShaderStr, const char *fragShaderStr) {
  vertex_file = vertShaderStr;
  fragment_file = fragShaderStr;
  renderer = Renderer();
}

void ShaderProg::createProgram() {
  programID = renderer.createProgram(vertex_file, fragment_file);
}
