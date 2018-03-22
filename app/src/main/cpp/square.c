//
// Created by simonppg on 21/03/18.
//

#include<GLES2/gl2.h>
#include <stdlib.h>
#include <android/log.h>
#include <stdbool.h>

#include "square.h"
#include "utils.h"

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
        -0.5f, 0.5f,// first triangle
        0.5f, 0.5f,
        -0.5f, -0.5f,

        -0.5f, -0.5f,// second triangle
        0.5f, -0.5f,
        0.5f, 0.5f
};

struct _Square
{
    GLuint program;
    GLuint aPosition;
    GLuint uColor;
    GLfloat *vertices;
    GLfloat *color;
};

Square* Square_new(GLfloat *color)
{
    Square *s;

    s = malloc(sizeof(Square));

    if(s != NULL)
    {
        s->vertices = vertices;
        s->color = color;
        s->program = createProgram(glVertexShader, glFragmentShader);
        if (!s->program)
        {
            LOGE ("Could not create program");
            return false;
        }
        s->aPosition = (GLuint) glGetAttribLocation(s->program, "vPosition");
        s->uColor = (GLuint) glGetUniformLocation(s->program, "vColor");
    }

    return s;
}

void Square_update(Square *s)
{
    // TODO: implement this
}

void Square_draw(Square *s)
{
    if(s == NULL)
        return;

    glUseProgram(s->program);

    // Send vertex to the Shader
    glVertexAttribPointer(s->aPosition, 2, GL_FLOAT, GL_FALSE, 0 , s->vertices);
    glEnableVertexAttribArray(s->aPosition);

    // Send color to the Shader
    glUniform4f(s->uColor, s->color[0], s->color[1], s->color[2], s->color[3]);
    // Draw shader
    glDrawArrays(GL_TRIANGLES, 0, 6); // 6 vertex, 3 for each triangle
}