#ifndef APP_SRC_MAIN_CPP_COMMON_OBJECT3D_HPP_
#define APP_SRC_MAIN_CPP_COMMON_OBJECT3D_HPP_

#include "Point3D.hpp"

class Object3D {
private:
  Point3D pos;

public:
  virtual ~Object3D();

  void moveTo(Point3D);
};

#endif // APP_SRC_MAIN_CPP_COMMON_OBJECT3D_HPP_
