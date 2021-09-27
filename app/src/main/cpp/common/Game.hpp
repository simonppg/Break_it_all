#ifndef GAME_H
#define GAME_H

#include "IScene.hpp"
#include "../shared/Platform.hpp"
#include "../shared/Logger.hpp"
#include "../shared/FilesManager.hpp"
#include "Event.hpp"
#include "CursorPositionChanged.hpp"
#include "KeyPressed.hpp"

class Game {
private:
    Platform *platform;
    Logger *logger;
    FilesManager *fileManager;

    void camera_forward();
    void camera_back();
    void camera_left();
    void camera_right();

    void cursorPositionChangedHanlder(CursorPositionChanged *event);
    void keyPressedHandler(KeyPressed *event);

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
    void camera_reset();
    void dispatchEvent(Event *event);
};

#endif // GAME_H
