// Copyright (c) 2022 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_BREAKITALL_HPP_
#define APP_SRC_MAIN_CPP_COMMON_BREAKITALL_HPP_

#include <iostream>
#include <string>
#include <vector>

#include "ShaderLoader.hpp"

using std::string;
using std::vector;

class BreakItAll {
private:
  ShaderLoader shaderLoader = ShaderLoader();
  vector<string> examples{"SandBox New", "Window", "Triangle",
                                    "Circle", "orthographic"};
  GLuint createProgram(const char *vertexSource, const char *fragmentSource);

public:
  void init();
  void render();
  void resume();
  void pause();
  string *exampleList();
  void exampleList(vector<string> *);
};

#endif // APP_SRC_MAIN_CPP_COMMON_BREAKITALL_HPP_
