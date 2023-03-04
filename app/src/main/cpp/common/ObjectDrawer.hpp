// Copyright (c) 2023 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_OBJECTDRAWER_HPP_
#define APP_SRC_MAIN_CPP_COMMON_OBJECTDRAWER_HPP_
#include <vector>

#include "Object.hpp"
#include "Object3D.hpp"

using std::vector;

class ObjectDrawer {
public:
  static void draw(vector<Object *>);
  static void draw(vector<Object3D *>);
};
#endif // APP_SRC_MAIN_CPP_COMMON_OBJECTDRAWER_HPP_
