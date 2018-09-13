//
// Created by simonppg on 11/06/18.
//

#ifdef __cplusplus
extern "C" {
#endif

#ifndef GAME_H
#define GAME_H

#include <stdbool.h>

typedef struct _game Game;

void on_surface_created();
void on_draw_frame();
bool on_touch_event();
void on_surface_changed(int width, int height);

#endif //GAME_H

#ifdef __cplusplus
}
#endif