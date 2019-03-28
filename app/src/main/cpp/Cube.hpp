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
    float size;
    char *vertex_file;
    char *fragment_file;
    static GLuint vbo; // vertex buffer object
    static GLuint iab; // index array buffer
    static const GLfloat vertex[48];
    static const GLushort indices[36];
    static const GLuint numVertices = NUM_ARRAY_ELEMENTS(vertex);
    static const GLuint numIndices = NUM_ARRAY_ELEMENTS(indices);

    Camera *camera;
    vec3 rotation;
    float angle;

public:

    Cube(Camera *camera);
    ~Cube();

    static void load_model();
    void draw();

    GLuint programID;

    void update_xyx(float x, float y, float z);

    void update_size(float size);

    void animate_x();

    void animate_y();

    void animate_z();

    void set_rotation_angle(float angle);

    void createProgram();
};

#endif //BREAK_IT_ALL_CUBE_H
