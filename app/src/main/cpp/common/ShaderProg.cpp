// Copyright (c) 2021 Simon Puente
#include "ShaderProg.hpp"
#include "Renderer.hpp"

ShaderProg::ShaderProg(const string vertShaderStr, const string fragShaderStr) {
  vertex_file = vertShaderStr;
  fragment_file = fragShaderStr;
  renderer = Renderer();
}

void ShaderProg::createProgram() {
  programID = renderer.createProgram(vertex_file, fragment_file);
}
