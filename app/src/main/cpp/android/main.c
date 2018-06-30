//
// Created by Simonppg on 11/4/2017.
//

#include <unistd.h>

#include "main.h"
#include "../utils.h"
#include "../triangle.h"
#include "../square.h"
#include "../colors.h"

#include "logger.h"

Triangle *t;//, *t2;
Square *s;
AAssetManager *g_pAssetManager = NULL;

static bool setupGraphics()
{
    t = Triangle_new(RED);
    //t2 = Triangle_new(BLUE);

    if(!t)
    {
        LOGE ("Could not create Triangle");
        return false;
    }

    /*if(!t2)
      {
      LOGE ("Could not create Triangle");
      return false;
      }*/

    s = Square_new("simple.vert", "square.frag", BLUE);
    if(!s)
    {
        LOGE ("Could not create Square");
        return false;
    }
    return true;
}

static void renderFrame()
{
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    //Triangle_draw(t2);
    Triangle_draw(t);
    Square_draw(s);
}

void on_surface_created() {
    LOGI("on_surface_created");
    setupGraphics();
}

void on_surface_changed(int width, int height) {
    glViewport(0, 0, width, height);
}

void on_draw_frame() {
    /* Sleeping to avoid thrashing the Android log. */
    usleep(500);
    LOGI("New Frame Ready to be Drawn!!!!");
    renderFrame();
}

bool on_touch_event()
{
    Triangle_update(t);
    //Triangle_update(t2);
    Square_update(s);
    return true;
}

void load_asset_manager(AAssetManager *pAssetManager)
{
    g_pAssetManager = pAssetManager;
}
