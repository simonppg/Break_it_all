//
// Created by simonppg on 19/03/18.
//

#include <stdlib.h>
#include <string.h>

#include "triangle.h"
#include "utils.h"

#ifdef __ANDROID_NDK__
#include "android/logger.h"
#else
#include "linux/logger.h"
#endif

static const Vertex vertex[] =
        {
                -1.0f, -1.0f, +0.0f,
                +1.0f, +0.0f, +0.0f,

                +1.0f, -1.0f, +0.0f,
                +0.0f, +1.0f, +0.0f,

                +0.0f, -0.0f, +0.0f,
                +0.0f, +0.0f, +1.0f,
        };

static const GLushort indices[] = { 0, 1, 2 };

Triangle* Triangle_new(GLfloat *color)
{
    Triangle *ret;

    ret = malloc(sizeof(Triangle));

    if (ret == NULL)
        return NULL;

    ret->numVertices = NUM_ARRAY_ELEMENTS(vertex);
    ret->vertices = malloc(sizeof(Vertex) * ret->numVertices);
    memcpy(ret->vertices, vertex, sizeof(vertex));
    ret->numIndices = NUM_ARRAY_ELEMENTS(indices);
    ret->indices = malloc(sizeof(GLushort) * ret->numIndices);
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