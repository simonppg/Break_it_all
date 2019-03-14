//
// Created by simonppg on 3/13/19.
//

#ifndef BREAK_IT_ALL_CUBE_H
#define BREAK_IT_ALL_CUBE_H

#include <GLES3/gl3.h>

#include "utils.hpp"
#include "Camera.hpp"

class Cube {
    float x,y,z;
    char *vertex_file;
    char *fragment_file;
    GLuint vbo; // vertex buffer object
    GLuint iab; // index array buffer
    GLuint numVertices = NUM_ARRAY_ELEMENTS(vertex);
    GLuint numIndices = NUM_ARRAY_ELEMENTS(indices);
    GLfloat vertex[48] =
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

    const GLushort indices[36] =
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

    Camera *camera;

public:

    Cube(Camera *camera);
    ~Cube();

    void load_model();
    void draw();

    GLuint programID;
};


#endif //BREAK_IT_ALL_CUBE_H
