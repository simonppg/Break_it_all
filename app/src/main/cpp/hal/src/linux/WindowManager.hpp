#ifndef BREAK_IT_ALL_WINDOW_MANAGER_H
#define BREAK_IT_ALL_WINDOW_MANAGER_H

#include <GLFW/glfw3.h>

class WindowManager {
private:
    GLFWwindow* window;
public:
    int createWindow(int width, int height);
    void destroyWindow();
    bool shouldClose();
    void pollEvents();
    void refreshWindow();
    void cursorCallback();
    void setCursorCallback(void (*callback) (double, double));
    void (*cursorPosCallback) (double, double);
    void setWindowSizeCallback(void (*callback) (int, int));
    void (*windowSizeCallback) (int, int);
    void setKeyCallback(void (*callback) (int, int, int, int));
    void (*keyCallback) (int, int, int, int);
    void setErrorCallback(void (*callback) (int, const char*));
    void (*errorCallback) (int, const char*);
};

#endif //BREAK_IT_ALL_WINDOW_MANAGER_H
