//
// Created by simonppg on 4/25/19.
//

#ifndef BREAK_IT_ALL_RENDERER_HPP
#define BREAK_IT_ALL_RENDERER_HPP

#include "Mesh.hpp"
#include "DrawContext.hpp"

class Renderer {
public:
    void load_model(Mesh *pMesh);
    void draw(DrawContext *pDrawContex);
    static unsigned int loadShader(unsigned int shaderType, const char *shaderSource);
    static unsigned int createProgram(const char *vertexSource, const char *fragmentSource);
};

#endif //BREAK_IT_ALL_RENDERER_HPP
