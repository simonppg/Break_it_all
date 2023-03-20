#include "Scene.hpp"
#include "ObjectDrawer.hpp"

Scene::Scene(Platform *platform) { this->platform = platform; }

void Scene::render() {
  gl.clearColor(0.6f, 0.6f, 0.6f, 1.0f);
  gl.clear();

  ObjectDrawer::draw(drawableObjects);
}

void Scene::enterScene(DrawableObject *drawableObject) {
  drawableObjects.push_back(drawableObject);
}
