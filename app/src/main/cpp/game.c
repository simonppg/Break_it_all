//
// Created by Simonppg on 11/6/2018.
//

#include <unistd.h>
#include <stdlib.h>

#include "game.h"
#include "colors.h"
#include "triangle.h"
#include "square.h"

#ifdef __ANDROID_NDK__
#include "android/logger.h"
#else
#include "linux/logger.h"
#endif

struct _game{
    Triangle *t;
    Square *s;
};

Game *game = NULL;

bool setupGraphics(Game *g)
{
    if(g == NULL)
        return false;

    g->t = Triangle_new(RED);
    g->s = Square_new("simple.vert", "square.frag", BLUE);

    if(g->t == NULL || g->s == NULL)
    {
        LOGE("Something went wrong!");
        return false;
    }

    return true;
}

void on_surface_created() {
    LOGI("on_surface_created");
    game = malloc(sizeof(Game));

    if(game == NULL)
        return;

    setupGraphics(game);
}

static void renderFrame()
{
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    //Triangle_draw(t2);
    Triangle_draw(game->t);
    Square_draw(game->s);
}

void on_surface_changed(int width, int height) {
    glViewport(0, 0, width, height);
}

void on_draw_frame() {
    /* Sleeping to avoid thrashing the Android log. */
    usleep(500);
    //LOGI("New Frame Ready to be Drawn!!!!");
    renderFrame();
}

bool on_touch_event()
{
    Triangle_update(game->t);
    //Triangle_update(t2);
    Square_update(game->s);
    return true;
}
