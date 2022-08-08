// Copyright (c) 2021 Simon Puente
#include "WindowManager.hpp"
#include "WindowCanNotBeCreated.hpp"

WindowManager::WindowManager(void *appContext)
    : appContext(appContext), cursorPosCallback(NULL), windowSizeCallback(NULL),
      keyCallback(NULL) {}

void *WindowManager::getAppContext() { return appContext; }

WindowManager *WindowManager::getWindowManger(GLFWwindow *window) {
  return reinterpret_cast<WindowManager *>(glfwGetWindowUserPointer(window));
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
  // TODO(simonpp): handle error here
}

void WindowManager::createWindow(int width, int height) {
  if (!glfwInit()) {
    throw WindowCanNotBeCreated();
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

  window = glfwCreateWindow(width, height, __FILE__, NULL, NULL);

  if (!window) {
    glfwTerminate();
    throw WindowCanNotBeCreated();
  }

  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);

  glfwSetWindowUserPointer(window, this);
  glfwSetCursorPosCallback(window, notifyCursorPosition);
  glfwSetWindowSizeCallback(window, notifyWindowSize);
  glfwSetKeyCallback(window, notifyKey);
  glfwSetErrorCallback(errorCallback);
}

void WindowManager::destroyWindow() {
  glfwDestroyWindow(window);
  glfwTerminate();
}

bool WindowManager::shouldClose() {
  return glfwWindowShouldClose(window);
}

void WindowManager::pollEvents() { glfwPollEvents(); }
void WindowManager::refreshWindow() { glfwSwapBuffers(window); }

void WindowManager::setCursorCallback(CursorPosCallback callback) {
  cursorPosCallback = callback;
}
void WindowManager::setWindowSizeCallback(WindowSizeCallback callback) {
  windowSizeCallback = callback;
}
void WindowManager::setKeyCallback(KeyCallback callback) {
  keyCallback = callback;
}
