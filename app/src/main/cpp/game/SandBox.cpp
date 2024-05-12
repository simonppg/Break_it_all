#include "SandBox.hpp"

#include <cstdlib>
#include <string>

#include "../eventbus/KeyPressed.hpp"
#include "../platform/FilesManager.hpp"
#include "Assets.hpp"
#include "Dimension.hpp"
#include "Math.hpp"
#include "ObjectDrawer.hpp"
#include "Point3D.hpp"
#include "Renderer.hpp"

using glm::mat4;
using glm::vec3;

SandBox::SandBox(Platform *platform)
    : Scene(platform) {
  auto camera = new Camera(Dimension(), Point3D(0, 0, 40));
  gl = new Gl();
  Math math = Math();
  shaderProg =
      new ShaderProg(platform->filesManager(), Assets::SIMPLE_VERT, Assets::SIMPLE_FRAG);
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

  bus = platform->bus();

  bus->subcribe(EventType::SCREEN_TOUCHED,
                [=](Event *event) -> void { povInDegrees += 5.0f; });
  bus->subcribe(EventType::CURSOR_POSITION_CHANGED,
                [=](Event *event) -> void { povInDegrees += 5.0f; });
  bus->subcribe(EventType::KEY_PRESSED, [=](Event *event2) -> void {
    KeyPressed *event = reinterpret_cast<KeyPressed *>(event2);
    Key key = event->key();
    PressState pressState = event->pressState();

    if (pressState == PressState::KEY_PRESSED ||
        pressState == PressState::KEY_HOLDED) {
      if (key == Key::W_KEY) {
        Point3D cameraPosition = camera->getPosition();
        camera->travel(cameraPosition.decrementZ(1));
      } else if (key == Key::S_KEY) {
        Point3D cameraPosition = camera->getPosition();
        camera->travel(cameraPosition.incrementZ(1));
      } else if (key == Key::D_KEY) {
        Point3D cameraPosition = camera->getPosition();
        camera->travel(cameraPosition.incrementX(1));
      } else if (key == Key::A_KEY) {
        Point3D cameraPosition = camera->getPosition();
        camera->travel(cameraPosition.decrementX(1));
      } else if (key == Key::L_KEY) {
        camera->travel(Point3D());
      }
    }
  });
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

void SandBox::surfaceChanged() {
  // TODO(simonpp): send dimension to camera through render
  //  camera->resize(dimension);
}

void SandBox::pause() {}

void SandBox::resume() {}

void SandBox::update(double dt) {
  for (auto &i : objects) {
    i->set_rotation_angle(povInDegrees);
  }
}
