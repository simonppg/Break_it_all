// Copyright (c) 2021 Simon Puente
#include "WindowManager.hpp"

WindowManager::WindowManager(void *appContext)
    : appContext(appContext), cursorPosCallback(NULL), windowSizeCallback(NULL),
      keyCallback(NULL) {}

void *WindowManager::getAppContext() { return appContext; }

WindowManager *WindowManager::getWindowManger(GLFWwindow *window) {
  return (WindowManager *)glfwGetWindowUserPointer(window);
}

void WindowManager::notifyCursorPosition(GLFWwindow *window, double x,
                                         double y) {
  WindowManager *manager = getWindowManger(window);

  if (manager->cursorPosCallback != NULL) {
    manager->cursorPosCallback(manager->getAppContext(), x, y);
  }
}

void WindowManager::notifyWindowSize(GLFWwindow *window, int width,
                                     int height) {
  WindowManager *manager = getWindowManger(window);

  if (manager->windowSizeCallback != NULL) {
    manager->windowSizeCallback(manager->getAppContext(), width, height);
  }
}

void WindowManager::notifyKey(GLFWwindow *window, int key, int scancode,
                              int action, int mods) {
  WindowManager *manager = getWindowManger(window);

  if (manager->keyCallback != NULL) {
    manager->keyCallback(manager->getAppContext(), key, scancode, action, mods);
  }
}

void WindowManager::errorCallback(int error, const char *description) {
  // TODO: handle error here
}

int WindowManager::createWindow(int width, int height) {
  if (!glfwInit()) {
    return -1;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

  this->window = glfwCreateWindow(width, height, __FILE__, NULL, NULL);

  if (!this->window) {
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(this->window);
  glfwSwapInterval(1);

  glfwSetWindowUserPointer(this->window, this);
  glfwSetCursorPosCallback(this->window, notifyCursorPosition);
  glfwSetWindowSizeCallback(this->window, notifyWindowSize);
  glfwSetKeyCallback(this->window, notifyKey);
  glfwSetErrorCallback(this->errorCallback);

  return 0;
}

void WindowManager::destroyWindow() {
  glfwDestroyWindow(this->window);
  glfwTerminate();
}

bool WindowManager::shouldClose() {
  return glfwWindowShouldClose(this->window);
}

void WindowManager::pollEvents() { glfwPollEvents(); }
void WindowManager::refreshWindow() { glfwSwapBuffers(this->window); }

void WindowManager::setCursorCallback(CursorPosCallback callback) {
  cursorPosCallback = callback;
}
void WindowManager::setWindowSizeCallback(WindowSizeCallback callback) {
  windowSizeCallback = callback;
}
void WindowManager::setKeyCallback(KeyCallback callback) {
  keyCallback = callback;
}
