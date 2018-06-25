#include <stdio.h>
#include <stdlib.h>

#define GLFW_INCLUDE_ES2
#include <GLFW/glfw3.h>
#include "../triangle.h"
#include "logger.h"

static const GLuint WIDTH = 800;
static const GLuint HEIGHT = 600;

Triangle *t;
GLfloat RED[] = {
        1.0f, 0.0f, 0.0f, 1.0f,
};

int main(void) {
    GLFWwindow* window;

    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    window = glfwCreateWindow(WIDTH, HEIGHT, __FILE__, NULL, NULL);
    glfwMakeContextCurrent(window);

    LOGI("GL_VERSION  : %s\n", glGetString(GL_VERSION) );
    LOGI("GL_RENDERER : %s\n", glGetString(GL_RENDERER) );

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glViewport(0, 0, WIDTH, HEIGHT);

    t = Triangle_new(RED);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

        Triangle_draw(t);

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return EXIT_SUCCESS;
}
