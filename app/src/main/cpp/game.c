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

static void sendDataToOpenGL()
{
    Triangle *tri = Triangle_new(RED);
    Square *sqr = Square_new("simple.vert", "square.frag", BLUE);

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

}

bool setupGraphics(Game *g)
{
    if(g == NULL)
        return false;

    sendDataToOpenGL();
    programID = createProgram(glVertexShader, glFragmentShader);
    glUseProgram(programID);

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
