// Copyright (c) 2021 Simon Puente
#include "SandBox.hpp"

#include <cstdlib>
#include <string>

#include "../shared/FilesManager.hpp"
#include "Assets.hpp"
#include "Dimension.hpp"
#include "Math.hpp"
#include "Point3D.hpp"
#include "Renderer.hpp"

using glm::mat4;
using glm::vec3;

SandBox::SandBox(FilesManager *filesManager, Camera *camera) {
  const string vertexFileStr = filesManager->loadFile(Assets::SIMPLE_VERT);
  const string fragmentFileStr = filesManager->loadFile(Assets::SIMPLE_FRAG);
  this->camera = camera;
  Math math = Math();
  shaderProg = new ShaderProg(vertexFileStr, fragmentFileStr);
  mesh = new Mesh(math.generateCube(), 8, math.generateCubeIndexs(), 36);
  renderer = new Renderer();

  unsigned int seed = (unsigned int)time(NULL);
  for (auto &object : objects) {
    object = new Object(shaderProg, mesh);
    object->updateSize(Point3D(2, 1, 1));
    float x = sin(rand_r(&seed) % 20 - 10) + rand_r(&seed) % 20 - 10;
    float y = cos(rand_r(&seed) % 36 - 18) + rand_r(&seed) % 36 - 18;
    float z = tan(rand_r(&seed) % 100 + 1) + rand_r(&seed) % 100 - 10;

    Point3D position = Point3D(x, y, z);

    object->updatePosition(position);
    object->animate_y();
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
  delete renderer;
  renderer = nullptr;
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
    i->draw(camera);
  }
}

void SandBox::surfaceChanged(Dimension dimension) {
  camera->resize(dimension);
  glViewport(0, 0, dimension.getWidth(), dimension.getHeight());
}

void SandBox::pause() {}

void SandBox::resume() {}

void SandBox::update(double dt) {
  for (auto &i : objects) {
    i->set_rotation_angle(povInDegrees);
  }
}

bool SandBox::events(Point2D point) {
  povInDegrees += 5.0f;
  return true;
}
