#include "Ball.hpp"

Ball::Ball(MeshFactory *meshFactory, Renderer *renderer, ShaderProg *pProg) {
  this->renderer = renderer;
  this->program = pProg;
  float radius = 1.0;
  int numberOfVertices = 15;
  mesh = meshFactory->circle(radius, numberOfVertices);
  position = Point3D();
  rotation = Point3D(1, 1, 1);
  size = Point3D(15, 15, 1);
}

Ball::~Ball() {}

void Ball::draw() {
  mat4 trasformed = renderer->trasform(position, angle, rotation, size);

  auto *drawContext = new DrawContext(program, trasformed, mesh);

  renderer->draw(drawContext);
}
