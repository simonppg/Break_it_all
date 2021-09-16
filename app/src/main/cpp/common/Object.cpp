//
// Created by simonppg on 4/23/19.
//

#include "Object.hpp"
#include <GLES3/gl3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

Object::Object(Camera *pCamera, ShaderProg *pProg, Mesh *pMesh):  y{0}, z{0},
    size_x{2}, size_y{1}, size_z{1}, angle{0}, x{0}{

    rotation = vec3(1);
    this->camera = pCamera;
    this->prog = pProg;
    this->mesh = pMesh;
    acceleration = 0;
    velocity = 500.0;
    draw_context = new DrawContext();
}

void Object::draw() {
    mat4 translate;
    mat4 rotate;
    mat4 scale;

    translate = glm::translate(camera->cameraTranslate, vec3(x, y, z));
    rotate = glm::rotate(translate, glm::radians(angle), rotation);
    scale = glm::scale(rotate, glm::vec3(size_x, size_y, size_z));

    draw_context->programID = prog->programID;
    draw_context->type = mesh->type;
    draw_context->vbo = mesh->vbo;
    draw_context->iab = mesh->iab;
    draw_context->vertex = mesh->vertex;
    draw_context->numVertices = mesh->numVertices;
    draw_context->indices = mesh->indices;
    draw_context->numIndices = mesh->numIndices;
    draw_context->matrix_transform = scale;

    renderer->draw(draw_context);
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