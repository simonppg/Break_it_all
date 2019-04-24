//
// Created by simonppg on 4/22/19.
//

#ifndef BREAK_IT_ALL_MESH_HPP
#define BREAK_IT_ALL_MESH_HPP

#include "GLES3/gl3.h"
#include "Camera.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using glm::vec3;

#define NUM_ARRAY_ELEMENTS(a) (sizeof(a) / sizeof(*a))
#define INDEX_BUFFER_SIZE(numIndices) ((GLsizeiptr)((numIndices) * (sizeof(GLushort))))
#define VERTEX_BUFFER_SIZE(numIndices) ((GLsizeiptr)((numIndices) * (sizeof(float) * 6)))

class Mesh {
public:
    Mesh(float *vertex, int v_size, short *indices, int i_size);
    void load_model();
    GLuint programID;
    GLuint vbo; // vertex buffer object
    GLuint iab; // index array buffer
    float *vertex;
    short *indices;
    int numVertices;
    int numIndices;
};

#endif //BREAK_IT_ALL_MESH_HPP
