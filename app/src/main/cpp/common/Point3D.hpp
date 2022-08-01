#ifndef COMMON_POINT3D_HPP
#define COMMON_POINT3D_HPP

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

#endif // COMMON_POINT3D_HPP
