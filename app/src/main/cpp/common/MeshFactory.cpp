#include "MeshFactory.hpp"
#include "Math.hpp"

Mesh* MeshFactory::circle(float radius, int numberOfVertices) {
  auto math = new Math();
  auto circle = math->generateCircle(radius, numberOfVertices);
  return new Mesh(circle, numberOfVertices);
}
