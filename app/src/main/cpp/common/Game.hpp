#ifndef GAME_H
#define GAME_H

#include "IScene.hpp"
#include "../shared/Platform.hpp"
#include "../shared/Logger.hpp"
#include "../shared/FilesManager.hpp"

class Game {
private:
    Platform *platform;
    Logger *logger;
    FilesManager *fileManager;

public:
    Game(IScene *pScene, Platform *platform);

    IScene *pScene;

    static Game * init(int, Platform *platform);

    // OpenGL context is in this functions
    void surfaceCreated();
    void surfaceChanged(int width, int height);
    void update();
    void render();
    void pause();
    void resume();
    void camera_forward();
    void camera_back();
    void camera_left();
    void camera_right();
    void camera_reset();
    bool on_touch_event(double xpos, double ypos);
};

#endif // GAME_H
