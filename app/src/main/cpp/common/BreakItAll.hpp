// Copyright (c) 2022 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_BREAKITALL_HPP_
#define APP_SRC_MAIN_CPP_COMMON_BREAKITALL_HPP_

#include <GLES3/gl3.h>
#include <iostream>
#include <string>
#include <vector>

#include "ShaderLoader.hpp"

using std::string;
using std::vector;

class BreakItAll {
private:
  Gl *gl;
  ShaderLoader *shaderLoader;
  vector<string> examples{"SandBox New", "Window", "Triangle", "Circle",
                          "orthographic"};
  GLuint createProgram(const char *vertexSource, const char *fragmentSource);
  void showProgramInfoLog(uint32_t program);

public:
  BreakItAll();
  ~BreakItAll();

  void init();
  void render();
  void resume();
  void pause();
  string *exampleList();
  void exampleList(vector<string> *);
};

#endif // APP_SRC_MAIN_CPP_COMMON_BREAKITALL_HPP_
