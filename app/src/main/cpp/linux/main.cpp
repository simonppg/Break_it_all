//
// Created by simonppg on 11/06/18.
//

#include "game.hpp"
#include "logger.hpp"
#include "WindowManager.hpp"

Game *game;

#ifdef __cplusplus
extern "C" {
#endif

#include <cstdio>
#include <cstdlib>

static void cursor_pos_callback(double xpos, double ypos)
{
    game->on_touch_event(xpos, ypos);
}

static void error_handler(int error, const char* description)
{
    LOGE("\nError glfw: %s", description);
}

static void onSizeChange(int width, int height)
{
    game->surfaceChanged(width, height);
}

static void key_callback(int key, int scancode, int action, int mods)
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
    const int WINDOW_WIDTH = 450;
    const int WINDOW_HEIGHT = 800;
    WindowManager *wm = new WindowManager();

    int test_number = 0;

    LOGI("%d", argc);
    if(argc > 1)
    {
        test_number = atoi(argv[1]);
    }
    LOGI("%d", test_number);

    if(wm->createWindow(WINDOW_WIDTH, WINDOW_HEIGHT) != 0) {
        LOGE("Window can not be created");
        exit(EXIT_FAILURE);
    }

    wm->setCursorCallback(cursor_pos_callback);
    wm->setErrorCallback(error_handler);
    wm->setWindowSizeCallback(onSizeChange);
    wm->setKeyCallback(key_callback);

    if(game) {
        delete game;
        game = nullptr;
    }

    assert(game == nullptr);
    game = Game::init(test_number);

    game->surfaceCreated();

    while (!wm->shouldClose()) {
        wm->pollEvents();

        game->update();
        game->render();

        wm->refreshWindow();
    }

    wm->destroyWindow();

    return EXIT_SUCCESS;
}

#ifdef __cplusplus
}
#endif
