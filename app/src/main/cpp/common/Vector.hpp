// Copyright (c) 2022 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_VECTOR_HPP_
#define APP_SRC_MAIN_CPP_COMMON_VECTOR_HPP_

class Vector {
public:
  float x, y, z;

  Vector(float x, float y, float z);
  float length();
};

#endif // APP_SRC_MAIN_CPP_COMMON_VECTOR_HPP_
