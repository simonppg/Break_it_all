//
// Created by simonppg on 3/28/19.
//

#include "Test1.hpp"

Test1::Test1() {}

void Test1::surfaceCreated() {}

void Test1::surfaceChanged(Dimension dimension) {
  glViewport(0, 0, dimension.getWidth(), dimension.getHeight());
}

void Test1::render() {
  glClearColor(0.6f, 0.6f, 0.6f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
}

void Test1::pause() {}

void Test1::resume() {}

void Test1::update() {}

bool Test1::events(double xpos, double ypos) { return false; }
