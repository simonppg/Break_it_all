// Copyright (c) 2021 Simon Puente
#ifndef GLFW_KEY_MAPPER_HPP
#define GLFW_KEY_MAPPER_HPP

#include "../common/Key.hpp"
#include <map>

using std::map;

class GLFWKeyMapper {
private:
  map<int, Key> keyMap;
  map<int, PressState> pressStateMap;

public:
  GLFWKeyMapper();

  Key mapKey(int key);
  PressState mapPressState(int action);
};

#endif // GLFW_KEY_MAPPER_HPP
