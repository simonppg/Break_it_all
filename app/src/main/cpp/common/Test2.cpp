// Copyright (c) 2021 - 2022 Simon Puente
#include "Test2.hpp"

#include <cstdlib>
#include <string>
#include <GLES3/gl3.h>

#include "../shared/FilesManager.hpp"
#include "Assets.hpp"
#include "Renderer.hpp"

Test2::Test2(FilesManager *filesManager) {
  renderer = Renderer();
  this->filesManager = filesManager;
  gl = new Gl();
}

Test2::~Test2() {
  delete gl;
  gl = nullptr;
}

void Test2::render() {
  gl->useProgram(programID);
  gl->clearColor(0.6f, 0.6f, 0.6f, 1.0f);
  gl->clear();

  glDrawArrays(GL_TRIANGLES, 0, 3);
  gl->useProgram(0);
}

void Test2::surfaceCreated() {
  const string vert = filesManager->loadFile(Assets::TRIANGLE_VERT);
  const string frag = filesManager->loadFile(Assets::TRIANGLE_FRAG);

  programID = renderer.createProgram(vert, frag);
  gl->useProgram(programID);
  gl->vertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vVertices);
  gl->enableVertexAttribArray(0);

  // if (vert)
  //   free(vert);
  // if (frag)
  //   free(frag);
}

void Test2::surfaceChanged(Dimension dimension) {
  gl->viewport(0, 0, dimension.getWidth(), dimension.getHeight());
}

void Test2::pause() { gl->deleteProgram(programID); }

void Test2::resume() { gl->useProgram(programID); }

void Test2::update(double dt) {}

bool Test2::events(Point2D point) { return false; }
