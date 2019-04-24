//
// Created by simonppg on 4/22/19.
//

#include "Mesh.hpp"

Mesh::Mesh(float *vertex, int v_size, short *indices, int i_size) {
    this->vertex = vertex;
    this->numVertices = v_size;

    this->indices = indices;
    this->numIndices = i_size;
}

void Mesh::load_model() {
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, VERTEX_BUFFER_SIZE(numVertices), vertex, GL_STATIC_DRAW);

    glGenBuffers(1, &iab);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iab);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, INDEX_BUFFER_SIZE(numIndices), indices, GL_STATIC_DRAW);
}