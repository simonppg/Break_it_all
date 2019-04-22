//
// Created by simonppg on 4/22/19.
//

#include "Mesh.hpp"

Mesh::Mesh(): x{0}, y{0}, z{0}, size_x{1}, size_y{1}, size_z{1} {}

void Mesh::update_xyx(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void Mesh::update_size(float size_x, float size_y, float size_z) {
    this->size_x = size_x;
    this->size_y = size_y;
    this->size_z = size_z;
}

void Mesh::animate_x() {
    rotation = vec3(1, 0, 0);
}

void Mesh::animate_y() {
    rotation = vec3(0, 1, 0);
}

void Mesh::animate_z() {
    rotation = vec3(0, 0, 1);
}

void Mesh::set_rotation_angle(float angle) {
    this->angle = angle;
}