//
// Created by simonppg on 11/06/18.
//

#include "../game.hpp"
#include "../triangle.hpp"
#include "../square.hpp"
#include "logger.hpp"

Game *game;

#ifdef __cplusplus
extern "C" {
#endif

#include <cstdio>
#include <cstdlib>

//#define GLFW_INCLUDE_ES2
#include <GLFW/glfw3.h>

static void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos)
{
    game->on_touch_event(xpos, ypos);
}

static void error_handler(int error, const char* description)
{
    LOGE("\nError glfw: %s", description);
}

static void onSizeChange(GLFWwindow *window, int width, int height)
{
    game->surfaceChanged(width, height);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(action == GLFW_REPEAT || action == GLFW_PRESS ) {
        if (key == GLFW_KEY_W)
            game->camera_forward();
        else if (key == GLFW_KEY_S)
            game->camera_back();
        else if (key == GLFW_KEY_D)
            game->camera_right();
        else if (key == GLFW_KEY_A)
            game->camera_left();
        else if (key == GLFW_KEY_L)
            game->camera_reset();
    }
}

int main(int argc, char **argv) {
    GLFWwindow* window;
    int test_number = 0;

    LOGI("%d", argc);
    if(argc > 1)
    {
        test_number = atoi(argv[1]);
    }
    LOGI("%d", test_number);

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

    if(game) {
        delete game;
        game = nullptr;
    }

    assert(game == nullptr);
    game = Game::init(test_number);

    game->surfaceCreated();

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        game->update();
        game->render();

        glfwSwapBuffers(window);
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return EXIT_SUCCESS;
}

#ifdef __cplusplus
}
#endif
