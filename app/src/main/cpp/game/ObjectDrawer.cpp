#include "ObjectDrawer.hpp"

void ObjectDrawer::draw(vector<DrawableObject *> objects) {
  for (auto &i : objects) {
    i->draw();
  }
}
