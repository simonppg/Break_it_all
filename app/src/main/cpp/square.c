//
// Created by simonppg on 21/03/18.
//

#include <stdlib.h>
#include <stdbool.h>

#include "square.h"
#include "utils.h"

#ifdef __ANDROID_NDK__
#include "android/logger.h"
#include "android/filesManager.h"
#else
#include "linux/logger.h"
#include "linux/filesManager.h"
#endif

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

Square* Square_new(char* vertex_file_path, char* fragment_file_path, GLfloat *color)
{
    Square *s;

    s = malloc(sizeof(Square));

    if(s != NULL)
    {
        s->vertices = vertices;
        s->color = color;
        s->program = createProgram(load_file(vertex_file_path),
                                   load_file(fragment_file_path));
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
