//
// Created by simonppg on 19/03/18.
//

#ifdef __cplusplus
extern "C" {
#endif

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "utils.hpp"

struct _Triangle
{
    GLfloat * vertices;
    GLuint numVertices;
    GLushort* indices;
    GLuint numIndices;
};

typedef struct _Triangle Triangle;

Triangle* Triangle_new(GLfloat *color);
void Triangle_draw(Triangle *t);
void Triangle_update(Triangle *t);

#endif //TRIANGLE_H

#ifdef __cplusplus
}
#endif