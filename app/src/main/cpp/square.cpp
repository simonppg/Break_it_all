//
// Created by simonppg on 21/03/18.
//

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <string.h>

#include "square.hpp"
#include "utils.hpp"

#ifdef __ANDROID_NDK__
#include "android/logger.hpp"
#include "android/filesManager.hpp"
#else
#include "linux/logger.hpp"
#include "linux/filesManager.hpp"
#endif

static GLfloat vertex[] =
        {
                -0.4f, -0.4f, +0.0f,
                +1.0f, +0.0f, +0.0f,

                -0.4f, +0.4f, +0.0f,
                +1.0f, +0.0f, +0.0f,

                +0.4f, -0.4f, +0.0f,
                +1.0f, +0.0f, +0.0f,

                +0.4f, +0.4f, +0.0f,
                +1.0f, +0.0f, +0.0f
        };

static const GLushort indices[] =
        {
                0, 1, 2, // left triangle
                1, 2, 3 // right triangle
        };

Square* Square_new(const char* vertex_file_path, const char* fragment_file_path, GLfloat *color)
{
    Square *ret;

    ret = (Square *) malloc(sizeof(Square));

    if(ret == NULL)
        return NULL;

    ret->numVertices = NUM_ARRAY_ELEMENTS(vertex);
    ret->vertices = vertex;
    ret->numIndices = NUM_ARRAY_ELEMENTS(indices);
    ret->indices = (GLushort *) malloc(sizeof(GLushort) * ret->numIndices);
    memcpy(ret->indices, indices, sizeof(indices));

    return ret;
}

void Square_update(Square *s)
{
    if(s == NULL)
        return;

    // TODO: implement this
}

void Square_draw(Square *s)
{
    if(s == NULL)
        return;

    // TODO: implement this
}

#ifdef __cplusplus
}
#endif