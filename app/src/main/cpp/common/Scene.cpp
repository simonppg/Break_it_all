// Copyright (c) 2023 Simon Puente
#include "Scene.hpp"
#include "ObjectDrawer.hpp"

void Scene::render() {
  gl.clearColor(0.6f, 0.6f, 0.6f, 1.0f);
  gl.clear();

  ObjectDrawer::draw(drawableObjects);
}

void Scene::enterScene(DrawableObject *drawableObject) {
  drawableObjects.push_back(drawableObject);
}
