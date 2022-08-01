// Copyright (c) 2021 Simon Puente
#include "Test2.hpp"

#include <cstdlib>

#include "../shared/FilesManager.hpp"
#include "Renderer.hpp"

static GLfloat vVertices[] = {0.0f, 0.5f, 0.0f,  -0.5f, -0.5f,
                              0.0f, 0.5f, -0.5f, 0.0f};
Test2::Test2(FilesManager *filesManager) {
  renderer = Renderer();
  this->filesManager = filesManager;
}

void Test2::render() {
  glUseProgram(programID);
  glClearColor(0.6f, 0.6f, 0.6f, 1.0f);
  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

  glDrawArrays(GL_TRIANGLES, 0, 3);
  glUseProgram(0);
}

void Test2::surfaceCreated() {
  char *vert, *frag;

  vert = filesManager->loadFile("examples/triangle/triangle.vert");
  frag = filesManager->loadFile("examples/triangle/triangle.frag");

  programID = renderer.createProgram(vert, frag);
  glUseProgram(programID);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vVertices);
  glEnableVertexAttribArray(0);

  if (vert)
    free(vert);
  if (frag)
    free(frag);
}

void Test2::surfaceChanged(Dimension dimension) {
  glViewport(0, 0, dimension.getWidth(), dimension.getHeight());
}

void Test2::pause() { glDeleteProgram(programID); }

void Test2::resume() { glUseProgram(programID); }

void Test2::update() {}

bool Test2::events(double xpos, double ypos) { return false; }
