//
// Created by simonppg on 21/03/18.
//

#include <stdlib.h>
#include <string.h>

#include "square.h"
#include "utils.h"

#ifdef __ANDROID_NDK__
#include "android/logger.h"
#include "android/filesManager.h"
#else
#include "linux/logger.h"
#include "linux/filesManager.h"
#endif

static Vertex vertex[] =
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

Square* Square_new(char* vertex_file_path, char* fragment_file_path, GLfloat *color)
{
    Square *ret;

    ret = malloc(sizeof(Square));

    if(ret == NULL)
        return NULL;

    ret->numVertices = NUM_ARRAY_ELEMENTS(vertex);
    ret->vertices = vertex;
    ret->numIndices = NUM_ARRAY_ELEMENTS(indices);
    ret->indices = malloc(sizeof(GLushort) * ret->numIndices);
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