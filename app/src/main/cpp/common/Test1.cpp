// Copyright (c) 2022 Simon Puente
#include "Test1.hpp"

Test1::Test1() { gl = new Gl(); }

Test1::~Test1() {
  delete gl;
  gl = nullptr;
}

void Test1::surfaceCreated() {}

void Test1::surfaceChanged(Dimension dimension) {
  gl->viewport(0, 0, dimension.getWidth(), dimension.getHeight());
}

void Test1::render() {
  gl->clearColor(0.6f, 0.6f, 0.6f, 1.0f);
  gl->clear();
}

void Test1::pause() {}

void Test1::resume() {}

void Test1::update(double dt) {}

bool Test1::events(Point2D point) { return false; }
