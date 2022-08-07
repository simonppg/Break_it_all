// Copyright (c) 2021 Simon Puente
#include "SandBox.hpp"

#include <cstdlib>

#include "../shared/FilesManager.hpp"
#include "Dimension.hpp"
#include "Math.hpp"
#include "Point3D.hpp"

using glm::mat4;
using glm::vec3;

float pov_in_degrees = 0.0f;
unsigned int seed = time(NULL);

SandBox::SandBox(FilesManager *filesManager) {
  const char *vertexFileStr = filesManager->loadFile("simple.vert");
  const char *fragmentFileStr = filesManager->loadFile("simple.frag");
  camera = new Camera(Dimension(), Point3D(0, 0, 40));
  shaderProg = new ShaderProg(vertexFileStr, fragmentFileStr);
  mesh = new Mesh(math->get_cube(), 8, math->get_cube_index(), 36);

  for (auto &i : objects) {
    i = new Object(shaderProg, mesh);
    i->updateSize(Point3D(2, 1, 1));
    float x = sin(rand_r(&seed) % 20 - 10) + rand_r(&seed) % 20 - 10;
    float y = cos(rand_r(&seed) % 36 - 18) + rand_r(&seed) % 36 - 18;
    float z = tan(rand_r(&seed) % 100 + 1) + rand_r(&seed) % 100 - 10;

    Point3D position = Point3D(x, y, z);

    i->updatePosition(position);
    i->animate_y();
  }
}

SandBox::~SandBox() {
  for (auto &object : objects) {
    delete object;
    object = nullptr;
  }
  delete mesh;
  mesh = nullptr;
  delete shaderProg;
  shaderProg = nullptr;
  delete camera;
  camera = nullptr;
}

void SandBox::surfaceCreated() {
  glEnable(GL_DEPTH_TEST);

  shaderProg->createProgram();
  renderer->load_model(mesh);
  // TODO(simonpp): free buffers
}

void SandBox::render() {
  glClearColor(0.6f, 0.6f, 0.6f, 1.0f);
  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

  for (auto &i : objects) {
    i->draw(camera->cameraTranslate);
  }
}

void SandBox::surfaceChanged(Dimension dimension) {
  this->camera->updateDimension(dimension);
  glViewport(0, 0, dimension.getWidth(), dimension.getHeight());
}

void SandBox::pause() {}

void SandBox::resume() {}

void SandBox::update(double dt) {
  for (auto &i : objects) {
    i->set_rotation_angle(pov_in_degrees);
  }
}

bool SandBox::events(Point2D point) {
  pov_in_degrees += 5.0f;
  return true;
}
