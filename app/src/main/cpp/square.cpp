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
            1.0, -1.0, -1.0,// right down back
            1.0, 0.0, 0.0,

            1.0, -1.0, 1.0, // right down front
            1.0, 0.0, 0.0,

            -1.0, -1.0, 1.0, // left down front
            1.0, 0.0, 0.0,

            -1.0, -1.0, -1.0, // left down back
            1.0, 0.0, 0.0,

            1.0, 1.0, -1.0, // right up back
            1.0, 0.0, 0.0,

            1.0, 1.0, 1.0, // right up front
            1.0, 0.0, 0.0,

            -1.0, 1.0, 1.0, // left up front
            1.0, 0.0, 0.0,

            -1.0, 1.0, -1.0, // left up back
            1.0, 0.0, 0.0
        };


static const GLushort indices[] =
        {
            // right face 0,1,4,5
            0, 1, 4,
            1, 4, 5,

            // left face 2,3,6,7
            2, 3, 6,
            3, 6, 7,

            // down face 0,1,2,3
            0, 1, 2,
            0, 2, 3,

            // up face 4,5,6,7
            4, 5, 6,
            4, 6, 7,

            // front face 1,2,5,6
            1, 2, 5,
            2, 5, 6,

            // back face 0,3,4,7
            0, 3, 4,
            3, 4, 7

        };

Square* Square_new()
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