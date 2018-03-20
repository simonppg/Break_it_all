//
// Created by simonppg on 19/03/18.
//

#include<GLES2/gl2.h>
#include <stdlib.h>
#include <android/log.h>
#include <stdbool.h>

#include "triangle.h"
#include "utils.h"

static int n;

GLfloat vertices[] = {
        0.0f, 1.0f,
        -1.0f, -1.0f,
        1.0f, -1.0f
};

struct _Triangle
{
    GLuint program;
    GLuint position;
    GLfloat *vertices;
};

Triangle* Triangle_new(const char* vertexSource, const char * fragmentSource)
{
    Triangle *t;

    t = malloc(sizeof(Triangle));

    if(t != NULL)
    {
        t->vertices = vertices;
        t->program = createProgram(vertexSource, fragmentSource);
        if (!t->program)
        {
            LOGE ("Could not create program");
            return false;
        }
        t->position = (GLuint) glGetAttribLocation(t->program, "vPosition");
    }

    return t;
}

void Triangle_update(Triangle *t)
{
    if(n % 2 == 0) {
        t->vertices[1] = 1.0f;
        n = 1;
    }
    else {
        t->vertices[1] = 0.0f;
        n = 2;
    }
}

void Triangle_draw(Triangle *t)
{
    if(t == NULL)
        return;

    glUseProgram(t->program);
    glVertexAttribPointer(t->position, 2, GL_FLOAT, GL_FALSE, 0 , t->vertices);
    glEnableVertexAttribArray(t->position);
    glDrawArrays(GL_TRIANGLES, 0, 3); 
}