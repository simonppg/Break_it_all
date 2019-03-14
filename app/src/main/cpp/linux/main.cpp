//
// Created by simonppg on 11/06/18.
//

#include "../game.hpp"
#include "../triangle.hpp"
#include "../square.hpp"
#include "logger.hpp"

#ifdef __cplusplus
extern "C" {
#endif

#include <cstdio>
#include <cstdlib>

//#define GLFW_INCLUDE_ES2
#include <GLFW/glfw3.h>

static void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos)
{
    on_touch_event(xpos, ypos);
}

static void error_handler(int error, const char* description)
{
    LOGE("\nError glfw: %s", description);
}

static void onSizeChange(GLFWwindow *window, int width, int height)
{
    on_surface_changed(width, height);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(action == GLFW_REPEAT || action == GLFW_PRESS ) {
        if (key == GLFW_KEY_W)
            camera_forward();
        else if (key == GLFW_KEY_S)
            camera_back();
        else if (key == GLFW_KEY_D)
            camera_rigth();
        else if (key == GLFW_KEY_A)
            camera_left();
    }
}

int main(void) {
    GLFWwindow* window;

    if (!glfwInit())
    {
        LOGE("glfwInit failed");
        exit(EXIT_FAILURE);
    }
    //glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    window = glfwCreateWindow(WIDTH, HEIGHT, __FILE__, NULL, NULL);
    if (!window)
    {
        LOGE("Window or OpenGL context creation failed");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    glfwSetCursorPosCallback(window, cursor_pos_callback);
    glfwSetErrorCallback(error_handler);
    glfwSetWindowSizeCallback(window, onSizeChange);
    glfwSetKeyCallback(window, key_callback);

    on_surface_created();

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        on_draw_frame();

        glfwSwapBuffers(window);
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return EXIT_SUCCESS;
}

#ifdef __cplusplus
}
#endif