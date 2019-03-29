//
// Created by simonppg on 11/06/18.
//

#ifndef BREAK_IT_ALL_GAME_H
#define BREAK_IT_ALL_GAME_H

#include "Triangle.hpp"
#include "square.hpp"
#include "Cube.hpp"
#include "IScene.hpp"

class Game
{
public:
    Game(int pos, IScene *pScene);

    Triangle *t;
    Square *s;
    float cube2[3];
    IScene *pScene;

    Cube *cube[15][15];
    Camera *camera;

    static Game * init(int);

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

#ifdef __cplusplus
extern "C" {
#endif

bool on_touch_event(double xpos, double ypos);


#ifdef __cplusplus
}
#endif

#endif //BREAK_IT_ALL_GAME_H
