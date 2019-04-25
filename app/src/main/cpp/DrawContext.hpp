//
// Created by simonppg on 4/25/19.
//

#ifndef BREAK_IT_ALL_CONTEXT_HPP
#define BREAK_IT_ALL_CONTEXT_HPP

#include <GLES3/gl3.h>
#include <glm/glm.hpp>

using glm::mat4;

class DrawContext {

public:
    GLuint programID;
    int type;
    GLuint vbo;
    GLuint iab;
    const void *vertex;
    GLsizei numIndices;
    mat4 matrix_transform;
    GLsizei numVertices;
    short *indices;
};

#endif //BREAK_IT_ALL_CONTEXT_HPP
