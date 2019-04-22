//
// Created by simonppg on 3/31/19.
//

#ifndef BREAK_IT_ALL_SQUARE_H
#define BREAK_IT_ALL_SQUARE_H

#include "Camera.hpp"
#include "utils.hpp"
#include "Mesh.hpp"

#include <GLES3/gl3.h>

class Square : Mesh {
    char *vertex_file;
    char *fragment_file;
    static GLuint vbo; // vertex buffer object
    static GLuint iab; // index array buffer
    static const GLfloat vertex[24];
    static const GLushort indices[6];
    static const GLuint numVertices = NUM_ARRAY_ELEMENTS(vertex);
    static const GLuint numIndices = NUM_ARRAY_ELEMENTS(indices);
    Camera *camera;

public:
    GLuint programID;

    Square(Camera *camera);

    void draw();

    void createProgram();

    static void load_model();
};


#endif //BREAK_IT_ALL_SQUARE_H
