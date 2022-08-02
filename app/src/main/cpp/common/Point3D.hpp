// Copyright (c) 2022 Simon Puente
#ifndef APP_SRC_MAIN_CPP_COMMON_POINT3D_HPP_
#define APP_SRC_MAIN_CPP_COMMON_POINT3D_HPP_

class Point3D {
public:
  Point3D(void);
  Point3D(float x, float y, float z);
  Point3D(const Point3D &point);

  float getX();
  float getY();
  float getZ();

  Point3D incrementX(float delta);
  Point3D decrementX(float delta);
  Point3D incrementY(float delta);
  Point3D decrementY(float delta);
  Point3D incrementZ(float delta);
  Point3D decrementZ(float delta);

private:
  float x, y, z;
};

#endif // APP_SRC_MAIN_CPP_COMMON_POINT3D_HPP_
