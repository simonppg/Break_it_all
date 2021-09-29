#ifndef COMMON_SHADERPROG_HPP
#define COMMON_SHADERPROG_HPP

#include "Renderer.hpp"

class ShaderProg {
private:
    Renderer renderer;

public:
    ShaderProg(const char *vertShaderPath, const char *fragShaderPath);

    char *vertex_file;
    char *fragment_file;

    void createProgram();

    unsigned int programID;
};

#endif // COMMON_SHADERPROG_HPP
