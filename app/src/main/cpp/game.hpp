//
// Created by simonppg on 11/06/18.
//

#include "triangle.hpp"
#include "square.hpp"
#include "Cube.hpp"

class Game
{
public:
    Triangle *t;
    Square *s;
    float camera[3];
    float cube2[3];

    int w, h;
    void renderFrame();
    void sendDataToOpenGL();
    Game();

    Cube *cube;
};

#ifdef __cplusplus
extern "C" {
#endif

#ifndef GAME_H
#define GAME_H

//#include <stdbool.h>

void on_surface_created();
void on_draw_frame();
bool on_touch_event();
void on_surface_changed(int width, int height);
void camera_forward();
void camera_back();
void camera_left();
void camera_rigth();

#endif //GAME_H

#ifdef __cplusplus
}
#endif