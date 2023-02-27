// Copyright (c) 2023 Simon Puente
#include "DrawContext.hpp"

DrawContext::DrawContext(ShaderProg *program, mat4 trasformed, Mesh *mesh) {
  this->program = program;
  this->matrixTransform = trasformed;
  this->mesh = mesh;
}

ShaderProg *DrawContext::getProgram() { return program; }

Mesh *DrawContext::getMesh() { return mesh; }

mat4 DrawContext::getMatrixTransform() { return matrixTransform; }
