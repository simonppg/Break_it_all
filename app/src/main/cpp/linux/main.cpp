#include "../common/EventFactory.hpp"
#include "../common/Game.hpp"
#include "../shared/FilesManager.hpp"
#include "../shared/Logger.hpp"
#include "../shared/Platform.hpp"
#include "LinuxPlatform.hpp"
#include "WindowManager.hpp"
#include "logger.hpp"

Game *game = nullptr;

#include <cstdio>
#include <cstdlib>

class App {
public:
  void start(int sceneNumber) {
    Platform *platform = new LinuxPlatform();
    FilesManager *filesManager = platform->filesManager();
    Logger *logger = platform->logger();

    logger->logi(filesManager->loadFile("simple.frag"));

    const int WINDOW_WIDTH = 450;
    const int WINDOW_HEIGHT = 800;
    WindowManager *wm = new WindowManager();

    LOGI("%d", sceneNumber);

    if (wm->createWindow(WINDOW_WIDTH, WINDOW_HEIGHT) != 0) {
      LOGE("Window can not be created");
      exit(EXIT_FAILURE);
    }

    wm->setCursorCallback([](double xpos, double ypos) -> void {
      EventFactory eventFactory = EventFactory();
      auto event = eventFactory.cursorPositionChanged(xpos, ypos);
      game->dispatchEvent(&event);
    });

    wm->setErrorCallback([](int error, const char *description) -> void {
      LOGE("\nError glfw: %s", description);
    });

    wm->setWindowSizeCallback([](int width, int height) -> void {
      game->surfaceChanged(width, height);
    });

    wm->setKeyCallback([](int key, int scancode, int action, int mods) -> void {
      if (action == GLFW_REPEAT || action == GLFW_PRESS) {
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
    });

    game = Game::init(sceneNumber, platform);

    game->surfaceCreated();

    while (!wm->shouldClose()) {
      wm->pollEvents();

      game->update();
      game->render();

      wm->refreshWindow();
    }

    wm->destroyWindow();
  }
};

int main(int argc, char **argv) {
  int sceneNumber = 0;

  if (argc > 1) {
    sceneNumber = atoi(argv[1]);
  }

  App().start(sceneNumber);

  return EXIT_SUCCESS;
}
