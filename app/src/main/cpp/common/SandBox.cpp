// Copyright (c) 2021 Simon Puente
#include "SandBox.hpp"

#include "../shared/FilesManager.hpp"
#include "Dimension.hpp"
#include "Math.hpp"
#include "Point3D.hpp"

using glm::mat4;
using glm::vec3;

float pov_in_degrees = 0.0f;

SandBox::SandBox(FilesManager *filesManager) {
  const char *vertexFileStr = filesManager->loadFile("simple.vert");
  const char *fragmentFileStr = filesManager->loadFile("simple.frag");
  camera = new Camera(Dimension(), Point3D(0, 0, 40));
  shaderProgs[0] = new ShaderProg(vertexFileStr, fragmentFileStr);
  meshes[0] = new Mesh(math->get_cube(), 8, math->get_cube_index(), 36);

  for (auto &i : objects) {
    i = new Object(camera, shaderProgs[0], meshes[0]);
    i->update_size(2, 1, 1);
    Point3D position = Point3D(sin(rand() % 20 - 10) + rand() % 20 - 10,
                               cos(rand() % 36 - 18) + rand() % 36 - 18,
                               tan(rand() % 100 + 1) + rand() % 100 - 10);

    i->updatePosition(position);
    i->animate_y();
  }
}

void SandBox::surfaceCreated() {
  glEnable(GL_DEPTH_TEST);

  shaderProgs[0]->createProgram();
  for (auto &i : meshes) {
    renderer->load_model(i);
  }
  // TODO(simonpp): free buffers
}

void SandBox::render() {
  glClearColor(0.6f, 0.6f, 0.6f, 1.0f);
  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

  for (auto &i : objects) {
    i->draw();
  }
}

void SandBox::surfaceChanged(int width, int height) {
  this->camera->updateDimension(Dimension(width, height));
  glViewport(0, 0, width, height);
}

void SandBox::pause() {}

void SandBox::resume() {}

void SandBox::update() {
  for (auto &i : objects) {
    i->set_rotation_angle(pov_in_degrees);
  }
}

bool SandBox::events(double xpos, double ypos) {
  pov_in_degrees += 5.0f;
  return true;
}
