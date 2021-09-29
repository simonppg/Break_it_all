#ifndef _BREAK_IT_ALL_H_
#define _BREAK_IT_ALL_H_

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

#endif //_BREAK_IT_ALL_H_
