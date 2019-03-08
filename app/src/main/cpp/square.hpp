//
// Created by simonppg on 21/03/18.
//

#ifdef __cplusplus
extern "C" {
#endif

#ifndef BREAK_IT_ALL_SQUARE_H
#define BREAK_IT_ALL_SQUARE_H

#include <GLES3/gl3.h>
#include "utils.hpp"

struct _Square
{
    GLfloat * vertices;
    GLuint numVertices;
    GLushort* indices;
    GLuint numIndices;
};

typedef struct _Square Square;

Square* Square_new(const char* vertex_file_path, const char* fragment_file_path, GLfloat *color);
void Square_draw(Square *t);
void Square_update(Square *t);

#endif //BREAK_IT_ALL_SQUARE_H

#ifdef __cplusplus
}
#endif