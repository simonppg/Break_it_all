#ifndef GLFW_KEY_MAPPER_H
#define GLFW_KEY_MAPPER_H

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

#endif // GLFW_KEY_MAPPER_H
