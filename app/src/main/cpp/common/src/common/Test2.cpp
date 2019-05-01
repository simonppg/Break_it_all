//
// Created by simonppg on 3/27/19.
//

#include "Test2.hpp"

#include <cstdlib>

static GLfloat vVertices[] = { 0.0f, 0.5f, 0.0f,
                               -0.5f, -0.5f, 0.0f,
                               0.5f, -0.5f, 0.0f };
Test2::Test2() {

}

void Test2::render() {
    glUseProgram(programID);
    glClearColor(0.6f, 0.6f, 0.6f, 1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    glDrawArrays(GL_TRIANGLES, 0, 3);
    glUseProgram(0);
}

void Test2::surfaceCreated() {
    char *vert, *frag;

    vert = load_file("examples/triangle/triangle.vert");
    frag = load_file("examples/triangle/triangle.frag");
    programID = Utils::createProgram(vert, frag);
    glUseProgram(programID);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vVertices);
    glEnableVertexAttribArray(0);

    if (vert)
        free(vert);
    if (frag)
        free(frag);
}

void Test2::surfaceChanged(int width, int height) {
    glViewport(0, 0, width, height);
}

void Test2::pause() {
    glDeleteProgram(programID);
}

void Test2::resume() {
    glUseProgram(programID);
}

void Test2::update() {}

bool Test2::events(double xpos, double ypos) {
    return false;
}
