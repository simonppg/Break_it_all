//
// Created by simonppg on 19/03/18.
//

#ifndef BREAK_IT_ALL_TRIANGLE_H
#define BREAK_IT_ALL_TRIANGLE_H

#include "utils.hpp"
#include "Camera.hpp"
#include "Mesh.hpp"

class Triangle {
    float x,y,z;
    float size;
    Camera *camera;

public:
    Triangle(Camera *camera);
    ~Triangle();
    char *vertex_file;
    char *fragment_file;
    static GLuint vbo; // vertex buffer object
    static GLuint iab; // index array buffer
    static const GLfloat vertex[18];
    static const GLushort indices[3];
    static const GLuint numVertices = NUM_ARRAY_ELEMENTS(vertex);
    static const GLuint numIndices = NUM_ARRAY_ELEMENTS(indices);
    GLuint programID;

    static void load_model();
    void draw();
    void createProgram();

    void update_xyx(float x, float y, float z);
    void update_size(float size);
};

#endif //BREAK_IT_ALL_TRIANGLE_H