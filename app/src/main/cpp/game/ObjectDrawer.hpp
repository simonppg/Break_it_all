#ifndef APP_SRC_MAIN_CPP_GAME_OBJECTDRAWER_HPP_
#define APP_SRC_MAIN_CPP_GAME_OBJECTDRAWER_HPP_
#include <vector>

#include "DrawableObject.hpp"
#include "Object.hpp"
#include "Object3D.hpp"

using std::vector;

class ObjectDrawer {
public:
  static void draw(vector<DrawableObject *>);
};
#endif // APP_SRC_MAIN_CPP_GAME_OBJECTDRAWER_HPP_
