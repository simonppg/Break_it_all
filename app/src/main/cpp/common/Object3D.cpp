// Copyright (c) 2022 Simon Puente
#include "Object3D.hpp"

Object3D::~Object3D() {}

void Object3D::moveTo(Point3D position) { this->pos = position; }

void Object3D::draw() {}
