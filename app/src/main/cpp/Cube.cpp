//
// Created by simonppg on 3/13/19.
//

#include "Cube.hpp"

#include <malloc.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#ifdef __ANDROID_NDK__
#include "android/filesManager.hpp"
#else
#include "linux/filesManager.hpp"
#endif
using glm::mat4;
using glm::vec3;

GLuint Cube::vbo = 0;
GLuint Cube::iab = 0;
constexpr GLfloat Cube::vertex[48] =
        {
                1.0, -1.0, -1.0,// right down back
                1.0, 0.0, 0.0,

                1.0, -1.0, 1.0, // right down front
                1.0, 1.0, 0.0,

                -1.0, -1.0, 1.0, // left down front
                0.0, 1.0, 0.0,

                -1.0, -1.0, -1.0, // left down back
                0.0, 0.0, 0.0,

                1.0, 1.0, -1.0, // right up back
                1.0, 0.0, 1.0,

                1.0, 1.0, 1.0, // right up front
                1.0, 1.0, 1.0,

                -1.0, 1.0, 1.0, // left up front
                0.0, 1.0, 1.0,

                -1.0, 1.0, -1.0, // left up back
                0.0, 0.0, 1.0
        };

constexpr GLushort Cube::indices[36] =
        {
                // right face 0,1,4,5
                0, 1, 4,
                1, 4, 5,

                // left face 2,3,6,7
                2, 3, 6,
                3, 6, 7,

                // down face 0,1,2,3
                0, 1, 2,
                0, 2, 3,

                // up face 4,5,6,7
                4, 5, 6,
                4, 6, 7,

                // front face 1,2,5,6
                1, 2, 5,
                2, 5, 6,

                // back face 0,3,4,7
                0, 3, 4,
                3, 4, 7
        };

Cube::Cube(Camera *camera) : Mesh() {
    this->camera = camera;
    vertex_file = load_file("simple.vert");
    fragment_file = load_file("simple.frag");
}

Cube::~Cube() {
    if(vertex_file)
        free(vertex_file);

    if(fragment_file)
        free(fragment_file);
}

void Cube::load_model() {
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, VERTEX_BUFFER_SIZE(numVertices), vertex, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glGenBuffers(1, &iab);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iab);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, INDEX_BUFFER_SIZE(numIndices), indices, GL_STATIC_DRAW);
}

void Cube::draw() {
    GLint uniform;
    mat4 translate;
    mat4 rotate;
    mat4 scale;

    glUseProgram(programID);
    uniform = glGetUniformLocation(programID, "matrix");

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (char*)(sizeof(float) * 3));
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iab);

    translate = glm::translate(camera->cameraTranslate, vec3(x, y, z));
    rotate = glm::rotate(translate, glm::radians(angle), rotation);
    scale = glm::scale(rotate, glm::vec3(size_x, size_y, size_z));

    glUniformMatrix4fv(uniform, 1, GL_FALSE, &scale[0][0]);
    glDrawElements(GL_TRIANGLES, numIndices, GL_UNSIGNED_SHORT, 0);
}

void Cube::createProgram() {
    programID = Utils::createProgram(vertex_file, fragment_file);
}
