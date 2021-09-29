#ifndef COMMON_BREAK_IT_ALL_HPP
#define COMMON_BREAK_IT_ALL_HPP

#include <string.h>
#include <iostream>
#include <vector>
#include "ShaderLoader.hpp"

using namespace std;

class BreakItAll {
private:
    ShaderLoader shaderLoader = ShaderLoader();
    std::vector<std::string> examples {"SandBox New", "Window", "Triangle", "Circle", "orthographic"};
    GLuint createProgram(const char* vertexSource, const char * fragmentSource);

public:
    void init();
    void render();
    void resume();
    void pause();
    string* exampleList();
    void exampleList(vector<string>*);
};

#endif // COMMON_BREAK_IT_ALL_HPP
