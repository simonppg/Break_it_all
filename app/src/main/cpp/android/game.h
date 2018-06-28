//
// Created by Simonppg on 11/4/2018
//

#ifndef BREAK_IT_ALL_GAME_H
#define BREAK_IT_ALL_GAME_H

#include <stdbool.h>
#include <android/asset_manager.h>

void on_surface_created();
void on_surface_changed(int width, int height);
void on_draw_frame();
bool on_touch_event();
void load_asset_manager(AAssetManager *assetManager);

#endif //BREAK_IT_ALL_GAME_H
