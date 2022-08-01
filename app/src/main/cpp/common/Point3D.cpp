#include "Point3D.hpp"

Point3D::Point3D(void) : x(0.0), y(0.0), z(0.0) {}
Point3D::Point3D(float x, float y, float z) : x(x), y(y), z(z) {}
Point3D::Point3D(const Point3D &point) : x{point.x}, y{point.y}, z{point.z} {}

float Point3D::getX() { return x; }
float Point3D::getY() { return y; }
float Point3D::getZ() { return z; }

Point3D Point3D::incrementX(float delta) { return Point3D(x + delta, y, z); }

Point3D Point3D::decrementX(float delta) { return Point3D(x - delta, y, z); }

Point3D Point3D::incrementY(float delta) { return Point3D(x, y + delta, z); }

Point3D Point3D::decrementY(float delta) { return Point3D(x, y - delta, z); }

Point3D Point3D::incrementZ(float delta) { return Point3D(x, y, z + delta); }

Point3D Point3D::decrementZ(float delta) { return Point3D(x, y, z - delta); }
