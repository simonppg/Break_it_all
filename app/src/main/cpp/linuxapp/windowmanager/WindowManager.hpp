#ifndef APP_SRC_MAIN_CPP_LINUXAPP_WINDOWMANAGER_WINDOWMANAGER_HPP_
#define APP_SRC_MAIN_CPP_LINUXAPP_WINDOWMANAGER_WINDOWMANAGER_HPP_

#include <GLFW/glfw3.h>

#include "WindowCanNotBeCreated.hpp"

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
  explicit WindowManager(void *appContext);

  void *getAppContext();
  bool shouldClose();

  void setCursorCallback(CursorPosCallback);
  void setWindowSizeCallback(WindowSizeCallback);
  void setKeyCallback(KeyCallback);

  void createWindow(int width, int height);
  void destroyWindow();
  void pollEvents();
  void refreshWindow();
};

#endif // APP_SRC_MAIN_CPP_LINUXAPP_WINDOWMANAGER_WINDOWMANAGER_HPP_
