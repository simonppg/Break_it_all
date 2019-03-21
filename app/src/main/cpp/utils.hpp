//
// Created by simonppg on 19/03/18.
//

#ifdef __cplusplus
extern "C" {
#endif

#ifndef BREAK_IT_ALL_UTILS_H
#define BREAK_IT_ALL_UTILS_H

#include <GLES3/gl3.h>

struct _vector{
    GLfloat x, y, z;
};

typedef struct _vector Vector;

struct _vertex{
    Vector position;
    Vector color;
};

typedef struct _vertex Vertex;

struct _Shape
{
    Vertex* vertices;
    GLuint numVertices;
    GLushort* indices;
    GLuint numIndices;
};

typedef struct _Shape Shape;

#define NUM_ARRAY_ELEMENTS(a) (sizeof(a) / sizeof(*a))
#define INDEX_BUFFER_SIZE(numIndices) ((GLsizeiptr)((numIndices) * (sizeof(GLushort))))
#define VERTEX_BUFFER_SIZE(numIndices) ((GLsizeiptr)((numIndices) * (sizeof(Vertex))))

GLuint createProgram(const char* vertexSource, const char * fragmentSource);

// Camera/viewport config
static const int WIDTH = 450;
static const int HEIGHT = 800;
static const float NCP = 0.1f;
static const float FCP = 100.0f;
static const float FOV = 60.0f;
static const float X = 0.0f;
static const float Y = 0.0f;
static const float Z = 40.0f;

#endif //BREAK_IT_ALL_UTILS_H

#ifdef __cplusplus
}
#endif