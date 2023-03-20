#include "Vector.hpp"
#include <cmath>

Vector::Vector(float x, float y, float z) {
  this->x = x;
  this->y = y;
  this->z = z;
}

float Vector::length() { return sqrt(x * x + y * y + z * z); }
