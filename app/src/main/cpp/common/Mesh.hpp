#ifndef COMMON_MESH_HPP
#define COMMON_MESH_HPP

#include "Camera.hpp"
#include "MeshType.hpp"

using glm::vec3;

#define NUM_ARRAY_ELEMENTS(a) (sizeof(a) / sizeof(*a))
#define INDEX_BUFFER_SIZE(numIndices)                                          \
  ((GLsizeiptr)((numIndices) * (sizeof(GLushort))))
#define VERTEX_BUFFER_SIZE(numIndices)                                         \
  ((GLsizeiptr)((numIndices) * (sizeof(float) * 6)))

class Mesh {
public:
  Mesh(float *pDouble, int i);
  Mesh(float *vertex, int v_size, short *indices, int i_size);

  MeshType type;
  float *vertex;
  short *indices;
  int numVertices;
  int numIndices;
  unsigned int vbo; // vertex buffer object
  unsigned int iab; // index array buffer
};

#endif // COMMON_MESH_HPP
