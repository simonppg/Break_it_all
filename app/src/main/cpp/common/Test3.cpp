// Copyright (c) 2021 Simon Puente
#include "Test3.hpp"

#include <GLES3/gl3.h>

#include <cstdint>
#include <string>
#include <vector>

#include "../shared/FilesManager.hpp"
#include "Assets.hpp"
#include "Dimension.hpp"
#include "Math.hpp"
#include "Point3D.hpp"
#include "Renderer.hpp"

Test3::Test3(FilesManager *filesManager, Camera *camera) {
  float RADIUS = 0.5;
  this->camera = camera;
  circle = math->generateCircle(RADIUS, NUMBER_OF_VERTICES);
  renderer = Renderer();
  this->filesManager = filesManager;
  gl = new Gl();
}

Test3::~Test3() {
  delete gl;
  gl = nullptr;
}

void Test3::render() {
  int32_t uniform;
  mat4 translate;
  mat4 rotate;
  mat4 scale;

  gl->useProgram(programID);
  uniform = glGetUniformLocation(programID, "matrix");

  gl->clearColor(0.6f, 0.6f, 0.6f, 1.0f);
  gl->clear();

  gl->enableVertexAttribArray(0);

  translate = camera->translate(Point3D(1, 0, 0));
  rotate = glm::rotate(translate, glm::radians(0.0f), vec3(1, 0, 0));
  scale = glm::scale(rotate, glm::vec3(5));
  glUniformMatrix4fv(uniform, 1, GL_FALSE, &scale[0][0]);

  glDrawArrays(GL_TRIANGLE_FAN, 0, NUMBER_OF_VERTICES);

  gl->useProgram(0);
}

void Test3::surfaceCreated() {
  const string vert = filesManager->loadFile(Assets::TRIANGLE_VERT);
  const string frag = filesManager->loadFile(Assets::TRIANGLE_FRAG);
  programID = renderer.createProgram(vert, frag);

  gl->bindBuffer(GL_ARRAY_BUFFER, 0);
  gl->vertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, circle);

  // if (vert)
  //   free(vert);
  // if (frag)
  //   free(frag);
}

void Test3::surfaceChanged(Dimension dimension) {
  gl->viewport(0, 0, dimension.getWidth(), dimension.getHeight());
}

void Test3::pause() { gl->deleteProgram(programID); }

void Test3::resume() { gl->useProgram(programID); }

void Test3::update(double dt) {}

bool Test3::events(Point2D point) { return false; }
