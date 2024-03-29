#ifndef APP_SRC_MAIN_CPP_LINUXAPP_GLFWKEYMAPPER_HPP_
#define APP_SRC_MAIN_CPP_LINUXAPP_GLFWKEYMAPPER_HPP_

#include <map>

#include "../eventbus/Key.hpp"

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

#endif // APP_SRC_MAIN_CPP_LINUXAPP_GLFWKEYMAPPER_HPP_
