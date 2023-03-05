// Copyright (c) 2021 - 2022 Simon Puente
#include "SandBox.hpp"

#include <cstdlib>
#include <string>

#include "../shared/FilesManager.hpp"
#include "Assets.hpp"
#include "Dimension.hpp"
#include "Math.hpp"
#include "ObjectDrawer.hpp"
#include "Point3D.hpp"
#include "Renderer.hpp"

using glm::mat4;
using glm::vec3;

SandBox::SandBox(FilesManager *filesManager) {
  auto camera = new Camera(Dimension(), Point3D(0, 0, 40));
  gl = new Gl();
  Math math = Math();
  shaderProg =
      new ShaderProg(filesManager, Assets::SIMPLE_VERT, Assets::SIMPLE_FRAG);
  mesh = new Mesh(math.generateCube(), 8, math.generateCubeIndexs(), 36);
  renderer = new Renderer(camera);

  unsigned int seed = (unsigned int)time(NULL);
  for (auto &object : objects) {
    object = new Object(renderer, shaderProg, mesh);
    object->updateSize(Point3D(2, 1, 1));
    float x = sin(rand_r(&seed) % 20 - 10) + rand_r(&seed) % 20 - 10;
    float y = cos(rand_r(&seed) % 36 - 18) + rand_r(&seed) % 36 - 18;
    float z = tan(rand_r(&seed) % 100 + 1) + rand_r(&seed) % 100 - 10;

    Point3D position = Point3D(x, y, z);

    object->updatePosition(position);
    object->animate_y();

    this->enterScene(object);
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
  delete gl;
  gl = nullptr;
}

void SandBox::surfaceCreated() {
  gl->enable();

  shaderProg->createProgram();
  renderer->load_model(mesh);
  // TODO(simonpp): free buffers
}

void SandBox::surfaceChanged(Dimension dimension) {
  // TODO(simonpp): send dimension to camera through render
  //  camera->resize(dimension);
  gl->viewport(0, 0, dimension.getWidth(), dimension.getHeight());
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
