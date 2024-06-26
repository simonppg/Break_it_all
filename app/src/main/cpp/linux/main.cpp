#include "game.hpp"
#include "logger.hpp"
#include "WindowManager.hpp"
#include "LinuxLogger.hpp"

Game *game;


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
    Logger * logger = new LinuxLogger();

    logger->sayHello();
    logger->logi("SurfaceCreated");
    logger->logi("%s","SurfaceCreated2");
    logger->logi("%s %d %s %f","aInt:", 15, "aFloat:", 123.123);
    std::string str = "This is a better test, print std::string str";
    logger->logi(str);
    int val = 101;
    logger->logi("%d", val);
    float pi = 3.1416f;
    logger->logi("%f", pi);
    const char *c_str = "a C string, const char*";
    logger->logi("%s", c_str);
    char aChar ='A';
    logger->logi(aChar);
     logger->logi("%s", c_str);
     logger->logi("%s %d", c_str, val);
     logger->logi("%s %d %f", c_str, val, pi);
     logger->logi("%s", "myNewStr");
     logger->logi("%s %d", "myNewStr", val);
     logger->logi("%s %d %f", "myNewStr", val, pi);
     logger->logi("%s %c", "myNewStr", 'F');
     logger->logi("%s %d %c", "myNewStr", val, 'F');
     logger->logi("%s %d %f %c", "myNewStr", val, pi, 'F');
     logger->logi("%c %s", 'R',c_str);
     logger->logi("%c %s %d", 'R',c_str, val);
     logger->logi("%c %s %d %f", 'R',c_str, val, pi);


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
    game = Game::init(test_number, new LinuxLogger());

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

