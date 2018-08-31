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

static const char glVertexShader[] =
    "attribute vec4 vPosition;\n"
    "attribute vec4 vColor;\n"
    "varying vec4 v_Color;\n"
    "void main()\n"
    "{\n"
    "  gl_Position = vec4(vPosition);\n"
       "v_Color = vColor;\n"
    "}\n";

static const char glFragmentShader[] =
    "precision mediump float;\n"
    "varying vec4 v_Color;\n"
    "void main()\n"
    "{\n"
    "  gl_FragColor = v_Color;\n"
    "}\n";

GLuint programID;

GLuint vertexBufferID;
GLuint indexArrayBufferID;

GLuint vertexBufferID2;
GLuint indexArrayBufferID2;

static Game* Game_new()
{
    Game *ret;

    ret = malloc(sizeof(Game));

    if(ret == NULL)
        return NULL;

    ret->t = Triangle_new(RED);
    ret->s = Square_new("simple.vert", "square.frag", BLUE);

    if(ret->t == NULL || ret->s == NULL)
    {
        LOGE("Something went wrong!");
        return NULL;
    }

    return ret;
}

static void sendDataToOpenGL(Game *g)
{
    Triangle *tri;
    Square *sqr;

    if (g == NULL)
        return;

    tri = g->t;
    sqr = g->s;

    // Triangle
    glGenBuffers(1, &vertexBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
    glBufferData(GL_ARRAY_BUFFER, VERTEX_BUFFER_SIZE(tri->numVertices), tri->vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glGenBuffers(1, &indexArrayBufferID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexArrayBufferID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, INDEX_BUFFER_SIZE(tri->numIndices), tri->indices, GL_STATIC_DRAW);

    // Square
    glGenBuffers(1, &vertexBufferID2);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID2);
    glBufferData(GL_ARRAY_BUFFER, VERTEX_BUFFER_SIZE(sqr->numVertices), sqr->vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &indexArrayBufferID2);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexArrayBufferID2);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, INDEX_BUFFER_SIZE(sqr->numIndices), sqr->indices, GL_STATIC_DRAW);

    // TODO: free buffers
}

static bool setupGraphics(Game *g)
{
    sendDataToOpenGL(g);
    programID = createProgram(glVertexShader, glFragmentShader);
    glUseProgram(programID);

    return true;
}

static void renderFrame()
{
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Square
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID2);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (char*)(sizeof(float) * 3));
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexArrayBufferID2);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);

    // Triangle
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (char*)(sizeof(float) * 3));
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexArrayBufferID);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, 0);
}

void on_surface_created() {
    LOGI("on_surface_created");

    Game *game = Game_new();
    setupGraphics(game);
    // TODO: free game
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
    return true;
}
