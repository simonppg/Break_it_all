// Copyright (c) 2022 Simon Puente
#include "Gl.hpp"
#include <GLES3/gl3.h>

Gl::Gl() {}

Gl::~Gl() {}

void Gl::useProgram(unsigned int programID) { glUseProgram(programID); }
