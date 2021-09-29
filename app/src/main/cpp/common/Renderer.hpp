#ifndef COMMON_RENDERER_HPP
#define COMMON_RENDERER_HPP

#include "Mesh.hpp"
#include "DrawContext.hpp"

class Renderer {
public:
    void load_model(Mesh *pMesh);
    void draw(DrawContext *pDrawContex);
    static unsigned int loadShader(unsigned int shaderType, const char *shaderSource);
    static unsigned int createProgram(const char *vertexSource, const char *fragmentSource);
};

#endif // COMMON_RENDERER_HPP
