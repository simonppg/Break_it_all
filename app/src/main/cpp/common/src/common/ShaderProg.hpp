//
// Created by simonppg on 4/23/19.
//

#ifndef BREAK_IT_ALL_SHADERPROG_HPP
#define BREAK_IT_ALL_SHADERPROG_HPP
#include "utils.hpp"

class ShaderProg {
public:
    ShaderProg(const char *vertShaderPath, const char *fragShaderPath);

    char *vertex_file;
    char *fragment_file;

    void createProgram();

    GLuint programID;
};

#endif //BREAK_IT_ALL_SHADERPROG_HPP
