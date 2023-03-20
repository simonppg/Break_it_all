#include "Ball.hpp"

Ball::Ball(MeshFactory *meshFactory) {
  float radius = 1.0;
  int numberOfVertices = 15;
  mesh = meshFactory->circle(radius, numberOfVertices);
}

Ball::~Ball() {}

void Ball::draw() {}
