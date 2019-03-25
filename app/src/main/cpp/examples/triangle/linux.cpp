#include "triangle.hpp"

#include <GLFW/glfw3.h>
#include <utils.hpp>
#include <filesManager.hpp>

int main() {
    GLFWwindow* window;
    GLuint programID;
    char *vert, *frag;


    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    window = glfwCreateWindow(450, 800, __FILE__, NULL, NULL);
    glfwMakeContextCurrent(window);

    surfaceCreated();

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        render();

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
