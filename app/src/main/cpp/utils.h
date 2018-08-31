//
// Created by simonppg on 19/03/18.
//

#ifndef BREAK_IT_ALL_UTILS_H
#define BREAK_IT_ALL_UTILS_H

#include <GLES3/gl3.h>

struct _vector{
    float x, y, z;
};
typedef struct _vector Vector;

struct _vertex{
    Vector position;
    Vector color;
};
typedef struct _vertex Vertex;

#define NUM_ARRAY_ELEMENTS(a) sizeof(a) / sizeof(*a)
#define INDEX_BUFFER_SIZE(numIndices) ((GLsizeiptr)((numIndices) * (sizeof(GLushort))))
#define VERTEX_BUFFER_SIZE(numIndices) ((GLsizeiptr)((numIndices) * (sizeof(Vertex))))

GLuint createProgram(const char* vertexSource, const char * fragmentSource);

#endif //BREAK_IT_ALL_UTILS_H