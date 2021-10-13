// Copyright (c) 2021 Simon Puente
#ifndef WINDOW_MANAGER_HPP
#define WINDOW_MANAGER_HPP

#include <GLFW/glfw3.h>

typedef void (*CursorPosCallback)(void *appContext, double, double);
typedef void (*WindowSizeCallback)(void *appContext, int, int);
typedef void (*KeyCallback)(void *appContext, int, int, int, int);

class WindowManager {
private:
  GLFWwindow *window;
  void *appContext;

  CursorPosCallback cursorPosCallback;
  WindowSizeCallback windowSizeCallback;
  KeyCallback keyCallback;

  static WindowManager *getWindowManger(GLFWwindow *window);
  static void notifyCursorPosition(GLFWwindow *window, double x, double y);
  static void notifyWindowSize(GLFWwindow *window, int width, int height);
  static void notifyKey(GLFWwindow *window, int key, int scancode, int action,
                        int mods);
  static void errorCallback(int, const char *);

public:
  WindowManager(void *appContext);

  void *getAppContext();
  bool shouldClose();

  void setCursorCallback(CursorPosCallback);
  void setWindowSizeCallback(WindowSizeCallback);
  void setKeyCallback(KeyCallback);

  int createWindow(int width, int height);
  void destroyWindow();
  void pollEvents();
  void refreshWindow();
};

#endif // WINDOW_MANAGER_HPP
