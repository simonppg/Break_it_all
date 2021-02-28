#include "WindowManager.hpp"

static WindowManager* getWindowManger(GLFWwindow *window) {
    return (WindowManager *) glfwGetWindowUserPointer(window);
}

static void notifyCursorPosition(GLFWwindow* window, double x, double y) {
    WindowManager *manager = getWindowManger(window);
    manager->cursorPosCallback(x, y);
}

static void notifyWindowSize(GLFWwindow *window, int width, int height) {
    WindowManager *manager = getWindowManger(window);
    manager->windowSizeCallback(width, height);
}

static void notifyKey(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    WindowManager *manager = getWindowManger(window);
    manager->keyCallback(key, scancode, action, mods);
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

    return 0;
}

void WindowManager::destroyWindow() {
    glfwDestroyWindow(this->window);
    glfwTerminate();
}

bool WindowManager::shouldClose() {
    return glfwWindowShouldClose(this->window);
}

void WindowManager::pollEvents() {
    glfwPollEvents();
}

void WindowManager::refreshWindow() {
    glfwSwapBuffers(this->window);
}

void WindowManager::setCursorCallback(void (*callback)(double, double)) {
    this->cursorPosCallback = callback;
}

void WindowManager::setWindowSizeCallback(void (*callback)(int, int)) {
    this->windowSizeCallback = callback;
}

void WindowManager::setKeyCallback(void (*callback)(int, int, int, int)) {
    this->keyCallback = callback;
}

void WindowManager::setErrorCallback(void (*callback) (int, const char*)){
    glfwSetErrorCallback(callback);
}
