#include <sstream>

#include "../eventbus/KeyPressed.hpp"
#include "../eventbus/SurfaceChanged.hpp"
#include "ObjectDrawer.hpp"
#include "Scene.hpp"

Scene::Scene(Platform *platform) {
  this->platform = platform;
  this->bus = platform->bus();
  this->logger = platform->logger();

  this->bus->subcribe(EventType::KEY_PRESSED, [=](Event *event) -> void {
    KeyPressed *keyPressed = reinterpret_cast<KeyPressed *>(event);
    Key key = keyPressed->key();
    PressState pressState = keyPressed->pressState();

    if (pressState == PressState::KEY_PRESSED ||
        pressState == PressState::KEY_HOLDED) {
      if (key == Key::ESCAPE_KEY) {
        // close();
      }
    }
  });

  this->bus->subcribe(EventType::SURFACE_CHANGED, [=](Event *event) -> void {
    auto realEvent = reinterpret_cast<SurfaceChanged *>(event);

    Dimension dimension = Dimension(realEvent->width(), realEvent->height());
    std::stringstream sstream;
    sstream << dimension;
    logger->logi(sstream.str());

    surfaceChanged(dimension);
  });
}

void Scene::render() {
  gl.clearColor(0.6f, 0.6f, 0.6f, 1.0f);
  gl.clear();

  ObjectDrawer::draw(drawableObjects);
}

void Scene::enterScene(DrawableObject *drawableObject) {
  drawableObjects.push_back(drawableObject);
}
