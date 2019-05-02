//
// Created by simonppg on 4/25/19.
//

#ifndef BREAK_IT_ALL_CONTEXT_HPP
#define BREAK_IT_ALL_CONTEXT_HPP

#include <glm/glm.hpp>

using glm::mat4;

class DrawContext {

public:
    unsigned int programID;
    int type;
    unsigned int vbo;
    unsigned int iab;
    const void *vertex;
    int32_t numIndices;
    mat4 matrix_transform;
    int32_t numVertices;
    short *indices;
};

#endif //BREAK_IT_ALL_CONTEXT_HPP
