//
// Created by simonppg on 4/22/19.
//

#include "Mesh.hpp"
#include "MeshType.hpp"

Mesh::Mesh(float *vertex, int v_size) {
    this->vertex = vertex;
    this->numVertices = v_size;
    type = TWO;
}

Mesh::Mesh(float *vertex, int v_size, short *indices, int i_size) {
    this->vertex = vertex;
    this->numVertices = v_size;

    this->indices = indices;
    this->numIndices = i_size;
    type = ONE;
}
