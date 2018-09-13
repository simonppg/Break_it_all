//
// Created by simonppg on 19/03/18.
//

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <string.h>

#include "triangle.hpp"
#include "utils.hpp"

#ifdef __ANDROID_NDK__
#include "android/logger.hpp"
#else
#include "linux/logger.hpp"
#endif

static Vertex vertex[] =
        {
                -0.5f, -0.5f, +0.0f,
                +1.0f, +0.0f, +0.0f,

                +0.5f, -0.5f, +0.0f,
                +0.0f, +1.0f, +0.0f,

                +0.0f, -0.0f, +0.0f,
                +0.0f, +0.0f, +1.0f,
        };

static const GLushort indices[] = { 0, 1, 2 };

Triangle* Triangle_new(GLfloat *color)
{
    Triangle *ret;

    ret = (Triangle *) malloc(sizeof(Triangle));

    if (ret == NULL)
        return NULL;

    ret->numVertices = NUM_ARRAY_ELEMENTS(vertex);
    ret->vertices = vertex;
    ret->numIndices = NUM_ARRAY_ELEMENTS(indices);
    ret->indices = (GLushort *) malloc(sizeof(GLushort) * ret->numIndices);
    memcpy(ret->indices, indices, sizeof(indices));

    return ret;
}

void Triangle_update(Triangle *t)
{
    if(t == NULL)
        return;

    // TODO: implement this
}

void Triangle_draw(Triangle *t)
{
    if(t == NULL)
        return;

    // TODO: implement this
}

#ifdef __cplusplus
}
#endif