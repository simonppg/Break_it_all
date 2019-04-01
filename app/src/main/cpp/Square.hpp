//
// Created by simonppg on 3/31/19.
//

#ifndef BREAK_IT_ALL_SQUARE_H
#define BREAK_IT_ALL_SQUARE_H

#include "Camera.hpp"
#include "utils.hpp"

#include <GLES3/gl3.h>

class Square {
    float x,y,z;
    float size;
    char *vertex_file;
    char *fragment_file;
    static GLuint vbo; // vertex buffer object
    static GLuint iab; // index array buffer
    static const GLfloat vertex[24];
    static const GLushort indices[6];
    static const GLuint numVertices = NUM_ARRAY_ELEMENTS(vertex);
    static const GLuint numIndices = NUM_ARRAY_ELEMENTS(indices);

    Camera *camera;
    vec3 rotation;
    float angle;
public:

    Square(Camera *camera);
    ~Square();

    GLuint programID;
    void draw();

    void update_xyx(float x, float y, float z);

    void update_size(float size);

    void animate_x();

    void animate_y();

    void animate_z();

    void set_rotation_angle(float angle);

    void createProgram();

    static void load_model();
};


#endif //BREAK_IT_ALL_SQUARE_H
