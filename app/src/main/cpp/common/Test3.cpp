// Copyright (c) 2021 Simon Puente
#include "Test3.hpp"

#include <string>
#include <vector>

#include "../shared/FilesManager.hpp"
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
}

void Test3::render() {
  GLint uniform;
  mat4 translate;
  mat4 rotate;
  mat4 scale;

  glUseProgram(programID);
  uniform = glGetUniformLocation(programID, "matrix");

  glClearColor(0.6f, 0.6f, 0.6f, 1.0f);
  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

  glEnableVertexAttribArray(0);

  translate = glm::translate(camera->cameraTranslate, vec3(0, 0, 0));
  rotate = glm::rotate(translate, glm::radians(0.0f), vec3(1, 0, 0));
  scale = glm::scale(rotate, glm::vec3(5));
  glUniformMatrix4fv(uniform, 1, GL_FALSE, &scale[0][0]);

  glDrawArrays(GL_TRIANGLE_FAN, 0, NUMBER_OF_VERTICES);

  glUseProgram(0);
}

void Test3::surfaceCreated() {
  const string vert = filesManager->loadFile("examples/triangle/triangle.vert");
  const string frag = filesManager->loadFile("examples/triangle/triangle.frag");
  programID = renderer.createProgram(vert, frag);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, circle);

  // if (vert)
  //   free(vert);
  // if (frag)
  //   free(frag);
}

void Test3::surfaceChanged(Dimension dimension) {
  glViewport(0, 0, dimension.getWidth(), dimension.getHeight());
}

void Test3::pause() { glDeleteProgram(programID); }

void Test3::resume() { glUseProgram(programID); }

void Test3::update(double dt) {}

bool Test3::events(Point2D point) { return false; }
