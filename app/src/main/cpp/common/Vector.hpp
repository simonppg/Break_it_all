#ifndef COMMON_VECTOR_HPP
#define COMMON_VECTOR_HPP

class Vector {
public:
  float x, y, z;

  Vector(float x, float y, float z);
  float length();
};

#endif // COMMON_VECTOR_HPP
