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

static const char glVertexShader[] =
        "attribute vec4 vPosition;\n"
        "void main()\n"
        "{\n"
        "  gl_Position = vPosition;\n"
        "}\n";

static const char glFragmentShader[] =
        "precision mediump float;\n"
        "uniform vec4 vColor;\n"
        "void main()\n"
        "{\n"
        "  gl_FragColor = vColor;\n"
        "}\n";

static GLfloat vertices[] = {
        0.0f, 1.0f,
        -1.0f, -1.0f,
        1.0f, -1.0f
};

struct _Triangle
{
    GLuint program;
    GLuint aPosition;
    GLuint uColor;
    GLfloat *vertices;
    GLfloat *color;
};

Triangle* Triangle_new(GLfloat *color)
{
    Triangle *t;

    t = malloc(sizeof(Triangle));

    if(t != NULL)
    {
        t->vertices = vertices;
        t->color = color;
        t->program = createProgram(glVertexShader, glFragmentShader);
        if (!t->program)
        {
            LOGE ("Could not create program");
            return false;
        }
        t->aPosition = (GLuint) glGetAttribLocation(t->program, "vPosition");
        t->uColor = (GLuint) glGetUniformLocation(t->program, "vColor");
    }

    return t;
}

void Triangle_update(Triangle *t)
{
    if(t == NULL)
        return;

    if(n % 2 == 0) {
        t->vertices[1] = 1.0f;
        n = 1;
        t->color[0] = 0;
        t->color[1] = 0;
        t->color[2] = 1;
    }
    else {
        t->vertices[1] = 0.0f;
        n = 2;
        t->color[0] = 0;
        t->color[1] = 1;
        t->color[2] = 0;
    }


}

void Triangle_draw(Triangle *t)
{
    if(t == NULL)
        return;

    glUseProgram(t->program);

    // Send vertex to the Shader
    glVertexAttribPointer(t->aPosition, 2, GL_FLOAT, GL_FALSE, 0 , t->vertices);
    glEnableVertexAttribArray(t->aPosition);

    // Send color to the Shader
    glUniform4f(t->uColor, t->color[0], t->color[1], t->color[2], t->color[3]);
    // Draw shader
    glDrawArrays(GL_TRIANGLES, 0, 3);
}