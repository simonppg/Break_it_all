//
// Created by simonppg on 3/31/19.
//

#include "Square.hpp"

#ifdef __ANDROID_NDK__
#include "android/filesManager.hpp"
#else
#include "linux/filesManager.hpp"
#endif

GLuint Square::vbo = 0;
GLuint Square::iab = 0;
constexpr GLfloat Square::vertex[24] =
        {
                1.0, -1.0, 1.0, // right down
                1.0, 1.0, 0.0,

                -1.0, -1.0, 1.0, // left down
                0.0, 1.0, 0.0,

                1.0, 1.0, 1.0, // right up
                1.0, 1.0, 1.0,

                -1.0, 1.0, 1.0, // left up
                0.0, 1.0, 1.0
        };

constexpr GLushort Square::indices[6] =
        {
                0, 1, 2,
                1, 2, 3
        };

Square::Square(Camera *camera): x{0}, y{0}, z{0}, size{1} {
    this->camera = camera;
    vertex_file = load_file("simple.vert");
    fragment_file = load_file("simple.frag");
}

void Square::update_xyx(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void Square::update_size(float size) {
    this->size = size;
}

void Square::animate_x() {
    rotation = vec3(1, 0, 0);
}

void Square::animate_y() {
    rotation = vec3(0, 1, 0);
}

void Square::animate_z() {
    rotation = vec3(0, 0, 1);
}

void Square::set_rotation_angle(float angle) {
    this->angle = angle;
}

void Square::createProgram() {
    programID = Utils::createProgram(vertex_file, fragment_file);
}

void Square::load_model() {
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, VERTEX_BUFFER_SIZE(numVertices), vertex, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glGenBuffers(1, &iab);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iab);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, INDEX_BUFFER_SIZE(numIndices), indices, GL_STATIC_DRAW);
}

void Square::draw() {
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
    scale = glm::scale(rotate, glm::vec3(size));

    glUniformMatrix4fv(uniform, 1, GL_FALSE, &scale[0][0]);
    glDrawElements(GL_TRIANGLES, numIndices, GL_UNSIGNED_SHORT, 0);
}