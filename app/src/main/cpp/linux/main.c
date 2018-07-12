//
// Created by simonppg on 11/06/18.
//

#include <stdio.h>
#include <stdlib.h>

#define GLFW_INCLUDE_ES2
#include <GLFW/glfw3.h>

#include "../game.h"
#include "../triangle.h"
#include "../square.h"
#include "logger.h"

static const GLuint WIDTH = 800;
static const GLuint HEIGHT = 600;

static void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos)
{
    on_touch_event();
}

int main(void) {
    GLFWwindow* window;

    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    window = glfwCreateWindow(WIDTH, HEIGHT, __FILE__, NULL, NULL);
    glfwMakeContextCurrent(window);

    LOGI("\nGL_VERSION  :");
    LOGI((char *)glGetString(GL_VERSION));
    LOGI("\nGL_RENDERER :");
    LOGI((char *)glGetString(GL_RENDERER));

    glfwSetCursorPosCallback(window, cursor_pos_callback);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glViewport(0, 0, WIDTH, HEIGHT);

    on_surface_created();

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

        on_draw_frame();

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return EXIT_SUCCESS;
}
