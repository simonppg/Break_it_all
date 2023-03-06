#include "GLFWKeyMapper.hpp"

#include <GLFW/glfw3.h>

#include "../common/Key.hpp"

GLFWKeyMapper::GLFWKeyMapper() {
  keyMap = {{GLFW_KEY_W, Key::W_KEY}, {GLFW_KEY_A, Key::A_KEY},
            {GLFW_KEY_S, Key::S_KEY}, {GLFW_KEY_D, Key::D_KEY},
            {GLFW_KEY_L, Key::L_KEY}, {GLFW_KEY_ESCAPE, Key::ESCAPE_KEY}};

  pressStateMap = {{GLFW_PRESS, PressState::KEY_PRESSED},
                   {GLFW_REPEAT, PressState::KEY_HOLDED},
                   {GLFW_RELEASE, PressState::KEY_RELEASED}};
}

Key GLFWKeyMapper::mapKey(int key) {
  Key myKey;

  auto keyFound = keyMap.find(key);
  if (keyFound != keyMap.end()) {
    myKey = keyFound->second;
  } else {
    myKey = Key::UNKNOWN;
  }

  return myKey;
}

PressState GLFWKeyMapper::mapPressState(int action) {
  PressState pressState;

  auto pressStateFound = pressStateMap.find(action);
  if (pressStateFound != pressStateMap.end()) {
    pressState = pressStateFound->second;
  } else {
    pressState = PressState::UNKNOWN;
  }

  return pressState;
}
