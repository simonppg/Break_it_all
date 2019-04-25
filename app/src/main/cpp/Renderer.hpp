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
};

#endif //BREAK_IT_ALL_RENDERER_HPP
