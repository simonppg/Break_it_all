// Copyright (c) 2022 Simon Puente
#include "Mesh.hpp"
#include "MeshType.hpp"

Mesh::Mesh(float *vertex, int v_size) {
  this->vertex = vertex;
  this->numVertices = v_size;
  type = MeshType::TWO;
}

Mesh::Mesh(float *vertex, int v_size, int16_t *indices, int i_size) {
  this->vertex = vertex;
  this->numVertices = v_size;

  this->indices = indices;
  this->numIndices = i_size;
  type = MeshType::ONE;
}

Mesh::~Mesh() {
  free(vertex);
  free(indices);
}
