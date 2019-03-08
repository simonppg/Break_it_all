#include <GLFW/glfw3.h>

int main(void) {
    GLFWwindow* window;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    window = glfwCreateWindow(600, 600, __FILE__, NULL, NULL);
    glfwMakeContextCurrent(window);


    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.6f, 0.6f, 0.6f, 1.0f);


        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
