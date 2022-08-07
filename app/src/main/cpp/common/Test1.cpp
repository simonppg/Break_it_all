// Copyright (c) 2022 Simon Puente
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

void Test1::terminate() {}

void Test1::pause() {}

void Test1::resume() {}

void Test1::update(double dt) {}

bool Test1::events(Point2D point) { return false; }
