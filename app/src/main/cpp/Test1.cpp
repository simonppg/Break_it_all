//
// Created by simonppg on 3/28/19.
//

#include "Test1.hpp"

Test1::Test1() {

}

void Test1::surfaceCreated() {
}

void Test1::surfaceChanged(int width, int height) {
    glViewport(0, 0, width, height);
}

void Test1::render() {
    glClearColor(0.6f, 0.6f, 0.6f, 1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
}
