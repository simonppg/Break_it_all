//
// Created by simonppg on 4/29/19.
//

#include <cmath>
#include "Vector.hpp"

Vector::Vector(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

float Vector::length() {
    return sqrt(x*x + y*y + z*z);
}
