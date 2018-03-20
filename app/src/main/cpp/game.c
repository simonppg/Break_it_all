//
// Created by Simonppg on 11/4/2017.
//

#include <jni.h>
#include <GLES2/gl2.h>
#include <stdlib.h>
#include <unistd.h>
#include <android/log.h>

#include "game.h"
#include "utils.h"
#include "triangle.h"

static const char glVertexShader[] =
        "attribute vec4 vPosition;\n"
        "void main()\n"
        "{\n"
        "  gl_Position = vPosition;\n"
        "}\n";

static const char glFragmentShaderRed[] =
        "precision mediump float;\n"
        "void main()\n"
        "{\n"
        "  gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);\n"
        "}\n";

static const char glFragmentShaderBlue[] =
        "precision mediump float;\n"
        "void main()\n"
        "{\n"
        "  gl_FragColor = vec4(0.0, 0.0, 1.0, 1.0);\n"
        "}\n";

const GLfloat triangleVertices[] = {
        0.0f, 0.5f,
        -0.5f, -0.5f,
        0.5f, -0.5f
};

GLuint simpleTriangleProgram;
GLuint vPosition;
Triangle *t;

static bool setupGraphics()
{
    simpleTriangleProgram = createProgram(glVertexShader, glFragmentShaderRed);
    if (!simpleTriangleProgram)
    {
        LOGE ("Could not create program");
        return false;
    }
    vPosition = (GLuint) glGetAttribLocation(simpleTriangleProgram, "vPosition");

    t = Triangle_new(glVertexShader, glFragmentShaderBlue);

    if(!t)
    {
        LOGE ("Could not create Triangle");
        return false;
    }
    return true;
}

static void renderFrame()
{
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    Triangle_draw(t);

    glUseProgram(simpleTriangleProgram);
    glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 0 ,triangleVertices);
    glEnableVertexAttribArray(vPosition);
    glDrawArrays(GL_TRIANGLES, 0, 3);
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
    return true;
}