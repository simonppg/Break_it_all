//
// Created by simonppg on 4/22/19.
//

#ifndef BREAK_IT_ALL_MESH_HPP
#define BREAK_IT_ALL_MESH_HPP

#include "Camera.hpp"

using glm::vec3;

#define NUM_ARRAY_ELEMENTS(a) (sizeof(a) / sizeof(*a))
#define INDEX_BUFFER_SIZE(numIndices) ((GLsizeiptr)((numIndices) * (sizeof(GLushort))))
#define VERTEX_BUFFER_SIZE(numIndices) ((GLsizeiptr)((numIndices) * (sizeof(float) * 6)))
#define ONE 1
#define TWO 2

class Mesh {
public:
    Mesh(float *pDouble, int i);
    Mesh(float *vertex, int v_size, short *indices, int i_size);

    int type;
    float *vertex;
    short *indices;
    int numVertices;
    int numIndices;
    unsigned int vbo; // vertex buffer object
    unsigned int iab; // index array buffer
};

#endif //BREAK_IT_ALL_MESH_HPP
