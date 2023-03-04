#include "ObjectDrawer.hpp"

void ObjectDrawer::draw(vector<Object *> objects) {
  for (auto &i : objects) {
    i->draw();
  }
}

void ObjectDrawer::draw(vector<Object3D *> objects) {
  for (auto &i : objects) {
    i->draw();
  }
}
