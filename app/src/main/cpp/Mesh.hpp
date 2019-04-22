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
protected:
    float x,y,z;
    float size_x, size_y, size_z;

    vec3 rotation;
    float angle;
public:

    Mesh();

    GLuint programID;

    void update_xyx(float x, float y, float z);

    void update_size(float size_x, float size_y, float size_z);

    void animate_x();

    void animate_y();

    void animate_z();

    void set_rotation_angle(float angle);
};

#endif //BREAK_IT_ALL_MESH_HPP
