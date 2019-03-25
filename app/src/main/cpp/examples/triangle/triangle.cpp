#include "triangle.hpp"

#include "../../utils.hpp"
#include <GLES3/gl3.h>
#include <cassert>

#ifdef __ANDROID_NDK__
#include "../../android/filesManager.hpp"
#include "../../android/logger.hpp"
#else
#include "../../linux/filesManager.hpp"
#include "../../linux/logger.hpp"
#endif

GLfloat vVertices[] = { 0.0f, 0.5f, 0.0f,
                        -0.5f, -0.5f, 0.0f,
                        0.5f, -0.5f, 0.0f };

#ifdef __ANDROID_NDK__
void init(void *data) {
    g_pAssetManager = (AAssetManager *) data;
}
#else
void init(void *data) {}
#endif

void surfaceCreated() {
    GLuint programID;
    char *vert, *frag;

    vert = load_file("examples/triangle/triangle.vert");
    frag = load_file("examples/triangle/triangle.frag");
    glViewport(0, 0, 450, 800);
    programID = createProgram(vert, frag);
    glUseProgram(programID);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vVertices);
    glEnableVertexAttribArray(0);
}

void surfaceChanged(int w, int h) {
    glViewport(0, 0, w, h);
}

void update() {}

void render() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.6f, 0.6f, 0.6f, 1.0f);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void pause() {}

void resume() {}