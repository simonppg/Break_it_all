//
// Created by simonppg on 4/23/19.
//

#include "Object.hpp"
#include <GLES3/gl3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

Object::Object(Camera *pCamera): x{0}, y{0}, z{0}, size_x{2}, size_y{1}, size_z{1} {
    this->camera = pCamera;
}

void Object::draw() {
    GLint uniform;
    mat4 translate;
    mat4 rotate;
    mat4 scale;

    glUseProgram(prog->programID);
    uniform = glGetUniformLocation(prog->programID, "matrix");

    glBindBuffer(GL_ARRAY_BUFFER, mesh->vbo);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (char*)(sizeof(float) * 3));
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->iab);

    translate = glm::translate(camera->cameraTranslate, vec3(x, y, z));
    rotate = glm::rotate(translate, glm::radians(angle), rotation);
    scale = glm::scale(rotate, glm::vec3(size_x, size_y, size_z));

    glUniformMatrix4fv(uniform, 1, GL_FALSE, &scale[0][0]);
    glDrawElements(GL_TRIANGLES, mesh->numIndices, GL_UNSIGNED_SHORT, 0);
}

void Object::update_xyz(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void Object::update_size(float size_x, float size_y, float size_z) {
    this->size_x = size_x;
    this->size_y = size_y;
    this->size_z = size_z;
}

void Object::set_rotation_angle(float angle) {
    this->angle = angle;
}

void Object::animate_x() {
    rotation = vec3(1, 0, 0);
}

void Object::animate_y() {
    rotation = vec3(0, 1, 0);
}

void Object::animate_z() {
    rotation = vec3(0, 0, 1);
}