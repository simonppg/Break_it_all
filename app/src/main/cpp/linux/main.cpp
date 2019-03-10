//
// Created by simonppg on 11/06/18.
//

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>

#define GLFW_INCLUDE_ES2
#include <GLFW/glfw3.h>

#include "../game.hpp"
#include "../triangle.hpp"
#include "../square.hpp"
#include "logger.hpp"

static const GLuint WIDTH = 800;
static const GLuint HEIGHT = 600;

static void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos)
{
    on_touch_event();
}

static void error_handler(int error, const char* description)
{
    LOGE("\nError glfw:");
    LOGE(description);
}

static void onSizeChange(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
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

    LOGI("\nGL_VERSION  :");
    LOGI((char *)glGetString(GL_VERSION));
    LOGI("\nGL_RENDERER :");
    LOGI((char *)glGetString(GL_RENDERER));

    glfwSetCursorPosCallback(window, cursor_pos_callback);
    glfwSetErrorCallback(error_handler);
    glfwSetWindowSizeCallback(window, onSizeChange);

    on_surface_created();

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        on_draw_frame();

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return EXIT_SUCCESS;
}

#ifdef __cplusplus
}
#endif