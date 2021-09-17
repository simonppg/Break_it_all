#ifndef _BREAK_IT_ALL_H_
#define _BREAK_IT_ALL_H_

#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

class BreakItAll {
private:
    std::vector<std::string> examples {"SandBox New", "Window", "Triangle", "Circle", "orthographic"};
public:
    void init();
    void render();
    void resume();
    void pause();
    string* exampleList();
    void exampleList(vector<string>*);
};

#endif //_BREAK_IT_ALL_H_